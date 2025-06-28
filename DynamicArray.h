#ifndef DYNAMICARRAY
#define DYNAMICARRAY

#include <iostream>

template <class T>
class DynamicArray
{
private:
    int len;
    T* arr;
public:
    DynamicArray(T* items, int count)
    {
        this->arr = (T*) malloc(count * sizeof(T));
        for (int i = 0; i < count; i++)
            this->arr[i] = items[i];
        this->len = count;
    }

    DynamicArray(int size)
    {
        this->arr = (T*) malloc(size * sizeof(T));
        this->len = size;
        for (int i = 0; i < this->len; i++)
            this->arr[i] = NULL;
    }

    DynamicArray(const DynamicArray<T> &dynamicArray)
    {
        this->len = dynamicArray.len;
        this->arr = (T*) malloc(this->len * sizeof(T));
        for (int i = 0; i < this->len; i++)
            this->arr[i] = dynamicArray.arr[i];
    }

    ~DynamicArray()
    {
        if (this->arr)
            free(this->arr);
    }

    T Get(int index)
    {
        try
        {
            if (index >= this->len || index < 0)
                throw std::out_of_range("Incorrect index!\n");
            else
                return this->arr[index];
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    int GetSize()
    {
        return this->len;
    }

    void Set(int index, T value)
    {
        try
        {
            if (index >= len || index < 0)
                throw std::out_of_range("Incorrect index!\n");
            else
                this->arr[index] = value;
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    void Resize(int newSize)
    {
        T *array = (T*) calloc(newSize, sizeof(T));
        for (int i = 0; i < newSize; i++)
        {
            if (i >= this->len)
                array[i] = NULL;
            else
                array[i] = this->arr[i];
        }
        this->arr = array;
        this->len = newSize;
    }

    void Print()
    {
        for (int i = 0; i < this->len; i++) {
            std::cout << this->arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif
