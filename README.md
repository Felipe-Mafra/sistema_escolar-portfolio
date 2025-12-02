
# 🎓 Sistema Escolar – Documentação Completa


## 1. README 

🎓 Sistema Escolar – README

Funcionalidades Implementadas ✅

Cálculo automático de médias: média por disciplina, média geral e status de aprovação.

Histórico acadêmico completo: notas, avaliações e desempenho consolidado.

Persistência: carregamento e salvamento automático em arquivos CSV.

Relatórios: informações organizadas para professores, alunos e coordenação.

Fluxo completo: coordenador cria disciplinas/turmas, professor lança notas, aluno consulta.

---

🚀 Início Rápido

# Compilar
g++ -std=c++17 *.cpp -o sistema

# Executar
./sistema

---

📦 Classes e Métodos

A seguir estão os métodos presentes no código, explicados de forma extremamente breve.

---

🧑‍🎓 Aluno
autenticar() — entra no sistema como aluno.
sair() — encerra a sessão do aluno.
verNotas(SistemaEscolar*) — exibe as notas do aluno.
verHistoricoCompleto(SistemaEscolar*) — mostra o histórico completo.
calcularMediaGeral(SistemaEscolar*) — retorna a média geral do aluno.

---

📝 Avaliacao
setNota(int idAluno, float nota) — registra a nota de um aluno.
getNota(int idAluno) const — consulta a nota de um aluno.

---

👨‍🏫 Professor
autenticar() — entra como professor.
sair() — encerra sessão do professor.
lançarNota(int idAluno, int idAvaliacao, float nota, SistemaEscolar*) — lança nota.
verTurmas(SistemaEscolar*) — lista turmas.
criarAvaliacao(Turma*, string tipo, float peso) — cria uma avaliação.

---

🧑‍💼 Coordenador
autenticar() — entra como coordenador.
sair() — encerra a sessão.
cadastrarProfessor(Professor*, SistemaEscolar*) — registra professor.
cadastrarDisciplina(Disciplina*, SistemaEscolar*) — registra disciplina.
cadastrarTurma(Turma*, SistemaEscolar*) — cria turma.
verRelatorios(SistemaEscolar*) — acessa relatórios administrativos.

---

📚 Disciplina
setNome(string) — define o nome.
setCodigo(int) — define o código.
getters — retornam nome e código.

---

🏫 Turma
designarProf(Professor*) — atribui professor.
adicionarAluno(Aluno*) — matricula aluno.
adicionarAvaliacao(Avaliacao*) — adiciona avaliação.
alunoEstaNaTurma(int) const — verifica pertencimento.
calcularMediaAluno(int) const — média do aluno.
obterStatusAprovacao(int) const — aprovado/reprovado/recuperação.

---

🏢 SistemaEscolar
cadastrarAluno(Aluno*)
cadastrarProfessor(Professor*)
cadastrarCoordenador(Coordenador*)
cadastrarDisciplina(Disciplina*)
cadastrarTurma(Turma*)
buscarAluno(int)
buscarProfessor(int)
buscarCoordenador(int)
buscarDisciplina(int)

---

✨ Características
Código organizado e modular.
Fluxos separados para aluno, professor e coordenação.
Estrutura clara de classes e responsabilidades.
Uso simples via terminal.
Fácil expansão para novas funcionalidades.

---

## 2. Visão Geral do Projeto

O **Sistema Escolar** é uma aplicação desenvolvida em C++ para simular o gerenciamento básico de uma instituição de ensino.

Inclui:
- registro de alunos, professores e disciplinas
- criação de turmas e avaliações
- lançamento de notas
- cálculo de médias e status de aprovação
- relatórios administrativos
- persistência em arquivos CSV

---

## 3. Arquitetura do Sistema

Estrutura baseada em POO:

### Usuários
- Aluno
- Professor
- Coordenador

### Entidades Acadêmicas
- Disciplina
- Turma
- Avaliação

### Gerenciador Global
SistemaEscolar (atua como um banco de dados em memória)

---

## 4. Estrutura de Pastas

/include  
/src  
main.cpp  
Makefile  
/data (arquivos CSV)

---

## 5. Compilação e Execução (versão melhorada)

Compilar:
```
make
```

Executar:
```
./app
```

Limpar:
```
make clean
```

---

## 6. Fluxos Operacionais

### Coordenador
cria turmas, gerencia professores, disciplinas, gera relatórios.

### Professor
visualiza turmas, cria avaliações, lança notas.

### Aluno
consulta notas, histórico e situação acadêmica.

---

## 7. Funcionalidades em Destaque

- média ponderada  
- média geral  
- histórico completo  
- aprovação automática  
- persistência em CSV  
- menus simples no terminal  

---

