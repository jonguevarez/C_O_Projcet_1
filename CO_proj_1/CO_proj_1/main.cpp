#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <vector>
#include "Registers.h"
#include "Hex_Bin.h"


using namespace std;

int main()
{
	Hex_Bin a;
	int o;
	vector<string> input_lines;
	vector<int> past_addr;
	
	//opening file to extract
	ifstream in;
	ofstream out("test_case1.s");
	in.open("test_case1.obj");
	//out.open("test_case1.s");
	string hex;
	string _binary;
	while (getline(in, hex, '\n'))
	{
		_binary = a.bin(hex);
		input_lines.push_back(_binary);
	}
	cout << input_lines.back() << endl;
	cout << input_lines.size() << endl;
	cout << input_lines[3] << endl;
	int pc = 0;
	int counter = 0;
	std::string acup;
	while (pc < input_lines.size())
	{
		
		a.pusher(input_lines[pc],pc);
		
		//if (a.opcode != 43 && a.opcode != 35)
			//counter++;
		// acup = a.split(input_lines[pc],pc);
		// out << acup << endl;

		pc++;
	}
	pc = 0;
	while (pc < input_lines.size())
	{

		//a.pusher(input_lines[pc], pc);

		//if (a.opcode != 43 && a.opcode != 35)
			//counter++;
		if (past_addr.empty() == true)
		{
			int pct = pc * 4;

			if (pc < 10) out << "Addr_000" + std::to_string(pct) + ":" << endl;
			else if (pc < 100) out << "Addr_00" + std::to_string(pct) + ":" << endl;
			else if (pc < 1000) out << "Addr_0" + std::to_string(pct) + ":" << endl;
			else if (pc < 10000) out << "Addr_" + std::to_string(pct) + ":" << endl;

			if (pc < 10) cout << "Addr_000" + std::to_string(pct) + ":" << endl;
			else if (pc < 100) cout << "Addr_00" + std::to_string(pct) + ":" << endl;
			else if (pc < 1000) cout << "Addr_0" + std::to_string(pct) + ":" << endl;
			else if (pc < 10000) cout << "Addr_" + std::to_string(pct) + ":" << endl;
			past_addr.push_back(a.real_addresses.back());
			a.real_addresses.pop_back();

		}
		else if (a.real_addresses.empty() == true)
		{

		}
		else
		{
			for (size_t i = 0; i < past_addr.size(); i++)
			{
					if (past_addr[i] == a.real_addresses.back())
					{
						a.real_addresses.pop_back();
						break;
					}
				
				
			
			}
			if (a.real_addresses.back() == pc)
			{
				int pct = pc * 4;

				if (pc < 10) out <<  "Addr_000" + std::to_string(pct) + ":" << endl;
				else if (pc < 100) out << "Addr_00" + std::to_string(pct) + ":" << endl;
				else if (pc < 1000) out <<  "Addr_0" + std::to_string(pct) + ":" << endl;
				else if (pc < 10000) out <<  "Addr_" + std::to_string(pct) + ":" << endl;

				if (pc < 10) cout << "Addr_000" + std::to_string(pct) + ":" << endl;
				else if (pc < 100) cout << "Addr_00" + std::to_string(pct) + ":" << endl;
				else if (pc < 1000) cout << "Addr_0" + std::to_string(pct) + ":" << endl;
				else if (pc < 10000) cout << "Addr_" + std::to_string(pct) + ":" << endl;
				past_addr.push_back(a.real_addresses.back());
				a.real_addresses.pop_back();
			}
		}

		acup = a.split(input_lines[pc], pc);
		out << acup << endl;
		cout << acup << endl;
  		pc++;
	}

	cout << a.real_addresses.size() << endl;
	string bin = a.bin(hex);
 	std::string fina = a.split(bin,counter);
	cout << hex << endl;
	cout << fina << endl;
	cout << bin << endl;
	cout << "Hello World" << endl;
	cin >> o;
	return 0;

}