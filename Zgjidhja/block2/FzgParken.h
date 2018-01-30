#pragma once
#include "FzgVerhalten.h"
class FzgParken :
	public FzgVerhalten//Legt das Verhalten f�r parkende Fahrzeuge fest
{
public:
	FzgParken(Weg* pWeg, double dStartzeitpunkt);//Konstrukor, Zeiger auf den Weg auf dem das Fahrzeug sich befindet und den Zeitpunkt zu dem das Fahrzeug los f�hrt
	virtual ~FzgParken();//Destruktor
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) const;//Gibt die maximale m�glich Strecke auf dem aktuellen Weg f�r das Fahrzeug zur�ck
private:
	double p_dStartzeitpunkt;//Zeitpunkt zu dem das Fahrzeug los f�hrt
};
