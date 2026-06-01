.PHONY: all clean run

all:
	cmake -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build

run: all
	./build/snype

clean:
	rm -rf build/
