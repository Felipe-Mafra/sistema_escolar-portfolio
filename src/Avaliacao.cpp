#include "Avaliacao.hpp"
#include "Turma.hpp"
#include <iostream>

void Avaliacao::setNota(int idAluno, float nota) {
    // Insere nota no mapa
    _notas[idAluno] = nota;
}

float Avaliacao::getNota(int idAluno) const {
    // Procura aluno no mapa
    auto it = _notas.find(idAluno);

    if (it != _notas.end()) {
        return it->second;
    }
    
    return -1.0f; // -1 = sem nota
}