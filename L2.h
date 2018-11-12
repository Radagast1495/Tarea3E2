#pragma once
#include "Campo2.h"
#include "L1.h"

using namespace std;



class L2 {
public:
	L2();
	~L2();
	int LineAmount = 4000;
	int TagSize = 15;
	int IndexSize = 12;
	int OffsetSize = 5;
	int TagData;
	int IndexData;
	int OffsetData;
	string RcvdLine;
	Campo2 CacheMatrix[4000];
	L1* P1;
	L1* P2;

	void CacheCheck();
	void Evict();



};