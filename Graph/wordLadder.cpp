#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{

    queue<pair<string, int>> q;

    // Add the starting word to queue
    q.push({startWord, 1});

    // Add all the words to a hashset
    unordered_set<string> st(wordList.begin(), wordList.end());

    /* Erase the starting word
    from set (if it exists) */
    st.erase(startWord);

    // Until the queue is empty
    while (!q.empty())
    {

        // Get the word from queue
        string word = q.front().first;

        // Get the steps from queue
        int steps = q.front().second;
        q.pop();

        // Return steps if target word is acheived
        if (word == targetWord)
            return steps;

        // Iterate on every character
        for (int i = 0; i < word.size(); i++)
        {
            // Store the original letter
            char original = word[i];

            /* Replacing current character with
            letters from 'a' to 'z' to match
            any possible word from set */

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // Check if it exists in the set
                if (st.find(word) != st.end())
                {

                    // Erase the word from set
                    st.erase(word);

                    // Add the transition to the queue
                    q.push({word, steps + 1});
                }
            }

            // Update the original letter back
            word[i] = original;
        }
    }

    /* If no transformation sequence
    is found, return 0 */
    return 0;
}