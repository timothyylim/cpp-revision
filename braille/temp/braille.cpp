#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <algorithm>
#include <stdlib.h>
 

using namespace std;
 
int encode_character(char ch, char braille[]);
string encode_normal(char ch);
string encode_cap(char ch);
string encode_num(char ch);
char encode_text(char sentence[], char braille[]);
char encode_recursive(char sentence[],  char braille[], int length, int i, char acc[]);
 
 
int main()
{
 
//char output[12];
//int size = encode_character('b', output);
 
//cout << size << "          " << output;
 
char blubb[300] = "Hello!";
char hello[300] = "aa";
char lisa[300] = "Hello lisa";
char braille[300];

cout << "Input: " << blubb << endl;
encode_text(blubb, braille );


cout << "======= result ====== " << endl;
cout << braille << endl;
//encode_text(hello, braille );
//cout << braille;
//encode_text(lisa, braille );
//cout << braille;
    return 0;
}
 
/*===== QUESTION 1 =====*/
int encode_character(char ch, char braille[])
{
  string str;
  if(isupper((int)(ch)))
    str = encode_cap(ch);
  else if(isdigit((int)(ch)) && ch != '0')
    str = encode_num(ch);
  else if(isdigit((int)(ch)) && ch == '0')
    str = "..0000.0.00.";
  else
    str = encode_normal(ch);
 
  strcpy(braille, str.c_str());
 
  int size = strlen(braille);
  braille[size] = '\0';
  return size;
}
 
string encode_normal(char ch)
{
  string braille;
  if(ch == 'a')
    braille = "0.....";
  else if(ch == 'b')
    braille = "00....";
  else if(ch == 'c')
    braille = "0..0..";
  else if(ch == 'd')
    braille = "0..00.";
  else if(ch == 'e')
    braille = "0...0.";
  else if(ch == 'f')
    braille = "00.0..";
  else if(ch == 'g')
    braille = "00.00.";
  else if(ch == 'h')
    braille = "00..0.";
  else if(ch == 'i')
    braille = ".0.0..";
  else if(ch == 'j')
    braille = ".0.00.";
  else if(ch == 'k')
    braille = "0.0...";
  else if(ch == 'l')
    braille = "000...";
  else if(ch == 'm')
    braille = "0.00..";
  else if(ch == 'n')
    braille = "0.000.";
  else if(ch == 'o')
    braille = "0.0.0.";
  else if(ch == 'p')
    braille = "0000..";
  else if(ch == 'q')
    braille = "00000.";
  else if(ch == 'r')
    braille = "000.0.";
  else if(ch == 's')
    braille = ".000..";
  else if(ch == 't')
    braille = ".0000.";
  else if(ch == 'u')
    braille = "0.0..0";
  else if(ch == 'v')
    braille = "000..0";
  else if(ch == 'w')
    braille = ".0.000";
  else if(ch == 'x')
    braille = "0.00.0";
  else if(ch == 'y')
    braille = "0.0000";
  else if(ch == 'z')
    braille = "0.0.00";
 
  else if(ch == '.')
    braille = ".0..00";
  else if(ch == ',')
    braille = ".0....";
  else if(ch == ';')
    braille = ".00...";
  else if(ch == '-')
    braille = "..0..0";
  else if(ch == '!')
    braille = ".00.0.";
  else if(ch == '?')
    braille = ".00..0";
  else if(ch == '(' || ch == ')')
    braille = ".00.00";
  return braille;
}
 
 
string encode_cap(char ch)
{
  string str = ".....0";
  //strcpy(str, ".....0");
 
  char lower_case = tolower(ch);
  string temp = encode_normal(lower_case);
 
  str.append(temp);
  //strcat(str, temp);
  return str;
}
 
string encode_num(char ch)
{
  string str = "..0000";
  //strcpy(str, "..0000");
 
  int ascii = static_cast<int>(ch);
  char eq = static_cast<char>(ascii + 48);
  string temp = encode_normal(eq);
 
  str.append(temp);
  //strcat(str, temp);
 
  return str;
}
 
char encode_text(char sentence[], char braille[])
{
  int length = strlen(sentence);
  int i = 0;
  char accumulator[300]; 
  accumulator[0] = '\0';

  encode_recursive(sentence, braille, length, i, accumulator);
}
 


/* How this crap works:
 *
 * You have 3 main data structures, sentence, braille and acc
 *
 * Do not touch braille until the very end of the recursion.
 *
 * So, as you loop through the sentence you need to encode each of the letters.
 * Encode the letters into a temporary variable called accNew and append 
 * this to the main accumulator.
 *
 * Pass the updated accumulator into the next step of the recursion, increment
 * the counter so you go to the next letter of the sentence and reduce the
 * length.
 *
 * When you get to the end of the recursion (when length is 0), set the
 * braille to the accumlated encoding using strcpy.
 *
 * 
 *
 * What went wrong the first time:
 *
 * Trying to update braille continuously during the recursion. Better to 
 * leave it be until all the encodings are complete in an accumulator string 
 * and just copy it at the end.
 *
 *
 *
 * Still to do:
 *
 * encode_recursive and encode_text should return void. The output is simply
 * the braille parameter. Think of that as the return type.
 *
 */ 
char encode_recursive(char sentence[], char braille[], int length, int i, char acc[])
{

  if(sentence[i] == ' ') i++;
    

  // Set braille when the end of the sentence is reached
  if (length == 0){
    strcpy(braille, acc);
    return 0;
  }


  // Encode a new character into a temporary variable 
  char accNew[100];
  encode_character(sentence[i],accNew);
  
  // Update the accumulator
  strcat(acc, accNew);

  // Pass in the updated accumulator
  encode_recursive(sentence, braille, length-1, ++i, acc);
}
