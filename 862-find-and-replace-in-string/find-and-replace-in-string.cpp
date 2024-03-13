class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string result;
        unordered_map<int, vector<int>> indicesMap;
        
        // Populate indices map
        for (int i = 0; i < indices.size(); i++) {
            indicesMap[indices[i]].push_back(i);
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (indicesMap.count(i)) {
                bool done = false;
                for (int j : indicesMap[i]) {
                    int len = min(static_cast<int>(s.length()), i + static_cast<int>(sources[j].length()));
                    string subStr = s.substr(i, len - i);
                    if (subStr == sources[j]) {
                        result += targets[j];
                        i += sources[j].length() - 1;
                        done = true;
                        break;
                    }
                }
                if (!done)
                    result += s[i];
            } else {
                result += s[i];
            }
        }
        
        return result;
    }
};