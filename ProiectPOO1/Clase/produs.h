#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>

namespace Online_Store {

class Produs {
protected:
    int m_id;
    std::string m_nume;
    std::string m_categorie;
    double m_pret;
    int m_stoc;

    void _ValidarePret(double pret);
    void _ValidareStoc(int stoc);

public:
    Produs();
    Produs(int id, const std::string& nume, const std::string& categorie, double pret, int stoc);
    virtual ~Produs();

    // Getteri
    int GetId() const;
    std::string GetNume() const;
    std::string GetCategorie() const;
    double GetPret() const;
    int GetStoc() const;

    // Setteri
    void SetNume(const std::string& nume);
    void SetCategorie(const std::string& categorie);
    void SetPret(double pret);
    void SetStoc(int stoc);

    // Functionalitati
    void ScadeStoc(int cantitate);
    void MaresteStoc(int cantitate);
    virtual void AfiseazaDetalii() const;
    virtual std::string GetDescriereDetaliata() const;

    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Produs& produs);

    // Operator ==
    bool operator==(const Produs& other) const;
};

} // namespace Online_Store

#endif
