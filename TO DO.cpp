#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    string status; // "Pending" or "Completed"
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.push_back({taskDescription, "Pending"});
        cout << "Task \"" << taskDescription << "\" added to the list.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
        } else {
            cout << "\nTo-Do List:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - " << tasks[i].status << "\n";
            }
        }
    }

    void markTaskAsCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].status = "Completed";
            cout << "Task " << taskNumber << " marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            cout << "Task \"" << tasks[taskNumber - 1].description << "\" removed from the list.\n";
            tasks.erase(tasks.begin() + taskNumber - 1);
        } else {
            cout << "Invalid task number.\n";
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); // Clear the newline character left in the input buffer
            string taskDescription;
            cout << "Enter the task: ";
            getline(cin, taskDescription);
            toDoList.addTask(taskDescription);
            break;
        }
        case 2:
            toDoList.viewTasks();
            break;
        case 3: {
            size_t taskNumber;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskNumber;
            toDoList.markTaskAsCompleted(taskNumber);
            break;
        }
        case 4: {
            size_t taskNumber;
            cout << "Enter the task number to remove: ";
            cin >> taskNumber;
            toDoList.removeTask(taskNumber);
            break;
        }
        case 5:
            cout << "Exiting To-Do List Manager. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
