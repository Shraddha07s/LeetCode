class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto i = 0, nonZero = 0;

        for (auto& n : nums) {
            nonZero |= n > 0;
            i ^= n;
        }

        return nonZero * (nums.size() - !i);
    }
};