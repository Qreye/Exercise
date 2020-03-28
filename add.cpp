class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int>result;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if((nums[i]+nums[j]) == target  && i != j){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
