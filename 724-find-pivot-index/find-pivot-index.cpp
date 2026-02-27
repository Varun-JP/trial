class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0;
        int rightsum=0;
        int totalsum=0;

        for(int x: nums) totalsum+=x;

        for(int i=0; i< nums.size() ; i++){
            rightsum = totalsum - leftsum - nums[i];
            if(rightsum == leftsum ){
                return i;
            }
            else{
                leftsum += nums[i];
            }
        }
        return -1;
    }
};