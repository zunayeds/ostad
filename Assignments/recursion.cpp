#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Task 1
bool isPalindrome(string s, int position) {
  int length = s.length();
  bool isMiddle = position == length / 2;
  
  if (isMiddle && length % 2 == 1) {
    if (length % 2 == 1) return true;
  }
  
  if (s[position] != s[length-position-1]) {
    return false;
  }
  else if (isMiddle) {
    return true;
  }
  
  return isPalindrome(s, ++position);
  
  // n = s.length / 2
  // Time Complexity = O(n)
  // Space Complexity = O(n)
}

// Task 2
int getMultipliedValue(int a, int b) {
  if (a == 0 || b == 0) return 0;
  
  int minVal = min(a, b);
  int maxVal = max(a, b);
  
  if (minVal == 1) return maxVal;
  
  else return maxVal + getMultipliedValue(maxVal, minVal-1);
  
  // n = min(a, b)
  // Time Complexity = O(n)
  // Space Complexity = O(n)
}

int main() 
{
    string s = "madam";
    cout << "Is a palindrome: " << boolalpha << isPalindrome(s, 0) << endl;
    
    int a = 4;
    int b = 5;
    cout << "Mulliplied value: " << getMultipliedValue(a, b) << endl;
    
    return 0;
}
