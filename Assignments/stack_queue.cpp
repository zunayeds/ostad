#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

// Task 1
bool isValidBracketString(string s) {
  map<char, char> bracketMap;
  bracketMap.insert({')', '('});
  bracketMap.insert({'}', '{'});
  bracketMap.insert({']', '['});
  
  stack<char> stk;
  
  for (char c: s) {
    if (!stk.empty() && (c == ')' || c == '}' || c == ']') && bracketMap[c] == stk.top()) {
      stk.pop();
    }
    else {
      stk.push(c);
    }
  }
  return stk.empty();
  
  // Time Complexity = O(n)
  // Space Complexity = O(n)
}

// Task 2
string getDuplicateRemovedString(string s) {
  stack<char> stk;
  
  for (char c: s) {
    if (!stk.empty() && c == stk.top()) {
      stk.pop();
    }
    else {
      stk.push(c);
    }
  }
  
  string result = "";
  while (!stk.empty()) {
    result = stk.top() + result;
    stk.pop();
  }
  
  return result;
  
  // Time Complexity = O(n)
  // Space Complexity = O(n)
}

int main() 
{
    string s1 = "()[]{}";
    auto isValid = isValidBracketString(s1);
    cout << "Is valid? " << (isValid ? "Yes" : "No") << endl;
    
    string s2 = "abbaca";
    cout << "Duplicate removed string: " << getDuplicateRemovedString(s2) << endl;
    
    return 0;
}
