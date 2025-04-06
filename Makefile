# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Имя исполняемого файла для основного проекта
TARGET = game

# Имя исполняемого файла для тестов
TEST_TARGET = game_tests

# Папки с исходными файлами
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests

# Список всех исходных файлов (исключая main.cpp)
SRCS = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))

# Список всех тестовых файлов
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

# Генерация списка объектных файлов для основного проекта
OBJS = $(SRCS:.cpp=.o)

# Генерация списка объектных файлов для тестов
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла для основного проекта
$(TARGET): $(OBJS) src/main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) src/main.o

# Сборка исполняемого файла для тестов
$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(OBJS) $(TEST_OBJS) -lgtest -lgtest_main -pthread

# Правило для компиляции каждого .cpp файла в .o (основной проект)
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для компиляции каждого .cpp файла в .o (тесты)
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка проекта
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET) src/main.o

# Флаг для предотвращения конфликтов с одноименными файлами
.PHONY: all clean test

# Правило для запуска тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)
