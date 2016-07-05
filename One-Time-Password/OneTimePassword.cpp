// A C/C++ Program to generate OTP (One Time Password)

#include<bits/stdc++.h>
using namespace std;

// A Function to generate a unique OTP everytime
string generateOTP(int len)
{
	// All possible characters of my OTP
	string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int n = str.length();
	
	// String to hold my OTP
	string OTP;
	
	for (int i=1; i<=len; i++)
		OTP.push_back(str[rand() % n]);
	
	return(OTP);
}

// Driver Program to test above functions
int main()
{
	// For different values each time we run the code
    srand(time(NULL)); 
	
	// Delare the length of OTP
	int len = 6;
	printf("Your OTP is - %s", generateOTP(len).c_str());
	
	return(0);
}

