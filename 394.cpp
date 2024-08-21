 #include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<string> st;
        for(int i=0; i<n; i++) {
            int count = 0;
            string as = "";
            if(s[i] > '0' && s[i] < '999') {
                count = s[i] - '0';
            }
            else if(s[i-1] == '[') {
                if(s[i] == ']') {
                    break;
                }
                while(count--) {
                    as += s[i];
                }
            }
            st.push(as);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "3[a]2[bc]";  // Expected output: "aaabcbc"
    cout << "Decoded string for \"" << s1 << "\": " << solution.decodeString(s1) << endl;

    // Test case 2
    string s2 = "3[a2[c]]";  // Expected output: "accaccacc"
    cout << "Decoded string for \"" << s2 << "\": " << solution.decodeString(s2) << endl;

    // Test case 3
    string s3 = "2[abc]3[cd]ef";  // Expected output: "abcabccdcdcdef"
    cout << "Decoded string for \"" << s3 << "\": " << solution.decodeString(s3) << endl;

    // Test case 4
    string s4 = "abc3[cd]xyz";  // Expected output: "abccdcdcdxyz"
    cout << "Decoded string for \"" << s4 << "\": " << solution.decodeString(s4) << endl;

    return 0;
}
