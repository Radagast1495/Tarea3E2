#pragma once
#include "L1.h"
#include "L2.h"

class Wrapper {
	public:
		Wrapper();

		int LineCount;
		L1 Proce1;
		L1 Proce2;
		L2 SharedCache;
		string ReadLine;
		void Compare();

		void SendLine(string Linea);

};