# DIGITAL-EVIDENCE-VERIFICATION-SYSTEM
An ordinary guy trying to make extra ordinary project



MANDATORY REQUIREMENTS FOR ALL CODE GENERATION:

LANGUAGE: C++ (ISO C++17 standard)
IDE: Visual Studio 2022
COMPILER: MSVC (Microsoft Visual C++)
PLATFORM: Windows 10/11

CODE REQUIREMENTS:
1. All code must compile without errors in Visual Studio 2022
2. All code must be complete - no placeholders or "TODO" comments
3. All code must be production-ready - fully implemented functions
4. Use #pragma once instead of header guards for Visual Studio
5. Include all necessary headers in every file
6. No external libraries except C++ Standard Library

NAMING STANDARDS (STRICTLY ENFORCE):
- Classes: PascalCase (EvidenceManager, HashTable, TreeNode)
- Functions: camelCase (addEvidence, verifyIntegrity, displayMenu)
- Variables: camelCase (evidenceID, fileName, totalCount)
- Constants: UPPER_SNAKE_CASE (MAX_SIZE, DEFAULT_VALUE)
- Private members: camelCase (no prefixes)
- Struct members: camelCase
- File names: Match class name exactly (EvidenceManager.h, EvidenceManager.cpp)

HEADER FILE STRUCTURE:
#pragma once
#include <system_headers>
#include "custom_headers.h"
using namespace std;

[declarations]

CPP FILE STRUCTURE:
#include "MatchingHeader.h"
#include <additional_headers>
using namespace std;

[implementations]

MEMORY MANAGEMENT:
- Initialize all pointers to nullptr
- Check for nullptr before dereferencing
- Implement destructors for classes with dynamic memory
- Use delete for single objects, delete[] for arrays
- In destructors, delete children before parent nodes

ERROR HANDLING:
- Return bool for success/failure (true = success, false = failure)
- Return nullptr for failed pointer returns
- Return empty string "" for failed string returns
- Return empty vector for failed collection returns
- Print error messages to cout with "Error: " prefix
- No exceptions - use return values only

CONSOLE OUTPUT:
- Use cout for all output
- Use cin for all input
- Clear input buffer after cin operations: cin.ignore(numeric_limits<streamsize>::max(), '\n');
- Use system("cls") for Windows to clear screen
- Use system("pause") for Windows to pause screen

STRING FORMATS (ENFORCE EXACTLY):
- Evidence ID format: "EV_2024_0001" (EV_ + year + underscore + 4-digit number)
- Case ID format: "CASE0001" (CASE + 4-digit number with leading zeros)
- Date format: "YYYY-MM-DD HH:MM:SS" (example: "2024-12-05 14:30:00")
- All IDs must use these exact formats

DATA STRUCTURE SPECIFICS:
- Hash Map: Use unordered_map<string, Type> from <unordered_map>
- BST: Store Evidence objects, compare by timestamp field (string comparison)
- Priority Queue: Use priority_queue from <queue> with custom comparator
- Graph: Use unordered_map<string, vector<Transfer>> for adjacency list
- Stack: Use stack<Type> from <stack>
- Queue: Use queue<Type> from <queue>

REQUIRED HEADERS FOR ALL FILES:
#include <iostream>
#include <string>
#include <vector>

ADDITIONAL HEADERS AS NEEDED:
#include <unordered_map>  // for hash maps
#include <queue>          // for priority queue and queue
#include <stack>          // for stack
#include <fstream>        // for file operations
#include <limits>         // for numeric_limits
#include <ctime>          // for timestamps
#include <algorithm>      // for sort, max, min

FUNCTION IMPLEMENTATION RULES:
- Every function must be fully implemented
- No function body should be empty
- No function should have just "// TODO" or similar
- All helper functions must be implemented
- All recursive functions must have base cases
- All loops must have proper termination conditions

COMPILATION REQUIREMENTS:
- Code must compile with zero errors
- Code must compile with zero warnings
- All included headers must exist
- All referenced functions must be defined
- All classes must be fully implemented

TESTING REQUIREMENTS:
- Each component must include a working test/example
- Tests should demonstrate the component works correctly
- Tests should be in comments or separate test files

COMMENTS REQUIREMENTS:
- Add // comment above each function explaining what it does
- Add // Time Complexity: O(...) for data structure operations
- Add inline comments for complex logic only
- Do not over-comment simple operations

VISUAL STUDIO SPECIFIC:
- Use _WIN32 preprocessor directive for Windows-specific code
- Use system("cls") for clearing screen on Windows
- Use system("pause") for pausing screen on Windows
- Ensure all paths use forward slashes or double backslashes

DO NOT INCLUDE:
- No placeholder functions
- No "implement later" comments
- No external library dependencies
- No Linux/Mac specific code without Windows alternatives
- No C-style casts (use C++ style: static_cast, etc.)
- No deprecated functions
- No using namespace std in header files (only in .cpp files)

VERIFICATION BEFORE PROVIDING CODE:
- Ensure all functions are fully implemented
- Ensure all headers are correct and exist
- Ensure code will compile in Visual Studio 2022
- Ensure no external dependencies
- Ensure all return types are correct
- Ensure all parameter types match function signatures
