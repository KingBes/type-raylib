# type-raylib 项目记忆

## 定位
TypePHP（tpc AOT）把 raylib 6.0 绑定到 PHP 的项目；产物是内嵌 Zend 运行时、链接系统图形库的独立可执行文件。

## 绑定约定（重要，改代码前必读）
- PHP API 声明在 `raylib.stub.php`（`Raylib\*` 类 + 类型签名）。
- C++ 胶水在 `src/*.cc`，函数命名 `php_<ns>__<class>__<method>(Object &_this, ...)`，基于 PHP-X（`phpx.h`）。
- 编译器生成 `build/raylib.stub.cc`（trampoline：参数个数校验 + php::toInt/toString 转换）与 `build/extension-tphp_raylib.cc`（MINIT 注册、RINIT eval main()）。
- Zend 类 entry 变量名：`php_class_entry_Raylib_<Class>`。

## 构建
- `tpc windows.yml` / `tpc linux.yml`。yml 控制 sources / include-paths / ld-flags / defines / mode:bin。
- Windows 用 `compat/` 兼容头（含 `compat/GL/gl.h`、`compat/user32_ext.def`）；`include/raylib_compat.h` 处理 windows.h 与 raylib 符号冲突。
- `tpc` 在 `C:\env\swoole_compiler\tpc.exe`（v0.4.3）。**Git Bash 陷阱**：`/usr/bin/link`(coreutils) 会抢占 MSVC `link.exe` 致链接失败，编译前需 `export PATH="/c/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/<ver>/bin/Hostx64/x64:$PATH"`。
- `func_decl.h` 由编译器每次从 stub.php 重新生成，无需手维护，只需保证 stub 声明与 .cc 定义签名一致。

## 当前覆盖
- 绑定分层：`Raylib\Color`(26 调色板+make) / `Raylib\Vector2`(make/x/y) / 7 个整型常量类(Key/MouseButton/MouseCursor/GamepadButton/GamepadAxis/ConfigFlag/TraceLogLevel，约190常量) / `Raylib\Core` 约93个方法(窗口/光标/计时/键盘/鼠标/触摸/手柄)。
- 尚未绑定：绘制模式/相机/着色器、Shapes/Textures/Text/Models/Audio 全模块（需更多 Box：Rectangle/Image/Texture/Camera/Shader 等）。

## 用户偏好（来自全局记忆）
- 实用性优先，不盲目预防性优化；只改实际痛点；潜伏边界 bug 若无实际依赖可暂不修但须诚实标注。
