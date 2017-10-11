#include"scena.h"
#include<iostream>
#include <GL/freeglut.h>

using namespace std;

cScena scena;  //globalny obiekt scena

void przerysuj()
{
	scena.rysuj();
}
void cScena::rysuj()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f : tab)
		f.draw();
	glPopMatrix();
	glutSwapBuffers();
}



void klawisz(unsigned char znak, int x, int y)
{
	scena.klawisz(znak, x, y);
}


cScena::cScena() : // nie wiem  do czego to na razie
aktywny(1) {
}

void cScena::klawisz(unsigned char znak, int x, int y)
{
	std::cout << "Naciœniêto klawisz: " << znak << ", a myszka znajduje siê w pozycji: " << x << ", " << y << "(w pikselach)" << std::endl;
	switch (znak)
	{

	case 'p':
	{
		//	cRectangle *pr = new cRectangle;
		cRectangle pr;
		tab.push_back(pr);
		aktywny = tab.size() - 1;
		break;
	}
	case 'w':
	{
		//		tab[aktywny]->move(0, 0.1);
		tab[aktywny].move(0.0, 0.1);
		break;
	}
	case 's':
	{
		tab[aktywny].move(0.0, -0.1);
		break;
	}
	case 'a':
	{
		tab[aktywny].move(-0.1, 0.0);
		break;
	}
	case 'd':
	{
		tab[aktywny].move(0.1, .0);
		break;
	}
	case '+':
	{
		tab[aktywny].resize(0.1, 0.1);
		break;
	}
	case '-':
	{
		tab[aktywny].resize(-0.1, -0.1);
		break;
	}
	case 'r':
	{
		tab[aktywny].setColor(0.1, 0, 0);
		break;
	}
	case 'g':
	{
		tab[aktywny].setColor(0, 0.1, 0);
		break;
	}
	case 'b':
	{
		tab[aktywny].setColor(0, 0, 0.1);
		break;
	}
	case 'z':
	{
		if (aktywny < tab.size() - 1) {
			aktywny++;
		}
		break;
	}
	case 'x':
	{
		if (aktywny > 0)
		{
			aktywny--;
		}
		break;
	}
	case 't':
	{
		float _x, _y;
		cout << "podaj wspolrzedna x: ";
		cin >> _x;
		cout << "podaj wspolrzedna y: ";
		cin >> _y;
		tab[aktywny].moveTo(_x, _y);
		break;
	}
	case '1':
	{
		tab[aktywny].rotate(5);
		break;
	}
	case '2':
	{
		int a = -5;
		tab[aktywny].rotate(a);
		break;
	}

	default:
	{
		break;
	}
	}
	glutPostRedisplay();


}



void cScena::inicjuj()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//Tworzy okno 320x320
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(420, 420);
	glutCreateWindow("Przykladowy program");
	//Rejestruje funkcje zdarzeñ
	glutDisplayFunc(::przerysuj);
	//glutReshapeFunc(ZmienRozmiarEkranu);
	glutKeyboardFunc(::klawisz);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //przechodzi do globalnego uk³adu kamery
	glOrtho(-1, 1, -1, 1, -.1, .1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}