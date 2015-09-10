template <class T>
class protectedArray
{
public:
	protectedArray(int length);
	~protectedArray();
	T* operator [](int index) const;
	T* operator +(int indexSet) const;
	T* operator -(int indexSet) const;
	T* operator +=(int indexSet) const;
	T* operator -=(int indexSet) const;
	T* operator --() const;
	T* operator ++() const;
	char* operator =(char* string);

private:
	T* m_firstNode;
	const int m_length;
};
