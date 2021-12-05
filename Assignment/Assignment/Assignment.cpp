#include <iostream>
#include "DAS.h"

using namespace std;


//Consrtructor for inaitalisation of data
template <typename T>
DAS<T>::DAS() :
	m_Head(nullptr),
	m_Tail(nullptr),
	m_IsEmpty(true)
{
	m_nSizeCount = 0;
}


//Desctructor
template <typename T>
DAS<T>::~DAS()
{

}


/*
Function Name: push_frot which inserts an element to the front of list.
Arguments: 1) int for input given by user 2) value which user needs to add in list
Return Value: it returns a bool value if successfully data is inserted then it returns TRUE else FALSE.
*/

template <typename T>
bool DAS<T>::push_front(int nSize, T val)
{
	if (nSize > 0)
	{
		if (m_nSizeCount == nSize)
		{
			cout << "List is full..!!";
			return false;
		}
		m_nSizeCount++;
	}
	Node<T>* node = new Node<T>;
	node->m_Value.m_Value = val;
	if (false == m_IsEmpty)
	{
		node->m_Next = m_Head;
		m_Head = node;
	}
	else
	{
		// First Node is going to insert from here
		m_Head = m_Tail = node;
	}
	m_IsEmpty = false;
	return true;
}

/*
Function Name: pop_frot which pop an element to the front of list.
Return Value: it returns a bool value if successfully data is poped then it returns TRUE else FALSE.
*/

template <typename T>
bool DAS<T>::pop_front()
{
	if (false == m_IsEmpty)
	{
		Node<T>* delNode = m_Head;
		m_Head = m_Head->m_Next;

		if (nullptr == m_Head)
		{
			// Here Linked List is having only one node and 
			// we are deleting that. So, m_Head also need to be updated
			m_Tail = nullptr;
		}

		//m_Head->m_Prev = nullptr;

		if (delNode)
		{
			delete delNode;
			delNode = nullptr;
		}

		// Update m_IsEmpty
		if ((nullptr == m_Head) && (nullptr == m_Tail))
			m_IsEmpty = true;
		else
			m_IsEmpty = false;

		m_nSizeCount--;
		return true;
	}
	else
	{
		cout << "pop_front() FAILED !! There is no element into linked list." << endl;
		// First Node is going to insert from here
		m_IsEmpty = true;
	}

	return false;
}

/*
Function Name: printList which prints all the element of the list.
Return Value: it returns a bool value if successfully data is printed then it returns TRUE else FALSE.
*/

template <typename T>
bool DAS<T>::printList()
{
	Node<T>* node = m_Head;
	if (node == nullptr)
		cout << "List is Blank.." << endl;

	while (node != nullptr)
	{
		cout << node->m_Value.m_Value << endl;
		node = node->m_Next;
	}
	cout << endl;
	return true;
}

/*
Function Name: GetHeaderAddress() prints a header address of the list and header element of the list.
*/

template <typename T>
void DAS<T>::GetHeadAddress()
{
	if (myIntList.m_Head != NULL)
	{
		cout << "FrontElement Pointer is : " << myIntList.m_Head;
		cout << "\nFrontElement is : " << myIntList.m_Head->m_Value.m_Value;
	}
	else
	{
		cout << "List is Blank..!!" << endl;
	}
}

/*
Function Name: GetTailAddress() prints a tail address of the list and tail element of the list.
*/

template <typename T>
void DAS<T>::GetTailAddress()
{
	if (myIntList.m_Tail != NULL)
	{
		cout << "BackElement Pointer is : " << myIntList.m_Tail;
		cout << "\nBackElement is : " << myIntList.m_Tail->m_Value.m_Value;
	}
	else
	{
		cout << "List is Blank..!!" << endl;
	}
}

/*
Function Name: insertIntegerData which push an int data to the fornt of the list.
*/

void insertIntegerData(int nSize, int nData)
{
	myIntList.push_front(nSize, nData);
	cout << "Data in List is : \n";
	myIntList.printList();
}

/*
Function Name: insertFloatData which push an float data to the fornt of the list.
*/

void insertFloatData(int nSize, float fData)
{
	myFloatList.push_front(nSize, fData);
	cout << "Data in List is : \n";
	myFloatList.printList();
}

/*
Function Name: insertStringData which push an string data to the fornt of the list.
*/

void insertStringData(int nSize, string sData)
{
	myStringList.push_front(nSize, sData);
	cout << "Data in List is : \n";
	myStringList.printList();
}

/*
Function Name: popIntData() which pop an int data from the fornt of the list.
*/

void popIntData()
{
	myIntList.pop_front();
	cout << "Data in List is : \n";
	myIntList.printList();
}

/*
Function Name: popFloatData() which pop a float data from the fornt of the list.
*/

void popFloatData()
{
	myFloatList.pop_front();
	cout << "Data in List is : \n";
	myFloatList.printList();
}

/*
Function Name: popStringData() which pop a string data from the fornt of the list.
*/

void popStringData()
{
	myStringList.pop_front();
	cout << "Data in List is : \n";
	myStringList.printList();
}

/*
Function Name: display_menu() which prints an initial menu for user options.
Return Value: it returns an int value which contains an user choice.
*/

int display_menu(int nMenuNo)
{
	int ch;
	switch (nMenuNo)
	{
	case 1:
		cout << endl;
		cout << "[ 1 ] Fixed Size" << endl;
		cout << "[ 2 ] Variable Size" << endl;
		cout << "Enter your choice :";
		cin >> ch;
		return ch;
		break;
	case 2:
		cout << endl;
		cout << "[ 1 ] Push " << endl;
		cout << "[ 2 ] Pop " << endl;
		cout << "[ 3 ] Front " << endl;
		cout << "[ 4 ] Back " << endl;
		cout << "[ 5 ] Exit " << endl;
		cout << "Enter your choice :";
		cin >> ch;
		return ch;
		break;
	default:
		break;
	}
	return 0;
}

/*
Function Name: checkDataType() it check a data type of user provided data.
Arguments : string which contains a user provided data.
Return Value: it returns a bool value if data is int type then it returns TRUE else FALSE.
*/

bool checkDataType(string sData)
{
	for (int i = 0; i < sData.length(); i++)
		if (isdigit(sData[i]) == false)
			return false;

	return true;
}

/*
It is a main starting point of the application.
*/

int main()
{
	int nSize = 0;
	string sData = "";
	int i = 0;
	bool bFloat = false;
	int nLastData = -1;
	int nCount = -1;

	while (1)
	{
		switch (display_menu(1))
		{
		case 1:
			cout << "Please insert a size : ";
			cin >> nSize;
			if (nSize <= 0)
			{
				cout << "Please insert a size grater than zero..!!";
				continue;
			}
			break;
		case 2:
			break;
		}
		break;
	}

	while (1)
	{
		switch (display_menu(2))
		{
		case 1:
			cout << "Please insert a data : ";
			cin >> sData;
			if (checkDataType(sData))
			{
				insertIntegerData(nSize, stoi(sData));
				nLastData = 1;
			}
			else
			{
				while (sData[i++] != '\0')    // same as while(length-->0)
				{
					if (sData[i] == '.')    // decimal point is present
					{
						bFloat = true;
						break;
					}
				}
				if (bFloat)
				{
					insertFloatData(nSize, stof(sData));
					nLastData = 2;
				}
				else
				{
					insertStringData(nSize, sData);
					nLastData = 3;
				}
			}
			break;
		case 2:
			if (nLastData == 1)
			{
				popIntData();
			}
			else if (nLastData == 2)
			{
				popFloatData();
			}
			else if (nLastData == 3)
			{
				popStringData();
			}
			break;
		case 3:
			myIntList.GetHeadAddress();
			break;
		case 4:
			myIntList.GetTailAddress();
			break;
		case 5:
			return 0;
		default:
			break;
		}
		//return 0;
	}
}