#include "Hex_Bin.h"
#include "Registers.h"


Hex_Bin::Hex_Bin()
{
	 opcode =-1;
	 rs = -1;
	 rt = -1;
	//Register vals
	 rd = -1;
	 shamt = -1;
	 funct = -1;
	//Immediete vals
	 imm = -1;
}
std::string Hex_Bin::bin(std::string hex)
{

	char use;
	std::string add_str;
	std::string end_str = "";
	for (size_t i = 0; i < hex.length(); i++)
	{
		use = hex[i];
		switch (toupper(use)) //hex translation
		{
		case '0': add_str = "0000";
			break;
		case '1': add_str = "0001";
			break;
		case '2': add_str = "0010";
			break;
		case '3': add_str = "0011";
			break;
		case '4': add_str = "0100";
			break;
		case '5': add_str = "0101";
			break;
		case '6': add_str = "0110";
			break;
		case '7': add_str = "0111";
			break;
		case '8': add_str = "1000";
			break;
		case '9': add_str = "1001";
			break;
		case 'A': add_str = "1010";
			break;
		case 'B': add_str = "1011";
			break;
		case 'C': add_str = "1100";
			break;
		case 'D': add_str = "1101";
			break;
		case 'E': add_str = "1110";
			break;
		case 'F': add_str = "1111";
			break;
		}
		end_str = end_str + add_str;
	}
	return end_str;
	

}
std::string Hex_Bin::split(std::string bin, int pc)
{
	Registers reg;

	//get opcode first to get things right
	std::string one = bin.substr(0, 4);
	//std::string two = bin.substr(4,4);

	std::string two_half = bin.substr(4, 2);
	std::string _opcode = one + two_half;

	const char *nummer = _opcode.c_str();
	 int opcode = strtol(nummer, NULL, 2);
	 //rs
	 std::string _rs = bin.substr(6, 5);
	 nummer = _rs.c_str();
	 rs = strtol(nummer, NULL, 2);
	 //rt
	 std::string _rt = bin.substr(11, 5);
	 nummer = _rt.c_str();
	 rt = strtol(nummer, NULL, 2);
	 
	
	if (opcode == 0)
	{
		//register stuff

		//rd
		std::string _rd = bin.substr(16, 5);
		nummer = _rd.c_str();
		rd = strtol(nummer, NULL, 2);
		//shamt
		std::string _shamt = bin.substr(21, 5);
		nummer = _shamt.c_str();
		shamt = strtol(nummer, NULL, 2);
		//funct
		std::string _funct = bin.substr(26, 6);
		nummer = _funct.c_str();
		funct = strtol(nummer, NULL, 2);
		std::string end = reg.product(opcode, rs, rt, rd, shamt, funct);
		real_pc++;
		return end;

	}
	else
	{
		//immediete stuff including bne's 
		std::string _imm = bin.substr(16, 16);
		nummer = _imm.c_str();
		imm = strtol(nummer, NULL, 2);
		std::string end_in = reg.imm_product(opcode, rs, rt, imm,real_pc);
		//if (opcode != 43 && opcode != 35)
			real_pc++;
		return end_in;

	}


}

void Hex_Bin::pusher(std::string bin, int pc)
{
	Registers reg;

	//get opcode first to get things right
	std::string one = bin.substr(0, 4);
	//std::string two = bin.substr(4,4);

	std::string two_half = bin.substr(4, 2);
	std::string _opcode = one + two_half;

	const char *nummer = _opcode.c_str();
	int opcode = strtol(nummer, NULL, 2);
	//rs
	std::string _rs = bin.substr(6, 5);
	nummer = _rs.c_str();
	rs = strtol(nummer, NULL, 2);
	//rt
	std::string _rt = bin.substr(11, 5);
	nummer = _rt.c_str();
	rt = strtol(nummer, NULL, 2);

	if (opcode == 0)
	{

	}
	else
	{
		std::string _imm = bin.substr(16, 16);
		nummer = _imm.c_str();
		imm = strtol(nummer, NULL, 2);
		if(opcode == 5 || opcode == 4)
		real_addresses.push_back( reg.address_check(opcode, rs, rt, imm, pc));
		//std::string end_in = reg.imm_product(opcode, rs, rt, imm);
	}
}
int Hex_Bin::show()
{
	int a=0;

	return a;
	
}
Hex_Bin::~Hex_Bin()
{
}
