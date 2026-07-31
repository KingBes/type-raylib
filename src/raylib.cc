#ifdef _WIN32
#include "raylib_compat.h" // windows *
#else
#include "raylib.h" 
#endif

#include <phpx.h>

using namespace php;

void php_raylib__core__init_window(Object &_this,Int width, Int height, String title)
{
    InitWindow(width, height, title.data());
}

void php_raylib__core__set_target_fps(Object &_this,Int fps)
{
    SetTargetFPS(fps);
}

Bool php_raylib__core__window_should_close(Object &_this)
{
    return WindowShouldClose() != 0;
}

void php_raylib__core__begin_drawing(Object &_this)
{
    BeginDrawing();
}

void php_raylib__core__end_drawing(Object &_this)
{
    EndDrawing();
}

void php_raylib__core__close_window(Object &_this)
{
    CloseWindow();
}

void php_raylib__core__clear_background(Object &_this)
{
    ClearBackground(RAYWHITE);
}

void php_raylib__core__draw_text(Object &_this,String text, Int posX, Int posY, Int fontSize)
{
    DrawText(text.data(), posX, posY, fontSize, DARKGRAY);
}