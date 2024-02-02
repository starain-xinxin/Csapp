***********************
The CS:APP Data Lab
Directions to Students
***********************

Your goal is to modify your copy of bits.c so that it passes all the
tests in btest without violating any of the coding guidelines.
您的目标是修改bits.c的副本，使其通过所有的测试
在不违反任何编码准则的情况下。

*********
## 0. Files: 文件说明
*********

Makefile	- Makes btest, fshow, and ishow
README		- This file
bits.c		- The file you will be modifying and handing in  修改并上交的文件
bits.h		- Header file
btest.c		- The main btest program
  btest.h	- Used to build btest
  decl.c	- Used to build btest
  tests.c       - Used to build btest
  tests-header.c- Used to build btest
dlc*		- Rule checking compiler binary (data lab compiler)	 规则检查编译器二进制(数据实验室编译器)
driver.pl*	- Driver program that uses btest and dlc to autograde bits.c 驱动程序，使用btest和dlc自动升级bits.c
Driverhdrs.pm   - Header file for optional "Beat the Prof" contest  可选的“击败教授”比赛的头文件
fshow.c		- Utility for examining floating-point representations  用于检查浮点表示的实用程序
ishow.c		- Utility for examining integer representations  检查整数表示的实用程序

***********************************************************
## 1. Modifying bits.c and checking it for compliance with dlc  修改bits.c并检查它是否符合dlc
***********************************************************

IMPORTANT: Carefully read the instructions in the bits.c file before you start. 
重要提示:在使用之前，请仔细阅读bits.c文件中的说明
These give the coding rules that you will need to follow if you want full credit.
这些给出了你需要遵循的编码规则，如果你想要全学分。

Use the dlc compiler (./dlc) to automatically check your version of
bits.c for compliance with the coding guidelines:
使用dlc编译器(./dlc)自动检查bits.c以符合编码指引:

       unix> ./dlc bits.c

dlc returns silently if there are no problems with your code.
如果您的代码没有问题，dlc将静默返回。
Otherwise it prints messages that flag any problems. 
 否则，它将打印标记任何问题的消息。
Running dlc with the -e switch:
打开-e开关运行：

    	unix> ./dlc -e bits.c  

causes dlc to print counts of the number of operators used by each function.
使dlc打印每个函数使用的操作符数目的计数。

Once you have a legal solution, you can test it for correctness using
the ./btest program.
一旦有了合法的解决方案，就可以使用./btest程序。

*********************
## 2. Testing with btest 测试
*********************

The Makefile in this directory compiles your version of bits.c with
additional code to create a program (or test harness) named btest.
这个目录中的Makefile用创建名为btest的程序(或测试工具)的附加代码。

To compile and run the btest program, type:

    unix> make btest
    unix> ./btest [optional cmd line args]

You will need to recompile btest each time you change your bits.c program. 
每次更改bits.c程序时，都需要重新编译btest。
When moving from one platform to another, you will want to get rid of the old version of btest and generate a new one.  
当从一个平台迁移到另一个平台时，您可能希望摆脱旧版本的btest并生成一个新版本。
Use the commands:
使用如下命令：

    unix> make clean
    unix> make btest

Btest tests your code for correctness by running millions of test cases on each function.  It tests wide swaths around well known corner
cases such as Tmin and zero for integer puzzles, and zero, inf, and the boundary between denormalized and normalized numbers for floating
point puzzles. When btest detects an error in one of your functions,it prints out the test that failed, the incorrect result, and the expected result, and then terminates the testing for that function.
Btest通过在每个函数上运行数百万个测试用例来测试代码的正确性。它在一个众所周知的角落里测试了大片土地
例如整数谜题的Tmin和0，以及浮点数的零、inf以及非规范化和规范化数字之间的边界
谜题。当btest检测到某个函数中的错误时，它会打印出失败的测试、不正确的结果和预期的结果，然后终止对该函数的测试。

Here are the command line options for btest:
btest的命令选项：

  unix> ./btest -h
  Usage: ./btest [-hg] [-r <n>] [-f <name> [-1|-2|-3 <val>]*] [-T <time limit>]
    -1 <val>  Specify first function argument
    -2 <val>  Specify second function argument
    -3 <val>  Specify third function argument
    -f <name> Test only the named function
    -g        Format output for autograding with no error messages
    -h        Print this message
    -r <n>    Give uniform weight of n for all problems
    -T <lim>  Set timeout limit to lim
-1指定第一个函数参数
-2指定第二个函数参数
-3指定第三个函数参数
-f只测试指定函数
-g格式化自动分级的输出，没有错误信息
-h打印此消息
给所有问题统一的权值n
-T将超时限制设置为lim

Examples:

  Test all functions for correctness and print out error messages:
  测试所有函数的正确性并打印出错误消息:
  unix> ./btest

  Test all functions in a compact form with no error messages:
  以紧凑的形式测试所有函数，没有错误消息:
  unix> ./btest -g

  Test function foo for correctness:
  测试函数foo的正确性:
  unix> ./btest -f foo

  Test function foo for correctness with specific arguments:
  测试函数foo特定参数的正确性:
  unix> ./btest -f foo -1 27 -2 0xf

Btest does not check your code for compliance with the coding
guidelines.  Use dlc to do that.
Btest不检查您的代码是否符合代码指导方针。使用dlc来做到这一点。

*******************
3. Helper Programs
*******************

We have included the ishow and fshow programs to help you decipher integer and floating point representations respectively. Each takes a
single decimal or hex number as an argument. To build them type:
我们已经包括了ishow和fshow程序来帮助您分别破译整数和浮点表示。每个都需要一个单个十进制或十六进制数字作为参数。要构建它们，输入:

    unix> make

Example usages:

    unix> ./ishow 0x27
    Hex = 0x00000027,	Signed = 39,	Unsigned = 39

    unix> ./ishow 27
    Hex = 0x0000001b,	Signed = 27,	Unsigned = 27

    unix> ./fshow 0x15213243
    Floating point value 3.255334057e-26
    Bit Representation 0x15213243, sign = 0, exponent = 0x2a, fraction = 0x213243
    Normalized.  +1.2593463659 X 2^(-85)

    linux> ./fshow 15213243
    Floating point value 2.131829405e-38
    Bit Representation 0x00e822bb, sign = 0, exponent = 0x01, fraction = 0x6822bb
    Normalized.  +1.8135598898 X 2^(-126)

    中文翻译



