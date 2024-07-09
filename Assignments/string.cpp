#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Task 1
string getShuffledString(string s, int* indices) {
  string result = s;
  
  for (int i = 0; i < s.length(); i++) {
    result[indices[i]] = s[i];
  }
  
  return result;
  
  // Time complexity = O(n)
  // Space complexity = O(1)
}

// Task 2
long getHashValue(string s) {
  long result = 0;
  int length = s.length();
  
  for (int i = 0; i < length; i++) {
    int power = (length-i) % 7;
    int value = s[i] - 'a' + 1;
    result += (value * pow(26, power));
  }
  
  return result;
}

bool isMatched(string target, string source, int index) {
  for (char c: target) {
    if (c != source[index]) return false;
    index++;
  }
  return true;
}

long getRollingHash(string s, long lastHash, int targetLength, int currentIndex) {
  int power = targetLength % 7;
  int oldValue = s[currentIndex-1] - 'a' + 1;
  int value = s[currentIndex+targetLength-1] - 'a' + 1;
  return ((lastHash + value - (oldValue * pow(26, power))) * 26);
}

int getNeedleInHaystack(string haystack, string needle) {
  int haystackLength = haystack.size();
  int needleLength = needle.size();
  
  if (haystackLength < needleLength) return -1;
  
  long needleHash = getHashValue(needle);
  string firstString = haystack.substr(0, needleLength);
  long currentHash = getHashValue(firstString);
  
  if (needleHash == currentHash && needle == firstString) {
    return 0;
  }
  
  for (int i = 1; i <= haystackLength - needleLength; i++) {
    currentHash = getRollingHash(haystack, currentHash, needleLength, i);
    if (needleHash == currentHash && isMatched(needle, haystack, i)) {
      return i;
    }
  }
  
  return -1;
  
  // Time complexity = O(n^2)
  // Space complexity = O(1)
}

int main() 
{
    string s = "mamacode";
    int indices[8] = { 4, 5, 6, 7, 0, 1, 2, 3 };
    cout << "Shuffled string: " << getShuffledString(s, indices) << endl;
    
    string haystack = "codemama";
    string needle = "mama";
    cout << "First occurence index: " << getNeedleInHaystack(haystack, needle) << endl;
    
    return 0;
}
