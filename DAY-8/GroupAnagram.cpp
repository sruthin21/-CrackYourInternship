class Solution {
private:
    bool anagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int count[26] = {0};
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : t) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> map;  // Store the index of the group in result
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // Sort the string to use as a key
            
            if (map.find(sortedStr) == map.end()) {
                map[sortedStr] = result.size();
                result.push_back({str});  // Create a new group
            } else {
                result[map[sortedStr]].push_back(str);  // Add to existing group
            }
        }
        
        return result;
    }
};