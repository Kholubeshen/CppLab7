// Course.h
#include <iostream>

using namespace std;
struct Course {

    enum dayOfWeek {MON, TUE, WED, THU, FRI, SAT, SUN, NOTADAY};
    //Methods
    Course () = default;
    Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);
    Course (const Course & m);


    dayOfWeek convert(char c);

    //Members
    string title; // Name of Course
    static constexpr char days[7] = {'M', 'T', 'W', 'R', 'F', 'S', 'U'};

    dayOfWeek day; // Day of Course
    unsigned int start_time; // Course start time in HHMM format
    unsigned int finish_time; // Course finish time in HHMM format

    //Overloaded Operators
    Course & operator = (const Course & m);
    bool operator < (const Course & m) const;
    bool operator == (const Course & m) const;
    bool operator != (const Course & m) const; // Overloaded for comparing for overlap
};

// Helper operator for output & input
ostream &operator << (ostream &os, const Course & m);
istream &operator >> (istream &is, Course &m);

