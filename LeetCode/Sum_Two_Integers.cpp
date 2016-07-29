#include "Sum_Two_Integers.h"

int Sum_Two_Integers::sum(int a, int b){


	int c = 0;
	int x = 1;
	int result = 0;
	int a_x, b_x;
	for (int i = 0; i < 64; i++){
		a_x = a & x;
		b_x = b & x;
		result = result | ((a_x ^ b_x) ^ c);
		c = ((a_x | b_x)&c) | (a_x&b_x);

		x <<= 1;
		c <<= 1;
	}
	return result;
}