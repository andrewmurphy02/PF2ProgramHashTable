#ifndef HASHTABLE_H
#define HASHTABLE_H
//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     Andrew Murphy
//-----------------------------------------------------------
#include "address.h"
class HashTable
{
    public:
        HashTable(int size);
        HashTable(const HashTable & hashtable);
        ~HashTable();

        // Methods
        bool Insert(int key, Address num);
        void Search(int zcode);
        void read_file(string filename);
        void write_file();
        void Print();

    private:
        vector<Address> *homeAddress;
        int hashtable(int key);
        int Size;
       
};
#endif
