#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Student{
    string studentID;
    string name;
    string course;
    float gpa;
};

string getStanding(float gpa){
    if(gpa>=90 && gpa<=100) return "Excellent";
    else if(gpa>=80) return "Very Good";
    else if(gpa>=70) return "Good";
    else if(gpa>=60) return "Passing";
    else return "Failed";
}

bool isDuplicateID(const vector<Student> &students, string id){
    for(const auto &s : students){
        if(s.studentID == id){
            return true;
        }
    }
    return false;
}

void addStudent(vector<Student>& students){
    Student s;

    cout<<"\nEnter Student ID: ";
    cin>>s.studentID;

    while(isDuplicateID(students, s.studentID)){
        cout<<"ID already exists! Enter another ID: ";
        cin>>s.studentID;
    }

    cin.ignore();
    cout<<"Enter Name: ";
    getline(cin, s.name);

    cout<<"Enter Course: ";
    getline(cin, s.course);

    cout<<"Enter GPA (0-100): ";
    cin>>s.gpa;

    students.push_back(s);
    cout<<"Student added successfully!\n";
}

void displayStudents(const vector<Student> &students){
    if(students.empty()){
        cout<<"\nNo records found.\n";
        return;
    }

    cout<<"\n==============================================================\n";
    cout<<left<<setw(15)<<"ID"
         <<setw(20)<<"Name"
         <<setw(15)<<"Course"
         <<setw(10)<<"GPA"
         <<setw(15)<<"Standing"<<endl;
    cout<<"==============================================================\n";

    for(const auto &s : students){
        cout<<left<<setw(15)<<s.studentID
             <<setw(20)<<s.name
             <<setw(15)<<s.course
             <<setw(10)<<s.gpa
             <<setw(15)<<getStanding(s.gpa)<<endl;
    }
}

void editStudent(vector<Student>& students){
    string id;
    cout<<"\nEnter Student ID to edit: ";
    cin>>id;

    for(auto& s : students){
        if(s.studentID == id){
            cin.ignore();
            cout<<"Enter new Name: ";
            getline(cin, s.name);

            cout<<"Enter new Course: ";
            getline(cin, s.course);

            cout<<"Enter new GPA: ";
            cin>>s.gpa;

            cout<<"Student updated successfully!\n";
            return;
        }
    }
    cout<<"Student not found!\n";
}

void deleteStudent(vector<Student> &students){
    string id;
    cout<<"\nEnter Student ID to delete: ";
    cin>>id;

    for(int i=0; i<students.size(); i++){
        if(students[i].studentID == id){
            students.erase(students.begin() + i);
            cout<<"Student deleted successfully!\n";
            return;
        }
    }
    cout<<"Student not found!\n";
}

int main(){
    vector<Student>students;
    int choice;

    do{
        cout<<"\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout<<"1. Add Student\n";
        cout<<"2. Edit Student\n";
        cout<<"3. Delete Student\n";
        cout<<"4. Display Students\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                editStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                displayStudents(students);
                break;
            case 5:
                cout<<"Exiting program...\n";
                break;
            default:
                 cout<<"Invalid choice!\n";
        }

    }while(choice != 5);

    return 0;
}
