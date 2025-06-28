#ifndef LISTSEQUENCE
#define LISTSEQUENCE

#include <iostream>
#include "LinkedList.h"
#include "Sequence.h"

template <class T>
class ListSequence : Sequence <T>
{
private:
	LinkedList<T>* items;
public:
	ListSequence(T* items, int count)
    {
		this->items = new LinkedList<T>(items, count);
	}

	ListSequence()
    {
		this->items = new LinkedList<T>();
	}

	ListSequence(const LinkedList<T> &list)
    {
		this->items = list;
	}

	~ListSequence()
    {
		this->items->~LinkedList<T>();
	}

	T GetFirst()
    {
		return this->items->GetFirst();
	}

	T GetLast()
    {
		return this->items->GetLast();
	}

	T Get(int index)
    {
		return this->items->Get(index);
	}

	Sequence<T>* GetSubsequence(int startIndex, int endIndex)
    {
		ListSequence<T>* sublist = new ListSequence<T>();
		sublist->items = this->items->GetSubList(startIndex, endIndex);
		return (Sequence<T>*) sublist;
	}

	int GetLength()
    {
		return this->items->GetLength();
	}

	void Append(T item)
    {
		this->items->Append(item);
	}

	void Prepend(T item)
    {
		this->items->Prepend(item);
	}

	void InsertAt(T item, int index)
    {
		this->items->InsertAt(item, index);
	}
	Sequence<T>* Concat(Sequence <T>* list)
    {
		ListSequence<T>* linked_list = this;
		for (int i = 0; i < list->GetLength(); i++)
			linked_list->Append(list->Get(i));
		return (Sequence<T>*) linked_list;
	}

	void Print()
    {
		this->items->print();
	}
};

#endif
