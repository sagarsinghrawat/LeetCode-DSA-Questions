class Solution {
public:

    int xorsum(vector<int>&nums, int i, int curr){

        if( i == nums.size() )
            return curr;

       int withElement = xorsum( nums, i+1, curr^nums[i]);
       int withoutElement = xorsum( nums, i+1, curr);

       return withElement + withoutElement;
    }
    int subsetXORSum(vector<int>& nums) {

        return xorsum( nums, 0, 0 );
    }
};