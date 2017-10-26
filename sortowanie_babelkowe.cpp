#include<iostream>
using namespace std;
void wyswietl_tablice(int *tab)
{
	for (int i = 0; i < 10; i++)
	{
		cout << tab[i]<<endl;
	}
}
int main()
{
	int tablica[10] = { 2, 6, 23, 12, 54, 67, 6, 3, 1, 10 };
	wyswietl_tablice(tablica);

	//tu zaczynamy sortowanie babelkowe
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (tablica[i] > tablica[j])
			{
				swap(tablica[i], tablica[j]);
			}
		}
	}

	cout << endl;
	wyswietl_tablice(tablica);
	system("pause");
	
}