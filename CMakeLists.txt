cmake_minimum_required(VERSION 3.21)
project(Mini_Blackboard C)

set(CMAKE_C_STANDARD 17)

add_executable(Mini_Blackboard main.c "lib/Mini Blackboard/Course/Course.c" "lib/Mini Blackboard/Course/Course.h" "lib/Mini Blackboard/Person/Person.c" "lib/Mini Blackboard/Person/Person.h" "lib/Mini Blackboard/Person/Teacher/Teacher.c" "lib/Mini Blackboard/Person/Teacher/Teacher.h" "lib/Mini Blackboard/Person/Student/Student.c" "lib/Mini Blackboard/Person/Student/Student.h" "lib/Mini Blackboard/Person/PersonName/PersonName.c" "lib/Mini Blackboard/Person/PersonName/PersonName.h" "lib/Mini Blackboard/Person/Email/Email.c" "lib/Mini Blackboard/Person/Email/Email.h" lib/List/List.c lib/List/List.h)
