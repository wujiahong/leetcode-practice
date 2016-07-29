#include "GuessNumber_I.h"

int GuessNumber_I::guessNumber(int n){

	int start = 1;
	int end = n;

	while (start <= end){
		if (guess(start) == 0){
			return start;
		}
		if (guess(end) == 0){
			return end;
		}
		int mid = (end - start) / 2 + start;
		int guess_result = guess(mid);
		if (guess_result == 0){
			return mid;
		}
		else if (guess_result == -1){
			start = start + 1;
			end = mid - 1;
		}
		else{
			start = mid + 1;
			end = end - 1;
		}
	}
	return 0;
}


