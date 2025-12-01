CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Arquivos-fonte
SRC = main.cpp \
      src/Aluno.cpp \
      src/Coordenador.cpp \
      src/Disciplina.cpp \
      src/Professor.cpp \
      src/SistemaEscolar.cpp \
      src/Turma.cpp \
      src/Avaliacao.cpp

# Gera os .o correspondentes
OBJ = $(SRC:.cpp=.o)

TARGET = app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar qualquer .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)