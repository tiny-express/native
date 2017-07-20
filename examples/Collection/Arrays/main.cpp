#include "../../../library.hpp"

void ArraysSort()
{
	long arrayLongNormal[5] = { 3 , -2 , 4 , 0 , -1 };
	Arrays::sort(arrayLongNormal, 0, 4);

	Array<long> arrayLongArray = { 3 , -2 , 4 , 0 , -1 };
    Arrays::sort(&arrayLongArray, 0, 4);
}

void ArraysSearch()
{
	long arrayLongNormal[5] = { 3 , -2 , 4 , 0 , -1 };
	Arrays::binarySearch(arrayLongNormal, 4, 5);

	Array<long> arrayLongArray = { 3 , -2 , 4 , 0 , -1 };
	Arrays::binarySearch(arrayLongArray, 4L, 5);
}

int main()
{
	ArraysSort();
	ArraysSearch();
	return 0;
}
