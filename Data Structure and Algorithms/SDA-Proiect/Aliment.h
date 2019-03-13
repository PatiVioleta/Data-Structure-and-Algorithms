#pragma once
#ifndef ALIMENT_H
#define ALIMENT_H

#include <string>
#include <ostream>

/*
CLASA DE ALIMENTE
*/
class Aliment {
private:
	//definim operatorul de afisare a unui aliment
	friend std::ostream& operator<<(std::ostream& os, const Aliment& a);

	//campul nume aliment
	std::string nume="";

	//campul calorii aliment
	float calorii=0;

public:
	//constructor default pentru aliment
	Aliment() = default;

	/*
	Constructor aliment
	In: n=numele alimentului, c=nr de calorii
	Pre: n-string, c-float
	Post: s-a creat obiectul aliment
	*/
	Aliment(std::string n,float c);

	/*
	Returneaza numele unui aliment
	Out: numele alimentului
	Post: numele returnat este un string
	*/
	std::string getNume() const;

	/*
	Returneaza nr de calorii ale alimentului
	Out:  nr de calorii
	Post: nr de calorii este de tip float
	*/
	float getCalorii() const;

	//definim operatorul de egalitate
	bool operator==(const Aliment& a);

	//definim operatorul !=
	bool operator!=(const Aliment& a);
};

#endif