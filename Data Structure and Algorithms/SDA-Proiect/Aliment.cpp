#include "Aliment.h"

Aliment::Aliment(std::string n, float c)
{
	this->nume = n;
	this->calorii = c;
}

std::string Aliment::getNume() const
{
	return this->nume;
}

float Aliment::getCalorii() const
{
	return this->calorii;
}

bool Aliment::operator==(const Aliment & a)
{
	if (this->calorii == a.getCalorii() && this->nume == a.getNume())
		return true;
	return false;
}

bool Aliment::operator!=(const Aliment & a)
{
	if (this->calorii == a.getCalorii() && this->nume == a.getNume())
		return false;
	return true;
}

std::ostream & operator<<(std::ostream & os, const Aliment & a)
{
	return os << "Nume aliment: " << a.nume << ", Calorii: " << a.calorii << "\n";
}
