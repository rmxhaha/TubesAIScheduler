#ifndef MATA_KULIAH_H
#define MATA_KULIAH_H

#include "Schedule.hpp"
#include "Classroom.hpp"
#include <memory>
#include <set>
#include <string>
#include <exception>
#include <vector>

class ScheduleNotDefined: public std::exception {
public:
  const char* what() const throw();
};

class ScheduleInvalid: public std::exception {
public:
  ScheduleInvalid(const string& v);
  const char* what() const throw();
private:
  const string message;
};

class Course {
public:
  Course(const string& name, const int duration, const int open_time, const int close_time, const vector<shared_ptr<Classroom>>& rooms, const std::vector<Day>& days = every_day);
  Course(const Course& c);

  void check_schedule() const;
  void check_schedule(const Schedule& s) const;

  const vector<shared_ptr<Classroom>>& get_possible_classroom() const;
  const vector<Day> get_possible_day() const;
  void set_schedule(const Schedule&);
  const Schedule& get_schedule() const ;


  const string name;
  const int duration;
  const int open_time;
  const int close_time;

  //void print_data() const;

private:
  unique_ptr<Schedule> schedule;
  vector<shared_ptr<Classroom>> possible_classroom;
  vector<Day> possible_day;
};

#endif
