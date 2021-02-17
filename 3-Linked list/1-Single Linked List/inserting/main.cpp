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
	void print();
    void insertFirst(int);
	void insertEnd(int);
	void insertAt(int, int);

private:
	nodeType *first, *last;
	int length;
};
linkedListType::linkedListType()
{
	first = last = NULL;
	length = 0;
}
void linkedListType::insertFirst(int item)
{
	nodeType *newNode = new nodeType;
	newNode->info = item;
	if (length == 0) {
		first = last = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = first;
		first = newNode;
	}
	length++;
}

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


void linkedListType::insertAt(int loc, int item)
{
	if (loc < 0 || loc > length)
		cout << "ERROR: Out of range" << endl;
	else
	{
		nodeType *newNode = new nodeType;
		newNode->info = item;
		if (loc == 0) //insert at the begining
			insertFirst(item);
		else if (loc == length) //insert at the end;
			insertEnd(item);
		else
		{
			nodeType *current = first;
			for (int i = 1; i < loc; i++)
				current = current->next;

			newNode->next = current->next;
		    current->next = newNode;
			length++;
		}

	}
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
	l1.insertAt(0, 10);
	l1.insertAt(1, 15);
	l1.insertAt(2, 20);
	l1.insertAt(3, 25);
	l1.print();

	return 0;
}
