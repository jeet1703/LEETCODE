#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        // Function implementation will go here
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> points1 = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    cout << "Test Case 1: " << sol.maxPoints(points1) << endl;  // Expected output: 9

    // Test Case 2
    vector<vector<int>> points2 = {{1, 5}, {2, 3}, {4, 2}};
    cout << "Test Case 2: " << sol.maxPoints(points2) << endl;  // Expected output: 11

    // Additional Test Case 3
    vector<vector<int>> points3 = {{7, 2, 8}, {5, 6, 1}, {4, 3, 9}};
    cout << "Test Case 3: " << sol.maxPoints(points3) << endl;  // Example test case with larger values

    return 0;
}
