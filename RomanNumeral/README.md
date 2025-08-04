# Roman to Integer

## Problem Description
Convert a Roman numeral string to an integer value.

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example:
- `III` = 3 (1 + 1 + 1)
- `LVIII` = 58 (50 + 5 + 1 + 1 + 1)
- `MCMXCIV` = 1994 (1000 + (1000-100) + (100-10) + (5-1))

## Solution Approach
1. Use a hash map to store the values of Roman numerals
2. Handle special cases where a smaller value comes before a larger value (like IV or IX)
3. If current value is less than next value, subtract current value
4. Otherwise, add the current value

## Complexity Analysis
- Time Complexity: O(n) where n is the length of the input string
- Space Complexity: O(1) as the map has a fixed size

## Special Cases
- IV = 4 (5-1)
- IX = 9 (10-1)
- XL = 40 (50-10)
- XC = 90 (100-10)
- CD = 400 (500-100)
- CM = 900 (1000-100)
