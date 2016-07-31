/* 
 A C++ program to decode many strings
 from Base64. There will be many queries and each of the
 query demands the decoded string from Base64 format

 Implemented By- Rachit Belwariar
 This project has been uploaded on my Github account
 Link:- https://github.com/gbelwariar

 The purpose of the program is to reduce the time 
 complexity in decoding many strings from Base64.
 In order to achieve this we have used a map

 ASSUMPTION- The string to be decoded is a valid Base64 
  		     string.

 Time Complexity- O(No_of_Strings * Avg_length_of_each_String)
 
 Space Complexity- O(Avg_length_of_each_String) 
 
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
// to its 6-bit representation
// The time complexity of this function is O(log(num))
// but since 'num' is very small so we can assume this
// to be a constant O(1) function
string _6_Bit_Representation(int num)
{
	string str;
	int remainder;
	
	// Fill the 'temp' string with its 8-bit
	// equivalent.
	// Note that the characters in this string
	// are inserted in reverse order.
	while (num != 0)
	{
		remainder = num % 2;
		num = num / 2;
		str.push_back(remainder + '0');
	}
	
	// Padding the extra space with 0's
	while (str.size() != 6)
		str.push_back('0');
	
	// Reverse the string to get the correct
	// 8-bit representations
	reverse(str.begin(), str.end());
	
	return(str);
}

// An O(1) "Amortized" function to map the ASCII values
// with their 8-bit representation
// We are using the word "Amortized" because this is a hash-
// map where O(1) upper-bound is not guaranteed
void mapCharacters_6_Bit(unordered_map<char, string>
						 &base64_char_to_6_bit, string base64)
{
	// Map all the letters	
	for (int i=0; i<=63; i++)
	{
		char ch = base64[i];
		string _6_bit = _6_Bit_Representation(i);
		base64_char_to_6_bit.insert(make_pair(ch, _6_bit));
	}	
	return;
}

// A function that converts an integer - 'num'
// to its 8-bit representation
// The time complexity of this function is O(log(num))
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
	
	// Padding the extra space with 0's
	while (temp.size() != 8)
		temp.push_back('0');
	
	// Reverse the string to get the correct
	// 8-Bit representations
	reverse(temp.begin(), temp.end());
	
	return(temp);
}

// 	A function to  map the 8-bit representaton to its
// respective ASCII character
// Time Complexity is O(1) "Amortized"
// We are using the word "Amortized" because this is a hash-
// map where O(1) upper-bound is not guaranteed
void mapCharacters_8_Bit(unordered_map<string, char> &_8_bit_to_ASCII)
{

	
	for (int i=0; i<=127; i++)
	{
		char ch = ' ' + i;
		int ASCII = getASCII(ch);
		string str = _8_Bit_Representation(ASCII);
		pair<string, char> p = make_pair(str, ch);
		_8_bit_to_ASCII.insert(p);
	}
	return;
}

// A function to decode the 'input' string from base64
// Time Complexity of this function is O(len) "Amortized"
// where 'len'= length of the string to be encoded
// Again, we are using the term 'Amortized' as unordered_map
// doesn't guarantee O(1) upper-bound for find() operation
string decode_Base64(string input, unordered_map<char, string> 
				base64_char_to_6_bit, unordered_map<string, char> 
				_8_bit_to_ASCII)
{
	int len = input.length();

	// The string 'grouped' holds the bits clubbed together
	// We will divide this string in groups of 8 and then
	// decode each group
	string output, grouped;
	
	for (int i=0; i<len; i++)
	{
		if (input[i] == '=')
			break;
		grouped = grouped + base64_char_to_6_bit[input[i]];	
	}

	// Handle the corner case when padding is done
	if (input[len-1] == '=')
	{
		// If there are two '=' signs at the end
		// then remove them
		if (input[len-2] == '=')
		{
			grouped.pop_back();
			grouped.pop_back();		
		}
		// If there is only one '=' sign at the end
		// then remove it
		else
			grouped.pop_back();
	}

	len = grouped.length();
	
	// Find the mapped character
	for (int i=0; i<len; i+=8)
		output.push_back(_8_bit_to_ASCII[grouped.substr(i, 8)]);
	
	return(output);
}

// Driver Function
int main()
{	
	// Characters allowed in Base64 Scheme
	string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"
					"ghijklmnopqrstuvwxyz0123456789+/";

	// An array of Base64-Encoded strings
	// Each of the strings have to be decoded from Base64
	string arr[] =  {"TWFyeSBoYWQ=", "Z2Vlaw==", "RW5jb2Rl", "RGVjb2Rl"};
    int n = sizeof(arr)/sizeof(arr[0]);	
	
	// A hash-map to map the base64 characters with their 6-bit
	// representation. We are using a hash-map to effictively
	// answer the queries
	unordered_map<char, string> base64_char_to_6_bit;

	// To pre-process the base64 characters and map them to their
	// respective 6-bit representation
	mapCharacters_6_Bit(base64_char_to_6_bit, base64);
		
	// A hash-map to map the 8-bit representation with the 
	// corresponding characters in ASCII scheme. We are using
	// a hash-map to effictively answer the queries
	unordered_map<string, char> _8_bit_to_ASCII;
	
	// To pre-process the characters in Base64 and map the 6-bit
	// to its respective Base64 character
	mapCharacters_8_Bit(_8_bit_to_ASCII);	
	
	for (int i=0; i<n; i++)
	{
		string input = arr[i];
		
		string output = decode_Base64(input, base64_char_to_6_bit,
										 _8_bit_to_ASCII);
		
		printf("Decoding \"%s\" from Base64 gives \"%s\"\n",
				 input.c_str(), output.c_str());
	}

	// Clearing the hash-maps
	base64_char_to_6_bit.clear();
	_8_bit_to_ASCII.clear();
	
	return(0);
}


