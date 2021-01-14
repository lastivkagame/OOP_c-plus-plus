#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

void doSomething() {
	std::cout << "\n\nDoing something\n\n";
}

int main()
{
	int counter = 1, chosen_option = counter;
	std::vector<std::string> options;

	options.push_back("Do something");
	options.push_back("Exit");

	while (chosen_option != 2)
	{

		system("cls"); // не лучшее решение, но сойдет



		for (size_t i = 0; i < options.size(); ++i)
		{
			if ((i + 1) == counter) std::cout << "> " << options[i] << std::endl;
			else                    std::cout << options[i] << std::endl;
		}



		char pressed = _getch();

		if (pressed == 'w' && counter != 1)
			counter--;
		if (pressed == 's' && counter != options.size())
			counter++;

		if (pressed == '\r' || pressed == '\n') {
			chosen_option = counter;
			system("cls");

			switch (chosen_option)
			{

			case 1: doSomething();  break;
			case 2: return 0;       break;

			}

			_getch();
		}


	}


	_getch();
}