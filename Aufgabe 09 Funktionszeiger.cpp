// Aufgabe 09 Funktionszeiger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
 * Aufgabe 1: Schreiben Sie für die vier Grundrechenarten (Addition, Subtraktion,
 *            Division und Multiplikation) vier Funktionen, sowie eine Funktion
 *            für eine modifizierte Modulo-Operation:
 *
 *            2.7 % 1.2 == 0.3 (der Quotient wird als 'int' angesehen,
 *                                und damit der Rest ausgerechnet und zurückgegeben)
 *
 *            quotient = static_cast<int>(x / y);
 *            return x - (quotient * y);
 *
 *            Dann haben also alle Funktionen das gleiche Format:
 *
 *            double fOperation(double, double)
 *
 *            Schreiben Sie die Funktionsadressen in ein Feld von Funktionszeigern
 *            für diesen Typ, und berechnen Sie damit dann diese Formel:
 *
 *            27.3 * 3.8 / 1.05 / 1.05 / 1.05 % 11.2
 *
 *            Geben Sie das Ergebnis formatiert über die Konsole aus.
 *
 *            Bemerkung: Alle Operationen haben die gleiche Priorität,
 *                       d.h. von links nach rechts auswerten.
 *
 *
 * Aufgabe 2: Gegeben sei folgender vector:
 *	      vector<double> v = { 1.5, 3.14, 98.12, 17.5, 9.99, 2.89 };
 *
 *	      a) Erstellen sie eine Funktion, die aus den Werten des Vectors den kleinsten Wert
 *           ermittelt.
 *
 *        b) Erstellen sie eine Funktion, die aus den Werten des Vectors den größten Wert
 *           ermittelt.
 *
 * 	      c) Erstellen sie eine Funktion, welche die Summe aller Werte des Vectors
 *		     berechnet.
 *
 *	      d) Erstellen sie eine Funktion, die aus den Werten des Vectors den 
 *           Durchschnittswert berechnet.
 *
 * 	      e) Erstellen sie eine Funktion, die aus den Werten des Vectors die 
 *           Standardabweichung berechnet.
 *
 *           Hinweis:
 *           Die Standardabweichung ist definiert als die Quadratwurzel der Varianz.
 *           Die Varianz gibt die mittlere quadratische Abweichung der Ergebnisse um ihren
 *           Mittelwert an.
 *           Um diese zu berechen, nehmen wir alle Werte aus dem Vector und ziehen von diesen
 *		     jeweils den Durchschnittswert ab. Die Differenz muss dann quadriert (hoch 2) und
 *           davon die Summe gebildet werden.
 *		     Am Ende wird noch durch die Anzahl der Werte dividiert und aus diesem Ergbebnis
 *           die Wurzel gezogen.
 *
 * 	      f) Erstellen sie eine Funktion double calc(vector<double> v, fz) die einen Vector
 *           mit double Werten übergeben bekommt und einen Zeiger auf jeweils eine der o.g. 
 *           Funktionen.
 *
 *           Geben Sie das Ergebnis formatiert über die Konsole aus.
 */

#include <iostream>
#include <vector>

using namespace std;

void aufgabe1();
void aufgabe2();

double addition(const double, const double);
double subtraktion(const double, const double);
double division(const double, const double);
double multiplikation(const double, const double);
double modifizierteModulo(const double, const double);

double minDouble(vector<double>);
double maxDouble(vector<double>);
double sumDouble(vector<double>);
double averageDouble(vector<double>);
double stanDevDouble(vector<double>);
double calc(vector<double>, double (*)(vector<double>));

int main()
{
	locale::global(locale("German_germany"));
	
	aufgabe1();

	aufgabe2();

	return EXIT_SUCCESS;
}

void aufgabe1()
{
	double (*fOperation[])(const double, const double) {
		addition, subtraktion, division, multiplikation, modifizierteModulo
	};

	// 27.3 * 3.8 / 1.05 / 1.05 / 1.05 % 11.2

	double result = fOperation[3](27.3, 3.8);
	result = fOperation[2](result, 1.05);
	result = fOperation[2](result, 1.05);
	result = fOperation[2](result, 1.05);
	result = fOperation[4](result, 11.2);

	printf("\nAufgabe 1: %1.6f\n\n", result);
}

void aufgabe2()
{
	cout << endl << "Aufgabe 2: " << endl << endl;

	vector<double> v = { 1.5, 3.14, 98.12, 17.5, 9.99, 2.89 };

	printf("minDouble    : %1.2f\n", calc(v, minDouble));
	printf("maxDouble    : %1.2f\n", calc(v, maxDouble));
	printf("sumDouble    : %1.2f\n", calc(v, sumDouble));
	printf("averageDouble: %1.2f\n", calc(v, averageDouble));
	printf("stanDevDouble: %1.2f\n", calc(v, stanDevDouble));
}

double addition(const double x, const double y)
{
	return x + y;
}

double subtraktion(const double x, const double y)
{
	return x - y;
}
double division(const double x, const double y)
{
	return x / y;
}

double multiplikation(const double x, const double y)
{
	return x * y;
}

double modifizierteModulo(const double x, const double y)
{
	auto quotient = static_cast<int>(x / y);

	return x - quotient * y;
}

double minDouble(vector<double> vec)
{
	double retValue = vec[0];

	for (auto v : vec)
		if (retValue > v)
			retValue = v;

	return retValue;
}

double maxDouble(vector<double> vec)
{
	double retValue = vec[0];

	for (auto v : vec)
		if (retValue < v)
			retValue = v;

	return retValue;
}

double sumDouble(vector<double> vec)
{
	double retValue = 0;

	for (auto v : vec)
		retValue += v;

	return retValue;
}

double averageDouble(vector<double> vec)
{
	return sumDouble(vec) / vec.size();
}

double stanDevDouble(vector<double> vec)
{
	double sum = 0;
	double average = averageDouble(vec);

	for (auto v : vec)
		sum += pow(v - average, 2);

	return sqrt(sum / vec.size());
}

double calc(vector<double> v, double (*fz)(vector<double>))
{
	return fz(v);
}
