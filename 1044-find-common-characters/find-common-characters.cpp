class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> chars;
        vector<string> result;
        // Create base word freq
        for (const char& c : words[0]) {
            chars[c]++;
        }

        for (const string& word : words) {
            unordered_map<char, int> tmp;
            // collect character frequency
            for (const char& letter : word) {
                tmp[letter]++;
            }

            // Compare base against tmp
            for (auto& item : chars) {
                if (!tmp[item.first]) {
                    item.second = 0;
                }
                else if (item.second > tmp[item.first]) {
                    item.second = tmp[item.first];
                }
            }
        }

        // convert map to vec<str> (??? why string ???)
        for (const auto& item : chars) {
            for (int i = 0; i < item.second; i++) {
                result.push_back(string(1, item.first));
            }
        }

        return result;
    }
};