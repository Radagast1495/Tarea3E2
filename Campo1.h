#pragma once


class Campo1 {
	public:
		int Coherence;
		int DB;
		int Tag;
		bool LRU;

		Campo1() {
			Coherence = 0;
			DB = 0;
			Tag = 0;
			LRU = false;
		}
		
};