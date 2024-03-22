
/*
        Check the README for specifications!
*/

// store,sum,newlist
#include "MyList.h"

void HashFunction(const int &key);
void ApplyHashFunction(MyList<int> keys);

int main() {
  MyList<int> l;

  int line;
  while (std::cin >> line) {
    l.push_front(line);

    // Finish Me!
  }
  ApplyHashFunction(l);

  return 0;
}

// "Suggested" Functions, feel free to change

// Takes in an integer (hash key) and prints the corresponding hash-code
// (see README)
void HashFunction(const int &key) { cout << key << endl; }

int HashSum(const int &key) {
  int num = key;
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

// Takes a list of hash keys
// Prints the hash codes for every element
void ApplyHashFunction(MyList<int> keys) {
  ListNode<int> *current = keys.begin();
  while (current != nullptr) {
    int hash_sum = HashSum(current->data);
    HashFunction(hash_sum);
    // current->data = HashSum(current->data);
    // HashFunction(current->data);
    current = current->next;
  }
}
