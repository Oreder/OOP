#include <vector>
#include <iostream>
using namespace std;

class Stooge
{
public:
	virtual Stooge * clone() = 0;
	virtual void slap_stick() = 0;
};

//----------------------------------------
class Larry : public Stooge
{
public:
	Stooge * clone() { return new Larry; }
	virtual void slap_stick()
	{
		cout << "Larry: pokes eyes!";
	}
};


class Kane : public Stooge
{
	Stooge * clone() { return new Kane; }
	virtual void slap_stick()
	{
		cout << "Kane: slap head!";
	}
};


class Curly : public Stooge
{
	Stooge * clone() { return new Curly; }
	virtual void slap_stick()
	{
		cout << "Curly: suffer abuse!";
	}
};

//------------------------------------------
class Factory
{
public:
	static Stooge * make_Stooge(int choice);

private:
	static Stooge * s_prototypes[4];
};


Stooge * Factory::s_prototypes[] = { 0, new Larry, new Kane, new Curly };

Stooge * Factory::make_Stooge(int choice)
{
	return s_prototypes[choice]->clone();
}

//------------------------------------------
int main()
{
	vector<Stooge *> roles;
	int choice;

	while (true)
	{
		cout << "Larry (1) - Kane (2) - Curly (3) - Go (0)\n-> ";
		cin >> choice;

		if (choice == 0)
			break;

		roles.push_back(Factory::make_Stooge(choice));
	}

	for (int i = 0; i < roles.size(); i++)
	{
		roles[i]->slap_stick();
		printf("\t\tAt address: %p\n", &roles[i]);
	}

	for (int i = 0; i < roles.size(); i++)
		delete roles[i];

	system("pause");
	return 0;
}