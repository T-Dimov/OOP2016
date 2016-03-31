#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <cassert>

template <typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    ~Stack();

    void push(const T&);
    void pop();
	T top();

    size_t size() const;
    bool empty() const;

private:
    T* items;
    size_t container_size;
    size_t capacity;

    void extend();

    void copy(const Stack&);
    void del();
};

template <typename T>
Stack<T>::Stack() :container_size(0), capacity(16)
{
    items = new T[capacity];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    del();
}

template <typename T>
void Stack<T>::push(const T& item)
{
    if (container_size == capacity)
    {
        extend();
    }

    items[container_size++] = item;
}

template <typename T>
void Stack<T>::pop()
{
    assert(container_size != 0);
    --container_size;
}

template <typename T>
T Stack<T>::top()
{
	return items[container_size - 1];
}

template <typename T>
size_t Stack<T>::size() const
{
    return container_size;
}

template <typename T>
bool Stack<T>::empty() const
{
    return container_size == 0;
}

template <typename T>
void Stack<T>::extend()
{
    T* oldItems = items;
    capacity *= 2;
    items = new T[capacity];

    for (size_t i = 0; i < container_size; ++i)
    {
        items[i] = oldItems[i];
    }

    delete[] oldItems;
}

template <typename T>
void Stack<T>::copy(const Stack<T>& other)
{
    container_size     = other.container_size;
    capacity = other.capacity;
    items    = new T[capacity];

    for (size_t i = 0; i < container_size; ++i)
    {
        items[i] = other.items[i];
    }
}

template <typename T>
void Stack<T>::del()
{
    delete[] items;
}

#endif // STACK_H_INCLUDED
