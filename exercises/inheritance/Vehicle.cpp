#include "stdafx.h"
#include "Vehicle.h"
#include <iostream>
#include <string.h>
using namespace std;

void Vehicle::setProducer(const char* producer)
{
	delete[]this->producer;
	this->producer = new char[strlen(producer) + 1];
	assert(this->producer);
	strcpy_s(this->producer, strlen(producer) + 1, producer);
}

const char* Vehicle::getProducer()const
{
	return producer;
}

Vehicle::Vehicle(const char* producer)
{
	this->producer = new char[strlen(producer) + 1];
	assert(this->producer);
	strcpy_s(this->producer, strlen(producer) + 1, producer);
}

void Vehicle::print()const
{
	cout << "Vehicle producer:" << producer << endl;
}

Vehicle::Vehicle()
{
	this->producer = new char[1];
	producer[0] = '\0';
}

Vehicle::~Vehicle()
{
	del();
}

Vehicle::Vehicle(const Vehicle& other)
{
	cpy(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}

void Car::setModel(const char* model)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void Car::setGears(int maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

int Car::getGears()
{
	return maxSpeed;
}

const char* Car::getModel()
{
	return model;
}

void Car::print()const
{
	Vehicle::print();
	cout << "Model:" << model << endl
		<< "Max Speed:" << maxSpeed << endl;
}

Car::Car() :Vehicle()
{
	this->model = new char[1];
	model[0] = '\0';
	this->maxSpeed = 0;
}

Car::Car(const char* model, int maxSpeed, const char* producer) :Vehicle(producer)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
	this->maxSpeed = maxSpeed;
}

Car::~Car()
{
	del();
}

Car::Car(const Car& other) :Vehicle(other)
{
	cpy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		del();
		cpy(other);
	}
	return *this;
}

void Bicycle::setModel(const char* model)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void Bicycle::setNumberOfGears(int numberOfGears)
{
	this->numberOfGears = numberOfGears;
}

int Bicycle::getNumberOfGears()
{
	return numberOfGears;
}

const char* Bicycle::getModel()
{
	return model;
}

void Bicycle::print()const
{
	Vehicle::print();
	cout << "Model:" << model << endl
		<< "Number of Gears:" << numberOfGears << endl;
}

Bicycle::Bicycle() :Vehicle()
{
	this->model = new char[1];
	model[0] = '\0';
}

Bicycle::Bicycle(char* model, int numberOfGears, char* producer) :Vehicle(producer)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
	this->numberOfGears = numberOfGears;
}

Bicycle::~Bicycle()
{
	del();
}

Bicycle::Bicycle(const Bicycle& other) :Vehicle(other)
{
	cpy(other);
}

Bicycle& Bicycle::operator=(const Bicycle& other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		del();
		cpy(other);
	}
	return *this;
}
