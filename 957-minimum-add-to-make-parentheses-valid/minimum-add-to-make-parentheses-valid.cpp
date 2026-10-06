class Solution {
public:
    int minAddToMakeValid(string s) {
        int unmatchedOpen = 0;
        int insertOpen = 0;

        for (char c : s) {
            if (c == '(') {
                ++unmatchedOpen;
            } else if (unmatchedOpen > 0) {
                --unmatchedOpen;
            } else {
                ++insertOpen;
            }
        }

        return insertOpen + unmatchedOpen;
    }
};