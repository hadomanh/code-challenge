#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s);

int main(int argc, char const *argv[])
{
    // "abcabcbb"
    // "bbbbb"
    // "pwwkew"
    // "dvdf"
    // "abba"
    // "tmmzuxt"
    string input = "tmmzuxt";
    cout << lengthOfLongestSubstring(input) << endl;
    return 0;
}

int lengthOfLongestSubstring(string s) {
        
    int currentLength = 0;
    int maxLength = 0;
    int presence[128] = {0};
    
    for (int i = 0; i < s.length(); i++) {
        currentLength = min(i + 1 - presence[s[i]], currentLength + 1);
        maxLength = max(currentLength, maxLength);
        presence[s[i]] = i + 1;
    }

    return maxLength;
}

