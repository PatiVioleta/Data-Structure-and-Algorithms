#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

#include "ListaOrdonata.h"
#include "Aliment.h"

typedef Aliment TElement;
class ListaOrdonata;

/*
CLASA ITERATOR
*/
class Iterator {
private:
	/*
	Constructorul iteratorului
	In: lista ordonata
	Post: s-a construit iteratorul pe lista ordonata
	*/
	Iterator(const ListaOrdonata& lst);

	//campul lista ordonata al iteratorului
	const ListaOrdonata& lista;

	//campul curent al iteratorului- retine elementul curent din lista
	int curent;

public:
	//Iteratorul trebuie sa aiba acces la clasa Lista Ordonata
	friend class ListaOrdonata;

	//seteaza iteratorul pe prima pozitie in lista ordonata
	void prim();

	//seteaza iteratorul pe ultima pozitie in lista
	void ultim();

	//returneaza adevarat daca iteratorul refera un element valid, fals altfel
	bool valid();

	/*
	Returneaza elementul curent
	Post: elementul este de tip TElement
	*/
	TElement element() const;

	//seteaza iteratorul pe urmatoarea pozitie
	void urmator();

	//seteaza iteratorul pe pozitia anterioara
	void anterior();
};


#endif