#include "Concurrent.h"
#include <iostream>

using namespace std;

Concurrent::Concurrent(string nom, int dossard)
{
//	cout << "--> Concurrent(nom) de " << this << endl;
	this->nom = nom;
	this->dossard = dossard;
}

Concurrent::~Concurrent()
{
//	cout << "--> ~Concurrent() de " << this << endl;
}
