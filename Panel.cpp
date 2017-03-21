#include "Panel.h"
#include "Internal.h"

typedef void* Panel_t;
typedef const char*(__fastcall *GetName_t)(Panel_t, void*, GuiPanel_t);
typedef void(__fastcall *PaintTraverse_t)(Panel_t, void*, GuiPanel_t, bool, bool);

static Panel_t panel = NULL;

void Panel_Initialize()
{
    CreateInterface_t factory = CreateInterfaceFactory("vgui2.dll");
    panel = factory("VGUI_Panel009", NULL);
}

const char* Panel_GetName(GuiPanel_t guiPanel)
{
    return ((GetName_t)GetVMTFunc(panel, 36, 0))(panel, NULL, guiPanel);
}

void Panel_PaintTraverse(GuiPanel_t guiPanel, bool forceRepaint, bool allowForce)
{
    ((PaintTraverse_t)GetVMTFunc(panel, 41, 0))(panel, NULL, guiPanel, forceRepaint, allowForce);
}
