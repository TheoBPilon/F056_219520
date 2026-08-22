#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]){
	int x;
	x = std::atoi(argv[1]); // converte o argumento p int e atribui a x

	std::cout <<"Hello world " <<x << std::endl;

	return 0;

}
