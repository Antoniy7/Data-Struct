#include<iostream>
#include"Stack.h"
//stack , matrix , bool masiv;
//dfs
using namespace std;

int main()
{
	Stack<int> myStack;
	int size;

	bool matr[64][64];

	cin>>size;

	if (size>64) 
		return false;

	int**buffer;
	buffer= new int*[size];

	for (int i=0;i<size;i++)
		buffer[i]=new int [size];

	for (int i=0;i<size;i++)
		for (int j=0;j<size;j++)
			cin>>matr[i][j];
       
	
	bool* visited= new bool[size*size];
	memset(visited,0, sizeof (bool)*size*size); // zanulqvame go ;d 

	if (!visited) 
		return 0;

	int start, end;
	cin >> start >> end;

	myStack.push(start);  // put v labirint 
	
	while (myStack.head()) // do koga shte raboti // dokato stack ne e prazen
	{
		int current= *(myStack.head());
		myStack.pop();

		if (visited[current]) //  1 ne iskam da go visisted 2 puti :) 
			continue;

		if (current == end)
			{
				cout<<"there is a route"<<endl;
				return 0;
		    }

		visited[current] = true;

		for(int i=-1;i<=1;i+=2) // -1 i 1 vzimame
		{
			if(!visited[current+i] &&  !matr[(current+i)/size][(current+i)%size]
			    && (current%size !=0  || current%size!= size-1) && current+i>=0 && current+i<size*size) // matricata false , da e 0
			{
				myStack.push(current+i);

			}
		}

		//- size ; size :) 


		for(int i=-1;i<=1;i+=2) // -1 i 1 vzimame
		{
			if(!visited[current+i*size] &&  !matr[(current+i *size)/size][(current+i*size)%size]) // matricata false , da e 0
			{
				myStack.push(current+i*size);

			}
		}

	
	}

	cout<<"no path"<<endl;


	system("pause");
	return 0;
}


// 3
//0 0 0
//1 1 0
//0 0 0
//start:0 ; end :6


