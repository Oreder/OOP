#include "Adapter.h"
#include <stdio.h>

void SD::readCard()
{
	printf("Reading SD Card..\n");
}


void MemoryStick::readCard()
{
	printf("Reading MemoryStick Card..\n");
}


CardReader::CardReader() : _insertedCard(nullptr){}

CardReader::~CardReader()
{
	delete _insertedCard;
}


void CardReader::insertCard(unsigned char type)
{
	if (!_insertedCard)
	{
		switch (type)
		{
		case eSD:
			_insertedCard = new SD();
			break;

		case eMemoryStick:
			_insertedCard = new MemoryStick();
			break;

		default:
			printf("Error: Invalid type of CardReader!\n");
			break;
		}
	}
	else
	{
		printf("Notice: A card is already inside the CardReader, please remove it first before inserting your new one!\n");
	}
}


void CardReader::readCard()
{
	if (_insertedCard)
		_insertedCard->readCard();
	else
		printf("Notice: Please insert card before reading!\n");
}


void CardReader::removeCard()
{
	delete _insertedCard;
	_insertedCard = nullptr;
	printf("# Card is now removed!\n\n");
}