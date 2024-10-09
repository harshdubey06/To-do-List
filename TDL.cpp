#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks in the list:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Task deleted: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore();
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                todoList.viewTasks();
                break;
            }
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.markTaskCompleted(index - 1);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index to delete: ";
                cin >> index;
                todoList.deleteTask(index - 1);
                break;
            }
            case 5: {
                cout << "Goodbye!" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
