#include <iostream>
using namespace std;

class Equipement
{
    string code;
    string dateAcquisition;
    string etat;
    double prixAchat;

public:
    Equipement(string c, string e, string d, double p)
    {
        code = c;
        etat = e;
        dateAcquisition = d;
        prixAchat = p;
    }

    string getCode()
    {
        return code;
    }
    string getEtat()
    {
        return etat;
    }
    string getDateAcquisition()
    {
        return dateAcquisition;
    }
    double getPrixAchat()
    {
        return prixAchat;
    }

    void setCode(string c)
    {
        code = c;
    }
    void setEtat(string e)
    {
        etat = e;
    }
    void setDateAcquisition(string d)
    {
        dateAcquisition = d;
    }
    void setPrixAchat(double p)
    {
        prixAchat = p;
    }

    void affiche()
    {
        cout << "Code : " << code << endl;
        cout << "État : " << etat << endl;
        cout << "Date d'acquisition : " << dateAcquisition << endl;
        cout << "Prix d'achat : " << prixAchat << " DH" << endl;
    }
};

class Ordinateur : public Equipement
{
    string marque;
    double tailleEcran;
public:
    Ordinateur(string c, string e, string d, double p, string m, double t): Equipement(c, e, d, p)
    {
        marque = m;
        tailleEcran = t;
    }
    void affiche()
    {
        Equipement::affiche();
        cout << "Marque : " << marque << endl;
        cout << "Taille d'écran : " << tailleEcran << " pouces" << endl;
    }
};

class Table : public Equipement
{
    double longueur;
    double largeur;
public:
    Table(string c, string e, string d, double p, double l, double L): Equipement(c, e, d, p)
    {
        longueur = l;
        largeur = L;
    }
    void affiche()
    {
        Equipement::affiche();
        cout << "Longueur : " << longueur << " cm" << endl;
        cout << "Largeur : " << largeur << " cm" << endl;
    }
};

class Imprimante : public Equipement
{
    string marque;
    string numeroSerie;
public:
    Imprimante(string c, string e, string d, double p, string m, string n): Equipement(c, e, d, p)
    {
        marque = m;
        numeroSerie = n;
    }
    void affiche()
    {
        Equipement::affiche();
        cout << "Marque : " << marque << endl;
        cout << "Numéro de série : " << numeroSerie << endl;
    }
};

int main()
{

    Ordinateur o1("ORD1", "Operationnel", "2024-06-01", 4000.0, "HP", 35.6);
    cout << "Informations sur l'ordinateur :\n";
    o1.affiche();
    cout << endl;


    Table t1("TAB1", "Bon état", "2024-08-25", 2200.0, 80.0, 50.0);
    cout << "Informations sur la table :\n";
    t1.affiche();
    cout << endl;


    Imprimante i1("IMP1", "Operationnel", "2024-12-20", 1000.0, "HP", "SN12345");
    cout << "Informations sur l'imprimante :\n";
    i1.affiche();

    return 0;
}
