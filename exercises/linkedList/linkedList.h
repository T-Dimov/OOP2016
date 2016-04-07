#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(const T& data, Node* next = nullptr) :
		data(data), next(next)
    {}
};

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    LinkedList& operator=(const LinkedList&);

    const T& getAt(size_t) const;

    void insertAtBeginning(const T&);
    void insertAtEnd(const T&);
    bool insertBefore(size_t, const T&);
    bool insertAfter(size_t, const T&);

    bool removeAt(size_t);
    bool removeBefore(size_t);
    bool removeAfter(size_t);

    size_t getSize() const;
    bool isEmpty() const;

	void print() const
	{
		Node<T> *printer = start;
		while(printer)
		{
			std::cout << printer->data << ' ';
			printer = printer->next;
		}
	}
private:

    Node<T>* start;
    size_t size;

    Node<T>* lookUp(size_t)const;

    void copy(const LinkedList&);
    void del();
};

template <typename T>
LinkedList<T>::LinkedList() :start(nullptr), size(0)
{}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    copy(other);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    del();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename T>
const T& LinkedList<T>::getAt(size_t index) const
{
    Node<T>* wantedItem = lookUp(index);

    if (!wantedItem)
    {
        std::cerr << "Index Error" << std::endl;
    }
    else
    {
        return wantedItem->data;
    }
}

template <typename T>
void LinkedList<T>::insertAtEnd(const T& item)
{
    insertAfter(size - 1, item);
}

template <typename T>
bool LinkedList<T>::insertBefore(size_t index, const T& item)
{
    if (index >= size)
    {
        return false;
    }

    if (index == 0)
    {
        insertAtBeginning(item);
    }
    else
    {
        Node<T>* previous = lookUp(index - 1);
        Node<T>* newNode  = new Node<T>(item, previous->next);
        previous->next = newNode;

        ++size;
    }
    return true;
}

template <typename T>
void LinkedList<T>::insertAtBeginning(const T& item)
{
    Node<T>* newNode = new Node<T>(item, start);
    start = newNode;
    ++size;
}

template <typename T>
bool LinkedList<T>::insertAfter(size_t index, const T& item)
{
    if (index >= size)
    {
        return false;
    }

    Node<T>* previous = lookUp(index);
    Node<T>* newNode  = new Node<T>(item, previous->next);
    previous->next = newNode;

    ++size;
    return true;
}

template <typename T>
bool LinkedList<T>::removeAt(size_t index)
{
    if (index >= size)
    {
        return false;
    }

    Node<T>* forRemoval;

    if (index == 0)
    {
        forRemoval = start;
        start = start->next;
    }
    else
    {
        Node<T>* previous = lookUp(index - 1);

        forRemoval = previous->next;
        previous->next = forRemoval->next;
    }

    delete forRemoval;

    --size;
    return true;
}

template <typename T>
bool LinkedList<T>::removeBefore(size_t index)
{
    if (index == 0)
    {
        return false;
    }

    removeAt(index - 1);
    return true;
}

template <typename T>
bool LinkedList<T>::removeAfter(size_t index)
{
    return removeAt(index + 1);
}

template <typename T>
size_t LinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
Node<T>* LinkedList<T>::lookUp(size_t index)const
{
    Node<T>* seeker = start;

    while (seeker && index > 0)
    {
        seeker = seeker->next;
        --index;
    }

    return seeker;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    size = other.size;

    if (!other.start)
    {
        start = nullptr;
        return;
    }

    start = new Node<T>(other.start->data);

    Node<T>* iterThis  = start;
    Node<T>* iterOther = other.start->next;
	Node<T>* newNode = nullptr;

    while (iterOther)
    {
        newNode  = new Node<T>(iterOther->data);
        iterThis->next = newNode;

        iterThis  = newNode;
        iterOther = iterOther->next;
    }
}

template <typename T>
void LinkedList<T>::del()
{
    Node<T>* exterminator;

    while (start)
    {
        exterminator = start;
        start    = start->next;

        delete exterminator;
    }
}

#endif
