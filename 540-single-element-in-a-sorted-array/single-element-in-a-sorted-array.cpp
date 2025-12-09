class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 1 1 2 2 3 4 4 5 5
        // 0 1 2 3 4 5 6 7 8
        // if index is odd let say 1
        // if elements at index and index-1 is same then single element is on
        // right if not it is on left

        // if the index is even let say 2
        // if elements at index and index+1 is same then single element is on
        // right if not it is on left


        int n = nums.size();
        // check if it is the first or last element
        if (n == 1) {
            return nums[0];
        } else if (nums[0] != nums[1]) {
            return nums[0];
        } else if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }
        // we have already handled first and last element
        // so going to index-1 and index+1 wont be a problem
        // We can also start from low = 1 and high = n-2
        int low = 0, mid, high = n - 1;
        while(low <= high) {
            mid = low + (high-low)/2;

            if( (nums[mid] != nums[mid+1]) && (nums[mid] != nums[mid-1]) ) {
                return nums[mid];
            }

            if(mid%2 == 0) {
                // even index
                if( nums[mid] == nums[mid+1] ) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                // odd index
                if( nums[mid] == nums[mid-1] ) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
        }
        return -1;
    }
};