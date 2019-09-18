//2019.09.18 17:34~18:12
#include <iostream>
using namespace std;

int MAP[20][20];

int N, X, ANSWER;

void init() {
	cin >> N >> X;
	ANSWER = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> MAP[y][x];
}



void SEARCH() {
	// 가로 방향 탐색
	for (int y = 0; y < N; y++) {
		int keep = 1, height = MAP[y][0], cross = 1;
		
		for (int x = 1; x < N; x++) {
			// 높이차 2면 불가
			if (abs(height - MAP[y][x]) >= 2) break;

			if (height == MAP[y][x]) { keep++; cross++; } // 평지
			else if (height < MAP[y][x]) {
				if (keep < X) break;
				cross++; keep = 1; height = MAP[y][x];
			}// 오르막
			else {
				keep = 0;
				bool flag = false; int temp = MAP[y][x];
				for (int mx = x; mx < x + X; mx++) {
					if (mx == N) break;
					if (temp == MAP[y][mx]) keep++;
					else break;
				}
				if (keep == X) flag = true;
				if (!flag) break;
				// 내리막 설치 가능한 곳일때
				x += X - 1; cross += X; height = temp; keep = 0;
			}// 내리막
		}
		if (cross == N) ANSWER++;
	}
	// 세로 탐색
	for (int x = 0; x < N; x++) {
		int keep = 1, height = MAP[0][x], cross = 1;
		for (int y = 1; y < N; y++) {
			if (abs(height - MAP[y][x]) >= 2) break;

			if (height == MAP[y][x]) { keep++; cross++; }
			else if (height < MAP[y][x]) {
				if (keep < X) break;
				cross++; keep = 1; height = MAP[y][x];
			}
			else {
				keep = 0;
				bool flag = false; int temp = MAP[y][x];
				for (int my = y; my < y + X; my++) {
					if (my == N) break;
					if (temp == MAP[my][x]) keep++;
					else break;
				}
				if (keep == X) flag = true;
				if (!flag) break;
				y += X - 1; cross += X; height = temp; keep = 0;
			}
		}
		if (cross == N) ANSWER++;
	}
}

void solution() {
	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		init();
		SEARCH();
		cout << "#"<< tc << " " << ANSWER << endl;
	}
}

int main() {
	solution();
}