/*
Wprowadzenie by Krzysztof Marchewka do zadania maturalnego z roku 2016 Matura rozszerzona, zadanie 6!
Kod zostal napisany w dosc zroznicowany sposob, dla tego, by uzytkownik oswoil sie z roznymi typami funkcji oraz rozwiazywaniem tych samych zadan na rozne sposoby.
Kod nie zostal napisany w sposob, jaki trzeba zrobic to na maturze, jest on tylko pogladowa wersja, jak poradzic sobie z roznymi problemami. Zadaniem uzytkownika jest przerobienie kodu, aby jego realizacja odbywala sie na danych pobranych z pliku. Algorytmy sa zupelne i poprawne. Nalezy tylko zmienic logike odczytywania i przekazywania danych.
Kod zostal skomentowany dla pelniejszego zrozumienia. 
Czas na napisanie tego kodu powinien byc nie wiekszy niz 20 minut.
*/
#include<iostream> //biblioteka podstawowa (przynajmniej na poziomie licealnym)
#include<string> //Obsluguje tablice znakow typu string. Pamietaj ze string, to tablica znakow "char"
using namespace std; //nie trzeba przy kazdym kozystaniu ze strumieniow etc uzywac "std::". Ulatwia zycie
void zadanie6_1(){
	string slowo;  cin >> slowo; //Pobranie slowa
	string slowoRozszyfrowane = slowo; //Zadeklarowanie nowej zmiennej, oraz przypisanie jej wartosci slowa pobranego, tylko po to, by tablice przechowujace slowo zaszyfrowane i rozszyfrowane mialy takie same wielkosci.
	int klucz; cin >> klucz; klucz %= 26; //Jak wiadomo alfabet ma 25 znakow, wiec po co klucz, ktory ma wiecej? klucz %= 26 mozna zapisac inaczej jako klucz = klucz % 26!

	for (int i = 0; i <= slowo.length() - 1; i++){ //tutaj musimy odtworzyc w celu przerobienia, kazda literke slowa z osobna. Petla for to umozliwia
		slowoRozszyfrowane[i] = slowo[i] + klucz; //tutaj szyfrujemy slowo, w taki o to banalny sposob
		if ((slowoRozszyfrowane[i] > 'Z' && slowoRozszyfrowane[i]<'a') || slowoRozszyfrowane[i]>'z')
			/*
			W tym miejscu pojawia sie problem.. mamy klucz, ktory ma wartosc np. 3. Chcemy nim zakodowac lierke "Z". Co zrobi program? zakodowany znak bedzie mial kod ASCII wiekszy o 3 od Z, a to jest jakiœ dziwny znaczek, ktorego nie chcemy. Chcemy, by alfabet znow zaczal sie od nowa, czyli Z+3 = C!!! Wiec w takim przypadku realizujemy algorytm, ktory bedzie w razie przekroczenia bariery wyznaczanej przez duze, albo male z, po prostu sie zapetlal i znow lecial od litery 'a', albo 'A'.
			To co zapisane zostalo w "ifie" sprawdza, czy bariera zostala przekroczona. Naleze takze zwrocic uwage na to, ze musimy to zabezpieczyc dla duzych i malych liter.
			"||" oraz "&&" to operatory logiczne, ktore oznaczaja kolejno "OR - czyli lub", oraz "AND - czyli i"
	
			*/
			slowoRozszyfrowane[i] -= 'z'-'a'+1;
		/*		Nie wiemy o ile mamy sie cofnac? czyli ile liter ma alfabet? Zaden problem, zapisujemy 'z'-'a' (litery zapisane w ten sposob sa interpretowane jako liczba kodu ASCII), co daje nam dlugosc alfabetu pomniejszona o jeden.
		*/
	}

	cout << slowoRozszyfrowane; //no i wyswietlmy slowo!!!!
	//Uwaga! w funkcji typu 'void' nic nie zwracamy! 
}

string zadanie6_2(string slowo, int klucz) //funkcja typu string! Czyli zwraca ona zmienna wlasnie tego typu!
{
	//Logika ta sama, co poprzednio, z tym ze troche odwrocona! Polecam porownac kody!
	string slowoRozszyfrowane = slowo;
	klucz %= 26;


	for (int i = 0; i <= slowo.length() - 1; i++){
		slowoRozszyfrowane[i] = slowo[i] - klucz; //odwrotnie, bo odszyfrowujemy
		if ((slowoRozszyfrowane[i] < 'Z' && slowoRozszyfrowane[i]>'a') || slowoRozszyfrowane[i]<'z') //tu takze jest roznica wzgledem 6_1! przeanalizuj ja
			slowoRozszyfrowane[i] += 'z' - 'a' + 1; //dlugosc alfabetu
	}

	return slowoRozszyfrowane; //zwracamy zmienna typu string, czyli w naszym przypadku zaszyfrowane slowo.
}

bool zadanie6_3(string slowo1, string slowo2){ //funkcja typu bool, zwraca prawde albo falsz!
	int sprawdzenie = slowo1[0] - slowo2[0]; //sprawdzamy, jaki jest kod pierwszej litery. Dla czego akurat pierwszej? Poniewaz slowo musi skladac sie przynajmniej z jednej litery, a nie wiemy jaka jest jego dlugosc. wiemy tylko, ze oba slowa sa tej zamej dlugosci.
	for (int i = 1; i < slowo1.length()-1; i++){
		if ((slowo1[i] - slowo2[i]) != sprawdzenie){ //jesli nie jest rowne to!!!!
			return false; //zwroc false
			break; //oraz obowiazkowo zatrzym petle, zeby dalej juz nie sprawdzala.
		}
		else
			return 1; //dla czego w tem przypadku zwracamy 1? Poniewaz w jezyku programistycznym "true" oznaczamy jako "1", a false jako "0". Mozna stosowac to zamiennie.
	}
}
int main(){
	/*Mozna odkomentowac sobie zadanie, w celu przetestowania!*/

	//zadanie6_1();
	//cout<<zadanie6_2("abc", 3);
	//cout << zadanie6_3("ABC", "ABC"); cout << endl << zadanie6_3("aBC", "ABC");
	system("pause"); //mozliwe ze ta funkcja, nie bd dzialac na wszystkich kompilatorach. W Visual Studio sluzy ona do zatrzymania programu do momentu wcisniecia klawisza.
}

/*
Program w calosci napisany przez Krzysztofa Marchewke w celach dydaktycznych, przeznaczony do nauki oraz wnikliwej analizy problemu, ktory mogl sprawic problem w zadaniu maturalnym. 7-03.2018.


Zadanie domowe:
Przerobic ten kod, tak by realizowal zadanie maturalne, czyli wczytywanie z pliku i zapisywanie do pliku.

Wskazowki:
Uzyj biblioteki "fstream".
Caly tekst, ktory jest w notatniku zapisz do zmiennej plikowej.
Aby to zrobic uzyj zmiennej typu fstream np. "fstream plik1.open('nazwa.txt',ios::in);"
teraz caly plik zapisany jest jako zmienna "plik1". Mozesz z niej dowolnie kozystac, np pobierac z niej dane. Rob to w taki sam sposob, jak robi sie to z konsoli. "cin" Oznacza doslownie "console input". Ty nie chcesz pobrac plikow z konsoli, tylko z zmiennej, wiec robisz to analogicznie do cout np. (cin<<slowo <=> plik1>>slowo)

Pamietaj o zamknieciu pliku na koncu: plik1.close(); W przeciwnym razie nadal bd on otwart gdzies w pamieci.

Nazywaj zmienne intuicyjnie, zebys sie nie pogubil. Np. "slowoZaszyfrowane", zamiast "a", "b" etc... albo "slowo_zaszyfrowane", lub jakkolwiek wolisz.
*/