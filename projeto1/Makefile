# My Little Makefile
FLEX=flex
BISON=bison
CC=clang++
PARAM=-std=c++11 -fcxx-exceptions -Wno-deprecated-register -Wall
OUTPUT=lukacompiler

all: $(OUTPUT) scanner.cpp parser.h test compare

$(OUTPUT): parser.h scanner.cpp main.cpp
	${CC} -o ${OUTPUT} *.cpp ${PARAM}

scanner.cpp: scanner.l parser.h
	${FLEX} -o scanner.cpp scanner.l 

parser.h: parser.y
	${BISON} --defines=parser.h --output=parser.cpp parser.y

clean:
	rm parser.cpp parser.h scanner.cpp ${OUTPUT}

test: 
#	./${OUTPUT} < tests/v0.1/input/1.in > tests/v0.1/output/1.out
	./${OUTPUT} < tests/v0.1/input/2.in > tests/v0.1/output/2.out
	./${OUTPUT} < tests/v0.1/input/3.in > tests/v0.1/output/3.out
#	./${OUTPUT} < tests/v0.2/input/1.in > tests/v0.2/output/1.out
	./${OUTPUT} < tests/v0.2/input/2.in > tests/v0.2/output/2.out
	./${OUTPUT} < tests/v0.2/input/3.in > tests/v0.2/output/3.out
	./${OUTPUT} < tests/v0.3/input/1.in > tests/v0.3/output/1.out
	./${OUTPUT} < tests/v0.3/input/2.in > tests/v0.3/output/2.out
	./${OUTPUT} < tests/v0.4/input/1.in > tests/v0.4/output/1.out
	./${OUTPUT} < tests/v0.4/input/2.in > tests/v0.4/output/2.out
	./${OUTPUT} < tests/v0.5/input/1.in > tests/v0.5/output/1.out
	./${OUTPUT} < tests/v0.5/input/2.in > tests/v0.5/output/2.out
	./${OUTPUT} < tests/v0.5/input/3.in > tests/v0.5/output/3.out
	./${OUTPUT} < tests/v0.6/input/1.in > tests/v0.6/output/1.out
	./${OUTPUT} < tests/v0.6/input/2.in > tests/v0.6/output/2.out
#	./${OUTPUT} < tests/v0.7/input/1.in > tests/v0.7/output/1.out
#	./${OUTPUT} < tests/v0.7/input/2.in > tests/v0.7/output/2.out
#	./${OUTPUT} < tests/v0.8/input/1.in > tests/v0.8/output/1.out
#	./${OUTPUT} < tests/v0.8/input/2.in > tests/v0.8/output/2.out
#	./${OUTPUT} < tests/v1.0/input/1.in > tests/v1.0/output/1.out
#	./${OUTPUT} < tests/v1.0/input/2.in > tests/v1.0/output/2.out


compare:
#	diff tests/v0.1/expected/1.ex tests/v0.1/output/1.out
	diff tests/v0.1/expected/2.ex tests/v0.1/output/2.out
	diff tests/v0.1/expected/3.ex tests/v0.1/output/3.out
#	diff tests/v0.2/expected/1.ex tests/v0.2/output/1.out
	diff tests/v0.2/expected/2.ex tests/v0.2/output/2.out
	diff tests/v0.2/expected/3.ex tests/v0.2/output/3.out
	diff tests/v0.3/expected/1.ex tests/v0.3/output/1.out
	diff tests/v0.3/expected/2.ex tests/v0.3/output/2.out
	diff tests/v0.4/expected/1.ex tests/v0.4/output/1.out
	diff tests/v0.4/expected/2.ex tests/v0.4/output/2.out
	diff tests/v0.5/expected/1.ex tests/v0.5/output/1.out
	diff tests/v0.5/expected/2.ex tests/v0.5/output/2.out
	diff tests/v0.5/expected/3.ex tests/v0.5/output/3.out
	diff tests/v0.6/expected/1.ex tests/v0.6/output/1.out
	diff tests/v0.6/expected/2.ex tests/v0.6/output/2.out
#	diff tests/v0.7/expected/1.ex tests/v0.7/output/1.out
#	diff tests/v0.7/expected/2.ex tests/v0.7/output/2.out
#	diff tests/v0.8/expected/1.ex tests/v0.8/output/1.out
#	diff tests/v0.8/expected/2.ex tests/v0.8/output/2.out
#	diff tests/v1.0/expected/1.ex tests/v1.0/output/1.out
#	diff tests/v1.0/expected/2.ex tests/v1.0/output/2.out
