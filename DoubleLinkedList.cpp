#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;
};

class LinkedList
{
public:

	Node* head;
	Node* tail;
	int length;


	LinkedList()
	{
		head = NULL;
		tail = NULL;
		length = 0;
	}

	void AddToQueue(int a)
	{
		if(tail == NULL)
		{
			tail = new Node;
			tail->value = a;
			tail->next = NULL;
			tail->prev = NULL;
			head = tail;
		}
		else
		{
			tail->next = new Node;
			tail->next->value = a;
			tail->next->next = NULL;
			tail->next->prev = tail;
			tail = tail->next;
		}
		length += 1;
	}

	void AddToFront(int a)
	{
		if(head == NULL)
		{
			head = new Node;
			head->next = NULL;
			head->prev = NULL;
			head->value = a;
			tail = head;
		}
		else
		{
			head->prev = new Node;
			head->prev->value = a;
			head->prev->next = head;
			head->prev->prev = NULL;
			head = head->prev;
		}
		length += 1;
	}

	int PopFromTail()
	{
		if(tail == NULL)
		{
			return -1;
		}
		else
		{
			Node* temp = tail->prev;
			int a = tail->value;
			delete tail;
			tail = temp;
			tail->next = NULL;
			length -= 1;
			return a;
		}
	}

	int RemoveFromFront()
	{
		if(head == NULL)
		{
			return -1;
		}
		else
		{
			Node* temp = head->next;
			int a = head->value;
			delete head;
			head = temp;
			head->prev = NULL;
			length -=1;
			return a;
		}
	}

	void ForwardPrint()
	{
		if(head == NULL)
		{
			cout << "List Empty" << endl;
			return;
		}
		Node* temp = head;
		while(temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void BackwardPrint()
	{
		if(tail == NULL)
		{
			cout << "List Empty" << endl;
			return;
		}
		Node* temp = tail;
		while(temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->prev;
		}
		cout << endl;
	}

	void InsertAt(int val, int pos)
	{
		if(pos < 0)
			cout << "bad postition" << endl;
		else if(pos >= length)
			AddToQueue(val);
		else if(pos == 0)
			AddToFront(val);
		else
		{
			Node* temp = head;
			for(int i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			Node* tnode = new Node;
			tnode->value = val;
			tnode->prev = temp;
			tnode->next = temp->next;
			temp->next = tnode;
			length  += 1;
		}
	}

	int PopAt(int pos)
	{
		if(pos < 0 || pos >= length)
		{
			cout << "bad postition" << endl;
			return -1;
		}
		else if(pos == length - 1)
			return PopFromTail();
		else if(pos == 0)
			return RemoveFromFront();
		else
		{
			Node* temp = head;
			for(int i = 0; i < pos -1; i++)
			{
				temp = temp->next;
			}
			Node* tNode = temp->next->next;
			int a = temp->next->value;
			delete temp->next;
			temp->next = tNode;
			tNode->prev = temp;
			length -= 1;
			return a;
		}
	}

	void ChangeValAt(int val, int pos)
	{
		if(pos < 0 || pos >= length)
			cout << "bad position";
		else
		{
			Node* temp = head;
			for(int i = 0; i < pos; i++)
			{
				temp = temp->next;
			}
			temp->value = val;
		}
	}
};

int main()
{
	LinkedList l;
	l.AddToFront(4);
	l.AddToFront(5);
	l.AddToFront(6);
	l.AddToQueue(3);
	l.AddToQueue(2);
	l.AddToQueue(1);
	l.ForwardPrint();
	l.BackwardPrint();
	l.InsertAt(12,0);
	l.InsertAt(13,1);
	l.InsertAt(14,2);
	l.ForwardPrint();
	l.PopFromTail();
	l.RemoveFromFront();
	l.ForwardPrint();
	l.PopAt(1);
	l.ForwardPrint();
	l.PopAt(4);
	l.ForwardPrint();
	l.ChangeValAt(54,3);
	l.ForwardPrint();
}


