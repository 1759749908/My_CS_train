//#include <iostream>
//using namespace std;
//
//void test() {
//	cout << "Hey,boy" << endl;
//}
//
//int main() {
//
//	unsigned char* p_MARK = (unsigned char*)test;
//
//	for (; p_MARK <= (unsigned char*)test; p_MARK++) {
//		if (*p_MARK == 0xCC) {
//			//(* p_MARK)++;
//			cout << "Don't debug me!" << endl;
//			exit(1);
//		}
//	}
//
//	test();
//}
//

//#include <stdio.h>
//#include <iostream>
//
//union data {
//    int n;
//    char ch[4];
//    short m;
//};
//
//int main() {
//    union data a;
//    printf("%d, %d\n", sizeof(a), sizeof(union data));
//    a.n = 0x40;
//    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
//    a.ch = '9';
//    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
//    a.m = 0x2059;
//    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
//    a.n = 0x3E25AD54;
//    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
//
//    return 0;
//}








#include <iostream>
using namespace std;

template<class T>
class vector {
public:
	vector();
	vector(const int&);
	vector(const int&,const T&);
	vector(const vector<T>&);
	~vector();

	void recapacity(const int&);
	void push_back(const T&);
	void pop_back();

	inline T& operator[](const int&);
	vector<T>& operator=(const vector&);
	vector<T> operator+(const vector&);
	vector<T> operator-(const vector&);
	bool operator==(const vector&);
	bool operator!=(const vector&);

	inline int Size();
	inline int Capacity();

	friend ostream& operator<<(ostream&, const vector<T>&);
	//friend istream& operator>>(istream&, vector<T>&);

private:
	T* T_Array;
	int capacity;
	int size;
};


template<class T>
ostream& operator<<(ostream& os, const vector<T>& Array)
{
	for (int i = 0; i < Array.size; i++) {
		os << Array.T_Array[i] << " ";
	}
	return os;
}

int main() {
	vector<int> arr(5,1);
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	arr.pop_back();

	for (int i = 0; i < arr.Size(); i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;

	vector<int> arr2(6,8);

	arr = arr + arr2;

	cout << (arr == arr2) << endl;
	cout << (arr != arr2) << endl;

	for (int i = 0; i < arr.Size(); i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;

}

template<class T>
void vector<T>::recapacity(const int& n) {
	if (n < 0) return;
	T* T_Tmp = new T[n];
	memcpy(T_Tmp, this->T_Array, n * sizeof(T));
	delete[] T_Array;
	T_Array = T_Tmp;
	T_Tmp = nullptr;

	capacity = n;

	if (n <= size) {
		size = n;
	}
}

template<class T>
void vector<T>::push_back(const T& tmp) {
	if (capacity > size) {
		T_Array[size] = tmp;
		++size;
	}
	else {
		this->recapacity(2 * size + 1);
		T_Array[size] = tmp;
		++size;
	}
}

template<class T>
void vector<T>::pop_back() {
	--size;
	//眼不见为净
}

template<class T>
inline T& vector<T>::operator[](const int& n) {
	return T_Array[n];
}

template<class T>
vector<T>& vector<T>::operator=(const vector& Array) {
	this->capacity = Array.capacity;
	this->size = Array.size;
	T_Array = new T[size];
	memcpy(this->T_Array, Array.T_Array, size * sizeof(T));
	return *this;
}

template<class T>
vector<T> vector<T>::operator+(const vector& Array) {
	int min = this->size > Array.size ? Array.size : this->size;
	vector<T> tmp = this->size > Array.size ? *this : Array;
	for (int i = 0; i < min; i++) {
		tmp[i] += Array.T_Array[i];
	}
	return tmp;
}

template<class T>
vector<T> vector<T>::operator-(const vector& Array) {
	int min = this->size > Array.size ? Array.size : this->size;
	vector<T> tmp = this->size > Array.size ? *this : Array;
	for (int i = 0; i < min; i++) {
		tmp[i] -= Array.T_Array[i];
	}
	return tmp;
}

template<class T>
bool vector<T>::operator==(const vector& Array) {
	if (this->size != Array.size) return false;
	return memcmp(this->T_Array, Array.T_Array, this->size * sizeof(T)) ? false : true;
}

template<class T>
bool vector<T>::operator!=(const vector& Array) {
	if (this->size != Array.size) return true;
	return memcmp(this->T_Array, Array.T_Array, this->size * sizeof(T)) ? true : false;
}

template<class T>
inline int vector<T>::Size() {
	return size;
}

template<class T>
inline int vector<T>::Capacity() {
	return capacity;
}

template<class T>
vector<T>::vector() {
	size = 0;
	capacity = 0;
	T_Array = new T[size];
}

template<class T>
vector<T>::vector(const int& n) {
	size = 0;
	capacity = n;
	T_Array = new T[size];
}

template<class T>
vector<T>::vector(const int& n,const T& tmp) {
	size = n;
	capacity = n;
	T_Array = new T[size];
	for (int i = 0; i < size; i++) {
		T_Array[i] = tmp;
	}
}

template<class T>
vector<T>::vector(const vector<T>& Array) {
	this->capacity = Array.capacity;
	this->size = Array.size;
	T_Array = new T[size];
	memcpy(this->T_Array, Array.T_Array, size * sizeof(T));
}

template<class T>
vector<T>::~vector() {
	delete[] T_Array;
}






//template<class T>
//istream& operator>>(istream& is, vector<T>& Array) {
//	while (Array.size < Array.capacity) {
//		is >> Array.T_Array[size];
//		++size;
//	}
//	return is;
//}








