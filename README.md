
link:-https://onlinegdb.com/xX_r44dTE


Library Management System (C++)
OOP Project
Project Overview

This project is a console-based Library Management System developed in C++ using Object-Oriented Programming (OOP) concepts. It allows users to add books and DVDs, display items, search by title, check out items, and return items.

The project demonstrates:

Classes and Objects

Inheritance

Abstract Class

Pure Virtual Functions

Polymorphism

Encapsulation (Getters/Setters)

Exception Handling

Dynamic Memory Allocation

Array of Base Class Pointers

Features

Add Book

Add DVD

Display All Items

Search Item by Title

Check Out Item

Return Item

Exception Handling for Invalid Inputs

Technologies Used

Technology

	

Purpose




C++

	

Programming Language




OOP Concepts

	

Project Structure




Exception Handling

	

Error Management

Class Structure
LibraryItem (Abstract Base Class)

Attributes:

title

author

dueDate

Functions:

checkOut() (pure virtual)

returnItem() (pure virtual)

displayDetails() (pure virtual)

Getters and Setters

Book Class

Additional Attributes:

isbn

isCheckedOut

DVD Class

Additional Attributes:

duration

isCheckedOut

Menu Options
Program Menu

==== Library Management System ====

Add Book

Add DVD

Display All Items

Search Item by Title

Check Out Item

Return Item

Exit

How to Compile & Run
Compile

Using g++:

g++ library.cpp -o library

Run

./library

Sample Output
Console Example

==== Library Management System ====

Add Book

Add DVD

Display All Items

Search Item by Title

Check Out Item

Return Item

Exit

Enter your choice: 1

Enter Title: C++ Programming

Enter Author: Bjarne Stroustrup

Enter Due Date: 10-07-2026

Enter ISBN: 123456789

Book added successfully!

Concepts Used
OOP Concepts

Concept

	

Used?




Class & Object

	

Yes




Inheritance

	

Yes




Polymorphism	

Yes


Abstraction


Yes

Encapsulation


Yes

Exception Handling

Yes

Project Files

library.cpp

Main source code file

README.md

Project documentation
Conclusion

This project is a simple but effective implementation of a Library Management System using C++ OOP principles. It demonstrates how inheritance, abstraction, and polymorphism can be used to manage different types of library items efficiently.
