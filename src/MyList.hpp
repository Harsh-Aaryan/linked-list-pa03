/*
 * Implementation file for a clean and simple linked list
 * std::forward_list syntax
 */

// These are freebies, touch only if attempting doubly-linked list
// Tests may depend on these working!
// linked list only no double
#ifndef MYLIST_HPP
#define MYLIST_HPP
#include "MyList.h"
template <typename T> ListNode<T> *MyList<T>::begin() { return head; }

template <typename T> MyList<T>::MyList() {
  num_elements = 0;
  head = new ListNode<T>;
  head->next = nullptr;
}

template <typename T> int MyList<T>::size() { return num_elements; }

template <typename T> T &MyList<T>::front() { return head->data; }

template <typename T> void MyList<T>::push_front(const T &value) {
  ListNode<T> *tmp = new ListNode<T>;
  tmp->data = value;
  tmp->next = head;
  head = tmp;
  num_elements++;
}

template <typename T> void MyList<T>::pop_front() {

  if (num_elements > 0) {
    ListNode<T> *tmp = head->next;
    delete head;
    head = tmp;
    num_elements--;
  }
}

// Implement each of the functions below
// PLEASE READ MyList.h carefully for details on each!
// Check out unit_tests/ and mem_tests/ for grading details

// deallocate
template <typename T> MyList<T>::~MyList() {
  clear();
  delete head;
}

// check from pa002
template <typename T> MyList<T> &MyList<T>::operator=(const MyList<T> &rhs) {
  // check ,clear and then copy from rhs
  clear();
  ListNode<T> *currentPos = head;
  ListNode<T> *dataPos = rhs.head;
  while (dataPos->next != nullptr) {
    insert(currentPos, dataPos->data);
    currentPos = currentPos->next;
    dataPos = dataPos->next;
  }

  return *this;
}
// see previous copy
template <typename T> MyList<T>::MyList(const MyList<T> &rhs) {
  head = new ListNode<T>;
  head->next = nullptr;
  *this = rhs;
}

// asign value-push
template <typename T> void MyList<T>::assign(int count, const T &value) {
  this->clear();
  // loop
  for (int i = 0; i < count; i++) {
    this->push_front(value);
  }
}

// remove
template <typename T> void MyList<T>::clear() {
  ListNode<T> *temp;
  temp = head->next;
  while (temp != nullptr) {
    delete head;
    head = temp;
    temp = head->next;
  }
  num_elements = 0;
}
// see example
template <typename T>
void MyList<T>::insert(LinkedListIterator<T> iter, const T &value) {
  ListNode<T> *temp = new ListNode<T>;
  temp->data = iter->data;
  temp->next = iter->next;
  iter->data = value;
  iter->next = temp;

  num_elements++;
}

template <typename T> void MyList<T>::erase(LinkedListIterator<T> iter) {
  ListNode<T> *temp = iter->next; // delete
  iter->data = temp->data;
  iter->next = temp->next; // next
  delete temp;
  num_elements--;
}
// reverse order previous,current and next
template <typename T> void MyList<T>::reverse() {
  ListNode<T> *previous = nullptr;
  ListNode<T> *current = head;
  ListNode<T> *next = head->next;

  while (current != nullptr) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  head->next = previous;
  head = previous->next;
  previous->next = nullptr;
}

template <typename T> LinkedListIterator<T> MyList<T>::find(const T &value) {
  // use example
  ListNode<T> *temp = head;
  while (temp->next != nullptr) {
    if (value == temp->data)
      return temp;
    temp = temp->next;
  }
  return nullptr;
}

// ceck

template <typename T>
void MyList<T>::splice_after(ListNode<T> *splice_point, MyList<T> &source) {

  // get size -insert to list
  // use pop front insertertion
  // check something wrong
  int source_size = source.size();
  for (int i = 0; i < source_size; i++) {
    this->insert(LinkedListIterator<T>(splice_point->next),
                 source.front());      // insert
    splice_point = splice_point->next; // move
    // remove
    source.pop_front();
  }
}

#endif
