#pragma once
#include "Oferta.h"
#include <map>
#include <vector>

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
	void menu();
	bool insertOffer(TIPURI type, float price, std::string departure, std::string returning, destination dest);
	bool deleteOffer(int ID);
	bool updateOffer(int ID, UPDATE updateType, float argument);
	bool updateOffer(int ID, UPDATE updateType, std::string argument);
	bool updateOffer(int ID, UPDATE updateType, destination);
	void printOffers(SORT printType);
private:
	bool m_enabled;
	std::vector<Oferta*> sorting;
};



