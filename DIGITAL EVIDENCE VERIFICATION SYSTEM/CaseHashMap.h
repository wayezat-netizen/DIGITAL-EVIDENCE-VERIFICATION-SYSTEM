#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Case.h"

using namespace std;

// Hash Map-based case storage system with evidence linking
class CaseHashMap {
private:
    // Hash map storing caseID as key and Case object as value
    unordered_map<string, Case> caseMap;

    // Hash map storing caseID as key and vector of evidenceIDs as value
    unordered_map<string, vector<string>> caseToEvidenceMap;

public:
    // Default constructor
    CaseHashMap();

    // Add case to hash map - O(1)
    bool addCase(Case c);

    // Get case by ID - O(1)
    Case* getCase(string caseID);

    // Delete case by ID - O(1)
    bool deleteCase(string caseID);

    // Link evidence to case - O(1)
    bool linkEvidenceToCase(string caseID, string evidenceID);

    // Get all evidence IDs for a case - O(1)
    vector<string> getCaseEvidence(string caseID);

    // Get all cases as vector - O(n)
    vector<Case> getAllCases();

    // Display all cases - O(n)
    void displayAllCases();

    // Get total count of cases - O(1)
    int getTotalCases();
};
#pragma once
