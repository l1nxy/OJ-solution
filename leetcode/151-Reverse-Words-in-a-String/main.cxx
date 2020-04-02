/*
 * main.cxx
 * 
 * Copyright 2020 linxy <l1nxy.zy@gmail.com>
 * 
 * Given an input string, reverse the string word by word.
 * 
 */


#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     string reverseWords(string s) {
//     	if(s.empty() == true) return s;
//     	//std::vector<string> v;
//        	int i = 0;
//        	while(i < (int)s.size())
//        	{
//        		if(s[i] != ' ')
//        		{
//        			string temp_str;
//        			int j = i;
//        			while(s[j++] != ' ' && j <=(int) s.size());
//        			for (int k = i; k < j-1; ++k)
//        			{
//        				temp_str.push_back(s[k]);
//        			}
//        			v.push_back(temp_str);
//        			i = j;
//        		}
//        		else
//        		{
//        			i++;
//        		}	

//        	}

//        	#ifdef _DEBUG
//        	for(auto i : v) cout<< i << " ";
//        	cout<<endl;
//         #endif

//         string ret;
//         for(auto i = v.rbegin();i != v.rend();++i)
//         {
//         	ret += *i;
//         	if(i + 1 != v.rend())
//         		ret += " ";
//         }
//         return ret;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
    	string str = s;
    	reverse(str.begin(),str.end());
    	//cout<< str << endl;
    	size_t insertPos = 0;

    	for(size_t i = 0; i < str.size();i++)
    	{
    		if(str[i] != ' '){
    			if(insertPos != 0) str[insertPos++] = ' ';
    			size_t j = i;
    			while(str[j] != ' ' && j < str.size())
    			{
    				str[insertPos++] = str[j++];
    			}
    			//cout <<  insertPos <<endl;
    			reverse(str.begin() + insertPos-(j-i), str.begin() + insertPos);
    			i = j;
    		}
    		
    	}str.erase(str.begin() + insertPos,str.end());
    	//cout << str <<endl;
    	return str;
    }

};


int main(int argc, char **argv)
{
	Solution s;
	cout<<s.reverseWords("a good   example")<<endl;
	//"  hello world!  "
	cout<<s.reverseWords("  hello world!  ")<<endl;
	cout<<s.reverseWords("")<<endl;

	return 0;
}

