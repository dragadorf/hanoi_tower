#include <iostream>

using namespace std;

struct brick
{
    int level;
    int column;
    int brick_width;
};

const int n = 8;


int main()
{
    brick stack_A [n];
    brick stack_B [n];
    brick stack_C [n];

    for (int i=0; i<n; i++)
    {
        stack_A[i].level=8-i;
        stack_A[i].column=1;

    switch(i)
    {
    case 0:
        stack_A[i].brick_width=100;
        break;
    case 1:
        stack_A[i].brick_width=90;
        break;
    case 2:
        stack_A[i].brick_width=80;
        break;
    case 3:
        stack_A[i].brick_width=70;
        break;
    case 4:
        stack_A[i].brick_width=60;
        break;
    case 5:
        stack_A[i].brick_width=50;
        break;
    case 6:
        stack_A[i].brick_width=40;
        break;
    case 7:
        stack_A[i].brick_width=30;
        break;
    }
        cout<<stack_A[i].level<<endl;
        cout<<stack_A[i].column<<endl;
        cout<<stack_A[i].brick_width<<endl;

    }

    return 0;
}
