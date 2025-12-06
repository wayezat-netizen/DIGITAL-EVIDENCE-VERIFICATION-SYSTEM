#pragma once 
#include <iostream>
#include <string>

using namespace std;

// Evidence structure for Digital Evidence Verification System
struct Evidence {
    // Member variables
    string evidenceID;
    string caseID;
    string fileName;
    string filePath;
    string fileHash;
    string fileType;
    string uploadedBy;
    string timestamp;
    int severity;
    int urgency;
    bool isVerified;

    // Default constructor
    Evidence();

    // Parameterized constructor
    Evidence(string id, string cid, string fname, string fpath, string fhash,
        string ftype, string uploader, string tstamp, int sev, int urg, bool verified);

    // Display evidence details
    void display() const;
};
