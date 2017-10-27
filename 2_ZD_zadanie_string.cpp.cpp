#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void zadanie1(string imiona[5])
{

}
void zadanie2(string imiona[5])
{

}
void zadanie3(string imiona[5])
{

}
int main()
{
	string imiona[5];
	cout << "Podaj 5 imion: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> imiona[i];
		cout << endl;
	}

	do //petla do najpierw wykonuje, potem sprawdza warunki!
	{
		int a;
		cout << "Wybierz numer zadania:\n1-odwrocenie liter\n2-podanie liczby kobiet\n3-zaszyfrowanie\n0-wyjscie";
		cin >> a;
		switch (a)
		{
		case 1:
			{
				zadanie1(imiona);
			}
		case 2:
			{
				zadanie2(imiona);
			}
		case 3:
			{
				zadanie3(imiona);
			}
		case 0:
		{
			break; //przerwanie nieskaczonej petli while
		}
		default: // w razie wcisniecia innego przycisku
		{
			break;
		}
		}

	} while (1); //petla ktora dziala w nieskonczonosc. alternatywa - for(;;)
}