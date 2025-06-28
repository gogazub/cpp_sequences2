#ifndef ARRAYSEQUENCE
#define ARRAYSEQUENCE

#include <iostream>
#include "DynamicArray.h"
#include "Sequence.h"

template <class T>
class ArraySequence : Sequence <T>
{
private:
	DynamicArray <T>* items;
public:
	ArraySequence(T* items, int count)
    {
		this->items = new DynamicArray<T>(items, count);
	}

	ArraySequence(int size)
    {
		this->items = new DynamicArray<T>(size);
	}

	ArraySequence(const DynamicArray<T> &dynamicArray)
    {
		this->items = dynamicArray;
	}

	~ArraySequence()
    {
		this->items->~DynamicArray<T>();
	}

	T GetFirst()
    {
		return this->items->Get(0);
	}

	T GetLast()
    {
		return this->items->Get(this->items->GetSize() - 1);
	}

	T Get(int index)
    {
		return this->items->Get(index);
	}

	Sequence<T>* GetSubsequence(int startIndex, int endIndex)
    {
        try
        {
            if (startIndex < 0 || startIndex > this->GetLength() || endIndex < 0 ||
                endIndex > this->GetLength() || endIndex < startIndex)
                throw std::out_of_range("Incorrect index\n");
            else
            {
                T *items = new T[endIndex - startIndex + 1];
                for (int i = startIndex; i <= endIndex; i++)
                    items[i - startIndex] = this->Get(i);
                Sequence<T> *sequence = new ArraySequence(items, endIndex - startIndex + 1);
                return (Sequence<T> *) sequence;
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

	int GetLength()
    {
		return this->items->GetSize();
	}

	void Append(T item)
    {
		this->items->Resize(this->items->GetSize() + 1);
		this->items->Set(this->items->GetSize() - 1, item);
	}

	void Prepend(T item)
    {
		this->items->Resize(this->items->GetSize() + 1);
		for (int i = this->GetLength() - 1; i > 0; i--)
			this->items->Set(i, this->items->Get(i - 1));
		this->items->Set(0, item);
	}

	void InsertAt(T item, int index)
    {
		this->items->Resize(this->items->GetSize() + 1);
		for (int i = this->GetLength() - 1; i > index; i--)
			this->items->Set(i, this->items->Get(i - 1));
		this->items->Set(index, item);
	}

	Sequence<T>* Concat(Sequence<T>* list)
    {
		ArraySequence<T>* sequence = this;
		int len = this->GetLength();
		for (int i = len; i < len + list->GetLength(); i++)
			sequence->Append(list->Get(i - len));
		return (Sequence<T>*) sequence;
	}

	void Print()
    {
		this->items->Print();
	}
};

#endif
