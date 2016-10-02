#include "LongestSubstring.h"

int LongestSubstring::lengthOfLongestSubstring(string s){

	if (s.length() == 0){
		return 0;
	}
	int length = 1;

	int head = 0;
	int tail = 1;

	for (; tail < s.length(); tail++)
	{
		if (tail - head > length){
			length = tail - head;
		}
		for (int i = head; i < tail; i++)
		{
			if (s[i] == s[tail]){
				head = i+1;
				break;
			}
		}
	}
	if (tail - head > length){
		length = tail - head;
	}
	return length;

}
