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
	//opening file to extract
	ifstream in;
	in.open("test_case1.obj");
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
		
		a.pusher(input_lines[pc],counter);
		//if (a.opcode != 43 && a.opcode != 35)
			//counter++;
		 acup = a.split(input_lines[pc],counter);
		

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