#pragma once
#include "FzgVerhalten.h"
class FzgFahren :
	public FzgVerhalten//Legt das Verhalten f�r fahrende Fahrzeuge fest
{
public:
	FzgFahren(Weg* pWeg);//Konstruktor, speichert einen Zeiger auf einen Weg
	virtual ~FzgFahren();//Destruktor
	virtual double dStrecke(Fahrzeug * pFahrzeug, double dZeit) const;//Gibt die maximale m�glich Strecke auf dem aktuellen Weg f�r das Fahrzeug zur�ck
};