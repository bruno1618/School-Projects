#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"

//Standardkonstruktor mit Fahrzeug und zugeh�rigem Weg
FahrAusnahme::FahrAusnahme(Fahrzeug * pFahrzeug, Weg * pWeg) : p_pFahrzeug(pFahrzeug), p_pWeg(pWeg)
{
}

FahrAusnahme::~FahrAusnahme()
{
}
