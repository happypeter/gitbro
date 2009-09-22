All:
	g++ -c apple.cpp -o apple.o
	g++ main.cpp -o peterApple -L. apple.o
clean:
	rm -rf apple.o peterApple
