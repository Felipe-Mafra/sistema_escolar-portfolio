#include "SistemaEscolar.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Coordenador.hpp"
#include "Disciplina.hpp"
#include "Turma.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

SistemaEscolar::SistemaEscolar() {
    _usuarioLogado = nullptr;
}

SistemaEscolar::~SistemaEscolar() {
    std::cout << "\n>> Salvando dados antes de encerrar..." << std::endl;
    salvarDados();
    
    for (auto const& pair : _alunos) delete pair.second;
    _alunos.clear();
    for (auto const& pair : _professores) delete pair.second;
    _professores.clear();
    for (auto const& pair : _coordenadores) delete pair.second;
    _coordenadores.clear();
    for (auto const& pair : _disciplinas) delete pair.second;
    _disciplinas.clear();
    for (auto const& pair : _turmas) delete pair.second;
    _turmas.clear();
    
    std::cout << ">> Sistema encerrado." << std::endl;
}

// --- Cadastros (Implementação) ---
void SistemaEscolar::cadastrarAluno(Aluno* aluno) {
    _alunos[aluno->getID()] = aluno; 
}
void SistemaEscolar::cadastrarProfessor(Professor* prof) {
    _professores[prof->getID()] = prof;
}
void SistemaEscolar::cadastrarCoordenador(Coordenador* coord) {
    _coordenadores[coord->getID()] = coord;
}
void SistemaEscolar::cadastrarDisciplina(Disciplina* disc) {
    _disciplinas[disc->getCod()] = disc;
}
void SistemaEscolar::cadastrarTurma(Turma* turma) {
    _turmas[turma->getCod()] = turma;
}

// --- Buscas ---
Aluno* SistemaEscolar::buscarAluno(int id) {
    if (_alunos.count(id)) return _alunos[id];
    return nullptr;
}
Professor* SistemaEscolar::buscarProfessor(int id) {
    if (_professores.count(id)) return _professores[id];
    return nullptr;
}
Coordenador* SistemaEscolar::buscarCoordenador(int id) {
    if (_coordenadores.count(id)) return _coordenadores[id];
    return nullptr;
}
Disciplina* SistemaEscolar::buscarDisciplina(int cod) {
    if (_disciplinas.count(cod)) return _disciplinas[cod];
    return nullptr;
}
Turma* SistemaEscolar::buscarTurma(int cod) {
    if (_turmas.count(cod)) return _turmas[cod];
    return nullptr;
}

std::vector<Turma*> SistemaEscolar::getTodasTurmas() const {
    std::vector<Turma*> lista;
    for (auto const& pair : _turmas) {
        lista.push_back(pair.second);
    }
    return lista;
}

Usuario* SistemaEscolar::getUsuarioLogado() {
    return _usuarioLogado;
}
void SistemaEscolar::deslogar() {
    if (_usuarioLogado) {
        _usuarioLogado->sair(); 
        _usuarioLogado = nullptr;
    }
}

void SistemaEscolar::salvarDados() {
    // Salvar Alunos
    std::ofstream arquivoAlunos("data/alunos.csv");
    if (arquivoAlunos.is_open()) {
        arquivoAlunos << "ID,Nome,Matricula\n";
        for (auto const& pair : _alunos) {
            Aluno* a = pair.second;
            arquivoAlunos << a->getID() << "," 
                         << a->getNome() << "," 
                         << a->getNumMatricula() << "\n";
        }
        arquivoAlunos.close();
        std::cout << ">> Alunos salvos: " << _alunos.size() << std::endl;
    }
    
    // Salvar Professores
    std::ofstream arquivoProfessores("data/professores.csv");
    if (arquivoProfessores.is_open()) {
        arquivoProfessores << "ID,Nome,Departamento\n";
        for (auto const& pair : _professores) {
            Professor* p = pair.second;
            arquivoProfessores << p->getID() << "," 
                              << p->getNome() << "," 
                              << p->getDepartamento() << "\n";
        }
        arquivoProfessores.close();
        std::cout << ">> Professores salvos: " << _professores.size() << std::endl;
    }
    
    // Salvar Disciplinas
    std::ofstream arquivoDisciplinas("data/disciplinas.csv");
    if (arquivoDisciplinas.is_open()) {
        arquivoDisciplinas << "Codigo,Nome,CargaHoraria,CoordenadorID\n";
        for (auto const& pair : _disciplinas) {
            Disciplina* d = pair.second;
            arquivoDisciplinas << d->getCod() << "," 
                              << d->getNome() << "," 
                              << d->getCarga() << ",1\n"; // Coordenador fixo por enquanto
        }
        arquivoDisciplinas.close();
        std::cout << ">> Disciplinas salvas: " << _disciplinas.size() << std::endl;
    }
    
    // Salvar Turmas
    std::ofstream arquivoTurmas("data/turmas.csv");
    if (arquivoTurmas.is_open()) {
        arquivoTurmas << "Codigo,Nome,DisciplinaCod,ProfessorID\n";
        for (auto const& pair : _turmas) {
            Turma* t = pair.second;
            arquivoTurmas << t->getCod() << "," 
                         << t->getNome() << "," 
                         << t->getDisciplina()->getCod() << ",10\n"; // Professor fixo por enquanto
        }
        arquivoTurmas.close();
        std::cout << ">> Turmas salvas: " << _turmas.size() << std::endl;
    }
    
    // Salvar Matrículas (TODO: implementar quando houver getter de alunos em Turma)
    std::ofstream arquivoMatriculas("data/matriculas.csv");
    if (arquivoMatriculas.is_open()) {
        arquivoMatriculas << "TurmaCod,AlunoID\n";
        // int totalMatriculas = 0;
        // TODO: Implementar quando Turma tiver getAlunos()
        arquivoMatriculas.close();
    }
    
    std::cout << ">> Dados salvos com sucesso!" << std::endl;
}

void SistemaEscolar::carregarDados() {
    // Carregar Alunos
    std::ifstream arquivoAlunos("data/alunos.csv");
    if (arquivoAlunos.is_open()) {
        std::string linha, id, nome, matricula;
        std::getline(arquivoAlunos, linha); // Pular cabeçalho
        
        int count = 0;
        while (std::getline(arquivoAlunos, linha)) {
            std::stringstream ss(linha);
            std::getline(ss, id, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, matricula, ',');
            
            if (!id.empty() && !nome.empty() && !matricula.empty()) {
                Aluno* a = new Aluno(std::stoi(id), nome, std::stoi(matricula));
                cadastrarAluno(a);
                count++;
            }
        }
        arquivoAlunos.close();
        if (count > 0) std::cout << ">> Alunos carregados: " << count << std::endl;
    }
    
    // Carregar Professores
    std::ifstream arquivoProfessores("data/professores.csv");
    if (arquivoProfessores.is_open()) {
        std::string linha, id, nome, depto;
        std::getline(arquivoProfessores, linha); // Pular cabeçalho
        
        int count = 0;
        while (std::getline(arquivoProfessores, linha)) {
            std::stringstream ss(linha);
            std::getline(ss, id, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, depto, ',');
            
            if (!id.empty() && !nome.empty() && !depto.empty()) {
                Professor* p = new Professor(std::stoi(id), nome, depto);
                cadastrarProfessor(p);
                count++;
            }
        }
        arquivoProfessores.close();
        if (count > 0) std::cout << ">> Professores carregados: " << count << std::endl;
    }
    
    // Carregar Disciplinas (precisa ter coordenador cadastrado)
    std::ifstream arquivoDisciplinas("data/disciplinas.csv");
    if (arquivoDisciplinas.is_open()) {
        std::string linha, cod, nome, carga, coordId;
        std::getline(arquivoDisciplinas, linha); // Pular cabeçalho
        
        int count = 0;
        while (std::getline(arquivoDisciplinas, linha)) {
            std::stringstream ss(linha);
            std::getline(ss, cod, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, carga, ',');
            std::getline(ss, coordId, ',');
            
            if (!cod.empty() && !nome.empty() && !carga.empty()) {
                Coordenador* coord = buscarCoordenador(std::stoi(coordId));
                if (coord) {
                    Disciplina* d = new Disciplina(std::stoi(cod), nome, std::stoi(carga), coord);
                    cadastrarDisciplina(d);
                    count++;
                }
            }
        }
        arquivoDisciplinas.close();
        if (count > 0) std::cout << ">> Disciplinas carregadas: " << count << std::endl;
    }
    
    if (_alunos.empty() && _professores.empty() && _disciplinas.empty()) {
        std::cout << ">> Nenhum dado encontrado nos arquivos. Iniciando com dados vazios." << std::endl;
    }
}