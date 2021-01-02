#pragma once
#include <iostream>
#include <conio.h>

// 请确保下列编译选项取消注释一个。

//#define AUTO
//#define STATIC_REGIONAL
//#define STATIC_GLOBAL_DUPLICATE
//#define EXTERN_GLOBAL

void msgline(const char* msg, const int cont = '\r');
void exp_static_glob_ext2(int* _dup = NULL);
void exp_ext_glob_ext2();
int sub();