#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "dopF.h"
#include "math/transp.h"
#include "math/det.h"
#include <boost/program_options.hpp>

using namespace std;

int main(int argc, const char *argv[])
{
	setlocale(LC_ALL, "rus");
	using namespace boost::program_options;

	double **A=0;

	string fileNameA;
	int act = 0;
	int nA=0, mA=0;
	try//������ ����� ��������� ������
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Help screen")
			("action", value<string>(),"������� ����������������� �������, ���� action=transp. ������� ������������, ���� action=det")
			("fileA", value<string>(), "File name A")//���� � �������� �
			("inputA",  "Input A")//���� �
			("nA", value<int>(), "Input n A")//nA
			("mA", value<int>(), "Input m A");//mA

		variables_map vm;

		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);
		if (vm.count("help")){
			std::cout << desc << '\n';
			return 0;
		}

		if (vm.count("inputA"))
		{
			cout << "\n������� ������� A:";
			nA = vm["nA"].as<int>();
			mA = vm["mA"].as<int>();
			A = inputM(nA, mA);
		}
		else if (vm.count("fileA")) {
			fileNameA= vm["fileA"].as<string>();
			nA = vm["nA"].as<int>();
			mA = vm["mA"].as<int>();
			A=inputFM(fileNameA, nA, mA);
		} 
		
		if (vm.count("action"))
		{
			string action = vm["action"].as<string>();
			if (action == "transp")
				act = 0;
			else if (action == "det")
				act = 1;
		}
	}
	catch (const error& ex)
	{
		std::cerr << ex.what() << '\n';
	}

	if (A == 0) {
		cout << "\n������� �� �������!\n";
		return 1;
	}
	else if (nA == 0 || mA == 0) {
		cout << "\n������� ������� �� �������!\n";
		return 1;
	}

	cout << endl;
	cout << "������� A:" << endl;
	outputM(A, nA, mA);


	int nC=0, mC=0;
	double** C = 0;
	double d = 0;
	if (act == 0) {
		C = transp(A, nA, mA, nC, mC);
		cout << "����������������� ������� A:" << endl;
	    outputM(C, nC, mC);
	}
	else if (act == 1) {
		d = det(A, nA, mA);
		cout<<"������������ ������� A = "<<d<<endl;
	}



	deleteM(A, nA, mA);
	deleteM(C, nC, mC);
}
