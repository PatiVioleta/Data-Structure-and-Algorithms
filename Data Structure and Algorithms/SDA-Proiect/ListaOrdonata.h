#pragma once
#ifndef LISTA_ORDONATA_H
#define LISTA_ORDONATA_H
#include "Iterator.h"
#include "Aliment.h"

#define Max 100

typedef Aliment TElement;
class Iterator;

/*
CLASA LISTA ORDONATA
*/
class ListaOrdonata {
private:
	//campul pentru capacitatea maxima a listei ordonate
	static const int cp=Max;

	//campul pentru dimensiunea listei ordonate
	int dim = 0;

	//campul pentru vectorul de elemente
	TElement e[Max];

	//campul pentru vectorul de urmatori
	int urm[Max];

	//campul pentru vectorul de precedenti
	int prec[Max];

	//campul pentru primul element din lista ordonata
	int prim;

	//campul pentru ultimul element din lista ordonata
	int ultim;

	//campul pentru primul element liber din lista ordonata
	int primLiber;

	//functia dupa care se va ordona lista
	bool(*R)(const TElement, const TElement);

	//functia de alocare, returneaza noul nod alocat
	int aloca();

	//functia de dealocare, dealoca nodul i
	void dealoca(int i);

	//creeaza un nou nod cu valoarea e si il returneaza
	int creeazaNod(TElement e);

public:
	//clasa lista ordonata trebuie sa aiba acces la clasa iterator
	friend class Iterator;

	/*
	Constructor pentru lista ordonata
	In: functia de comparare
	Post: s-a creat lista ordonata
	*/
	ListaOrdonata(bool(*R)(const TElement, const TElement));

	//destructor pentru lista ordonata
	~ListaOrdonata();

	//returneaza true daca lista e vida si false altfel
	bool vida() const;

	//returneaza numarul de elemente din lista
	int getDim() const { return dim; };

	/*
	Adauga un element in lista ordonata
	In: e noul element
	Post: e a fost adaugat corect in lista ordonata
	*/
	void adauga(TElement e);

	/*
	Sterge un element din lista ordonata
	In: e elementul de sters
	Post: e a fost sters din lista daca a fost gasit
	*/
	void sterge(TElement e);

	//returneaza un iterator pe lista ordonata
	Iterator iterator()const;
};

#endif