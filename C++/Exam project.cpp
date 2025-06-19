#include <iostream> // For input/output (cin, cout)
#include <cstring>  // For string manipulation (not actually used in this code)
#include <iomanip>  // For formatting output (e.g., setting decimal precision)
using namespace std;   // To avoid writing std:: before standard functions

// Struct to present a Student
struct Student {
    char name[30];  // Fixed-size character array to store student name
    float* grades;  // Pointer to dynamically allocated array of grades
    int nGrades;    // Number of grades the student has
};

// here we Abstract base class for grade metric calculation (interface)
class GradeMetric {
public:
    virtual float compute(const Student* student) = 0;     // Pure virtual function (must be overridden)
    virtual ~GradeMetric() {}   // Virtual destructor for proper cleanup
};

//this stage is about Average grade calculator
class AverageMetric : public GradeMetric {
public:
    float compute(const Student* student) override {     // Override base compute method
        if (student->nGrades == 0) return 0.0f;        // Return 0 if no grades available
        float sum = 0.0f;                             // Variable to store sum of grades
        for (int i = 0; i < student->nGrades; ++i)
            sum += *(student->grades + i);           // Add each grade using pointer arithmetic
        return sum / student->nGrades;               // Return average
    }
};

// at this step we derived class to calculate minimum grade
class MinMetric : public GradeMetric {
public:
    float compute(const Student* student) override {      // Override base compute method
        if (student->nGrades == 0) return 0.0f;           // Return 0 if no grades available
        float min = *(student->grades);                   // Initialize min with the first grade
        for (int i = 1; i < student->nGrades; ++i)        // Start from second grade
            if (*(student->grades + i) < min)             // Compare current grade to min
                min = *(student->grades + i);             // Update min if current grade is smaller
        return min;                                       // Return the minimum grade
    }
};

// here we are going to make function to Add grade dynamically
void addGrade(Student& student, float grade) {           
    float* newGrades = new float[student.nGrades + 1];     // Allocate new array with space for one more grade
    for (int i = 0; i < student.nGrades; ++i)              // Copy old grades to new array
        *(newGrades + i) = *(student.grades + i);
    *(newGrades + student.nGrades) = grade;                 // Add new grade at the end
    delete[] student.grades;                                // Delete old grades array to free memory
    student.grades = newGrades;                             // Update pointer to new array
    ++student.nGrades;                                      // Increase number of grades
}

int main() {
    Student student;                     // Declare a student variable
    student.grades = nullptr;            // Initialize grades pointer to null (no grades yet)
    student.nGrades = 0;                 // Initially no grades

    // Input student name
    cout << "Enter student name: ";      
    cin.getline(student.name, 30);       // Read full line for name (including spaces)

    // Input number of grades
    int totalGrades;
    cout << "Enter number of grades: ";
    cin >> totalGrades;                    

    // Input each grade
    for (int i = 0; i < totalGrades; ++i) {
        float grade;
        cout << "Enter grade #" << (i + 1) << ": ";
        cin >> grade;
        addGrade(student, grade);                    // Dynamically add grade
    }

    // Create metrics
    GradeMetric* metrics[2];
    metrics[0] = new AverageMetric();               // Pointer to average calculator
    metrics[1] = new MinMetric();                   // Pointer to min calculator

    // Output results
    cout << "\nStudent: " << student.name << endl;
    cout << "Grades: ";
    for (int i = 0; i < student.nGrades; ++i)                   // Display each grade
        cout << *(student.grades + i) << " ";                   // Set 2 decimal places
    cout << fixed << setprecision(2) << endl;
    
    // Compute and display metrics
    cout << "Average: " << metrics[0]->compute(&student) << endl;   // Call compute on average
    cout << "Minimum: " << metrics[1]->compute(&student) << endl;   // Call compute on min

    // Cleanup memory to avoid leaks
    delete[] student.grades;           // Free dynamically allocated grades
    delete metrics[0];                 // Delete average metric object
    delete metrics[1];                // Delete min metric object

    return 0;                        // Exit the program
}

