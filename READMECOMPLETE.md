

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

lançarNota(int idAluno, int idAvaliacao, float nota, SistemaEscolar*) — lança uma nota para um aluno.

verTurmas(SistemaEscolar*) — lista as turmas do professor.

criarAvaliacao(Turma*, string tipo, float peso) — cria uma avaliação para a turma.



---

🧑‍💼 Coordenador

autenticar() — entra como coordenador.

sair() — encerra a sessão.

cadastrarProfessor(Professor*, SistemaEscolar*) — registra um professor.

cadastrarDisciplina(Disciplina*, SistemaEscolar*) — registra uma disciplina.

cadastrarTurma(Turma*, SistemaEscolar*) — cria uma turma.

verRelatorios(SistemaEscolar*) — acessa relatórios administrativos.



---

📚 Disciplina

setNome(string) — define o nome da disciplina.

setCodigo(int) — define o código da disciplina.

getters correspondentes — retornam nome e código.



---

🏫 Turma

designarProf(Professor*) — atribui um professor.

adicionarAluno(Aluno*) — matricula um aluno.

adicionarAvaliacao(Avaliacao*) — adiciona uma avaliação.

alunoEstaNaTurma(int) const — verifica se o aluno pertence à turma.

calcularMediaAluno(int) const — calcula a média do aluno na turma.

obterStatusAprovacao(int) const — retorna aprovado/reprovado/recuperação.



---

🏢 SistemaEscolar

cadastrarAluno(Aluno*) — registra um aluno.

cadastrarProfessor(Professor*) — registra um professor.

cadastrarCoordenador(Coordenador*) — registra um coordenador.

cadastrarDisciplina(Disciplina*) — registra uma disciplina.

cadastrarTurma(Turma*) — registra uma turma.

buscarAluno(int) — retorna um aluno pelo ID.

buscarProfessor(int) — retorna um professor.

buscarCoordenador(int) — retorna um coordenador.

buscarDisciplina(int) — retorna uma disciplina pelo código.



---

✨ Características

Código organizado e modular.

Fluxos separados para aluno, professor e coordenação.

Estrutura clara de classes e responsabilidades.

Uso simples via terminal.

Fácil expansão para novas funcionalidades.



---
