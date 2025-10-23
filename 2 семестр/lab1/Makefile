build/rect.o: src/rect/rect.cpp src/rect/rect.h
	g++ -g -c -o build/rect.o src/rect/rect.cpp

build/barrel.o: src/barrel/barrel.cpp src/barrel/barrel.h
	g++ -g -c -o build/barrel.o src/barrel/barrel.cpp

build/my_string.o: src/my_string/my_string.cpp src/my_string/my_string.h
	g++ -g -c -o build/my_string.o src/my_string/my_string.cpp

build/text_wrapper.o: src/text_wrapper/text_wrapper.cpp src/text_wrapper/text_wrapper.h
	g++ -g -c -o build/text_wrapper.o src/text_wrapper/text_wrapper.cpp

build/debug.out: build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o src/main.cpp
	g++ -g -o build/debug.out src/main.cpp build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o


build/leaks.out: build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o src/main.cpp
	g++ -g -o build/leaks.out src/main.cpp build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o -fsanitize=address


#Tests

build/test_rect_basic_methods.out: tests/test_rect_basic_methods.cpp build/rect.o
	g++ -g -o build/test_rect_basic_methods.out tests/test_rect_basic_methods.cpp build/rect.o

build/test_rect_properties.out: tests/test_rect_properties.cpp build/rect.o
	g++ -g -o build/test_rect_properties.out tests/test_rect_properties.cpp build/rect.o

build/test_rect_operations.out: tests/test_rect_operations.cpp build/rect.o
	g++ -g -o build/test_rect_operations.out tests/test_rect_operations.cpp build/rect.o

build/test_bounding_rect.out: tests/test_bounding_rect.cpp build/rect.o
	g++ -g -o build/test_bounding_rect.out tests/test_bounding_rect.cpp build/rect.o




#Labels
test: build/test_rect_basic_methods.out build/test_rect_operations.out build/test_rect_properties.out build/test_bounding_rect.out
	./build/test_rect_basic_methods.out
	./build/test_rect_properties.out
	./build/test_rect_operations.out
	./build/test_bounding_rect.out

leaks: build/leaks.out
	./build/leaks.out
 
debug: build/debug.out
	./build/debug.out
