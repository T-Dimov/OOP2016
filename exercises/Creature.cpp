// Creature.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Creature
{
public:
	Creature()
	{
		name = nullptr;
		age = 0;
		HP = 0;
	}

	Creature(const char *cName, size_t cAge, size_t cHP)
	{
		name = new char[strlen(cName) + 1];
		strcpy(name, cName);
		age = cAge;
		HP = cHP;
	}

	virtual ~Creature()
	{
		delete[] name;
	}

	size_t getHP() const
	{
		return HP;
	}

	virtual double getAbility() const = 0;

protected:
	char *name;
	size_t age, HP;
};

class Muggle: public Creature
{
public:
	Muggle(): Creature()
	{
		inteligence = 0;
	}

	Muggle(const char *mName, size_t mAge, size_t mHP, size_t mInteligence): Creature(mName, mAge, mHP)
	{
		inteligence = mInteligence;
	}

	double getAbility() const
	{
		return 0.1*(inteligence + HP);
	}

private:
	size_t inteligence;
};

class Wizard: public Creature
{
public:
	Wizard(): Creature()
	{
		house = nullptr;
		power = 0;
	}

	Wizard(const char *wName, size_t wAge, size_t wHP, const char *wHouse, size_t wPower): Creature(wName, wAge, wHP)
	{
		house = new char[strlen(wHouse) + 1];
		strcpy(house, wHouse);
		power = wPower;
	}

	~Wizard()
	{
		delete[] house;
	}

	double getAbility() const
	{
		return power + HP;
	}

private:
	char *house;
	double power;
};

struct Spell
{
	Spell()
	{
		name = nullptr;
		damage = 0;
	}

	Spell(const char *sName, double sDamage)
	{
		name = new char[strlen(sName) + 1];
		strcpy(name, sName);
		damage = sDamage;
	}

	~Spell()
	{
		delete[] name;
	}

	char *name;
	double damage;
};

size_t stillAlive(Creature const * const * const creatures, size_t size, const Spell& spell)
{
	size_t count = 0;
	for(size_t i = 0; i < size; i++)
	{
		if (spell.damage < creatures[i]->getHP())
			++count;
	}
	return count;
}

size_t wantThemDead(Creature const * const * const creatures, size_t size, const Spell& spell)
{
	size_t maxHP = 0;
	for(size_t i = 0; i < size; i++)
	{
		if(creatures[i]->getHP() > maxHP)
			maxHP = creatures[i]->getHP();
	}
	return ceil(maxHP / spell.damage);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Muggle a("emo",20,3,4);
	Wizard b("ome",20,300,"kon",9001);
	Creature  *arr[2];
	arr[0] = &a;
	arr[1] = &b;
	Spell c("avada kedavra", 101);
	cout << stillAlive(arr,2,c) << endl << wantThemDead(arr,2,c) << endl;
	cin.get();
	return 0;
}

