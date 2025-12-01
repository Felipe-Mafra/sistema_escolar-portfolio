#include "Professor.hpp"
#include "Aluno.hpp"
#include "Turma.hpp"
#include "Avaliacao.hpp"
#include "SistemaEscolar.hpp"
#include <iostream>
#include <string>
#include <vector>


void Professor::autenticar() {
    std::cout << "Professor " << getNome() << " Logado com sucesso " << "Departamento: " << getDepartamento() << std::endl;
}

void Professor::sair() {
    std::cout << "Professor " << getNome() << " Deslogado do sistema! " << std::endl;
}

void Professor::criarAvaliacao(SistemaEscolar* sistema) {
    int codTurma, codAv;
    std::string nomeAv;

    std::cout << "Para qual turma deseja criar avaliacao? (Cod): ";
    std::cin >> codTurma;
    Turma* turma = sistema->buscarTurma(codTurma);

    if (!turma) {
        std::cout << "Turma nao encontrada." << std::endl;
        return;
    }

    std::cout << "Codigo da Avaliacao: "; std::cin >> codAv;
    std::cin.ignore();
    std::cout << "Nome da Avaliacao (ex: Prova 1): "; std::getline(std::cin, nomeAv);

    Avaliacao* novaAv = new Avaliacao(codAv, nomeAv, turma);
    turma->adicionarAvaliacao(novaAv);
    
    std::cout << "Avaliacao criada na turma " << turma->getNome() << std::endl;
}

void Professor::atribuirNota(SistemaEscolar* sistema) {
    int codTurma, idAluno, codAv;
    float nota;

    std::cout << "Codigo da Turma: "; std::cin >> codTurma;
    Turma* turma = sistema->buscarTurma(codTurma);
    if (!turma) return;

    // Mostra as avaliações disponíveis
    std::cout << "Avaliacoes desta turma:" << std::endl;
    auto avaliacoes = turma->getAvaliacoes();
    for (auto av : avaliacoes) {
        std::cout << " - [" << av->getCod() << "] " << av->getTitulo() << std::endl;
    }

    std::cout << "Codigo da Avaliacao escolhida: "; std::cin >> codAv;
    
    // Busca avaliação na lista
    Avaliacao* avSelecionada = nullptr;
    for (auto av : avaliacoes) {
        if (av->getCod() == codAv) {
            avSelecionada = av;
            break;
        }
    }

    if (!avSelecionada) {
        std::cout << "Avaliacao nao encontrada." << std::endl;
        return;
    }

    std::cout << "ID do Aluno: "; std::cin >> idAluno;
    Aluno* aluno = sistema->buscarAluno(idAluno);
    
    if (!aluno) { std::cout << "Aluno invalido." << std::endl; return; }
    
    // Verifica se aluno está matriculado na turma
    if (!turma->alunoEstaNaTurma(idAluno)) {
        std::cout << "Erro: Aluno nao esta matriculado nesta turma." << std::endl;
        return;
    }

    std::cout << "Nota (0-10): "; std::cin >> nota;
    
    // Validação da nota
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Erro: Entrada invalida. Digite um numero." << std::endl;
        return;
    }
    
    if (nota < 0 || nota > 10) {
        std::cout << "Erro: Nota deve estar entre 0 e 10." << std::endl;
        return;
    }

    avSelecionada->setNota(idAluno, nota);
    std::cout << "Nota lancada com sucesso." << std::endl;
}