#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        for(int a : asteroids) {
            bool destroy = false;
            while(!s.empty() && a < 0 && s.top() > 0) {
                if(s.top() < -a) {
                    s.pop();
                } else if(s.top() == -a) {
                    s.pop();
                    destroy = true;
                    break;
                } else {
                    destroy = true;
                    break;
                }
            }
            if(!destroy) {
                s.push(a);
            }
        }

        vector<int> result(s.size());
        for(int i = s.size() - 1; i >= 0; --i) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1: Simple collision where smaller negative asteroid destroys itself
    vector<int> asteroids1 = {5, 10, -5};  // Expected output: [5, 10]
    vector<int> result1 = solution.asteroidCollision(asteroids1);
    cout << "Remaining asteroids: ";
    for(int asteroid : result1) {
        cout << asteroid << " ";
    }
    cout << endl;

    // Test case 2: Equal collision where both asteroids destroy each other
    vector<int> asteroids2 = {8, -8};  // Expected output: []
    vector<int> result2 = solution.asteroidCollision(asteroids2);
    cout << "Remaining asteroids: ";
    for(int asteroid : result2) {
        cout << asteroid << " ";
    }
    cout << endl;

    // Test case 3: Larger positive asteroid survives
    vector<int> asteroids3 = {10, 2, -5};  // Expected output: [10]
    vector<int> result3 = solution.asteroidCollision(asteroids3);
    cout << "Remaining asteroids: ";
    for(int asteroid : result3) {
        cout << asteroid << " ";
    }
    cout << endl;

    // Test case 4: No collisions, all asteroids remain
    vector<int> asteroids4 = {-2, -1, 1, 2};  // Expected output: [-2, -1, 1, 2]
    vector<int> result4 = solution.asteroidCollision(asteroids4);
    cout << "Remaining asteroids: ";
    for(int asteroid : result4) {
        cout << asteroid << " ";
    }
    cout << endl;

    // Test case 5: Complex collision scenario
    vector<int> asteroids5 = {-2, -1, 1, -1};  // Expected output: [-2, -1]
    vector<int> result5 = solution.asteroidCollision(asteroids5);
    cout << "Remaining asteroids: ";
    for(int asteroid : result5) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}
