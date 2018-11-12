#include "L1.h"

L1::L1() {
	IndexData = 0;
	TagData = 0;
	OffsetData = 0;
	for (int i = 0; i < 250; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			CacheMatrix[i][j] = new Campo1();
		}
	}
}

void L1::CacheCheck() {
	string OnlyInstru = RcvdLine.substr(4, 8);
	string OD=OnlyInstru.substr(27,5);
	string ID=OnlyInstru.substr(19,8);
	string TD=OnlyInstru.substr(0,19);
	OffsetData = stoi(OD, 0, 16);
	IndexData = stoi(ID, 0, 16);
	TagData = stoi(TD, 0, 16);

	bool LoadHit = false;
	bool StoreHit = false;

	if (InstruType == '0') {
		for (int i = 0; i < Asso; i++)
		{
			if (CacheMatrix[IndexData][i]->Tag == TagData) {
				LoadHit=true;
				CacheMatrix[IndexData][i]->DB = 0;
				CacheMatrix[IndexData][i]->LRU = false;
				if (i == 0) {
					CacheMatrix[IndexData][i+1]->LRU = true;
				}
				else {
					CacheMatrix[IndexData][i-1]->LRU = true;
				}
			}
		}
		if (!LoadHit) {
			L2Check();
		}
	}
	else if (InstruType == '1') {
		int Freespace = 2;
		for (int i = 0; i < Asso; i++)
		{
			if (CacheMatrix[IndexData][i]->Tag == TagData) {
				StoreHit=true;
				CacheMatrix[IndexData][i]->LRU = false;
				CacheMatrix[IndexData][i]->DB = 1;
				if (i == 0) {
					CacheMatrix[IndexData][i + 1]->LRU = true;
				}
				else {
					CacheMatrix[IndexData][i - 1]->LRU = true;
				}
			}
			else {
				if (CacheMatrix[IndexData][i]->Tag == 0) {
					Freespace = i;
				}
			}
		}
		if (!LoadHit) {
			if (Freespace != 2) {
				CacheMatrix[IndexData][Freespace]->Tag = TagData;
				CacheMatrix[IndexData][Freespace]->DB = 1;
				CacheMatrix[IndexData][Freespace]->LRU = false;
			}
			else {
				L2Ptr->RcvdLine = RcvdLine;
				L2Check();
			}
		}
	}

	
}