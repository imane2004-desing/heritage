#include <iostream>
#include <string>

using namespace std;

class Pokemon
{
protected:
    string nom;
    double poids;
public:
    Pokemon(string n, double p) : nom(n), poids(p) {}

    virtual double calculerVitesse() = 0;
    virtual string toString() = 0;
};

class PokemonSportif : public Pokemon
{
protected:
    int nbPattes;
    double taille;
    int freqCardiaque;
public:
    PokemonSportif(string n, double p, int nbP, double t, int f)
        : Pokemon(n, p), nbPattes(nbP), taille(t), freqCardiaque(f) {}

    double calculerVitesse() override
    {
        return nbPattes * taille * 3;
    }

    string toString() override
    {
        return "Nom: " + nom + ", Poids: " + to_string(poids) + " kg, Pattes: " + to_string(nbPattes) +", Taille: " + to_string(taille) + " m, Fréquence Cardiaque: " + to_string(freqCardiaque) + " bpm, Vitesse: " + to_string(calculerVitesse()) + " m/s (Sportif)";
    }
};

class PokemonCasaniers : public Pokemon
{
protected:
    int nbPattes;
    double taille;
    int heuresTV;
public:
    PokemonCasaniers(string n, double p, int nbP, double t, int h)
        : Pokemon(n, p), nbPattes(nbP), taille(t), heuresTV(h) {}

    double calculerVitesse() override
    {
        return nbPattes * taille * 3;
    }

    string toString() override
    {
        return "Nom: " + nom + ", Poids: " + to_string(poids) + " kg, Pattes: " + to_string(nbPattes) +", Taille: " + to_string(taille) + " m, Heures TV: " + to_string(heuresTV) + " h, Vitesse: " + to_string(calculerVitesse()) + " m/s (Casaniers)";
    }
};

class PokemonMer : public Pokemon
{
protected:
    int nbNageoires;
public:
    PokemonMer(string n, double p, int nN)
        : Pokemon(n, p), nbNageoires(nN) {}

    double calculerVitesse() override
    {
        return poids / 25 * nbNageoires;
    }

    string toString() override
    {
        return "Nom: " + nom + ", Poids: " + to_string(poids) + " kg, Nageoires: " + to_string(nbNageoires) + ", Vitesse: " + to_string(calculerVitesse()) + " m/s (Mer)";
    }
};

class PokemonCroisiere : public Pokemon
{
protected:
    int nbNageoires;
public:
    PokemonCroisiere(string n, double p, int nN)
        : Pokemon(n, p), nbNageoires(nN) {}

    double calculerVitesse() override
    {
        return (poids / 25 * nbNageoires) / 2;
    }

    string toString() override
    {
        return "Nom: " + nom + ", Poids: " + to_string(poids) + " kg, Nageoires: " + to_string(nbNageoires) +", Vitesse: " + to_string(calculerVitesse()) + " m/s (Croisière)";
    }
};

int main()
{
    PokemonSportif pokemonSportif("Pikachu", 20.0, 4, 0.5, 150);
    PokemonCasaniers pokemonCasaniers("Pikachu2", 21.0, 4, 0.3, 5);
    PokemonMer pokemonMer("Pikachu3", 25.0, 6);
    PokemonCroisiere pokemonCroisiere("Pikachu4", 30.0, 8);

    cout << pokemonSportif.toString() << endl;
    cout << pokemonCasaniers.toString() << endl;
    cout << pokemonMer.toString() << endl;
    cout << pokemonCroisiere.toString() << endl;

    return 0;
}
