#include <iostream>
#include <fstream>

int main()
{
	std::fstream File;
	File.open("SecretData.txt", std::ios::out);
	if (File.is_open())
	{
		File << "Hello World!" << std::endl;
	}
	File.close();

	std::fstream SecretNumberFile;
	SecretNumberFile.open("SecretNumbers.txt", std::ios::in);
	if (SecretNumberFile.is_open())
	{
		int ReadNumber = 0;
		while (!SecretNumberFile.eof())
		{
			SecretNumberFile >> ReadNumber;
			std::cout << ReadNumber << std::endl;
		}
	}
	SecretNumberFile.close();
	
	std::fstream SecretBinaryFile;
	SecretBinaryFile.open("SecretBinary.txt", std::ios::out | std::ios::binary);
	if (SecretBinaryFile.is_open())
	{
		int TheNumber = 3;
		SecretBinaryFile.write((char*)&TheNumber, sizeof(TheNumber));
	}
	SecretBinaryFile.close();

	std::fstream IncomingSecretBinaryFile;
	IncomingSecretBinaryFile.open("SecretBinary.txt", std::ios::in | std::ios::binary);
	if (IncomingSecretBinaryFile.is_open())
	{
		int TheNumber = 3;
		IncomingSecretBinaryFile.read((char*)&TheNumber, sizeof(TheNumber));
		std::cout << "Binary Data: " << TheNumber << std::endl;
	}
	IncomingSecretBinaryFile.close();

	return 0;
}