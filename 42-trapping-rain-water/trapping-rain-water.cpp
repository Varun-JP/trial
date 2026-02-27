class Solution {
public:
    int trap(vector<int>& height) {
        int water =0;
        int left = 0;
        int n = height.size();
        int right = n-1;
        int leftmax = 0;
        int rightmax = 0;
        while(left< right){
            leftmax = max(height[left], leftmax);
            rightmax = max(height[right], rightmax);

            if(leftmax < rightmax) {
                water+= leftmax - height[left];
                left++;
            }
            else{
                water+= rightmax - height[right];
                right--;
            }
        }
        return water;
    }
};