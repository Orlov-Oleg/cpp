#include<iostream>
using namespace std;

struct listnode
{
	int value;
	listnode*next;
public:
	listnode();
	listnode(int Val, listnode*Next) :next(Next), value(Val){}
};

class List{
	listnode*head = nullptr;
public:
	void InsertBegin(int n);
	void InsertEnd(int n);
	void Print();
	void Insert(int n, int pos);
	void DelBegin();
	void DelEnd();
	void Del(int pos);
	int Find(int n);
};

void List::InsertBegin(int n){
	head = new listnode(n, head);
}

void List::InsertEnd(int n){
	if (!head)
	{
		head = new listnode(n, head);
	}
	else
	{
		listnode*nxt = head;
		while (nxt->next)
		{
			nxt = nxt->next;
		}
		nxt->next = new listnode(n, nxt->next);
	}
}

void List::Print(){
	listnode*nxt = head;
	while (nxt)
	{
		cout << nxt->value << "\t";
		nxt = nxt->next;
	}
	cout << endl << endl;
}

void List::Insert(int n, int pos){
	if (pos == 0)
	{
		InsertBegin(n);
	}
	else if (pos == -1)
	{
		InsertEnd(n);
	}
	else
	{
		listnode*nxt = head;
		int count = 0;
		while (count++ != (pos - 1))
		{
			nxt = nxt->next;
			if (nxt->next == nullptr)
			{
				nxt->next = new listnode(n, nxt->next);
				return;
			}
		}
		nxt->next = new listnode(n, nxt->next);
	}
}

void List::DelBegin(){
	listnode*temp = head;
	head = head->next;
	delete temp;
}

void List::DelEnd(){
	listnode*temp = head;
	listnode*temp1 = temp;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next)
		{
			temp1 = temp;
		}
	}
	temp1->next = nullptr;
	delete temp;
}

void List::Del(int pos){
	if (pos == 0)
	{
		DelBegin();
	}
	else if (pos == -1)
	{
		DelEnd();
	}
	else
	{
		listnode*temp = head;
		listnode*temp1 = temp;
		int count = 0;
		while (++count != (pos - 1))
		{
			temp = temp->next;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		delete temp1;
	}
}

int List::Find(int n){
	listnode*temp = head;
	int count = 0;
	while (temp)
	{
		if (temp->value == n)
		{
			return count;
		}
		temp = temp->next;
		count++;
	}
	return NULL;
}

int main(){
	List l;

	l.InsertBegin(5);
	l.InsertBegin(3);
	l.Print();

	l.InsertEnd(8);
	l.Print();

	l.InsertBegin(2);
	l.InsertEnd(4);
	l.Print();

	l.Insert(7, 14);
	l.Print();

	l.Insert(1, 0);
	l.Print();

	l.Insert(10, -1);
	l.Print();

	l.Insert(9, 5);
	l.Print();

	l.Del(0);
	l.Print();

	l.Del(-1);
	l.Print();

	l.Del(2);
	l.Print();

	cout << l.Find(10) << endl;

	cout << l.Find(7) << endl;

	return 0;
}