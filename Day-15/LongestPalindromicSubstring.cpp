//longest palindromic Substring

class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.length();
    
    // If the string length is less than or equal to 1, return the string
    if (n <= 1) {
        return str;
    }

    int start = 0; // Starting index of the longest palindromic substring
    int maxLength = 1; // Length of the longest palindromic substring

    // Function to expand around a center 'i' for odd length palindrome
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && str[left] == str[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    };

    // Loop through each character as a potential center
    for (int i = 0; i < n; ++i) {
        // Expand around center 'i' for odd length palindrome
        int len1 = expandAroundCenter(i, i);

        // Expand around center 'i' and 'i+1' for even length palindrome
        int len2 = expandAroundCenter(i, i + 1);

        // Find the maximum length between len1 and len2
        int len = max(len1, len2);

        // If the length of the current palindromic substring is greater, update the start index and length
        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2;
        }
    }

    // Return the longest palindromic substring
    return str.substr(start, maxLength);
        
    }
};