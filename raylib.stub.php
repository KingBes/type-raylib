<?php

namespace Raylib;

class Color
{
    public static function make(int $r, int $g, int $b, int $a = 255): mixed {}
    public static function lightgray(): mixed {}
    public static function gray(): mixed {}
    public static function darkgray(): mixed {}
    public static function yellow(): mixed {}
    public static function gold(): mixed {}
    public static function orange(): mixed {}
    public static function pink(): mixed {}
    public static function red(): mixed {}
    public static function maroon(): mixed {}
    public static function green(): mixed {}
    public static function lime(): mixed {}
    public static function darkgreen(): mixed {}
    public static function skyblue(): mixed {}
    public static function blue(): mixed {}
    public static function darkblue(): mixed {}
    public static function purple(): mixed {}
    public static function violet(): mixed {}
    public static function darkpurple(): mixed {}
    public static function beige(): mixed {}
    public static function brown(): mixed {}
    public static function darkbrown(): mixed {}
    public static function white(): mixed {}
    public static function black(): mixed {}
    public static function blank(): mixed {}
    public static function magenta(): mixed {}
    public static function raywhite(): mixed {}
}

class Vector2
{
    public static function make(float $x, float $y): mixed {}
    public static function x(mixed $v): float {}
    public static function y(mixed $v): float {}
}

class Key
{
    public const KEY_NULL = 0;
    public const KEY_APOSTROPHE = 39;
    public const KEY_COMMA = 44;
    public const KEY_MINUS = 45;
    public const KEY_PERIOD = 46;
    public const KEY_SLASH = 47;
    public const KEY_ZERO = 48;
    public const KEY_ONE = 49;
    public const KEY_TWO = 50;
    public const KEY_THREE = 51;
    public const KEY_FOUR = 52;
    public const KEY_FIVE = 53;
    public const KEY_SIX = 54;
    public const KEY_SEVEN = 55;
    public const KEY_EIGHT = 56;
    public const KEY_NINE = 57;
    public const KEY_SEMICOLON = 59;
    public const KEY_EQUAL = 61;
    public const KEY_A = 65;
    public const KEY_B = 66;
    public const KEY_C = 67;
    public const KEY_D = 68;
    public const KEY_E = 69;
    public const KEY_F = 70;
    public const KEY_G = 71;
    public const KEY_H = 72;
    public const KEY_I = 73;
    public const KEY_J = 74;
    public const KEY_K = 75;
    public const KEY_L = 76;
    public const KEY_M = 77;
    public const KEY_N = 78;
    public const KEY_O = 79;
    public const KEY_P = 80;
    public const KEY_Q = 81;
    public const KEY_R = 82;
    public const KEY_S = 83;
    public const KEY_T = 84;
    public const KEY_U = 85;
    public const KEY_V = 86;
    public const KEY_W = 87;
    public const KEY_X = 88;
    public const KEY_Y = 89;
    public const KEY_Z = 90;
    public const KEY_LEFT_BRACKET = 91;
    public const KEY_BACKSLASH = 92;
    public const KEY_RIGHT_BRACKET = 93;
    public const KEY_GRAVE = 96;
    public const KEY_SPACE = 32;
    public const KEY_ESCAPE = 256;
    public const KEY_ENTER = 257;
    public const KEY_TAB = 258;
    public const KEY_BACKSPACE = 259;
    public const KEY_INSERT = 260;
    public const KEY_DELETE = 261;
    public const KEY_RIGHT = 262;
    public const KEY_LEFT = 263;
    public const KEY_DOWN = 264;
    public const KEY_UP = 265;
    public const KEY_PAGE_UP = 266;
    public const KEY_PAGE_DOWN = 267;
    public const KEY_HOME = 268;
    public const KEY_END = 269;
    public const KEY_CAPS_LOCK = 280;
    public const KEY_SCROLL_LOCK = 281;
    public const KEY_NUM_LOCK = 282;
    public const KEY_PRINT_SCREEN = 283;
    public const KEY_PAUSE = 284;
    public const KEY_F1 = 290;
    public const KEY_F2 = 291;
    public const KEY_F3 = 292;
    public const KEY_F4 = 293;
    public const KEY_F5 = 294;
    public const KEY_F6 = 295;
    public const KEY_F7 = 296;
    public const KEY_F8 = 297;
    public const KEY_F9 = 298;
    public const KEY_F10 = 299;
    public const KEY_F11 = 300;
    public const KEY_F12 = 301;
    public const KEY_LEFT_SHIFT = 340;
    public const KEY_LEFT_CONTROL = 341;
    public const KEY_LEFT_ALT = 342;
    public const KEY_LEFT_SUPER = 343;
    public const KEY_RIGHT_SHIFT = 344;
    public const KEY_RIGHT_CONTROL = 345;
    public const KEY_RIGHT_ALT = 346;
    public const KEY_RIGHT_SUPER = 347;
    public const KEY_KB_MENU = 348;
    public const KEY_KP_0 = 320;
    public const KEY_KP_1 = 321;
    public const KEY_KP_2 = 322;
    public const KEY_KP_3 = 323;
    public const KEY_KP_4 = 324;
    public const KEY_KP_5 = 325;
    public const KEY_KP_6 = 326;
    public const KEY_KP_7 = 327;
    public const KEY_KP_8 = 328;
    public const KEY_KP_9 = 329;
    public const KEY_KP_DECIMAL = 330;
    public const KEY_KP_DIVIDE = 331;
    public const KEY_KP_MULTIPLY = 332;
    public const KEY_KP_SUBTRACT = 333;
    public const KEY_KP_ADD = 334;
    public const KEY_KP_ENTER = 335;
    public const KEY_KP_EQUAL = 336;
    public const KEY_BACK = 4;
    public const KEY_MENU = 5;
    public const KEY_VOLUME_UP = 24;
    public const KEY_VOLUME_DOWN = 25;
}

class MouseButton
{
    public const MOUSE_BUTTON_LEFT = 0;
    public const MOUSE_BUTTON_RIGHT = 1;
    public const MOUSE_BUTTON_MIDDLE = 2;
    public const MOUSE_BUTTON_SIDE = 3;
    public const MOUSE_BUTTON_EXTRA = 4;
    public const MOUSE_BUTTON_FORWARD = 5;
    public const MOUSE_BUTTON_BACK = 6;
}

class MouseCursor
{
    public const MOUSE_CURSOR_DEFAULT = 0;
    public const MOUSE_CURSOR_ARROW = 1;
    public const MOUSE_CURSOR_IBEAM = 2;
    public const MOUSE_CURSOR_CROSSHAIR = 3;
    public const MOUSE_CURSOR_POINTING_HAND = 4;
    public const MOUSE_CURSOR_RESIZE_EW = 5;
    public const MOUSE_CURSOR_RESIZE_NS = 6;
    public const MOUSE_CURSOR_RESIZE_NWSE = 7;
    public const MOUSE_CURSOR_RESIZE_NESW = 8;
    public const MOUSE_CURSOR_RESIZE_ALL = 9;
    public const MOUSE_CURSOR_NOT_ALLOWED = 10;
}

class GamepadButton
{
    public const GAMEPAD_BUTTON_UNKNOWN = 0;
    public const GAMEPAD_BUTTON_LEFT_FACE_UP = 1;
    public const GAMEPAD_BUTTON_LEFT_FACE_RIGHT = 2;
    public const GAMEPAD_BUTTON_LEFT_FACE_DOWN = 3;
    public const GAMEPAD_BUTTON_LEFT_FACE_LEFT = 4;
    public const GAMEPAD_BUTTON_RIGHT_FACE_UP = 5;
    public const GAMEPAD_BUTTON_RIGHT_FACE_RIGHT = 6;
    public const GAMEPAD_BUTTON_RIGHT_FACE_DOWN = 7;
    public const GAMEPAD_BUTTON_RIGHT_FACE_LEFT = 8;
    public const GAMEPAD_BUTTON_LEFT_TRIGGER_1 = 9;
    public const GAMEPAD_BUTTON_LEFT_TRIGGER_2 = 10;
    public const GAMEPAD_BUTTON_RIGHT_TRIGGER_1 = 11;
    public const GAMEPAD_BUTTON_RIGHT_TRIGGER_2 = 12;
    public const GAMEPAD_BUTTON_MIDDLE_LEFT = 13;
    public const GAMEPAD_BUTTON_MIDDLE = 14;
    public const GAMEPAD_BUTTON_MIDDLE_RIGHT = 15;
    public const GAMEPAD_BUTTON_LEFT_THUMB = 16;
    public const GAMEPAD_BUTTON_RIGHT_THUMB = 17;
}

class GamepadAxis
{
    public const GAMEPAD_AXIS_LEFT_X = 0;
    public const GAMEPAD_AXIS_LEFT_Y = 1;
    public const GAMEPAD_AXIS_RIGHT_X = 2;
    public const GAMEPAD_AXIS_RIGHT_Y = 3;
    public const GAMEPAD_AXIS_LEFT_TRIGGER = 4;
    public const GAMEPAD_AXIS_RIGHT_TRIGGER = 5;
}

class ConfigFlag
{
    public const FLAG_VSYNC_HINT = 64;
    public const FLAG_FULLSCREEN_MODE = 2;
    public const FLAG_WINDOW_RESIZABLE = 4;
    public const FLAG_WINDOW_UNDECORATED = 8;
    public const FLAG_WINDOW_HIDDEN = 128;
    public const FLAG_WINDOW_MINIMIZED = 512;
    public const FLAG_WINDOW_MAXIMIZED = 1024;
    public const FLAG_WINDOW_UNFOCUSED = 2048;
    public const FLAG_WINDOW_TOPMOST = 4096;
    public const FLAG_WINDOW_ALWAYS_RUN = 256;
    public const FLAG_WINDOW_TRANSPARENT = 16;
    public const FLAG_WINDOW_HIGHDPI = 8192;
    public const FLAG_WINDOW_MOUSE_PASSTHROUGH = 16384;
    public const FLAG_BORDERLESS_WINDOWED_MODE = 32768;
    public const FLAG_MSAA_4X_HINT = 32;
    public const FLAG_INTERLACED_HINT = 65536;
}

class TraceLogLevel
{
    public const LOG_ALL = 0;
    public const LOG_TRACE = 1;
    public const LOG_DEBUG = 2;
    public const LOG_INFO = 3;
    public const LOG_WARNING = 4;
    public const LOG_ERROR = 5;
    public const LOG_FATAL = 6;
    public const LOG_NONE = 7;
}

class Core
{
    public static function init_window(int $width, int $height, string $title): void {}
    public static function set_target_fps(int $fps): void {}
    public static function window_should_close(): bool {}
    public static function begin_drawing(): void {}
    public static function end_drawing(): void {}
    public static function close_window(): void {}
    public static function clear_background(mixed $color): void {}

    // window-related
    public static function is_window_ready(): bool {}
    public static function is_window_fullscreen(): bool {}
    public static function is_window_hidden(): bool {}
    public static function is_window_minimized(): bool {}
    public static function is_window_maximized(): bool {}
    public static function is_window_focused(): bool {}
    public static function is_window_resized(): bool {}
    public static function is_window_state(int $flag): bool {}
    public static function set_window_state(int $flags): void {}
    public static function clear_window_state(int $flags): void {}
    public static function toggle_fullscreen(): void {}
    public static function toggle_borderless_windowed(): void {}
    public static function maximize_window(): void {}
    public static function minimize_window(): void {}
    public static function restore_window(): void {}
    public static function set_window_title(string $title): void {}
    public static function set_window_position(int $x, int $y): void {}
    public static function set_window_monitor(int $monitor): void {}
    public static function set_window_min_size(int $width, int $height): void {}
    public static function set_window_max_size(int $width, int $height): void {}
    public static function set_window_size(int $width, int $height): void {}
    public static function set_window_opacity(float $opacity): void {}
    public static function set_window_focused(): void {}
    public static function get_screen_width(): int {}
    public static function get_screen_height(): int {}
    public static function get_render_width(): int {}
    public static function get_render_height(): int {}
    public static function get_monitor_count(): int {}
    public static function get_current_monitor(): int {}
    public static function get_monitor_width(int $monitor): int {}
    public static function get_monitor_height(int $monitor): int {}
    public static function get_monitor_physical_width(int $monitor): int {}
    public static function get_monitor_physical_height(int $monitor): int {}
    public static function get_monitor_refresh_rate(int $monitor): int {}
    public static function get_monitor_name(int $monitor): string {}
    public static function set_clipboard_text(string $text): void {}
    public static function get_clipboard_text(): string {}
    public static function get_monitor_position(int $monitor): mixed {}
    public static function get_window_position(): mixed {}
    public static function get_window_scale_dpi(): mixed {}
    public static function enable_event_waiting(): void {}
    public static function disable_event_waiting(): void {}

    // cursor-related
    public static function show_cursor(): void {}
    public static function hide_cursor(): void {}
    public static function is_cursor_hidden(): bool {}
    public static function enable_cursor(): void {}
    public static function disable_cursor(): void {}
    public static function is_cursor_on_screen(): bool {}
    public static function set_mouse_cursor(int $cursor): void {}

    // timing-related
    public static function get_frame_time(): float {}
    public static function get_time(): float {}
    public static function get_fps(): int {}

    // keyboard
    public static function is_key_pressed(int $key): bool {}
    public static function is_key_pressed_repeat(int $key): bool {}
    public static function is_key_down(int $key): bool {}
    public static function is_key_released(int $key): bool {}
    public static function is_key_up(int $key): bool {}
    public static function get_key_pressed(): int {}
    public static function get_char_pressed(): int {}
    public static function get_key_name(int $key): string {}
    public static function set_exit_key(int $key): void {}

    // mouse
    public static function is_mouse_button_pressed(int $button): bool {}
    public static function is_mouse_button_down(int $button): bool {}
    public static function is_mouse_button_released(int $button): bool {}
    public static function is_mouse_button_up(int $button): bool {}
    public static function get_mouse_x(): int {}
    public static function get_mouse_y(): int {}
    public static function get_mouse_position(): mixed {}
    public static function get_mouse_delta(): mixed {}
    public static function set_mouse_position(int $x, int $y): void {}
    public static function set_mouse_offset(int $offsetX, int $offsetY): void {}
    public static function set_mouse_scale(float $scaleX, float $scaleY): void {}
    public static function get_mouse_wheel_move(): float {}
    public static function get_mouse_wheel_move_v(): mixed {}

    // touch
    public static function get_touch_x(): int {}
    public static function get_touch_y(): int {}
    public static function get_touch_position(int $index): mixed {}
    public static function get_touch_point_id(int $index): int {}
    public static function get_touch_point_count(): int {}

    // gamepad
    public static function is_gamepad_available(int $gamepad): bool {}
    public static function get_gamepad_name(int $gamepad): string {}
    public static function is_gamepad_button_pressed(int $gamepad, int $button): bool {}
    public static function is_gamepad_button_down(int $gamepad, int $button): bool {}
    public static function is_gamepad_button_released(int $gamepad, int $button): bool {}
    public static function is_gamepad_button_up(int $gamepad, int $button): bool {}
    public static function get_gamepad_button_pressed(): int {}
    public static function get_gamepad_axis_count(int $gamepad): int {}
    public static function get_gamepad_axis_movement(int $gamepad, int $axis): float {}
    public static function set_gamepad_mappings(string $mappings): int {}
    public static function set_gamepad_vibration(int $gamepad, float $leftMotor, float $rightMotor, float $duration): void {}
}
