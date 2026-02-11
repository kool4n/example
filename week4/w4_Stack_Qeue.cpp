// class of stack with static array: 
#include<iostream>
#include <stack>
using namespace std;

class stack_bowls
{
    private: 
    int top, stack_size, max_size;
    public:
    stack<string> myStack;
    stack_bowls(int s) 
   { 
        max_size = s;
        top = -1; 
   }
   int push_item(string x);
   void check_size();
   void isFull();
   void pop_item();
   void isEmpty();
   void disply_stack();
   void check_top();

};
//pushes element on to the stack
int stack_bowls::push_item(string item)
{
    myStack.push(item);
    top = top +1;
    return top;
}
void stack_bowls::check_size()
{
    stack_size = top +1;
    cout << "The size of my stack: " << stack_size << endl;
}
void stack_bowls::isFull()
{
    int cur_size = top +1;
    if (cur_size==max_size)
        cout << "The stack is Full! " << endl;
    else
        cout << "The stack is NOT Full! " << endl;
}
void stack_bowls::pop_item()
{
    myStack.pop();
}
void stack_bowls:: disply_stack()
{
    std::stack<string> temp;

    
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        temp.push(myStack.top());
        myStack.pop();
    }

    cout << endl;

    while (!temp.empty()) {
        myStack.push(temp.top());
        temp.pop();
    }
}
void stack_bowls:: isEmpty()
{
    if (top>=0)
    {
        cout << "My stact is not Empty"; 
    }
    else
    {
        cout << "My stact is Empty"; 
    }
    cout << endl;
}
void stack_bowls:: check_top()
{
    cout << "The color bowl at Top: " << myStack.top() << endl; 
}

int main() 
{
    system ("CLS");
    stack_bowls stack_bowl1(6);
    stack_bowl1.push_item("purple");
    stack_bowl1.push_item("blue");
    stack_bowl1.push_item("green");
    stack_bowl1.push_item("yellow");
    stack_bowl1.push_item("orange");
    stack_bowl1.push_item("red");

    
    stack_bowl1.isEmpty();
     stack_bowl1.check_top();

    stack_bowl1.disply_stack();
    stack_bowl1.check_size();
    stack_bowl1.isFull();
    stack_bowl1.disply_stack();
    stack_bowl1.isEmpty();



    return 0;

}