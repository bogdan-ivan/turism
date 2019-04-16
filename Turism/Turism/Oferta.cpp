#include "Oferta.h"
#include <iostream>

int Oferta::counter = 0;

Oferta::Oferta()
	:m_tip(INVALID),m_pret(-1),m_dataPlecare("Undefined"),m_dataIntoarcere("Undefined")
{
	m_destinatie.first = "Undefined";
	m_destinatie.second = "Undefined";
	++counter;
	m_id = counter;
}

Oferta::Oferta(TIPURI type, float price, std::string departure, std::string returning, destination dest)
	:m_tip(type),m_pret(price),m_dataPlecare(departure),m_dataIntoarcere(returning)
{
	m_destinatie.first = dest.first;
	m_destinatie.second = dest.second;
	++counter;
	m_id = counter;
}

Oferta::Oferta(const Oferta & other)
{
	this->m_tip = other.m_tip;
	this->m_pret = other.m_pret;
	this->m_dataPlecare = other.m_dataPlecare;
	this->m_dataIntoarcere = other.m_dataIntoarcere;
	this->m_destinatie = other.m_destinatie;
	this->m_id = other.m_id;
}

Oferta::Oferta(const Oferta && other)
{

}

Oferta::~Oferta()
{
	--counter;
}

void Oferta::setTip(int type)
{
	if (type < -1 || type > 2)
	{
		std::cerr << "Can't set type: Invalid type !" << std::endl;
		return;
	}
	m_tip = type;
}

int Oferta::getTip()
{
	return m_tip;
}

void Oferta::setPret(float price)
{
	if (price < 0)
	{
		std::cerr << "Can't set price: Negative price !" << std::endl;
		return;
	}
	m_pret = price;
}

float Oferta::getPret()
{
	return m_pret;
}

void Oferta::setPlecare(const std::string & departure)
{
	//TODO
	//clasa date care verifica corectitudinea datelor introduse
	m_dataPlecare = departure;
}

std::string Oferta::getPlecare()
{
	return m_dataPlecare;
}

void Oferta::setIntoarcere(const std::string & returning)
{
	m_dataIntoarcere = returning;
}

std::string Oferta::getIntoarcere()
{
	return m_dataIntoarcere;
}

void Oferta::setDestination(destination dest)
{
	m_destinatie.first = dest.first;
	m_destinatie.second = dest.second;
}

destination Oferta::getDestinatie()
{
	return m_destinatie;
}

int Oferta::getID()
{
	return m_id;
}