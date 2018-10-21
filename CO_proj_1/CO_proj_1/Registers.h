#include <iostream>
#include <string>
#include <vector>

class Registers
{
public:
	Registers();
	std::string product(int opcode, int rs, int rt, int rd, int shamt, int fucnt);
	std::string imm_product(int opcode, int rs, int rt, int imm);
	void address_check(int opcode, int rs, int rt, int imm);
	
	std::vector<int> addresses;
	~Registers();
};

