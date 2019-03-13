#include "Iterator.h"

Iterator::Iterator(const ListaOrdonata & lst): lista(lst)
{
	curent = lista.prim;
}

void Iterator::prim()
{
	curent = lista.prim;
}

void Iterator::ultim()
{
	curent = lista.ultim;
}

bool Iterator::valid()
{
	return curent != -1;
}

TElement Iterator::element() const
{
	return lista.e[curent];
}

void Iterator::urmator()
{
	curent = lista.urm[curent];
}

void Iterator::anterior()
{
	curent = lista.prec[curent];
}
