
#include "stdafx.h"

#include "Super_Pow.h"



vector<int> sub(const vector<int>& a, const vector<int>& b){

	vector<int> b_temp;

	int a_length = a.size();
	int b_length = b.size();

	for (int i = 0; i < a_length - b_length; i++){
		b_temp.push_back(0);
	}
	for (int i = 0; i < b_length; i++){
		b_temp.push_back(b[i]);
	}

	int carry = 0;
	vector<int> result;
	for (int i = a_length - 1; i >= 0; i--){
		if (a[i] - carry >= b_temp[i]){
			result.insert(result.begin(), a[i] - carry - b_temp[i]);
			carry = 0;
		}
		if (a[i] - carry < b_temp[i]){
			result.insert(result.begin(), a[i] - carry + 10 - b_temp[i]);
			carry = 1;
		}
	}

	int i = 0;
	while (result[i] == 0){
		i++;
	}
	if (i != 0){
		result.erase(result.begin(), result.begin() + i);
	}
	return result;
}

int compare(const vector<int>& a, const vector<int>& b){
	if (a.size() > b.size()){
		return 1;
	}
	if (a.size() == b.size()){
		int length = a.size();
		for (int i = 0; i < length; i++)
		{
			if (a[i] > b[i]){
				return 1;
			}
			if (a[i] < b[i]){
				return -1;
			}
		}
		return 0;
	}
	if (a.size() < b.size()){
		return -1;
	}
}

int Super_Pow::superPow(int a, vector<int>& b){

	char* char_a = int_to_char(a);

	char* char_b = new char(b.size() + 1);
	memset(char_b, '\0', b.size() + 1);

	for (int i = 0; i < b.size(); i++){
		char_b[i] = b[i];
	}

	char* result = exponent(char_a, char_b);

	result = char_mod(result, "1337");

	int ret = 0;
	int times = 10;
	for (int i = strlen(result) - 1; i >= 0; i--){
		if (i == strlen(result) - 1){
			ret += result[i];
		}
		else{
			ret += (result[i] * times);
			times *= 10;
		}
	}
	return ret;
}

char* Super_Pow::exponent(char* a, char* b){

	char c_2[2] = "\0";
	c_2[0] = 2;

	char c_1[2] = "\0";
	c_1[0] = 1;

	char c_0[2] = "\0";
	c_0[0] = 0;

	if (strlen(b) == 1 && b[0] == 1){
		return a;
	}
	else if (strlen(b) >= 1 && strcmp(char_mod(b, c_2), c_0) == 0){
		return char_mul(exponent(a, char_div(b, c_2)), exponent(a, char_div(b, c_2)));
	}
	else if (strlen(b) >= 1 && strcmp(char_mod(b, c_2), c_1) == 0)
	{
		return char_mul(char_mul(a, a), a);
	}

	return "";
}

char* Super_Pow::int_to_char(int a){
	vector<int> int_vector;

	while (a != 0){
		int_vector.push_back(a%10);
		a = a / 10;
	}

	char* char_num = new char(int_vector.size() + 1);
	memset(char_num, '\0', int_vector.size() + 1);

	for (int i = int_vector.size() - 1, j = 0; i >=0 ; i--, j++){
		char_num[j] = int_vector[i];
	}

	return char_num;
}

char* Super_Pow::char_mul(char* a, char* b){


	char* result;
	vector<vector<int>> mul_middle_result;
	int a_length = strlen(a);
	int b_length = strlen(b);

	vector<int>* int_list;

	int longest = 0;

	int carry;
	for (int i = a_length - 1; i >= 0; i--)
	{
		int_list = new vector < int > ;

		carry = 0;
		int mul_temp_result = 0;
		for (int ii = b_length - 1; ii >= 0; ii--){

			mul_temp_result = a[i] * b[ii] + carry;
			mul_temp_result %= 10;
			carry = mul_temp_result/10;

			(*int_list).push_back(mul_temp_result);
		}
		if (carry != 0){
			(*int_list).push_back( carry);
		}

		for (int ii = 1; ii < a_length - i; ii++)
		{
			(*int_list).insert((*int_list).begin(), 0);
		}

		mul_middle_result.push_back(*int_list);

		if (i == 0){

			longest = (*int_list).size();

			for (int ii = 0; ii < a_length - 1; ii++){
				int_list = &mul_middle_result[ii];
				int loop = longest - (*int_list).size();
				for (int iii = 0; iii < loop; iii++){
					(*int_list).push_back(0);
				}
			}
		}
	}

	int sum_loop = mul_middle_result.size();
	int sum;
	carry = 0;
	vector<int> temp_result;
	for (int i = 0; i < longest; i++){
		sum = carry;
		for (int ii = 0; ii < sum_loop; ii++){
			sum += mul_middle_result[ii][i];
		}
		carry = sum / 10;
		sum = sum % 10;

		temp_result.push_back(sum);
	}
	if (carry != 0){
		temp_result.push_back(carry);
	}

	result = new char(temp_result.size() + 1);
	memset(result, '\0', temp_result.size() + 1);
	for (int i = temp_result.size() - 1, j = 0; i >=0; i--, j++){
		result[j] = temp_result[i];
	}

	return result;
}

char* Super_Pow::char_div(char* a, char* b){

	int a_length = strlen(a);
	int b_length = strlen(b);

	vector<int> a_vector;
	vector<int> b_vector;

	for (int i = 0; i < a_length; i++){
		a_vector.push_back(a[i]);
	}
	for (int i = 0; i < b_length; i++){
		b_vector.push_back(b[i]);
	}

	int compare_result;
	vector<int> div_middle_result;
	if ((compare_result = compare(a_vector, b_vector)) == 1){
		b_vector.push_back(0);
		div_middle_result.push_back(0);
		while ((compare_result = compare(a_vector, b_vector)) == 1){
			b_vector.push_back(0);
			div_middle_result.push_back(0);
		}
		if (compare_result == 0){
			div_middle_result[0]++;
			int result_len = div_middle_result.size();
			char* result = new char(result_len+1);
			memset(result, '\0', result_len + 1);
			for (int i = 0; i < result_len; i++){
				result[i] = div_middle_result[i];
			}
			return result;
		}

		int position = 0;
		while (b_vector.size() > b_length){
			b_vector.pop_back();
			a_vector = sub(a_vector, b_vector);
			div_middle_result[position]++;
			while ((compare_result = compare(a_vector, b_vector)) == 1){
				a_vector = sub(a_vector, b_vector);
				div_middle_result[position]++;
			}
			if (compare_result == 0){
				div_middle_result[position]++;
				int result_len = div_middle_result.size();

				char* result = new char(result_len + 1);
				memset(result, '\0', result_len + 1);
				for (int i = 0; i < result_len; i++){
					result[i] = div_middle_result[i];
				}
				return result;
			}
			position++;
		}
	}
	else if (compare_result == 0){
		char c_1[2] = "\0";
		c_1[0] = 1;
		return c_1;
	}
	else{
		char c_0[2] = "\0";
		c_0[0] = 0;
		return c_0;
	}
}

char* Super_Pow::char_mod(char* a, char* b){

	int a_length = strlen(a);
	int b_length = strlen(b);

	vector<int> a_vector;
	vector<int> b_vector;

	for (int i = 0; i < a_length; i++){
		a_vector.push_back(a[i]);
	}
	for (int i = 0; i < b_length; i++){
		b_vector.push_back(b[i]);
	}

	int compare_result;
	if ((compare_result = compare(a_vector, b_vector)) == 1){
		b_vector.push_back(0);
		while ((compare_result = compare(a_vector, b_vector)) == 1){
			b_vector.push_back(0);
		}
		if (compare_result == 0){
			char c_0[2] = "\0";
			c_0[0] = 0;
			return c_0;
		}

		while (b_vector.size() > b_length){
			b_vector.pop_back();
			a_vector = sub(a_vector, b_vector);
			while ((compare_result = compare(a_vector, b_vector)) == 1){
				a_vector = sub(a_vector, b_vector);
			}
			if (compare_result == 0){
				char c_0[2] = "\0";
				c_0[0] = 0;
				return c_0;
			}
		}

		int result_len = a_vector.size();
		char* result = new char(result_len + 1);

		memset(result, '\0', result_len + 1);

		for (int i = 0; i < result_len; i++){
			result[i] = a_vector[i];
		}

		return result;

	}else if (compare_result == 0){
		char c_0[2] = "\0";
		c_0[0] = 0;
		return c_0;
	}else{
		return a;
	}
}


