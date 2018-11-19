#pragma once
#include "Campo2.h"
#include <string>


using namespace std;



class L2 {
public:
	L2();
	~L2();
	int LineAmount = 4000;
	int TagSize = 15;
	int IndexSize = 12;
	int OffsetSize = 5;
	string RcvdLine;
	Campo2* CacheMatrix[4096];

	bool L2Check();



};