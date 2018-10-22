
#include <iostream>
#include <string>
#include <vector>

class Hex_Bin
{
public:

	Hex_Bin();
	std::string bin(std::string hex);
	std::string split(std::string bin, int pc);
	int real_pc = 0;
	void pusher(std::string bin, int pc);

	std::vector<int> real_addresses;
	int show();

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

