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

	friend Integer operator*(Integer& left, const Integer& right);

		// Логика

	friend bool operator==(const Integer& left, const Integer& right);

	friend bool operator<(Integer& left, Integer& right);

	friend bool operator<=(Integer& left, Integer& right);
};

const Integer operator+(const Integer& left, const Integer& right) {
	return Integer(left.WholeNamber + right.WholeNamber);
}

Integer& operator+=(Integer& left, const Integer& right) {
	left.WholeNamber += right.WholeNamber;
	return left;
}

Integer operator*(Integer& left, const Integer& right) {
	return Integer((left.WholeNamber * right.WholeNamber));
}

bool operator==(const Integer& left, const Integer& right) {
	return left.WholeNamber == right.WholeNamber;
}

bool operator<(Integer& left, Integer& right) {
	return (left.GetNumber()) < right.GetNumber();
}

bool operator<=(Integer& left, Integer& right) {
	return left.GetNumber() <= right.GetNumber();
}