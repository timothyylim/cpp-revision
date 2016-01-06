#include <iostream> 
#include "substring.h"

using namespace std;

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
