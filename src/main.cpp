
/*
        Check the README for specifications!
*/

// store,sum,newlist
#include "MyList.h"

void HashFunction(const long &key);
void ApplyHashFunction(MyList<long> keys);

int main() {
  MyList<long> l;

  long line;
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
void HashFunction(const long &key) { cout << key << endl; }

int HashSum(const long &key) {
  long num = key;
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
// large numbers not being handled
//  Takes a list of hash keys
//  Prints the hash codes for every element
void ApplyHashFunction(MyList<long> keys) {
  ListNode<long> *current = keys.begin();
  for (int i = 0; i < keys.size(); i++) {
    current->data = HashSum(current->data);
    // HashFunction(current->data);
    current = current->next;
  }
  // reverse print
  for (int i = keys.size() - 1; i >= 0; i--) {
    current = keys.begin();

    for (int j = 0; j < i; j++) {
      current = current->next;
    }
    HashFunction(current->data);
  }
  /*current = keys.begin();
  for (int i = 0; i < keys.size(); i++)
  {
                  HashFunction(current->data);
                  current = current->next;
  }*/
}
