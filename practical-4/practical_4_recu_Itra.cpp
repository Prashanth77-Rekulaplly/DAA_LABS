#include <iostream>
using namespace std;

// Iterative Method
int factorialIterative(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Method
int factorialRecursive(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorialRecursive(n - 1);
    }
}

int main()
{
    int n;

    cout << "Enter the number: ";
    cin >> n;

    cout << "\nFactorial using Iterative Method: "
         << factorialIterative(n);

    cout << "\nFactorial using Recursive Method: "
         << factorialRecursive(n);

    return 0;
}