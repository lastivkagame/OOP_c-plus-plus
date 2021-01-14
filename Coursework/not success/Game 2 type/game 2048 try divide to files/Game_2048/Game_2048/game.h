#include "logic.h"

class Game : public Logic // клас який збирає все і відповідає за весь процес(також викликаючи те що треба з інших класів)
{
private:
	ifstream read;
	ofstream write;
	string nameuser;
	map<string, int> userready;
	int score;
public:
	void StartField();
};