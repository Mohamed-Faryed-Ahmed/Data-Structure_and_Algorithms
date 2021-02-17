#include <iostream>
using namespace std;
struct nodeType
{
	int info;
	nodeType *next;
};
class linkedListType
{
public:
	linkedListType();
	void insertEnd(int item);
	bool isEmpty();
	void print();
	void removeFirst();
	void removeLast();
	void removeAt(int);
	void removee(int item);

private:
	nodeType *first, *last;
	int length;
};

linkedListType::linkedListType()
{
	first = last = NULL;
	length = 0;
}

void linkedListType::removeFirst()
{
	if (length == 0)
		cout << "ERROR: EMPTY LIST" << endl;
	else if (length == 1)
	{
		delete first;
		last = first = NULL;
		length--;
	}
	else
	{
		nodeType *current = first;
		first = first->next;
		delete current;
		length--;
	}
}

void linkedListType::removeLast()
{
	if (length == 0)
		cout << "ERROR: EMPTY LIST" << endl;
	else if (length == 1)
	{
		delete first;
		last = first = NULL;
		length--;
	}
	else
	{
		nodeType *current = first->next;
		nodeType *trailCurrent = first;
		while (current != last)
		{
			trailCurrent = current;
			current = current->next;
		}
		delete current;
		trailCurrent->next = NULL;
		last = trailCurrent;
		length--;
	}
}

void linkedListType::removeAt(int loc)
{
	if (loc < 0 || loc >= length)
		cout << "ERROR: Out of range" << endl;
	else
	{
		nodeType *current, *trailCurrent;
		if (loc == 0)
		{
			current = first;
			first = first->next;
			delete current;
			length--;
			if (length == 0)
				last = NULL;
		}
		else
		{
			current = first->next;
			trailCurrent = first;
			for (int i = 1; i < loc; i++)
			{
				trailCurrent = current;
				current = current->next;
			}

			trailCurrent->next = current->next;
			if (last == current) //delete the last item
				last = trailCurrent;
			delete current;
			length--;
		}
	}
}

void linkedListType::removee(int item)
{
	if (isEmpty())
	{
		cout << "Can not remove from empty list\n";
		return;
	}

	nodeType *current, *trailCurrent;
	if (first->info == item)//delete the first element, special case
	{
		current = first;

		first = first->next;
		delete current;
		length--;
		if (length == 0)
			last = NULL;
	}
	else
	{
		current = first->next;
		trailCurrent = first;
		while (current != NULL)
		{
			if (current->info == item)
				break;
			trailCurrent = current;
			current = current->next;
		}

		if (current == NULL)
			cout << "The item is not there\n";
		else
		{
			trailCurrent->next = current->next;
			if (last == current) //delete the last item
				last = trailCurrent;
			delete current;
			length--;
		}
	}
}

////////////////////////////////////////
void linkedListType::insertEnd(int item)
{
	nodeType *newNode = new nodeType;
	newNode->info = item;
	if (length == 0) {
		first = last = newNode;
		newNode->next = NULL;
	}
	else {
		last->next = newNode;
		newNode->next = NULL;
		last = newNode;
	}
	length++;
}

bool linkedListType::isEmpty()
{
	return (length == 0);
}

void linkedListType::print()
{
	nodeType *current = first;
	while (current != NULL)
	{
		cout << current->info << endl;
		current = current->next;
	}
}

int main()
{
	linkedListType l1;
	l1.insertEnd(15);
	l1.insertEnd(5);
	l1.insertEnd(10);
	l1.insertEnd(50);
	l1.insertEnd(25);
	l1.print();
	cout<<"////////\n";
	l1.removeAt(3);
	l1.print();
	cout<<"////////\n";
	l1.removee(5);
	l1.print();

	return 0;
}
