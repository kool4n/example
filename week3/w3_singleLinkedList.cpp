#include <iostream>
using namespace std;
class Node 
{
public:
  int data;
  Node* next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};
class Linkedlist 
{
  Node* head;
    public:
    Linkedlist() 
    {
        head = NULL; 
    }
    void insert_end(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insert_begine(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void remove_front()
    {
        if (head->next==NULL)
        {
            return;
        }
        head = head->next;
    }
    void remove_end()
    {
        if (head == NULL) 
        {
           cout << "This list is empty!";
           return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) 
        {
            prev =temp;
            temp = temp->next;
        }
        delete temp;
        prev->next = NULL;
        return;
    }
    void printList()
    {
        Node* temp = head;
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }
        cout << "Elements of the list are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<< endl;
    }
    void search_elm(int item)
    {
        int count = 0;
        Node* temp = head;
        while (temp!=NULL)
        {
            if (temp->data==item)
            {
                count = count + 1;
            }
            temp = temp->next;
        }
        if (count==0)
        {
            cout << "Cannot found " << item << " in the list!" << endl;
        }
        else if (count ==1)
        {
            cout << item << " Found:non-douplicated element in list!" << endl;
        }
        else
        {
            cout << item << " Found: douplicated element in list!" << endl;
        }
    }
    void check_size()
    {
        int size_sl = 0;
        Node* temp = head;
        while (temp!=NULL)
        {
            size_sl = size_sl +1;
            temp = temp->next;
        }
        cout << "The current size of my SL: " << size_sl << endl;
    }
};
int main()
{
    system("cls");
  Linkedlist list;
  list.insert_end(64);
  list.insert_end(33);
    list.insert_begine(22);
    list.insert_begine(100);
    list.check_size();
    list.printList();

   
    
  return 0;
}