#include <iostream>
#include "substring.h"

using namespace std;

int main() {
  cout << "===================" << endl;
  cout << "Recursively" << endl;
  cout << "===================" << endl;
  cout << substring_position("this", "this is a simple exercise") << endl;
  cout << substring_position("is", "this is a simple exercise") << endl;
  cout << substring_position("is a", "this is a simple exercise") << endl;
  cout << substring_position("is an", "this is a simple exercise") << endl;
  cout << substring_position("exercise", "this is a simple exercise") << endl;
  cout << substring_position("simple exercise", "this is a simple") << endl;
  cout << substring_position("", "this is a simple exercise") << endl;
  cout << substring_position("", "") << endl;
  
  cout << "===================" << endl;
  cout << "Iteratively" << endl;
  cout << "===================" << endl;
  cout << substring_position_itr("this", "this is a simple exercise") << endl;
  cout << substring_position_itr("is", "this is a simple exercise") << endl;
  cout << substring_position_itr("is a", "this is a simple exercise") << endl;
  cout << substring_position_itr("is an", "this is a simple exercise") << endl;
  cout << substring_position_itr("exercise", "this is a simple exercise") << endl;
  cout << substring_position_itr("simple exercise", "this is a simple") << endl;
  cout << substring_position_itr("", "this is a simple exercise") << endl;
  cout << substring_position_itr("", "") << endl;
  return 0;
}
