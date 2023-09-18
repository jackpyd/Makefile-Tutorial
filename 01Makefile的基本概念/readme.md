# 相关概念

## Makefile

一个工程中的源文件不计其数，其按类型、功能、模块分别放在若干个目录中，makefile 定义了一系列的规则来指定哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂的功能操作。

> Makefile 是一个文件。

## Make 与 Makefile 之间的关系

make 是一个命令工具，它解释 Makefile 中的指令。在 Makefile 文件中描述了整个工程所有文件的编译顺序、编译规则。

## Makefile 命名规则

文件名可以采用 Makefile 或 makefile，一般使用 Makefile

## CMake

CMake 是一个跨平台的安装（编译）工具，可以用简单的语句来描述所有平台的安装(编译过程)。它能够输出各种各样的 makefile 或者 project 文件，能测试编译器所支持的 C++特性,类似 UNIX 下的 qutomake。只是 CMake 的组态档取名为 **CMakelists.txt**。Cmake 并不直接建构出最终的软件，而是产生标准的建构档（如 Unix 的 Makeflle 或 Windows Visual C++ 的 projects/workspaces），然后再依一般的建构方式使用。

> CMake 根据 CMakeLists.txt 的内容，生成 Makefile 文件。

## CMake 和 CMakelists 的关系

Cmake 是一个命令工具，可用来生成 makefile。但也要根据 CMakeLists.txt 中的内容来生成，CMakeLists.txt 就是写给 cmake 的规则。

## 总结

- make 是一个命令工具，Mckefie 是一个文件，make 执行的时候，去读取 Makefle 文件中的热则，重点是 makefle 得自己写。
- cmake 是一个命令工具，CMakeliststxt 是一个文件，cmake 执行的时候，去读取 CMake 快建鞋北 文件中的规则，重点是 CMakeliststxt 得自己号。
