#ifndef ADDRESS_H
#define ADDRESS_H

//-----------------------------------------------------------
//  Purpose:    Header file for the Address class.
//  Author:     John Gauch added on by Andrew Murphy
//-----------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//-----------------------------------------------------------
// Define the Address class interface
//-----------------------------------------------------------
class Address
{
 public:
   // Constructors
   Address();
   Address(const Address & address);
   ~Address();

   // Methods
   void set(int hn, string sn, string cn, string stn, int zc);
   int getHouseNumber();
   string getStreetName();
   string getCityName();
   string getStateName();
   int getZipcode();
   void read_address(string filename);
   void write_address();
   void print();
   
 private:
   int House_Number;
   string Street_Name;
   string City_Name;
   string State_Name;
   int Zipcode;
   vector<Address> homeAddress;
};
#endif