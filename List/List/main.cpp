#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
	Queue<int> myQueue;

	while(!myQueue.isEmpty())
		cout<<*(myQueue.head())<<endl;


	return 0;
}