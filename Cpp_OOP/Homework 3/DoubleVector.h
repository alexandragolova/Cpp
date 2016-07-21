#ifndef DOUBLE_VECTOR_H
#define DOUBLE_VECTOR_H

class DoubleVector
{

private:
	double* data;
	int size;

public:
	DoubleVector(const double* = 0);
	DoubleVector(const DoubleVector&);
	DoubleVector& operator =(const DoubleVector&);
	~DoubleVector();

	void SetData(const double*);
	void SetSize(size_t size);
	void DoubleVector::Resize(int newSize);
	
	double& operator[](int) const;

	DoubleVector& operator+(const DoubleVector& other)const;

	DoubleVector& operator+=(const DoubleVector& other);

	DoubleVector& operator-(const DoubleVector& other)const;

	DoubleVector& operator-=(const DoubleVector& other);

	DoubleVector& operator*(const double& other)const;

	DoubleVector& operator*=(const double& other);

	DoubleVector& operator/(const double& other)const;

	DoubleVector& operator/=(const double& other);

	int DoubleVector::operator% (const DoubleVector&)const;

	void ShowVector()const;
};

#endif