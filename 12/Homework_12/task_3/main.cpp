/*	Породжуючі патерни. Прототип(Prototype).
Продемонструвати створення різних видів зброї для деякої гри(можна доповнити задачу про юніти).
У програмі визначити клас Сховище пототипів зброї.
У сховище можна додавати нові прототипи, замовляти клон прототипу за номером(рядком чи enum)*/

#include "Game.h"

Weapon* FactoryWeapons::prototypes[] = { new Knifes, new Grenades, new Electroshock };
//int Unit::num = 0;

int main()
{
	srand(time(nullptr));

	Game game;
	game.Start();

	return 0;
}