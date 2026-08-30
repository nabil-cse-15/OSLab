#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Process: ";
    cin >> n;
    int bt[n], wt[n], tat[n], p[n];
    cout << "Enter Process: " << endl;
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "P" << p[i] << ": ";
        cin >> bt[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    cout << "Process\t" << "BT\t" << "WT\t" << "TAT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\t" << endl;
    }
   
    cout << "Gantt Chart" << endl;
    cout << "|";
    for (int i = 0; i < n; i++)
    {
        cout << "\tP" << p[i]<< "\t|";
    }
    cout << endl;

    cout << "0\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << tat[i] << "\t";
    }
}