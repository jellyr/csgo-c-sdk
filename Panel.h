#pragma once
#include <stdbool.h>

typedef unsigned long GuiPanel_t;

void Panel_Initialize();
const char *Panel_GetName(GuiPanel_t guiPanel);
void Panel_PaintTraverse(GuiPanel_t guiPanel, bool forceRepaint, bool allowForce);