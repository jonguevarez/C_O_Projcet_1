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
		 if (funct == 32) end_str = "add ";
	else if (funct == 36) end_str = "and ";
	else if (funct == 39) end_str = "nor ";
	else if (funct == 37) end_str = "or ";
	else if (funct == 42) end_str = "slt ";
	else if (funct == 43) end_str = "sltu ";
	else if (funct == 00) end_str = "sll ";
	else if (funct == 02) end_str = "srl ";
	else if (funct == 34) end_str = "sub ";
	else if (funct == 35) end_str = "subu ";
	else if (funct == 33) end_str = "addu ";

	end_str = end_str + reggies[rd] + ", ";
	end_str = end_str + reggies[rs] + ", ";
	end_str = end_str + reggies[rt] + " ";
	return end_str;
}

std::string Registers::imm_product(int opcode, int rs, int rt, int imm, int pc)
{
	std::string reggies[] = { "$zero", "$at", "$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2",
						 "$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6",
						 "$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra" };

	std::string end_str = "";

		 if (opcode == 8) end_str = "addi ";
	else if (opcode == 9) end_str = "addiu ";
	else if (opcode == 10) end_str = "slti ";
	else if (opcode == 11) end_str = "sltiu ";
	else if (opcode == 12) end_str = "andi ";
	else if (opcode == 13) end_str = "ori ";
	else if (opcode == 15) end_str = "lui ";
	else if (opcode == 35)
	{

			 end_str = "lw ";
			
			 end_str = end_str + reggies[rt] + ",";
			 end_str = end_str + std::to_string(imm) + "(" + reggies[rs] + ")";

	 }


	else if (opcode == 43)
	{
			 end_str = "sw ";
			 end_str = end_str + reggies[rt] + ",";
			 end_str = end_str + std::to_string(imm) + "(" + reggies[rs] + ")";
	}
	else if (opcode == 4)
	 {
			 end_str = "beq ";
			 end_str = end_str + reggies[rs] + ", ";
			 end_str = end_str + reggies[rt] + ", ";
			 int add = (imm + pc - 1) * 4;
			 if (add < 10) end_str = end_str + "Addr_000" + std::to_string(add);
			 else if (add < 100) end_str = end_str + "Addr_00" + std::to_string(add);
			 else if (add < 1000) end_str = end_str + "Addr_0" + std::to_string(add);
			 else if (add < 10000) end_str = end_str + "Addr_" + std::to_string(add);

	 }
	else if (opcode == 5)
	{
			 end_str = "bne ";
			 end_str = end_str + reggies[rs] + ", ";
			 end_str = end_str + reggies[rt] + ", ";
			 int add = (static_cast<int>(imm) + pc - 1) * 4;
			 if (add < 10) end_str = end_str + "Addr_000" + std::to_string(add);
			 else if (add < 100) end_str = end_str + "Addr_00" + std::to_string(add);
			 else if (add < 1000) end_str = end_str + "Addr_0" + std::to_string(add);
			 else if (add < 10000) end_str = end_str + "Addr_" + std::to_string(add);
	}
		 //maybe add the wierd ones?

		 if (opcode == 5 && opcode == 4 && opcode == 35 && opcode == 43)
		 {
			 end_str = end_str + reggies[rt] + ",";
			 end_str = end_str + reggies[rs] + ",";
			 end_str = end_str + std::to_string(imm);
		 }

	return end_str;
}

std::vector<int> Registers::address_check(int opcode, int rs, int rt, int imm, int pc)
{
	 if (opcode == 4)
	 {
		
		 addresses.push_back(imm+pc);

	 }
	else if (opcode == 5)
	{
		 addresses.push_back(imm+pc);
	}
	 return addresses;
}

Registers::~Registers()
{
}
