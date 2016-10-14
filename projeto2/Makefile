# My Little Makefile
FLEX=flex
BISON=bison
CC=clang++
PARAM=-std=c++11 -fcxx-exceptions -Wno-deprecated-register -Wall 
OUTPUT=lukacompiler

all: $(OUTPUT) scanner.cpp parser.h test compare_test error_test compare_error_test

$(OUTPUT): parser.h scanner.cpp main.cpp
	${CC} -o ${OUTPUT} *.cpp ${PARAM}

scanner.cpp: scanner.l parser.h
	${FLEX} -o scanner.cpp scanner.l 

parser.h: parser.y
	${BISON} --defines=parser.h --output=parser.cpp parser.y

clean:
	rm parser.cpp parser.h scanner.cpp ${OUTPUT}

test: 
	./${OUTPUT} < tests/v0.1/input/1.in > tests/v0.1/output/1.out 
	./${OUTPUT} < tests/v0.1/input/2.in > tests/v0.1/output/2.out
	./${OUTPUT} < tests/v0.1/input/3.in > tests/v0.1/output/3.out
	./${OUTPUT} < tests/v0.2/input/1.in > tests/v0.2/output/1.out
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
	./${OUTPUT} < tests/v0.7/input/1.in > tests/v0.7/output/1.out
	./${OUTPUT} < tests/v0.7/input/2.in > tests/v0.7/output/2.out
	./${OUTPUT} < tests/v0.7/input/3.in > tests/v0.7/output/3.out
	./${OUTPUT} < tests/v0.8/input/1.in > tests/v0.8/output/1.out
	./${OUTPUT} < tests/v0.8/input/2.in > tests/v0.8/output/2.out
	./${OUTPUT} < tests/v0.8/input/3.in > tests/v0.8/output/3.out
	./${OUTPUT} < tests/v1.0/input/1.in > tests/v1.0/output/1.out
	./${OUTPUT} < tests/v1.0/input/2.in > tests/v1.0/output/2.out
	./${OUTPUT} < tests/v1.0/input/3.in > tests/v1.0/output/3.out

compare_test:
	diff tests/v0.1/expected/1.ex tests/v0.1/output/1.out  || exit 0
	diff tests/v0.1/expected/2.ex tests/v0.1/output/2.out
	diff tests/v0.1/expected/3.ex tests/v0.1/output/3.out
	diff tests/v0.2/expected/1.ex tests/v0.2/output/1.out
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
	diff tests/v0.7/expected/1.ex tests/v0.7/output/1.out
	diff tests/v0.7/expected/2.ex tests/v0.7/output/2.out
	diff tests/v0.8/expected/1.ex tests/v0.8/output/1.out
	diff tests/v0.8/expected/2.ex tests/v0.8/output/2.out
	diff tests/v0.8/expected/3.ex tests/v0.8/output/3.out
	diff tests/v1.0/expected/1.ex tests/v1.0/output/1.out
	diff tests/v1.0/expected/2.ex tests/v1.0/output/2.out
	diff tests/v1.0/expected/3.ex tests/v1.0/output/3.out

##Testes de erro


# Para nao poluir a tela, consultar error_tests/versao/input para as entradas do teste e error_tests/versao/output para as saidas correspondentes, o status dos testes pode ser resumido consultando o arquivo errors_tests/errors_testes.txt\

error_test:
	./${OUTPUT} < error_tests/v0.1/input/1.in > error_tests/v0.1/output/1.out 2> error_tests/v0.1/output/1.out_err
	./${OUTPUT} < error_tests/v0.1/input/2.in > error_tests/v0.1/output/2.out 2> error_tests/v0.1/output/2.out_err
	./${OUTPUT} < error_tests/v0.1/input/3.in > error_tests/v0.1/output/3.out 2> error_tests/v0.1/output/3.out_err
	./${OUTPUT} < error_tests/v0.1/input/4.in > error_tests/v0.1/output/4.out 2> error_tests/v0.1/output/4.out_err
	./${OUTPUT} < error_tests/v0.2/input/1.in > error_tests/v0.2/output/1.out 2> error_tests/v0.2/output/1.out_err
	./${OUTPUT} < error_tests/v0.2/input/2.in > error_tests/v0.2/output/2.out 2> error_tests/v0.2/output/2.out_err
	./${OUTPUT} < error_tests/v0.1/input/3b.in > error_tests/v0.1/output/3b.out 2> error_tests/v0.1/output/3b.out_err
	./${OUTPUT} < error_tests/v0.4/input/1.in > error_tests/v0.4/output/1.out 2> error_tests/v0.4/output/1.out_err
	./${OUTPUT} < error_tests/v0.5/input/1.in > error_tests/v0.5/output/1.out 2> error_tests/v0.5/output/1.out_err
	./${OUTPUT} < error_tests/v0.6/input/1.in > error_tests/v0.6/output/1.out 2> error_tests/v0.6/output/1.out_err
	./${OUTPUT} < error_tests/v0.7/input/1.in > error_tests/v0.7/output/1.out 2> error_tests/v0.7/output/1.out_err
	./${OUTPUT} < error_tests/v0.7/input/2.in > error_tests/v0.7/output/2.out 2> error_tests/v0.7/output/2.out_err
	./${OUTPUT} < error_tests/v0.7/input/3.in > error_tests/v0.7/output/3.out 2> error_tests/v0.7/output/3.out_err
	./${OUTPUT} < error_tests/v0.7/input/4.in > error_tests/v0.7/output/4.out 2> error_tests/v0.7/output/4.out_err
	./${OUTPUT} < error_tests/v0.7/input/5.in > error_tests/v0.7/output/5.out 2> error_tests/v0.7/output/5.out_err
	./${OUTPUT} < error_tests/v0.7/input/6.in > error_tests/v0.7/output/6.out 2> error_tests/v0.7/output/6.out_err
	./${OUTPUT} < error_tests/v0.7/input/7.in > error_tests/v0.7/output/7.out 2> error_tests/v0.7/output/7.out_err
	./${OUTPUT} < error_tests/v0.8/input/1.in > error_tests/v0.8/output/1.out 2> error_tests/v0.8/output/1.out_err
	./${OUTPUT} < error_tests/v0.8/input/2.in > error_tests/v0.8/output/2.out 2> error_tests/v0.8/output/2.out_err
	./${OUTPUT} < error_tests/v1.0/input/1.in > error_tests/v1.0/output/1.out 2> error_tests/v1.0/output/1.out_err
	./${OUTPUT} < error_tests/v1.0/input/2.in > error_tests/v1.0/output/2.out 2> error_tests/v1.0/output/2.out_err
	./${OUTPUT} < error_tests/v1.0/input/3.in > error_tests/v1.0/output/3.out 2> error_tests/v1.0/output/3.out_err
	./${OUTPUT} < error_tests/v1.0/input/4.in > error_tests/v1.0/output/4.out 2> error_tests/v1.0/output/4.out_err
	./${OUTPUT} < error_tests/v1.0/input/5.in > error_tests/v1.0/output/5.out 2> error_tests/v1.0/output/5.out_err
	./${OUTPUT} < error_tests/v1.0/input/6.in > error_tests/v1.0/output/6.out 2> error_tests/v1.0/output/6.out_err

compare_error_test:
	diff error_tests/v0.1/expected/1.ex     error_tests/v0.1/output/1.out 
	diff error_tests/v0.1/expected/1.ex_err error_tests/v0.1/output/1.out_err
	diff error_tests/v0.1/expected/2.ex     error_tests/v0.1/output/2.out || exit 0    
	diff error_tests/v0.1/expected/2.ex_err error_tests/v0.1/output/2.out_err || exit 0
	diff error_tests/v0.1/expected/3.ex     error_tests/v0.1/output/3.out
	diff error_tests/v0.1/expected/3.ex_err error_tests/v0.1/output/3.out_err
	diff error_tests/v0.1/expected/3b.ex     error_tests/v0.1/output/3b.out
	diff error_tests/v0.1/expected/3b.ex_err error_tests/v0.1/output/3b.out_err
	diff error_tests/v0.1/expected/4.ex     error_tests/v0.1/output/4.out
	diff error_tests/v0.1/expected/4.ex_err error_tests/v0.1/output/4.out_err
#	diff error_tests/v0.2/expected/1.ex     error_tests/v0.2/output/1.out || exit 0
#	diff error_tests/v0.2/expected/1.ex_err error_tests/v0.2/output/1.out_err || exit 0
#	diff error_tests/v0.2/expected/2.ex     error_tests/v0.2/output/2.out || exit 0
#	diff error_tests/v0.2/expected/2.ex_err error_tests/v0.2/output/2.out_err || exit 0
