#ifndef TURMA_HPP
#define TURMA_HPP

#include <string>
#include <vector>

//Forward Declaration
class Professor;
class Aluno;
class Disciplina;
class Avaliacao;

class Turma {
private:
    int _cod;
    std::string _nome;
    Disciplina* _disc;
    Professor* _prof;
    std::vector<Aluno*> _alunos;
    std::vector<Avaliacao*> _avaliacoes;

public:
    Turma(int cod, std::string nome, Disciplina* disc, Professor* prof)
        : _cod(cod), _nome(nome), _disc(disc), _prof(prof) {}
    
    ~Turma();

    //getters
    int getCod() const {return this->_cod;}
    std::string getNome() const {return this->_nome;}
    std::vector<Avaliacao*> getAvaliacoes() const {return this->_avaliacoes;}
    Disciplina* getDisciplina() const {return this->_disc;}


    void designarProf(Professor* prof);
    void adicionarAluno(Aluno* aluno);
    void adicionarAvaliacao(Avaliacao* avaliacao);
    bool alunoEstaNaTurma(int idAluno) const;
    
    float calcularMediaAluno(int idAluno) const;
    std::string obterStatusAprovacao(int idAluno) const;
};

#endif