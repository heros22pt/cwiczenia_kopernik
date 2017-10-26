#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cout << "podaj liczbe pieter  "; int liczba_pieter; cin >> liczba_pieter;

	for (int i = 0; i < liczba_pieter+1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	system("pause");
}