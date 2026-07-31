<?php

use Raylib\Core;
use Raylib\Color;

function main(): void
{
    Core::init_window(800, 600, "TypePHP raylib");
    Core::set_target_fps(60);
    while (!Core::window_should_close()) {
        Core::begin_drawing();
        Core::clear_background(Color::white());
        Core::end_drawing();
    }
    Core::close_window();
}
