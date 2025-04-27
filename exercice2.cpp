#include <iostream>
#include <string>
using namespace std;

class Pokemon {
protected:
    string nom;
    double poids;
public:
    Pokemon(string n, double p) : nom(n), poids(p) {}
    virtual double calculerVitesse() = 0;
    virtual string toString() = 0;
};

class PokemonSportif : public Pokemon {
    int nbPattes;
    double taille;
    int freqCardiaque;
public:
    PokemonSportif(string n, double p, int nbP, double t, int f)
        : Pokemon(n, p), nbPattes(nbP), taille(t), freqCardiaque(f) {}

    double calculerVitesse() override {
        return nbPattes * taille * 3;
    }

    string toString() override {
        return nom + " (Sportif) - Poids: " + to_string(poids) + "kg, Pattes: " +
               to_string(nbPattes) + ", Taille: " + to_string(taille) + "m, FC: " +
               to_string(freqCardiaque) + "bpm, Vitesse: " +
               to_string(calculerVitesse()) + "m/s";
    }
};

class PokemonCasanier : public Pokemon {
    int nbPattes;
    double taille;
    int heuresTV;
public:
    PokemonCasanier(string n, double p, int nbP, double t, int h)
        : Pokemon(n, p), nbPattes(nbP), taille(t), heuresTV(h) {}

    double calculerVitesse() override {
        return nbPattes * taille * 3;
    }

    string toString() override {
        return nom + " (Casanier) - Poids: " + to_string(poids) + "kg, Pattes: " +
               to_string(nbPattes) + ", Taille: " + to_string(taille) + "m, TV: " +
               to_string(heuresTV) + "h, Vitesse: " +
               to_string(calculerVitesse()) + "m/s";
    }
};

class PokemonMer : public Pokemon {
    int nbNageoires;
public:
    PokemonMer(string n, double p, int nN)
        : Pokemon(n, p), nbNageoires(nN) {}

    double calculerVitesse() override {
        return poids / 25 * nbNageoires;
    }

    string toString() override {
        return nom + " (Mer) - Poids: " + to_string(poids) + "kg, Nageoires: " +
               to_string(nbNageoires) + ", Vitesse: " +
               to_string(calculerVitesse()) + "m/s";
    }
};

class PokemonCroisiere : public PokemonMer {
public:
    PokemonCroisiere(string n, double p, int nN)
        : PokemonMer(n, p, nN) {}

    double calculerVitesse() override {
        return PokemonMer::calculerVitesse() / 2;
    }

    string toString() override {
        return nom + " (Croisière) - Poids: " + to_string(poids) + "kg, Nageoires: " +
               to_string(nbNageoires) + ", Vitesse: " +
               to_string(calculerVitesse()) + "m/s";
    }
};

int main() {
    PokemonSportif ps("Pikachu", 20.0, 4, 0.5, 150);
    PokemonCasanier pc("Pikachu2", 21.0, 6, 0.3, 5);
    PokemonMer pm("Pikach3", 25.0, 6);
    PokemonCroisiere pcr("Pikachu4", 30.0, 8);

    cout << ps.toString() << endl;
    cout << pc.toString() << endl;
    cout << pm.toString() << endl;
    cout << pcr.toString() << endl;

    return 0;
}
