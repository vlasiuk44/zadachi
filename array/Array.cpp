#include "Array.h"
#include <istream>

Array::Array(int startCapacity)
{
	capacity = startCapacity;
	ptr = new int[capacity];
	size = 0;
}

Array::~Array()
{
	//delete[] ptr;
}

Array::Array(const Array& arr)
{
	ptr = new int[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;

	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
}

Array& Array::operator=(const Array& arr)
{
	if (this == &arr)
		return *this;

	if (capacity != arr.capacity)
	{
		delete[] ptr;
		ptr = new int[arr.capacity];
		capacity = arr.capacity;
	}
	size = arr.size;

	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];

	return *this;
}

bool Array::operator==(const Array& arr) {
	if (size != arr.size) {
		return false;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] != arr.ptr[i]) {
				return false;
			}
		}
		return true;
	}
};


int& Array::operator[](int index)
{
	if (index >= size || index < 0)
		throw ArrayException();
	else
		return ptr[index];
}

void Array::insert(int elem, int index)
{
	if (index < 0 || index > size)
		throw ArrayException();

	if (size == capacity)
		increaseCapacity(size + 1);

	for (int j = size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];

	size++;
	ptr[index] = elem;
}

void Array::insert(int elem)
{
	insert(elem, size);
}

void Array::insert(const Array& arr, int index)
{
	if (index < 0 || index > size)
		throw ArrayException();

	int sumCapacities = size + arr.size;

	if (sumCapacities == capacity)
		increaseCapacity(sumCapacities + 1);

	for (int i = sumCapacities - 1; i >= index + arr.size; i--)
		ptr[i] = ptr[i - arr.size];

	for (int i = arr.size - 1; i >= 0; i--)
		ptr[index + i] = arr.ptr[i];

	size += arr.size;
}

void Array::increaseCapacity(int newCapacity)
{
	capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
	int* newPtr = new int[capacity];

	for (int i = 0; i < size; i++)
		newPtr[i] = ptr[i];

	delete[] ptr;
	ptr = newPtr;
}

void Array::remove(int index)
{
	if (index < 0 || index >= size)
		throw ArrayException();

	for (int j = index; j < size - 1; j++)
		ptr[j] = ptr[j + 1];

	ptr[size - 1] = 0;
	size--;
}

int Array::getSize() const
{
	return size;
}

void Array::pop() { // removing last elem
	ptr[size - 1] = NULL;
	size--;
}


int Array::find(int elem) { // find elem
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] == elem) {
			return i;
		}
	}
	return -1;
}

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
	out << "Total size: " << arr.size << std::endl;

	for (int i = 0; i < arr.size; i++)
		out << arr.ptr[i] << std::endl;

	return out;
}