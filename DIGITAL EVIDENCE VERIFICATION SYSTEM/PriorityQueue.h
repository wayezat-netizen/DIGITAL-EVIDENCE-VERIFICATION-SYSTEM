#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "Evidence.h"

using namespace std;

// Helper structure to store evidence with priority score
struct PriorityEvidence {
    Evidence evidence;
    int priorityScore;

    // Constructor
    PriorityEvidence(Evidence e, int score);
};

// Comparator for max heap (highest priority first)
struct ComparePriority {
    // Return true if a has LOWER priority than b
    bool operator()(PriorityEvidence& a, PriorityEvidence& b);
};

// Priority Queue for evidence processing using max heap
class PriorityQueue {
private:
    // Max heap priority queue
    priority_queue<PriorityEvidence, vector<PriorityEvidence>, ComparePriority> pq;

public:
    // Constructor
    PriorityQueue();

    // Calculate priority score based on severity, urgency, and age
    int calculatePriorityScore(int severity, int urgency, int daysOld);

    // Add evidence to priority queue - O(log n)
    void enqueue(Evidence e, int severity, int urgency, int daysOld);

    // Remove and return highest priority evidence - O(log n)
    Evidence dequeue();

    // View highest priority evidence without removing - O(1)
    Evidence peek();

    // Check if queue is empty - O(1)
    bool isEmpty();

    // Get number of items in queue - O(1)
    int getSize();

    // Display all items with priorities (non-destructive)
    void displayQueue();
};