#include <iostream>
#include <ctime>
#include <boost/locale.hpp>
#include <boost/date_time.hpp>
#include <windows.h>

using namespace std;
using namespace boost::posix_time;


int main()
{

	ptime now = not_a_date_time;

	int num[16];

	cout << now << endl;
}