#include <iostream> 
#include <cctype>
#include <fstream>
#include <cstring> 
#include "piglatin.h"

using namespace std;

int findFirstVowel(char* str){

  for (int i = 0; str[i] != '\0'; i++){

    if (isVowel(str[i]))return i;

    if( str[i]   == 'y'      &&
        i        != 0        &&
        str[i+1] != '\0') return i;
  }
  return -1;
}

bool isVowel(char ch){
  
  if (isupper(ch))tolower(ch);
  if (ch == 'a' ||
      ch == 'e' ||
      ch == 'i' ||
      ch == 'o' ||
      ch == 'u') return true;

  return false;
}


void translateWord(char* input, char* output){

  string result;
  string input_string(input);
  bool capitalised = false;
  
  if (isupper(input[0])){
    char ch = tolower(input[0]);
    input_string[0] = ch;
    capitalised = true;
  }



  int first_vowel = findFirstVowel(input);

  if(first_vowel == 0){
    result+= input_string;        
    result+= "way";  
  }
  else if (first_vowel != -1){

    for (int i = first_vowel; i < input_string.length();  i++){
      result += input_string[i]; 
    }

    for (int i = 0; i < first_vowel ; i++){
      result += input_string[i];
    }

    result += "ay";

  }

  else if(first_vowel == -1){
    result += input_string;
    result += "ay";
  }

  if(capitalised){
    result[0] = toupper(result[0]);
  }
  strcpy(output, result.c_str());
}

void translateStream(istream& input, ostream& output) {
  char word[64], translated[64], last='\0';
  int end;
  bool punct = false;

  input.getline(word, 64, ' ');

  if (input.fail())
    return;

  else {
    cout << word << endl;

    translateWord(word, translated);
    output << translated << endl;
    translateStream(input, output);
    return;
  }
}
