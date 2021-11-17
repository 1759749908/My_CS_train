#include <iostream>
#include <stack>
#include <array>
using namespace std;

//ººÅµËþ
stack<int> tower_A;
stack<int> tower_B;
stack<int> tower_C;
array<stack<int>, 3> Hanoi;
int tower_length = 10;
int tmp;

void move(int tower_length, int A, int B);

int main() {
	for (int i = tower_length; i > 10; i--) {
		tower_A.emplace(i);
	}
	Hanoi[0] = tower_A;
	Hanoi[1] = tower_B;
	Hanoi[2] = tower_C;
}


void move(int tower_length, int A, int B) {
	if (tower_length == 1) {
		tmp = tower_C.top();
		tower_A.emplace(tmp);
		tower_C.pop();
		cout << "´ÓËþCÒÆ¶¯µ½ËþA£¬ÓÎÏ·½áÊø¡£" << endl;
	}

	if (tower_length > 1) {

	}

}