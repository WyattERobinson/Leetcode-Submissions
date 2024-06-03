class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_in = 0;
        for (int i = 0; i < s.size() && t_in < t.size(); i++) {
            if (s[i] == t[t_in]) {
                t_in++;
            }
        }
        return t.size() - t_in; 
    }
};