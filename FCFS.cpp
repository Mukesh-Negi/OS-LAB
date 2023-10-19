#include <iostream>
using namespace std;

// Function to Calculate waiting time
// and average waiting time
void CalculateWaitingTime(int at[],
                          int bt[], int N)
{

    // Declare the array for waiting
    // time
    int wt[N];

    // Waiting time for first process
    // is 0
    wt[0] = 0;

    // Print waiting time process 1
    cout << "PN\t\tAT\t\t"
         << "BT\t\tWT\n\n";
    cout << "1"
         << "\t\t" << at[0] << "\t\t"
         << bt[0] << "\t\t" << wt[0] << endl;

    // Calculating waiting time for
    // each process from the given
    // formula
    for (int i = 1; i < 5; i++)
    {
        wt[i] = (at[i - 1] + bt[i - 1] + wt[i - 1]) - at[i];

        // Print the waiting time for
        // each process
        cout << i + 1 << "\t\t" << at[i]
             << "\t\t" << bt[i] << "\t\t"
             << wt[i] << endl;
    }

    // Declare variable to calculate
    // average
    float average;
    float sum = 0;

    // Loop to calculate sum of all
    // waiting time
    for (int i = 0; i < 5; i++)
    {
        sum = sum + wt[i];
    }

    // Find average waiting time
    // by dividing it by no. of process
    average = sum / 5;

    // Print Average Waiting Time
    cout << "\nAverage waiting time = "
         << average;
}

// Driver code
int main()
{
    // Number of process
    cout << "ENTER NUMBER OF PROCESS :->";
    int n;
    cin >> n;

    // Array for Arrival time
    int at[n];
    int bt[n];
    cout << "ENTER ARRIVAL TIME :-> \n";
    for (int i = 0; i < n; i++)
    {
        cin >> at[i];
    }

    cout << "ENTER BURST TIME :-> \n";
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }

    // Function call to find
    // waiting time
    CalculateWaitingTime(at, bt, n);
    return 0;
}
