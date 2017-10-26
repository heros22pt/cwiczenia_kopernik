#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cout << "podaj liczbe pieter  "; int liczba_pieter; cin >> liczba_pieter;
	liczba_pieter++;

	for (int aktualne_pietro = 1; aktualne_pietro < liczba_pieter; aktualne_pietro++) 

	{
		for (int j = 1; j < liczba_pieter-aktualne_pietro; j++)
		{
			cout << " "; 
		}
		/* dodajemy tyle spacji, ile jest wynosi aktualne pietro
		*/
		for (int k = 1; k <= 2 * aktualne_pietro - 1; k++) /*zastanowic sie dla czego mnozymy aktualne pietro razy 2 a potem odejmujemy 1*/
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int l = 1; l < liczba_pieter-1; l++)
		cout << " ";
	cout << "#" << endl;

	system("pause");
}