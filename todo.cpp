#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> tasks;
void add(string task)
{
    tasks.push_back(task);
    cout << "Task added: " << task << endl;
}
void del(int n)
{
    if (n > 0 && n <= tasks.size())
    {
        cout << "Task deleted: " << tasks[n - 1] << endl;
        tasks.erase(tasks.begin() + n - 1);
    }
    else
    {
        cout << "Invalid task number." << endl<<endl<<endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "1. Add Task\n2. Delete Task\n3. View Tasks\n4. Exit\n";
        cin >> choice;
        cin.ignore(); 
        switch (choice)
        {
        case 1:
            {
                string task;
                cout << "Enter task: ";
                getline(cin, task);
                add(task);
                cout<<endl;
                break;
            }
        case 2:
            {
                int n;
                cout << "Enter task number to delete: ";
                cin >> n;
                del(n);
                cout<<endl;
                break;
            }
        case 3:
            {
                if(tasks.empty())
                {
                    cout << "No tasks available." << endl<<endl<<endl;
                    break;
                }
                cout << "Tasks:\n";
                for (int i = 0; i < tasks.size(); i++)
                {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
                cout<<endl;
                break;
            }
        case 4:
            cout << "Exiting..." << endl<<endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}