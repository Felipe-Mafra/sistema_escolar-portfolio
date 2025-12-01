#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <string>
#include "Usuario.hpp"

class SistemaEscolar;

class Professor : public Usuario {
private:
    std::string _departamento;
public:
    Professor(int id, std::string nome, std::string departamento)
        : Usuario(id, nome), _departamento(departamento) {}

    std::string getDepartamento() const {return this->_departamento;}

    void autenticar() override;
    void sair() override;

    void criarAvaliacao(SistemaEscolar* sistema);
    void atribuirNota(SistemaEscolar* sistema);
};

#endif