# C++ 程序的生前死后
### 要解决的问题
* C++进入点是main()吗？  
* 什么代码比main()更早被执行？  
* 什么代码在main()结束后才被执行？  
* 为什么上述代码可以如此行为？  
* heap 的结构如何？  
* I/O 的结构如何？  
### 前言
* 主要基于: VC 6, VC 10, 主要面向 windows 平台  
* entry-point symbol (__stdcall calling convention)  
* It is recommended that you let the linker set the entry point so that the C run-time library is initialized correctly, and C++ constructors for static objects are executed.  
* startup code 的三个可能形式：main/WinMain/DllMain  
* 在 Linux 下自定startup code: gcc xxx.c -e function_name  
### startup code 在哪儿
* VC 6 下，启动代码在 crt0.c 中, mainCRTStartup()   
* windows 下的call stack
```c
1. _heap_init()  // heap 初始化 
2. _ioinit()  // I/O 初始化
// 3-6 为一些字符串的处理
3. GetCommandLineA()  
4. __crtGetEnvironmentStringsA()  
5. _setargv()  
6. _setenvp()  
7. _cinit()  // do C data initialization
8. main()  // 注意calling convention
9. exit()  
```
### _heap_init()
* 进入 main() 之前，CRT 已经做了许多工作，其中需要若干 memory ，因此当 main() 首次调用 malloc() 时，已有若干 blocks 挂在 SBH 所维护的 free lists 上头。
* SBH: Small Block Heap (1KB)
* 根据要分配的 heap 的大小 (threshold = 1KB)，来调用不同的函数
* __sbh_heap_init() 进行16个 header 的分配和初始化
* 上cookie与下cookie的作用
### _ioinit()
* I/O initialization 就是要在 client space 中建立起 stdin/stdout/stderr 及其对应的 FILEs，使程序进入 main() 之后立即可用 printf()/scanf() 等函数。
