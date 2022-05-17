class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int count0=0;
        int count1=0;
        int count2=0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            
            if(nums[i] == 0)
                count0++;
            else if(nums[i] == 1)
                count1++;
            else
                count2++;
        }
        int i=0;
        while(count0){
            nums[i] = 0;
            count0--;
            i++;
        }
        while(count1){
            nums[i] = 1;
            count1--;
            i++;
        }
        while(count2){
            nums[i] = 2;
            count2--;
            i++;
        }
        
    }
};