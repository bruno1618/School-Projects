#pragma once
#include "Weg.h"
class FzgVerhalten//Abstrakte Oberklasse von FzgFahren und FzgParken
{
public:
	FzgVerhalten(Weg* pWeg);//Konstruktor, Zeiger auf den Weg
	virtual ~FzgVerhalten();//Destruktor
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) const = 0;//Gibt die maximale m�glich Strecke auf dem aktuellen Weg f�r das Fahrzeug zurueck, rein virtuell, wird in den Unterklassen ueberschrieben
	double dLimit() const;//Gibt die Begrenzung auf dem Weg zurueck
protected:
	Weg* p_pWeg;//Zeiger auf den Weg
};
