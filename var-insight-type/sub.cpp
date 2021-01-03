#include "var-insight-type.h"
using namespace std;

// Task 01
void var_basic() {
	int var_int = 1;
	char var_ch = '\064';
	short var_short = 25151;
	long var_l = 252525252;
	long long var_ll = 253535353535353ll;

	float var_f = 2.718281f;
	double var_lf = 3.14159265358979;

	bool var_bool = false;
	
	var_int = 2;
	var_ch = '\046';
	var_short = 21515;
	var_l = 225252525;
	var_ll = 235353535353535ll;
	var_f = 3.14159f;
	var_lf = 2.71828182845904;
	var_bool = true;
}

// Task 03
void var_arr() {
	int arr[10] = { 0 };
	for (int k = 1; k <= 3; k++) {
		for (int i = 0; i < 9; i++) {
			if (arr[i] == 0) {
				arr[i] = i;
				continue;
			}
			arr[i] *= arr[i];
		}
	}
}

// Task 05
void var_arr_2d() {
	int arr[4][4] = { 0 };
	for (int k = 1; k <= 3; k++) {
		for (int m = 0; m <= 6; m++) {
			for (int n = 0; n <= m; n++) {
				if (n <= 3 && m - n <= 3) {
					arr[n][m - n] = k;
				}
			}
		}
	}
}

// Task 02
void var_ptr_var() {
	int arr[10] = { 0 };
	for (int i = 1; i <= 10; i++) {
		arr[i - 1] = i;
	}
	int* ptr = arr;
	for (int i = 0; i <= 9; i++)
		ptr++;
}

// Task 04
void var_ptr_arr() {
	int arr[4][4];
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			arr[i][j] = (1 << i) + j;
		}
	}

	int (*ptr)[4];

	for (int i = 0; i <= 3; i++) {
		ptr = &arr[i];
	}
}

// Task 06/09: 越界问题也一并在此测试
void var_ptr_ext(int* p, int offset) {
	int(*ptr)[6] = (int (*)[6])p;
	if (ptr == NULL)
		return;
	int n = sizeof((*ptr)) / sizeof((*ptr)[0]), temp, * pptr;
	n += offset;
	for (int i = 0; i < n; i++) {
		pptr = (*ptr) + i;
		temp = *pptr;
	}
}

// Task 07
void var_ptr_strconst() {
	const char* str[5] = {
		"高等数学",
		"线性代数",
		"高级语言程序设计",
		"人工智能导论",
		"并行计算导论"
	};
	const char* ptr;

	for (int i = 0; i < 5; i++) {
		ptr = str[i];
	}

	ptr = "算法与数据结构";
	ptr += 6; // 数据结构
	ptr = "面向对象程序设计";
	ptr += 8; // 程序设计
}

// Task 08
void var_quote() {
	int a = 10;
	int& b = a;

	for (int i = 1; i <= 20; i++) {
		if (i % 2 == 0)
			a++;
		else
			b++;
	}
}