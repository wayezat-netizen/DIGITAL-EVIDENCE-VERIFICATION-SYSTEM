#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Hash Table-based integrity checker for evidence verification
class IntegrityChecker {
private:
    // Hash table mapping evidenceID to checksum value
    unordered_map<string, string> checksumTable;

    // Compute checksum using DJB2 hash algorithm
    // Simple DJB2 hash for demo. Use SHA-256 in production.
    string computeChecksum(string data);

public:
    // Default constructor
    IntegrityChecker();

    // Add evidence with checksum to hash table - O(1)
    void addEvidence(string evidenceID, string checksum);

    // Verify if evidence checksum matches stored value - O(1)
    bool verifyEvidence(string evidenceID, string currentChecksum);

    // Retrieve stored checksum for evidence - O(1)
    string getChecksum(string evidenceID);

    // Remove evidence from hash table - O(1)
    void removeEvidence(string evidenceID);

    // Get total number of evidence items - O(1)
    int getTotalEvidence();

    // Display all evidence and checksums
    void displayAll();
}; 
