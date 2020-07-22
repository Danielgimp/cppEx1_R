#include <iostream>
#include <cstring> 
#include "PhoneticFinder.hpp"
using namespace std;
namespace phonetic {

	string comparisonAlgorithem(string word)
	{
		string output("");
		for(int i=0;i<word.length();i++)
		{
			char currChar=tolower(word.at(i));
			if (currChar == 'i' || currChar == 'y')
			output += '1';
			else if (currChar == 'o' || currChar == 'u')
			output += '2';
			else if (currChar == 's' || currChar == 'z')
			output += '3';
			else if (currChar == 'd' || currChar == 't')
			output += '4';
			else if (currChar == 'g' || currChar == 'j')
			output += '5';
			else if (currChar == 'c' || currChar == 'k' || currChar == 'q')
			output += '6';
			else if (currChar == 'b' || currChar == 'f' || currChar == 'p')
			output += '7';
			else if (currChar == 'v' || currChar == 'w')
			output += '8';
			else
			output += currChar;
		}
		return output;
		}

	


bool isSimilar(string firstWord,string secondWord)
{
	string word1=comparisonAlgorithem(firstWord);
	string word2=comparisonAlgorithem(secondWord);
	int word1Length=word1.length();
	int word2Length=word2.length();
	if(word1Length!=word2Length)
		return false;
	if(word1.compare(word2)==0)
		return true;
	else 
		return false;


}
	string find(string origText,string testWord)
	{
		string origTextTerm=origText+'\0';
		int i=0,j=0;
		if (testWord.compare("")==0|| testWord.compare(" ")==0) //if word is just an empty string
			throw "Incorrect Input! - Empty testWord";
		if (origTextTerm.compare("")==0|| origTextTerm.compare(" ")==0) //if text is just an empty string
			throw "Incorrect Input! - Empty String";

		while(i<origTextTerm.length())
		{
			if(origTextTerm.at(i)==' ' || i==origTextTerm.length() -1)
			{
				char origTextWord[i-j+1];
				memset(origTextWord,0,i-j+1);
				origTextTerm.copy(origTextWord,i-j,j);
				if (isSimilar(origTextWord, testWord)==true) //check if they are similar
					return origTextWord; //if so return  to string
				j = i + 1;
			}
			i++;
		}
		throw runtime_error("Could not find the word: \"" + testWord + "\"");

	}

}

