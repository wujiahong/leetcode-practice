
#pragma once

#include <vector>

using namespace std;

class Find_K_Pairs{

public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);

	bool checkExist(int nums1_pos, int nums2_pos, vector<vector<pair<int, int>>*>& except);
};