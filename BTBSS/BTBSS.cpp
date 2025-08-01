#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Brute Force Solution - Time: O(n²), Space: O(1)
    int maxProfitBruteForce(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        
        return maxProfit;
    }

    // Optimal Solution - Time: O(n), Space: O(1)
    int maxProfitOptimal(vector<int>& prices) {
        int minPrice = INT_MAX;    // Track minimum price seen so far
        int maxProfit = 0;         // Track maximum profit possible
        
        for (int price : prices) {
            // Update minimum price seen so far
            minPrice = min(minPrice, price);
            
            // Calculate potential profit if we sell at current price
            int potentialProfit = price - minPrice;
            
            // Update maximum profit if current potential profit is greater
            maxProfit = max(maxProfit, potentialProfit);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};  // Expected output: 5 (buy at 1, sell at 6)
    vector<int> prices2 = {7, 6, 4, 3, 1};     // Expected output: 0 (no profit possible)
    vector<int> prices3 = {2, 4, 1, 7};        // Expected output: 6 (buy at 1, sell at 7)
    
    // Test brute force solution
    cout << "Brute Force Solutions:" << endl;
    cout << "Input: [7,1,5,3,6,4]" << endl;
    cout << "Output: " << solution.maxProfitBruteForce(prices1) << endl;
    
    cout << "Input: [7,6,4,3,1]" << endl;
    cout << "Output: " << solution.maxProfitBruteForce(prices2) << endl;
    
    cout << "Input: [2,4,1,7]" << endl;
    cout << "Output: " << solution.maxProfitBruteForce(prices3) << endl;
    
    // Test optimal solution
    cout << "\nOptimal Solutions:" << endl;
    cout << "Input: [7,1,5,3,6,4]" << endl;
    cout << "Output: " << solution.maxProfitOptimal(prices1) << endl;
    
    cout << "Input: [7,6,4,3,1]" << endl;
    cout << "Output: " << solution.maxProfitOptimal(prices2) << endl;
    
    cout << "Input: [2,4,1,7]" << endl;
    cout << "Output: " << solution.maxProfitOptimal(prices3) << endl;
    
    return 0;
}
