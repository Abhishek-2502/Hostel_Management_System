# Hostel-Management-System
Hostel Management system addresses the common issue of Allocation faced by hostels for initial allocation of students. It uses a menu driven program to systematically help in the process by using conceot of OOPs in C++.
# Problem Statement:
In a college or university, it's common to have a hostel or dormitory where students live during their
academic years. Managing the accommodation for a large number of students efficiently can be
challenging. The Hostel Accommodation Management System is designed to address this problem by
providing a software solution to manage student accommodations within a college hostel. It uses the concepts of OOPS in C++.
It makes use of concepts like inheritance, polymorphism, abstraction and encapsulation.
Here’s the description of the problem it solves:<br />
● Student Allocation<br />
● Student Removal and Modification<br />
● Displaying Student Details<br />
● User Interface<br />
# Explanation:
The Hostel Accommodation Management System is designed to manage student accommodations
efficiently. It allows students to be added, modify their details, and later removing students from
their allocated rooms if necessary. The system distinguishes between students, keeping track of their name,
address and phone number. It simplifies the management of hostel accommodations, ensuring efficient allocation and tracking of resources using file handling.
The Hostel Accommodation Management System provides a software solution for managing student
accommodations efficiently. It includes the following components:<br />
This C++ program is a basic Hostel Management System. It consists of a class hostel that manages room bookings and student records.
Here's a concise breakdown:<br />
● Classes:<br />
1.There are two classes defined - hostel and menuclass.<br />
2.hostel contains private data members (room_number, name, address, and phone_number) along with several protected member functions for various operations.<br />
● Inheritance:<br />
1.menuclass is derived from hostel using single-level inheritance.<br />
2.menuclass overrides the menu() function from the base class (hostel), providing a custom menu interface.<br />
● Menu Interface:<br />
1.The program presents a menu to the user with options like booking a room, displaying student records, checking room allocation, editing records, and exiting the program.<br />
● File Operations:<br />
1.The program uses file operations to store and retrieve student records. It writes records to a file named "Record.txt" and reads from it when needed.<br />
● Room Management:<br />
1.Functions like add_room(), display_room(), and room_sel() allow the user to perform operations related to booking and displaying rooms.<br />
● Record Modification:<br />
1.Functions like modify_room() and delete_room() enable the user to edit or delete existing student records.<br />
● User Interface:<br />
1.The program uses console-based user interfaces, with various prompts and messages for user interaction.<br />
● Abstraction:<br />
1.The implementation details are hidden from the user, providing an abstract view of the hostel management operations.<br />
● System Commands:<br />
1.The program uses system commands to clear the console screen and set the console color.<br />
# Class Diagram: <br >
<img src="https://github.com/ayushimahajan295/Hostel-Management-System/assets/145414094/fc060f2e-d827-4185-bcdd-59d4fb55998b" alt="error">
