#include <iostream>
using namespace std;

int main(){
    int age = 35;
if (age >= 20 && age < 55) {
    cout << "You are an adult." << endl;
} else if (age >= 60) {
    cout << "You are a senior citizen." << endl;
} else {
    cout << "You are a minor." << endl;
}

}
