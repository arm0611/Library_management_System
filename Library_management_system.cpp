/* This program uses array of structures to implement a Library Management System. There is a switch-case
which allows the user to chose whether to add, display, search or sort the list of books. Searching can be
done on the basis of author name or book name. When a case is chosen, it calls the corresponding function
to perform the task. 
*/
#include <iostream>
#include <string.h>
using namespace std;

int n;

struct Library
{
    char book_name[100] , auth_name[100];    //To hold the name of book and author respectively
    int no_copies;                           //Number of copies
    float book_price;                        //The book price . It is in float as price can be in decimal.
}s[1000];


void Add_details()                          // Function to enter the list
{
    cout << "Enter the number of entries you wish to make " <<endl;
    cin >> n;                              // How many entries user wants to make
    
    if(n >= 0 && n <= 1000 )               // To check for underflow and overflow 
    {
        for(int i=0; i<n; i++)
        {
            cout << "Enter the name of book "<< i+1 <<" :" <<endl;
            cin  >> s[i].book_name;
            cout <<"Enter the Author of book "<< i+1 <<" :" <<endl;
            cin  >> s[i].auth_name;
            cout <<"Enter the price of book  "<< i+1 <<" :" <<endl;
            cin  >> s[i].book_price;
            cout << "Enter the number of copies of book "<< i+1 <<" :" <<endl;
            cin  >> s[i].no_copies;
        }
        cout<<"Successfully entered all the details !"<<endl;
    }
    else 
    {
        cout << "Error ! Please try again. " << endl ;  //error message if not successful
    }
    
}


void Display()     //Function to Display the list
{
    cout<<"\t\t\t Book Name \t\t\t Author Name \t\t\t Price \t\t\t Number of copies "<<endl;
    for (int i=0; i<n; i++)
    {
        cout << i+1 << "\t\t " << s[i].book_name<< "\t\t  " << s[i].auth_name<< "\t\t  " << s[i].book_price<< "\t\t " << s[i].no_copies << endl;
    }
    cout<<endl;   //for aesthetic purposes
    cout<<endl;
}


void Search_book ()  //Function to search using book name
{
    int flag = 0 ;        // Flag used to determine if book not found
    char search_bname[100]; // To input which name needs to be sorted
    cout << "Please enter the name of the book that you want to search: "<<endl; 
    cin >> search_bname;

    for (int i = 0; i < n; i++)
    {
        if(strcmp(search_bname , s[i].book_name)==0) //Using strcmp to check if book is present
        {
            cout<<" The book is present "<<endl;     // If strcmp is 0, then book present
            cout<< s[i].book_name << "\t" <<s[i].no_copies<<endl; //Showing book name and number of copies
            flag++;   //Incrementing flag to signify that book found
        }
        
    }
    if(flag == 0) // No change in flag value.Hence, book absent
    {
        cout<< "The book could not be found. "<<endl;
    } 
}


void Search_auth () //Function to search by Author name
{   
    int flag; //To determine if name present or not
    char search_aname[100];  // To input name to search for
    cout << "Please enter the name of the author that you want to search: "<<endl;
    cin >> search_aname;

    for (int i = 0; i < n; i++)
    {
        if(strcmp(search_aname , s[i].auth_name)==0) //Using strcmp to check. Present if value is 0.
        {
            cout<< s[i].book_name << "\t" <<s[i].no_copies<<endl; // Displaying all books from same author.
            flag++;  //Incrementing flag to signify that author found.
        }
        
    } 
    if(flag == 0) // No change in flag value.Hence, author name not found.
    {
        cout<< "The name of this author is absent"<<endl;
    }
}


void Sort() //Function to sort
{
    int i,j;
    char temp[100];     //placeholder
    for(i=0;i<n;i++)    //nested for loop to compare
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
    Display(); // Function called to print sorted list.
    cout<<"Successfully sorted ! "<<endl;
}



int main()
{
    int ch; //To choose a case

    do
    {
        cout << "1.	Enter the book details in the system." <<endl;
        cout << "2.	Display the complete list of the books." <<endl;
        cout << "3.	Search the book in the library by its name." <<endl;
        cout << "4.	Search the books in the library by Author Name." <<endl;
        cout << "5.	Sort the list of books by its name." <<endl;
        cout << "6.      Exit." <<endl;
        cout << "Please enter a choice: " <<endl;
        cin >> ch ;
        
        switch(ch)           //switvh case
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
        
    }while(ch != 6);  //To continue loop till Exit option is chosen.
}





