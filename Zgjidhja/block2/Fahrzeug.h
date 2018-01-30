#pragma once

#include "AktivesVO.h"
#include "FzgVerhalten.h"
#include "SimuClient.h"

class Weg;//Weg wird bekannt gemacht

class Fahrzeug :
	public AktivesVO
{
	public:
		Fahrzeug(); //Standartkonstruktor
		Fahrzeug(const string sName);//Konstruktor mit Namens�bergabe
		Fahrzeug(const string sName, const double dMaxgeschwindigkeit);//Konstruktor mit Namens�bergabe und MaxGeschwindigkeit
		virtual ~Fahrzeug();//Destruktor
		virtual void vAusgabe() const; //gibt Fahrzeugspezifische Informationen �ber die Textausgabe aus
		virtual void vAbfertigung();//Abfertigungsschritt, aktualisiert Fahrzeugspezifische Informationen gem�� der Globalen Zeit
		virtual double dTanken(double dMenge = -1);//Tankt das Fahrzeug
		virtual double dGeschwindigkeit() const;// gibt die aktuelle Geschwindigkeit des Fahrzeugs zur�ck
		virtual ostream& ostreamAusgabe(ostream& out) const;//Ausgabe �ber die �berladung des << Operators
		virtual istream& istreamEingabe(istream& in);
		bool operator<(const Fahrzeug& Fzg) const;//�berladung des < Operators, vergleicht die gefahrene Strecke von zwei Fahrzeugen
		bool operator>(const Fahrzeug& Fzg) const;//�berladung des > Operators, vergleicht die gefahrene Strecke von zwei Fahrzeugen
		Fahrzeug& operator=(const Fahrzeug& Fzg);//�berladung des Zuweisungsoperators, kopiert Objekte und wei�t eine neue ID zu
												 //bool operator==(const Fahrzeug& Fzg) const;//�berladung des == Operators, vergleicht die gefahrene Strecke von zwei Fahrzeugen
		void vNeueStrecke(Weg* pWeg);//Setzt das _Fahrzeug auf einen neuen Weg
		void vNeueStrecke(Weg * pWeg, double dStartzeitpunkt);//�berladung der Funktion, gibt zus�tzlich einen Startzeitpunkt an zu dem das Fahrzeug los fahren soll
		double getAbschnittsStrecke() const;//Get-Funktion f�r p_dAbschnittsStrecke
		virtual void vZeichnen(const Weg* pWeg) const;//Macht in Fahrzeug nichts, wird in beiden Unterklassen �berschrieben

	private:
		Fahrzeug(const Fahrzeug& Fzg);//Copykonstruktor des Fahrzeugs, auf private damit er nicht zuf�llig benutzt wird
		void vInitialisierung(); // Initialisiert Membervariablen auf 0 oder "" und setzt die ID

	protected:
		double p_dMaxGeschwindigkeit; //Maximale GGeschwindigkeit des Fahrzeugs
		double p_dGesamtstrecke; //Gesamt gefahrene Strecke des Fahrzeugs
		double p_dGesamtzeit; //Gesamtfahrzeit des Fahrzeugs
		double p_dAbschnittStrecke; //zur�ckgelegte Strecke auf dem aktuellen Abschnitt
		FzgVerhalten* p_pVerhalten;//Legt das Verhalten auf einem Weg fest, 
};

