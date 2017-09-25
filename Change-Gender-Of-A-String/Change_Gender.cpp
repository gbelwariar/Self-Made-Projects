// A C++ Program to change the gender of a string

#include<bits/stdc++.h>
using namespace std;

// A Funtion that returns the new string with gender
// changed
string changeGender(string str)
{
	// A Dictionary to store the mapping of genders
	// The user can add his words too.
	unordered_multimap <string, string> dictionary = 
	{
		{"batman", "batwoman"}, {"batwoman", "batman"},
		{"boy", "girl"}, {"girl", "boy"},
		{"boyfriend", "girlfriend"}, {"girlfriend", "boyfriend"},
		{"father", "mother"}, {"mother", "father"},
		{"husband", "wife"}, {"wife", "husband"},
		{"he", "she"}, {"she", "he"},
		{"his", "her"}, {"her", "his"},
		{"male", "female"}, {"female", "male"},
		{"man", "woman"}, {"woman", "man"},
		{"Mr", "Ms"}, {"Ms", "Mr"},
		{"sir", "madam"}, {"madam", "sir"},
		{"son", "daughter"}, {"daughter", "son"},
		{"uncle", "aunt"}, {"aunt", "uncle"},
	};
	
	str = str + ' '; // Append a space at the end
	int i, n = str.length();
	
	// 'temp' string will hold the intermediate words
	// and 'ans' string will be our result
	string temp, ans;
	
	for (i=0; i<=n-1; i++)
	{
		if (str[i] != ' ')
			temp.push_back(str[i]);
		else 
		{
			// If this is a 'male' or a 'female' word then
			// swap this with its counterpart
			if (dictionary.find(temp) != dictionary.end())
				temp = dictionary.find(temp)->second;
				
			ans = ans + temp + ' ';
			temp.clear();
		}
	}
	
	return(ans);
}

// Driver Program to test above functions
int main()
{
	string str = "she is going to watch the new movie of batman with her boyfriend";

	str = changeGender(str);
	printf ("%s\n", str.c_str());

	return (0);
}

