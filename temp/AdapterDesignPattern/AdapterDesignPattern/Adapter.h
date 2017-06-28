#pragma once

class Card
{
public:
	virtual void readCard() = 0;
	virtual ~Card(){ ; }
};

class SD : public Card
{
public:
	void readCard();
	//~SD();
};

class MemoryStick : public Card
{
public:
	void readCard();
	//~MemoryStick();
};


class CardReader
{
public:
	enum CardType
	{
		eSD,
		eMemoryStick,
		eQtyCardType
	};

	CardReader();
	~CardReader();

	void insertCard(unsigned char type);

	void readCard();

	void removeCard();

private:
	Card * _insertedCard;
};

