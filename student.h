#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>
#include "sqlite3.h"


using namespace std;

class CCourse
{
    private:
        string course_name;
        string course_code;
        float course_cost;
    public:
        CCourse(); // Constructor

        void setCourseName(string cn1);

        void setCourseCode(string cc1);

        void setCourseCost(float ccc1);

        void AddCourse(string cn2, string cc2, float ccc2);

        string getCourseName();

        string getCourseCode();

        float getCourseCost();

        void getCourseInfo(int i);
};

class CStudent
{
    private:
        string student_name;
        int student_id;
        string student_email_username;
        string student_major;
        float student_grades[5];
        float student_score;
        string student_email_password;
    public:
        CStudent();  // Constructor

        void setStudentName(string sn1);

        void setStudentId(int id1);

        void setStudentEU(string user1);

        void setStudentM(string major1);

        void setStudentEP(string password1);

        void setStudentG();

        void registerStudent(string sn2, int id2, string user2, string major2, string password2);

        string getStudentName();

        int getStudentId();

        string getStudentEU();

        string getStudentM();

        string getStudentEP();

        float getStudentG(int i);

        void getStudentInfo(int i);

        float claculateGPA();
};

class CPG_Student : public CStudent
{
    private:
        string pg_student_job_title;
    public:
        void setPostStudent(string JT);

        string getPostStudent();
};

class Database {
public:
    Database();
    ~Database();
    
    bool open(); // Opens the database connection
    void close(); // Closes the database connection
    
    bool createTables();  // Creates tables for Student and Course
    
    void insertStudent(CStudent& student); // Insert student into database
    void insertCourse(CCourse& course); // Insert course into database
    
    // Query methods to retrieve student and course data...
private:
    sqlite3* db;
    bool executeSQL(const char* sql) {
        // Execute SQL statement and return result
    } 
};     




#endif
