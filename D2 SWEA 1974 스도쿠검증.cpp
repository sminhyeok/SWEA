//2019.09.23 09:49~10:05
#include <iostream>
#define MAX 9
using namespace std;

int BOARD[MAX][MAX];

void init() {
	for (int y = 0; y < MAX; y++)
		for (int x = 0; x < MAX; x++)
			cin >> BOARD[y][x];
}

bool CHECK() {
	// 가로축 탐색
	for (int y = 0; y < MAX; y++) {
		bool USE[10];
		for (int i = 0; i < MAX; i++)
			USE[i] = false;
		for (int x = 0; x < MAX; x++) {
			if (!USE[BOARD[y][x]-1]) USE[BOARD[y][x]-1] = true;
			else return false;
		}
	}
	// 세로축 탐색
	for (int x = 0; x < MAX; x++) {
		bool USE[MAX];
		for (int i = 0; i < MAX; i++)
			USE[i] = false;
		for (int y = 0; y < MAX; y++) {
			if (!USE[BOARD[y][x] - 1]) USE[BOARD[y][x] - 1] = true;
			else return false;
		}
	}
	// 블록 탐색
	for(int Y = 0; Y < 3; Y++)
		for (int X = 0; X < 3; X++) {
			bool USE[MAX];
			for (int i = 0; i < MAX; i++) USE[i] = false;
			for (int BY = 0 + 3 * Y; BY < 3 + 3 * Y; BY++)
				for (int BX = 0 + 3 * X; BX < 3 + 3 * X; BX++)
					if (!USE[BOARD[BY][BX]-1]) USE[BOARD[BY][BX]-1] = true;
					else return false;
		}
	return true;
}

void solution() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		cout << "#" << t << " " << CHECK() << endl;
	}
}

int main() {
	solution();
}