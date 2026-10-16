
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0), window(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int required = 0;
        for (int c = 0; c < 128; c++) {
            if (need[c] > 0) required++;
        }

        int formed = 0;
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            while (formed == required) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                char out = s[left];
                window[out]--;

                if (need[out] > 0 && window[out] < need[out]) {
                    formed--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
