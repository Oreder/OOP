#pragma once

class chicken
{
private:
	static chicken * getChicken;
	chicken();
	~chicken();

public:
	static chicken * requestGetChicken();
};

