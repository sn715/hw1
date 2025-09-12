#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){

  //if list is empty 
  if (head_ == NULL) {

    Item* temp = new Item();

    temp->val[0] = val;

    temp->first = 0;
    temp->last = 1;

    head_ = temp;
    tail_ = temp;
  }
  else if (tail_->last < ARRSIZE) {

    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else{
    Item* temp = new Item();

    temp->val[0] = val;

    temp->first = 0;
    temp->last = 1;

    //
    tail_->next = temp;
    temp->next = NULL;
    temp->prev = tail_;
    tail_ = temp;
  }

  size_++;
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back(){
  
  if (tail_ == NULL){
    return;
  }
  else{
    tail_->last--;

    if (tail_->first == tail_->last)
    {
      Item* temp = tail_;

      tail_ = tail_->prev;
      if (tail_ == NULL){
        head_ = NULL;
      }
      else{
        tail_->next = NULL;
      }

      delete temp;
    }
  }
  size_--;
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val){

  if (head_ == NULL) {

    Item* temp = new Item();

    temp->val[9] = val;

    temp->first = 9;
    temp->last = 10;

    head_ = temp;
    tail_ = temp;
  }
  else if (head_->first > 0) {

    head_->val[head_->first-1] = val;
    head_->first--;
  }
  else{
    Item* temp = new Item();

    temp->val[9] = val;

    temp->first = 9;
    temp->last = 10;

    //
    head_->prev = temp;
    temp->prev = NULL;
    temp->next = head_;
    head_ = temp;
  }

  size_++;
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front(){
  if (head_ == NULL){
    return;
  }
  else{
    head_->first++;

    if (head_->first == head_->last)
    {
      Item* temp = head_;

      head_ = head_->next;
      if (head_ == NULL){
        tail_ = NULL;
      }
      else{
        head_->prev = NULL;
      }

      delete temp;
    }
  }
  size_--;

}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const{
  if(size_ == 0){
    static const std::string null = "";
    return null;
  }
  else{
    return tail_->val[tail_->last-1];
  }

}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const{
  if(size_ == 0){
    static const std::string null = "";
    return null;
  }
  else{
    return head_->val[head_->first];
  }

}

std::string* ULListStr::getValAtLoc(size_t loc) const{

  if (loc >= size_){
    return NULL;
  }

  Item* temp = head_;
  size_t i = 0;
  while(temp != NULL) {
    size_t elements = temp->last - temp->first;

    if (loc < elements + i)
    {
      return &(temp->val[temp->first + (loc - i)]);
    }

    i += elements; // next node
    temp = temp->next;
  }

  return NULL;
}
  

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
