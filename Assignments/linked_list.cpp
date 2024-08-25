#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

Node* getLinkedList(int arr[], int length) {
  if (length > 0) {
    Node* head = new Node;
    head->value = arr[0];
    Node* current = head;
    
    int index = 1;
    while (index < length) {
      Node* temp = new Node;
      temp->value = arr[index];
      temp->next = NULL;
      current->next = temp;
      current = current->next;
      index++;
    }
    
    return head;
  }
  
  return NULL;
}

void printLinkedList(Node* head) {
  Node* current = head;
    
  while (current != NULL) {
    cout << current->value << endl;
    current = current->next;
  }
}

// Task 1
Node* getReveresedLinkedList(Node* head) {
  Node* current = head;
  Node* result = NULL;
  
  while(current != NULL) {
    if (result != NULL) {
      Node* temp = result;
      result = new Node;
      result->next = temp;
    }
    else {
      result = new Node;
    }
    
    result->value = current->value;
    current = current->next;
  }
  
  return result;
  
  // Time Complexity = O(n)
  // Space Complexity = O(1)
}

// Task 2
Node* getMergedLinkedList(Node* list1, Node* list2) {
  Node* it1 = list1;
  Node* it2 = list2;
  Node* head = new Node;
  Node* result = head;
  
  while(it1 != NULL && it2 != NULL) {
    int value;
    
    if (it1->value <= it2->value) {
      value = it1->value;
      it1 = it1->next;
    }
    else {
      value = it2->value;
      it2 = it2->next;
    }
    
    result->next = new Node;
    result->next->value = value;
    result = result->next;
  }
  
  if (it1 != NULL) {
    result->next = it1;
  }
  else if (it2 != NULL) {
    result->next = it2;
  }
  
  return head->next != NULL ? head->next : NULL;
  
  // Time Complexity = O(n)
  // Space Complexity = O(1)
}

int main() 
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int length = sizeof(arr) / sizeof(arr[0]);
    auto head = getLinkedList(arr, length);
    auto reversed = getReveresedLinkedList(head);
    cout << "Reversed:" << endl;
    printLinkedList(reversed);
    
    int arr1[3] = { 1, 2, 4 };
    int arr2[3] = { 1, 3, 4 };
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    auto list1 = getLinkedList(arr1, length1);
    auto list2 = getLinkedList(arr2, length2);
    auto merged = getMergedLinkedList(list1, list2);
    cout << "Merged:" << endl;
    printLinkedList(merged);
    
    return 0;
}
