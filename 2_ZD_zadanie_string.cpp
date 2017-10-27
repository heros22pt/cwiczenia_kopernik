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
	int menu = 1; //zmienna wyboru menu. dowolna deklaracja na poczatku..
	do //petla do najpierw wykonuje, potem sprawdza warunki!
	{

		cout << "Wybierz numer zadania:\n1-odwrocenie liter\n2-podanie liczby kobiet\n3-zaszyfrowanie\n0-wyjscie";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "1";
			zadanie1(imiona);
			break; // gdyby nie bylo break, automatycznie zaczelaby wykonywac sie instrukcja 2. 
		}
		case 2:
		{
			cout << "2";
			zadanie2(imiona);
			break;
		}
		case 3:
		{
			cout << "3";
			zadanie3(imiona);
			break;
		}
		default: // w razie wcisniecia innego przycisku
		{
			cout << "wcisnales zly przycisk!!!";
			break;
		}
		}

	} while (menu != 0); // dziala dopuki menu jest rozne od 0 - wyjscie z petli
}