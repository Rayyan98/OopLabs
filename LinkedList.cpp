#include <iostream>

using namespace std;



class Unit
{
public:
    Unit()
    {
    }
    virtual void Draw()
    {
        cout << " Unit class here ";
    }
    void Mov()
    {
    }
};


class Turret : public Unit
{
public:
    void Draw()
    {
        cout << " Turret class here ";
    }
    void Mov()
    {
    }
};


class Tank : public Unit
{
public:
    Turret* t;
public:
    Tank()
    {
        t = new Turret;
    }
    void Draw()
    {
        cout << " Tank class here ";
    }
    void Mov()
    {
    }
};

class Node
{
public:
    int value;
    Node* prev;
    Node* next;
};

class Stack
{
public:
    Node* head;
    Node* tail;

    Stack()
    {
        head = NULL;
        tail = NULL;
    }

    void Push(int val)
    {
        Node* tmp = new Node;
        tmp->value = val;
        if(tail == NULL)
        {
            tmp->prev = NULL;
            tmp->next = NULL;
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tmp->prev = tail;
            tmp->next = NULL;
            tail = tmp;
        }
    }

    void PushAtFront(int val)
    {
        Node* tmp = new Node;
        tmp->value = val;
        if(head == NULL)
        {
            tmp->prev = NULL;
            tmp->next = NULL;
            head = tmp;
            tail = tmp;
        }
        else
        {
            head->prev = tmp;
            tmp->next = head;
            tmp->prev = NULL;
            head = tmp;
        }
    }

    int Pop()
    {
        if(tail != NULL)
        {
            int a = tail->value;
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            return a;
        }
        else
        {
            cout << " kya kar  raha hay bay" ;
            return -1;
        }
    }

    int PopFromFront()
    {
        if(head != NULL)
        {
            int a = head->value;
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            return a;
        }
        else
        {
            cout << " kya kar  raha hay bay" ;
            return -1;
        }
    }

    void ShowBobAfterHead()
    {
        Node* tmp = head;
        while(tmp != NULL)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void ShowBobBeforeTail()
    {
        Node* tmp = tail;
        while(tmp != NULL)
        {
            cout << tmp->value << " ";
            tmp = tmp->prev;
        }
        cout << endl;
    }
};

int main()
{
//    Unit c;
//    Tank p;
//    p.t->Draw();
    Stack s;
    s.Push(4);
    s.ShowBobAfterHead();
    s.Push(5);
    s.ShowBobAfterHead();
    s.Push(6);
    s.ShowBobAfterHead();
    s.Push(7);
    s.ShowBobAfterHead();
    s.Push(8);
    s.ShowBobAfterHead();
    s.Push(9);
    s.ShowBobAfterHead();
    s.Push(10);
    s.ShowBobAfterHead();
    s.Push(11);
    s.ShowBobAfterHead();
    s.Push(12);
    s.ShowBobAfterHead();
    s.PushAtFront(3);
    s.ShowBobAfterHead();
    s.PushAtFront(2);
    s.ShowBobAfterHead();
    s.PushAtFront(1);
    s.ShowBobAfterHead();
    s.ShowBobBeforeTail();
    s.Pop();
    s.ShowBobAfterHead();
    cout << s.head->value << endl;
    s.Pop();
    s.ShowBobAfterHead();
    s.PopFromFront();
    s.ShowBobAfterHead();
    s.PopFromFront();
    s.ShowBobAfterHead();
}
