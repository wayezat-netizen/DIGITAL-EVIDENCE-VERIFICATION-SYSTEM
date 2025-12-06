#include "Transfer.h"

using namespace std;

// Default constructor - initialize all members to default values
Transfer::Transfer() {
    fromPerson = "";
    toPerson = "";
    evidenceID = "";
    action = "";
    timestamp = "";
}

// Parameterized constructor - initialize all members with provided values
Transfer::Transfer(string from, string to, string evid, string act, string tstamp)
    : fromPerson(from), toPerson(to), evidenceID(evid), action(act), timestamp(tstamp) {
}

// Display all transfer details in formatted output
void Transfer::display() const {
    cout << "================================" << endl;
    cout << "From: " << fromPerson << endl;
    cout << "To: " << toPerson << endl;
    cout << "Evidence ID: " << evidenceID << endl;
    cout << "Action: " << action << endl;
    cout << "Timestamp: " << timestamp << endl;
    cout << "================================" << endl;
}