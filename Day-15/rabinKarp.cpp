//rabin karp algo for pattern matching
#include <bits/stdc++.h>
using namespace std;

const int prime = 101;

int calculateHash(string str, int start, int length) {
    int hash = 0;
    for (int i = start; i < start + length; i++) {
        hash += str[i] * pow(prime, i - start);
    }
    return hash;
}

int recalculateHash(string str, int oldHash, int oldChar, int newChar, int length) {
    int newHash = oldHash - oldChar;
    newHash /= prime;
    newHash += newChar * pow(prime, length - 1);
    return newHash;
}

vector<int> stringMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> ans;
    int patternHash = calculateHash(pattern, 0, m);
    int textHash = calculateHash(text, 0, m);
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ans.push_back(i + 1);
            }
        }
        if (i < n - m) {
            textHash = recalculateHash(text, textHash, text[i], text[i + m], m);
        }
    }
    return ans;
}

/*
    Time complexity: O(n + m)
    Space complexity: O(1)

    Where 'n' and 'm' are the lengths of 'text' and 'pattern' respectively.
*/

#define MOD 1000000007

long long modPower(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long p = modPower(a, b / 2);

    if (b % 2 == 1)
        return p p % MOD * a % MOD;
    return p * p % MOD;
}

vector<int> stringMatch(string text, string pattern)
{
    int n = text.size(), m = pattern.size();

    // List storing the indices of occurrences
    vector<int> ans;

    long long maxPow = modPower(26, m - 1);

    long long hashPattern = 0, hashText = 0;
    for (int i = 0; i < m; i++)
    {
        hashPattern = hashPattern * 26 + pattern[i] - 'a';
        hashPattern %= MOD;
    }
    for (int i = 0; i < m - 1; i++)
    {
        hashText = hashText * 26 + text[i] - 'a';
        hashText %= MOD;
    }

    for (int i = 0; i <= n - m; i++)
    {
        // Adding the last character in hash
        hashText = hashText * 26 + text[i + m - 1] - 'a';
        hashText %= MOD;

        if (hashText == hashPattern)
        {
            // Checking if the substring is equal to 'pattern'
            bool match = true;

            for (int j = 0; j < m; j++)
            {
                // If a character mismatch occurs
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                ans.push_back(i + 1);
            }
        }

        // Removing the first character in hash
        hashText = hashText - maxPow * (text[i] - 'a');
        hashText %= MOD;
        hashText = (hashText + MOD) % MOD;
    }

    return ans;
}