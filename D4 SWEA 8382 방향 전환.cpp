//2019.09.11 13:34~14:47 수학적 접근
#include <iostream>
using namespace std;

int X1, Y1, X2, Y2, GAPX, GAPY;

void init() {
	cin >> X1 >> Y1 >> X2 >> Y2;
	X1 += 100; Y1 += 100; X2 += 100; Y2 += 100;
	GAPX = abs(X2 - X1); GAPY = abs(Y2 - Y1);
}

int MIN(int a, int b) { return a < b ? a : b; }
int MAX(int a, int b) { return a > b ? a : b; }
int CALC() {
	int distance = 0;
	int min = MIN(GAPX, GAPY); 
	for (int i = 1; i <= min; i++)
		distance += 2;
	GAPX -= min; GAPY -= min;
	int max = MAX(GAPX, GAPY);
	for (int m = 1; m <= max; m++) {
		if (m % 2 == 1) distance += 1;
		else distance += 3;
	}
	return distance;
}

void solution() {
	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; test++) {
		init();
		cout << "#" << test << " " << CALC() << endl;
	}
}

int main() {
	solution();
}