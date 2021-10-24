#include<iostream>
using namespace std;

int main()
{
    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    int n[7] = { 5000, 1000, 500, 100, 50, 20, 10 };
    int nf[7] = { 0 };
    for (int i = 0; i < 7; i++)
    {
        if (amount >= n[i])
        {
            nf[i] = amount / n[i];
            amount = amount - nf[i] * n[i];
        }
    }

    for (int j = 0; j < 7; j++)
    {
        if (nf[j] != 0)
        {
            cout << nf[j] << " x " << n[j] << endl;
        }
    }
}
