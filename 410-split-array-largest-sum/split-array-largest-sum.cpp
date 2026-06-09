class Solution {
public:
    bool isValid(vector<int>& nums, int k, long long maxAllowed) {
        int subarrays = 1;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= maxAllowed) {
                sum += nums[i];
            } else {
                subarrays++;
                sum = nums[i];
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long st = *max_element(nums.begin(), nums.end());
        long long end = 0;

        for (int x : nums) {
            end += x;
        }

        long long ans = end;

        while (st <= end) {
            long long mid = st + (end - st) / 2;

            if (isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return (int)ans;
    }
};
