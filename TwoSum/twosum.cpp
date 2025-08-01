#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Brute Force Solution - Time: O(n²), Space: O(1)
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }

    // Optimal Solution using Hash Map - Time: O(n), Space: O(n)
    vector<int> twoSumOptimal(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // val -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Add current number and its index to map
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
};

int main() {
    Solution solution;
    
    // Test cases
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    
    // Test brute force solution
    cout << "Brute Force Solutions:" << endl;
    vector<int> result1 = solution.twoSumBruteForce(nums1, target1);
    cout << "Input: [2,7,11,15], target = 9" << endl;
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;
    
    vector<int> result2 = solution.twoSumBruteForce(nums2, target2);
    cout << "Input: [3,2,4], target = 6" << endl;
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;
    
    // Test optimal solution
    cout << "\nOptimal Solutions:" << endl;
    result1 = solution.twoSumOptimal(nums1, target1);
    cout << "Input: [2,7,11,15], target = 9" << endl;
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;
    
    result2 = solution.twoSumOptimal(nums2, target2);
    cout << "Input: [3,2,4], target = 6" << endl;
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;
    
    return 0;
}
