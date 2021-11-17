#include <iostream>
using namespace std;


int main()
{
	struct bit_4 {
		unsigned char c1 : 4;
		unsigned char c2 : 4;

		bit_4(int i1,int i2) {
			this->c1 = i1;
			this->c2 = i2;

			cout << this << endl;
			cout << c1 << endl;
			cout << c2 << endl;

		}
	};

	bit_4(7, 5);

}