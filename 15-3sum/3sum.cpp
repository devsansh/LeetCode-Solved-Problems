class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int target = 0;
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> uniqueTriplets;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    uniqueTriplets.insert({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        for (const auto& triplets : uniqueTriplets) {
            result.push_back(triplets);
        }

        return result;
    }
};