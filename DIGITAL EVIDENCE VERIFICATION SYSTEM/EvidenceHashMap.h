#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Evidence.h"

using namespace std;

// Hash Map-based evidence storage system
class EvidenceHashMap {
private:
    // Hash map storing evidenceID as key and Evidence object as value
    unordered_map<string, Evidence> evidenceMap;

public:
    // Default constructor
    EvidenceHashMap();

    // Add evidence to hash map - O(1)
    bool addEvidence(Evidence e);

    // Get evidence by ID - O(1)
    Evidence* getEvidence(string evidenceID);

    // Delete evidence by ID - O(1)
    bool deleteEvidence(string evidenceID);

    // Check if evidence exists - O(1)
    bool evidenceExists(string evidenceID);

    // Get all evidence as vector - O(n)
    vector<Evidence> getAllEvidence();

    // Get total count of evidence - O(1)
    int getTotalCount();

    // Display all evidence - O(n)
    void displayAllEvidence();
};