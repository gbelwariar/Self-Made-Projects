/* 
 This is a C++ program to encode many strings
 into Base64. There will be many queries and each of the
 query demands the encoded string into Base64 format

 Implemented By- Rachit Belwariar
 This project has been uploaded on my Github account
 Link:- https://github.com/gbelwariar

 The purpose of the program is to reduce the time 
 complexity in encoding a string to Base64.
  In order to achieve this we have used a map

 Assumption:- The input string is alphanumeric
 i.e- It will contain 'a'-'z', 'A'-'Z', '0'-'9'

 Time Complexity- O(No_of_Strings * Avg_length_of_each_String)
 
 Space Complexity- 
 

 Implementation Date:- 30th July 2016
*/

#include<bits/stdc++.h>
using namespace std;

// An O(1) Function to return the ASCII Value of 
// the character -'ch'
int getASCII(char ch)
{
	return((int)ch);
}

// A function that converts an integer - 'num'
// to its 8-bit representation
// The time complexity of this function if O(log(num))
// but since 'num' is very small so we can assume this
// to be a constant O(1) function
string _8_Bit_Representation(int num)
{
	string temp;
	int remainder;
	
	// Fill the 'temp' string with its 8-bit
	// equivalent
	// Note that the characters in this string
	// are inserted in reverse order
	while (num != 0)
	{
		remainder = num % 2;
		num = num / 2;
		temp.push_back(remainder + '0');
	}
	
	// Padd the extra space with 0's
	while (temp.size() != 8)
		temp.push_back('0');
	
	// Reverse the string to get the correct
	// 8-Bit representations
	reverse(temp.begin(), temp.end());
	
	return(temp);
}

// An O(1) "Amortized" function to map the ASCII values
// with their 8-bit representation
// We are using the word "Amortized" because this is a hash-
// map where O(1) upper-bound is not guaranteed
void mapCharacters_8_Bit(unordered_map<char, string> &char_to_8_bit)
{
	// Map all the letters	
	for (int i=0; i<=127; i++)
	{
		char ch = ' ' + i;
		int ASCII = getASCII(ch);
		string _8_bit = _8_Bit_Representation(ASCII);
		char_to_8_bit.insert(make_pair(ch, _8_bit));
	}	
	return;
}

// A function that converts an integer - 'num'
// to its 6-bit representation
// The time complexity of this function is O(log(num))
// but since 'num' is very small so we can assume this
// to be a constant O(1) function
string _6_Bit_Representation(int num)
{
	string str;
	int remainder;
	
	// Fill the 'temp' string with its 8-bit
	// equivalent
	// Note that the characters in this string
	// are inserted in reverse order
	while (num != 0)
	{
		remainder = num % 2;
		num = num / 2;
		str.push_back(remainder + '0');
	}
	
	// Padd the extra space with 0's
	while (str.size() != 6)
		str.push_back('0');
	
	// Reverse the string to get the correct
	// 8-bit representations
	reverse(str.begin(), str.end());
	
	return(str);
}

// 	A function to  map the 6-bit representaton to its
// respective Base64 character
// Time Complexity is O(1) "Amortized"
// We are using the word "Amortized" because this is a hash-
// map where O(1) upper-bound is not guaranteed
void mapCharacters_6_Bit(unordered_map<string, char> &_6_bit_to_base64, string base64)
{
	int len = base64.length();
	
	for (int i=0; i<len; i++)
	{
		string str = _6_Bit_Representation(i);
		pair<string, char> p = make_pair(str, base64[i]);
		_6_bit_to_base64.insert(p);
	}
	return;
}

// An O(1) function to find the number of '='
// required as a padding
int findPadding(string input)
{
	int len = input.length(), padding;		
	string output;
		
	if ((len * 8) % 6 == 0)
		padding = 0;
	else
		padding = (6 - (len * 8) % 6) / 2; 
		
	return(padding);
}

// A function to encode the 'input' string to base64
// Time Complexity of this function is O(len) "Amortized"
// where 'len'= length of the string to be encoded
// Again, we are using the term 'Amortized' as unordered_map
// doesn't guarantee O(1) upper-bound for find() operation
string encode_Base64(string input, unordered_map<char, string> 
					char_to_8_bit, unordered_map<string, char> 
					_6_bit_to_base64)
{
	int pad = findPadding(input);
	int len = input.length();
	
	// The string 'grouped' holds the bits clubbed together
	// We will divide this string in groups of 6 and change
	// it to Base64 Encoding
	string output, grouped;
	
	for (int i=0; i<len; i++)
		grouped = grouped + char_to_8_bit[input[i]];	

	// Handle the corner cases
	if (pad == 1)
		grouped = grouped + "00";
	else if (pad == 2)
		grouped = grouped + "0000";
	
	len = grouped.length();
	
	// Find the mapped character
	for (int i=0; i<len; i+=6)
		output.push_back(_6_bit_to_base64[grouped.substr(i, 6)]);
	
	// Add an '=' sign for decoding without information loss
	if (pad == 1)
		output = output + "=";
	else if (pad == 2)
		output = output + "==";
	
	return(output);
}

// Driver Function
int main()
{
	// Characters allowed in Base64 Scheme
	string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"
					"ghijklmnopqrstuvwxyz0123456789+/";
	
	// An array of strings
	// Each of the strings have to be encoded in Base64
	string arr[] =  {"Mary had", "geek", "Encode", "Decode"};
    int n = sizeof(arr)/sizeof(arr[0]);	
	
	// A hash-map to map the characters with their 8-bit
	// representation. We are using a hash-map to effictively
	// answer the queries
	unordered_map<char, string> char_to_8_bit;
	
	// To pre-process the characters and map them to their
	// respective 8-bit representation
	mapCharacters_8_Bit(char_to_8_bit);
	
	// A hash-map to map the 6-bit representation with the 
	//corresponding characters in Base64 scheme. We are using
	// a hash-map to effictively answer the queries
	unordered_map<string, char> _6_bit_to_base64;
	
	// To pre-process the characters in Base64 and map the 6-bit
	// to its respective Base64 character
	mapCharacters_6_Bit(_6_bit_to_base64, base64);	
	
	for (int i=0; i<n; i++)
	{
		string input = arr[i];
		
		string output = encode_Base64(input, char_to_8_bit,
										 _6_bit_to_base64);
		
		printf("Encoding \"%s\" in Base64 gives \"%s\"\n",
				 input.c_str(), output.c_str());
	}
	
	// Clearing the hash-maps
	char_to_8_bit.clear();
	_6_bit_to_base64.clear();
	
	return(0);
}

