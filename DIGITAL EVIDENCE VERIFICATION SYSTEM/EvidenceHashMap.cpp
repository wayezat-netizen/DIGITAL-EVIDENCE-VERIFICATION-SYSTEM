#include "EvidenceHashMap.h"

using namespace std;

// Default constructor - initialize empty hash map
EvidenceHashMap::EvidenceHashMap() {
}

// Add evidence to hash map
bool EvidenceHashMap::addEvidence(Evidence e) {
    // O(1) - Hash map insertion
    evidenceMap[e.evidenceID] = e;
    return true;
}

// Get evidence by ID, return pointer to evidence or nullptr
Evidence* EvidenceHashMap::getEvidence(string evidenceID) {
    // O(1) - Hash map lookup
    auto it = evidenceMap.find(evidenceID);

    if (it != evidenceMap.end()) {
        return &evidenceMap[evidenceID];
    }
    else {
        return nullptr;
    }
}

// Delete evidence by ID
bool EvidenceHashMap::deleteEvidence(string evidenceID) {
    // O(1) - Hash map deletion
    auto it = evidenceMap.find(evidenceID);

    if (it != evidenceMap.end()) {
        evidenceMap.erase(evidenceID);
        return true;
    }
    else {
        return false;
    }
}

// Check if evidence exists in map
bool EvidenceHashMap::evidenceExists(string evidenceID) {
    // O(1) - Hash map lookup
    return evidenceMap.find(evidenceID) != evidenceMap.end();
}

// Get all evidence as vector
vector<Evidence> EvidenceHashMap::getAllEvidence() {
    // O(n) - Iterate through all elements
    vector<Evidence> result;

    for (auto& pair : evidenceMap) {
        result.push_back(pair.second);
    }

    return result;
}

// Get total count of evidence
int EvidenceHashMap::getTotalCount() {
    // O(1) - Size operation
    return evidenceMap.size();
}

// Display all evidence using their display() method
void EvidenceHashMap::displayAllEvidence() {
    if (evidenceMap.empty()) {
        cout << "No evidence in system" << endl;
        return;
    }

    cout << "========== All Evidence in System ==========" << endl;
    for (auto& pair : evidenceMap) {
        pair.second.display();
        cout << "------------------------" << endl;
    }
}