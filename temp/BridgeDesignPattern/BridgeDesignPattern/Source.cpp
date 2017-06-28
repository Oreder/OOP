#include <iostream>
//using namespace std;
#include <string>


class AbstractInterface
{
public:
	virtual void someFunctionality() = 0;
};


class ImplementationInterface
{
public:
	virtual void anotherFunctionality() = 0;
};


class Bridge : public AbstractInterface
{
protected:
	ImplementationInterface * implementation;

public:
	Bridge(ImplementationInterface * backend) : implementation(backend){}
};


class Usage_1 : public Bridge
{
public:
	Usage_1(ImplementationInterface * backend) : Bridge(backend){}

	void someFunctionality()
	{
		std::cout << "Usage_1 on:";
		implementation->anotherFunctionality();
	}
};


class Usage_2 : public Bridge
{
public:
	Usage_2(ImplementationInterface * backend) : Bridge(backend){}

	void someFunctionality()
	{
		std::cout << "Usage_2 on:";
		implementation->anotherFunctionality();
	}
};


class Window : public ImplementationInterface
{
public:
	void anotherFunctionality()
	{
		std::cout << "\t# Windows\n";
	}
};


class Linux : public ImplementationInterface
{
public:
	void anotherFunctionality()
	{
		std::cout << "\t# Linux\n";
	}
};



int main()
{
	AbstractInterface * useCase = nullptr;

	ImplementationInterface *osWindows = new Window;
	ImplementationInterface *osLinux = new Linux;

	// First case
	useCase = new Usage_1(osWindows);
	useCase->someFunctionality();

	useCase = new Usage_1(osLinux);
	useCase->someFunctionality();

	// Second case
	useCase = new Usage_2(osWindows);
	useCase->someFunctionality();

	useCase = new Usage_2(osLinux);
	useCase->someFunctionality();

	delete osWindows;
	delete osLinux;
	delete useCase;

	system("pause");
	return 0;
}