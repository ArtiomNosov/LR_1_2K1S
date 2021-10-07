/*
*	Integer.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
class Integer {
private:
	int WholeNamber;
protected:
public:
	Integer(int n):WholeNamber(n){}
	~Integer(){}
	// G&S
	int GetNumber() {
		return WholeNamber;
	};
	void SetNumber(int n) {
		WholeNamber = n;
	};
	// Перегрузка операторов
		// Арифметика
	friend const Integer operator+(const Integer& left, const Integer& right);

	friend Integer& operator+=(Integer& left, const Integer& right);

	friend Integer* operator*(Integer& left, const Integer& right);

		// Логика

	friend bool operator==(const Integer& left, const Integer& right);

	friend bool operator<(Integer& left, Integer& right);

	friend bool operator>(Integer& left, Integer& right);

	friend bool operator<=(Integer& left, Integer& right);

	friend std::ostream& operator<< (std::ostream& out, Integer& point);
	friend std::istream& operator>> (std::istream& in, Integer& point);
};

const Integer operator+(const Integer& left, const Integer& right) {
	return Integer(left.WholeNamber + right.WholeNamber);
}

Integer& operator+=(Integer& left, const Integer& right) {
	left.WholeNamber += right.WholeNamber;
	return left;
}

Integer* operator*(Integer& left, const Integer& right) {
	auto newInt = new Integer((left.WholeNamber * right.WholeNamber));
	return newInt;
}

bool operator==(const Integer& left, const Integer& right) {
	return left.WholeNamber == right.WholeNamber;
}

bool operator<(Integer& left, Integer& right) {
	return (left.GetNumber()) < right.GetNumber();
}

bool operator>(Integer& left, Integer& right) {
	return (left.GetNumber()) > right.GetNumber();
}

bool operator<=(Integer& left, Integer& right) {
	return left.GetNumber() <= right.GetNumber();
}

std::ostream& operator<< (std::ostream& out, Integer& integer) {
	out << integer.WholeNamber;
	return out;
}

std::istream& operator>> (std::istream& in, Integer& integer) {
	in >> integer.WholeNamber;
	return in;
}
