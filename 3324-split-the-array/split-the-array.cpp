class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int i : nums){
            count[i]++;
        }

        for(auto & pair : count){
            if(pair.second > 2){
                return false;
            }
        }
        return true;
    }
};