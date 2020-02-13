#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string str;
        if(numRows == 1) return s;
        vector<string> rows(min(int(s.size()),numRows));
        int curRows = 0;
        bool isEnd = false;
        for(char c: s){
            rows[curRows] +=c;
            if(curRows == 0 || curRows == numRows -1) isEnd = !isEnd;
            curRows += isEnd? 1 : -1;
        }
        for(string row: rows) str += row;
        return str;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
