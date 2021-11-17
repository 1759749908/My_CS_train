#include<iostream>
#include<vector>
#include<thread>
#include <chrono>
#include <windows.h>

using namespace std;

//´óÃû¶¦¶¦µÄË¯ÃßÅÅÐò

void sort(unsigned int sleep_time) {
	//this_thread::sleep_for(chrono::milliseconds(sleep_time*50));
	Sleep(sleep_time);
	printf("%d\n", sleep_time);
}

int main() {

	vector<thread> my_threads;
	vector<unsigned int> unsort;
	for (int i = 0; i < 100000000; i++) {

		unsort.push_back(rand());
	}


	for (auto& i : unsort)
	{
		my_threads.push_back(thread(sort, i));
	}

	for (auto& i : my_threads)
	{
		i.join();
	}


	//for (auto iter=my_threads.begin();iter!=my_threads.end();++iter)
	//{
	//	iter->join();
	//}


}