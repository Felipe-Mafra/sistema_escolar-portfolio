#include "Aluno.hpp"
#include "Turma.hpp"
#include "Avaliacao.hpp"
#include "Disciplina.hpp"
#include "SistemaEscolar.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


void Aluno::autenticar() {
	std::cout << "Aluno " << getNome() << " Logado com sucesso via Matricula: " << _num_matricula << std::endl;
}

void Aluno::sair() {
	std::cout << "Aluno " << getNome() << " Deslogado do sistema! " << std::endl;
}

void Aluno::verNotas(SistemaEscolar* sistema) {
    std::cout << "=== Boletim de " << getNome() << " ===" << std::endl;

    std::vector<Turma*> todasTurmas = sistema->getTodasTurmas();

    for (Turma* turma : todasTurmas) {
        std::vector<Avaliacao*> avaliacoes = turma->getAvaliacoes();
        
        if (avaliacoes.empty()) continue;

        std::cout << "Disciplina: " << turma->getNome() << std::endl;
        
        for (Avaliacao* av : avaliacoes) {
            float nota = av->getNota(this->getID());
            
            if (nota >= 0) { // -1 = sem nota
                std::cout << "   - " << av->getTitulo() << ": " << std::fixed << std::setprecision(1) << nota << std::endl;
            } else {
                 std::cout << "   - " << av->getTitulo() << ": (Pendente)" << std::endl;
            }
        }
    }
    std::cout << "========================" << std::endl;
}

void Aluno::verHistoricoCompleto(SistemaEscolar* sistema) {
    std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        HISTÓRICO ACADÊMICO COMPLETO                       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << "Aluno: " << getNome() << " | Matrícula: " << _num_matricula << std::endl;
    std::cout << "────────────────────────────────────────────────────────────" << std::endl;

    std::vector<Turma*> todasTurmas = sistema->getTodasTurmas();
    
    bool temDisciplinas = false;
    int totalDisciplinas = 0;
    int aprovadas = 0;
    int recuperacao = 0;
    int reprovadas = 0;
    
    for (Turma* turma : todasTurmas) {
        if (!turma->alunoEstaNaTurma(this->getID())) {
            continue;
        }
        
        temDisciplinas = true;
        totalDisciplinas++;
        
        std::vector<Avaliacao*> avaliacoes = turma->getAvaliacoes();
        
        std::cout << "\n📚 DISCIPLINA: " << turma->getDisciplina()->getNome() << std::endl;
        std::cout << "   Turma: " << turma->getNome() << std::endl;
        std::cout << "   ──────────────────────────────────────" << std::endl;
        
        if (avaliacoes.empty()) {
            std::cout << "   Sem avaliações cadastradas" << std::endl;
            continue;
        }
        
        // Mostra todas as notas
        bool temNotas = false;
        for (Avaliacao* av : avaliacoes) {
            float nota = av->getNota(this->getID());
            if (nota >= 0) {
                std::cout << "   ✓ " << std::left << std::setw(25) << av->getTitulo() 
                          << " " << std::fixed << std::setprecision(1) << nota << std::endl;
                temNotas = true;
            } else {
                std::cout << "   ○ " << std::left << std::setw(25) << av->getTitulo() 
                          << " (Pendente)" << std::endl;
            }
        }
        
        // Calcula e mostra média
        if (temNotas) {
            float media = turma->calcularMediaAluno(this->getID());
            std::string status = turma->obterStatusAprovacao(this->getID());
            
            std::cout << "   ──────────────────────────────────────" << std::endl;
            std::cout << "   MÉDIA: " << std::fixed << std::setprecision(2) << media 
                      << " | STATUS: " << status << std::endl;
            
            if (status == "Aprovado") aprovadas++;
            else if (status == "Recuperacao") recuperacao++;
            else if (status == "Reprovado") reprovadas++;
        } else {
            std::cout << "   (Nenhuma nota lançada)" << std::endl;
        }
    }
    
    if (!temDisciplinas) {
        std::cout << "\nNenhuma disciplina cursada." << std::endl;
    } else {
        // Resumo geral
        std::cout << "\n════════════════════════════════════════════════════════════" << std::endl;
        std::cout << "RESUMO GERAL:" << std::endl;
        std::cout << "   Total de Disciplinas: " << totalDisciplinas << std::endl;
        std::cout << "   ✓ Aprovadas: " << aprovadas << std::endl;
        std::cout << "   ⚠ Recuperação: " << recuperacao << std::endl;
        std::cout << "   ✗ Reprovadas: " << reprovadas << std::endl;
        
        float mediaGeral = calcularMediaGeral(sistema);
        if (mediaGeral >= 0) {
            std::cout << "   Média Geral: " << std::fixed << std::setprecision(2) << mediaGeral << std::endl;
        }
    }
    
    std::cout << "════════════════════════════════════════════════════════════\n" << std::endl;
}

float Aluno::calcularMediaGeral(SistemaEscolar* sistema) {
    std::vector<Turma*> todasTurmas = sistema->getTodasTurmas();
    
    float somaMedias = 0.0f;
    int countDisciplinas = 0;
    
    for (Turma* turma : todasTurmas) {
        if (!turma->alunoEstaNaTurma(this->getID())) {
            continue;
        }
        
        float media = turma->calcularMediaAluno(this->getID());
        if (media >= 0) {
            somaMedias += media;
            countDisciplinas++;
        }
    }
    
    if (countDisciplinas == 0) {
        return -1.0f;
    }
    
    return somaMedias / countDisciplinas;
}