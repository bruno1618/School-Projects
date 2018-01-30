#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;
extern double dGlobaleZeit;

class AktivesVO//Abstrakte Oberklasse f�r Weg und Fahrzeug, es wird kein Objekt von AktivesVO erstellt
{
public:
	AktivesVO();//Standartkonstruktor
	AktivesVO(const string sName);//Konstruktor mit Zuweisung eines Namen
	virtual ~AktivesVO();//Desruktor
	virtual void vAusgabe() const;//Ausgabefunktion
	virtual ostream& ostreamAusgabe(ostream& out) const;//Ausgabe �ber die �berladung des << Operators
	virtual istream& istreamEingabe(istream& in);
	virtual void vAbfertigung() = 0;//Abfertigungsschritt, aktualisiert Fahrzeugspezifische Informationen gem�� der Globalen Zeit
	AktivesVO& operator=(const AktivesVO& AVO);//�berladung des Zuweisungsoperators, kopiert Objekte und weist eine neue ID zu
	string getName() const;//Get-Funktion f�r den Namen
	static AktivesVO* ptObjekt(string sName);
private:
	AktivesVO(const AktivesVO& AVO);//Copykonstrukor, private damit nicht zufaellig aufgerufen
	void vInitialisierung(); // Initialisiiert Membervariablen auf 0 oder "" und setzt die ID
	static int p_iMaxID; //Aktuelle MaxID, static damit sie nur einmal f�r die Klasse erstellt wird und nicht f�r jedes Objekt
	static map<string, AktivesVO*> p_mVO; //Speichert den Namen und einen Zeiger auf ein VO
protected:
	int p_iID; //ID des Verkehrsobjekts
	double p_dZeit; //Letzte Abfertigung des Verkehrsobjekts
	string p_sName; //Name des Verkehrsobjekts
};
ostream& operator<<(ostream& out, const AktivesVO& AVO);//�berladung des << Operators
istream& operator>>(istream& in, AktivesVO& AVO); //�berladung des >> Operators