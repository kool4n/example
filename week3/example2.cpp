#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    string code;
    string country;
    Node* next;
    
    Node(string code, string country)
    {
        this->code = code;
        this->country = country;
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
    
    // Insert at end - O(n)
    void insert_end(string code, string country)
    {
        Node* newNode = new Node(code, country);
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
    
    // Insert at beginning - O(1)
    void insert_begin(string code, string country)
    {
        Node* newNode = new Node(code, country);
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
    
    // Insert at index - O(n)
    void insert_index(int index, string code, string country)
    {
        if (index == 0)
        {
            insert_begin(code, country);
            return;
        }
        
        Node* newNode = new Node(code, country);
        Node* temp = head;
        int count = 0;
        
        while (temp != NULL && count < index - 1)
        {
            temp = temp->next;
            count++;
        }
        
        if (temp == NULL)
        {
            cout << "Index out of range!" << endl;
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    // Remove first node - O(1)
    void remove_front()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    // Remove last node - O(n)
    void remove_end()
    {
        if (head == NULL) 
        {
           cout << "This list is empty!" << endl;
           return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) 
        {
            prev = temp;
            temp = temp->next;
        }
        delete temp;
        prev->next = NULL;
    }
    
    // Remove at index - O(n)
    void remove_index(int index)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (index == 0)
        {
            remove_front();
            return;
        }
        
        Node* temp = head;
        Node* prev = NULL;
        int count = 0;
        
        while (temp != NULL && count < index)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        
        if (temp == NULL)
        {
            cout << "Index out of range!" << endl;
            return;
        }
        
        prev->next = temp->next;
        delete temp;
    }
    
    // Display list - O(n)
    void printList()
    {
        Node* temp = head;
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }
        cout << "Elements of the list are:" << endl;
        while (temp != NULL) {
            cout << "Code: " << temp->code << ", Country: " << temp->country << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Search by code - O(n)
    void search_code(string code)
    {
        int count = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->code == code)
            {
                count = count + 1;
            }
            temp = temp->next;
        }
        if (count == 0)
        {
            cout << "Cannot found code '" << code << "' in the list!" << endl;
        }
        else if (count == 1)
        {
            cout << "Code '" << code << "' Found: non-duplicated element in list!" << endl;
        }
        else
        {
            cout << "Code '" << code << "' Found: duplicated element in list!" << endl;
        }
    }
    
    // Search by country - O(n)
    void search_country(string country)
    {
        int count = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->country == country)
            {
                count = count + 1;
            }
            temp = temp->next;
        }
        if (count == 0)
        {
            cout << "Cannot found country '" << country << "' in the list!" << endl;
        }
        else if (count == 1)
        {
            cout << "Country '" << country << "' Found: non-duplicated element in list!" << endl;
        }
        else
        {
            cout << "Country '" << country << "' Found: duplicated element in list!" << endl;
        }
    }
    
    // Check size - O(n)
    void check_size()
    {
        int size_sl = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            size_sl = size_sl + 1;
            temp = temp->next;
        }
        cout << "The current size of my SL: " << size_sl << endl;
    }
    

};

int main()
{
    system("cls");
    Linkedlist list;
    
    cout << "========== Country Linked List ==========" << endl;
    
    // Insert operations
    cout << "\n--- Inserting at End ---" << endl;
    list.insert_end("US", "United States");
    list.insert_end("JP", "Japan");
    list.printList();
    
    cout << "--- Inserting at Beginning ---" << endl;
    list.insert_begin("GB", "United Kingdom");
    list.insert_begin("DE", "Germany");
    list.printList();
    
    cout << "--- Inserting at Index 2 ---" << endl;
    list.insert_index(2, "CA", "Canada");
    list.printList();
    
    // Check size
    list.check_size();
    
    // Search operations
    cout << "\n--- Searching Elements ---" << endl;
    list.search_code("CA");
    list.search_country("Japan");
    list.search_code("FR");
    
    // Remove operations
    cout << "\n--- Removing Front ---" << endl;
    list.remove_front();
    list.printList();
    
    cout << "--- Removing End ---" << endl;
    list.remove_end();
    list.printList();
    
    cout << "--- Removing at Index 1 ---" << endl;
    list.remove_index(1);
    list.printList();
    
    // Final size
    list.check_size();
    
    return 0;
}