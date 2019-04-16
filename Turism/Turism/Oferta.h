#pragma once

#include <string>

enum TIPURI
{
	INVALID = -1,
	MARE,
	MUNTE,
	CITY_BREAK
};

typedef std::pair<std::string, std::string> destination;

class Oferta
{
private:
	int m_tip;
	float m_pret;
	std::string m_dataPlecare;
	std::string m_dataIntoarcere;
	std::pair<std::string, std::string> m_destinatie;
	int m_id;
	static int counter;
public:
	Oferta();
	explicit Oferta(TIPURI type, float price, std::string departure, std::string returning, destination dest);
	Oferta(const Oferta& other);
	Oferta(const Oferta&& other);
	~Oferta();

	void setTip(int type);
	int getTip();
	void setPret(float price);
	float getPret();
	void setPlecare(const std::string& departure);
	std::string getPlecare();
	void setIntoarcere(const std::string& returning);
	std::string getIntoarcere();
	void setDestination(destination dest);
	destination getDestinatie();
    int getID();
};