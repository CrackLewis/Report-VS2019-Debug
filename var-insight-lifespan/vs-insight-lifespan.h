#pragma once
#include <iostream>
#include <conio.h>

// ��ȷ�����б���ѡ��ȡ��ע��һ����

//#define AUTO
//#define STATIC_REGIONAL
//#define STATIC_GLOBAL_DUPLICATE
//#define EXTERN_GLOBAL

void msgline(const char* msg, const int cont = '\r');
void exp_static_glob_ext2(int* _dup = NULL);
void exp_ext_glob_ext2();
int sub();