#include <iostream>
#include <string>

class Player
{
public:
	Player()
	{
		std::cout << "Player Created!" << std::endl;
	}

	~Player() { }
};

int main()
{
	Player John;
}