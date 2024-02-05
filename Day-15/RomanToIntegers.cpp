class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> conv = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int ans = 0; // Initialize ans to zero
    int preInt = 0;

    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        char ch = s[i];
        int curr = conv[ch];
        if (preInt <= curr) {
            ans += curr;
        } else {
            ans = (ans - curr);
        }
        preInt = curr;
    }
    return ans;
        
    }
};