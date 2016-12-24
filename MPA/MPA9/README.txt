MPA9 (I AM, FIRST AND FOREMOST, A STUDENT)
NOTE: This is the same as one of the MPs but instead of using an array implementation of the list, you will implement it as a linked-list. Also, make sure that previously entered data is stored in some file to be retrieved every time the program is re-run.

Create a structure that would represent a student. It should contain the following information:

hyphenated student number
first name
middle name
last name
program
year level
Implement another structure that represent a node that contains a pointer to the next node and its item is a student structure. Then create a list structure to represent a record of students via a linked-list. In our class, we are assuming that a class becomes full when size is 10. 

We should be able to do the following:

enroll a student
withdraw a student from the roll
display all students
search all students based on the year level
search all students based on the course
search all students based on the family name
search a student based on the student number
ALL THESE SHOULD BE IMPLEMENTED AS FUNCTIONS (this means, apart from the main, you should have at least 7 functions)

The first input is the number of operations, say T, to be executed followed T inputs which are a combination of type of input (1-7, refer to the listing above) and the actual input.  The output is based on the input type.  If the input type is 1, 2, or 3, the output is the display of all the students in the record. The output for all other input types is still a display but based only on the search criteria. The input should be read from a file named mpa9.in.

The display should print all the information of a student exactly like the following:

Student Number: 1997-65336
Name: Dulaca, Ryan Ciriaco Madolin
Program: BS Math Computer Science
Year Level: 4

 

If there exists more than one student in the list, separate the display with a blank line exactly like the one below:

Student Number: 1997-65336
Name: Dulaca, Ryan Ciriaco Madolin
Program: BS Math Computer Science
Year Level: 4

Student Number: 2015-55038
Name: Noynay, Danny Boy Anislag
Program: BS Computer Science
Year Level: 1

 

Sample Input File:

3
1
1997-65336
Ryan Ciriaco
Madolin
Dulaca
BS Math Computer Science
4
3
1
2015-55038
Danny Boy
Noynay 
Anislag
BS Computer Science
1

 Output:

Student Number: 1997-65336
Name: Dulaca, Ryan Ciriaco Madolin
Program: BS Math Computer Science
Year Level: 4

Student Number: 1997-65336
Name: Dulaca, Ryan Ciriaco Madolin
Program: BS Math Computer Science
Year Level: 4

Student Number: 1997-65336
Name: Dulaca, Ryan Ciriaco Madolin
Program: BS Math Computer Science
Year Level: 4

Student Number: 2015-55038
Name: Noynay, Danny Boy Anislag
Program: BS Computer Science
Year Level: 1