#include <bits/stdc++.h>
using namespace std;
// problem link
//https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

int minEle;
stack<int> s;
/*returns min element from stack*/
int getMin()
{

    // Write your code here
    if (s.empty())
        return -1;

    return minEle;
}

/*returns poped element from stack*/
int pop()
{

    // Write your code here
    if (s.empty())
        return -1;
    int currVal = s.top();
    s.pop();
    if (currVal > minEle)
        return currVal;

    int previousMin = minEle;
    minEle = 2 * minEle - currVal;
    return previousMin;
}

/*push element x into the stack*/
void push(int x)
{

    // Write your code here
    if (s.empty())
    {
        s.push(x);
        minEle = x;
    }

    else if (x < minEle)
    {
        s.push(2 * x - minEle);
        minEle = x;
    }
    else
        s.push(x);
}