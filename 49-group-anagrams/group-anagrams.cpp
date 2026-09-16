class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string str : strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());

            mp[sorted].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto &pair : mp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};