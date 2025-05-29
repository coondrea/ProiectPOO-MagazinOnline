#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>

namespace Online_Store {

// Clasa de baza pentru produse in magazin
class Produs {
protected:
    int m_id;                       // ID unic al produsului
    std::string m_nume;             // Numele produsului
    std::string m_categorie;        // Categoria din care face parte produsul
    double m_pret;                  // Pretul produsului
    int m_stoc;                     // Cantitatea in stoc

    // Metode private pentru validarea pretului si stocului
    void _ValidarePret(double pret);
    void _ValidareStoc(int stoc);

public:
    Produs(); 
    Produs(int id, const std::string& nume, const std::string& categorie, double pret, int stoc); 
    virtual ~Produs(); 

    
    int GetId() const;
    std::string GetNume() const;
    std::string GetCategorie() const;
    double GetPret() const;
    int GetStoc() const;

    
    void SetNume(const std::string& nume);
    void SetCategorie(const std::string& categorie);
    void SetPret(double pret);
    void SetStoc(int stoc);

    
    void ScadeStoc(int cantitate);         // scade o cantitate din stoc
    void MaresteStoc(int cantitate);       // mareste stocul
    virtual void AfiseazaDetalii() const;  // afiseaza informatii despre produs
    virtual std::string GetDescriereDetaliata() const; // descriere detaliata (polimorfism)

    // Supraincarcare operator de afisare pentru Produs
    friend std::ostream& operator<<(std::ostream& os, const Produs& produs);

    // Supraincarcare operator egal pentru compararea a doua produse dupa ID
    bool operator==(const Produs& other) const;
};

} // namespace Online_Store

#endif

