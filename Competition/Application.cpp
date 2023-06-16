#include <iostream>
#include <Windows.h>
#include "Application.h"
#include "Concurrent.h"

using namespace std;

/// <summary>
/// Retourne un nombre entier g�n�r� au hasard, n,
/// avec deb <= n < fin
/// </summary>
/// <param name="deb"> la valeur minimale de n</param>
/// <param name="fin"> la valeur � laquelle n doit �tre < </param>
/// <returns> n avec deb <= n < fin </returns>
int hasard(int deb, int fin)
{
	int val;
	val = (rand() % fin) + deb;
	return val;
}


/// <summary>
/// Initialiser la comp�tition.
/// Consiste � saisir le nombre de dossards n�cessaires (= nombre de concurrents)
/// puis � les cr�er dans le conteneur dossardsPourAffectation.
/// Entre 2 et 100 dossards.
/// </summary>
void Application::InitialiserCompetition()
{
	cout << "Saisir le nombre de dossards n�cessaires (entre 2 et 100) : " << endl;
	int nombreDossards;
	cin >> nombreDossards;

	if (nombreDossards < 2 || nombreDossards > 100) {
		cout << "Nombre de dossards invalide !" << endl;
		return;
	}

	for (int i = 1; i <= nombreDossards; i++) {
		dossardsPourAffectation.push_back(i);
	}

	cout << "Comp�tition initialis�e avec " << nombreDossards << " dossards." << endl;
}


/// <summary>
/// Inscrire un concurent.
/// Apr�s v�rification qu'il reste un dossard disponible, il faut:
/// - saisir le nom du concurrent
/// - retirer 1 dossard au hasard dans le conteneur dossardsPourAffectation
/// - cr�er le concurrent avec son nom et le dossard
/// - ajouter le concurrent au conteneur concurentsInscrits
/// Pas d'inscription possible s'il ne reste plus de dossard disponible.
/// </summary>
void Application::InscrireUnConcurrent()
{
	if (dossardsPourAffectation.empty()) {
		cout << "Il n'y a plus de dossard disponible !" << endl;
		return;
	}

	string nom;
	cout << "Saisir le nom du concurrent : ";
	cin >> nom;

	int index = hasard(0, dossardsPourAffectation.size());
	int dossard = dossardsPourAffectation[index];
	dossardsPourAffectation.erase(dossardsPourAffectation.begin() + index);
	
	Concurrent concurrent(nom, dossard);
	concurrentsInscrits.push_back(concurrent);

	cout << "Concurrent inscrit : " << nom << " avec le num�ro de dossard : " << dossard << endl;
	cout << "Nombre de dossards disponibles : " << dossardsPourAffectation.size() << endl;
}

/// <summary>
/// Affiche la liste des concurrents inscrits, par ordre alphab�tique des noms
/// </summary>
void Application::AfficherParNom()
{
	concurrentsInscrits.sort([](const Concurrent& a, const Concurrent& b) {
		return a.GetNom() < b.GetNom();
	});

	cout << "Liste des concurrents inscrits par ordre alphab�tique des noms : " << endl;
	for (const Concurrent& concurrent : concurrentsInscrits) {
		cout << "Nom : " << concurrent.GetNom() << ", Dossard : " << concurrent.GetDossard() << endl;
	}
}

/// <summary>
/// Affiche la liste des concurrents inscrits, par ordre croissant des dossards
/// </summary>
void Application::AfficherParDossard()
{
	concurrentsInscrits.sort([](const Concurrent& a, const Concurrent& b)
		{
			return a.GetDossard() < b.GetDossard();
		});

	cout << "Liste des concurrents inscrits par ordre de dossards : " << endl;
	for (const Concurrent& concurrent : concurrentsInscrits)
	{
		cout << "Dossard : " << concurrent.GetDossard() << ", Nom : " << concurrent.GetNom() << endl;
	}
}

/// <summary>
/// Permet de noter (scorer) tous les concurrents.
/// - extrait et supprime le premier concurrent du conteneur concurentsInscrits
/// - lui affecte un score entre 0 et 10 inclus
/// - ins�re le concurrent not� dans le conteneur resultats, les mieux not�s rang�s en premier
/// Le score doit servir de cl� pour retrouver tous les concurrents ayant un certain score.
/// Attention!! On peut avoir plusieurs concurrents avec le m�me score.
/// </summary>
void Application::NoterConcurrents()
{
	if (concurrentsInscrits.empty()) {
		cout << "Aucun concurrent inscrit !" << endl;
		return;
	}

	Concurrent concurrent = concurrentsInscrits.front();
	concurrentsInscrits.pop_front();

	int score = hasard(0, 11);
	concurrent.SetScore(score);

	resultats.insert(make_pair(score, concurrent));

	cout << "Concurrent not� - Score : " << score << ", Dossard : " << concurrent.GetDossard()
		<< ", Nom : " << concurrent.GetNom() << endl;
}

/// <summary>
/// Affiche le score, le dossard et le nom des concurrents not�s.
/// </summary>
void Application::AfficherResultats()
{
	//@TODO � compl�ter.
}

/// <summary>
/// Boucle d'ex�cution du programme.
/// </summary>
void Application::Run()
{
	bool quit = false;
	int choix = 0;

	do
	{
		//  Affiche le menu et lit le choix de l'utilisateur
		menu.Affiche();
		choix = menu.SaisirEntierEntre(1, 6);

		switch(choix)	//  R�alise l'action choisie par l'utilisateur
		{
		case 1:
			InscrireUnConcurrent();
			break;
		case 2:
			AfficherParNom();
			break;
		case 3:
			AfficherParDossard();
			break;
		case 4:
			NoterConcurrents();
			break;
		case 5:
			AfficherResultats();
			break;
		case 6:
			quit = true;
			break;
		}
	} while (!quit);
}
