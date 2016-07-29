// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Super_Pow.h"
#include "GuessNumber_I.h"
#include "Sum_Two_Integers.h"
#include "Largest_Divisible_Subset.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//Super_Pow super_pow;

	//int a = 12;
	//vector<int> b;
	//b.push_back(2);
	//b.push_back(2);

	//int ret = super_pow.superPow(a, b);

	//cout << ret;

	//GuessNumber_I guessNumber(10, 6);

	//cout << guessNumber.guessNumber(10);

	//Sum_Two_Integers sumTwoInt;
	//int ret = sumTwoInt.sum(-70, 9);
	//cout << ret;

	vector<int> nums;

	/*nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	//nums.push_back(8);
	nums.push_back(9);
	//nums.push_back(10);
	//nums.push_back(11);
	nums.push_back(12);
	//nums.push_back(11);
	//nums.push_back(16);*/

	for (int i = 1; i < 1001; i++){
		nums.push_back(i);
	}
	Largest_Divisible_Subset largest_Divisible_Subset;
	nums = largest_Divisible_Subset.largestDivisibleSubset(nums);

	cout << "( ";
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	cout << ")";

	return 0;
}

