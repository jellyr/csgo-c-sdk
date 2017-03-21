#pragma once
#include <cstdbool>

typedef unsigned long Font_t;

typedef enum {
    FONT_DRAW_DEFAULT = 0,
    FONT_DRAW_NONADDITIVE,
    FONT_DRAW_ADDITIVE
} FontDrawType_t;

void Surface_Initialize();
void Surface_DrawSetColor(int r, int g, int b, int a);
void Surface_DrawFilledRect(int x0, int y0, int x1, int y1);
void Surface_DrawOutlinedRect(int x0, int y0, int x1, int y1);
void Surface_DrawLine(int x0, int y0, int x1, int y1);
void Surface_DrawSetTextFont(Font_t font);
void Surface_DrawSetTextColor(int r, int g, int b, int a);
void Surface_DrawSetTextPos(int x, int y);
void Surface_DrawPrintText(const wchar_t *text, int textLen, FontDrawType_t drawType);
void Surface_GetScreenSize(int *wide, int *tall);
Font_t Surface_CreateFont();
bool Surface_SetFontGlyphSet(Font_t font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags, int rangeMin, int rangeMax);
void Surface_GetTextSize(Font_t font, const wchar_t *text, int *wide, int *tall);
void Surface_PlaySound(const char *fileName);
void Surface_GetCursorPos(int *x, int *y);
void Surface_SetCursorPos(int x, int y);