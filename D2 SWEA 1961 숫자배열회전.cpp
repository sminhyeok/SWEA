//2019.09.23 10:36~10:53
#include <iostream>
#include <string>
using namespace std;

char INPUT[10][10];
string ANSWER[10][3];
int N;

void init() {
	cin >> N;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> INPUT[y][x];
	for (int y = 1; y <= N; y++)
		for (int x = 0; x < 3; x++)
			ANSWER[y][x].clear();
}

void ENTER() {
	// 첫째줄
	for (int x = 1; x <= N; x++)
		for (int y = N; y > 0; y--) 
			ANSWER[x][0] += INPUT[y][x];
	
	// 둘째줄
	for (int y = N; y > 0; y--)
		for (int x = N; x > 0; x--)
			ANSWER[N - y+1][1] += INPUT[y][x];

	// 셋째줄
	for (int x = N; x > 0; x--)
		for (int y = 1; y <= N; y++)
			ANSWER[N - x+1][2] += INPUT[y][x];
}

void print() {
	for (int y = 1; y <= N; y++) {
		for (int x = 0; x < 3; x++)
			cout << ANSWER[y][x] << " ";
		cout << endl;
	}
}

void solution() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		ENTER();
		cout << "#" << t << endl;
		print();
	}
}

int main() {
	solution();
}