#include "ListaOrdonata.h"
#include <iostream>

int ListaOrdonata::aloca()
{
	int i = primLiber;             //extragem primul liber din sirul de pozitii libere
	primLiber = urm[primLiber];    //prim liber se muta pe urmatoarea pozitie libera
	return i;                      //returnam noul nod alocat
}

void ListaOrdonata::dealoca(int i)
{
	urm[i] = primLiber;    //legam elementul de pe pozitia i de primul liber
	primLiber = i;         //noul prim liber este i
}

int ListaOrdonata::creeazaNod(TElement e)
{
	int i = aloca();      //alocam spatiu pt noul nod
	if (i != -1)          //daca exista spatiu liber
	{
		this->e[i] = e;   //punem elementul in vector pe noua pozitie i
		urm[i] = -1;      //marcam faptul ca dupa nodul e nu mai avem elemente
		prec[i] = -1;     //marcam faptul ca inainte de noul nod nu avem elemente
	}
	return i;             //returnam noul nod
}

ListaOrdonata::ListaOrdonata(bool(*R)(const TElement, const TElement))
{
	this->prim = -1;         //la inceput lista e vida
	this->ultim = -1;        //la inceput lista e vida

	for (int i = 0; i < cp - 1; i++)   //initializam vectorul de urmatori
		urm[i] = i + 1;
	urm[cp - 1] = -1;

	for (int i = 1; i < cp; i++)       //initializam vectorul de predecesori
		prec[i] = i - 1;
	prec[0] = -1;

	this->primLiber = 0;               //initializam primul liber cu 0
	this->R = R;                       //initializam relatia R
}

ListaOrdonata::~ListaOrdonata()
{
	int i = ultim;          //incepem de pe ultima pozitie pe care avem element
	while (i!=-1)           //cat timp mai avem elemente in lista
	{
		dealoca(i);         //dealocam
		i = prec[i];        //trecem la precedentul
	}
	 
	prim = -1;              //prim devine -1 deoarece lista acum e vida
	ultim = -1;             //ultim devine -1 deoarece lista acum e vida
}

bool ListaOrdonata::vida() const
{
	if (getDim() == 0)
		return true;
	else
		return false;
}

void ListaOrdonata::adauga(TElement e)
{
	int i = creeazaNod(e);                //cream noul nod de adaugat
	
	if (i != -1) {
		if (vida())                       //daca lista e vida actualizam prim si ultim
		{
			prim = i;
			ultim = i;
		}
		else
			if (R(e, this->e[prim]))      //adaugare inaintea primului nod
			{
				urm[i] = prim;
				prec[prim] = i;
				prim = i;
			}
		else
			if (R(this->e[ultim], e))     //adaugare dupa ultimul nod
			{
				urm[ultim] = i;
				prec[i] = ultim;
				ultim = i;
			}
		else                              //adaugare undeva in lista ordonata
		{
			int j = prim;         
			while (j != -1 && R(this->e[urm[j]],e))            
				j = urm[j];        

			prec[urm[j]] = i;
			urm[i] = urm[j];
			urm[j] = i;
			prec[i] = j;
		}
	dim++;
	}

}

void ListaOrdonata::sterge(TElement e)
{
	if (this->e[prim] == e && getDim() == 1)      //daca avem un singur nod si trebuie sters
	{
		dealoca(prim);
		prim = -1;
		ultim = -1;
		dim--;
	}
	else
		if (this->e[prim] == e)                   //stergem primul nod
		{
			int aux = urm[prim];
			prec[aux] = -1;
			dealoca(prim);
			prim = aux;
			dim--;
		}
	else
		if (this->e[ultim] == e)                 //stergem ultimul nod
		{
			int aux = prec[ultim];
			urm[aux] = -1;
			dealoca(ultim);
			ultim = aux;
			dim--;
		}
	else                                         //stergem undeva in lista ordonata
	{
		int j = prim;
		while (j != -1 && this->e[urm[j]]!=e)
			j = urm[j];

		if (j != -1)
		{
			int aux = urm[j];
			prec[urm[aux]] = j;
			urm[j] = urm[aux];
			dealoca(aux);
			dim--;
		}
		
	}

}

Iterator ListaOrdonata::iterator() const
{
	return Iterator(*this);        //apelam constructorul iteratorului pe lista curenta
}

