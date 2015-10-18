#include<stdio.h>
union student{
char letter_grade;
float gpa;

};
int main(){
union student students[10];
students[0].letter_grade = 'A';
students[1].gpa = 3.99;
printf(" student 0 grade is %c\n" 
       " student 1 grade is %01f\n",students[0].letter_grade,students[1].gpa);

}
