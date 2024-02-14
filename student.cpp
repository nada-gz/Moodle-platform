#include "student.h"

CCourse :: CCourse() // Constructor
    {
        course_name = "NULL";
        course_code = "NULL";
        course_cost = 0;
    }

void CCourse :: setCourseName(string cn1)
    {
        course_name = cn1;
    }

void CCourse :: setCourseCode(string cc1)
    {
        course_code = cc1;
    }

void CCourse :: setCourseCost(float ccc1)
    {
        course_cost = ccc1;
    }

void CCourse :: AddCourse(string cn2, string cc2, float ccc2)
    {
        setCourseName(cn2);
        setCourseCode(cc2);
        setCourseCost(ccc2);
    }

string CCourse :: getCourseName()
    {
        return course_name;
    }

string CCourse :: getCourseCode()
    {
        return course_code;
    }

float CCourse :: getCourseCost()
    {
        return course_cost;
    }

void CCourse :: getCourseInfo(int i)
    {
        cout << endl << "Course " << i << " Name is: " << getCourseName() << "\n" << "Course " << i << " Code is: " << getCourseCode() << "\n" << "Course " << i << " Cost is: " << getCourseCost() << "\n";
    }







CStudent :: CStudent() // Constructor
    {
        student_name = "NULL";
        student_id = 0;
        student_email_username = "NULL";
        student_major = "NULL";
        student_score = 0;
        student_email_password = "NULL";
        for(int i = 0; i < 5; i++)
        {
            student_grades[i] = 0;
        }
    }

void CStudent :: setStudentName(string sn1)
    {
        student_name = sn1;
    }

void CStudent :: setStudentId(int id1)
    {
        student_id = id1;
    }

void CStudent :: setStudentEU(string user1)
    {
        student_email_username = user1;
    }

void CStudent :: setStudentM(string major1)
    {
        student_major = major1;
    }

void CStudent :: setStudentEP(string password1)
    {
        student_email_password = password1;
    }

void CStudent :: setStudentG()
    {
        for(int i = 0; i < 5;i++)
        {
            cout << "Enter Grade " << i + 1 << ": ";
            cin >> student_grades[i];
        }
    }

void CStudent :: registerStudent(string sn2, int id2, string user2, string major2, string password2)
    {
        setStudentName(sn2);
        setStudentM(major2);
        setStudentId(id2);
        setStudentEU(user2);
        setStudentEP(password2);
        setStudentG();
    }

string CStudent :: getStudentName()
    {
        return student_name;
    }

int CStudent :: getStudentId()
    {
        return student_id;
    }

string CStudent :: getStudentEU()
    {
        return student_email_username;
    }

string CStudent :: getStudentM()
    {
        return student_major;
    }

string CStudent :: getStudentEP()
    {
        return student_email_password;
    }

float CStudent :: getStudentG(int i)
    {
        return student_grades[i];
    }

void CStudent :: getStudentInfo(int i)
    {
        cout << endl << "Student " << i << " Name is: " << getStudentName() << "\n" << "Student " << i << " ID is: " << getStudentId() << "\n" << "Student " << i << " User-name is: " << getStudentEU() << "\n" << "Student " << i << " Password is: " << getStudentEP() << "\n" << "Student " << i << " Major is: " << getStudentM() << "\n";
    }

float CStudent :: claculateGPA()
    {
        float sum = 0;
        for(int i = 0; i < 5; i++)
        {
            sum += student_grades[i];
        }
        student_score = sum / 100;

        return student_score;
    }

void CPG_Student :: setPostStudent(string JT)
    {
        pg_student_job_title = JT;
    }

string CPG_Student :: getPostStudent()
    {
        return pg_student_job_title;
    }






Database::Database() {
    db = nullptr;
}

bool Database::open() {
    int rc = sqlite3_open("school.db", &db);
    return rc == SQLITE_OK;
}

bool Database::createTables() {
    // SQL to create Student table
    const char* sql = "CREATE TABLE ..."; 
    
    // Execute SQL    
    return executeSQL(sql);
}

bool Database::executeSQL(const char* sql) {
    char* err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        // Handle error
        return false; 
    }
    
    return true;
}

void Database::insertStudent(CStudent& student) {
    const char* sql = "INSERT INTO Student ...";
    
    // Bind student attributes and execute SQL
}
