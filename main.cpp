// Omar Tawfik      221000307
// Mostafa ElSheikh 221000362
// Mariam Alaa      221000919
// Nada Zaki        221000829

#include <iostream>
#include <string>
#include "student.h"
#include <mysqlx/xdevapi.h>

using namespace std;


int main()
{
    int nc = 0, ns = 0, nps = 0;
    string cName, cCode, sName, sUser, sPass, sMajor, pJobTitle;
    float cCost = 0;
    int sId;

    cout << "Enter the Number of Students: ";
    cin >> ns;
    cout << "Enter the Number of Courses: ";
    cin >> nc;

    cout << "\n";

    CStudent students[ns]; // array of objects from CStudent class

// start adding data to CStudent class objects

    for(int i = 0; i < ns; i++)
    {
        cout << "Enter Student " << i + 1 << " Name: ";
        cin >> sName;
        cout << "Enter Student " << i + 1 << " ID: ";
        cin >> sId;
        cout << "Enter Student " << i + 1 << " User: ";
        cin >> sUser;
        cout << "Enter Student " << i + 1 << " Password: ";
        cin >> sPass;
        cout << "Enter Student " << i + 1 << " Major: ";
        cin >> sMajor;

        students[i].registerStudent(sName, sId, sUser, sMajor, sPass);
        cout << "\n";
    }

    CCourse courses[nc]; // array of objects from CCourse class

// start adding data to CCourse class objects

    for(int i = 0; i < nc; i++)
    {
        cout << "Enter Course " << i + 1 << " Name: ";
        cin >> cName;
        cout << "Enter Course " << i + 1 << " Code: ";
        cin >> cCode;
        cout << "Enter Course " << i + 1 << " Cost: ";
        cin >> cCost;
        cout << "\n";

        courses[i].AddCourse(cName, cCode, cCost);
    }

// start displaying CStudent class data

    for(int i = 0; i < ns; i++)
        {
            students[i].getStudentInfo(i + 1);
            for(int l = 0; l < 5; l++)
                {
                cout << "Grade " << l + 1 << " : " << students[i].getStudentG(l) << "\n";
                }
            cout << "Student " << i + 1 << " GPA is: " << students[i].claculateGPA();
            cout << "\n";
        }

// start displaying CCourse class data

    for(int i = 0; i < nc; i++)
    {
        courses[i].getCourseInfo(i + 1);
    }

    cout << "\n";

// start taking number of post students and courses

    cout << "Enter the Number of Post Graduate Students: ";
    cin >> nps;
    cout << "Enter the Number of Courses: ";
    cin >> nc;

    CPG_Student student[nps]; // array of objects from CPG_Student class

    cout << "\n";

// start adding data to CPG_Student class objects

    for(int i = 0; i < nps; i++)
    {
        cout << "Enter Student " << i + 1 << " Name: ";
        cin >> sName;
        cout << "Enter Student " << i + 1 << " ID: ";
        cin >> sId;
        cout << "Enter Student " << i + 1 << " User: ";
        cin >> sUser;
        cout << "Enter Student " << i + 1 << " Password: ";
        cin >> sPass;
        cout << "Enter Student " << i + 1 << " Major: ";
        cin >> sMajor;
        cout << "Enter Student " << i + 1 << " Job Title: ";
        cin >>  pJobTitle;

        student[i].registerStudent(sName, sId, sUser, sMajor, sPass);
        student[i].setPostStudent(pJobTitle);
        cout << "\n";
    }

    CCourse course[nc]; // array of objects from CCourse class

// start adding data to CCourse class objects

    for(int i = 0; i < nc; i++)
    {
        cout << "Enter Course " << i + 1 << " Name: ";
        cin >> cName;
        cout << "Enter Course " << i + 1 << " Code: ";
        cin >> cCode;
        cout << "Enter Course " << i + 1 << " Cost: ";
        cin >> cCost;
        cout << "\n";

        course[i].AddCourse(cName, cCode, cCost);
    }

// start displaying CPG_Student class data

    for(int i = 0; i < nps; i++)
        {
            student[i].getStudentInfo(i + 1);
            for(int l = 0; l < 5; l++)
                {
                cout << "Grade " << l + 1 << ": " << student[i].getStudentG(l) << "\n";
                }
            cout << "Student " << i + 1 << " GPA is: " << student[i].claculateGPA();
            cout << "\n";
            cout << "Student " << i + 1 << " Job Title: " << student[i].getPostStudent();
            cout << "\n";
        }

// start displaying CCourse class data

    for(int i = 0; i < nc; i++)
    {
        course[i].getCourseInfo(i + 1);
    }

    return 0;


    Database db;

    db.open();
    db.createTables();

// Insert students and courses   
    db.insertStudent(students[i]);
    db.insertCourse(courses[j]);

// Query database to retrieve data
db.close();



}
