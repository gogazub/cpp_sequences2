#ifndef DECKSEQUENCE
#define DECKSEQUENCE

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Sequence.h"

template <class T>
class DeckSequence : Sequence <T>
{
private:
	LinkedList<T>* items;
public:
	DeckSequence(T* items, int count)
    {
		this->items = new LinkedList<T>(items, count);
	}

	DeckSequence()
    {
		this->items = new LinkedList<T>();
	}

	DeckSequence(const LinkedList<T> &list)
    {
		this->items = list;
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
		DeckSequence<T>* sublist = new DeckSequence<T>();
		sublist->items = this->items->GetSubList(startIndex, endIndex);
		return (Sequence<T>*)sublist;
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
		DeckSequence<T>* linked_list = this;
		for (int i = 0; i < list->GetLength(); i++)
			linked_list->Append(list->Get(i));
		return (Sequence<T>*)linked_list;
	}

	T Pop(int index)
    {
		return this->items->Pop(index);
	}

	void Print(void(*function)(T))
    {
		this->items->Print(function);
	}

	void PushBack(T item)
    {
		this->items->Append(item);
	}

	void PushFront(T item)
    {
		this->items->Prepend(item);
	}

	T PopBack()
    {
		return this->items->Pop(this->items->GetLength() - 1);
	}

	T PopFront()
    {
		return this->items->Pop(0);
	}

	Sequence<T>* Map(T(*function)(T))
    {
		T* arr = NULL;
		DeckSequence<T> map(arr, 0);
		DeckSequence<T>* mapList = &map;
		for (int i = 0; i < this->GetLength(); i++) {
			mapList->Append(function(this->Get(i)));
		}
		return (Sequence<T>*) mapList;
	}

	Sequence<T>* Where(int(*function)(T))
    {
		T* arr = NULL;
		DeckSequence<T> list(arr, 0);
		DeckSequence<T>* whereList = &list;
		for (int i = 0; i < this->GetLength(); i++)
        {
			if (function(this->Get(i)))
				whereList->Append(this->Get(i));
		}
		return (Sequence<T>*) whereList;
	}

	T Reduce(T(*function)(T, T), T startNumber)
    {
		T data = startNumber;
		for (int i = 0; i < this->GetLength(); i++)
			data = function(this->Get(i), data);
		return data;
	}

	Sequence<T>* Sorted(int(*function)(const void*, const void*))
    {
		T* arr = (T*)calloc(this->GetLength(), sizeof(T));
		for (int i = 0; i < this->GetLength(); i++)
			arr[i] = this->Get(i);
		qsort(arr, this->GetLength(), sizeof(T), function);
		DeckSequence<T> list(arr, 0);
		DeckSequence<T>* deckList = &list;
		for (int i = 0; i < this->GetLength(); i++)
			deckList->Append(arr[i]);
		return (Sequence<T>*) deckList;
	}
};

#endif
