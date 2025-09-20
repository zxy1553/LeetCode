class Solution {
    public:
        bool canJump(vector<int>& nums) {
                int max_jump =0;
                for (int i = 0; i < nums.size(); i++)
                {
                    if(max_jump<i) return false;
                    max_jump= max(max_jump,i+nums[i]);
                    if(max_jump>nums.size()-1) return true;
                }
                return true;
        }
    };