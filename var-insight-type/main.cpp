#include "var-insight-type.h"
using namespace std;

int main() {
	if (1) { // 1
		var_basic();
	}

	if (1) { // 3/5
		var_arr();
		var_arr_2d();
	}
	
	if (1) { // 2/4/6/7
		var_ptr_var();
		var_ptr_arr();

		int ext[6] = { 1, 1, 2, 3, 5, 8 };
		var_ptr_ext(ext, 0);

		var_ptr_strconst();
	}

	if (1) { // 8
		var_quote();
	}

	if (1) { // 9
		int ext[6] = { 13, 21, 34, 55, 89, 143 };
		var_ptr_ext(ext, 2);
	}
	return 0;
}