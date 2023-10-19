#include <bits/stdc++.h>
using namespace std;

void findWait(int wt[], int bt[], int n)
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTat(int tat[], int bt[], int wt[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvg(int bt[], int n)
{
    int wt[n];
    int tat[n];

    findWait(wt, bt, n); // calculate wait time

    findTat(tat, bt, wt, n); // calculate turn around time

    float totalWait = 0;
    float totalTat = 0;

    cout << "P \t"
         << "BT\t  "
         << "WT\t"
         << "TAT\n";
    for (int i = 0; i < n; i++)
    {
        totalWait += wt[i];

        totalTat += tat[i];

        cout << 3
             << i + 1 << "\t" << bt[i] << "    \t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "Avg. waiting time :-> " << totalWait / n << endl;

    cout << "Avg. TURN AROUND TIME time :-> " << totalTat / n;
}

int main()
{
    int n;
    cout << "ENTER NUMBER OF PROCESS :->";
    cin >> n;

    int bTime[n];

    cout << "ENTER BURST TIME OF THE PROCESS :->";
    for (int i = 0; i < n; i++)
    {
        cin >> bTime[i];
    }

    findAvg(bTime, n);
    return 0;
}