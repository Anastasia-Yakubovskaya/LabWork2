CXX = g++
CXXFLAGS = -g -Wall -pthread -I. -Werror -Wpedantic
GTEST_LIBS = -lgtest -lpthread

# Основной файл
MAIN_FILE = main.cpp
MAIN_OBJ = $(MAIN_FILE:.cpp=.o)

# Файлы тестов
TEST_DIR = Tests
TEST_FILES = $(wildcard $(TEST_DIR)/GoogleTests.cpp)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

# Основная цель
all: LabWork runTests

# Компиляция основного файла
LabWork: $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o LabWork $(MAIN_OBJ) $(GTEST_LIBS)

# Компиляция объектных файлов тестов
$(TEST_OBJ_FILES): $(TEST_DIR)/%.o : $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Сборка тестов
runTests: $(TEST_OBJ_FILES) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o runTests $(TEST_OBJ_FILES) $(GTEST_LIBS)

# Правила сборки для основного объекта
$(MAIN_OBJ): $(MAIN_FILE)
	$(CXX) $(CXXFLAGS) -c $(MAIN_FILE) -o $(MAIN_OBJ)

# Очистка объектных файлов
clean:
	rm -f $(TEST_DIR)/*.o *.o

# Полная очистка
cleanall:
	rm -f $(TEST_DIR)/*.o *.o LabWork runTests
