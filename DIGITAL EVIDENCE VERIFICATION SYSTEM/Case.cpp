#include "Case.h"

using namespace std;

// Default constructor - initialize all members to default values
Case::Case() {
    caseID = "";
    caseName = "";
    description = "";
    priority = "";
    status = "";
    createdDate = "";
    totalEvidence = 0;
}

// Parameterized constructor - initialize all members with provided values
Case::Case(string id, string name, string desc, string prio, string stat, string date, int total)
    : caseID(id), caseName(name), description(desc), priority(prio),
    status(stat), createdDate(date), totalEvidence(total) {
}

// Display all case details in formatted output
void Case::display() const {
    cout << "================================" << endl;
    cout << "Case ID: " << caseID << endl;
    cout << "Case Name: " << caseName << endl;
    cout << "Description: " << description << endl;
    cout << "Priority: " << priority << endl;
    cout << "Status: " << status << endl;
    cout << "Created Date: " << createdDate << endl;
    cout << "Total Evidence: " << totalEvidence << endl;
    cout << "================================" << endl;
}
