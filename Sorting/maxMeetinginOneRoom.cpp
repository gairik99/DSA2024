#include <bits/stdc++.h>
using namespace std;

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    //  int n= start.size();

    // Finding maximum starting time O(n)
    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < N; i++)
        v.push_back({{F[i], S[i]}, i + 1});
    sort(v.begin(), v.end());
    vector<int> ans;
    ans.push_back(v[0].second);
    int ansend = v[0].first.first;
    for (int i = 1; i < N; i++)
    {
        if (v[i].first.second > ansend)
        {
            ans.push_back(v[i].second);
            ansend = v[i].first.first;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}