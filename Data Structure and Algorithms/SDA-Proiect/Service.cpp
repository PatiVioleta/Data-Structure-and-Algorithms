#include "Service.h"

void Service::adauga(std::string nume, float cal)
{
	Aliment a{ nume, cal };
	lo.adauga(a);
}

void Service::sterge(std::string nume, float cal)
{
	Aliment a{ nume, cal };
	lo.sterge(a);
}
