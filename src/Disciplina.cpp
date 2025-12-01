#include "Disciplina.hpp"
#include "Turma.hpp"


void Disciplina::adicionarTurma(Turma* turma) {
    _turmas.push_back(turma);
}