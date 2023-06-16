#pragma once

/// <summary>
/// La classe modélisant le menu de l'application de gestion de la compétition
/// </summary>
class Menu
{
public:
	/// <summary>
	/// Affiche le menu
	/// </summary>
	void Affiche();

	/// <summary>
	/// Permet à l'utilisateur de choisir un nombre entier compris entre les limites données en paramètres.
	/// Utilisé par exemple pour saisir le n° de la rubrique qu'il choisit.
	/// </summary>
	/// <param name="minNb">La plus petite valeur autorisée, par défaut 1</param>
	/// <param name="max">La plus grande valeur autorisée, par défaut 6</param>
	/// <returns>Le nombre entier saisi par l'utilisateur</returns>
	int SaisirEntierEntre(int minNb = 1, int max = 6);
};

