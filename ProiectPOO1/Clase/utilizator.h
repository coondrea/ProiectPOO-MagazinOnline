#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <iostream>

namespace Online_Store {

// Clasa de baza abstracta pentru toti utilizatorii magazinului
class Utilizator {
protected:
    int m_id;                          // ID unic al utilizatorului
    std::string m_nume_utilizator;    // Numele de utilizator
    std::string m_email;              // Adresa de email

public:
    Utilizator(); 
    Utilizator(int id, const std::string& nume_utilizator, const std::string& email); 
    virtual ~Utilizator(); 

    
    int GetId() const;
    std::string GetNumeUtilizator() const;
    std::string GetEmail() const;

   
    void SetEmail(const std::string& email);

    // Metode virtuale pure ce trebuie implementate de clasele derivate
    virtual void AfiseazaProfil() const = 0;
    virtual std::string GetTipUtilizator() const = 0;
};

} // namespace Online_Store

#endif

