# C++ 程序的生前死后
### 要解决的问题
> C++进入点是main()吗？  
> 什么代码比main()更早被执行？  
> 什么代码在main()结束后才被执行？  
> 为什么上述代码可以如此行为？  
> heap 的结构如何？  
> I/O 的结构如何？  
### 前言
> 主要基于: VC 6, VC 10, 主要面向 windows 平台  
> entry-point symbol (__stdcall calling convention)  
> It is recommended that you let the linker set the entry point so that the C run-time library is initialized correctly, and C++ constructors for static objects are executed.  
> startup code 的三个可能形式：main/WinMain/DllMain  
> 在 Linux 下自定startup code: gcc xxx.c -e function_name  
### startup code 在哪儿
> VC 6 下，启动代码在 crt0.c 中, mainCRTStartup()   
> windows 下的call stack
>> _heap_init()  // heap 初始化 
>> _ioinit()  // I/O 初始化
>> GetCommandLineA()  
>> __crtGetEnvironmentStringsA()  
>> _setargv()  
>> _setenvp()  
>> _cinit()  
>> main()  
>> exit()  
