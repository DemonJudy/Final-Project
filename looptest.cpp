#include <iostream>
using namespace std;
int n=0;
string table[100][2];
int main()
{
	for(int m=1;m<=100;m++)
	{
		n++;
		table[m-1][1]='F';
		if(m<10)
		{
			table[m-1][0]=n;
		}
		else if(m<20)
		{
			table[m-1][0]=n+1;
		}
		else
		{
			table[m-1][0]=n+2;
		}
		cout << table[m-1][0] << table[m-1][1] << endl;
	}
}