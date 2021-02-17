#include<iostream>
#include<string.h>

using namespace std;
const int MAX_SIZE = 4;
template<class t>
class stack {
	int top;
	t item[MAX_SIZE];
public:
	stack() :top(-1) {}
	bool isEmpty()
	{
		return top < 0;
	}

	void push(t Element)
	{
		if (top >= MAX_SIZE-1)
		{
			cout << "Stack full on push";
		}
		else
		{
			top++;
			item[top] = Element;
		}
	}
	void pop()
	{
		if (isEmpty())
			cout << "stack empty on pop";
		else
			top--;
	}
	void pop(t&Element)
	{
		if (isEmpty())
			cout << "stack empty on pop";
		else {
			Element = item[top];
			top--;
		}
	}
	void getTop(t&stackTop)
	{
		if (isEmpty())
			cout << "stack empty on getTop";
		else {
			stackTop = item[top];
			cout << stackTop << endl;
		}
	}
	void print() {
		cout << "[ ";
		for (int i = top; i >= 0; i--)
		{
			cout << item[i] << " ";
		}
		cout << "]";
		cout << endl;

	}
};
int main() {
	stack<string>s;
	s.push("Pro");
	s.push("Soft");
	s.push("Faryed");
	s.push("Mohamed");
	s.print();
}
