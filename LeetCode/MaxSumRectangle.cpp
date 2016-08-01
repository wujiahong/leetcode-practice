#include "MaxSumRectangle.h"

int MaxSumRectangle::maxSumSubmatrix(vector<vector<int>>& matrix, int k){


	int ret = INT_MIN;

	int col = matrix.size();
	int row = matrix[0].size();

	vector<vector<int>> sum_col(col+1, vector<int>(row+1, 0));

	for (register int i = 0, ii = 1; i < col; i++, ii++){
		for (register int j = 0, jj = 1; j < row; j++, jj++){
				sum_col[ii][jj] = sum_col[i][jj] + matrix[i][j];
		}
	}

	vector<int> col_sums(row + 1, 0);
	for (register int i = 1; i <= col; i++){
		for (register int j = 0; j < i; j++){
			for (register int r = 1; r <= row; r++){
				col_sums[r] = sum_col[i][r] - sum_col[j][r];
			}
			for (register int ii = 1; ii <= row; ii++){
				int sum = col_sums[ii]; 
				if (sum == k){
					return k;
				}
				else if (sum < k && ret < sum){
					ret = sum;
				}
				for (register int jj = ii - 1; jj > 0; jj--){
					sum += col_sums[jj]; 
					if (sum == k){
						return k;
					}
					else if (sum < k && ret < sum){
						ret = sum;
					}
				}
			}
		}
	}
	return ret;
}