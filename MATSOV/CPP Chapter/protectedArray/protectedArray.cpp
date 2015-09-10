#include "string.h"
#include "protectedArray.h"

const char* NOT_APPLICABLE_ARRAY_LENGTH = "Array length must be bigger or equal to 1!";
const char* ARRAY_INDEX_OUT_OF_BOUND = "Array index out of bound exception";

template <class T>
protectedArray<T>::protectedArray(int length)
{
	if(length < 1) { throw NOT_APPLICABLE_ARRAY_LENGTH; }
	m_length = length;
	m_firstNode = new T[m_length];
}

template <class T>
protectedArray<T>::~protectedArray()
{
	delete[] m_firstNode;
}

template <class T>
T* protectedArray<T>::operator [](int index) const
{
	if(index < 0 || index >= m_length) { throw ARRAY_INDEX_OUT_OF_BOUND; }
	return (m_firstNode + index);
}

template <class T>
T* protectedArray<T>::operator +(int indexSet) const
{
	if(this + indexSet < 0 || this + indexSet >= m_length) { throw ARRAY_INDEX_OUT_OF_BOUND; }
	return (this + indexSet);
}

template <class T>
T* protectedArray<T>::operator -(int indexSet) const
{
	if(this - indexSet < 0 || this - indexSet >= m_length) { throw ARRAY_INDEX_OUT_OF_BOUND; }
	return (this - indexSet);
}

template <class T>
T* protectedArray<T>::operator ++() const
{
	return operator +(1);
}

template <class T>
T* protectedArray<T>::operator --() const
{
	return operator -(1);
}

template <class T>
char* protectedArray<T>::operator =(char* string)
{
	if(this + strlen(string) + 1 > m_length) { throw ARRAY_INDEX_OUT_OF_BOUND; }
	for(int i = 0; i < strlen(string); i++)
	{
		*(this + i) = string[i];
	}
	(this + strlen(string) + 1) = '\0';
	return (this + strlen(string) + 1);
}
