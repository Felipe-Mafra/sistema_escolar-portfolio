#include "Professor.hpp"
#include "Aluno.hpp"
#include "Disciplina.hpp"
#include "Turma.hpp"
#include "Avaliacao.hpp"
#include <iostream>

Turma::~Turma() {
    // Libera memória das avaliações
    for (Avaliacao* av : _avaliacoes) {
        delete av;
    }
    _avaliacoes.clear();
}

void Turma::designarProf(Professor* prof) {
    this->_prof = prof;
}

void Turma::adicionarAluno(Aluno* aluno) {
    // Verifica se aluno já está matriculado
    for (Aluno* a : _alunos) {
        if (a->getID() == aluno->getID()) {
            std::cout << "Aluno " << aluno->getNome() << " ja esta matriculado nesta turma." << std::endl;
            return;
        }
    }
    _alunos.push_back(aluno);
    std::cout << "Aluno " << aluno->getNome() << " matriculado com sucesso!" << std::endl;
}

void Turma::adicionarAvaliacao(Avaliacao* avaliacao) {
    _avaliacoes.push_back(avaliacao);
}

bool Turma::alunoEstaNaTurma(int idAluno) const {
    for (Aluno* a : _alunos) {
        if (a->getID() == idAluno) {
            return true;
        }
    }
    return false;
}

float Turma::calcularMediaAluno(int idAluno) const {
    if (!alunoEstaNaTurma(idAluno)) {
        return -1.0f;
    }
    
    if (_avaliacoes.empty()) {
        return -1.0f; // Sem avaliações
    }
    
    float soma = 0.0f;
    int count = 0;
    
    for (Avaliacao* av : _avaliacoes) {
        float nota = av->getNota(idAluno);
        if (nota >= 0) { // -1 significa sem nota
            soma += nota;
            count++;
        }
    }
    
    if (count == 0) {
        return -1.0f; // Nenhuma nota lançada
    }
    
    return soma / count;
}

std::string Turma::obterStatusAprovacao(int idAluno) const {
    float media = calcularMediaAluno(idAluno);
    
    if (media < 0) {
        return "Sem Notas";
    } else if (media >= 7.0f) {
        return "Aprovado";
    } else if (media >= 5.0f) {
        return "Recuperacao";
    } else {
        return "Reprovado";
    }
}