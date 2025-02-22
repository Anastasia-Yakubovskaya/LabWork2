CXX = g++
CXXFLAGS = -g -Wall -pthread -I. -Werror -Wpedantic
GTEST_LIBS = -lgtest -lpthread


MAIN_FILE = main.cpp
MAIN_OBJ = $(MAIN_FILE:.cpp=.o)


TEST_DIR = Tests
TEST_FILES = $(wildcard $(TEST_DIR)/GoogleTests.cpp)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)


all: LabWork runTests


LabWork: $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o LabWork $(MAIN_OBJ) $(GTEST_LIBS)


$(TEST_OBJ_FILES): $(TEST_DIR)/%.o : $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


runTests: $(TEST_OBJ_FILES) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o runTests $(TEST_OBJ_FILES) $(GTEST_LIBS)


$(MAIN_OBJ): $(MAIN_FILE)
	$(CXX) $(CXXFLAGS) -c $(MAIN_FILE) -o $(MAIN_OBJ)


clean:
	rm -f $(TEST_DIR)/*.o *.o


cleanall:
	rm -f $(TEST_DIR)/*.o *.o LabWork runTests
