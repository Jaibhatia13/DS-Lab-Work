#include <iostream>
#include <vector>

using namespace std;

const int NUM_SUBJECTS = 5;
const int NUM_STUDENTS = 3;

void calculateTotalAndAverage(vector<vector<int>> &marks)
{
    int numStudents = marks.size();

    for (int i = 0; i < numStudents; ++i)
    {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; ++j)
        {
            total += marks[i][j];
        }
        cout << "Total marks for Student " << (i + 1) << ": " << total << endl;
    }

    for (int j = 0; j < NUM_SUBJECTS; ++j)
    {
        int subjectTotal = 0;
        for (int i = 0; i < numStudents; ++i)
        {
            subjectTotal += marks[i][j];
        }
        double subjectAverage = (subjectTotal * 1.0) / numStudents;
        cout << "Average marks for Subject " << (j + 1) << ": " << subjectAverage << endl;
    }
}

int main()
{
    vector<vector<int>> marks(NUM_STUDENTS, vector<int>(NUM_SUBJECTS));

    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        cout << "Enter marks for Student " << (i + 1) << " (5 subjects): ";
        for (int j = 0; j < NUM_SUBJECTS; ++j)
        {
            cin >> marks[i][j];
        }
    }

    calculateTotalAndAverage(marks);

    return 0;
}
