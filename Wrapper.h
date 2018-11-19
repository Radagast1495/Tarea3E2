#pragma once
#include "L1.h"
#include "L2.h"

class Wrapper {
	public:
		Wrapper();

		int LineCount;
		void CacheCheck();
		void CheckProce2OnRead(int E2, int i, int IndexData, int HitCol2);
		void CheckProce2OnWrite(int E2, int i, int IndexData, int HitCol2);
		void CheckProce1OnRead(int E1, int i, int IndexData, int HitCol1);
		void CheckProce1OnWrite(int E1, int i, int IndexData, int HitCol1);
		L1* Proce1;
		L1* Proce2;
		L2* SharedCache;
		string ReadLine;
		void Compare();
		

};