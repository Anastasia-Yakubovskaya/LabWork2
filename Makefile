# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Имя исполняемого файла
TARGET = game

# Папки с исходными файлами
SRC_DIR = src
INCLUDE_DIR = include

# Список всех исходных файлов (включая main.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Генерация списка объектных файлов
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило для компиляции каждого .cpp файла в .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



# Очистка проекта
clean:
	rm -f $(OBJS) $(TARGET)

# Флаг для предотвращения конфликтов с одноименными файлами
.PHONY: all clean
