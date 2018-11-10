#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void checkConflict(vector<Course> courses);
void readFile(vector<Course> &courses);
void printSchedule(vector<Course> courses);



int main () {
    vector<Course> courses;
    readFile(courses);
    sort(courses.begin(),courses.end());
    checkConflict(courses);
    printSchedule(courses);

    return 0;
}

void printSchedule(vector<Course> courses) {
    copy(courses.begin(), courses.end(), ostream_iterator<Course>(cout));
}

void readFile(vector<Course>  &courses){
    ifstream f;
    f.open("../courses.txt");
    Course c;
    while(f >> c){
        courses.push_back(c);
    }
}

void checkConflict(vector<Course> courses) {
    for (int i = 0; i < courses.size(); ++i) {
        for (int j = i + 1; j < courses.size(); ++j) {
            if(courses[i] != (courses[j])){
                cout << "CONFLICT: " << endl;
                cout << courses[i];
                cout << courses[j] << endl;
            }
        }
    }
}
