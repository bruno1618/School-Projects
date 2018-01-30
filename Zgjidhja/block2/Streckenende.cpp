#include "Streckenende.h"
#include "Kreuzung.h"



Streckenende::Streckenende(Fahrzeug* pFahrzeug, Weg* pWeg):FahrAusnahme(pFahrzeug, pWeg)
{
}

Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	p_pWeg->vAbgabe(p_pFahrzeug); //löscht das auto von liste

	Kreuzung* pKreuzung = p_pWeg->getKreuzung();
	Weg* pNeuerWeg = pKreuzung->ptZufaelligerWeg(p_pWeg);
	
	pKreuzung->vAnnahme(p_pFahrzeug, p_pWeg, pNeuerWeg);


	cout << "ZEIT      :" << dGlobaleZeit << endl
		<< "KREUZUNG  :" << pKreuzung->getName() << pKreuzung->getTankstelle() << endl
		<< "WECHSEL   :" << p_pWeg->getName() << " -> " << pNeuerWeg->getName() << endl
		<< "FAHRZEUG  :" << *p_pFahrzeug << endl;
}
