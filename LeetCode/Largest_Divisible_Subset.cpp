#include "Largest_Divisible_Subset.h"


vector<int> Largest_Divisible_Subset::test(vector<int>& nums){

	vector<int> current_nums = nums;

	vector<int> result;

	while (current_nums.size() >= 1){
		vector<int> select_nums;
		int select = current_nums[0];
		for (int i = 0; i < current_nums.size(); i++){
			vector<int> next_nums;
			for (int ii = 0; ii < current_nums.size(); ii++){
				if (i != ii && (current_nums[i] % current_nums[ii] == 0 || current_nums[ii] % current_nums[i] == 0)){
					next_nums.push_back(current_nums[ii]);
				}
			}

			if (select_nums.size() == 0 && next_nums.size() != 0){
				select_nums = next_nums;
				select = current_nums[i];
			}
			else if (select_nums.size() != 0 && next_nums.size() != 0){
				if (!(select % current_nums[i] == 0 || current_nums[i] % select == 0)){
					vector<int> option1 = test(select_nums);
					vector<int> option2 = test(next_nums);

					if (option1.size() < option2.size()){
						select_nums = option2;
						select = current_nums[i];
						//result.insert(result.end(), option2.begin(), option2.end());
					}
					else{
						select_nums = option1;
						//result.insert(result.end(), option1.begin(), option1.end());
					}
					//return result;
 				}
			}
		}

		current_nums = select_nums;

		result.push_back(select);
	}

	sort(result.begin(), result.end());
	return result;
}

vector<int> Largest_Divisible_Subset::largestDivisibleSubset(vector<int>& nums){

	if (nums.size() == 0 || nums.size() == 1){
		return nums;
	}
	sort(nums.begin(), nums.end());

	vector<int> result_train(nums.size(), -1);
	vector<int> count(nums.size(), 0);

	for (int i = nums.size() - 1; i >= 0; i--){
		for (int ii = i+1; ii < nums.size(); ii++){
			if (nums[ii] % nums[i] == 0 && 
				((result_train[i] == -1) || (result_train[i] != -1 && count[result_train[i]] <= count[ii]))){
				result_train[i] = ii;
				count[i] = count[ii] + 1;
			}
		}
	}

	int max = count[0];
	int pos = 0;

	for (int i = 0; i < count.size(); i++){
		if (max < count[i]){
			max = count[i];
			pos = i;
		}
	}

	vector<int> result;
	do{
		result.push_back(nums[pos]);
		pos = result_train[pos];
	} while (pos != -1);

	return result;
}