#include<iostream>
#include<algorithm>
using namespace std;
void wyswietl_tablice(int *tab)
{
	for (int i = 0; i < 10; i++)
	{
		cout << tab[i]<<endl;
	}
}
bool predykat(int a, int b)
{
	return a > b;
}
int main()
{
	int tablica[10] = { 2, 6, 23, 12, 54, 67, 6, 3, 1, 10 };
	wyswietl_tablice(tablica);

	//tu zaczynamy sortowanie quick sort wg pliku nag³ówkowego "alghorithm"
	sort(tablica, tablica + 10/*,predykat*/);

	cout <<endl<< endl;
	wyswietl_tablice(tablica);
	system("pause");
	
}