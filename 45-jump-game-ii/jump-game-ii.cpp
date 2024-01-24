class Solution {
public:
    int jump(std::vector<int>& nums) {
        int totalJumps = 0;
        int currentJumpEnd = 0;
        int nextJumpEnd = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the maximum reachable position in the current jump.
            currentJumpEnd = std::max(currentJumpEnd, i + nums[i]);

            // If the current position reaches the end of the current jump,
            // update to the next jump and increment the total jumps.
            if (i == nextJumpEnd) {
                ++totalJumps;
                nextJumpEnd = currentJumpEnd;
            }
        }

        return totalJumps;
    }
};