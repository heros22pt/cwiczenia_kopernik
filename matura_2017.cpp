#include<iostream>
#include<fstream>

using namespace std;


void zadanie1(int t[200][320])
{
	int max, min;
	max = t[0][0];
	for (int i = 0; i<200; i++)
	{
		for (int j = 0; j<320; j++)
			if (t[i][j]>max)max = t[i][j];
	}
	cout << max << " to jest max ";
	min = t[0][0];
	for (int i = 0; i<200; i++)
	{
		for (int j = 0; j<320; j++)
			if (t[i][j]<min)min = t[i][j]; //tu miales max zamiast minimum.
	}
	cout << min << " to jest min ";
	//...................
}
void zadanie2(int t[200][320])
{
	int licznik=0;
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 320/2; j++) //rownie dobrze bd dzialac jak bd 320, po prostu bd dzialac duzej, czym bym sie nie przejmowal na Twoim miejscu...
		{
			if (t[i][j] != t[i][320 - j - 1])
			{
				licznik++;
				break;
			}
		}
	}
	cout << licznik;
}
void zadanie3(int t[200][320])
{
	int licznik = 0;
	for (int i = 1; i < 200-1; i++) //dla czego -1?
	{
		for (int j = 1; j < 320-1; j++) //bez uwzglednienia pikseli brzegowych!! jak to zmienic?
		{ //zadanie! rozwazyc problem naprawy pikseli na krawedziach
			if (abs(t[i][j] - t[i][j + 1]) >128 || abs(t[i][j] - t[i + 1][j]) > 128 || abs(t[i][j] - t[i][j - 1]) >128 || abs(t[i][j] - t[i-1][j]) >128)
				licznik++;
		}
	}

	cout << licznik;
}
int main()
{
	int t[200][320];
	ifstream plik;
	plik.open("dane.txt");
	for (int i = 0; i<200; i++)
	{
		for (int j = 0; j<320; j++)
			plik >> t[i][j];
	}

	//zadanie1(t);
//	zadanie2(t);
	zadanie3(t);

	//..................




	//zadanie 2



	system("PAUSE");
}
