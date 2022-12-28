#include <iostream>
#include <cstring>
#include "Utils.h"

#pragma warning(disable:4996)

using namespace std;


typedef int IDTYpe; // user-defined type

enum DirectionType {
	NORTH = 0,
	EAST,
	SOUTH,
	WEST
};


struct BookType {
	int bookId;
	char title[256];
	char author[256];
	int year;
	float price;
};

void Func(const BookType& book);





// Problem 2
typedef int DataTypeDynamicArray;

struct DynamicArray {
	DataTypeDynamicArray* dynamicArray;
	int size;
	int capacity;
};

void CreateDynamicArray(DynamicArray& dArray, int capacity);
void DeleteDynamicArray(DynamicArray& dArray);
void InsertElement(DynamicArray& dArray, int element);
void DeleteElement(DynamicArray& dArray, int elementIndex);
void ResizeDynamicArray(DynamicArray& dArray, int newCapacity);
void PrintDynamicArray(DynamicArray& dArray);


int main()
{
	/*
		Problem 1: 

		Create an enum called CharacterCaseType. CharacterCaseType should have 3 values:
		CC_UPPER_CASE, CC_LOWER_CASE, and CC_EITHER.
		Using this enum, modify the GetCharacter function you wrote to modify the input
		to one of those values depending on the value of the CharacterCaseType 
		(e.g if it was CC_LOWER_CASE, all input would come out lower case from GetCharacter)


		Problem: Improve your Dynamic array that you made previously by 
		using structs to hold the pointer to the dynamic array and
		the size and capacity of the array:

		struct DynamicArray{

			int * dynamicArray;

			int capacity;

			int size;

		};

		update all the functions to reflect this change.

		What's a way you could use to change the type of data being held in the dynamic array?
		My answer is using typedef :3
	*/

	int capacity = 6;
	DynamicArray dArray;
	CreateDynamicArray(dArray, capacity);

	InsertElement(dArray, 1);
	InsertElement(dArray, 2);
	InsertElement(dArray, 3);
	InsertElement(dArray, 4);
	InsertElement(dArray, 5);
	InsertElement(dArray, 6);
	InsertElement(dArray, 7);

	PrintDynamicArray(dArray);

	DeleteDynamicArray(dArray);

	return 0;
}

void PrintDynamicArray(DynamicArray& dArray) {
	for (int i = 0; i < dArray.size; ++i) {
		cout << dArray.dynamicArray[i] << " ";
	}
	cout << endl;
}

void CreateDynamicArray(DynamicArray& dArray, int capacity) {
	dArray.capacity = capacity;
	dArray.size = 0;
	dArray.dynamicArray = new DataTypeDynamicArray[capacity];
}

void DeleteDynamicArray(DynamicArray& dArray) {
	dArray.capacity = 0;
	dArray.size = 0;
	delete[] dArray.dynamicArray;
}

void InsertElement(DynamicArray& dArray, int element) {
	if (dArray.dynamicArray != nullptr && dArray.size < dArray.capacity) {
		dArray.dynamicArray[dArray.size++] = element;
	}
	else {
		std::cout << "the dynamic array already filled! It will be resized" << endl;
		ResizeDynamicArray(dArray, dArray.capacity * 2);
		InsertElement(dArray, element);
	}
}

void DeleteElement(DynamicArray& dArray, int elementIndex) {
	for (int i = elementIndex + 1; i < dArray.size; ++i) {
		dArray.dynamicArray[i - 1] = dArray.dynamicArray[i];
	}

	dArray.size--;
}

void ResizeDynamicArray(DynamicArray& dArray, int newCapacity) {
	if (dArray.capacity >= newCapacity) {
		std::cout << "The new capacity must be greater than old capacity is " << dArray.capacity << endl;
		return;
	}

	DataTypeDynamicArray* ptrDynamicArray = dArray.dynamicArray;
	DataTypeDynamicArray* newDynamicArray = new DataTypeDynamicArray[newCapacity];

	for (int i = 0; i < dArray.size; ++i) {
		newDynamicArray[i] = ptrDynamicArray[i];
	}

	delete ptrDynamicArray;

	dArray.capacity = newCapacity;
	dArray.dynamicArray = newDynamicArray;
}


void TestProblem1() {
	char input = GetCharacter("Enter: ", "Input error! Please re-enter!", CC_LOWER_CASE);
	cout << input << endl;

	char input2 = GetCharacter("Enter: ", "Input error! Please re-enter!", CC_UPPER_CASE);
	cout << input2 << endl;

	char input3 = GetCharacter("Enter: ", "Input error! Please re-enter!", CC_EITHER);
	cout << input3 << endl;

	char input4 = GetCharacter("Enter: ", "Input error! Please re-enter!", CC_EITHER);
	cout << input4 << endl;
}

void Test() {
	BookType aBook;

	aBook.bookId = 1000;
	strcpy(aBook.title, "A Tale of Two Cities");
	strcpy(aBook.author, "Charles Dickens");
	aBook.year = 1859;
	aBook.price = 19.99;

	cout << "The size of an integer is: " << sizeof(int) << endl;
	cout << "The size of BookType is: " << sizeof(BookType) << endl;

	Func(aBook);
}

void Func(const BookType& book) {
	// useBook
}

