#include <iostream>
using namespace std;
template <typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	bool empty()const;
	T peek()const;
	void push(T value);
	T pop();
	int getSize()const;
private:
	T* elements;
	int size;
	int capacity;
	void ensureCapacity();
};
template<typename T>
Stack<T>::Stack() : size(0), capacity(16)
{
	elements = new T[capacity];
}
template<typename T>
Stack<T>::Stack(const Stack& stack)
{
	elements = new T[stack.capacity];
	size = stack.size;
	capacity = stack.capacity;
	for (int i = 0; i < size; i++)
	{
		elements[i] = stack.elements[i];
	}
}
template<typename T>
Stack<T>::~Stack()
{
	delete[] elements;
}
template<typename T>
bool Stack<T>::empty()const
{
	return size == 0;
}
template<typename T>
T Stack<T>::peek()const
{
	return elements[size - 1];
}
template<typename T>
void Stack<T>::push(T value)
{
	ensureCapacity();
	elements[size++] = value;
}
template<typename T>
void Stack<T>::ensureCapacity()
{
	if (size >= capacity)
	{
		T* old = elements;
		capacity = 2 * size;
		elements = new T[size * 2];
		for (int i = 0; i < size; i++)
			elements[i] = old[i];
		delete[] old;
	}
}
template<typename T>
T Stack<T>::pop()
{
	return elements[--size];
}
template<typename T>
int Stack<T>::getSize() const
{
	return size;
}
int main()
{
	Stack<char> charStack;
	for (int i = 0; i < 9; i++)
	{
		char x;
		cin >> x;
		charStack.push(x);
	}
	int a, b, temp = 0;
	char z;
	for (int i = 0; i < 4; i++)
	{
		a = charStack.pop();
		z = charStack.pop();
		b = charStack.pop();
		a = a - '0';
		b = b - '0';
		if (z == '+')
			temp = a + b;
		if (z == '-')
			temp = b - a;
		if (z == '*')
			temp = a * b;
		if (z == '/')
			temp = b / a;
		cout << temp << endl;
		temp = temp + '0';
		z = temp;
		charStack.push(z);
	}
	system("pause");
	return 0;
}