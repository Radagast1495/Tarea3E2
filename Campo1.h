#pragma once


class Campo1 {
	public:
		int Coherence;
		int DB;
		int Tag;
		bool LRU;

		Campo1() {
			//0->estado inicial
			//1->M
			//2->E
			//3->S
			//4->I
			Coherence = 4;
			DB = 0;
			Tag = 0;
			LRU = true;
		}
		
};