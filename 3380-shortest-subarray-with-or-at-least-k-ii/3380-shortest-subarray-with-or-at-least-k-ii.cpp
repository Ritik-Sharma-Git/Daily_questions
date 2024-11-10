class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
    int ans = n + 1;
    int ors = 0;
    vector<int> count(32, 0);
    int left = 0;

    for (int right = 0; right < n; ++right) {
        ors |= nums[right];
        for (int i = 0; i < 32; ++i) {
            if ((nums[right] >> i) & 1) {
                count[i]++;
            }
        }

        while (ors >= k && left <= right) {
            ans = min(ans, right - left + 1);
            for (int i = 0; i < 32; ++i) {
                if ((nums[left] >> i) & 1) {
                    count[i]--;
                    if (count[i] == 0) {
                        ors ^= (1 << i);
                    }
                }
            }
            left++;
        }
    }
    return (ans == n + 1) ? -1 : ans;
    }
};
