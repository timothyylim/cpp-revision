#include <iostream>
#include <cctype>

#include "words.h"

using namespace std;

void reverse(const char* str, char* reversed){

  int len;
  for (len = 0; str[len] != '\0'; len++);
  len --;

  for (int i = 0; i <= len; i ++){
    reversed[i] = str[len-i];
  }
  
  reversed[len+1] = '\0';
  
}


bool compare(const char* str1, const char* str2){
  
  while(ispunct(str1[0]) || str1[0] == ' ') str1 = str1+1;
  while(ispunct(str2[0]) || str2[0] == ' ') str2 = str2+1;

  //cout << str1[0] << " : " << str2[0] << endl;
  if(str1[0] == '\0' && str2[0] == '\0') return true;

  if(tolower(str1[0]) == tolower(str2[0])){
    return compare(str1+1, str2+1);
  }

  return false;

}

bool palindrome(const char* str){

  char reversed[100];
  reverse(str, reversed);
  return compare(str, reversed);

}

bool anagram(const char* str1, const char* str2){

  char letters[26] = {0};

  for (int i = 0; str1[i]!='\0'; i++){
    letters[tolower(str1[i]) - 'a'] ++;
  }

  for (int i = 0; str2[i]!='\0'; i++){
    letters[tolower(str2[i]) - 'a']--;
  }

  for (int i = 0; i < 26; i++){
    if(letters[i] != 0) return false;
  }

  return true; 
}

