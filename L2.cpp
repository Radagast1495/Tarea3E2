#include "L2.h"
#include <bitset>
#include <sstream>


L2::L2() {
	for (int i = 0; i < 4096; i++)
	{
		CacheMatrix[i] = new Campo2();

	}
}

bool L2::L2Check() {
	char InstruType = RcvdLine.at(2);
	/*int OffsetData, IndexData, TagData;
	string OnlyInstru = RcvdLine.substr(4, 8);
	stringstream ss;
	ss << hex << OnlyInstru;
	unsigned n;
	ss >> n;
	bitset<32> Converted(n);
	bitset<32> OffMask(string("00000000000000000000000000011111"));
	bitset<32> OD = Converted & OffMask;
	bitset<32> TagMask(string("11111111111111100000000000000000"));
	bitset<32> TD = Converted & TagMask;
	TD >>= 13;
	bitset<32> IndexMask(string("00000000000000011111111111100000"));
	bitset<32> ID = Converted & IndexMask;
	ID >>= 5;
	OffsetData = OD.to_ulong();
	IndexData = ID.to_ulong();
	TagData = TD.to_ulong();*/

	int IndexData, TagData, OffsetData;
	string OnlyInstru = RcvdLine.substr(4, 8);
	long long int IOI = stoi(OnlyInstru, 0, 16);
	int TagMask, IndexMask, OffsetMask;
	TagMask = 4294836224;
	IndexMask = 131040;
	OffsetMask = 31;
	TagData = IOI & TagMask;
	TagData >>= 13;
	IndexData = IOI & IndexMask;
	IndexData >>= 5;
	OffsetData = IOI & OffsetMask;

	if (InstruType == '0') {
		if (CacheMatrix[IndexData]->Tag == TagData) {
			return true;
		}
		else{
			return false;
		}
	}
	else {
		if (CacheMatrix[IndexData]->Tag == TagData) {
			return true;
		}
		else {
			CacheMatrix[IndexData]->Tag = TagData;
			return false;
		}
	}


}