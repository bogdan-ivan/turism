#pragma once
#include "Oferta.h"
#include <map>

enum SORT
{
	NORMAL,
	CRESCATOR_PRET,
	DESCRESCATOR_PRET,
	CRESCATOR_DESTINATIE,
	DESCRESCATOR_DESTINATIE,
};

enum UPDATE
{
	TIP,
	PRET,
	PLECARE,
	INTOARCERE,
	DESTINATIE
};

class Agentie
{
private:
	std::map<int,Oferta*> info;
public:
	Agentie();
	~Agentie();
	bool insertOffer(TIPURI type, float price, std::string departure, std::string returning, destination dest);
	bool deleteOffer(int ID);
	template <typename T>
	bool updateOffer(int ID, UPDATE updateType, T argument);
	void printOffers(SORT printType);
};

// nu este implementat bine template-ul
// merg doar int,float
template <typename T>
bool Agentie::updateOffer(int ID, UPDATE updateType, T argument)
{
	switch (updateType)
	{
	case TIP:
		info.at(ID)->setTip(argument);
		break;
	case PRET:
		info.at(ID)->setPret(argument);
		break;
	case PLECARE:
		//info.at(ID)->setPlecare(argument);
		break;
	case INTOARCERE:
		//info.at(ID)->setIntoarcere(argument);
		break;
	case DESTINATIE:
		//info.at(ID)->setDestinatie(argument);
		break;
	default:
		break;
	}

	return false;
}

