#include "vs-insight-lifespan.h"
using namespace std;

// 全局变量声明
#ifdef STATIC_GLOBAL_DUPLICATE
static int duplicate;
#elif defined(EXTERN_GLOBAL)
extern int ext_glob;
#endif

// 用于实验的函数
#ifdef STATIC_GLOBAL_DUPLICATE
void exp_static_glob_ext2(int* _dup) {
	const int dup_init = 0x7fffffff;

	duplicate = dup_init;

	while (duplicate >= 1) {
		duplicate >>= 1;
	}
}
#elif defined(EXTERN_GLOBAL)
void exp_ext_glob_ext2() {
	while (ext_glob) {
		ext_glob >>= 1;
	}
}
#endif