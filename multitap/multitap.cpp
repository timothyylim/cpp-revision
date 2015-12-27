#include <iostream> 
#include <cstring> 
#include <cctype> 

using namespace std;
#include "multitap.h"

int encode_character(char ch, char* multitap){

  // Encode numerals 
	if( ch >= '0' && ch <= '9'){
		multitap[0] = '*';
		multitap[1] = ch;
		multitap[2] = '\0';
    		return 3;
	}

	// Encode spaces
	if (ch == ' '){
		multitap[0] = '0';
		return 1;
	}
	
	// Encode letters
	// Loop through the table 
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 4; j++){

			// Check letter is in the table
			if(table[i][j] == tolower(ch)){

				// Add the digit as many times as necessary
				for(int k = 0; k <= j; k++){
	  			multitap[k] = char(i+48+1);
				}

				// Set the sentinal character
				multitap[j+1] = '\0';
				return j+1;
			}
		}	
	}

	return -1;
}


void encode(const char* str, char* multitap){

  char encoded[100];
  bool Caps_On = false;
  string result = "";

  for (int i = 0; str[i]!='\0'; i++){

    // Toggle caps on
    if (isupper(str[i]) && !Caps_On){
      result += '#';
      Caps_On = true;
    }

    // Toggle caps off
    if (islower(str[i]) && Caps_On){
      result += '#';
      Caps_On = false;
    }

    // Get the encoded char array, convert it
    // to a string and concatenate it
    encode_character(str[i], encoded);
    string str_encoded(encoded);

    // Check if '|' is necessary
    int res_len = result.length();
    if (result[res_len -1] == str_encoded[0]){
      result += '|';
    }

    result += str_encoded;

  }

  // Return the goddamn encoding 
  strcpy(multitap, result.c_str());
  	
}
