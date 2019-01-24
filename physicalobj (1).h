#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class physical 
{
public:
	double x, y;
	physical()	{}
	physical(double a, double b)	{x=a; y=b;}
	~physical()	{}
	virtual char checkobj () {return 'b';}
};

class powerplant : public physical
{
public:
	double consumptionRate;	//to get from smart meter	//changing
	double maxProduction;	//fixed
	double productionRate;	//changing

	char checkobj () {return 'p';}

	powerplant () {};
	powerplant (physical pos, double pro) : physical(pos), maxProduction(pro) {}

	void upgradation (double production)
	{
		maxProduction=production;
	}

	void supplypower(int con)
	{
		while (maxProduction<12);
	}
};

class renewable : public powerplant
{
public:

	renewable () {};
	renewable (physical pos, double pro) : powerplant(pos,pro) {}
};

class consumers : public physical
{
public:
	double consumptionRate;	//to get from smart meter	//changing\\

	consumers () {};
	consumers (physical pos) : physical(pos) {}
	double get_consumptionrate ()
	{
		//reading from file
		consumptionRate=200;
		return consumptionRate;
	}

	char checkobj () {return 'c';}
};