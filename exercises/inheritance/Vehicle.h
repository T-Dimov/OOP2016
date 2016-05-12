#ifndef VEH_H
#define VEH_H

#include <assert.h>

#include <iostream>
using namespace std;

class Vehicle {
private:
	char* producer;
	void cpy(const Vehicle& a)
	{
		this->producer = new char[strlen(a.producer) + 1];
		assert(this->producer);
		strcpy_s(this->producer, strlen(a.producer) + 1, a.producer);
	}
	void del()
	{
		delete[]producer;
	}
public:
	void setProducer(const char*);
	const char* getProducer()const;
	virtual void print()const;

	Vehicle();
	Vehicle(const char*);
	~Vehicle();
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
};

class Car : public Vehicle {
private:
	char* model;
	int maxSpeed;
	void cpy(const Car& other)
	{
		this->maxSpeed = other.maxSpeed;
		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}
	void del()
	{
		delete[]model;
	}
public:
	void setModel(const char*);
	void setGears(int);
	int getGears();
	const char* getModel();
	virtual void print()const;

	Car();
	Car(const char*, int, const char*);
	~Car();
	Car(const Car&);
	Car& operator=(const Car&);
};

class Bicycle : public Vehicle {
private:
	char* model;
	int numberOfGears;
	void cpy(const Bicycle& other)
	{
		this->numberOfGears = other.numberOfGears;
		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}

	void del()
	{
		delete[]model;
	}
public:
	void setModel(const char*);
	void setNumberOfGears(int);
	int getNumberOfGears();
	const char* getModel();
	virtual void print()const;

	Bicycle();
	Bicycle(char*, int, char*);
	~Bicycle();
	Bicycle(const Bicycle&);
	Bicycle& operator=(const Bicycle&);
};

#endif
