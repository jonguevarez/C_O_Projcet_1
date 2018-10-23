#include <iostream>
#include <string>
#include <vector>

class Registers
{
public:
	Registers();
	std::string product(int opcode, int rs, int rt, int rd, int shamt, int fucnt);
	std::string imm_product(int opcode, int rs, int rt, int imm, int pc);
	int address_check(int opcode, int rs, int rt, int imm, int pc);
	
	std::vector<int> addresses;
	~Registers();
};

