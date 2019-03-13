#pragma once
#ifndef SERVICE_H
#define SERVICE_H

#include "ListaOrdonata.h"

/*
CLASA SERVICE
*/
class Service {
private:
	//campul lista ordonata
	ListaOrdonata & lo;

public:
	//constructor default
	Service() = default;

	/*
	Constructor service
	In: lo lista ordonata
	*/
	Service(ListaOrdonata& lo): lo{lo} {}

	/*
	Functia de adaugare
	In: nume- numele alimentului, cal- nr de calorii
	Pre: nume este string, caloriile sunt float
	Post: a fost adaugat alimentul cu numele si caloriile date
	*/
	void adauga(std::string nume, float cal);

	/*
	Functia de stergere
	In: nume- numele alimentului, cal- nr de calorii
	Pre: nume este string, caloriile sunt float
	Post: a fost sters alimentul cu numele si caloriile date
	*/
	void sterge(std::string nume, float cal);

	//returneaza dimensiunea curenta a listei
	int dim() { return lo.getDim(); }
};

#endif