#pragma once

using namespace std;

class GuessNumber_I{

private:
	int n;
	int pick;

public:

	GuessNumber_I(int n, int pick):n(n),pick(pick){

	}

	int guess(int num){
		if (num == pick){
			return 0;
		}
		else if (num < pick)
		{
			return 1;
		}
		else{
			return -1;
		}
	}

	int guessNumber(int n);
};