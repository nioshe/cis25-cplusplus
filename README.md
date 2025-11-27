# Week 6 - Strings and Classes

For this week, I created a C++ program that uses a class and file I/O.

I made a class called Item. It has:
- a string for the item name
- an int for the quantity

The class includes two functions:
- saveToFile() → saves the item data into a file called items.txt
- loadFromFile() → reads the data from the file and prints it

In the main function:
- I created an Item object
- I set the name to "Screwdriver" and the quantity to 10
- I saved the data to the file
- Then I loaded the file and showed the content

How to compile and run:
1. Compile:
   g++ week6.cpp -o week6
2. Run:
   ./week6

Files included this week:
- week6.cpp
- items.txt (this file is created automatically when the program runs)
