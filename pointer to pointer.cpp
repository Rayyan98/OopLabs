#include<iostream>
using namespace std;

struct stac
{

    int arr[10];
    stac();
    int** push(int** index, int** endind, int val);
    int** pop(int** index);

};

stac::stac()
{
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
}

int** stac::push(int** index,int** endind, int val)
{
    if (*index < *endind)
    {
        *index = * index +1;
        **index = val;


    }
    else
        cout<<"Cannot push, please pop"<<endl;
    return index;
}

int** stac::pop(int** index)
{
    if  (*index >= &arr[0])
    {

        cout<<**index<<endl;
        *index = *index-1;

    }
    else
        cout<<"No elements to pop"<<endl;
    return index;

}

int main()
{

   stac stk;
   int* index = &stk.arr[0] - 1;
   int* endind = &stk.arr[3];

   cout << index  << "index " << endl;
   stk.push(&index, &endind, 10);
   cout << index  << "index " << endl;
   stk.push(&index, &endind, 9);
   cout << index  << "index " << endl;
   stk.push(&index, &endind, 8);
   cout << index  << "index " << endl;
   stk.push(&index, &endind, 2);
   cout << index  << "index " << endl;
   stk.push(&index, &endind, 1);
   cout << index  << "index " << endl;
   stk.push(&index, &endind, 1);
   cout << index  << "index " << endl;
   stk.pop(&index);
   cout << index  << "index " << endl;
   stk.pop(&index);
   cout << index  << "index " << endl;
   stk.push(&index, &endind, 11);
   cout << index  << "index " << endl;
   stk.pop(&index);
   cout << index  << "index " << endl;
   stk.pop(&index);
   cout << index  << "index " << endl;
   stk.pop(&index);
   cout << index  << "index " << endl;
   stk.pop(&index);
   cout << index  << "index " << endl;
   stk.pop(&index);
   cout << index  << "index " << endl;
   return 0;
}
