#include <iostream>
#include <string>

class APlayer
{
public:
	APlayer()
	{
		std::cout << "Player Created!" << std::endl;
	}

	~APlayer() { }
};

int main()
{
	APlayer John;
}