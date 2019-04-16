#include "Agentie.h"
#include <iostream>

Agentie::Agentie()
{

}

Agentie::~Agentie()
{

}

bool Agentie::insertOffer(TIPURI type, float price, std::string departure, std::string returning, destination dest)
{
	Oferta* offer = new Oferta(type, price, departure, returning, dest);
	info.insert(std::make_pair(offer->getID(), offer));
	return true;
}

bool Agentie::deleteOffer(int ID)
{
	return true;
	info.erase(ID);
}

void Agentie::printOffers(SORT printType)
{
	auto it = info.begin();

	switch (printType)
	{
	case NORMAL:
		for (it; it != info.end(); it++)
		{
			std::cout << "ID : " << it->first << " ---> " << it->second->getTip() << " " << it->second->getPret() << " lei " << it->second->getPlecare() << " " << it->second->getIntoarcere() << " " << it->second->getDestinatie().first << " " << it->second->getDestinatie().second << std::endl;
		}
		break;
	case CRESCATOR_PRET:
		//TODO
		break;
	case DESCRESCATOR_PRET:
		//TODO
		break;
	case CRESCATOR_DESTINATIE:
		//TODO
		break;
	case DESCRESCATOR_DESTINATIE:
		//TODO
		break;
	default:
		break;
	}
}


