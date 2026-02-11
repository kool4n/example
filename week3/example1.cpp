#include<iostream>
using namespace std;

class myArray
{
    public: 
    int max_arr, size_arr, arr [];
    myArray(int max)
    {
        max_arr = max;
        arr[max_arr];
    }
    void display_arr()
    {
        cout << "The element in array: ";
        for(int i=0;i<size_arr;i++)
        {
          cout<<arr[i]<<" ";
        }
    }
    void insert_arr()
    {
        cout<<"Enter the Size for Array: ";
        cin>>size_arr;
        cout<<"Enter "<<size_arr<<" Array Elements: ";
        for(int i=0; i<size_arr; i++)
            {
                cin>>arr[i];
            }
    }
    void insert_arr_pos()
    {
        // Ask what element and position of array want to insert
        int i, pos, elem;
        cout<<"\nEnter Element to Insert: ";
        cin>>elem;
        cout<<"At What Position ? ";
        cin>>pos;
        // adding new element regarding to position 
        for(i=size_arr; i>pos; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[i] = elem;
        size_arr++;
        
        cout << "The element in array after adding NEW element: ";
        for(int i=0;i<size_arr;i++)
        {
          cout<<arr[i]<<" ";
        }
        cout << endl;
    }
    void insert_arr_begine()
    {
        // Ask what element of array want to insert
        int i, elem;
        cout<<"\nEnter NEW Element to Insert at BEGINE: ";
        cin>>elem;
        // adding new element regarding to position 
        for(i=size_arr; i>0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = elem;
        size_arr++;
        cout << "The element in array after adding NEW element to BEGINE: ";
        for(int i=0;i<size_arr;i++)
        {
          cout<<arr[i]<<" ";
        }
        cout << endl;
    }
    void insert_arr_ending()
    {
        // Ask what element of array want to insert
        int i, elem;
        cout<<"\nEnter NEW Element to Insert at ENDING: ";
        cin>>elem;
        arr[size_arr] = elem;
        size_arr++;
        cout << "The element in array after adding NEW element to ENDING: ";
        for(int i=0;i<size_arr;i++)
        {
          cout<<arr[i]<<" ";
        }
        cout << endl;
    }
     void deleted_arr_pos()
    {
        // Ask what element and position of array want to insert
        int i, pos;
        cout<<"At What Position of array to be deleted ? ";
        cin>>pos;
        // adding new element regarding to position 
        for (i=pos; i<size_arr-1; i++)
        {
            arr[i] = arr[i+1];  
        }
        size_arr--;
        cout << "The element in array after deleting element: ";
        for(int i=0;i<size_arr;i++)
        {
          cout<<arr[i]<<" ";
        }
        cout << endl;
    }
    void search_element()
    {
        int new_elem;
        cout<<"Enter the element that you are looking ";
        cin>> new_elem;
        int count = 0;
        for(int i=0;i<size_arr;i++)
        {
            if(arr[i]==new_elem)
            {
                count++;
            }
        }
        if(count>1)
            {
                cout<< "We found the element and it is the duplicated number which found "<< count <<" times in array.";
            }
        else if(count ==1)
            {
                cout<< "We found the element but it is not duplicated number.";
            }
        else
            {
                cout <<"The number " << new_elem<<" has no in array.";
            }
    }

};

int main()
{
      // To clear the screen in Visual C++
    myArray arr_1(100);
    arr_1.insert_arr();
    arr_1.display_arr();
    arr_1.insert_arr_pos();
    arr_1.insert_arr_begine();
    arr_1.insert_arr_ending();
    arr_1.search_element();
    return 0;
}