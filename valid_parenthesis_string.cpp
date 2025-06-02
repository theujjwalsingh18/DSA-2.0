// Problem : https://leetcode.com/problems/valid-parenthesis-string/

// ------------------  Solution -----------------------------

#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkValidString(string s)
    {
        int open_count = 0, close_count = 0;
        int len = s.length() - 1;
        for (int i = 0; i <= len; i++)
        {
            if (s[i] == '(' || s[i] == '*')
                open_count++;
            else
                open_count--;
            if (s[len - i] == ')' || s[len - i] == '*')
                close_count++;
            else
                close_count--;
            if (open_count < 0 || close_count < 0)
                return false;
        }
        return true;
    }
};

/*

-------------- Time Complexity and Space Complexity using min-heap ---------------
|                                                                                |
|                 T.C : O(N)                 S.C : O(1)                          |
|                                                                                |
----------------------------------------------------------------------------------

*/