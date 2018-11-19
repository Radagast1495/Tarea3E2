using namespace std;
#include <fstream>
#include <iostream>
#include<cstdio>
#include "Wrapper.h"
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
		Wrapper* Test = new Wrapper();
		ifstream Archivo("mcf.trace");
		string Linea;
		while (getline(Archivo, Linea)) {
			Test->LineCount++;
			Test->ReadLine = Linea;
			Test->Compare();
		}
		cout << "Misses p1: " << Test->Proce1->Misses<<"\n";
		cout << "Misses p: " << Test->Proce2->Misses << "\n";

		cout << "Accesses p1: " << Test->Proce1->Accesses << "\n";
		cout << "Accesses p: " << Test->Proce2->Accesses << "\n";

		float MissRate1 = (float) Test->Proce1->Misses /(float) Test->Proce1->Accesses;
		float MissRate2 = (float) Test->Proce2->Misses / (float) Test->Proce2->Accesses;
		float GlobalMissRate = (float) (Test->Proce1->Misses + Test->Proce2->Misses) / (float) Test->LineCount;

		cout << "Local Miss Rate P1: "<< MissRate1<<"\n";
		cout << "Local Miss Rate P2: " << MissRate2 << "\n";
		cout << "Global Miss Rate: " << GlobalMissRate << "\n";

		cout << "Invalidaciones p1: " << Test->Proce1->Invalidtaions << "\n";;
		cout << "Invalidaciones p2: " << Test->Proce2->Invalidtaions << "\n";;

		int x;
		cin >> x;


}
