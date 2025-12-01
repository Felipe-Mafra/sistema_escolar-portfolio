#ifndef SISTEMA_ESCOLAR_HPP
#define SISTEMA_ESCOLAR_HPP

#include <vector>
#include <map>
#include <string>

//Forward Declaration
class Aluno;
class Professor;
class Coordenador;
class Disciplina;
class Turma;
class Usuario;

class SistemaEscolar {
private:
    std::map<int, Aluno*> _alunos;
    std::map<int, Professor*> _professores;
    std::map<int, Coordenador*> _coordenadores;
    
    std::map<int, Disciplina*> _disciplinas;
    std::map<int, Turma*> _turmas;

    Usuario* _usuarioLogado;

public:
    SistemaEscolar();
    ~SistemaEscolar(); 

    //Cadastros
    void cadastrarAluno(Aluno* aluno);
    void cadastrarProfessor(Professor* prof);
    void cadastrarCoordenador(Coordenador* coord);
    void cadastrarDisciplina(Disciplina* disc);
    void cadastrarTurma(Turma* turma);

    //Buscas
    Aluno* buscarAluno(int id);
    Professor* buscarProfessor(int id);
    Coordenador* buscarCoordenador(int id);
    Disciplina* buscarDisciplina(int cod);
    Turma* buscarTurma(int cod);
    
    std::vector<Turma*> getTodasTurmas() const;

    //Login
    Usuario* getUsuarioLogado();
    void deslogar();
    
    //Persistencia
    void salvarDados();
    void carregarDados();
};

#endif