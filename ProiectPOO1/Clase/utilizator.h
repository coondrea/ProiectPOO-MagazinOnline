#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <iostream>

namespace Online_Store {

class Utilizator {
protected:
    int m_id;
    std::string m_nume_utilizator;
    std::string m_email;

public:
    Utilizator();
    Utilizator(int id, const std::string& nume_utilizator, const std::string& email);
    virtual ~Utilizator();

    // Getteri
    int GetId() const;
    std::string GetNumeUtilizator() const;
    std::string GetEmail() const;

    // Setteri
    void SetEmail(const std::string& email);

    // Metode virtuale pure
    virtual void AfiseazaProfil() const = 0;
    virtual std::string GetTipUtilizator() const = 0;
};

} // namespace
