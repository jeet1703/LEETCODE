#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       int ans = INT32_MIN;
       int nowmin = arrays[0][0];
       int nowmax = arrays[0].back();
       for(int i=1;i<arrays.size();i++){
        int currmin = arrays[i][0];
        int currmax = arrays[i].back();

        ans = max(ans ,abs(nowmax - currmin));
        ans = max(ans ,abs(currmax - nowmin));

        nowmin = min(nowmin,currmin);
        nowmax = max(nowmax,currmax);
       }
       return ans;
    }

};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> arrays1 = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    cout << "Test case 1: " << sol.maxDistance(arrays1) << endl; // Expected output: 4

    // Test case 2
    vector<vector<int>> arrays2 = {{1}, {1}};
    cout << "Test case 2: " << sol.maxDistance(arrays2) << endl; // Expected output: 0

    // Test case 3
    vector<vector<int>> arrays3 = {{-10, -5, 0, 5, 10}, {20, 25}, {-15, -10, 0, 10}};
    cout << "Test case 3: " << sol.maxDistance(arrays3) << endl; // Expected output: 35

    // Test case 4
    vector<vector<int>> arrays4 = {{1, 4}, {0, 2}, {3, 5}};
    cout << "Test case 4: " << sol.maxDistance(arrays4) << endl; // Expected output: 5

    // Additional test cases
    vector<vector<int>> arrays5 = {{2, 4}, {3}};
    cout << "Test case 5: " << sol.maxDistance(arrays5) << endl; // Expected output: 2

    vector<vector<int>> arrays6 = {{2, 5}, {3, 100}};
    cout << "Test case 6: " << sol.maxDistance(arrays6) << endl; // Expected output: 98

    vector<vector<int>> arrays7 = {{2, 5}, {9999, 10000}};
    cout << "Test case 7: " << sol.maxDistance(arrays7) << endl; // Expected output: 9998

    vector<vector<int>> arrays8 = {{1, 3}, {2}, {3, 100}};
    cout << "Test case 8: " << sol.maxDistance(arrays8) << endl; // Expected output: 99

    return 0;
}
