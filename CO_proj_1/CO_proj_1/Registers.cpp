#include "Registers.h"
#include "Hex_Bin.h"


Registers::Registers()
{
}

std::string Registers::product(int opcode, int rs, int rt, int rd, int shamt, int funct )
{
	std::string reggies[] = {"$zero", "$at", "$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2",
							 "$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6",
							 "$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra" };
	
	std::string end_str = "";
		 if (funct = 32) end_str = "add ";
	else if (funct = 36) end_str = "and ";
	else if (funct = 39) end_str = "nor ";
	else if (funct = 37) end_str = "or ";
	else if (funct = 42) end_str = "slt ";
	else if (funct = 43) end_str = "sltu ";
	else if (funct = 00) end_str = "sll ";
	else if (funct = 02) end_str = "srl ";
	else if (funct = 34) end_str = "sub ";
	else if (funct = 35) end_str = "subu ";
	else if (funct = 34) end_str = "addu ";

	end_str = end_str + reggies[rd] + ", ";
	end_str = end_str + reggies[rs] + ", ";
	end_str = end_str + reggies[rt] + " ";
	return end_str;
}
Registers::~Registers()
{
}
