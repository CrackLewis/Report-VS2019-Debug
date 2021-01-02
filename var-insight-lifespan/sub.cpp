#include "vs-insight-lifespan.h"
using namespace std;

#ifdef STATIC_GLOBAL_DUPLICATE
static int duplicate;
#elif defined(EXTERN_GLOBAL)
int ext_glob;
#endif

// 一个行显示函数，如未定义SENTENCE_DEBUG则等一个回车
void msgline(const char* msg, const int cont) {
	int temp = 0;
	cout << msg;
#ifndef SENTENCE_DEBUG
#pragma message("If you're in the sentence-debug mode, please define the macro SENTENCE_DEBUG in the header.")
	while (1) {
		temp = _getch();
		if (temp == cont)
			break;
	}
#endif
	cout << endl;
}

#ifdef AUTO
void exp_auto_var(int arg) {
	// 常数定义
	const int varc = 11;
	const int varv[varc] = { 0, 1, 2, 1024, 114514, 998244353, 1000000007, 2147483647, -858993460, -1073741812, -1 };
	const int default_val = 0;

	// 变量定义
	int auto_var = default_val;

	// 对形参反复进行写操作
	for (int order = 1; order < varc; order += 2) {
		arg = varv[order];
	}

	// 对自动变量反复进行写操作
	for (int _order = 0; _order < varc; _order += 2) {
		auto_var = varv[_order];
	}

}
#elif defined(STATIC_REGIONAL)
void exp_static_region() {
	// 常数定义
	const int varc = 11;
	const int varv[varc] = { 0, 1, 2, 1024, 114514, 998244353, 1000000007, 2147483647, -858993460, -1073741812, -1 };
	const int default_val = 0;

	// 变量定义
	static int stat_re = default_val;

	// 对静态局部进行反复写操作
	for (int order = 0, i = 1; i <= 20; order = (order + 3) % varc, i = i + 1) {
		stat_re = varv[order];
	}
}
#elif defined(STATIC_GLOBAL_DUPLICATE)
void exp_static_glob_ext1() {
	const int dup_init = 0x0;
	
	duplicate = dup_init;
	while (duplicate <= 0x00000014) {
		duplicate += 2;
	}
}

void exp_static_glob() {
	exp_static_glob_ext1();
	exp_static_glob_ext2(&duplicate);
}

#elif defined(EXTERN_GLOBAL)
void exp_ext_glob_ext1() {
	const int ext_glob_init = 0x0;

	ext_glob = ext_glob_init;
	while (ext_glob <= 0x00000020) {
		ext_glob += 3;
	}
}

void exp_ext_glob() {
	exp_ext_glob_ext1();
	exp_ext_glob_ext2();
}
#endif

int sub() {
	if (1) {
#if defined(AUTO)
		int auto_var = 0;
		exp_auto_var(auto_var);
#elif defined(STATIC_REGIONAL)
		exp_static_region();
#elif defined(STATIC_GLOBAL_DUPLICATE)
		exp_static_glob();
#elif defined(EXTERN_GLOBAL)
		exp_ext_glob();
#else
#pragma message("No specific macro defined. Check the header and add one preprocessor.")
		msgline(
			"No specific macro defined. Add one of the following preprocessors in the header and try again: \r\n"
			"\t#define AUTO\n"
			"\t#define STATIC_REGIONAL\n"
			"\t#define STATIC_GLOBAL_DUPLICATE\n"
			"\t#define EXTERN_GLOBAL\n"
			"Function sub() is being terminated."
		);
		return 13;
#endif
	}
	return 0;
}