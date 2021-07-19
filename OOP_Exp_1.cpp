#include <iostream>
#include <string.h>
using namespace std;

int n;

struct Library
{
    char book_name[100] , auth_name[100];
    int no_copies;
    float book_price;
}s[1000];


void Add_details()
{
    cout << "Enter the number of entries you wish to make " <<endl;
    cin >> n;
    
    if(n >= 0 && n <= 1000 )
    {
        for(int i=0; i<n; i++)
        {
            cout << "Enter the name of book "<< i+1 <<endl;
            cin  >> s[i].book_name;
            cout <<"Enter the Author of book "<< i+1 <<endl;
            cin  >> s[i].auth_name;
            cout <<"Enter the price of book  "<< i+1 <<endl;
            cin  >> s[i].book_price;
            cout << "Enter the number of copies of book "<< i+1 <<endl;
            cin  >> s[i].no_copies;
        }
        cout<<"Successfully entered all the details !"<<endl;
    }
    else 
    {
        cout << "Error ! Please try again. " << endl ;
    }
    
}


void Display()
{
    cout<<"\t Book Name \t\t Author Name \t\t Price \t\t Number of copies "<<endl;
    for (int i=0; i<n; i++)
    {
        cout << i+1 << "\t\t " << s[i].book_name<< "\t\t  " << s[i].auth_name<< "\t\t  " << s[i].book_price<< "\t\t " << s[i].no_copies << endl;
    }
}


void Search_book ()
{
    int flag;
    char search_bname[100];
    cout << "Please enter the name of the book that you want to search: "<<endl;
    cin >> search_bname;

    for (int i = 0; i < n; i++)
    {
        if(strcmp(search_bname , s[i].book_name)==0)
        {
            cout<<" The book is present "<<endl;
            cout<< s[i].book_name << "\t" <<s[i].no_copies<<endl;
            flag++;
        }
        
    }
    if(flag == 0)
    {
        cout<< "The book could not be found. "<<endl;
    } 
}


void Search_auth () 
{   
    int flag;
    char search_aname[100];
    cout << "Please enter the name of the author that you want to search: "<<endl;
    cin >> search_aname;

    for (int i = 0; i < n; i++)
    {
        if(strcmp(search_aname , s[i].auth_name)==0)
        {
            cout<< s[i].book_name << "\t" <<s[i].no_copies<<endl;
            flag++;
        }
        
    } 
    if(flag == 0)
    {
        cout<< "The name of this author is absent"<<endl;
    }
}


void Sort()
{
    int i,j;
    char temp[100];
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
           if(strcmp(s[i].book_name, s[j].book_name)>0)
           {
               strcpy(temp,s[i].book_name);
              strcpy(s[i].book_name ,s[j].book_name);
              strcpy(s[j].book_name ,temp);
           }
      } 
    }    
    Display();
    cout<<"Successfully sorted ! "<<endl;
}



int main()
{
    int ch;

    do
    {
        cout << "1.	Enter the book details in the system." <<endl;
        cout << "2.	Display the complete list of the books." <<endl;
        cout << "3.	Search the book in the library by its name." <<endl;
        cout << "4.	Search the books in the library by Author Name." <<endl;
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





