#pragma once
#include "AktivesVO.h"
#include "Weg.h"
#include "Fahrzeug.h"

class Kreuzung :
	public AktivesVO
{
public:
	Kreuzung();		//aufgabe 8,1,b
	Kreuzung(const string sName, const double dTankstelle = 0);  //aufgabe 8,1,b
	virtual ~Kreuzung();		//aufgabe 8,1,b


	void vVerbinde(const string sNameHin, const string sNameZurueck, Kreuzung* pKreuzung, const double dLaenge, const Weg::Begrenzung eLimit, const bool bUeberholverbot);		//aufgabe 8,1,c
	void vTanken(Fahrzeug* pFahrzeug);		//aufgabe 8,1,c


	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeit, Weg* pNeuerWeg = 0);	//aufgabe 8,1,d ---> for new car
	void vAnnahme(Fahrzeug* pFahrzeug, Weg* pVorherigerWeg = 0, Weg* pWeg = 0);	//aufgabe 8,1,d ---> for car that enters from a weg
	virtual void vAbfertigung();		//aufgabe 8,1,d


	Weg* ptZufaelligerWeg(Weg* pWeg);  //aufgabe 8,3,a


	void vNeuerWeg(Weg* pWeg);
	void vZeichnen() const;
	

	virtual ostream& ostreamAusgabe(ostream& out) const;
	virtual istream& istreamEingabe(istream& in);
	double getTankstelle() const;

private:
	double p_dTankstelle;  //aufgabe 8,1,b
	list<Weg*> p_pWege;		//aufgabe 8,1,b
};

