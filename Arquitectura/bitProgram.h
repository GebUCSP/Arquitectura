#pragma once

#include <vector>
#include <iostream>

class bitProgram
{
public:
	std::vector<bool> DecToBin(int);
	std::vector<bool> Add(std::vector<bool>,std::vector<bool>);
	std::vector<bool> Subtraction(std::vector<bool>, std::vector<bool>);
	std::vector<bool> TwoComplement(const std::vector<bool>);
	std::vector<bool> BoothAlgorithm();
};

