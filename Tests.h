#include <iostream>
#include "DeckSequence.h"
#include <string.h>
#include <cctype>

#ifndef TESTS_H
#define TEST_H

class Complex {
private:
	int real;
	int imag;
public:
	Complex(int real, int imag) {
		this->real = real;
		this->imag = imag;
	}
	Complex(Complex const &arr) {
		this->real = arr.real;
		this->imag = arr.imag;
	}
	int GetImag() {
		return this->imag;
	}
	int GetReal() {
		return this->real;
	}
};

void Checking(int* check, std::string message) {
	std::cout << message;
	if (*check) {
		std::cout << "Test completed successfully" << std::endl;
	}
	else std::cout << "Test failed" << std::endl;
	*check = 1;
}

int IntCompare(const void* a, const void* b) {
	return *(int*)a > *(int*)b;
}

int FloatCompare(const void* a, const void* b) {
	return *(float*)a > *(float*)b;
}

template <class T>
T Multiply(T num1, T num2) {
	return num1 * num2;
}

template <class T>
T MultiplyBy2(T num) {
	return num * 2;
}

template <class T>
int IsPositive(T number) {
	if (number > 0) {
		return 1;
	}
	return 0;
}

template <class T>
void StandartPrint(T item) {
	std::cout << item << " ";
}



void IntTesting() {
	int int_array[7] = { 8, 4, 4, -2, -5, 3, -7 };
	int int_array_pushback[8] = { 8, 4, 4, -2, -5, 3, -7, 1 };
	int int_array_popfront[7] = { 4, 4, -2, -5, 3, -7, 1 };
	int int_array_pushfront[8] = { 9, 4, 4, -2, -5, 3, -7, 1 };
	int int_array_popback[7] = { 9, 4, 4, -2, -5, 3, -7 };
	int int_maplist[7] = { 18, 8, 8, -4, -10, 6, -14 };
	int int_wherelist[4] = {9, 4, 4, 3};
	int int_reduce[1] = { -30240 };
	int int_sorted[7] = { -7, -5, -2, 3, 4, 4, 9 };

	int check = 1;
	int* TestInt[9] = { int_array, int_array_pushback, int_array_popfront, int_array_pushfront, int_array_popback, int_maplist, int_wherelist, int_reduce, int_sorted };
	DeckSequence<int> DeckInt(int_array, 7);
	DeckInt.Print(StandartPrint);
	for (int i = 0; i < 7; i++) {
		if (DeckInt.Get(i) != TestInt[0][i]) {
			check = 0;
		}
	}
	Checking(&check, "Initialization: ");
	DeckInt.PushBack(1);
	for (int i = 0; i < 8; i++) {
		if (DeckInt.Get(i) != TestInt[1][i]) {
			check = 0;
		}
	}
	Checking(&check, "PushBack: ");
	DeckInt.PopFront();
	for (int i = 0; i < 7; i++) {
		if (DeckInt.Get(i) != TestInt[2][i]) {
			check = 0;
		}
	}
	Checking(&check, "PopFront: ");
	DeckInt.PushFront(9);
	for (int i = 0; i < 8; i++) {
		if (DeckInt.Get(i) != TestInt[3][i]) {
			check = 0;
		}
	}
	Checking(&check, "PushFront: ");
	DeckInt.PopBack();
	for (int i = 0; i < 7; i++) {
		if (DeckInt.Get(i) != TestInt[4][i]) {
			check = 0;
		}
	}
	Checking(&check, "PopBack: ");
	for (int i = 0; i < 7; i++) {
		if (DeckInt.Map(MultiplyBy2)->Get(i) != TestInt[5][i]) {
			check = 0;
		}
	}
	Checking(&check, "Map: ");
	for (int i = 0; i < 4; i++) {
		if (DeckInt.Where(IsPositive)->Get(i) != TestInt[6][i]) {
			check = 0;
		}
	}
	Checking(&check, "Where: ");
	if (DeckInt.Reduce(Multiply, 1) == TestInt[7][0]) check = 1;
	else check = 0;
	Checking(&check, "Reduce: ");
	for (int i = 0; i < 7; i++) {
		if (DeckInt.Sorted(IntCompare)->Get(i) != TestInt[8][i]) {
			check = 0;
		}
	}
	Checking(&check, "Sorting: ");
}

void FloatTesting() {
	float float_array[7] = { 1.5, 3.4, -4.23, 8.0, -2.0, 1.75, 1.55 };
	float float_array_pushback[8] = { 1.5, 3.4, -4.23, 8.0, -2.0, 1.75, 1.55, -0.43 };
	float float_array_popfront[7] = { 3.4, -4.23, 8.0, -2.0, 1.75, 1.55, -0.43 };
	float float_array_pushfront[8] = { 1.01, 3.4, -4.23, 8.0, -2.0, 1.75, 1.55, -0.43 };
	float float_array_popback[7] = { 1.01, 3.4, -4.23, 8.0, -2.0, 1.75, 1.55 };
	float float_maplist[7] = { 2.02, 6.8, -8.46, 16.0, -4.0, 3.50, 3.10 };
	float float_wherelist[5] = { 1.01, 3.4, 8.0, 1.75, 1.55 };
	float float_reduce[1] = { 630.420588 };
	float float_sorted[7] = { -4.23, -2.0, 1.01, 1.55, 1.75, 3.4, 8.0 };

	int check = 1;
	float* Testfloat[9] = { float_array, float_array_pushback, float_array_popfront, float_array_pushfront, float_array_popback, float_maplist, float_wherelist, float_reduce, float_sorted };
	DeckSequence<float> Deckfloat(float_array, 7);
	Deckfloat.Print(StandartPrint);
	for (int i = 0; i < 7; i++) {
		if (Deckfloat.Get(i) != Testfloat[0][i]) {
			check = 0;
		}
	}
	Checking(&check, "Initialization: ");
	Deckfloat.PushBack(-0.43);
	for (int i = 0; i < 8; i++) {
		if (Deckfloat.Get(i) != Testfloat[1][i]) {
			check = 0;
		}
	}
	Checking(&check, "PushBack: ");
	Deckfloat.PopFront();
	for (int i = 0; i < 7; i++) {
		if (Deckfloat.Get(i) != Testfloat[2][i]) {
			check = 0;
		}
	}
	Checking(&check, "PopFront: ");
	Deckfloat.PushFront(1.01);
	for (int i = 0; i < 8; i++) {
		if (Deckfloat.Get(i) != Testfloat[3][i]) {
			check = 0;
		}
	}
	Checking(&check, "PushFront: ");
	Deckfloat.PopBack();
	for (int i = 0; i < 7; i++) {
		if (Deckfloat.Get(i) != Testfloat[4][i]) {
			check = 0;
		}
	}
	Checking(&check, "PopBack: ");
	for (int i = 0; i < 7; i++) {
		if (Deckfloat.Map(MultiplyBy2)->Get(i) != Testfloat[5][i]) {
			check = 0;
		}
	}
	Checking(&check, "Map: ");
	for (int i = 0; i < 4; i++) {
		if (Deckfloat.Where(IsPositive)->Get(i) != Testfloat[6][i]) {
			check = 0;
		}
	}
	Checking(&check, "Where: ");
	if (Deckfloat.Reduce(Multiply, 1) == Testfloat[7][0]) check = 1;
	else check = 0;
	Checking(&check, "Reduce: ");
	for (int i = 0; i < 7; i++) {
		if (Deckfloat.Sorted(FloatCompare)->Get(i) != Testfloat[8][i]) {
			check = 0;
		}
	}
	Checking(&check, "Sorting: ");

}



int ComplexCompare(const void* a, const void* b) {
	return (*(Complex*)a).GetImag() * (*(Complex*)a).GetImag() + (*(Complex*)a).GetReal() * (*(Complex*)a).GetReal() > (*(Complex*)b).GetImag() * (*(Complex*)b).GetImag() + (*(Complex*)b).GetReal() * (*(Complex*)b).GetReal();
}

Complex ComplexMultiplyBy2(Complex num) {
	Complex res(num.GetReal() * 2, num.GetImag() * 2);
	return res;
}
int IsImaginary(Complex num) {
	if (num.GetImag() != 0 && num.GetReal() == 0) return 1;
	return 0;
}

Complex ComplexMultiply(Complex num1, Complex num2) {
	Complex res(num1.GetReal() * num2.GetReal() - num1.GetImag() * num2.GetImag(), num1.GetImag() * num2.GetReal() + num1.GetReal() * num2.GetImag());
	return res;
}

void ComplexPrint(Complex item) {
	if (item.GetImag() == 0) {
		std::cout << item.GetReal() << " ";
	}
	else if (item.GetReal() == 0) {
		if (item.GetImag() == 1) std::cout << "i ";
		else if (item.GetImag() == -1) std::cout << "-i ";
		else std::cout << item.GetImag() << "i ";
	}
	else std::cout << item.GetReal() << "+" << item.GetImag() << "i ";
}

void ComplexTesting() {
	Complex complex_array[3] = { {1, 1}, {0, 7}, {1, 0} };
	Complex complex_array_pushback[4] = { {1, 1}, {0, 7}, {1, 0}, {2, 2} };
	Complex complex_array_popfront[3] = { {0, 7}, {1, 0}, {2, 2} };
	Complex complex_array_pushfront[4] = { {1, 4}, {0, 7}, {1, 0}, {2, 2} };
	Complex complex_array_popback[3] ={ {1, 4}, {0, 7}, {1, 0} };
	Complex complex_maplist[3] = { {2, 8}, {0, 14}, {2, 0} };
	Complex complex_wherelist[1] = { {0, 7} };
	Complex complex_reduce[1] = { {-28, 7} };
	Complex complex_sorted[3] = { {1, 0}, {1, 4}, { 0, 7 } };

	int check = 1;
	Complex* TestComplex[9] = { complex_array, complex_array_pushback, complex_array_popfront, complex_array_pushfront, complex_array_popback, complex_maplist, complex_wherelist, complex_reduce, complex_sorted };
	DeckSequence<Complex> DeckComplex(complex_array, 3);
	DeckComplex.Print(ComplexPrint);
	for (int i = 0; i < 3; i++) {
		if (DeckComplex.Get(i).GetImag() != TestComplex[0][i].GetImag() || DeckComplex.Get(i).GetReal() != TestComplex[0][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "Initialization: ");
	DeckComplex.PushBack({2, 2});
	for (int i = 0; i < 4; i++) {
		if (DeckComplex.Get(i).GetImag() != TestComplex[1][i].GetImag() || DeckComplex.Get(i).GetReal() != TestComplex[1][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "PushBack: ");
	DeckComplex.PopFront();
	for (int i = 0; i < 3; i++) {
		if (DeckComplex.Get(i).GetImag() != TestComplex[2][i].GetImag() || DeckComplex.Get(i).GetReal() != TestComplex[2][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "PopFront: ");
	DeckComplex.PushFront({1, 4});
	for (int i = 0; i < 4; i++) {
		if (DeckComplex.Get(i).GetImag() != TestComplex[3][i].GetImag() || DeckComplex.Get(i).GetReal() != TestComplex[3][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "PushFront: ");
	DeckComplex.PopBack();
	for (int i = 0; i < 3; i++) {
		if (DeckComplex.Get(i).GetImag() != TestComplex[4][i].GetImag() || DeckComplex.Get(i).GetReal() != TestComplex[4][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "PopBack: ");
	for (int i = 0; i < 3; i++) {
		if (DeckComplex.Map(ComplexMultiplyBy2)->Get(i).GetImag() != TestComplex[5][i].GetImag() || DeckComplex.Map(ComplexMultiplyBy2)->Get(i).GetReal() != TestComplex[5][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "Map: ");
	for (int i = 0; i < 1; i++) {
		if (DeckComplex.Where(IsImaginary)->Get(i).GetImag() != TestComplex[6][i].GetImag() || DeckComplex.Where(IsImaginary)->Get(i).GetReal() != TestComplex[6][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "Where: ");
	if (DeckComplex.Reduce(ComplexMultiply, {1, 0}).GetImag() == TestComplex[7][0].GetImag() && DeckComplex.Reduce(ComplexMultiply, {1, 0}).GetReal() == TestComplex[7][0].GetReal()) check = 1;
	else check = 0;
	Checking(&check, "Reduce: ");
	for (int i = 0; i < 3; i++) {
		if (DeckComplex.Sorted(ComplexCompare)->Get(i).GetImag() != TestComplex[8][i].GetImag() || DeckComplex.Sorted(ComplexCompare)->Get(i).GetReal() != TestComplex[8][i].GetReal()) {
			check = 0;
		}
	}
	Checking(&check, "Sorting: ");
	DeckComplex.Sorted(ComplexCompare)->Print(ComplexPrint);
}

class Student {
private:
	int id;
	const char* firstName;
	const char* lastName;
	time_t date;

public:
	Student(int id, const char* firstName, const char* lastName, time_t date) {
		this->id = id;
		this->firstName = firstName;
		this->lastName = lastName;
		this->date = date;
	}
	int GetID() {
		return this->id;
	}
	const char* GetFirstName() {
		return this->firstName;
	}
	const char* GetLastName() {
		return this->lastName;
	}
	time_t GetDate() {
		return this->date;
	}
};

void StudentPrint(Student student) {
	std::cout << student.GetID() << " ";
	std::cout << student.GetFirstName() << " ";
	std::cout << student.GetLastName() << std::endl;
}


template <class T>
int FirstNameCompare(const void* a, const void* b) {
	return strcmp(((Student*)a)->GetFirstName(), ((Student*)b)->GetFirstName());
}


int LastNameCompare(const void* a, const void* b) {
	return strcmp(((Student*)a)->GetLastName(), ((Student*)b)->GetLastName());
}

template <class T>
int IDCompare(const void* a, const void* b) {
	return (((Student*)a)->GetID() > ((Student*)b)->GetID());
}

char* Caps(const char* name) {
	char namecopy[80];
	strcpy_s(namecopy, _countof(namecopy), name);
	for (int i = 0; i < strlen(namecopy); i++) {
		namecopy[i] = toupper(namecopy[i]);
	}
	return namecopy;
}

Student CapsStudent(Student student) {
	return Student(student.GetID(), Caps(student.GetFirstName()), Caps(student.GetLastName()), student.GetDate());
}

void StudentTesting() {
	Student stud_array[4] = { {10453, "Ivan", "Vasiliev", 6387136}, {10423, "Mariya", "Kovaleva", 6378631}, {10287, "Denis", "Bereznyak", 6347636}, {10982, "Anna", "Avina", 6356126} };
	Student stud_array_pushback[5] = { {10453, "Ivan", "Vasiliev", 6387136}, {10423, "Mariya", "Kovaleva", 6378631}, {10287, "Denis", "Bereznyak", 6347636}, {10982, "Anna", "Avina", 6356126}, {10934, "Andrey", "Gelin", 7364372}};
	Student stud_array_popfront[4] = { {10423, "Mariya", "Kovaleva", 6378631}, {10287, "Denis", "Bereznyak", 6347636}, {10982, "Anna", "Avina", 6356126}, {10934, "Andrey", "Gelin", 7364372} };
	Student stud_array_pushfront[5] = { {11231, "Lyudmila", "Savina", 653723}, {10423, "Mariya", "Kovaleva", 6378631}, {10287, "Denis", "Bereznyak", 6347636}, {10982, "Anna", "Avina", 6356126}, {10934, "Andrey", "Gelin", 7364372} };
	Student stud_array_popback[4] = { {11231, "Lyudmila", "Savina", 653723}, {10423, "Mariya", "Kovaleva", 6378631}, {10287, "Denis", "Bereznyak", 6347636}, {10982, "Anna", "Avina", 6356126} };
	Student stud_maplist[4] = { {11231, "LYUDMILA", "SAVINA", 653723}, {10423, "MARIYA", "KOVALEVA", 6378631}, {10287, "DENIS", "BEREZNYAK", 6347636}, {10982, "ANNA", "AVINA", 6356126} };
	Student stud_wherelist[3] = { {10423, "Mariya", "Kovaleva", 6378631}, {10287, "Denis", "Bereznyak", 6347636}, {10982, "Anna", "Avina", 6356126} };
	Student stud_reduce[1] = { {11231, "Mariya", "Savina", 6378631}};
	Student stud_sorted[4] = { {10982, "Anna", "Avina", 6356126}, {10287, "Denis", "Bereznyak", 6347636}, {10423, "Mariya", "Kovaleva", 6378631}, {11231, "Lyudmila", "Savina", 653723} };

	int check = 1;
	Student* TestStudent[9] = { stud_array, stud_array_pushback, stud_array_popfront, stud_array_pushfront, stud_array_popback, stud_maplist, stud_wherelist, stud_reduce, stud_sorted };
	DeckSequence<Student> DeckStudent(stud_array, 4);
	DeckStudent.Print(StudentPrint);
	for (int i = 0; i < 4; i++) {
		if (DeckStudent.Get(i).GetID() != TestStudent[0][i].GetID() || DeckStudent.Get(i).GetDate() != TestStudent[0][i].GetDate() || DeckStudent.Get(i).GetFirstName() != TestStudent[0][i].GetFirstName() || DeckStudent.Get(i).GetLastName() != TestStudent[0][i].GetLastName()) {
			check = 0;
		}
	}
	Checking(&check, "Initialization: ");
	DeckStudent.PushBack({ 10934, "Andrey", "Gelin", 7364372 });
	for (int i = 0; i < 5; i++) {
		if (DeckStudent.Get(i).GetID() != TestStudent[1][i].GetID() || DeckStudent.Get(i).GetDate() != TestStudent[1][i].GetDate() || DeckStudent.Get(i).GetFirstName() != TestStudent[1][i].GetFirstName() || DeckStudent.Get(i).GetLastName() != TestStudent[1][i].GetLastName()) {
			check = 0;
		}
	}
	Checking(&check, "PushBack: ");
	DeckStudent.PopFront();
	for (int i = 0; i < 4; i++) {
		if (DeckStudent.Get(i).GetID() != TestStudent[2][i].GetID() || DeckStudent.Get(i).GetDate() != TestStudent[2][i].GetDate() || DeckStudent.Get(i).GetFirstName() != TestStudent[2][i].GetFirstName() || DeckStudent.Get(i).GetLastName() != TestStudent[2][i].GetLastName()) {
			check = 0;
		}
	}
	Checking(&check, "PopFront: ");
	DeckStudent.PushFront({ 11231, "Lyudmila", "Savina", 653723 });
	for (int i = 0; i < 5; i++) {
		if (DeckStudent.Get(i).GetID() != TestStudent[3][i].GetID() || DeckStudent.Get(i).GetDate() != TestStudent[3][i].GetDate() || DeckStudent.Get(i).GetFirstName() != TestStudent[3][i].GetFirstName() || DeckStudent.Get(i).GetLastName() != TestStudent[3][i].GetLastName()) {
			check = 0;
		}
	}
	Checking(&check, "PushFront: ");
	DeckStudent.PopBack();
	for (int i = 0; i < 4; i++) {
		if (DeckStudent.Get(i).GetID() != TestStudent[4][i].GetID() || DeckStudent.Get(i).GetDate() != TestStudent[4][i].GetDate() || DeckStudent.Get(i).GetFirstName() != TestStudent[4][i].GetFirstName() || DeckStudent.Get(i).GetLastName() != TestStudent[4][i].GetLastName()) {
			check = 0;
		}
	}

	Checking(&check, "PopBack: ");
	/*for (int i = 0; i < 4; i++) {
		
		if (DeckStudent.Map(CapsStudent)->Get(i).GetID() != TestStudent[5][i].GetID() || DeckStudent.Map(CapsStudent)->Get(i).GetDate() != TestStudent[5][i].GetDate() || DeckStudent.Map(CapsStudent)->Get(i).GetFirstName() != TestStudent[5][i].GetFirstName() || DeckStudent.Map(CapsStudent)->Get(i).GetLastName() != TestStudent[5][i].GetLastName()) {
			check = 0;
		}
		
	}
	Sequence<Student>* DeckMap = DeckStudent.Map(CapsStudent);
	DeckStudent.Map(CapsStudent)->Print(StudentPrint);
	Checking(&check, "Map: ");*/
	/*for (int i = 0; i < 2; i++) {
		if (DeckStudent.Where(IsPositive)->Get(i) != TestStudent[6][i]) {
			check = 0;
		}
	}
	Checking(&check, "Where: ");
	if (DeckStudent.Reduce(Multiply, 1) == TestStudent[7][0]) check = 1;
	else check = 0;
	Checking(&check, "Reduce: ");*/
	for (int i = 0; i < 4; i++) {
		if (DeckStudent.Sorted(LastNameCompare)->Get(i).GetID() != TestStudent[8][i].GetID() || DeckStudent.Sorted(LastNameCompare)->Get(i).GetDate() != TestStudent[8][i].GetDate() || DeckStudent.Sorted(LastNameCompare)->Get(i).GetFirstName() != TestStudent[8][i].GetFirstName() || DeckStudent.Sorted(LastNameCompare)->Get(i).GetLastName() != TestStudent[8][i].GetLastName()) {
			check = 0;
		}
	}
	Checking(&check, "Sorting: ");
	DeckStudent.Sorted(LastNameCompare)->Print(StudentPrint);
}


class Teacher {
private:
	int id;
	std::string firstName;
	std::string lastName;
	time_t date;

public:
	Teacher(int id, std::string firstName, std::string lastName, time_t date) {
		this->id = id;
		this->firstName = firstName;
		this->lastName = lastName;
		this->date = date;
	}
	int GetID() {
		return this->id;
	}
	std::string GetFirstName() {
		return this->firstName;
	}
	std::string GetLsstName() {
		return this->lastName;
	}
	time_t GetDate() {
		return this->date;
	}
};

#endif
