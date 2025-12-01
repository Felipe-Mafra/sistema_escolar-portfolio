#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

#include <string>
#include <vector>

//Forward Declaration
class Coordenador; 
class Turma;

class Disciplina {
protected:
    int _cod;
    std::string _nome;
    int _carga_horaria;
    Coordenador* _coord;
    std::vector<Turma*> _turmas;

public:
    Disciplina(int cod, std::string nome, int carga_horaria, Coordenador* coord)
        : _cod(cod), _nome(nome), _carga_horaria(carga_horaria), _coord(coord) {}

    //getters
    int getCod() const {return this-> _cod;}
    std::string getNome() const {return this-> _nome;}
    int getCarga() const {return this-> _carga_horaria;}

    void adicionarTurma(Turma* turma);

};

#endif