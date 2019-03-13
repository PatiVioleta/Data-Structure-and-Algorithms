#include "ListaOrdonata.h"
#include "Iterator.h"
#include "Aliment.h"
#include "Service.h"

#include <iostream>

using namespace std;
class Error {
public:
	//Constructor
	Error(std::string message)noexcept : message(message) {}

	//Return the message of the exception
	const std::string& getMessage() const noexcept {
		return message;
	}
private:
	//message
	std::string message;
};

void meniu()
{
	cout << "MENIU:\n";
	cout << "1.Adaugati un aliment\n";
	cout << "2.Stergeti un aliment\n";
	cout << "3.Afisati lista pentru o zi SEDENTARA\n";
	cout << "4.Afisati lista pentru o zi ACTIVA\n";
	cout << "5.Afisare toata lista\n";
	cout << "0.EXIT\n";
}

void creeazaLista(ListaOrdonata& lo)
{
	lo.adauga(Aliment("Afine",46));
	lo.adauga(Aliment("Mere", 30));
	lo.adauga(Aliment("Ananas", 157));
	lo.adauga(Aliment("Caise", 47));
	lo.adauga(Aliment("Paine", 300));
	lo.adauga(Aliment("Friptura", 500));
	lo.adauga(Aliment("Salata", 120));
	lo.adauga(Aliment("Cartofi", 310));
	lo.adauga(Aliment("Orez", 220));
	lo.adauga(Aliment("Muraturi", 190));
	lo.adauga(Aliment("Tocana", 315));
	lo.adauga(Aliment("Gratar", 650));
	lo.adauga(Aliment("Ciuperci", 250));
	lo.adauga(Aliment("Vinete", 280));
	lo.adauga(Aliment("Ardei", 130));
	lo.adauga(Aliment("Rosii", 140));
}

void creeazaLista1(ListaOrdonata& lo)
{
	lo.adauga(Aliment("Mure", 60));
	lo.adauga(Aliment("Iaurt", 70));
	lo.adauga(Aliment("Stafide", 170));
}

void tiparesteLista(const ListaOrdonata& lo,int& nrAlimente)
{
	if (lo.vida())
		cout << "Lista e vida\n";
	else
	{
		cout << "\n";
		Iterator it = lo.iterator();
		it.prim();
		while (it.valid() && nrAlimente>0)
		{
			cout << it.element();
			nrAlimente--;
			it.urmator();
		}
		cout << "\n";
	}
}

void tiparesteListaInv(const ListaOrdonata& lo, int& nrAlimente)
{
	if (lo.vida())
		cout << "Lista e vida\n";
	else
	{
		Iterator it = lo.iterator();
		it.ultim();
		while (it.valid() && nrAlimente>0)
		{
			cout << it.element();
			nrAlimente--;
			it.anterior();
		}
		cout << "\n";
	}
}

bool R(const Aliment a1,const Aliment a2)
{
	if (a1.getCalorii() < a2.getCalorii())
		return true;
	return false;
}

bool R1(const Aliment a1, const Aliment a2)
{
	if (a1.getCalorii() > a2.getCalorii())
		return true;
	return false;
}

void ziSedentara(const ListaOrdonata& lo)
{
	if (lo.vida())
		cout << "Lista e vida\n";
	else
	{
		float total = 0;
		int nrAlimente = 0;
		Iterator it = lo.iterator();
		it.prim();
		while (it.valid() && total<1800)
		{
			nrAlimente++;
			total += it.element().getCalorii();
			it.urmator();
		}
		if (total < 1800  || nrAlimente==0)
			cout << "Insuficiente alimente!\n\n";
		else
		{
			cout << "\nAlimentele pentru astazi:\n";
			tiparesteLista(lo, nrAlimente);
			cout << "Total: " << total << "\n\n";
		}
	}
}

void ziActiva(const ListaOrdonata& lo)
{
	if (lo.vida())
		cout << "Lista e vida\n";
	else
	{
		float total = 0;
		int nrAlimente = 0;
		Iterator it = lo.iterator();
		it.ultim();
		while (it.valid() && total+it.element().getCalorii()<=3000)
		{
			nrAlimente++;
			total += it.element().getCalorii();
			it.anterior();
		}
		if (nrAlimente==0)
			cout << "Insuficiente alimente!\n\n";
		else
		{
			cout << "\nAlimentele pentru astazi:\n";
			tiparesteListaInv(lo, nrAlimente);
			cout << "Total: " << total << "\n\n";
		}
	}
}

void ui_adauga(Service serv)
{
	std::string nume;
	float cal;
	std::cout << "Dati numele alimentului: ";
	std::cin >> nume;
	std::cout << "Introduceti nr de calorii: ";
	std::cin >> cal;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw Error("INTRODUCETI UN NUMAR!!!\n");
	}
	if (cal < 0)
		throw Error("NR DE CALORII NU POATE SA FIE NEGATIV!!!\n");
	std::cout << "\n";
	serv.adauga(nume, cal);
}

void ui_sterge(Service serv)
{
	std::string nume;
	float cal;
	std::cout << "Dati numele alimentului: ";
	std::cin >> nume;
	std::cout << "Introduceti nr de calorii: ";
	std::cin >> cal;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw Error("INTRODUCETI UN NUMAR!!!\n");
	}
	int dimVechi = serv.dim();
	serv.sterge(nume, cal);
	if (dimVechi == serv.dim())
		std::cout << "NU A FOST GASIT UN ASTFEL DE ALIMENT PENTRU STERGERE!!!\n";
	std::cout << "\n";
}

void interclaseaza(const ListaOrdonata& lo, const ListaOrdonata& lo1)
{
	ListaOrdonata lo2(R);
	Iterator it = lo.iterator();
	it.prim();
	while (it.valid())
	{
		lo2.adauga(it.element());
		it.urmator();
	}

	Iterator it1 = lo1.iterator();
	it1.prim();
	while (it1.valid())
	{
		lo2.adauga(it1.element());
		it1.urmator();
	}

	int dime = lo2.getDim();
	tiparesteLista(lo2, dime);
}

int main()
{
	ListaOrdonata lo(R);
	ListaOrdonata lo1(R1);
	creeazaLista(lo);
	creeazaLista1(lo1);

	int dime = lo.getDim();
	tiparesteLista(lo, dime);

	int dime1 = lo1.getDim();
	tiparesteLista(lo1, dime1);

	interclaseaza(lo, lo1);

	Service serv{ lo };

	while (1)
	{
		try
		{
			meniu();

			int com, d;
			cout << "\nAlegeti comanda: \n";
			cin >> com;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw Error("INTRODUCETI UN NUMAR!!!\n");
			}
			switch (com) {
			case 1: ui_adauga(serv); break;
			case 2: ui_sterge(serv); break;
			case 3: ziSedentara(lo); break;
			case 4: ziActiva(lo); break;
			case 5: d = serv.dim(); tiparesteLista(lo, d); break;
			case 0: return 0;
			defaulte: return 0;
			}
		}
		catch (Error& err)
		{
			std::cout << err.getMessage() << std::endl;
		}
	}

	return 0;
}