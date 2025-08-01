# Best Time to Buy and Sell Stock

## Problem Description
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Solutions

### 1. Brute Force Approach (O(n²))
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- For each day, check all future days to find maximum profit
- Simple but inefficient for large inputs
- Nested loops to try every possible buy-sell combination

### 2. Optimal Approach (O(n))
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- Uses single pass through the array
- Maintains two variables:
  - `minPrice`: tracks the minimum price seen so far
  - `maxProfit`: tracks the maximum profit possible
- For each price:
  1. Update minimum price if current price is lower
  2. Calculate potential profit using current price
  3. Update maximum profit if potential profit is higher

## Example
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
```

## How to Run
```bash
g++ BTBSS.cpp -o BTBSS
./BTBSS
```
