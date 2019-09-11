//2019.09.09 20:33~21:44 DP사용
#include <iostream>
#define N 1000000
using namespace std;

unsigned long long DP[21][N+1];
unsigned long long DP2[N + 1];

void calc(int n) {
	int index[21];	// 2Áø¼ö ÀúÀå
	int K = 0;
	int temp = n;
	while (temp) {
		index[K++] = temp % 2;
		temp /= 2;
	}
	DP2[n] = 1;
	for (int i = K; i > 0; i--) {
		if (index[i - 1]) {
			DP2[n] = (DP2[n] * DP[i][n]) % 1000000007;
		}
	}
}

void DYNAMIC() {
	DP2[1] = 1;
	for (unsigned long long i = 2; i <= N; i++) {
		DP[1][i] = i; int K = 1;
		for (int j = 2; j <= i; j *= 2) {
			DP[K + 1][i] = (DP[K][i] * DP[K][i]) % 1000000007; K++;
		}
		calc(i);
		DP2[i] = (DP2[i] + DP2[i - 1]) % 1000000007;
	}
}

int main() {
	DYNAMIC();
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n;
		cout << "#" << t << " " << DP2[n] << endl;
	}
}

