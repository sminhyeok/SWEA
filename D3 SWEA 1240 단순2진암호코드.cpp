//2019.09.18 12:52~13:55
#include <iostream>
#include <string>
using namespace std;

string BARCODE[50];
string CODE;
int N, M;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> BARCODE[i];
	}
}

void sep() {
	CODE = "";
	for (int i = 0; i < N; i++)
		CODE += BARCODE[i];
	string temp = "";
	int last = 0;
	for (int i = 0; i < CODE.size(); i++)
		if (CODE[i] == '1') last = i;	// 마지막 1의 위치 탐색
	for (int i = last - 55; i <= last; i++)
		temp += CODE[i];
	CODE = temp;
}

int search(int start) {
	string KEY[10] = { "0001101","0011001","0010011","0111101", "0100011","0110001","0101111","0111011","0110111", "0001011" };
	for (int i = 0; i < 10; i++) {
		bool flag = true;
		for (int j = 0; j < 7; j++) {
			if (KEY[i][j] != CODE[j + start]) { flag = false; break; }
		}
		if (flag) return i;
	}
}

int DECODER() {
	string DECODE;
	for (int start = 0; start < 8; start++) {
		DECODE += (search(start * 7)+'0');
	}
	int odd = 0, even = 0, last = 0;

	for (int i = 0; i < 4; i++)
		odd += DECODE[i * 2] - '0';
	for (int i = 0; i < 3; i++)
		even += DECODE[i * 2 + 1] - '0';
	last = DECODE[7] - '0';
	if ((odd * 3 + even + last) % 10 == 0) return odd+even+last;
	else return 0;
}

void solution() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		sep();
		cout << "#" << tc << " " << DECODER() << endl;
	}
}

int main() {
	solution();
}