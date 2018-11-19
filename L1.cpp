#include "L1.h"

L1::L1(L2* L2Ptr) {
	this->L2Ptr = L2Ptr;
	Invalidtaions = 0;
	Misses = 0;
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			CacheMatrix[i][j] = new Campo1();

		}
	}
}


void L1::Evict() {
	char InstruType = RcvdLine.at(2);
	for (int i = 0; i < 2; i++)
	{
		if (CacheMatrix[IndexData][i]->LRU == true) {
			CacheMatrix[IndexData][i]->Tag = TagData;
			CacheMatrix[IndexData][i]->DB = 1;
			CacheMatrix[IndexData][i]->Coherence = 1;
			CacheMatrix[IndexData][i]->LRU = false;
			if (i==0) {
				CacheMatrix[IndexData][i + 1]->LRU = true;
			}
			else {
				CacheMatrix[IndexData][i - 1]->LRU = true;
			}
			
		}
	}
}

