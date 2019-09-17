//2019.09.17 18:03~20:09
#include <iostream>
using namespace std;
long long length[10];
long long MAX;
int N, MAX_INDEX;

void init() {
	cin >> N;
	MAX = 0;
	long long x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		length[i] = abs(x) + abs(y);
		if (MAX < length[i]) {
			MAX = length[i]; MAX_INDEX = i;
		}
	}
}

void SUB(int index, long long sub) {
	if (length[index] >= sub) length[index] -= sub;
	else if (length[index] % 2 == sub % 2) length[index] = 0;
	else length[index] = 1;
}

int INDEX() {
	long long index = 0, total = 0;
	while (total < MAX) {
		index++;
		total += index;
	}
	SUB(MAX_INDEX, total);
	return index;
}

int CALC() {
	long long temp = length[0];
	// 원점 도달 불가
	for (int i = 1; i < N; i++)
		if (temp % 2 != length[i] % 2) return -1;
	temp = INDEX();
	if (length[MAX_INDEX] % 2 == 0) return temp;
	else if (length[MAX_INDEX] % 2 == 1) {
		if (temp % 2 == 0) return temp + 1;
		else return temp + 2;
	}
}

void solution() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		cout << "#" << t << " " << CALC() << '\n';
	}
}

int main() {
	solution();
}