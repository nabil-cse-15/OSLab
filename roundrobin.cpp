#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, bt[20], wt[20], tat[20], rem[20], ct[20], tq;
    float avg_tat = 0, avg_wt = 0;
    vector<int> gantt, gant_time;

    cout << "Enter Number of process: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
        rem[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }

    int time = 0;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        gantt.push_back(p);
        if (rem[p] > tq)
        {
            time += tq;
            rem[p] -= tq;
            q.push(p);
        }
        else
        {
            time += rem[p];
            rem[p] = 0;
            ct[p] = time;
            tat[p] = ct[p]; // AT=0
            wt[p] = tat[p] - bt[p];
        }
        gant_time.push_back(time);
    }

    cout << "Process\t" << "BT\t" << "WT\t" << "TAT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    cout << "Average Waiting Time: " << avg_wt / n << endl;
    cout << "Average Turn Around Time: " << avg_tat / n << endl;

    cout << "Gantt Chart" << endl;
    cout << "|";
    for (int i = 0; i < gantt.size(); i++)
    {
        cout << "\tP" << gantt[i] + 1 << "\t|";
    }
    cout << endl;
    cout<<"0\t";
    for (int i = 0; i < gant_time.size(); i++)
    {
        cout<< "\t"<<gant_time[i] << "\t";
    }
}