#include <bits/stdc++.h>
using namespace std;

void func(int ind, string digits, string s, vector<string> &ans, string combos[])
{
    // Base case: if index reaches the end of digits
    if (ind == digits.size())
    {
        // Add the current combination to the answer
        ans.push_back(s);
        return;
    }
    // Convert the current character to an integer
    int digit = digits[ind] - '0';
    // Loop through the corresponding characters
    for (int i = 0; i < combos[digit].size(); i++)
    {
        // Recursively call function with next index
        // Add current character to the string
        func(ind + 1, digits, s + combos[digit][i], ans, combos);
    }
}

vector<string> letterCombinations(string digits)
{
    // your code goes here
    //  Mapping digits to corresponding characters
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans; // Vector to store results
    string s = "";      // Temporary string to build combinations
    // Initiate recursive function
    func(0, digits, s, ans, combos);
    return ans;
}