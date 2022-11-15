// FILE: wk7_palindrome.cxx
// Program to test whether an input line is a palindrome. Spaces,
// punctuation, and the difference between upper- and lowercase are ignored.

// Author: Son Phan
// Date: 11/14/2022 

#include <cassert>    // Provides assert
#include <cctype>     // Provides isalpha, toupper
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cout, cin, peek
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class
#include <string>     // Provides String library

using namespace std;
void readString(string & lineOfWords, stack<string> &s, queue <string> &q);
bool checkPalindrome(stack<string> &s, queue<string> &q);

int main( )
{
    queue<string> q; //
    stack<string> s; // reverse order
    
    string lineOfWords; // User input 
    
    char user_choice;
    bool result = false;
    
    cout << " ===== PALINDROME PROGRAM ===== " << endl;
    cout << " ============================== " << endl;

    do 
    {
    	readString(lineOfWords, s, q);
    	result = checkPalindrome(s,q);
    	cout << " ======== Result ======= " << endl;
    	if(result == true)
    		cout << "That is a palindrome." << endl;
    	else 
    		cout << "That is not a palindrome." << endl;
    		
    		
    	cout << "Do you want to try again? (y/n)" << endl;
    	//user_choice = getchar();
    	cin >> user_choice;
    	cin.ignore(10,'\n');
    	
    }while(toupper(user_choice) != 'N');
    
    cout << endl;
       
    return EXIT_SUCCESS;    
}
void readString(string & lineOfWords, stack<string> &s, queue <string> &q)
{
	cout << "Enter a line and I will see if it's a palindrome:" << endl;
	getline(cin,lineOfWords);
	
	
	//cout << lineOfWords;
	
	for(int i = 0; i < lineOfWords.length(); i++)
    	{
    		lineOfWords.at(i) = toupper(lineOfWords.at(i));
    	}
    	
    	string temp = "";
   
    	for(int i = 0; i < lineOfWords.length(); i++)
    	{
    		if(lineOfWords[i] == ' ' || lineOfWords[i] == ',')
    		{	
    			q.push(temp);
    			s.push(temp);
			temp = "";
    		}
    		else
    		{
    			temp = temp+lineOfWords[i];
    		}
    	}
    	s.push(temp);
    	q.push(temp);
}

bool checkPalindrome(stack<string> &s, queue<string> &q)
{
	queue<string>::size_type mismatches = 0;  // Mismatches between queue and stack
	while ((!q.empty( )) && (!s.empty( )))
	{
        	if (q.front( ) != s.top( ))
        	    ++mismatches;
        	q.pop( );
        	s.pop( );
    	}

    	if (mismatches == 0)
        	return true;
    	else
        	return false; 
}
