
// An array mimicking the specification of the phone
int const table[9][4] = {
	{'.',',','!','?'},{'a','b','c'}, {'d','e','f'},
	{'g','h','i'},    {'j','k','l'}, {'m','n','o'},
	{'p','q','r','s'},{'t','u','v'}, {'w','x','y','z'}
};

// Encode a single character
int encode_character(char ch, char* multitap);

// Encode a stirng of characters
void encode(const char* str, char* multitap);

/* How this crap works:
 *
 * Use the table to encode single characters,
 * the row is the number that you have to press 
 * on the phone and the column is the number of 
 * times you have to press it it. 
 * e.g. to get 'c' you need to type 222. We get 
 * this by finding 2 in the second row and c in 
 * the third column. So we press 2 three times.
 *
 * Note: spaces and numbers are dealt with seperately
 *
 * To encode strings, simply concatenate the 
 * encoded character outputs (which are arrays
 * of chars). You can use string library functions
 * to do that as shown in the code.
 *
 * There is no error checking in this code, I leave
 * that up to you Zaytun. 
*/ 


