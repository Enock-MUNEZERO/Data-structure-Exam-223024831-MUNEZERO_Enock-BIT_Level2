#include <iostream> // this is For input/output (cin, cout).
#include <cstring>  // this is For string manipulation (not actually used in this code).
#include <iomanip>  // this is For formatting output (e.g., setting decimal precision).
using namespace std;   // we use this To avoid writing std::more times, before standard functions.

// Here is struct to present a Student.
struct Student {
    char name[30];  // This line used to fixed-size character array to store student name.
    float* grades;  // This line used for pointer to dynamically allocated array of grades.
    int nGrades;    // This line used for Number of grades the student has.
};

// here we Abstract base class for grade metric calculation (interface).
class GradeMetric {
public:
    virtual float compute(const Student* student) = 0;     // This line used for Pure virtual function (must be overridden)
    virtual ~GradeMetric() {}   // This line used for Virtual destructor for proper cleanup
};

//this stage is about Average grade calculator
class AverageMetric : public GradeMetric {
public:
    float compute(const Student* student) override {     // This line used for override base compute method
        if (student->nGrades == 0) return 0.0f;        // This line used for return 0 if no grades available
        float sum = 0.0f;                             // This line used for variable to store sum of grades
        for (int i = 0; i < student->nGrades; ++i)
            sum += *(student->grades + i);           // This line used for add each grade using pointer arithmetic
        return sum / student->nGrades;               // This line used for return average
    }
};

// at this step we derived class to calculate minimum grade
class MinMetric : public GradeMetric {                    // This line used for inherits from the abstract base class GradeMetric
public:
    float compute(const Student* student) override {      // This line used for override base compute method
        if (student->nGrades == 0) return 0.0f;           // This line used for return 0 if no grades available
        float min = *(student->grades);                   // This line used for initialize min with the first grade
        for (int i = 1; i < student->nGrades; ++i)        // This line used for start from second grade
            if (*(student->grades + i) < min)             // This line used for compare current grade to min
                min = *(student->grades + i);             // This line used for update min if current grade is smaller
        return min;                                       // This line used for return the minimum grade
    }
};

// here we are going to make function to Add grade dynamically
void addGrade(Student& student, float grade) {           
    float* newGrades = new float[student.nGrades + 1];     // This line used for allocate new array with space for one more grade
    for (int i = 0; i < student.nGrades; ++i)              // This line used for copy old grades to new array
        *(newGrades + i) = *(student.grades + i);
    *(newGrades + student.nGrades) = grade;                 // This line used for add new grade at the end
    delete[] student.grades;                                // This line used for delete old grades array to free memory
    student.grades = newGrades;                             // This line used for update pointer to new array
    ++student.nGrades;                                      // This line used for increase number of grades
}

int main() {
    Student student;                     // This line used for declare a student variable
    student.grades = nullptr;            // This line used for initialize grades pointer to null (no grades yet)
    student.nGrades = 0;                 // This line used for initially no grades

    // Input student name
    cout << "Enter student name: ";      
    cin.getline(student.name, 30);       // This line used for read full line for name (including spaces)

    // Input number of grades
    int totalGrades;                          // This line used for variable to store how many grades will be entered
    cout << "Enter number of grades: ";
    cin >> totalGrades;                    

    // Input each grade
    for (int i = 0; i < totalGrades; ++i) {
        float grade;                                 // This line used for temporary variable to store user input
        cout << "Enter grade #" << (i + 1) << ": ";
        cin >> grade;
        addGrade(student, grade);                    // This line used for dynamically add grade
    }

    // Create metrics
    GradeMetric* metrics[2];                        // This line used for array of pointers to GradeMetric (interface) for polymorphism
    metrics[0] = new AverageMetric();               // This line used for pointer to average calculator
    metrics[1] = new MinMetric();                   // This line used for pointer to min calculator

    // Output results
    cout << "\nStudent: " << student.name << endl;              // This line used for display student name
    cout << "Grades: ";
    for (int i = 0; i < student.nGrades; ++i)                   // This line used for display each grade
        cout << *(student.grades + i) << " ";                   // This line used for output each grade using pointer
    cout << fixed << setprecision(2) << endl;                   // This line used for format: show 2 digits after decimal
    
    // Compute and display metrics
    cout << "Average: " << metrics[0]->compute(&student) << endl;   // This line used for call compute on average
    cout << "Minimum: " << metrics[1]->compute(&student) << endl;   // This line used for call compute on min

    // Cleanup memory to avoid leaks
    delete[] student.grades;           // This line used for free dynamically allocated grades
    delete metrics[0];                 // This line used for delete average metric object
    delete metrics[1];                // This line used for delete min metric object

    return 0;                        // This line used for exit the program
}

