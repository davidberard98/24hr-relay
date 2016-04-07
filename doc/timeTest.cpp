#include <iostream>
#include <chrono>
#include <unistd.h>

using namespace std;

int main()
{
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	for(int i=0;i<10000000;++i)
	{
		i*i;
	}
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration<int, ratio<1, 1000>> time_span = chrono::duration_cast<chrono::duration<int, ratio<1, 1000>>> (t2-t1);
	cout << "Timespan " << time_span.count() << endl;
	
	
	return 0;
}
