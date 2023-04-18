CC = clang
LAB_OPTS = -I./src src/lib.c
C_OPTS = $(MAC_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

all: clean prep compile check doxygen

all_doxygen: clean_doxygen doxygen

clean:
	rm -rf dist
	
clean_doxygen:
	rm -rf ./dist/html
	rm -rf ./dist/latex
doxygen: 
	doxygen main.c
	
prep:
	mkdir dist
	
doxygen: 
	doxygen doxyfile
	
compile: main.bin test.bin
test.bin: test/test.c
	$(CC) $(C_OPTS) $< -fprofile-instr-generate -fcoverage-mapping -o ./dist/$@ -lcheck
test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/main.bin
check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
