# Makefile 执行流程

make target 会先判断 prerequisites 是否存在：

- 无前置条件，判断 make 在目录下 target 文件是否存在：
  - （1.a）已存在，命令不执行 （使用.PHONY:target ...,无视文件是否存在，执行命令）
  - 不存在，命令执行
- 有前置条件，先依次执行前置条件，判断 make 目录下 prerequisites 文件是否存在：
  - 若存在，先判断文件是否更新
    - 未更新，根据 1.a 进行判断（推荐使用，避免每次执行都要编译）
    - 更新，target，命令必须执行
  - 若不存在，匹配目标，循环上述条件

流程的目的：

- 保证目标是用最新的依赖生成的
- 第一次完全编译，后面只编译最新的代码（部分编译），提高编译的速度
