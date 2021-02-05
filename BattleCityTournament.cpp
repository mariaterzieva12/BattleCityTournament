#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Card
{
public:
	Card();
	Card(const char* _name, int _attack, int _defence, bool _isMonster);
	Card(const Card& other);
	Card& operator=(const Card& other);
	int getAttack();
	int getDefence();
	char getName();
	void setName(char name);
	void setAttack(int attack);
	void setDefence(int defence);
	bool getType();

private:
	char name[25];
	int attack;
	int defence;
	bool isMonster;
	void copyFrom(const Card& other);
};

class Deck
{
public:
	Deck();
	void changeCard(int index, const Card& card);
	int numberOfMonsters();
	int numberOfSpellCards();

	Deck& operator=(const Deck& other);

private:
	Card deck[40];
};

class Duelist
{
public:
	Duelist();
	~Duelist();

	void setName(const char*);
	char* getName()
	{
		return name;
	}

private:
	char* name;
	Deck deck;
};


Card::Card()
{
	strcpy_s(name, 25, "token");
	isMonster = true;
	attack = 0;
	defence = 0;
}

Card::Card(const char* _name, int _attack, int _defence, bool _isMonster)
{
	if (strlen(_name) > 25)
	{
		cout << "Buffer overflow " << endl;
	}
	strcpy_s(name, 25, _name);

	isMonster = _isMonster;

	if (isMonster)
	{
		attack = _attack;
		defence = _defence;
	}
}


Card::Card(const Card& other)
{
	copyFrom(other);
}

Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		copyFrom(other);
	}
	return *this;
}
char Card::getName()
{
	return name[25];
}

int Card::getAttack()
{
	return attack;
}

int Card::getDefence()
{
	return defence;
}

void Card::setAttack(int attack)
{
	if (attack < 0 && attack > 5000)
	{
		cout << "Error" << endl;
	}
}
void Card::setDefence(int defence)
{
	if (defence < 0 && defence > 5000)
	{
		cout << "Error" << endl;
	}
}
void Card::setName(char name)
{
	if (name < 0 && name > 25)
	{
		cout << " Invalid name  " << endl;
	}
}


bool Card::getType()
{
	return isMonster;
}

void Card::copyFrom(const Card& other)
{
	if (strlen(other.name) > 25)
	{
		cout << "Buffer overflow " << endl;
	}
	strcpy_s(name, 25, other.name);

	isMonster = other.isMonster;

	if (isMonster)
	{
		attack = other.attack;
		defence = other.defence;
	}
}

Deck::Deck()
{
	Card defaultCard;
	for (int i = 0; i < 40; ++i)
	{
		deck[i] = defaultCard;
	}
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 40; i++)
		{
			deck[i] = other.deck[i];
		}
	}
	return *this;
}

int Deck::numberOfMonsters()
{
	int count = 0;
	for (size_t i = 0; i < 40; i++)
	{
		if (deck[i].getType())
		{
			++count;
		}
	}
	return count;
}

int Deck::numberOfSpellCards()
{
	return 40 - numberOfMonsters();
}

void Deck::changeCard(int index, const Card& card)
{
	deck[index] = card;
}

void Duelist::setName(const char* _name)
{
	if (!_name)
	{
		name = new char[1];
		strcpy_s(name, 1, "");
		return;
	}

	size_t len = strlen(_name) + 1;
	name = new char[len];
	strcpy_s(name, len, _name);
}
Duelist::Duelist()
{
	setName(" ");
	Deck defaultDeck;
	deck = defaultDeck;
}

Duelist::~Duelist()
{
	delete[] name;
}

int main()
{
	Deck d1;
	Duelist dan;
	dan.setName("Pe6o");
	cout << dan.getName();
	cout << endl;

	system("pause");
}