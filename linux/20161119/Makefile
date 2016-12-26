SRC=test.o max.o min.o
#
#
test:$(SRC)
	@echo "开始编译"
	g++ -o test test.o max.o min.o
	@echo "结束编译"
test.o:test.cpp
	g++ -o test.o -c test.cpp
max.o:max.cpp
	g++ -o max.o -c max.cpp
min.o:min.cpp
	g++ -o min.o -c min.cpp
.PHONY:clean
clean:
	rm *.o test
