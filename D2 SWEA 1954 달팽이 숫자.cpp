//2019.09.23 10:06~10:35
#include <iostream>
using namespace std;
int MAP[10][10];
int N;

void init() {
	cin >> N;
}

void ENTER() {
	int NUM = 1;
	for (int i = 1; i <= N*N ; i++) {
		if (N - i / 2 == 0) break;

		// 위쪽
		if (i % 4 == 1) {
			for (int x = i / 4; x < N - i / 4; x++) {
				MAP[i / 4][x] = NUM++;
			}
		}
		// 오른쪽
		if (i % 4 == 2) {
			for (int y = 1 + i / 4; y < N - i / 4; y++)
				MAP[y][N - 1 - i / 4] = NUM++;
		}
		// 아래쪽
		if (i % 4 == 3) {
			for (int x = N - 2 - i / 4; x >= i / 4; x--) {
				MAP[N -1 - i / 4][x] = NUM++;
			}
		}
		// 왼쪽
		if (i % 4 == 0) {
			for (int y = N -1 - i / 4; y >= i / 4; y--)
				MAP[y][(i/4)-1] = NUM++;
		}
	}
}

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++)
			cout << MAP[y][x] << " ";
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