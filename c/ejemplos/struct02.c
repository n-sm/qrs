/*
Este ejemplo muestra como se usa el '->' en C.
Fuente: Al Kelley, p.411 [217].
 */

#include <stdio.h>
#define CLASS_SIZE 100


typedef struct student {
  char *last_name;
  int student_id;
  char grade;
} student, *STU ;

int fail(student class[])
{
  int i, cnt = 0;

  for (i = 0; i < CLASS_SIZE; ++i) 
    cnt += class[i].grade == 'F';
  return cnt;
}

void printInfo (char* nombre, student* estu)
{
  printf("Datos de %s:\ngrade: %c\nid: %d\napellido: %s\n",
         nombre, estu->grade, estu->student_id,estu->last_name);
}

main()
{

  student tmp, class[CLASS_SIZE];
  tmp.grade = 'A';
  tmp.last_name = "Garcia";
  tmp.student_id = 910017;
  
  STU ptrs = &tmp;
    
  printInfo("tmp",&tmp);
  printInfo("ptrs", ptrs);
}

