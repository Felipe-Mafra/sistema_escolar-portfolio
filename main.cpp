#include <iostream>
#include "SistemaEscolar.hpp"
#include "Coordenador.hpp"
#include "Professor.hpp"
#include "Aluno.hpp"
#include "Disciplina.hpp"
#include "Turma.hpp"


void carregarDadosIniciais(SistemaEscolar& sistema) {
    std::cout << ">> Carregando dados do banco de dados..." << std::endl;
    sistema.carregarDados();
    
    // Se não houver dados, cria dados de exemplo
    if (sistema.buscarCoordenador(1) == nullptr) {
        std::cout << ">> Criando dados iniciais para teste..." << std::endl;
        
        //Coordenador p/ teste
        Coordenador* c1 = new Coordenador(1, "Jose");
        sistema.cadastrarCoordenador(c1);

        //Professores p/ teste
        Professor* p1 = new Professor(10, "Prof. Aldo", "Matematica");
        Professor* p2 = new Professor(20, "Prof. Naldo", "Fisica");
        sistema.cadastrarProfessor(p1);
        sistema.cadastrarProfessor(p2);

        //Alunos p/ teste
        Aluno* a1 = new Aluno(100, "Thiago", 202401);
        Aluno* a2 = new Aluno(101, "Vitor", 202402);
        Aluno* a3 = new Aluno(102, "Lucas", 202403);
        sistema.cadastrarAluno(a1);
        sistema.cadastrarAluno(a2);
        sistema.cadastrarAluno(a3);
        
        std::cout << ">> Dados iniciais criados!" << std::endl;
    }
}

void menuCoordenador(Coordenador* c, SistemaEscolar& sis);
void menuProfessor(Professor* p, SistemaEscolar& sis);
void menuAluno(Aluno* a, SistemaEscolar& sis);

int main() {
    SistemaEscolar sistema; 
    carregarDadosIniciais(sistema);

    int perfil = -1;
    while (perfil != 0) {
        std::cout << "\n=== SIMULADOR ESCOLAR ===" << std::endl;
        std::cout << "Escolha o perfil para simular:" << std::endl;
        std::cout << "1. Coordenador (ID 1)" << std::endl;
        std::cout << "2. Professor (IDs 10, 20)" << std::endl;
        std::cout << "3. Aluno (IDs 100, 101, 102)" << std::endl;
        std::cout << "9. Salvar Dados Agora" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> perfil;
        
        // Tratamento de entrada inválida
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erro: Entrada invalida. Digite um numero." << std::endl;
            continue;
        }

        if (perfil == 0) break;
        
        if (perfil == 9) {
            std::cout << "\n>> Salvando dados manualmente..." << std::endl;
            sistema.salvarDados();
            continue;
        }

        int id;
        std::cout << "Informe o ID do usuario: ";
        std::cin >> id;
        
        // Tratamento de entrada inválida para ID
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erro: ID invalido. Digite um numero." << std::endl;
            continue;
        }

        if (perfil == 1) {
            Coordenador* c = sistema.buscarCoordenador(id);
            if (c) menuCoordenador(c, sistema);
            else std::cout << ">> Coordenador nao encontrado." << std::endl;
        }
        else if (perfil == 2) {
            Professor* p = sistema.buscarProfessor(id);
            if (p) menuProfessor(p, sistema);
            else std::cout << ">> Professor nao encontrado." << std::endl;
        }
        else if (perfil == 3) {
            Aluno* a = sistema.buscarAluno(id);
            if (a) menuAluno(a, sistema);
            else std::cout << ">> Aluno nao encontrado." << std::endl;
        }
        else {
            std::cout << "Opcao invalida." << std::endl;
        }
    }
    return 0;
}

//Menus
void menuCoordenador(Coordenador* coord, SistemaEscolar& sistema) {
    int op;
    coord->autenticar();
    do {
        std::cout << "\n[MENU COORDENADOR]" << std::endl;
        std::cout << "1. Criar Disciplina" << std::endl;
        std::cout << "2. Abrir Turma" << std::endl;
        std::cout << "3. Matricular Aluno" << std::endl;
        std::cout << "0. Voltar" << std::endl;
        std::cout << "Opcao: "; std::cin >> op;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erro: Entrada invalida." << std::endl;
            continue;
        }

        switch (op) {
            case 1: coord->criarDisciplina(&sistema); break;
            case 2: coord->abrirTurma(&sistema); break;
            case 3: coord->matricularAluno(&sistema); break;
            case 0: coord->sair(); break;
            default: std::cout << "Invalido!" << std::endl;
        }
    } while (op != 0);
}

void menuProfessor(Professor* prof, SistemaEscolar& sistema) {
    int op;
    prof->autenticar();
    do {
        std::cout << "\n[MENU PROFESSOR]" << std::endl;
        std::cout << "1. Criar Avaliacao" << std::endl;
        std::cout << "2. Lancar Notas" << std::endl;
        std::cout << "0. Voltar" << std::endl;
        std::cout << "Opcao: "; std::cin >> op;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erro: Entrada invalida." << std::endl;
            continue;
        }

        switch (op) {
            case 1: prof->criarAvaliacao(&sistema); break;
            case 2: prof->atribuirNota(&sistema); break;
            case 0: prof->sair(); break;
            default: std::cout << "Invalido!" << std::endl;
        }
    } while (op != 0);
}

void menuAluno(Aluno* aluno, SistemaEscolar& sistema) {
    int op;
    aluno->autenticar();
    do {
        std::cout << "\n[MENU ALUNO]" << std::endl;
        std::cout << "1. Ver Boletim" << std::endl;
        std::cout << "2. Ver Historico Completo" << std::endl;
        std::cout << "0. Voltar" << std::endl;
        std::cout << "Opcao: "; std::cin >> op;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erro: Entrada invalida." << std::endl;
            continue;
        }

        switch (op) {
            case 1: aluno->verNotas(&sistema); break;
            case 2: aluno->verHistoricoCompleto(&sistema); break;
            case 0: aluno->sair(); break;
            default: std::cout << "Invalido!" << std::endl;
        }
    } while (op != 0);
}