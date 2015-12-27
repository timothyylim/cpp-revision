#include<iostream>
#include<cstring>

using namespace std;

#include"multitap.h"

int main() {

  char multitap[500];

  cout << "====== QUESTION 1 ===============================================" << endl << endl;

  encode_character(' ', multitap);
  cout << "' ' is encoded as " << multitap << endl;

  encode_character('a', multitap);
  cout << "'a' is encoded as " << multitap << endl;

  encode_character('c', multitap);
  cout << "'c' is encoded as " << multitap << endl;

  encode_character('r', multitap);
  cout << "'r' is encoded as " << multitap << endl;

  encode_character('6', multitap);
  cout << "'6' is encoded as " << multitap << endl;

  encode_character('0', multitap);
  cout << "'0' is encoded as " << multitap << endl;

  encode_character('?', multitap);
  cout << "'?' is encoded as " << multitap << endl;

  encode_character(',', multitap);
  cout << "',' is encoded as " << multitap << endl;


  cout << endl << "====== QUESTION 2 ===============================================" << endl << endl;

  encode("Meet Anna at 5pm", multitap);
  cout << "'Meet Anna at 5pm' in multitap format is " << multitap << endl << endl;

  return 0;
}
