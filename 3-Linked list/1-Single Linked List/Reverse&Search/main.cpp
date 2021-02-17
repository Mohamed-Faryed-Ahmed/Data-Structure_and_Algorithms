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
	void reversee();
	int Search(int item);

private:
	nodeType *first, *last;
	int length;
};

linkedListType::linkedListType()
{
	first = last = NULL;
	length = 0;
}

void linkedListType::reversee() {
	nodeType *prev, *next, *curr;
	prev = NULL;
	curr = first;
	next = curr->next;
	while (next != NULL)//curr!=NULL
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	first = prev;
}

int linkedListType::Search(int item)
{
	nodeType *current = first;
	int loc = 0;
	while (current != NULL)
	{
		if (current->info == item)
			return loc;
		current = current->next;
		loc++;
	}
	return -1;
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
	l1.insertEnd(11);
	l1.insertEnd(22);
	l1.insertEnd(33);
	l1.insertEnd(44);
	l1.insertEnd(55);
	l1.print();
	cout<<"////////\n";
	l1.reversee();
	l1.print();
	cout<<"////////\n";
	cout<<l1.Search(33);

	return 0;
}
