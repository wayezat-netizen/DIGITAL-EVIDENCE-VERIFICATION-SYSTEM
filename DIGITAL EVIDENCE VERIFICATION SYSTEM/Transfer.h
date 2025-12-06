#pragma once
#include <iostream>
#include <string>

using namespace std;

// Transfer structure for tracking chain of custody
struct Transfer {
    // Member variables
    string fromPerson;
    string toPerson;
    string evidenceID;
    string action;
    string timestamp;

    // Default constructor
    Transfer();

    // Parameterized constructor
    Transfer(string from, string to, string evid, string act, string tstamp);

    // Display transfer details
    void display() const;
}; 
