#pragma once
#include <iostream>
#include <string>

using namespace std;

// Case structure for Digital Evidence Verification System
struct Case {
    // Member variables
    string caseID;
    string caseName;
    string description;
    string priority;
    string status;
    string createdDate;
    int totalEvidence;

    // Default constructor
    Case();

    // Parameterized constructor
    Case(string id, string name, string desc, string prio, string stat, string date, int total = 0);

    // Display case details
    void display() const;
};
#pragma once
