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
	int length;

public:
	Stack()
	{
		head = NULL;
		length=0;
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
		length += 1;
	}

	int Pop()
	{
		if(head != NULL)
		{
			Node* temp = head->next;
			int a=head->value;
			delete head;
			head = temp;
			length -= 1;
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

	int Getlength()
	{
		return length;
	}

	bool Isempty()
	{
		if(head == NULL)
		{
			return false;
		}
		else return true;
	}

	int Bottom(){
		if(head == NULL)
		{
			return -1;
		}

		Node* temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->value;
	}
};


int main()
{
	Stack s;
	cout << s.Isempty() <<endl;
	s.Push(5);
	cout << s.Isempty() <<endl;
	cout<<	s.Top()<<endl;
	s.Push(6);
	s.Push(87);
	s.Push(98);
	cout << s.Getlength() <<endl;
	cout << s.Bottom() << endl;
	cout<<	s.Top()<<endl;
	s.Pop();
	cout<<	s.Top()<<endl;
	s.Pop();
	cout<<	s.Pop()<<endl;
	cout<< s.Top()<<endl;
	cout << s.Isempty() << endl;
	s.Pop();
	cout << s.Isempty()<<endl;
	cout << s.Top()<<endl;
	return 0;
}

