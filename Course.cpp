#include "Course.hpp"


using namespace std;

constexpr char Course::days[];

//Constructs new object of type course
Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) :
    title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}

//Copy constructor
Course::Course (const Course & m) = default;

Course & Course::operator =(const Course & m) {
    this->title = m.title;
    this->day = m.day;
    this->start_time = m.start_time;
    this->finish_time = m.finish_time;
    return *this;
}
bool Course::operator == (const Course & m) const {
    return (this->day == m.day && this->start_time == m.start_time && this->finish_time == m.finish_time);
}

bool Course::operator < (const Course & m) const {
    if(this->day == m.day){
        if(this->start_time == m.start_time){
            return (this->finish_time < m.finish_time);
        } else {
            return (this->start_time < m.start_time);
        }
    } else {
        return (this->day < m.day);
    }
}

bool Course::operator != (const Course & m) const {
    if (this->day == m.day) {
        return (this->start_time == m.start_time ||
                this->finish_time == m.finish_time ||
                (this->start_time < m.start_time && this->finish_time > m.start_time) ||
                (m.start_time < this->start_time && m.finish_time > this->start_time));
    }
    return false;
}


ostream & operator << (ostream &os, const Course & m) {
    os << m.title << " " << m.days[m.day] << " " << m.start_time << " " << m.finish_time << endl;
    return os;
}

Course::dayOfWeek Course::convert(char c){
    switch(c){
        case 'M':
            return Course::MON;
        case 'T':
            return Course::TUE;
        case 'W':
            return Course::WED;
        case 'R':
            return Course::THU;
        case 'F':
            return Course::FRI;
        case 'S':
            return Course::SAT;
        case 'U':
            return Course::SUN;
        default:
            return Course::NOTADAY;
    }
}

istream &operator >> (istream &is, Course &m){
    char c;
    is >> m.title >> c >> m.start_time >> m.finish_time;
    m.day = m.convert(c);
    return is;
}
