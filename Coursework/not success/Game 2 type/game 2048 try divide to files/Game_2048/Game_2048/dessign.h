#include "color.h"

class Dessign //клас у €кому будуть картинки тобто перше завантаженн€, меню та ≥нше 
{
public:
	int score = 0;  //рахунок
	int bestscore = 0;  // найкращий результат одного гравц€
	int color = 12;

	void FirstLoader(); //просто вив≥д першоњ картинки
	
	int Menu();

	void Name(); // просто в≥дображаЇ назву гри

	void InGame(); // виводить назву ≥ рахунок очок п≥д час гри
	
	void SpecialPrint(vector<string> temp, int el);  // щоб зробити виб≥р стр≥лками

};