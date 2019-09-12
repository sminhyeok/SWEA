//2019.09.12 21:08~21:55
#include <iostream>
using namespace std;

int N, A, B;	// N���� ����, A��ŭ ���̰ų�, ���� �����Ȱ� B��ŭ ��������
int LETTER[100], READ[100];

void init() {
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		cin >> LETTER[i];
		READ[i] = 0;
	}
	
}

void calc() {
	int START = 0, FINISH = 0, LEFT = 0; // �б� ����, ��, �о�� �� ��
	int T = 0;
	while (READ[N - 1] == 0) {
		T++;
		if (FINISH < N && LETTER[FINISH] == T) { FINISH++; LEFT++; }

		if (LEFT == A || T == LETTER[START] + B) {
			for (int i = START; i < START + LEFT /2 + LEFT % 2; i++) 
				READ[i] = T;
			
			START += LEFT / 2 + LEFT % 2;
			LEFT =  LEFT - (LEFT / 2 + LEFT % 2);
		}
	}
}

void print() {
	for (int i = 0; i < N; i++)
		cout <<" " << READ[i];
	cout << endl;
}

void solution() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		init();
		calc();
		cout << "#" << i; 
		print();
	}	
}

int main() {
	solution();
}