// Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void laduj(fstream & plik, int tab[9][9])
{
	char znak;
	string linia;
	int nr = 0;
	while (getline(plik, linia))
	{
		for (int i = 0; i < 9; i++)
		{
			tab[nr][i] = linia[i]-'1';
		}
		nr++;
	}
}

bool kolumna(int tab[9][9], int nr)
{
	bool bylo[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		bylo[tab[nr][i]] = 1;
	}
	for (int j = 0; j < 9; j++)
	{
		if (bylo[j] == 0)
		{
			return false;
		}
	}
	return true;
   }

bool wiersz(int tab[9][9], int nr)
{
	bool bylo[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		bylo[tab[i][nr]] = 1;
	}
	for (int j = 0; j < 9; j++)
	{
		if (bylo[j] == 0)
		{
			return false;
		}
	}
	return true;
}

bool kwadrat(int tab[9][9], int nr)//robi po 3 dla wiersza
{
	bool bylo[9] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bylo[tab[nr + i][j]] = 1;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (bylo[j] == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	fstream plik;
	const int rozmiar = 9;
	int tab[rozmiar][rozmiar];
	plik.open("C:/Users/SL/Documents/aeirepo/Tomasz-Skowron-gr07-repo/student/Sudoku/Debug/sudoku.txt",ios::in);
	if (plik.good()==true)
	{
		laduj(plik, tab);
		for (int i = 0; i < 9; i++)
		{
			if (kolumna(tab, i) == false || wiersz(tab, i) == false)
			{
				cout << "falsz" << endl;
				break;
			}
		}
		for (int j = 0; j < 9; j = j + 3)
		{
			if (kwadrat(tab, j) == false)
			{
				cout << "falsz" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "...";
		return 1;
	}
	plik.close();
    return 0;
}

