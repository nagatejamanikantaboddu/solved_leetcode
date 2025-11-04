// Problem: X Sum of All K Long Subarrays
// Platform: LeetCode
// Approach: Frequency Map + Sorting (Brute Force per Window)
// Date: 2025-11-04
// Time Complexity: O(N * K * logK)
// Space Complexity: O(K)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> count;

            // Count frequency of each number in window
            for (int j = i; j < i + k; j++) {
                count[nums[j]]++;
            }

            // Convert to vector for sorting
            vector<pair<int, int>> freq(count.begin(), count.end());

            // Sort by frequency desc, then value desc
            sort(freq.begin(), freq.end(), [](const auto &a, const auto &b) {
                if (a.second != b.second)
                    return a.second > b.second;
                return a.first > b.first;
            });

            // Calculate x-sum
            int sum = 0;
            for (int j = 0; j < x && j < freq.size(); j++) {
                sum += freq[j].first * freq[j].second;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
 /*manikanta*/