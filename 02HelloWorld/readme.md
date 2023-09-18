# HelloWorld

## Makefile 基本语法

```shell
目标:依赖
Tab 命令
```

- 目标：一般是指要编译的目标，也可以是一个动作
- 依赖：指执行当前目标所要依赖的先项，包括其他目标，某个具体文件或库等。一个目标可以有多个依赖
- 命令：该目标下要执行的具体命令，可以没有，也可以多条。多条时，每条命令一行

示例文件：

- 命令前加@，抑制命令本身输出
- 未指定目标时，默认执行第一个目标
- a 依赖 b，所以会执行 b 再执行 a

```Makefile
a:b
	@echo "hello world"		#输出hello world
	@ls ./					#查看当前目录下文件
	gcc -lstdc++ main.cpp	#编译源文件

b:
	@echo "hello world!"

clean:
	@rm -rf a.out			#清除编译后产生的.out文件
	@echo "make clean success"
```

## Makefile 常用选项

make 默认在当前目录中寻找 GNUmakefile，makefile，Makefile 的文件作为 make 的输入文件。

```Makefile
make [-f file] [options] [target]
```

参数解释：

- -f: 可以指定除上述文件名之外的文件作为输入文件
- -v: 显示版本号
- -n: 只输出命令，但不执行，一般用来测试
- -s: 只执行命令，但不显示具体命令，此处可在命令中用@抑制命令输出
- -w: 显示执行前执行后的路径
- -C: dir 指定 makeflie 所在的目录
