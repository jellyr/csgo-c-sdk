#include "VMTHook.h"
#include <Windows.h>

static size_t GetTableLength(void** table)
{
    size_t i = 0;
    while (!IsBadCodePtr(table[i]))
        ++i;
    return i;
}

void VMTHook_Initialize(VMTHook_t* outHook, void* class, size_t vmtIndex)
{
    ptrdiff_t offset = vmtIndex * sizeof(void**);

    outHook->table = (void***)class + offset;
    outHook->originalTable = *outHook->table;
    
    size_t tableSize = GetTableLength(outHook->originalTable) * sizeof(void*);
    outHook->clonedTable = malloc(tableSize);
    memcpy(outHook->clonedTable, outHook->originalTable, tableSize);
}

void VMTHook_Uninitialize(VMTHook_t* hook)
{
    *hook->table = hook->originalTable;
    free(hook->clonedTable);
}

void VMTHook_HookFunction(VMTHook_t* hook, size_t index, void* dest)
{
    hook->clonedTable[index] = dest;
}

void VMTHook_UnhookFunction(VMTHook_t* hook, size_t index)
{
    hook->clonedTable[index] = hook->originalTable[index];
}