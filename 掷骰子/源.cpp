#include <iostream>
#include <ctime>
using namespace std;

void game_1();
void game_2();

int main() {
	game_2();

}

void game_1() {
	cout << "��س�Ͷ��ö����" << endl;
	system("pause");

	srand((unsigned)time(NULL));
	int dice_1 = rand() % 6 + 1;
	int dice_2 = rand() % 6 + 1;

	cout << "��Ͷ���ˣ�" << dice_1 << "��" << dice_2 << endl;

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
		cout << "�����Ͷ����" << endl;
		system("pause");
		dice = rand() % 6 + 1;
		cout << "��Ͷ���ˣ�" << dice << endl;
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
	cout << "��س�Ͷ����" << endl;
	system("pause");

	srand((unsigned)time(NULL));
	int dice_1 = rand() % 6 + 1;
	int dice_2 = rand() % 6 + 1;

	cout << "��Ͷ���ˣ�" << dice_2 << endl;
	cout << "�����Ͷ���ˣ�" << dice_1 << endl;

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
		cout << "�����Ͷ����" << endl;
		system("pause");
		dice = rand() % 6 + 1;
		cout << "��Ͷ���ˣ�" << dice << endl;
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