#ifndef COORDENADOR_HPP
#define COORDENADOR_HPP

#include "Usuario.hpp"

class SistemaEscolar;

class Coordenador : public Usuario {
public:
    Coordenador(int id, std::string nome)
        : Usuario(id, nome) {}

    void autenticar() override;
    void sair() override;

    void criarDisciplina(SistemaEscolar* sistema);
    void abrirTurma(SistemaEscolar* sistema);
    void matricularAluno(SistemaEscolar* sistema);
};

#endif