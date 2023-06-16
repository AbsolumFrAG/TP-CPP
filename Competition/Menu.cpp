#include <iostream>
#include <Windows.h>
#include <limits> 
#include "Menu.h"

using namespace std;

/// <summary>
/// Affiche le menu
/// </summary>
void Menu::Affiche()
{
	SetConsoleOutputCP(CP_UTF8);

	cout << endl;
	cout << ">>>>>>>>>><<<<<<<<<<<" << endl;
	cout << ">>>>>   MENU   <<<<<<" << endl;
	cout << ">>>>>>>>>><<<<<<<<<<<" << endl << endl;
	cout << "1) Inscrire un concurrent" << endl;
	cout << "2) Afficher les inscrits par Nom" << endl;
	cout << "3) Afficher les inscrits par Dossard" << endl;
	cout << "4) Noter un concurrent" << endl;
	cout << "5) Afficher les résultats" << endl << endl;
	cout << "6) Quitter" << endl << endl << endl;
}

/// <summary>
/// Permet à l'utilisateur de choisir un nombre entier compris entre les limites données en paramètres.
/// Utilisé par exemple pour saisir le n° de la rubrique qu'il choisit.
/// </summary>
/// <param name="minNb">La plus petite valeur autorisée, par défaut 1</param>
/// <param name="max">La plus grande valeur autorisée, par défaut 6</param>
/// <returns>Le nombre entier saisi par l'utilisateur</returns>
int Menu::SaisirEntierEntre(int minNb, int maxNb)
{
	// Le nombre saisi par l'utilisateur
	int nbSaisi = 0;

	cout << "--> Saisir un entier entre " << minNb << " et " << maxNb << ": ";
	while (!(cin >> nbSaisi) || nbSaisi < minNb || nbSaisi > maxNb)
	{
		if (cin.fail())	// Erreur, ce n'est pas un entier
		{
			cout << "!! Saisie incorrecte, recommencez : ";
			cin.clear();
			cin.ignore(1024,'\n');
		}
		else
		{
			// Saisie d'un entier, mais hors des limites
			cout << "Le nombre n'est pas entre " << minNb << " et " << maxNb << ", recommencez : ";
		}
	}

	return nbSaisi;
}
