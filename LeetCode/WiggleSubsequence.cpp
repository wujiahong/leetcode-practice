#include "WiggleSubsequence.h"


int WiggleSubsequence::wiggleMaxLength(vector<int>& nums){

	if (nums.size() == 0){
		return 0;
	}
	if (nums.size() == 1){
		return 1;
	}

	int flag;
	int i = 1;
	int ret = 1;

	while (i < nums.size() && nums[i] - nums[i - 1] == 0){
		i++;
	}

	if (i < nums.size()){
		if (nums[i] - nums[i - 1] > 0){
			flag = 1;
		}
		else {
			flag = -1;
		}
		ret++;
		i++;
	}

	for (; i < nums.size(); i++){
		if (flag == 1 && nums[i] - nums[i - 1] < 0){
			flag = -1;
			ret++;
		}
		else if (flag == -1 && nums[i] - nums[i - 1] > 0){
			flag = 1;
			ret++;
		}
	}
	
	return ret;
}