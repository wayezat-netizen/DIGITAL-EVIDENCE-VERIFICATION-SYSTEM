#include "Evidence.h"

using namespace std;

// Default constructor - initialize all members to default values
Evidence::Evidence() {
    evidenceID = "";
    caseID = "";
    fileName = "";
    filePath = "";
    fileHash = "";
    fileType = "";
    uploadedBy = "";
    timestamp = "";
    severity = 0;
    urgency = 0;
    isVerified = false;
}

// Parameterized constructor - initialize all members with provided values
Evidence::Evidence(string id, string cid, string fname, string fpath, string fhash,
    string ftype, string uploader, string tstamp, int sev, int urg, bool verified)
    : evidenceID(id), caseID(cid), fileName(fname), filePath(fpath), fileHash(fhash),
    fileType(ftype), uploadedBy(uploader), timestamp(tstamp), severity(sev),
    urgency(urg), isVerified(verified) {
}

// Display all evidence details in formatted output
void Evidence::display() const {
    cout << "================================" << endl;
    cout << "Evidence ID: " << evidenceID << endl;
    cout << "Case ID: " << caseID << endl;
    cout << "File Name: " << fileName << endl;
    cout << "File Path: " << filePath << endl;
    cout << "File Hash: " << fileHash << endl;
    cout << "File Type: " << fileType << endl;
    cout << "Uploaded By: " << uploadedBy << endl;
    cout << "Timestamp: " << timestamp << endl;
    cout << "Severity: " << severity << endl;
    cout << "Urgency: " << urgency << endl;
    cout << "Verified: " << (isVerified ? "Yes" : "No") << endl;
    cout << "================================" << endl;
}