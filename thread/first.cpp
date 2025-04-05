#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

long long evenSum(int start, int end)
{
    long long sum = 0;
    for (int i = start; i < end; i++)
    {
        if (i % 2 == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    long long result = 0;

    // Lambda function to update result with the return value of evenSum
    auto threadFunc = [&result](int start, int end)
    {
        result = evenSum(start, end);
    };

    // Create a thread and execute the lambda function
    thread t1(threadFunc, 0, 2000);

    // Wait for the thread to finish
    t1.join();

    // Output the result
    cout << result << endl;

    return 0;
}