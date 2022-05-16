/* Author: YiJia Chen */

#include "Stack.cpp"

int main()
{
    Stack<int> stack;
    for (int i = 1;; i++)
    {
        try
        {
            cout << stack << endl;
            stack.Push(i);
        }
        catch (StackException& ex)
        {
            cout << ex.GetMessage() << endl;
            break;
        }
    }
    for (;;)
    {
        try
        {
            cout << "Pop " << stack.Pop() << endl;
        }
        catch(StackException& ex)
        {
            cout << ex.GetMessage() << endl;
            break;
        }
    }
}