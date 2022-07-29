//-----------------------------------------------------------
//  Purpose:    Implementation of Address class.
//  Author:     John Gauch added on by Andrew Murphy
//-----------------------------------------------------------
#include "address.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
Address::Address()
{
   House_Number = 0;
   Street_Name = "";
   City_Name = "";
   State_Name = "";
   Zipcode = 0;
}


//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
Address::Address(const Address & address)
{
   House_Number = address.House_Number;
   Street_Name = address.Street_Name;
   City_Name = address.City_Name;
   State_Name = address.State_Name;
   Zipcode = address.Zipcode;
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
Address::~Address()
{
}

//-----------------------------------------------------------
// Set method
//-----------------------------------------------------------
void Address::set(int hn, string sn, string cn, string stn, int zc)
{
    House_Number = hn;
    Street_Name = sn;
    City_Name = cn;
    State_Name = stn;
    Zipcode = zc;
}

//-----------------------------------------------------------
// Get house number
//-----------------------------------------------------------
int Address::getHouseNumber() 
{
    return House_Number;
}

//-----------------------------------------------------------
// Get street name
//-----------------------------------------------------------
string Address::getStreetName()
{
    return Street_Name;
}

//-----------------------------------------------------------
// Get city name
//-----------------------------------------------------------
string Address::getCityName()
{
    return City_Name;
}

//-----------------------------------------------------------
// Get state name
//-----------------------------------------------------------
string Address::getStateName()
{
    return State_Name;
}

//-----------------------------------------------------------
// Get zipcode
//-----------------------------------------------------------
int Address::getZipcode()
{
    return Zipcode;
}

//-----------------------------------------------------------
// Reads file
//-----------------------------------------------------------
void Address::read_address(string filename)
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
            // Pushback
            homeAddress.push_back (data);
            // Final getline
            getline (din, spot);
            if (spot.size() == 0)
            continue;
        }
        // Close the file
        din.close();
}

//-----------------------------------------------------------
// Writes file
//-----------------------------------------------------------
void Address::write_address()
{
    ofstream dout;
	dout.open("sort_address.txt");
    if (dout.fail())
    {
        cout << "Error";
    }
    dout << homeAddress.size();
	for (int index = 0; index < homeAddress.size(); index++)
    {
        dout << endl;
        dout << homeAddress[index].getHouseNumber() << endl;
        dout << homeAddress[index].getStreetName() << endl;
        dout << homeAddress[index].getCityName() << endl;
        dout << homeAddress[index].getStateName() << endl;
        dout << homeAddress[index].getZipcode() << endl;
    }
	dout.close();
}

//-----------------------------------------------------------
// Print
//-----------------------------------------------------------
void Address::print()
{
   
    cout << getHouseNumber() << " ";
    cout << getStreetName() << " ";
    cout << getCityName() << " ";
    cout << getStateName() << " ";
    cout << getZipcode() << endl;

}