#include <iostream>
#include <string.h>
using namespace std;

int n;

struct Library
{
    char book_name[100] , auth_name[100];
    int no_copies;
    float book_price;
} s[1000];


void Add_details()
{
    cout<<"Success"<<endl;
}


void Display()
{
    cout<<"Success"<<endl;
}


void Search_book ()
{
    cout<<"Success"<<endl;
}


void Search_auth () 
{
    cout<<"Success"<<endl;
}


void Sort()
{
    cout<<"Success"<<endl;
}


int main()
{
    int ch;
    cout << "Enter the number of entries you wish to make " <<endl;
    cin >> n;
    
    do
    {
        cout << "1.	Enter the book details in the system" <<endl;
        cout << "2.	Display the complete list of the books." <<endl;
        cout << "3.	Search the book in the library by its name." <<endl;
        cout << "4.	Search the books in the library by Author Name" <<endl;
        cout << "5.	Sort the list of books by its name." <<endl;
        cout << "6. Exit." <<endl;
        cout << "Please enter a choice: " <<endl;
        cin >> ch ;
        
        switch(ch)
        {
            case 1: Add_details() ;
                    break;
            case 2: Display();
                    break;
            case 3: Search_book();
                    break;
            case 4: Search_auth();
                    break;
            case 5: Sort();
                    break;
            case 6: cout << "Thank You" <<endl;
                    break;
            default:std::cout<<"Invalid choice"<<std::endl;
        }
        
    }while(ch != 6);
}





