#include <iostream>
#include "Adapter.h"


int main()
{
	CardReader myCard;

	myCard.readCard();

	myCard.insertCard(CardReader::eSD);

	myCard.readCard();

	myCard.insertCard(CardReader::eMemoryStick);

	myCard.removeCard();

	myCard.insertCard(CardReader::eMemoryStick);

	myCard.readCard();

	myCard.removeCard();

	system("pause");
	return 0;
}