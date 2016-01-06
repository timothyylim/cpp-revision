#include <iostream> 
#include "substring.h"

using namespace std;


// Recursive Solution

int substring_position(const char* substr, const char* str){

  if (is_prefix(substr, str)) return 0;

  if(str[0] != '\0'){
    if (1+substring_position(substr, str+1) > 0){
      return 1+substring_position(substr, str+1); 
    }
  }

  return -1;

}

bool is_prefix(const char* substr, const char* str){

  if(substr[0] == '\0') return true;

  if(substr[0] == str[0]){
    return is_prefix(substr+1, str+1);
  }

  return false; 
}



// Iterative Solution
int substring_position_itr(char const* substring, char const* mainString){

  //Check length of substring 
  int sslength; 
  for (sslength= 0; substring[sslength]!='\0';sslength++);
  int mslength;
  for (mslength= 0; mainString[mslength]!='\0';mslength++);
  if (sslength>mslength) return -1;

  if(substring[0] == '\0') return 0; 

  return match(substring, sslength, mainString, mslength); 

}

int match(char const* substring, int sslength, char const* mainString, int mslength){
 
  for (int i=0; i<mslength; i++){

      if (mslength < sslength){return -1;}

      if (substring[0] == mainString[i]){
        int k;
        for(k=0; k <sslength; k++){
          if(substring[k] != mainString[i+k]){break;}
        }
       
        if (k == sslength){return i;}
    } 
  }

  
  return -1;
}
