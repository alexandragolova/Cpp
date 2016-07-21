#ifndef BOOL_VECTOR_H
#define BOOL_VECTOR_H

class BoolVector
{
private:
	bool* data;
	size_t size;

public:
	BoolVector(const bool* = 0);
	BoolVector(const BoolVector&);
	~BoolVector();
	
	BoolVector& operator =(const BoolVector&);
	bool& BoolVector::operator[](size_t index);
	void SetData(const bool*);
	void SetSize(size_t size);

	bool Set(int index);
	bool Clear(int index);
	void ShowVector(BoolVector boolVector);
};


#endif