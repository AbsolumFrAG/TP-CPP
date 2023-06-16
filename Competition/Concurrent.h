#pragma once
#include <string>

/// <summary>
/// La classe modélksant un concurrent de la compétition
/// </summary>
class Concurrent
{
private:
	/// <summary>
	/// Le nom du concurrent
	/// </summary>
	std::string nom;

	/// <summary>
	/// Le n° de dossard du concurrent
	/// </summary>
	int dossard;

	/// <summary>
	/// Le score (la note) obtenue par le concurrent
	/// </summary>
	int score = 0;

public:
	/// <summary>
	/// Contructeur
	/// </summary>
	/// <param name="nom">Le nom à affecter au concurrent</param>
	/// <param name="dossard">Le numéro de dossard à affecter au concurrent</param>
	Concurrent(std::string nom, int dossard);

	/// <summary>
	/// Destructeur
	/// </summary>
	virtual ~Concurrent();

	/// <summary>
	/// Accesseurs en lecture pour le nom du concurrent
	/// </summary>
	/// <returns>Le nom du concurrent</returns>
	std::string GetNom() { return this->nom; }
	std::string GetNom() const { return this->nom; }

	/// <summary>
	/// Accesseurs en lecture pour le n° de dossard du concurrent
	/// </summary>
	/// <returns>Le n° de dossard du concurrent</returns>
	int GetDossard() { return this->dossard; }
	int GetDossard() const { return this->dossard; }

	/// <summary>
	/// Accesseurs en lecture pour le score du concurrent
	/// </summary>
	/// <returns>Le score du concurrent</returns>
	int GetScore() { return this->score; }
	int GetScore() const { return this->score; }

	/// <summary>
	/// Accesseurs en écriture pour affecter le score du concurrent
	/// </summary>
	/// <param name="score">Le score à affecter au concurrent</param>
	void SetScore(const int score) { this->score = score; }
};

