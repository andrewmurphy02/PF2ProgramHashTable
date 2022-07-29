//-----------------------------------------------------------
// Purpose: Main program to test the Address and Hash classes.
//          
//          
// Author:  Andrew Murphy
//-----------------------------------------------------------
#include "address.h"
#include "hash.h"
int main()
{
    Address a;
    HashTable h(10000);
    string command = "";
    while (command != "0")
    {
        // Read user command
        cout << "Welcome to Andrew's Address database\n";
        cout << "\nCommand options\n";
        cout << "   0) quit the program\n";
        cout << "   1) Call read_address and write_address functions\n";
        cout << "   2) Call hash.read and hash.writes methods\n";
        cout << "   3) Search hash table by zipcode\n";
        getline(cin, command);
        //
        if (command == "1")
        {
            a.read_address("address.txt");
            a.write_address();
            return 0;
        }
        //
        if (command == "2")
        {
            h.read_file("address.txt");
            h.write_file();
            return 0;
        }
        //
        if (command == "3")
        {
            int num;
            cout << "Enter zipcode\n";
            cin >> num;
            h.read_file("address.txt");
            h.Search(num);
            //a.print();
            return 0;
        }
    }    
}