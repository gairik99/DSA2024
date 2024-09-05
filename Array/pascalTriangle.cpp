#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row)
{

    long long ans = 1;
    vector<int> ansRow;
    /// Inserting the 1st element
    ansRow.push_back(1);

    // Calculate the rest of the elements
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> pascalTriangle;

    // Store the entire Pascal's Triangle
    for (int row = 1; row <= n; row++)
    {
        pascalTriangle.push_back(generateRow(row));
    }

    // return the pascalTriangle
    return pascalTriangle;
}