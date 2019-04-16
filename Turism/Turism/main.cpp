// Aplicatie pentru agentie de turism
// pentru gestionarea ofertelor
// C.R.U.D
// create, read, update, delete

#include "Agentie.h"

void main()
{
	Agentie trivago;
	trivago.insertOffer(MARE, 500, "22.06.2019", "27.06.2019", std::make_pair("Romania", "Constanta"));
	trivago.printOffers(NORMAL);
	trivago.updateOffer(1, PRET, 600.0f);
	trivago.updateOffer(1, TIP, MUNTE);
	trivago.printOffers(NORMAL);
}