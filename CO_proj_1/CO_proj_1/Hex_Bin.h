
#include <iostream>
#include <string>

class Hex_Bin
{
public:

	Hex_Bin();
	std::string bin(std::string hex);
	std::string split(std::string bin);


	int opcode;
	int rs;
	int rt;
	//Register vals
	int rd;
	int shamt;
	int funct;
	//Immediete vals
	int imm;

	~Hex_Bin();
};

