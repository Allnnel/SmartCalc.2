CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++17
APP = SmartCalc/SmartCalc.app
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	LEAKS_CMD = valgrind --tool=memcheck --leak-check=yes
	ADD_LIB = -lgtest -lpthread
endif

ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open -a "Google Chrome"
	LEAKS_CMD = leaks -atExit --
	ADD_LIB = -lgtest
endif

all: test install

test: clean
	@$(CC) $(CPPFLAGS) test.cc -o test $(ADD_LIB)
	@./test

test_leaks: clean
	@$(CC) $(CPPFLAGS) test.cc -o test $(ADD_LIB)
	$(LEAKS_CMD) ./test

build:  
	@mkdir SmartCalc
	cd SmartCalc/ && qmake ../Front/SmartCalc.pro && make 

install: build
	@mkdir -p $(HOME)/Desktop/SmartCalc/
	@cp -rf $(APP) $(HOME)/Desktop/SmartCalc/
	make clean

uninstall:
	@rm -rf $(HOME)/Desktop/SmartCalc/

dvi:
	@open ./Specification/SpecificationSmartCalc.md

dist: install
	@mkdir -p $(HOME)/Desktop/dist
	@cp -R $(HOME)/Desktop/SmartCalc/SmartCalc.app $(HOME)/Desktop/dist
	@cp -R ./Specification/. $(HOME)/Desktop/dist/Specification
	@cd $(HOME)/Desktop/dist && tar cvzf smartCalc_v2.0.tgz *
	@cd $(HOME)/Desktop/dist && rm -rf SmartCalc.app ./Specification
	@rm -rf $(HOME)/Desktop/SmartCalc/

gcov: clean
	@$(CC) $(CPPFLAGS) --coverage test.cc Controller/s21_controllerSmartCalc.h Model/s21_modelSmartCalc.h -o test $(ADD_LIB)
	@./test
	@rm -rf test_main.gcda test_main.gcno
	@lcov -t "test" -o fizzbuzz.info -c -d . --ignore-errors mismatch
	@genhtml -o report fizzbuzz.info
	@$(OPEN_CMD) report/index.html

style:
	@find . \( -name "*.cc" -o -name "*.cpp" -o -name "*.h" \) -exec clang-format -style=Google -n {} \;

clean:
	@-rm -rf *.o *.gcno *.gcda *.info *.gcov *.a *.dSYM report test SmartCalc*

.PHONY: test gcov valgrind test_leaks all install uninstall dvi dist style clean
