#include "Agentie.h"
#include <iostream>
#include <algorithm>
#include <tuple>

Agentie::Agentie()
	:m_enabled(true)
{
	sorting.reserve(5);
}

Agentie::~Agentie()
{

}

void Agentie::menu()
{
	while (m_enabled)
	{
		int option;
		std::cout << "1 to insert, 2 to detele, 3 to update, 4 to print, 5 to exit" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			int t_tip;
			float t_pret;
			std::string t_dataPlecare;
			std::string t_dataIntoarcere;
			std::string t_tara;
			std::string t_oras;
			std::cout << "Inserting a new offer :" << std::endl;
			std::cout << "Care este tipul ? (Mare,Munte,CityBreak)" << std::endl;
			std::cin >> t_tip;
			std::cout << "Care este pretul ?" << std::endl;
			std::cin >> t_pret;
			std::cout << "Care este data de plecare ? dd.mm.yyyy" << std::endl;
			std::cin >> t_dataPlecare;
			std::cout << "Care este data de intoarcere ? dd.mm.yyyy" << std::endl;
			std::cin >> t_dataIntoarcere;
			std::cout << "Care este destinatia ? " << std::endl;
			std::cout << "Tara : " ;
			std::cin >> t_tara;
			std::cout << "Oras : " ;
			std::cin >> t_oras;
			insertOffer(static_cast<TIPURI>(t_tip), t_pret, t_dataPlecare, t_dataIntoarcere, std::make_pair(t_tara, t_oras));
			break;
		}
		case 2:
			int t_id;
			std::cout << "Deleting an offer :" << std::endl;
			std::cout << "Care este ID-ul ofertei ?" << std::endl;
			std::cin >> t_id;
			deleteOffer(t_id);
			break;
		case 3:
		{
			int t_id;
			int t_updateType;
			float numericArgument;
			std::string stringArgument;
			std::string t_tara;
			std::string t_oras;
			std::cout << "Updating an offer :" << std::endl;
			std::cout << "Care este ID-ul ofertei ?" << std::endl;
			std::cin >> t_id;
			std::cout << "Ce modificare doriti ? (tip, pret, plecare, intoarcere, destinatie)" << std::endl;
			std::cin >> t_updateType;
			if (t_updateType < 2)
			{
				std::cout << "Introduceti pretul nou :" << std::endl;
				std::cin >> numericArgument;
				updateOffer(t_id, static_cast<UPDATE>(t_updateType), numericArgument);
			}
			else if (t_updateType < 4)
			{
				std::cout << "Introduceti data noua :" << std::endl;
				std::cin >> stringArgument;
				updateOffer(t_id, static_cast<UPDATE>(t_updateType), stringArgument);
			}
			else
			{
				std::cout << "Care este destinatia ? " << std::endl;
				std::cout << "Tara : " ;
				std::cin >> t_tara;
				std::cout << "Oras : " ;
				std::cin >> t_oras;
				updateOffer(t_id, static_cast<UPDATE>(t_updateType), std::make_pair(t_tara,t_oras));
			}
			break;
		}
		case 4:
			int type;
			std::cout << "Modul de afisare : (normal,cpret,dpret,cdestinatie,ddestinatie)" << std::endl;
			std::cin >> type;
			printOffers(static_cast<SORT>(type));
			break;
		case 5:
			m_enabled = false;
			break;
		default:
			break;
		}
	}
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

bool Agentie::updateOffer(int ID, UPDATE updateType, float argument)
{
	switch (updateType)
	{
		case TIP:
			info.at(ID)->setTip(static_cast<int>(argument));
			break;
		case PRET:
			info.at(ID)->setPret(argument);
			break;
		default:
			return false;
	}	
}

bool Agentie::updateOffer(int ID, UPDATE updateType, std::string argument)
{
	switch (updateType)
	{
	case PLECARE:
		info.at(ID)->setPlecare(argument);
		break;
	case INTOARCERE:
		info.at(ID)->setIntoarcere(argument);
		break;
	default:
		return false;
	}
}

bool Agentie::updateOffer(int ID, UPDATE updateType, destination argument)
{
	switch (updateType)
	{
	case DESTINATIE:
		info.at(ID)->setDestination(argument);
		break;
	default:
		return false;
	}
}

void Agentie::printOffers(SORT printType)
{
	auto it = info.begin();

	switch (printType)
	{
	case NORMAL:
		for (it; it != info.end(); ++it)
		{
			std::cout << "ID : " << it->first << " ---> " << it->second->getTip() << " " << it->second->getPret() << " lei " << it->second->getPlecare() << " " << it->second->getIntoarcere() << " " << it->second->getDestinatie().first << " " << it->second->getDestinatie().second << std::endl;
		}
		break;
	case CRESCATOR_PRET:
		//TODO
		for (it; it != info.end(); ++it)
		{
			sorting.push_back(it->second);
		}
		std::sort(sorting.begin(), sorting.end(), [](Oferta* first, Oferta* second)
		{
			return first->getPret() < second->getPret();
		});
		for (auto it = sorting.begin(); it != sorting.end(); ++it)
		{
			std::cout << "ID : " << (*it)->getID() << " ---> " << (*it)->getTip() << " " << (*it)->getPret() << " lei " << (*it)->getPlecare() << " " << (*it)->getIntoarcere() << " " << (*it)->getDestinatie().first << " " << (*it)->getDestinatie().second << std::endl;
		}
		for (auto of : sorting)
		{
			delete of;
		}
		sorting.clear();
		break;
	case DESCRESCATOR_PRET:
		//TODO
		for (it; it != info.end(); ++it)
		{
			sorting.push_back(it->second);
		}
		std::sort(sorting.begin(), sorting.end(), [](Oferta* first, Oferta* second)
		{
			return first->getPret() > second->getPret();
		});
		for (auto it = sorting.begin(); it != sorting.end(); ++it)
		{
			std::cout << "ID : " << (*it)->getID() << " ---> " << (*it)->getTip() << " " << (*it)->getPret() << " lei " << (*it)->getPlecare() << " " << (*it)->getIntoarcere() << " " << (*it)->getDestinatie().first << " " << (*it)->getDestinatie().second << std::endl;
		}
		for (auto of : sorting)
		{
			delete of;
		}
		sorting.clear();
		break;
	case CRESCATOR_DESTINATIE:
		//TODO
		for (it; it != info.end(); ++it)
		{
			sorting.push_back(it->second);
		}
		std::sort(sorting.begin(), sorting.end(), [](Oferta* first, Oferta* second)
		{
			return std::tie(first->getDestinatie().first, first->getDestinatie().second) < std::tie(second->getDestinatie().first, second->getDestinatie().second);
		});
		for (auto it = sorting.begin(); it != sorting.end(); ++it)
		{
			std::cout << "ID : " << (*it)->getID() << " ---> " << (*it)->getTip() << " " << (*it)->getPret() << " lei " << (*it)->getPlecare() << " " << (*it)->getIntoarcere() << " " << (*it)->getDestinatie().first << " " << (*it)->getDestinatie().second << std::endl;
		}
		for (auto of : sorting)
		{
			delete of;
		}
		sorting.clear();
		break;
	case DESCRESCATOR_DESTINATIE:
		//TODO
		for (it; it != info.end(); ++it)
		{
			sorting.push_back(it->second);
		}
		std::sort(sorting.begin(), sorting.end(), [](Oferta* first, Oferta* second)
		{
			return std::tie(first->getDestinatie().first, first->getDestinatie().second) > std::tie(second->getDestinatie().first, second->getDestinatie().second);
		});
		for (auto it = sorting.begin(); it != sorting.end(); ++it)
		{
			std::cout << "ID : " << (*it)->getID() << " ---> " << (*it)->getTip() << " " << (*it)->getPret() << " lei " << (*it)->getPlecare() << " " << (*it)->getIntoarcere() << " " << (*it)->getDestinatie().first << " " << (*it)->getDestinatie().second << std::endl;
		}
		for (auto of : sorting)
		{
			delete of;
		}
		sorting.clear();
		break;
	default:
		break;
	}
}
