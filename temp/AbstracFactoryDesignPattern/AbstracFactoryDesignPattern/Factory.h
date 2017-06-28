#pragma once
class GUI
{
public:
	virtual void say() = 0;
	virtual ~GUI(){ ; }
};

class Chicken: public GUI
{
public:
	void say();
	virtual ~Chicken(){ ; }
};


class Sheep : public GUI
{
public:
	void say();
	virtual ~Sheep(){ ; }
};


class Elephant : public GUI
{
public:
	void say();
	virtual ~Elephant(){ ; }
};

class Factory
{
public:
	GUI * createGUI(const char * type);
};

