<?php

namespace Raylib;

class Core
{
    public static function init_window(int $width, int $height, string $title): void {}
    public static function set_target_fps(int $fps): void {}
    public static function window_should_close(): bool {}
    public static function begin_drawing(): void {}
    public static function end_drawing(): void {}
    public static function close_window(): void {}
    public static function clear_background(): void {}
    public static function draw_text(string $text, int $x, int $y, int $fontSize,): void {}
}
