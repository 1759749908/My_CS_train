#include<iostream> 
#include<string> 
#include<vector>
#include<iomanip> 
#include<algorithm> 
using namespace std;

#define auto_clean_back true		//清理高位的0

class BigNum {
private:
	char get_number(const BigNum& T, const unsigned long long& index) const;
	char get_number(const unsigned long long& index) const;
public:
	//输出 int8_t 类型的变量实际输出的是其对应的字符, 而不是真实数字。
	//还不如直接用char
	vector<char> Num_string;
	//	bool sign = 0;	//0正，1负。
	//	算了，不肝了，目前用不到负数。
	BigNum();
	BigNum(const unsigned long long&);
	BigNum(const char*);
	BigNum(const string&);
	BigNum(const BigNum&);

	BigNum operator+(const BigNum&) const;
	//不要试图搞出负数，否则后果自负。
	BigNum operator-(const BigNum&) const;
	BigNum operator*(const char&) const;
	BigNum operator*(const BigNum& T) const;
	BigNum operator*(const unsigned long long& t) const;
	//严打高位0。
	BigNum operator/(BigNum) const;
	BigNum operator/(const int&) const;

	BigNum operator%(const BigNum&) const;
	BigNum operator%(const int&) const;

	BigNum push_zero(unsigned long long&, const BigNum&) const;
	BigNum push_zero(unsigned long long&) const;
	BigNum slice(unsigned long long&, unsigned long long&) const;
	BigNum slice(const BigNum&, unsigned long long&, unsigned long long&) const;

	bool   operator==(const BigNum&) const;
	bool   operator>(const BigNum&)const;
	bool   operator>(const int&)const;
	bool   operator<(const BigNum&)const;
	bool   operator<(const int&)const;

	void   clean_high_zero();
	//输出大数
	void print();
	void rprint();
}
;
char BigNum::get_number(const BigNum& T, const unsigned long long& index) const {
	if (index < T.Num_string.size()) { return T.Num_string[index]; }
	return 0;
}

char BigNum::get_number(const unsigned long long& index) const {
	if (index < this->Num_string.size()) { return this->Num_string[index]; }
	return 0;
}


BigNum::BigNum() {
	//什么也不做
}

BigNum::BigNum(const unsigned long long& I) {
	string tmp = to_string(I);
	for (auto it = tmp.crbegin(); it != tmp.crend(); it++) {
		this->Num_string.emplace_back(*it - '0');
	}
}

BigNum::BigNum(const char* I) {
	unsigned long long length = strlen(I);
	for (unsigned long long i = length; i > 0; i--) {
		this->Num_string.emplace_back(I[i - 1] - '0');
	}
}

BigNum::BigNum(const string& I) {
	for (auto it = I.crbegin(); it != I.crend(); it++) {
		this->Num_string.emplace_back(*it - '0');
	}
}

BigNum::BigNum(const BigNum& T) {
	this->Num_string.assign(T.Num_string.cbegin(), T.Num_string.cend());
}

BigNum BigNum::operator+(const BigNum& T) const {
	BigNum T2;
	char carry = 0;
	char L, R, SUM;
	unsigned long long len_A = this->Num_string.size();
	unsigned long long len_B = T.Num_string.size();
	unsigned long long length = len_A > len_B ? len_A : len_B;
	for (unsigned long long i = 0; i < length || carry != 0; i++) {
		L = get_number(*this, i);
		R = get_number(T, i);
		SUM = L + R + carry;
		if (SUM >= 10)	carry = SUM / 10; else carry = 0;
		T2.Num_string.emplace_back(SUM % 10);
	}
	return T2;
}

BigNum BigNum::operator-(const BigNum& T) const {
	BigNum T2;
	char carry = '\0';
	char L, R, SUM, wait_R;
	unsigned long long len_A = this->Num_string.size();
	unsigned long long len_B = T.Num_string.size();
	unsigned long long length = len_A > len_B ? len_A : len_B;
	for (unsigned long long i = 0; i < length; i++) {
		L = get_number(*this, i);
		R = get_number(T, i);
		wait_R = R + carry;
		if (L >= wait_R) {
			SUM = L - wait_R;
			carry = 0;
		}
		else {
			SUM = L - wait_R + 10;
			carry = 1;
		}
		T2.Num_string.emplace_back(SUM);
	}

#if auto_clean_back == true
	unsigned long long total_zero = 0;
	for (auto iterator = T2.Num_string.rbegin(); iterator != T2.Num_string.rend(); iterator++) {
		if (*iterator != 0) {
			total_zero++;
		}
		else {
			break;
		}
	}
	for (; total_zero > 0; total_zero--) {
		T2.Num_string.pop_back();
	}
#endif

	return T2;
}

BigNum BigNum::operator*(const char& t) const {
	BigNum T2;
	char carry = 0;
	char SUM = 0;
	for (unsigned long long i = 0; i < this->Num_string.size() || carry != 0; i++) {
		SUM = this->get_number(i) * t + carry;
		carry = 0;
		if (SUM >= 10) {
			carry = SUM / 10;
		}
		T2.Num_string.emplace_back(SUM % 10);
	}
	return T2;
}

BigNum BigNum::operator*(const unsigned long long& t) const {
	return *this * BigNum(t);
}

BigNum BigNum::operator*(const BigNum& T) const {
	BigNum T2;
	BigNum T3;
	//这里我得考虑要不要吧vector换成deque了。
	for (unsigned long long i = 0; i < T.Num_string.size(); i++) {
		T3 = *this * T.get_number(i);
		for (unsigned long long u = 0; u < i; u++) {
			T3.Num_string.insert(T3.Num_string.begin(), '\0');
		}
		T2 = T2 + T3;
	}
	return T2;
}

BigNum BigNum::operator/(const int& t) const {
	return *this / BigNum(t);
}

BigNum BigNum::operator/(BigNum T) const {
	BigNum T2(*this);
	BigNum T3;
	T2.clean_high_zero();
	T.clean_high_zero();
	unsigned long long length_this = this->Num_string.size();
	unsigned long long length_division = T.Num_string.size();

	if (length_this < length_division) return BigNum('0');

	T3.Num_string.resize(length_this,'\0');
	//for (; length_this >= length_division; length_this--) {}	//也不是不可以，就是要担心高位0的问题。
	for (; length_this >= length_division; length_this--) {
		//还好char是有符号的。
		for (char i = 9; i >= 0; i--) {
			if (T2 > T * ((length_this + 1) - length_division) * i) {
				T2 = T2 - T * ((length_this + 1) - length_division) * i;
				T3.Num_string[length_this - length_division] = i;
				break;
			}
		}
	}
	return T3;
}

BigNum BigNum::operator%(const BigNum& T) const {
	return BigNum();
}

BigNum BigNum::operator%(const int& t) const {
	return *this % BigNum(t);
	//未完待续
}

bool   BigNum::operator==(const BigNum& T) const {
	if (this->Num_string == T.Num_string) return true; else return false;
}

bool   BigNum::operator>(const BigNum& T)const {
	unsigned long long len;
	len = (this->Num_string.size() > T.Num_string.size()) ? this->Num_string.size() : T.Num_string.size();
	for (; len > 0; len--) {
		//理论上这里会出BUG，但是没出BUG???
		if (get_number(*this, len - 1) > get_number(T, len - 1)) return true;
		if (get_number(*this, len - 1) < get_number(T, len - 1)) return false;
	}
	return false;
}

bool   BigNum::operator>(const int& t)const {
	BigNum T(t);
	return *this > T;
}

bool   BigNum::operator<(const BigNum& T)const {
	return !(*this > T);
}

bool   BigNum::operator<(const int& t)const {
	BigNum T(t);
	return *this < T;
}

BigNum BigNum::push_zero(unsigned long long& total_0, const BigNum& T) const {
	BigNum T2;
	for (; total_0 > 0; total_0--) {
		T2.Num_string.emplace_back('\0');
	}
	for (const auto& i : T.Num_string) {
		T2.Num_string.emplace_back(i);
	}
	return T2;
}

BigNum BigNum::push_zero(unsigned long long& total_0) const {
	BigNum T2;
	for (; total_0 > 0; total_0--) {
		T2.Num_string.emplace_back('\0');
	}
	for (const auto& i : this->Num_string) {
		T2.Num_string.emplace_back(i);
	}
	return T2;
}

BigNum BigNum::slice(unsigned long long& first, unsigned long long& last) const {
	BigNum T2;
	auto iterator_first = this->Num_string.begin() + first;
	auto iterator_last = this->Num_string.begin() + last;

	for (; iterator_first != iterator_last + 1; iterator_first++) {
		T2.Num_string.emplace_back(*iterator_first);
	}
	return T2;
}

BigNum BigNum::slice(const BigNum& T, unsigned long long& first, unsigned long long& last) const {
	BigNum T2;
	auto iterator_first = T.Num_string.begin() + first;
	auto iterator_last = T.Num_string.begin() + last;

	for (; iterator_first != iterator_last + 1; iterator_first++) {
		T2.Num_string.emplace_back(*iterator_first);
	}
	return T2;
}

void BigNum::clean_high_zero() {
	unsigned long long total_zero = 0;
	for (auto iterator = this->Num_string.rbegin(); iterator != this->Num_string.rend(); iterator++) {
		if (*iterator != 0) {
			total_zero++;
		}
		else {
			break;
		}
	}
	for (; total_zero > 0; total_zero--) {
		this->Num_string.pop_back();
	}
}

void BigNum::print() {
	for (auto it = this->Num_string.crbegin(); it != Num_string.crend(); it++) {
		cout << *it + 0;
		//让编译器知道输出ascii码
	}
	cout << endl;
}

void BigNum::rprint() {
	for (auto it = this->Num_string.cbegin(); it != Num_string.cend(); it++) {
		cout << *it + 0;
		//让编译器知道输出ascii码
	}
	cout << endl;
}

int main() {
	BigNum a = 250;
	BigNum b = "10";
	BigNum C = a / b;
	C.print();
}