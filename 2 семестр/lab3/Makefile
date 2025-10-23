build/my_string.o: src/my_string/my_string.cpp src/my_string/my_string.h
	g++ -g -c -o build/my_string.o src/my_string/my_string.cpp

build/matrix.o: src/matrix/matrix.cpp src/matrix/matrix.h
	g++ -g -c -o build/matrix.o src/matrix/matrix.cpp

build/short_array.o: src/short_array/short_array.cpp src/short_array/short_array.h
	g++ -g -c -o build/short_array.o src/short_array/short_array.cpp

build/base_file.o: src/base_file/base_file.cpp src/base_file/base_file.h
	g++ -g -c -o build/base_file.o src/base_file/base_file.cpp

build/bool_array.o: src/bool_array/bool_array.cpp src/bool_array/bool_array.h
	g++ -g -c -o build/bool_array.o src/bool_array/bool_array.cpp

build/worker_db.o: src/worker_db/worker_db.cpp src/worker_db/worker_db.h
	g++ -g -c -o build/worker_db.o src/worker_db/worker_db.cpp


build/leaks.out: build/matrix.o build/my_string.o build/short_array.o build/base_file.o build/bool_array.o build/worker_db.o src/lab3.cpp
	g++ -g -o build/leaks.out build/matrix.o build/my_string.o build/short_array.o build/base_file.o build/bool_array.o build/worker_db.o src/lab3.cpp -fsanitize=address


leaks: build/leaks.out
	./build/leaks.out