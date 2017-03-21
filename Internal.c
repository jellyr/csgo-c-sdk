#include "Internal.h"
#include <Windows.h>

CreateInterface_t CreateInterfaceFactory(const char *moduleName)
{
    HMODULE module = GetModuleHandle(moduleName);
    return (CreateInterface_t)GetProcAddress(module, "CreateInterface");
}

void* GetVMTFunc(void* class, size_t index, size_t vmtIndex)
{
    size_t offset = vmtIndex * sizeof(void**);
    void** vmt = *((void***)class + offset);
    return vmt[index];
}