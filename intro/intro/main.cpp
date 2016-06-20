#include "vector.h"
#include <cmath>

#include <iostream>
#include <string>

using namespace std;

void reverseSection(string& rs, int pos, int len)
{
	//if (pos <= 0 || pos >= rs.size() || pos + len
	for (int i = 0; i < (len - pos + 2) / 2; i++)
	{
		cout << i << endl;
		char temp = rs[pos + i]; 
		rs[pos + i] = rs[len - pos - i - 1];
		rs[len - pos - i - 1] = temp;
	}
}

int main()
{
	Vector myVec;
	myVec.insert(0, 1);
	myVec.insert(1, 19);
	myVec.insert(1, 20);

	//myVec.print();

	string s = "abcdefg";
	reverseSection(s, 1, 3);
	cout << s;

	system("PAUSE");
	return 0;
}