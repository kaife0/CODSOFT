#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addTask(vector<string> &tasks);
void viewTasks(const vector<string> &tasks);
void deleteTask(vector<string> &tasks); 

int main() {
    vector<string> tasks;
    char choice;
    do {
        cout << "\nWelcome to Simple To-Do List!" << endl; 
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                deleteTask(tasks);
                break;
            case '4':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}

void addTask(vector<string> &tasks) {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "\nTasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to delete." << endl;
        return;
    }

    viewTasks(tasks);
    int index;
    cout << "Enter the index of the task to delete: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid index. Please try again." << endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "Task deleted successfully!" << endl;
}
