#include <iostream>

using namespace std;
struct Node{
 int item;
 Node *link;
};

class Queue_Link
{
public:
    Queue_Link();
    void Insertion(int item);
    void Removing(int P);
    void print();

private:
    Node *first;
    Node *Tail;
    Node *POS;
    Node *CUR;
    int length;
};
Queue_Link::Queue_Link()
{
    first=Tail=POS=CUR=NULL;
    length=0;
}
void Queue_Link::Insertion(int item)
{
    Node *C_node=new Node;
    if((Tail&&first)==NULL)
    {
     Tail=C_node;
     first=C_node;
     C_node->link=first;
    }
    else
    {
        Tail->link=C_node;
        C_node->link=first;
        Tail=C_node;
    }
    C_node->item=item;
    length++;

}
void Queue_Link::Removing(int P)
{
    if(first==Tail)
    {
     POS=first;
     first=Tail=NULL;
     delete POS;
     length--;
    }
    else if(P==0)
    {
     POS=first;
     first=first->link;
     Tail->link=first;
     delete POS;
     length--;
    }
    else
    {
        POS=first;
        CUR=first->link;
        for(int i=1; i<P ;i++)
        {
            POS=POS->link;
            CUR=POS->link;
        }
        if(length==P)
        {
            Tail=POS;
            POS->link=first;
            delete CUR;
        }
        else
        {
            POS->link=CUR->link;
            delete CUR;
        }
        length--;
    }
}

void Queue_Link::print()
{
    Node*current = first;
	int C=0;
	while (C < length)
	{
		cout << current->item << endl;
		current = current->link;
		C++;
	}
}

int main()
{
    int P;
    Queue_Link L;
    L.Insertion(5);
    L.Insertion(3);
    L.Insertion(4);
    L.Insertion(2);
    L.Insertion(5);
    L.print();
    cout <<"//////////////" << endl;
    L.Removing(1);
    L.Removing(0);
    L.Removing(2);
    L.print();

    return 0;
}
