#include <iostream>
#include <cstring> 
using namespace std;

#include "braille.h"
// find and replace
// reset string?

int encode_character(char ch, char* str){
  
 str[0]='\0';
 int size = 0;
 
  if (isalpha(ch)) {

   if (isupper(ch)) {
     strcpy(str,".....0");
     ch = tolower(ch);
     size+=6;
   }
   
   size += 6;
   switch(ch) { 
    case 'a':
      strcat(str, "0....."); return size;
    case 'b':
      strcat(str, "00...."); return size;
    case 'c':
      strcat(str, "0..0.."); return size;
    case 'd':
      strcat(str, "0..00."); return size;
    case 'e':
      strcat(str, "0...0."); return size;
    case 'f':
      strcat(str, "00.0.."); return size;
    case 'g':
      strcat(str, "00.00."); return size;
    case 'h':
      strcat(str, "00..0."); return size;
    case 'i':
      strcat(str, ".0.0.."); return size;
    case 'j':
      strcat(str, ".0.00."); return size;
    case 'k':
      strcat(str, "0.0..."); return size;
    case 'l':
      strcat(str, "000..."); return size;
    case 'm':
      strcat(str, "0.00.."); return size;
    case 'n':
      strcat(str, "0.000."); return size;
    case 'o':
      strcat(str, "0.0.0."); return size;
    case 'p':
      strcat(str, "0000.."); return size;
    case 'q':
      strcat(str, "00000."); return size;
    case 'r':
      strcat(str, "000.0."); return size;
    case 's':
      strcat(str, ".000.."); return size;
    case 't':
      strcat(str, ".0000."); return size;
    case 'u':
      strcat(str, "0.0..0"); return size;
    case 'v':
      strcat(str, "000..0"); return size;
    case 'w':
      strcat(str, ".0.000"); return size;
    case 'x':
      strcat(str, "0.00.0"); return size;
    case 'y':
      strcat(str, "0.0000"); return size;
    case 'z':
      strcat(str, "0.0.00"); return size;
    }
  }

  if (isdigit(ch)) {
    switch(ch) { 
    case '1':
      strcpy(str,"..00000....."); return 12;
    case '2':
      strcpy(str,"..000000...."); return 12;
    case '3':
      strcpy(str,"..00000..0.."); return 12;
    case '4':
      strcpy(str,"..00000..00."); return 12;
    case '5':
      strcpy(str,"..00000...0."); return 12;
    case '6':
      strcpy(str,"..000000.0.."); return 12;
    case '7':
      strcpy(str,"..000000.00."); return 12;
    case '8':
      strcpy(str,"..000000..0."); return 12;
    case '9':
      strcpy(str,"..0000.0.0.."); return 12;
    case '0':
      strcpy(str,"..0000.0.00."); return 12;
    }
  }

  if (ispunct(ch)) {
    switch(ch) {
    case '.':
      strcpy(str,".0..00"); return 6;
    case ',':
      strcpy(str,".0...."); return 6;
    case ';':
      strcpy(str,".00..."); return 6;
    case '-':
      strcpy(str,"..0..0"); return 6;
    case '!':
      strcpy(str,".00.0."); return 6;
    case '?':
      strcpy(str,".00..0"); return 6;
    case '(':
      strcpy(str,".00.00"); return 6;
    case ')':
      strcpy(str,".00.00"); return 6;
    }
  }

 
  return -1;
}


void encode(const char* str, char* braille) {
  if (str[0]=='\0')
    return;          //braille[0] = '\0' first?

  else {
    int length = encode_character(str[0], braille);
    return encode(&str[1], &braille[length]);       //length+1? length-1?
  }
}

void print_braille(char* str){
  char encoded[100]; 
  encode(str, encoded);
  
  int len;
  for(len = 0;encoded[len]!='\0';len++);
 
  string line1;
  for(int i = 0; i<len; i+=3){
    line1+=encoded[i];
  }
 
  string line2;
  for(int i = 1; i<len; i+=3){
    line2+=encoded[i];
  }
 
  string line3;
  for(int i = 2; i<len; i+=3){
    line3+=encoded[i];
  }

  cout << line1 << endl;
  cout << line2 << endl;
  cout << line3 << endl; 

  
  for (int i = 0; str[i]!='\0'; i++){
    if(isupper(str[i]) ||
       isdigit(str[i])){
      cout << "  ";
    }
    cout << " " << str[i]; 
  }

  cout << endl;
}
