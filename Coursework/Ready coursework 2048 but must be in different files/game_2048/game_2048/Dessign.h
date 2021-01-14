#pragma once
#include "color.h"

class Dessign //клас у якому будуть виводитися картинки (тобто перше завантаження, меню та інше) 
{
public:
	int color = 12; //змінна для зміни кольору

	void FirstLoader(); //просто вивід першої картинки
	
	int Menu();  // менюі

	void Name(); // просто відображає назву гри
	
	void SpecialPrint(vector<string> temp, int el, int color = -1);  // метод що виводить виділеним певний рядок(щоб зробити вибір стрілками) 
	
};