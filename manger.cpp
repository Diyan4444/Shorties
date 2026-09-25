#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
    string name;
    int id;
    vector<int> marks;
};
void addStudent(vector<Student>& students, const string& name, int id)
{
    auto it = find_if(students.begin(), students.end(), [id](const Student& s) { return s.id == id; });
    if (it != students.end())
    {
        cout << "Student with ID " << id << " already exists.\n";
        return;
    }
    students.push_back({name, id, {}});
    cout << "Student added successfully!\n";
}
void deleteStudent(vector<Student>& students, int id)
{
    for (size_t i = 0; i < students.size(); i++) 
    {
        if (students[i].id == id) 
        {
            students.erase(students.begin() + i);
            cout << "Student removed.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
bool addMarks(vector<Student>& students, int id)
{
    for (auto& s : students)
    {
        if (s.id == id)
        {
            s.marks.clear();
            cout << "Enter marks for 5 subjects:\n";
            for (int i = 1; i <= 5; i++)
            {
                int score;
                cout << "Subject " << i << ": ";
                cin >> score;
                s.marks.push_back(score);
            }
            cout << "Marks added successfully for " << s.name << "!\n";
            return true;
        }
    }
    cout << "Student not found.\n";
    return false;
}
char calculateGrade(const vector<int>& marks)
{
    if (marks.empty()) return 'N'; // No marks entered yet

    int sum = 0;
    for (int score : marks)
    {
        sum += score;
    }
    double avg = static_cast<double>(sum) / marks.size();

    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}
void viewGrade(const vector<Student>& students, int id)
{
    for (const auto& s : students)
    {
        if (s.id == id)
        {
            if (s.marks.empty())
            {
                cout << "No marks found for student " << s.name << ". Please add marks first.\n";
                return;
            }

            char grade = calculateGrade(s.marks);
            cout << "Grade for " << s.name << " (ID " << id << "): " << grade << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
int main()
{
    vector<Student> students;
    char check = 'y';

    while (check == 'y' || check == 'Y')
    {
        cout << "\n1. Add Student\n2. Delete Student\n3. Add Marks (5 Subjects)\n4. View Grade\n5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int id;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student ID: ";
            cin >> id;
            addStudent(students, name, id);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            deleteStudent(students, id);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter student ID to add marks: ";
            cin >> id;
            addMarks(students, id);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter student ID to view grade: ";
            cin >> id;
            viewGrade(students, id);
            break;
        }
        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        cout << "Do you want to continue? (y for Yes, n for No): ";
        cin >> check;
    }
    return 0;
}