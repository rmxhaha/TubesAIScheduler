#include <iostream>

#include "Course.hpp"
#include "Classroom.hpp"
#include "State.hpp"

#include <memory>

using namespace std;

int main(){
  RoomVector rooms;
  rooms.emplace_back(new Classroom("7606",8,16));
  rooms.emplace_back(new Classroom("7602",8,16));
  CourseVector courses;

  courses.emplace_back(new Course("AI",2, 7, 15));
  courses.emplace_back(new Course("TBFO",3, 7, 12));

//  course->set_schedule(Schedule(room,Day::Monday,8,9));
//  course->get_schedule();

//  Schedule s1(room,Day::Monday,8,9);
//  Schedule s2(room2,Day::Monday,7,9);

//  cout << Schedule::intersect(s1,s2) << endl;
  State s(rooms,courses);
  s.init_random_schedule();

  return 0;
}
