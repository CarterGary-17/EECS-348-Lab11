#include <iostream>
#include <vector>

using namespace std;

// Returns true if the student has 3 or more absences (0 = absent).
// Note: as written, the loop starts at index 1, so attendanceRecords[0] is never checked.
bool failLecture(const vector<int>& attendanceRecords) {
    int absentCount = 0;
    for (int i = 1; i < attendanceRecords.size(); ++i) {
        absentCount += attendanceRecords[i] == 0;
    }
    return absentCount >= 3;
}

int main() {
    // Each test: records, expected result
    struct Test {
        vector<int> records;
        bool expected;
    };

    vector<Test> tests = {
        {{1,1,1,1,1,1,1,1,1,1}, false},       // perfect attendance: fault but does not result in error state
        {{1,0,0,0,0,0,0,0,0,0}, true},       // all absences except at i=0: fault but does not result in error state
        {{0,0,1,1,1,1,1,1,1,1}, false},        // 2 absences (one at i=0): error state but not failure
        {{0,0,0,1,1,1,1,1,1,1}, true},     // exactly 3 absences: failure
        
    };

    for (size_t t = 0; t < tests.size(); ++t) {
        bool result = failLecture(tests[t].records);

        cout << "Test " << t + 1 << ": "
             << (result ? "False" : "True")
             << (result == tests[t].expected ? "  [OK]" : "  [FAILURE]")
             << endl;
    }

    return 0;
}
