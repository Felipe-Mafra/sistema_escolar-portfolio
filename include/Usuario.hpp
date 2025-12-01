#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

//Classe genérica para os Usuários do Sistema

class Usuario {
private:
    int _id;
    std::string _nome;

public:
    Usuario(int id, std::string nome) : _id(id), _nome(nome) {}

    //getters
    int getID() const { return this->_id; }
    std::string getNome() const { return this->_nome; }

    virtual void autenticar() = 0;
    virtual void sair() = 0;

    virtual ~Usuario() {}
};


#endif