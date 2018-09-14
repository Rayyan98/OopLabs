#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
};

class Stack
{
private:

	Node* head;

public:
	Stack()
	{
		head = NULL;
	}

	~Stack()
	{

	}

	void Push(int val)
	{
		if(head == NULL)
		{
			head = new Node;
			head->value = val;
			head->next = NULL;
		}
		else
		{
			Node* temp = head;
			head = new Node;
			head->value = val;
			head->next=temp;
		}
	}

	int Pop()
	{
		if(head != NULL)
		{
			Node* temp = head->next;
			int a=head->value;
			delete head;
			head = temp;
			return a;
		}
		return -1;
	}

	int Top()
	{
		if(head != NULL)
		{
		return head->value;			
		}
		return -1;
	}
};


int main()
{
	Stack s;
	s.Push(5);
	cout<<	s.Top();
	s.Push(6);
	s.Push(87);
	s.Push(98);
	cout<<	s.Top();
	s.Pop();
	cout<<	s.Top();
	s.Pop();
	cout<<	s.Top();
	s.Pop();
	cout<< s.Top();
	s.Pop();
	cout << s.Top();
	return 0;
}

