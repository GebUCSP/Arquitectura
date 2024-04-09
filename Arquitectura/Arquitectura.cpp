#include <iostream>
#include "bitProgram.h"

int main()
{
	bitProgram* program = new bitProgram;

	std::vector<bool>a = { 0,1,0,1};
	std::vector<bool>b = { 0,0,1,0};


	std::vector<bool>rpta = program->BoothAlgorithm();
	//rpta = program->Substraction(a, b);

	std::cout << "La respuesta es: ";
	for (bool i : rpta) {
		std::cout << i;
	}
}

