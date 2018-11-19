#include "Wrapper.h"
#include <bitset>
#include <sstream>


Wrapper::Wrapper() {
	LineCount = 0;

	SharedCache = new L2();
	Proce1 = new L1(SharedCache);
	Proce2 = new L1(SharedCache);
}

void Wrapper::CheckProce2OnRead(int E2, int i, int IndexData, int HitCol2) {

	switch (Proce1->CacheMatrix[IndexData][i]->Coherence) {
	case 1:
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;

	case 2:
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			Proce1->CacheMatrix[IndexData][i]->Tag = Proce2->CacheMatrix[IndexData][HitCol2]->Tag;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;
	case 3:
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			Proce1->CacheMatrix[IndexData][i]->Tag = Proce2->CacheMatrix[IndexData][HitCol2]->Tag;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			Proce1->CacheMatrix[IndexData][i]->Coherence = 2;
			break;
		}
		break;
	case 4:
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][i]->Coherence = 3;
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			Proce1->CacheMatrix[IndexData][i]->Tag = Proce2->CacheMatrix[IndexData][HitCol2]->Tag;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][i]->Coherence = 3;
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			Proce1->CacheMatrix[IndexData][i]->Coherence = 3;
			break;
			//Proce2 en Invalid
		case 4:
			Proce1->CacheMatrix[IndexData][i]->Coherence = 2;
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}
		break;

	}

}

void Wrapper::CheckProce2OnWrite(int E2, int i, int IndexData, int HitCol2) {


	switch (Proce1->CacheMatrix[IndexData][i]->Coherence) {
	case 1:
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;

	case 2:
		Proce1->CacheMatrix[IndexData][i]->Coherence = 1;
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;
	case 3:
		Proce1->CacheMatrix[IndexData][i]->Coherence = 1;
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}
		break;
	case 4:
		Proce1->CacheMatrix[IndexData][i]->Coherence = 1;
		switch (E2) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce2->CacheMatrix[IndexData][HitCol2]->Coherence = 4;
			Proce2->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}
		break;

	}

}

void Wrapper::CheckProce1OnRead(int E1, int i, int IndexData, int HitCol1) {

	switch (Proce2->CacheMatrix[IndexData][i]->Coherence) {
	case 1:
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;

	case 2:
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			Proce2->CacheMatrix[IndexData][i]->Tag = Proce1->CacheMatrix[IndexData][HitCol1]->Tag;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;
	case 3:
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			Proce2->CacheMatrix[IndexData][i]->Tag = Proce1->CacheMatrix[IndexData][HitCol1]->Tag;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			Proce2->CacheMatrix[IndexData][i]->Coherence = 2;
			break;
		}
		break;
	case 4:
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce2->CacheMatrix[IndexData][i]->Coherence = 3;
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			Proce2->CacheMatrix[IndexData][i]->Tag = Proce1->CacheMatrix[IndexData][HitCol1]->Tag;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce2->CacheMatrix[IndexData][i]->Coherence = 3;
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 3;
			break;
			//Proce2 En shared
		case 3:
			Proce2->CacheMatrix[IndexData][i]->Coherence = 3;
			break;
			//Proce2 en Invalid
		case 4:
			Proce2->CacheMatrix[IndexData][i]->Coherence = 2;
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}
		break;

	}

}
void Wrapper::CheckProce1OnWrite(int E1, int i, int IndexData, int HitCol1) {


	switch (Proce1->CacheMatrix[IndexData][i]->Coherence) {
	case 1:
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;

	case 2:
		Proce2->CacheMatrix[IndexData][i]->Coherence = 1;
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}

		break;
	case 3:
		Proce1->CacheMatrix[IndexData][i]->Coherence = 1;
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}
		break;
	case 4:
		Proce2->CacheMatrix[IndexData][i]->Coherence = 1;
		switch (E1) {
			//Proce2 en Modified
		case 1:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Exclusive
		case 2:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 En shared
		case 3:
			Proce1->CacheMatrix[IndexData][HitCol1]->Coherence = 4;
			Proce1->Invalidtaions++;
			break;
			//Proce2 en Invalid
		case 4:
			break;
			//Proce2 no tiene el bloque
		case 5:
			break;
		}
		break;

	}
}



void Wrapper::Compare() {
	char InstruType = ReadLine.at(2);
	/*int OffsetData, IndexData, TagData;
	string OnlyInstru = ReadLine.substr(4, 8);
	stringstream ss;
	ss << hex << OnlyInstru;
	unsigned n;
	ss >> n;
	bitset<32> Converted(n);
	bitset<32> OffMask(string("00000000000000000000000000011111"));
	bitset<32> OD=Converted&OffMask;
	bitset<32> TagMask(string("11111111111111111110000000000000"));
	bitset<32> TD = Converted & TagMask;
	TD >>= 13;
	bitset<32> IndexMask(string("00000000000000000001111111100000"));
	bitset<32> ID = Converted & IndexMask;
	ID >>= 5;
	OffsetData = OD.to_ulong();
	IndexData = ID.to_ulong();
	TagData = TD.to_ulong();
	Proce1->IndexData = IndexData;
	Proce1->OffsetData = OffsetData;
	Proce1->TagData = TagData;
	Proce2->IndexData = IndexData;
	Proce2->OffsetData = OffsetData;
	Proce2->TagData = TagData;
	Proce1->RcvdLine = ReadLine;
	Proce2->RcvdLine = ReadLine;*/


	int IndexData, TagData, OffsetData;
	string OnlyInstru = ReadLine.substr(4, 8);
	long long int IOI = stoi(OnlyInstru, 0, 16);
	int TagMask, IndexMask, OffsetMask;
	TagMask = 4294959104;
	IndexMask = 8160;
	OffsetMask = 31;
	TagData = IOI & TagMask;
	TagData >>= 13;
	IndexData = IOI & IndexMask;
	IndexData >>= 5;
	OffsetData = IOI & OffsetMask;
	Proce1->IndexData = IndexData;
	Proce1->OffsetData = OffsetData;
	Proce1->TagData = TagData;
	Proce2->IndexData = IndexData;
	Proce2->OffsetData = OffsetData;
	Proce2->TagData = TagData;
	Proce1->RcvdLine = ReadLine;
	Proce2->RcvdLine = ReadLine;






	bool LoadHit = false;
	bool StoreHit = false;

	//Instrucción de proce1
	if (LineCount % 4 == 0) {
		Proce1->Accesses++;
		int E2,HitCol2=2;

		for (int i = 0; i < 2; i++)
		{
			if (Proce2->CacheMatrix[IndexData][i]->Tag == TagData) {
				E2 = Proce2->CacheMatrix[IndexData][i]->Coherence;
				HitCol2 = i;
			}
		}
		//No se encontro el bloque en la cache2
		if (HitCol2 == 2) {
			E2 = 5;
		}
		if (InstruType == '0') {
			for (int i = 0; i < 2; i++)
			{
				if (Proce1->CacheMatrix[IndexData][i]->Tag == TagData) {
					LoadHit = true;
					Proce1->CacheMatrix[IndexData][i]->DB = 0;
					Proce1->CacheMatrix[IndexData][i]->LRU = false;
					CheckProce2OnRead(E2,i,IndexData,HitCol2);
					if (i == 0) {
						Proce1->CacheMatrix[IndexData][i + 1]->LRU = true;
					}
					else {
						Proce1->CacheMatrix[IndexData][i - 1]->LRU = true;
					}
					break;
				}
			}
			if (!LoadHit) {
				SharedCache->RcvdLine = ReadLine;
				bool ReadHit=SharedCache->L2Check();
				if (ReadHit == false) {
					Proce1->Misses++;
				}
				else {
					Proce1->Evict();
					for (int i = 0; i < 2; i++)
					{
						if (Proce1->CacheMatrix[IndexData][i]->Tag == TagData) {
							CheckProce2OnRead(E2, i, IndexData, HitCol2);
						}
					}
				}
			}
		}
		else {
			int Freespace = 2;
			int CheckHit = 2;
			for (int i = 0; i < 2; i++)
			{
				if (Proce1->CacheMatrix[IndexData][i]->Tag == TagData) {
					StoreHit = true;
					Proce1->CacheMatrix[IndexData][i]->LRU = false;
					Proce1->CacheMatrix[IndexData][i]->Coherence = 1;
					Proce1->CacheMatrix[IndexData][i]->DB = 1;
					if (i == 0) {
						Proce1->CacheMatrix[IndexData][i + 1]->LRU = true;
					}
					else {
						Proce1->CacheMatrix[IndexData][i - 1]->LRU = true;
					}
					CheckProce2OnWrite(E2,i,IndexData,HitCol2);
				}
				else {
					if (Proce1->CacheMatrix[IndexData][i]->Tag == 0) {
						Freespace = i;
					}
				}
			}
			if (!StoreHit) {
				
				if (Freespace != 2) {
					Proce1->CacheMatrix[IndexData][Freespace]->Tag = TagData;
					Proce1->CacheMatrix[IndexData][Freespace]->DB = 1;
					Proce1->CacheMatrix[IndexData][Freespace]->Coherence = 1;
					Proce1->CacheMatrix[IndexData][Freespace]->LRU = false;
					CheckProce2OnWrite(E2, Freespace, IndexData, HitCol2);
					if (Freespace == 0) {
						Proce1->CacheMatrix[IndexData][Freespace + 1]->LRU = true;
					}
					else {
						Proce1->CacheMatrix[IndexData][Freespace - 1]->LRU = true;
					}
				}
				else {
					SharedCache->RcvdLine = ReadLine;
					bool WriteHit=SharedCache->L2Check();
					if (WriteHit == false) {
						Proce1->Evict();
						Proce1->Misses++;
						for (int i = 0; i < 2; i++)
						{
							if (Proce1->CacheMatrix[IndexData][i]->Tag == TagData) {
								CheckProce2OnWrite(E2, i, IndexData, HitCol2);
							}
						}
					}
					else {
						Proce1->Evict();
						for (int i = 0; i < 2; i++)
						{
							if (Proce1->CacheMatrix[IndexData][i]->Tag == TagData) {
								CheckProce2OnWrite(E2, i, IndexData, HitCol2);
							}
						}
					}
				}
			}
		}

	}

	//Instrucción de proce2
	else {
		Proce2->Accesses++;
		int E1, HitCol1 = 2;
		for (int i = 0; i < 2; i++)
		{
			if (Proce1->CacheMatrix[IndexData][i]->Tag == TagData) {
				E1 = Proce1->CacheMatrix[IndexData][i]->Coherence;
				HitCol1 = i;
			}
		}
		//No se encontro el bloque en la cache2
		if (HitCol1 == 2) {
			E1 = 5;
		}
		if (InstruType == '0') {
			for (int i = 0; i < 2; i++)
			{
				if (Proce2->CacheMatrix[IndexData][i]->Tag == TagData) {
					LoadHit = true;
					Proce2->CacheMatrix[IndexData][i]->DB = 0;
					Proce2->CacheMatrix[IndexData][i]->LRU = false;
					CheckProce1OnRead(E1, i, IndexData, HitCol1);
					if (i == 0) {
						Proce2->CacheMatrix[IndexData][i + 1]->LRU = true;
					}
					else {
						Proce2->CacheMatrix[IndexData][i - 1]->LRU = true;
					}
				}
			}
			if (!LoadHit) {
				SharedCache->RcvdLine = ReadLine;
				bool ReadHit = SharedCache->L2Check();
				if (ReadHit == false) {
					Proce2->Misses++;
				}
				else {
					Proce2->Evict();
					for (int i = 0; i < 2; i++)
					{
						if (Proce2->CacheMatrix[IndexData][i]->Tag == TagData) {
							CheckProce1OnRead(E1, i, IndexData, HitCol1);
						}
					}
				}
			}
		}
		else {
			int Freespace = 2;
			int CheckHit = 2;
			for (int i = 0; i < 2; i++)
			{
				if (Proce2->CacheMatrix[IndexData][i]->Tag == TagData) {
					StoreHit = true;
					Proce2->CacheMatrix[IndexData][i]->LRU = false;
					Proce2->CacheMatrix[IndexData][i]->Coherence = 1;
					Proce2->CacheMatrix[IndexData][i]->DB = 1;
					if (i == 0) {
						Proce2->CacheMatrix[IndexData][i + 1]->LRU = true;
					}
					else {
						Proce2->CacheMatrix[IndexData][i - 1]->LRU = true;
					}
					CheckProce1OnWrite(E1, i, IndexData, HitCol1);
				}
				else {
					if (Proce2->CacheMatrix[IndexData][i]->Tag == 0) {
						Freespace = i;
					}
				}
			}
			if (!StoreHit) {

				if (Freespace != 2) {
					Proce2->CacheMatrix[IndexData][Freespace]->Tag = TagData;
					Proce2->CacheMatrix[IndexData][Freespace]->DB = 1;
					Proce2->CacheMatrix[IndexData][Freespace]->Coherence = 1;
					Proce2->CacheMatrix[IndexData][Freespace]->LRU = false;
					CheckProce1OnWrite(E1, Freespace, IndexData, HitCol1);
				}
				else {
					SharedCache->RcvdLine = ReadLine;
					bool WriteHit = SharedCache->L2Check();
					if (!WriteHit) {
						Proce2->Misses++;
						Proce2->Evict();
						for (int i = 0; i < 2; i++)
						{
							if (Proce2->CacheMatrix[IndexData][i]->Tag == TagData) {
								CheckProce1OnWrite(E1, i, IndexData, HitCol1);
							}
						}
						
					}
					else {
						Proce2->Evict();
						for (int i = 0; i < 2; i++)
						{
							if (Proce2->CacheMatrix[IndexData][i]->Tag == TagData) {
								CheckProce1OnWrite(E1, i, IndexData, HitCol1);
							}
						}
					}
				}
			}

		}
	}
}