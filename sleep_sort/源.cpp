#include<iostream>
#include<vector>
#include<thread>
#include <windows.h>

using namespace std;

//Ë¯ÃßÅÅÐò

void sort(unsigned int sleep_time) {
	Sleep(sleep_time);
	printf("%d\n", sleep_time);
}

int main() {
	vector<thread> my_threads;
	vector<unsigned int> unsort;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {
		unsort.push_back(rand());
	}

	for (const auto& i : unsort)
	{
		my_threads.push_back(thread(sort, i));
	}

	for (auto& i : my_threads)
	{
		i.join();
	}
}