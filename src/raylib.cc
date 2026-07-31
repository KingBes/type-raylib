#ifdef _WIN32
#include "raylib_compat.h" // windows *
#else
#include "raylib.h" 
#endif

#include <phpx.h>

using namespace php;

// ---- 把 raylib 的 Color 结构打包成 Box ----
class ColorBox : public Box {
public:
    unsigned char r, g, b, a;
    ColorBox(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
        : r(r), g(g), b(b), a(a) {}
};

// Box 资源 -> raylib 的 Color 结构（供 ClearBackground/DrawText 等使用）
static Color toRaylibColor(var c) {
    auto cb = c.toBox<ColorBox>();
    return Color{cb->r, cb->g, cb->b, cb->a};
}

// 工厂：自定义颜色
var php_raylib__color__make(Object &_this, Int r, Int g, Int b, Int a) {
    return {new ColorBox((unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a)};
}

// raylib v6.0 全部 26 个调色板常量（RGBA 取自 include/raylib.h）
var php_raylib__color__lightgray(Object &_this) { return {new ColorBox(200,200,200,255)}; }
var php_raylib__color__gray(Object &_this)      { return {new ColorBox(130,130,130,255)}; }
var php_raylib__color__darkgray(Object &_this)  { return {new ColorBox(80,80,80,255)}; }
var php_raylib__color__yellow(Object &_this)    { return {new ColorBox(253,249,0,255)}; }
var php_raylib__color__gold(Object &_this)      { return {new ColorBox(255,203,0,255)}; }
var php_raylib__color__orange(Object &_this)    { return {new ColorBox(255,161,0,255)}; }
var php_raylib__color__pink(Object &_this)      { return {new ColorBox(255,109,194,255)}; }
var php_raylib__color__red(Object &_this)       { return {new ColorBox(230,41,55,255)}; }
var php_raylib__color__maroon(Object &_this)    { return {new ColorBox(190,33,55,255)}; }
var php_raylib__color__green(Object &_this)     { return {new ColorBox(0,228,48,255)}; }
var php_raylib__color__lime(Object &_this)      { return {new ColorBox(0,158,47,255)}; }
var php_raylib__color__darkgreen(Object &_this) { return {new ColorBox(0,117,44,255)}; }
var php_raylib__color__skyblue(Object &_this)   { return {new ColorBox(102,191,255,255)}; }
var php_raylib__color__blue(Object &_this)      { return {new ColorBox(0,121,241,255)}; }
var php_raylib__color__darkblue(Object &_this)  { return {new ColorBox(0,82,172,255)}; }
var php_raylib__color__purple(Object &_this)    { return {new ColorBox(200,122,255,255)}; }
var php_raylib__color__violet(Object &_this)    { return {new ColorBox(135,60,190,255)}; }
var php_raylib__color__darkpurple(Object &_this){ return {new ColorBox(112,31,126,255)}; }
var php_raylib__color__beige(Object &_this)     { return {new ColorBox(211,176,131,255)}; }
var php_raylib__color__brown(Object &_this)     { return {new ColorBox(127,106,79,255)}; }
var php_raylib__color__darkbrown(Object &_this) { return {new ColorBox(76,63,47,255)}; }
var php_raylib__color__white(Object &_this)     { return {new ColorBox(255,255,255,255)}; }
var php_raylib__color__black(Object &_this)     { return {new ColorBox(0,0,0,255)}; }
var php_raylib__color__blank(Object &_this)     { return {new ColorBox(0,0,0,0)}; }
var php_raylib__color__magenta(Object &_this)   { return {new ColorBox(255,0,255,255)}; }
var php_raylib__color__raywhite(Object &_this)  { return {new ColorBox(245,245,245,255)}; }


// raylib 的 rcore模块

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

void php_raylib__core__clear_background(Object &_this,Var color)
{
    ClearBackground(toRaylibColor(color));
}

// ---- Vector2 的 Box 封装 ----
class Vector2Box : public Box {
public:
    float x, y;
    Vector2Box(float x, float y) : x(x), y(y) {}
};

// raylib Vector2 -> Box
static var toVector2Box(Vector2 v) {
    return {new Vector2Box(v.x, v.y)};
}

var php_raylib__vector2__make(Object &_this, Float x, Float y) {
    return {new Vector2Box((float)x, (float)y)};
}
Float php_raylib__vector2__x(Object &_this, var v) {
    return v.toBox<Vector2Box>()->x;
}
Float php_raylib__vector2__y(Object &_this, var v) {
    return v.toBox<Vector2Box>()->y;
}

// raylib 的 rcore 模块：窗口 / 光标 / 计时 / 输入

// window-related
Bool php_raylib__core__is_window_ready(Object &_this) { return IsWindowReady() != 0; }
Bool php_raylib__core__is_window_fullscreen(Object &_this) { return IsWindowFullscreen() != 0; }
Bool php_raylib__core__is_window_hidden(Object &_this) { return IsWindowHidden() != 0; }
Bool php_raylib__core__is_window_minimized(Object &_this) { return IsWindowMinimized() != 0; }
Bool php_raylib__core__is_window_maximized(Object &_this) { return IsWindowMaximized() != 0; }
Bool php_raylib__core__is_window_focused(Object &_this) { return IsWindowFocused() != 0; }
Bool php_raylib__core__is_window_resized(Object &_this) { return IsWindowResized() != 0; }
Bool php_raylib__core__is_window_state(Object &_this, Int flag) { return IsWindowState((unsigned int)flag) != 0; }
void php_raylib__core__set_window_state(Object &_this, Int flags) { SetWindowState((unsigned int)flags); }
void php_raylib__core__clear_window_state(Object &_this, Int flags) { ClearWindowState((unsigned int)flags); }
void php_raylib__core__toggle_fullscreen(Object &_this) { ToggleFullscreen(); }
void php_raylib__core__toggle_borderless_windowed(Object &_this) { ToggleBorderlessWindowed(); }
void php_raylib__core__maximize_window(Object &_this) { MaximizeWindow(); }
void php_raylib__core__minimize_window(Object &_this) { MinimizeWindow(); }
void php_raylib__core__restore_window(Object &_this) { RestoreWindow(); }
void php_raylib__core__set_window_title(Object &_this, String title) { SetWindowTitle(title.data()); }
void php_raylib__core__set_window_position(Object &_this, Int x, Int y) { SetWindowPosition((int)x, (int)y); }
void php_raylib__core__set_window_monitor(Object &_this, Int monitor) { SetWindowMonitor((int)monitor); }
void php_raylib__core__set_window_min_size(Object &_this, Int width, Int height) { SetWindowMinSize((int)width, (int)height); }
void php_raylib__core__set_window_max_size(Object &_this, Int width, Int height) { SetWindowMaxSize((int)width, (int)height); }
void php_raylib__core__set_window_size(Object &_this, Int width, Int height) { SetWindowSize((int)width, (int)height); }
void php_raylib__core__set_window_opacity(Object &_this, Float opacity) { SetWindowOpacity((float)opacity); }
void php_raylib__core__set_window_focused(Object &_this) { SetWindowFocused(); }
Int php_raylib__core__get_screen_width(Object &_this) { return GetScreenWidth(); }
Int php_raylib__core__get_screen_height(Object &_this) { return GetScreenHeight(); }
Int php_raylib__core__get_render_width(Object &_this) { return GetRenderWidth(); }
Int php_raylib__core__get_render_height(Object &_this) { return GetRenderHeight(); }
Int php_raylib__core__get_monitor_count(Object &_this) { return GetMonitorCount(); }
Int php_raylib__core__get_current_monitor(Object &_this) { return GetCurrentMonitor(); }
Int php_raylib__core__get_monitor_width(Object &_this, Int monitor) { return GetMonitorWidth((int)monitor); }
Int php_raylib__core__get_monitor_height(Object &_this, Int monitor) { return GetMonitorHeight((int)monitor); }
Int php_raylib__core__get_monitor_physical_width(Object &_this, Int monitor) { return GetMonitorPhysicalWidth((int)monitor); }
Int php_raylib__core__get_monitor_physical_height(Object &_this, Int monitor) { return GetMonitorPhysicalHeight((int)monitor); }
Int php_raylib__core__get_monitor_refresh_rate(Object &_this, Int monitor) { return GetMonitorRefreshRate((int)monitor); }
String php_raylib__core__get_monitor_name(Object &_this, Int monitor) { const char *s = GetMonitorName((int)monitor); return String(s ? s : ""); }
void php_raylib__core__set_clipboard_text(Object &_this, String text) { SetClipboardText(text.data()); }
String php_raylib__core__get_clipboard_text(Object &_this) { const char *s = GetClipboardText(); return String(s ? s : ""); }
var php_raylib__core__get_monitor_position(Object &_this, Int monitor) { return toVector2Box(GetMonitorPosition((int)monitor)); }
var php_raylib__core__get_window_position(Object &_this) { return toVector2Box(GetWindowPosition()); }
var php_raylib__core__get_window_scale_dpi(Object &_this) { return toVector2Box(GetWindowScaleDPI()); }
void php_raylib__core__enable_event_waiting(Object &_this) { EnableEventWaiting(); }
void php_raylib__core__disable_event_waiting(Object &_this) { DisableEventWaiting(); }

// cursor-related
void php_raylib__core__show_cursor(Object &_this) { ShowCursor(); }
void php_raylib__core__hide_cursor(Object &_this) { HideCursor(); }
Bool php_raylib__core__is_cursor_hidden(Object &_this) { return IsCursorHidden() != 0; }
void php_raylib__core__enable_cursor(Object &_this) { EnableCursor(); }
void php_raylib__core__disable_cursor(Object &_this) { DisableCursor(); }
Bool php_raylib__core__is_cursor_on_screen(Object &_this) { return IsCursorOnScreen() != 0; }
void php_raylib__core__set_mouse_cursor(Object &_this, Int cursor) { SetMouseCursor((int)cursor); }

// timing-related
Float php_raylib__core__get_frame_time(Object &_this) { return GetFrameTime(); }
Float php_raylib__core__get_time(Object &_this) { return (Float)GetTime(); }
Int php_raylib__core__get_fps(Object &_this) { return GetFPS(); }

// keyboard
Bool php_raylib__core__is_key_pressed(Object &_this, Int key) { return IsKeyPressed((int)key) != 0; }
Bool php_raylib__core__is_key_pressed_repeat(Object &_this, Int key) { return IsKeyPressedRepeat((int)key) != 0; }
Bool php_raylib__core__is_key_down(Object &_this, Int key) { return IsKeyDown((int)key) != 0; }
Bool php_raylib__core__is_key_released(Object &_this, Int key) { return IsKeyReleased((int)key) != 0; }
Bool php_raylib__core__is_key_up(Object &_this, Int key) { return IsKeyUp((int)key) != 0; }
Int php_raylib__core__get_key_pressed(Object &_this) { return GetKeyPressed(); }
Int php_raylib__core__get_char_pressed(Object &_this) { return GetCharPressed(); }
String php_raylib__core__get_key_name(Object &_this, Int key) { const char *s = GetKeyName((int)key); return String(s ? s : ""); }
void php_raylib__core__set_exit_key(Object &_this, Int key) { SetExitKey((int)key); }

// mouse
Bool php_raylib__core__is_mouse_button_pressed(Object &_this, Int button) { return IsMouseButtonPressed((int)button) != 0; }
Bool php_raylib__core__is_mouse_button_down(Object &_this, Int button) { return IsMouseButtonDown((int)button) != 0; }
Bool php_raylib__core__is_mouse_button_released(Object &_this, Int button) { return IsMouseButtonReleased((int)button) != 0; }
Bool php_raylib__core__is_mouse_button_up(Object &_this, Int button) { return IsMouseButtonUp((int)button) != 0; }
Int php_raylib__core__get_mouse_x(Object &_this) { return GetMouseX(); }
Int php_raylib__core__get_mouse_y(Object &_this) { return GetMouseY(); }
var php_raylib__core__get_mouse_position(Object &_this) { return toVector2Box(GetMousePosition()); }
var php_raylib__core__get_mouse_delta(Object &_this) { return toVector2Box(GetMouseDelta()); }
void php_raylib__core__set_mouse_position(Object &_this, Int x, Int y) { SetMousePosition((int)x, (int)y); }
void php_raylib__core__set_mouse_offset(Object &_this, Int offsetX, Int offsetY) { SetMouseOffset((int)offsetX, (int)offsetY); }
void php_raylib__core__set_mouse_scale(Object &_this, Float scaleX, Float scaleY) { SetMouseScale((float)scaleX, (float)scaleY); }
Float php_raylib__core__get_mouse_wheel_move(Object &_this) { return GetMouseWheelMove(); }
var php_raylib__core__get_mouse_wheel_move_v(Object &_this) { return toVector2Box(GetMouseWheelMoveV()); }

// touch
Int php_raylib__core__get_touch_x(Object &_this) { return GetTouchX(); }
Int php_raylib__core__get_touch_y(Object &_this) { return GetTouchY(); }
var php_raylib__core__get_touch_position(Object &_this, Int index) { return toVector2Box(GetTouchPosition((int)index)); }
Int php_raylib__core__get_touch_point_id(Object &_this, Int index) { return GetTouchPointId((int)index); }
Int php_raylib__core__get_touch_point_count(Object &_this) { return GetTouchPointCount(); }

// gamepad
Bool php_raylib__core__is_gamepad_available(Object &_this, Int gamepad) { return IsGamepadAvailable((int)gamepad) != 0; }
String php_raylib__core__get_gamepad_name(Object &_this, Int gamepad) { const char *s = GetGamepadName((int)gamepad); return String(s ? s : ""); }
Bool php_raylib__core__is_gamepad_button_pressed(Object &_this, Int gamepad, Int button) { return IsGamepadButtonPressed((int)gamepad, (int)button) != 0; }
Bool php_raylib__core__is_gamepad_button_down(Object &_this, Int gamepad, Int button) { return IsGamepadButtonDown((int)gamepad, (int)button) != 0; }
Bool php_raylib__core__is_gamepad_button_released(Object &_this, Int gamepad, Int button) { return IsGamepadButtonReleased((int)gamepad, (int)button) != 0; }
Bool php_raylib__core__is_gamepad_button_up(Object &_this, Int gamepad, Int button) { return IsGamepadButtonUp((int)gamepad, (int)button) != 0; }
Int php_raylib__core__get_gamepad_button_pressed(Object &_this) { return GetGamepadButtonPressed(); }
Int php_raylib__core__get_gamepad_axis_count(Object &_this, Int gamepad) { return GetGamepadAxisCount((int)gamepad); }
Float php_raylib__core__get_gamepad_axis_movement(Object &_this, Int gamepad, Int axis) { return GetGamepadAxisMovement((int)gamepad, (int)axis); }
Int php_raylib__core__set_gamepad_mappings(Object &_this, String mappings) { return SetGamepadMappings(mappings.data()); }
void php_raylib__core__set_gamepad_vibration(Object &_this, Int gamepad, Float leftMotor, Float rightMotor, Float duration) { SetGamepadVibration((int)gamepad, (float)leftMotor, (float)rightMotor, (float)duration); }