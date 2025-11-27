# Week 6 - Pointers and Binary Search

For this week, I completed the Module 7 exercise.  
The goal was to use a struct, dynamic memory, and binary search.

I created a struct called Item that has:
- a string name
- an int id

The program:
- creates a dynamic array of 100 items using `new`
- fills the array with sorted IDs from 1 to 100
- asks the user to enter an ID
- uses binary search to find the item in the array
- prints the name and ID if found
- frees the memory using delete[]

How to compile:
g++ week6.cpp -o week6

How to run:
./week6

Files included:
- week6.cpp
