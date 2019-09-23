//2019.09.23 14:17~15:54
#include <iostream>
#include <string>
using namespace std;

string INPUT;
int CHANGE, ORDER[6];

void init() {
	cin >> INPUT >> CHANGE;

	for (int i = 0; i < INPUT.size(); i++) {
		int order = 1;
		for (int j = 0; j < INPUT.size(); j++) {
			if (INPUT[i] < INPUT[j]) order++;
		}
		ORDER[i] = order;
	}
}

void swap(int a, int b) {
	char temp = INPUT[a];
	INPUT[a] = INPUT[b];
	INPUT[b] = temp;
}

void FIND() {
	for (int i = 0; i < INPUT.size() - 1; i++) {
		if (CHANGE == 0) break;
		int index = i+1;
		int small = INPUT[i] - '0', large = INPUT[index]-'0';
		for (int j = i + 2; j < INPUT.size(); j++) {
			if (large < INPUT[j] - '0') { large = INPUT[j] - '0'; index = j; }
			else if (large == INPUT[j] - '0') {
				if (ORDER[i]-1 >= j) index = j;
			}
		}
		if (small < large) { CHANGE--; swap(i, index); }
	}

	if (CHANGE % 2 == 1) {
		for (int i = 0; i < INPUT.size() - 1; i++) {
			for (int j = i + 1; j < INPUT.size(); j++)
				if (INPUT[i] == INPUT[j]) return;
		}
		swap(INPUT.size() - 2, INPUT.size() - 1);
	}
}

void solution() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		FIND();
		cout << "#" << t << " " << INPUT << endl;
	}
}

int main() {
	solution();
}