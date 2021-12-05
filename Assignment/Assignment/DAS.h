#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T>

struct Value
{
	T m_Value;
	Value()
	{
		m_Value = 0;
	}
};

template <>
struct Value <string>
{
	string m_Value;
	Value()
	{
		m_Value.assign("");
	}
};

template <typename T>
struct Node
{
	Node();
	Value<T> m_Value;
	Node<T>* m_Prev;
	Node<T>* m_Next;
};

template <typename T>
Node<T>::Node()
{
	m_Next = nullptr;
}


/*
CDAS is a templagte class for data processing.
It has a push,pop,print,Head address and tail address functions.
*/
template <typename T>
class DAS
{
private:
	Node<T>* m_Head;
	Node<T>* m_Tail;

public:
	DAS();
	~DAS();
	int m_nSizeCount;
	bool m_IsEmpty;
	bool push_front(int nSize, T val);
	bool pop_front();
	bool printList();
	void GetHeadAddress();
	void GetTailAddress();
};


DAS<int> myIntList; //IntObj of template class for integer data processing
DAS<float> myFloatList; //FloatObj of template class for float data processing
DAS<string> myStringList; //StringObj of template class for string data processing
