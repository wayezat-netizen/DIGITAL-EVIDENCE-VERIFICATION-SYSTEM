#include "CaseHashMap.h"

using namespace std;

// Default constructor - initialize empty hash maps
CaseHashMap::CaseHashMap() {
}

// Add case to hash map and initialize empty evidence vector
bool CaseHashMap::addCase(Case c) {
    // O(1) - Hash map operations
    caseMap[c.caseID] = c;
    caseToEvidenceMap[c.caseID] = vector<string>();
    return true;
}

// Get case by ID, return pointer to case or nullptr
Case* CaseHashMap::getCase(string caseID) {
    // O(1) - Hash map lookup
    auto it = caseMap.find(caseID);

    if (it != caseMap.end()) {
        return &caseMap[caseID];
    }
    else {
        return nullptr;
    }
}

// Delete case by ID from both maps
bool CaseHashMap::deleteCase(string caseID) {
    // O(1) - Hash map deletion
    auto it = caseMap.find(caseID);

    if (it != caseMap.end()) {
        caseMap.erase(caseID);
        caseToEvidenceMap.erase(caseID);
        return true;
    }

    return false;
}

// Link evidence to case and increment case evidence counter
bool CaseHashMap::linkEvidenceToCase(string caseID, string evidenceID) {
    // O(1) - Hash map lookup and vector push_back (amortized O(1))
    auto it = caseMap.find(caseID);

    if (it == caseMap.end()) {
        return false;  // Case not found
    }

    caseToEvidenceMap[caseID].push_back(evidenceID);
    caseMap[caseID].totalEvidence++;
    return true;
}

// Get all evidence IDs for a case
vector<string> CaseHashMap::getCaseEvidence(string caseID) {
    // O(1) - Hash map lookup
    auto it = caseToEvidenceMap.find(caseID);

    if (it != caseToEvidenceMap.end()) {
        return it->second;
    }
    else {
        return vector<string>();  // Return empty vector if not found
    }
}

// Get all cases as vector
vector<Case> CaseHashMap::getAllCases() {
    // O(n) - Iterate through all elements
    vector<Case> result;

    for (auto& pair : caseMap) {
        result.push_back(pair.second);
    }

    return result;
}

// Display all cases with their evidence count
void CaseHashMap::displayAllCases() {
    if (caseMap.empty()) {
        cout << "No cases in system" << endl;
        return;
    }

    cout << "========== All Cases in System ==========" << endl;
    for (auto& pair : caseMap) {
        pair.second.display();
        vector<string> evidence = getCaseEvidence(pair.first);
        cout << "Evidence Count: " << evidence.size() << endl;
        cout << "------------------------" << endl;
    }
}

// Get total count of cases
int CaseHashMap::getTotalCases() {
    // O(1) - Size operation
    return caseMap.size();
}