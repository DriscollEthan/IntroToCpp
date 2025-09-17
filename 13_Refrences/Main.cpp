#include <iostream>
#include <cmath>

struct Vector3
{
	float x, y, z;

	float GetLength() const
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}
};

float GetLength(Vector3 Vec)
{
	return Vec.GetLength();
}

int main()
{

}