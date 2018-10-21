#include <iostream>
#include <string>

class Registers
{
public:
	Registers();
	std::string product(int opcode, int rs, int rt, int rd, int shamt, int fucnt);
	
	~Registers();
};

