#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Student { // class Student with public methods addGrade, removeGrade, print and private members name and grades (vector of int)
public: // public methods of the class Student
    Student(string name) : name(name) {}
    void addGrade(int grade) {
        grades.push_back(grade);
    }
    void removeGrade(int grade) {
        grades.erase(remove(grades.begin(), grades.end(), grade), grades.end());
    }
    void print() {
        cout << name << ": ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

private: // private members of the class Student
    string name;
    vector<int> grades;
};

class GradeManager { // class GradeManager with public methods addStudent, removeStudent, addGrade, removeGrade, print and private member students (map of string and Student)
public:
    void addStudent(string name) {
        students[name] = Student(name);
    }
    void removeStudent(string name) {
        students.erase(name);
    }
    void addGrade(string name, int grade) {
        students[name].addGrade(grade);
    }
    void removeGrade(string name, int grade) {
        students[name].removeGrade(grade);
    }
    void print() {
        for (auto& student : students) {
            student.second.print();
        }
    }

    private: // private member of the class GradeManager
        map<string, Student> students;
};


int main() {
    GradeManager gradeManager;
    gradeManager.addStudent("Zack");
    gradeManager.addStudent("Will");
    gradeManager.addGrade("Zack", 90);
    gradeManager.addGrade("Zack", 80);
    gradeManager.addGrade("Will", 70);
    gradeManager.addGrade("Will", 60);
    gradeManager.print();
    gradeManager.removeGrade("Zack", 80);
    gradeManager.removeStudent("Will");
    gradeManager.print();
    return 0;
}

