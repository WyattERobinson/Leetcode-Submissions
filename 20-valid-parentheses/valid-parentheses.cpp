class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) { return false; }
        
        map<char, char> brackets = {{'(',')'}, {'[',']'}, {'{', '}'}};
        stack<char> closers;
        for (int i = 0; i < s.size(); i++) {
            if (brackets.find(s[i]) != brackets.end()) {
                closers.push(brackets[s[i]]);
            }
            else {
                if (closers.empty()) {
                    return false;
                }
                if (s[i] != closers.top()) {
                    return false;
                }
                else {
                    closers.pop();
                }
            }
        }
        return closers.empty();
    }
};