#include <iostream>
#include <cctype>
#include "soundex.h"

using namespace std;

void encode(const char* str, char* soundex){

  soundex[0] = str[0];

  int k = 1;

  for (int i = 1; str[i] != '\0'; i++){

    if (switch_char(str[i]) != '0' && 
        k < 4 &&
        switch_char(str[i]) != switch_char(str[i-1])
        ){

      soundex[k] = switch_char(str[i]);
      k++;
    }
  }

  while (k < 4){
    soundex[k] = '0';
    k++;
  }


  soundex[4] = '\0';
}


char switch_char(char input){
    switch(input) {
    case 'b':
    case 'f':
    case 'p':
    case 'v':
      return '1';

    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
      return '2';

    case 'd':
    case 't':
      return '3';

    case 'l':
      return '4';

    case 'm':
    case 'n':
      return '5';

    case 'r':
      return '6';

    default:
      return '0';
    }
}

int compare(const char* str1, const char* str2){

  if(str1[0] == '\0'  && str2[0] == '\0') return 1;

  if(str1[0] == str2[0]){
    return compare(str1+1, str2+1);
  }

  return 0;
}

int count(const char* surname, const char* sentence){

  char temp[100];
  int k = 0;
  char encoded[5];
  char encoded_name[5];
  int count = 0; 

  for (int i = 0; sentence[i] != '\0'; i++){

    temp[k] = sentence[i];
    k ++;

    if(sentence[i] == ' ' ||
       sentence[i] == ',' ||
       sentence[i] == '.'){
       
      temp[k-1] = '\0';

      encode(temp, encoded);
      encode(surname, encoded_name);

      if (compare(encoded_name, encoded)) count ++;

      temp[0] = '\0';
      k = 0;
    }
  }

  return count;
}






