class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() == 1) { return 1; }
        int max = 0;
        bool extra = false;
        map<char,int> letters;

        cout << "max: " << max << endl;
        for (const auto& c : s) {
            letters[c]++;
        }
        for (const auto& c : letters) {
            if (c.second % 2 != 0) { extra = true; } // Gotta be a better way than this
            max += c.second - (c.second % 2);
            cout << "max: " << max << endl;
        }
        if (extra) {
            max++;
        }
        return max;
    }
};