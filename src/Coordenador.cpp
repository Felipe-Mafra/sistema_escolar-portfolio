#include "Coordenador.hpp"
#include "Professor.hpp"
#include "Aluno.hpp"
#include "Disciplina.hpp"
#include "Turma.hpp"
#include "SistemaEscolar.hpp"
#include <iostream>
#include <string>
#include <vector>


void Coordenador::autenticar() {
    std::cout << "Coordenador " << getNome() << " Logado com sucesso " << std::endl;
}

void Coordenador::sair() {
    std::cout << "Coordenador " << getNome() << " Deslogado do sistema! " << std::endl;
}

void Coordenador::criarDisciplina(SistemaEscolar* sistema) {
    int cod, carga;
    std::string nome;

    std::cout << "--- Nova Disciplina ---" << std::endl;
    std::cout << "Codigo (num): "; std::cin >> cod;
    std::cin.ignore();
    std::cout << "Nome: "; std::getline(std::cin, nome);
    std::cout << "Carga Horaria: "; std::cin >> carga;
    
    // Validação de carga horária
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Erro: Entrada invalida para carga horaria." << std::endl;
        return;
    }
    
    if (carga <= 0) {
        std::cout << "Erro: Carga horaria deve ser positiva." << std::endl;
        return;
    }

    Disciplina* novaDisc = new Disciplina(cod, nome, carga, this);

    sistema->cadastrarDisciplina(novaDisc);
    std::cout << "Disciplina cadastrada com sucesso!" << std::endl;
}

void Coordenador::abrirTurma(SistemaEscolar* sistema) {
    int codTurma, codDisc, idProf;
    std::string nomeTurma;

    std::cout << "--- Abrir Turma ---" << std::endl;
    std::cout << "Codigo da Disciplina base: "; std::cin >> codDisc;
    Disciplina* disc = sistema->buscarDisciplina(codDisc);

    if (!disc) {
        std::cout << "Erro: Disciplina nao encontrada." << std::endl;
        return;
    }

    std::cout << "ID do Professor Responsavel: "; std::cin >> idProf;
    Professor* prof = sistema->buscarProfessor(idProf);

    if (!prof) {
        std::cout << "Erro: Professor nao encontrado." << std::endl;
        return;
    }

    std::cout << "Codigo da Turma: "; std::cin >> codTurma;
    std::cin.ignore();
    std::cout << "Identificacao da Turma (ex: 2024.1): "; std::getline(std::cin, nomeTurma);

    Turma* novaTurma = new Turma(codTurma, nomeTurma, disc, prof);
    
    disc->adicionarTurma(novaTurma);
    
    sistema->cadastrarTurma(novaTurma);
    std::cout << "Turma criada com sucesso!" << std::endl;
}

void Coordenador::matricularAluno(SistemaEscolar* sistema) {
    int idAluno, codTurma;
    std::cout << "--- Matricular Aluno ---" << std::endl;
    std::cout << "ID do Aluno: "; std::cin >> idAluno;
    std::cout << "Codigo da Turma: "; std::cin >> codTurma;

    Aluno* aluno = sistema->buscarAluno(idAluno);
    Turma* turma = sistema->buscarTurma(codTurma);

    if (!aluno) {
        std::cout << "Erro: Aluno nao encontrado." << std::endl;
        return;
    }
    
    if (!turma) {
        std::cout << "Erro: Turma nao encontrada." << std::endl;
        return;
    }
    
    turma->adicionarAluno(aluno);
}