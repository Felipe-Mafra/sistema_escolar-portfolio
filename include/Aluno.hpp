#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"

class SistemaEscolar;

class Aluno : public Usuario {
private:
    int _num_matricula;
public:
    Aluno(int id, std::string nome, int num_matricula)
        : Usuario(id, nome), _num_matricula(num_matricula) {}

    int getNumMatricula() const {return this->_num_matricula;}
    
    void autenticar() override;
    void sair() override;

    void verNotas(SistemaEscolar* sistema);
    void verHistoricoCompleto(SistemaEscolar* sistema);
    float calcularMediaGeral(SistemaEscolar* sistema);
};

#endif