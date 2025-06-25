/*
Aamer Goual-Belhamidi
axg210204
Programming Fundamentals
CS1436.008
12/1/23
12/7/23
12/7/23
*/

//Grade Book

#include <iostream>
#include <cstring>
//need c string file to save student names

using namespace std;

int main() {
    // size of the arrays
    const int sizeOfArray = 5;
    const int numOfExams = 4;

    // arrays to store student names, letter grades, and test scores
    string studentNames[sizeOfArray];
    char letterGrade[] = {'A', 'B', 'C', 'D', 'F'};
    double studentScores[sizeOfArray][numOfExams];

    // program menu explanation
    cout << "There are five students, each taken four tests." << endl;
    cout << "This program will drop your lowest score and calculate your grade." << endl;

    // getting the input of names from the user
    for (int index = 0; index < sizeOfArray; index++) {
        
        cout << "What is the name of student " << (index + 1) << "? ";
        cin >> studentNames[index];
        //using index +1 because index starts at 0
    }

    // getting the test scores for each student
    for (int studentIndex = 0; studentIndex < sizeOfArray; studentIndex++) {
    
        cout << "Enter scores for " << studentNames[studentIndex] << ": " << endl;

        for (int examIndex = 0; examIndex < numOfExams; examIndex++) {
            // input validation for the exam scores
            do {
                cout << "Enter score for exam " << (examIndex + 1) << ": ";
                cin >> studentScores[studentIndex][examIndex];

                if (studentScores[studentIndex][examIndex] < 0 || studentScores[studentIndex][examIndex] > 100) {
                    cout << "Invalid score. Please enter a score between 0 and 100." << endl;
                }

            } while (studentScores[studentIndex][examIndex] < 0 || studentScores[studentIndex][examIndex] > 100);
        //do if while loop ensures that user has to enter scores between 0 and 100
        }

    }

    // calculates the averages and determine letter grades for each student
    for (int studentIndex = 0; studentIndex < sizeOfArray; studentIndex++) {
        double lowest = studentScores[studentIndex][0];
        int sum = 0;

        // find the lowest test score
        for (int examIndex = 1; examIndex < numOfExams; examIndex++) {
            // switching to lowest if a lower score is found
            if (studentScores[studentIndex][examIndex] < lowest) {
                lowest = studentScores[studentIndex][examIndex];
            }
        }

        // calculate the sum of valid test scores
        for (int examIndex = 0; examIndex < numOfExams; examIndex++) {
            if (studentScores[studentIndex][examIndex] != lowest) {
        //the if statement ensures that the sum doesnt include the lowest, just skips
                sum += studentScores[studentIndex][examIndex];
            }
        }

        // find the average of exams, -1 because of total numofExams each took
        double avg = sum / (numOfExams - 1);

        // find and outfit the letter grade for each student
        if (avg >= 90) {
            cout << studentNames[studentIndex] << "'s grade is: A" << endl;
        } else if (avg >= 80) {
            cout << studentNames[studentIndex] << "'s grade is: B" << endl;
        } else if (avg >= 70) {
            cout << studentNames[studentIndex] << "'s grade is: C" << endl;
        } else if (avg >= 60) {
            cout << studentNames[studentIndex] << "'s grade is: D" << endl;
        } else {
            cout << studentNames[studentIndex] << "'s grade is: F" << endl;
        }
    }
    //if else statement to print the students final grade

    return 0;
}
//could have used functions but the lab did not mention use of it so i didnt
//also we have not learned how to pass two arrays into a function so wont work

