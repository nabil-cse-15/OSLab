// Implementation of non-preemptive priority sheduling algorithm

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Process: ";
    cin >> n;
    int bt[20], pr[20], wt[20], tat[20], p[20];

    cout << "Enter Burst Time: " << endl;
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "P" << p[i] << ": ";
        cin >> bt[i];
    }
    cout << "Enter priority Time: " << endl;
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "P" << p[i] << ": ";
        cin >> pr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                swap(pr[i], pr[j]);
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

    cout << "\nProcess\tBT\tPriority\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t" << bt[i] << "\t" << pr[i] << "\t\t" << wt[i] << "\t" << tat[i] << endl;
    }
    cout << "Gantt Chart" << endl;
    cout << "|";
    for (int i = 0; i < n; i++)
    {
        cout << "\tP" << p[i] << "\t|";
    }
    cout << endl;

    cout << "0\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << tat[i] << "\t";
    }
    return 0;
}