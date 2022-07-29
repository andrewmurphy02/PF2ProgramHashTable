//-----------------------------------------------------------
//  Purpose:    Implementation of Address class.
//  Author:     Andrew Murphy
//-----------------------------------------------------------
#include "hash.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
    Size = size;
    homeAddress = new vector<Address>[size];
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable &hashtable)
{
    Size = hashtable.Size;
    homeAddress = new vector <Address>[Size];
    for (int index = 0; index < Size; index++)
    {
        homeAddress[index] = hashtable.homeAddress[index];
    }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
    delete[] homeAddress;
}

//-----------------------------------------------------------
// Insert Method
//-----------------------------------------------------------
bool HashTable::Insert(int key, Address num)
{
    int index = hashtable(key);
    homeAddress[index].push_back(num);
    return true;
}

//-----------------------------------------------------------
// Read file
//-----------------------------------------------------------
void HashTable::read_file(string filename)
{
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
    {
        cout << "Error1";
    }
        string spot = "";
        int hn, zc = 0;
        string hn1, sn, cn, stn, zc1 = "";

        while (!din.eof())
        {
            Address data;
            // Getlines
            getline(din, hn1);
            hn = stoi(hn1);
            getline(din, sn);
            getline(din, cn);
            getline(din, stn);
            getline(din, zc1);
            zc = stoi(zc1);
            // Set the data
            data.set(hn, sn, cn, stn, zc);
            // Insert
            Insert(data.getZipcode(), data);
            // Final getline
            getline (din, spot);
            if (spot.size() == 0)
            continue;
        }
        // Close the file
        din.close();
}

//-----------------------------------------------------------
// Write file
//-----------------------------------------------------------
void HashTable::write_file()
{
    ofstream dout;
    dout.open("hash_address.txt");
    if (dout.fail())
    {
        cout << "Error";
    }
    
    for (int index = 0; index < Size; index++)
    {
        for (int pos = 0; pos < homeAddress[index].size(); pos++)
        {
            dout << homeAddress[index][pos].getHouseNumber() << endl;
            dout << homeAddress[index][pos].getStreetName() << endl;
            dout << homeAddress[index][pos].getCityName() << endl;
            dout << homeAddress[index][pos].getStateName() << endl;
            dout << homeAddress[index][pos].getZipcode() << endl;
        }
    }
}

//-----------------------------------------------------------
// Sets key
//-----------------------------------------------------------
int HashTable::hashtable(int key)
{
    return (key + 1) % Size;
}

//-----------------------------------------------------------
// Search
//-----------------------------------------------------------
void HashTable::Search(int zcode)
{
    int index = hashtable(zcode);
    for (int pos = 0; pos < homeAddress[index].size(); pos++)
    {
        if (homeAddress[index][pos].getZipcode() == zcode)
        {
            homeAddress[index][pos].print();
        }
    }
}

//-----------------------------------------------------------
// Print
//-----------------------------------------------------------
void HashTable::Print()
{
    
}