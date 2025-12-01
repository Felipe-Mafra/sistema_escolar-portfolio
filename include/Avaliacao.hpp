#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include <string>
#include <map>

//Forward Declaration
class Turma;
class Aluno;

class Avaliacao {
private:
    int _cod;
    std::string _titulo;
    Turma* _turma;
    std::map<int, float> _notas;

public:
    Avaliacao(int cod, std::string titulo, Turma* turma)
        : _cod(cod), _titulo(titulo), _turma(turma) {}

    //getters
    int getCod() const {return this->_cod;}
    std::string getTitulo() const {return this->_titulo;}
    Turma* getTurma() const { return this->_turma; }

    void setNota(int idAluno, float nota);

    float getNota(int idAluno) const;
};

#endif