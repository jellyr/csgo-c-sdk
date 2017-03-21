#pragma once
#include <stddef.h>

typedef void*(*CreateInterface_t)(const char*, int*);

CreateInterface_t CreateInterfaceFactory(const char *moduleName);
void* GetVMTFunc(void *class, size_t index, size_t vmtIndex);