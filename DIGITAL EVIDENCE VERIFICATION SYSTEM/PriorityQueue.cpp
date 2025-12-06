#include "PriorityQueue.h"

using namespace std;

// PriorityEvidence constructor
PriorityEvidence::PriorityEvidence(Evidence e, int score) : evidence(e), priorityScore(score) {
}

// ComparePriority operator - creates max heap
bool ComparePriority::operator()(PriorityEvidence& a, PriorityEvidence& b) {
    // Return true if a < b. This makes max heap (higher score = higher priority)
    return a.priorityScore < b.priorityScore;
}

// PriorityQueue constructor
PriorityQueue::PriorityQueue() {
}

// Calculate priority score using formula
int PriorityQueue::calculatePriorityScore(int severity, int urgency, int daysOld) {
    // Higher score = higher priority. Severity and urgency increase priority, age decreases it
    return (severity * 10) + (urgency * 5) - (daysOld * 2);
}

// Add evidence to priority queue
void PriorityQueue::enqueue(Evidence e, int severity, int urgency, int daysOld) {
    // O(log n) - Binary heap insertion
    int score = calculatePriorityScore(severity, urgency, daysOld);
    PriorityEvidence pe(e, score);
    pq.push(pe);
}

// Remove and return highest priority evidence
Evidence PriorityQueue::dequeue() {
    // O(log n) - Binary heap deletion (remove max)
    if (isEmpty()) {
        return Evidence();
    }

    Evidence e = pq.top().evidence;
    pq.pop();
    return e;
}

// View highest priority evidence without removing
Evidence PriorityQueue::peek() {
    // O(1) - View heap root without removal
    if (isEmpty()) {
        return Evidence();
    }

    return pq.top().evidence;
}

// Check if queue is empty
bool PriorityQueue::isEmpty() {
    return pq.empty();
}

// Get size of queue
int PriorityQueue::getSize() {
    return pq.size();
}

// Display all items with priorities (non-destructive)
void PriorityQueue::displayQueue() {
    // Creates temporary copy to display without destroying original queue
    if (isEmpty()) {
        cout << "Priority queue is empty" << endl;
        return;
    }

    priority_queue<PriorityEvidence, vector<PriorityEvidence>, ComparePriority> temp = pq;
    int rank = 1;

    cout << "========== Priority Queue Contents ==========" << endl;
    while (!temp.empty()) {
        PriorityEvidence pe = temp.top();
        cout << "Rank " << rank << " | Priority Score: " << pe.priorityScore << endl;
        pe.evidence.display();
        cout << "------------------------" << endl;
        temp.pop();
        rank++;
    }
}
