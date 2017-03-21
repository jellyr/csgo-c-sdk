#include "Surface.h"
#include "Internal.h"

typedef void* Surface_t;
typedef void(__fastcall *DrawSetColor_t)(Surface_t, void*, int, int, int, int);
typedef void(__fastcall *DrawFilledRect_t)(Surface_t, void*, int, int, int, int);
typedef void(__fastcall *DrawOutlinedRect_t)(Surface_t, void*, int, int, int, int);
typedef void(__fastcall *DrawLine_t)(Surface_t, void*, int, int, int, int);
typedef void(__fastcall *DrawSetTextFont_t)(Surface_t, void*, Font_t);
typedef void(__fastcall *DrawSetTextColor_t)(Surface_t, void*, int, int, int, int);
typedef void(__fastcall *DrawSetTextPos_t)(Surface_t, void*, int, int);
typedef void(__fastcall *DrawPrintText_t)(Surface_t, void*, const wchar_t*, int, FontDrawType_t);
typedef void(__fastcall *GetScreenSize_t)(Surface_t, void*, int*, int*);
typedef Font_t(__fastcall *CreateFont_t)(Surface_t, void*);
typedef bool(__fastcall *SetFontGlyphSet_t)(Surface_t, void*, Font_t, const char*, int, int, int, int, int, int, int);
typedef void(__fastcall *GetTextSize_t)(Surface_t, void*, Font_t, const wchar_t*, int*, int*);
typedef void(__fastcall *PlaySound_t)(Surface_t, void*, const char*);
typedef void(__fastcall *GetCursorPos_t)(Surface_t, void*, int*, int*);
typedef void(__fastcall *SetCursorPos_t)(Surface_t, void*, int, int);

static Surface_t surface = NULL;

void Surface_Initialize()
{
    CreateInterface_t factory = CreateInterfaceFactory("vguimatsurface");
    surface = factory("VGUI_Surface030", NULL);
}

void Surface_DrawSetColor(int r, int g, int b, int a)
{
    ((DrawSetColor_t)GetVMTFunc(surface, 15, 0))(surface, NULL, r, g, b, a);
}

void Surface_DrawFilledRect(int x0, int y0, int x1, int y1)
{
    ((DrawFilledRect_t)GetVMTFunc(surface, 16, 0))(surface, NULL, x0, y0, x1, y1);
}

void Surface_DrawOutlinedRect(int x0, int y0, int x1, int y1)
{
    ((DrawOutlinedRect_t)GetVMTFunc(surface, 18, 0))(surface, NULL, x0, y0, x1, y1);
}

void Surface_DrawLine(int x0, int y0, int x1, int y1)
{
    ((DrawLine_t)GetVMTFunc(surface, 19, 0))(surface, NULL, x0, y0, x1, y1);
}

void Surface_DrawSetTextFont(Font_t font)
{
    ((DrawSetTextFont_t)GetVMTFunc(surface, 23, 0))(surface, NULL, font);
}

void Surface_DrawSetTextColor(int r, int g, int b, int a)
{
    ((DrawSetTextColor_t)GetVMTFunc(surface, 25, 0))(surface, NULL, r, g, b, a);
}

void Surface_DrawSetTextPos(int x, int y)
{
    ((DrawSetTextPos_t)GetVMTFunc(surface, 26, 0))(surface, NULL, x, y);
}

void Surface_DrawPrintText(const wchar_t *text, int textLen, FontDrawType_t drawType)
{
    ((DrawPrintText_t)GetVMTFunc(surface, 28, 0))(surface, NULL, text, textLen, drawType);
}

void Surface_GetScreenSize(int *wide, int *tall)
{
    ((GetScreenSize_t)GetVMTFunc(surface, 44, 0))(surface, NULL, wide, tall);
}

Font_t Surface_CreateFont()
{
    return ((CreateFont_t)GetVMTFunc(surface, 71, 0))(surface, NULL);
}

bool Surface_SetFontGlyphSet(Font_t font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags, int rangeMin, int rangeMax)
{
    return ((SetFontGlyphSet_t)GetVMTFunc(surface, 72, 0))(surface, NULL, font, windowsFontName, tall, weight, blur, scanlines, flags, rangeMin, rangeMax);
}

void Surface_GetTextSize(Font_t font, const wchar_t *text, int *wide, int *tall)
{
    ((GetTextSize_t)GetVMTFunc(surface, 79, 0))(surface, NULL, font, text, wide, tall);
}

void Surface_PlaySound(const char *fileName)
{
    ((PlaySound_t)GetVMTFunc(surface, 82, 0))(surface, NULL, fileName);
}

void Surface_GetCursorPos(int *x, int *y)
{
    ((GetCursorPos_t)GetVMTFunc(surface, 100, 0))(surface, NULL, x, y);
}

void Surface_SetCursorPos(int x, int y)
{
    ((SetCursorPos_t)GetVMTFunc(surface, 101, 0))(surface, NULL, x, y);
}