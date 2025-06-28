#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>

template <class T>
struct ListItem
{
	struct ListItem* next;
	T data;
};

template <class T>
class LinkedList
{
private:
	int len;
	ListItem <T>* head;
	ListItem <T>* tail;
public:
	LinkedList(T* items, int count)
    {
        this->len = count;
        for (int i = 0; i < count; i++)
        {
            ListItem<T>* ptr = (ListItem<T>*) malloc(sizeof(ListItem<T>));
            ptr->data = items[i];
            ptr->next = NULL;
            if (!i)
            {
                this->head = ptr;
                this->tail = ptr;
            }
            else
            {
                this->tail->next = ptr;
                this->tail = ptr;
            }
        }
    }

	LinkedList()
    {
		this->len = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	LinkedList(const LinkedList <T> &list)
    {
		this->len = list.len;
		struct ListItem<T>* ptr_list = list.head;
		this->head = ptr_list;
		while (ptr_list)
        {
			this->len += 1;
			this->tail->next = ptr_list;
			this->tail = ptr_list;
			ptr_list = ptr_list->next;
		}
		this->tail->next = NULL;
	}

	~LinkedList()
    {
		struct ListItem<T>* ptr = this->head;
		struct ListItem<T>* ptr_prev;
		while (ptr) {
			ptr_prev = ptr;
			ptr = ptr->next;
			free(ptr_prev);
		}
	}

	T GetFirst()
    {
		try
        {
			if (!this->len)
				throw(std::out_of_range("The linked list is empty!\n"));
			else
				return this->head->data;
		}
		catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
	}

	T GetLast()
    {
		try
        {
			if (!this->len)
				throw(std::out_of_range("The linked list is empty!\n"));
			else
				return this->tail->data;
		}
		catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
	}

	T Get(int index)
    {
		try
        {
			if (this->len <= index || index < 0)
				throw std::out_of_range("Incorrect index!\n");
			else
            {
				struct ListItem<T>* ptr = this->head;
				int i = 0;
				while (i != index)
                {
					ptr = ptr->next;
					i++;
				}
				return ptr->data;
			}
		}
		catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
	}

	int GetLength()
    {
		return this->len;
	}

	void Append(T item)
    {
		this->len += 1;
		struct ListItem<T>* ptr = (ListItem<T>*) malloc(sizeof(struct ListItem<T>));
		ptr->next = NULL;
		ptr->data = item;
		if (this->tail == NULL && this->head == NULL)
        {
			this->head = ptr;
			this->tail = ptr;
		}
		else
        {
			this->tail->next = ptr;
			this->tail = ptr;
		}
	}

	void Prepend(T item)
    {
		this->len += 1;
		struct ListItem<T>* ptr = (struct ListItem<T>*) malloc(sizeof(struct ListItem<T>));
        ptr->data = item;
		ptr->next = this->head;
		this->head = ptr;
	}

	void InsertAt(T item, int index)
    {
		try
        {
			if (this->len <= index || index < 0)
				throw std::out_of_range("Incorrect index!\n");
			else
            {
				this->len += 1;
                struct ListItem<T>* ptr_prev = this->head;
				struct ListItem<T>* ptr = (struct ListItem<T>*) malloc(sizeof(struct ListItem<T>));
				ptr->next = NULL;
				ptr->data = item;

				if (!index)
					this->Prepend(item);
				else if (index == this->len)
					this->Append(item);
				else
                {
                    int i = 0;
					while (i != index - 1)
                    {
						ptr_prev = ptr_prev->next;
						i++;
					}
					ptr->next = ptr_prev->next;
					ptr_prev->next = ptr;
				}
			}
		}
		catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
	}

    LinkedList <T>* Concat(LinkedList <T>* list1, LinkedList <T>* list2)
    {
		struct LinkedList <T>* linked_list = list1;
		struct ListItem<T>* ptr = list2->head;
		while (ptr)
        {
			linked_list->Append(ptr->data);
			ptr = ptr->next;
		}
		return linked_list;
	}

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        try
        {
            if (this->len <= startIndex || startIndex < 0)
                throw std::out_of_range("Incorrect start index\n");
            else if (this->len <= endIndex || endIndex < 0)
                throw std::out_of_range("Incorrect end index\n");
            else
            {
                LinkedList<T>* linked_list = new LinkedList();
                int index = 0;
                ListItem<T>* ptr = this->head;
                while ((index < endIndex + 1) && ptr)
                {
                    if (index >= startIndex)
                        linked_list->Append(ptr->data);
                    index++;
                    ptr = ptr->next;
                }
                return linked_list;
            }
        }
        catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

	void Print()
    {
		ListItem<T>* ptr = this->head;
		while (ptr)
        {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}
};

#endif
