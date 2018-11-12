#pragma once
#include <string>
#include "Campo1.h"
#include "L2.h"

using namespace std;

class L1 {
	public:
		L1();
		~L1();
		int LineAmount = 250;
		int Asso=2;
		int TagSize = 19;
		int IndexSize = 8;
		int OffsetSize = 5;
		int TagData;
		int IndexData;
		int OffsetData;
		int Misses;
		int TotalInstr;
		int Invalidtaions;
		char InstruType;
		int Origin;
		string RcvdLine;
		Campo1* CacheMatrix[250][2];
		L2* L2Ptr;

		void CacheCheck();
		void L2Check();
		void Evict();




};