#include "IntegrityChecker.h"

using namespace std;

// Default constructor - initialize empty hash table
IntegrityChecker::IntegrityChecker() {
}

// Compute checksum using DJB2 hash algorithm
// Simple DJB2 hash for demo. Use SHA-256 in production.
string IntegrityChecker::computeChecksum(string data) {
    unsigned long hash = 5381;

    for (char c : data) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }

    return to_string(hash);
}

// Add evidence with checksum to hash table
void IntegrityChecker::addEvidence(string evidenceID, string checksum) {
    // Time Complexity: O(1) - Hash table insertion
    checksumTable[evidenceID] = checksum;
}

// Verify if evidence checksum matches stored value
bool IntegrityChecker::verifyEvidence(string evidenceID, string currentChecksum) {
    // Time Complexity: O(1) - Hash table lookup and comparison

    // Check if evidence exists in table
    if (checksumTable.find(evidenceID) == checksumTable.end()) {
        return false;  // Evidence not found
    }

    // Compare stored checksum with current checksum
    return checksumTable[evidenceID] == currentChecksum;
}

// Retrieve stored checksum for evidence
string IntegrityChecker::getChecksum(string evidenceID) {
    // Time Complexity: O(1) - Hash table lookup
    auto it = checksumTable.find(evidenceID);

    if (it != checksumTable.end()) {
        return it->second;  // Return stored checksum
    }

    return "";  // Evidence not found
}

// Remove evidence from hash table
void IntegrityChecker::removeEvidence(string evidenceID) {
    // Time Complexity: O(1) - Hash table deletion
    checksumTable.erase(evidenceID);
}

// Get total number of evidence items
int IntegrityChecker::getTotalEvidence() {
    // Time Complexity: O(1) - Size operation
    return checksumTable.size();
}

// Display all evidence and checksums
void IntegrityChecker::displayAll() {
    if (checksumTable.empty()) {
        cout << "No evidence in integrity checker" << endl;
        return;
    }

    cout << "========== Integrity Checker Contents ==========" << endl;
    for (auto& pair : checksumTable) {
        cout << "Evidence ID: " << pair.first << " | Checksum: " << pair.second << endl;
    }
    cout << "=================================================" << endl;
}