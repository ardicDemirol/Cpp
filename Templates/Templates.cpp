#include <iostream>
using namespace std;


template <typename T>
void printArray(const T* const array, int count)
{
	for (int i = 0; i < count; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main()
{
	const int aCount = 5;
	const int bCount = 7;
	const int cCount = 6;

	int a[aCount] = { 1, 2, 3, 4, 5 };
	double b[bCount] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	char c[cCount] = "HELLO";

	cout << "Array a contains:" << endl;

	printArray(a, aCount);

	cout << "Array b contains:" << endl;

	printArray(b, bCount);

	cout << "Array c contains:" << endl;

	printArray(c, cCount);
}


///////////////// ----------------------------- //////////////////////


#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	Stack(int = 10);
	~Stack() {
		delete[] stackPtr;
	}
	bool push(const T &);
	bool pop(T &);

	bool isEmpty() const {
		return top == -1;
	}

	bool isFull() const {
		return top == size - 1;
	}

private:
	int size;
	int top;
	T* stackPtr;
};

template <typename T>
Stack<T>::Stack(int s)
	: size(s > 0 ? s : 10),
	top(-1),
	stackPtr(new T[size])
{
	// empty body
}	

template <typename T>
bool Stack<T>::push(const T& pushValue)
{
	if (!isFull())
	{
		stackPtr[++top] = pushValue;
		return true;
	}
	return false;
}

template <typename T>
bool Stack<T>::pop(T& popValue)
{
	if (!isEmpty())
	{
		popValue = stackPtr[top--];
		return true;
	}
	return false;
}

#endif

int main() {
	Stack<double> doubleStack(5);
	double doubleValue = 1.1;

	cout << "Pushing elements onto doubleStack\n";

	while (doubleStack.push(doubleValue))
	{
		cout << doubleValue << ' ';
		doubleValue += 1.1;
	}

	cout << "\nStack is full. Cannot push " << doubleValue
		<< "\n\nPopping elements from doubleStack\n";
}


