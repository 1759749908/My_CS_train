#include <iostream>
#include <ctime>
using namespace std;

void game_1();
void game_2();

int main() {
	game_2();

}

void game_1() {
	cout << "请回车投两枚骰子" << endl;
	system("pause");

	srand((unsigned)time(NULL));
	int dice_1 = rand() % 6 + 1;
	int dice_2 = rand() % 6 + 1;

	cout << "你投出了：" << dice_1 << "和" << dice_2 << endl;

	int SUM = dice_1 + dice_2;
	int answer;

	switch (SUM)
	{
	case 7:
	case 11:
		cout << "you win!" << endl;
		exit(0);
	case 2:
	case 3:
	case 12:
		cout << "you lost!" << endl;
		exit(1);
	default:
		answer = SUM;
		break;
	}


	int dice;
	for (int i = 0; i < 7; i++) {
		cout << "请继续投骰子" << endl;
		system("pause");
		dice = rand() % 6 + 1;
		cout << "你投出了：" << dice << endl;
		if (dice == answer) {
			cout << "you win!" << endl;
			exit(0);
		}
		else {
			cout << "try again." << endl;
		}
	}

	cout << "you lost!" << endl;
	exit(1);
}

void game_2() {
	cout << "请回车投骰子" << endl;
	system("pause");

	srand((unsigned)time(NULL));
	int dice_1 = rand() % 6 + 1;
	int dice_2 = rand() % 6 + 1;

	cout << "你投出了：" << dice_2 << endl;
	cout << "计算机投出了：" << dice_1 << endl;

	int SUM = dice_1 + dice_2;
	int answer;

	switch (SUM)
	{
	case 7:
	case 11:
		cout << "you win!" << endl;
		exit(0);
	case 2:
	case 3:
	case 12:
		cout << "you lost!" << endl;
		exit(1);
	default:
		answer = SUM;
		break;
	}


	int dice;
	for (int i = 0; i < 7; i++) {
		cout << "请继续投骰子" << endl;
		system("pause");
		dice = rand() % 6 + 1;
		cout << "你投出了：" << dice << endl;
		if (dice == answer) {
			cout << "you win!" << endl;
			exit(0);
		}
		else {
			cout << "try again." << endl;
		}
	}

	cout << "you lost!" << endl;
	exit(1);
}