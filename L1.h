#pragma once
#include <string>
#include "Campo1.h"
#include "L2.h"

using namespace std;

class L1 {
	public:
		L1(L2* L2Ptr);
		~L1();
		int LineAmount = 250;
		int Asso=2;
		int TagSize = 19;
		int IndexSize = 8;
		int OffsetSize = 5;
		int Misses;
		int TagData;
		int IndexData;
		int OffsetData;
		int TotalInstr;
		int Invalidtaions;
		int Accesses;
		char InstruType;
		int Origin;
		string RcvdLine;
		Campo1* CacheMatrix[256][2];
		L2* L2Ptr;
		void Evict();




};