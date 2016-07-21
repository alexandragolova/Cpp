template <class T>
class Sort {
private:
	T list[128];     
	size_t size;
	void resize(int newSize);
public:
	Sort();
	~Sort();
	Sort(size_t size);

	void add(T& element); 
	void remove(T& element);
	void print();
	void sort();
	const T getElementByPosition(int pos)const;

};


