#include <iostream>

using namespace std;

class Node
{
public:
    char value;
    Node* next;
};

class Stack
{
public:
    Node* head;

    Stack()
    {
        head = NULL;
    }

    void Push(char a)
    {
        Node* temp = new Node;
        temp->value = a;
        temp->next = head;
        head = temp;
    }

    char Pop()
    {
        if(head != NULL)
        {
            char temp = head->value;
            Node* t = head->next;
            delete head;
            head = t;
            return temp;
        }
        else
        {
            return '\0';
        }
    }

    char Top()
    {
        if(head != NULL)
        {
            return head->value;
        }
        else
        {
            return '\0';
        }
    }

    ~Stack()
    {
        cout << endl << "haana destroy hogaya";
    }
};

int main()
{
    char exp[] = "(((25+30)*2)/5)";
    Stack s;
    for(int i = 0; i < sizeof(exp) - 1; i++)
    {
        char a=exp[i];
        if(a=='(' || a=='[' || a=='{')
        {
            s.Push(a);
        }
        else if(a==')')
        {
            if(s.Top() == '(' || s.Top() == '\0')
            {
                s.Pop();
            }
            else
            {
                cout << "bad expression";
                return 0;
            }
        }
        else if(a==']')
        {
            if(s.Top() == '[' || s.Top() == '\0')
            {
                s.Pop();
            }
            else
            {
                cout << "bad expression";
                return 0;
            }
        }
        else if(a=='}')
        {
            if(s.Top() == '{' || s.Top() == '\0')
            {
                s.Pop();
            }
            else
            {
                cout << "bad expression";
                return 0;
            }
        }
    }
    if(s.Top() != '\0')
    {
        cout << "bad expression";
    }
    else
    {
        cout << "all good";
    }
    return 0;
}
