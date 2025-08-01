# Two Sum Problem

## Problem Description
Given an array of integers `nums` and an integer `target`, return indices of the two numbers in the array such that they add up to `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Solutions

### 1. Brute Force Approach
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- Uses nested loops to check every possible pair of numbers
- Simple but inefficient for large inputs

### 2. Optimal Approach using Hash Map
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- Uses an unordered_map to store previously seen numbers
- For each number, checks if its complement (target - current number) exists in the map

## Example
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]
```

## How to Run
```bash
g++ twosum.cpp -o twosum
./twosum
```
