#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Process: ";
    cin >> n;
    int at[n], bt[n], pr[n], ct[n], wt[n], tat[n], rem[n];
    cout << "Enter Arrival Time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> at[i];
    }

    cout << "Enter Burst Time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
        rem[i] = bt[i];
    }

    cout << "Enter Priority Time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> pr[i];
    }

    int completed = 0;
    int time = 0;

    while (completed < n)
    {
        int highest = -1;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rem[i] > 0)
            {
                if (highest == -1 || pr[i] < pr[highest])
                {
                    highest = i;
                }
            }
        }

        if (highest == -1)
        {
            time++;
        }
        else
        {
            rem[highest]--;
            time++;
            if (rem[highest] == 0)
            {
                completed++;
                ct[highest] = time;
                tat[highest] = ct[highest] - at[highest];
                wt[highest] = tat[highest] - bt[highest];
            }
        }
    }
    cout << "Process\t" << "AT\t" << "BT\t" << "Priority\t" << "CT\t" << "WT\t" << "TAT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i] << "\t\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << "\t" << endl;
    }
}