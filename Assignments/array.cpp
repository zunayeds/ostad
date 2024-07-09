#include <iostream>
#include <map>
#include <cmath>
using namespace std;

// Task 1
int* getIndices(int nums[], int length, int target) {
  int* result = new int[2];
  map<int, int> numMap;
  
  for (int i = 0; i < length; i++) {
    int required = target - nums[i];
    if (numMap.find(required) != numMap.end()) {
      result[0] = numMap[required];
      result[1] = i;
      return result;
    }
    
    numMap[nums[i]] = i;
  }
  
  // Time complexity = O(n)
  // Space complexity = O(n)
}

// Task 2
int getMaximizedProfit(int prices[], int length) {
  int profit = 0;
  int buyPrice = prices[0];
  int sellPrice = -1;
  
  if (length > 1) {
    for (int i = 1; i < length; i++) {
      if (buyPrice >= prices[i]) {
        buyPrice = prices[i];
      }
      else {
        sellPrice = prices[i];
        profit = max(profit, sellPrice - buyPrice);
      }
    }
  }
  
  return profit;
  
  // Time complexity = O(n)
  // Space complexity = O(1)
}

int main()
{
    int nums[4] = { 2, 7, 11, 15 };
    int length = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    
    int* res = getIndices(nums, length, target);
  
    cout << "Indices [" << res[0] << ", " << res[1] << "]" << endl;
    
    int prices[6] = { 7, 1, 5, 3, 6, 4 };
    int length2 = sizeof(prices) / sizeof(prices[0]);
    cout << "Maximized Profit " << getMaximizedProfit(prices, length2) << endl;
    
    return 0;
}
