#include <iostream>
#include <string>
#include <vector>


using namespace std;

void MainMenu() {
    cout << "=== Student Management System ===" << endl;
    cout << "1. Add Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Add Course to Student\n";
    cout << "4. Delete Course from Student\n";
    cout << "5. Display All Students\n";
    cout << "6. Exit\n";
}

struct Student {
    string name;
    vector<string> courses;
};

int main() {
    vector<Student> students;
    int choice =0;
    string name ;
    string course;
    while (choice != 6) {
        MainMenu();
        cout <<"enter your choice" << endl;
        cin >> choice ;
        if (choice == 1) {
            cout <<"add the student name" << endl;
            cin >> name ;
            students.push_back({name, {}});
            cout << "student " << name << " added successfully" << endl;
        }
        else if (choice == 2) {

            cout <<"enter the student name" << endl;
            cin >> name ;
            int found = 0;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].name == name) {
                    students.erase(students.begin() + i);
                    cout << "Student removed successfully" << endl;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                cout << "Student does not exist" << endl;
            }

        }
        else if (choice == 3) {
            cout <<"enter the student name" << endl;
            cin >> name ;
            int found=0;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].name == name) {
                    cout << "Enter the course name" << endl;
                    cin >> course;

                    students[i].courses.push_back(course);

                    cout << "Course " << course << " added successfully the student " << name  << endl;

                    found =1;
                    break;
                }
            }
            if (found == 0) {
                    cout << "Student does not exist" << endl;
            }


        }
        else if (choice == 4) {
            cout << "Enter the student name" << endl;
            cin >> name;

            int studentFound = 0;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].name == name) {
                    studentFound = 1;

                    cout << "Enter the course name" << endl;
                    cin >> course;

                    int courseFound = 0;

                    for (int j = 0; j < students[i].courses.size(); j++) {
                        if (students[i].courses[j] == course) {
                            students[i].courses.erase(
                                students[i].courses.begin() + j
                            );

                            cout << "Course removed successfully" << endl;

                            courseFound = 1;
                            break;
                        }
                    }

                    if (courseFound == 0) {
                        cout << "Course is not registered for this student" << endl;
                    }

                    break;
                }
            }

            if (studentFound == 0) {
                cout << "Student does not exist" << endl;
            }
        }
        else if (choice == 5) {
            cout << "---------------------------------" << endl;

            for (int i = 0; i < students.size(); i++) {
                cout << "Student: " << students[i].name << " || " << "Courses: ";

                for (int j = 0; j < students[i].courses.size(); j++) {
                    cout << students[i].courses[j] << " ";
                }

                cout << endl;
                cout << "---------------------------------" << endl;
            }
        }
        else if (choice == 6) {
            cout <<"thank you" << endl;
            break;
        }
        else {
            cout <<"invalid choice try again" << endl;
        }
    }


    return 0;
}