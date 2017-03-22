#pragma once
#include <cstddef>

typedef struct {
    void*** table;
    void** originalTable;
    void** clonedTable;
} VMTHook_t;

void VMTHook_Initialize(VMTHook_t* outHook, void* class, size_t vmtIndex);
void VMTHook_Uninitialize(VMTHook_t* hook);
void VMTHook_HookFunction(VMTHook_t* hook, size_t index, void* dest);
void VMTHook_UnhookFunction(VMTHook_t* hook, size_t index);