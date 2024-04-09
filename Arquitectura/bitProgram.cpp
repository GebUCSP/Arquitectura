#include "bitProgram.h"

std::vector<bool> bitProgram::DecToBin(int decimal) {
	std::vector<bool>tempVect;

	bool signo = !(decimal > 0);

	while (decimal) {
		tempVect.insert(tempVect.begin(), decimal % 2);
		decimal /= 2;
	}

	return tempVect;
}

std::vector<bool> bitProgram::Add(std::vector<bool> a, std::vector<bool> b)
{
	int size = a.size() > b.size() ? a.size() : b.size();
	int carry = 0;
	std::vector<bool>rpta;

	for (int i = a.size(); i < size; i++) {
		a.insert(a.begin(), 0);
	}
	for (int i = b.size(); i < size; i++) {
		b.insert(b.begin(), 0);
	}

	for (int i{ 0 }; i < size; i++) {
		int accumulated = a[size-1-i] + b[size-1-i] + carry;

		switch (accumulated)
		{
		case 3:
			carry = 1;
			rpta.insert(rpta.begin(),1);
			break;
		case 2:
			carry = 1;
			rpta.insert(rpta.begin(), 0);
			break;
		case 1:
			carry = 0;
			rpta.insert(rpta.begin(), 1);
			break;
		case 0:
			carry = 0;
			rpta.insert(rpta.begin(), 0);
			break;
		default:
			break;
		}

	}



	return rpta;
}

std::vector<bool> bitProgram::Subtraction(std::vector<bool>a, std::vector<bool>b)
{
	return Add(a, TwoComplement(b));
}

std::vector<bool> bitProgram::TwoComplement(std::vector<bool> input)
{
	input.flip();
	std::vector<bool>uno(input.size());
	uno[uno.size() - 1] = 1;
	std::vector<bool>rpta = Add(input, uno);
	
	return rpta;
}


std::vector<bool> bitProgram::BoothAlgorithm()
{
	int n;
	std::cout << "Introduzca la longitud de los numeros binarios: ";
	std::cin >> n;
	
	std::vector<bool>M;
	std::vector<bool>Q;
	std::vector<bool>A(n);
	int q_1{0};

	std::cout << "Tomando en cuenta la longitud introducida. Se repetira si no es correcta." << std::endl;
	while (Q.size() != n) {
		Q.clear();
		std::string temp;
		std::cout << "Introduzca el numero binario MULTIPLICANDO: ";
		std::cin >> temp;
		for (int i = 0; i < temp.size(); i++) {
			Q.push_back(temp[i] == '1' ? 1 : 0);
		}
	}

	while (M.size() != n) {
		M.clear();
		std::string temp;
		std::cout << "Introduzca el numero binario MULTIPLICADOR: ";
		std::cin >> temp;
		for (int i = 0; i < temp.size(); i++) {
			M.push_back(temp[i] == '1' ? 1 : 0);
		}
	}


	while (n != 0)
	{
		if (Q[Q.size() - 1] && !q_1) {
			A = Subtraction(A, M);
		}
		else if (!(Q[Q.size() - 1]) && q_1) {
			A = Add(A, M);

		}


		std::vector<bool>newVector = {A[0]};
		for (int i = 0; i < A.size() - 1; i++) {
			newVector.push_back(A[i]);
		}

		bool lastA = A[A.size() - 1];
		Q.insert(Q.begin(), lastA);
		q_1 = Q[Q.size() - 1];
		Q.pop_back();
		A = newVector;
		n--;
	}

	for (int i = 0; i < Q.size();i++) {
		A.push_back(Q[i]);
	}

	return A;
}
