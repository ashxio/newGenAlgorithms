#include <iostream>
#include <vector>
#include <string>
using std::cout, std::cin, std::endl;
using namespace std;

/**
 * Create a simple student enrollment system using a menu.
 * 
 * You are given a pre-filled list of student names. Your program should allow the user
 * to manage this list by choosing options from a menu.
 * 
 * The program should support the following features:
 * 1. Add Student
 * 2. Remove Student
 * 3. Update Student
 * 4. Search Student
 * 5. Show All Students
 * 6. Show Total Students
 * 
 */

void addStudent(std::vector<std::string>& students) {
    std::string name;
    std::cin.ignore();
    std::cout << "Enter student name to add: ";
    std::getline(std::cin, name);
    
    students.push_back(name);
    cout << "Student " << name << " added successfully" << endl;
    /**
     * Add the entered student name from the user input into
     * the students vector and then display the success message.
     */

}

void searchStudent(const std::vector<std::string>& students) {
    std::string name;
    std::cin.ignore();
    std::cout << "Enter student name to search: ";
    std::getline(std::cin, name);
    bool found = false;

    for (int i = 0; i < students.size(); i++){
        if (students[i] == name){
           cout << "Student " << name << " found at position " << i + 1 << endl; 
           found = true;
           break;
        }
    }
    if (found == false){
            cout << "Student " << name << " not found." << endl; 
    }
    /**
     * Search the student by name
     * - if found, show the position (e.g., "Student found at position X.")
     * - if not found, show "Student not found."
     * 
     * Use a loop or to check if the name exists in the vector
     */
}

void removeStudent(std::vector<std::string>& students) {
    std::string name;
    std::cin.ignore();
    std::cout << "Enter student name to remove: ";
    std::getline(std::cin, name);
    bool found = false;

    for (int i = 0; i < students.size(); i++){
        if (students[i] == name){
            students.erase(students.begin() + i); 
            cout << "Student " << name << " removed successfully." << endl;
            found = true;
            break;
        }
    }
    if (found == false){
            cout << "Student " << name << " not found." << endl; 
    }

    /**
     * Ask for the student name to remove from the list
     * - if found, show "Student removed successfully."
     * - if not found, show "Student not found."
     * 
     * Use a loop or to check if the name exists in the vector
     */
}

void updateStudent(std::vector<std::string>& students) {
    std::string oldName, newName;
    std::cin.ignore();
    cout << "Enter the student old name to update: ";
    getline(cin, oldName);
    bool found = false;

    for (int i = 0; i < students.size(); i++){
        if (students[i] == oldName){
            cout << "Enter student new name: ";
            getline(cin, newName);
            students[i] = newName;
            cout << "Student name updated from " << oldName << "to " << newName << "successfully." << endl;
            found = true;
            break;
        }
    }
    if (found == false){
            cout << "Student " << oldName << " not found." << endl; 
    }
    /**
     * Ask for the current student name to change and then check if the student
     * name exist. If found, ask for a new name and update the student’s name.
     */
}

void showAllStudents(const std::vector<std::string>& students) {
    if (!students.empty()){
        cout << "List of students: " << endl;
        for (int i = 0; i < students.size(); i++){
            cout << i + 1 << "." << students[i] << endl;
        }
    } else {
        cout << "No students enrolled yet.";
    }
    /**
     * Check if the vector is empty
     * - If empty, show "No students enrolled yet."
     * Use a loop to print all student names with numbering
     * Example:
     * 1. Bunleap
     * 2. Deny
     */
}

void showTotalStudents(const std::vector<std::string>& students) {
    //  Show the number of students
    cout << "Total students: " << students.size() << endl;
}

int main() {
    std::vector<std::string> students = {"Bunleap", "Deny", "Methy", "Seyha"};
    int choice; 

    do {
        std::cout << "\n===== Student Enrollment System =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. Update Student\n";
        std::cout << "4. Search Student\n";
        std::cout << "5. Show All Students\n";
        std::cout << "6. Show Total Students\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: removeStudent(students); break;
            case 3: updateStudent(students); break;
            case 4: searchStudent(students); break;
            case 5: showAllStudents(students); break;
            case 6: showTotalStudents(students); break;
            case 0: std::cout << "Exiting program. Goodbye!\n"; break;
            default: std::cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
