#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class hostel
{
private:
    //Encapsulation as these important details are declared in private hence improving Security.
    int room_number;
    char name[50];
    char address[50];
    char phone_number[50];

protected:
    int add_room();
    int display_room();
    int room_sel();
    int menu();
    int check_avail(int);
    int modify_room(int);
    int delete_room(int);
};

class menuclass : public hostel  //Single-level Inheritance
{
public:
    int menu()   //Function Overriding Runtime-Polymorphism as menu() function is also decalred in hostel class.
    {
        system("color 0B");
        int choice = 0;
        while (choice != 5)
        {
            system("cls");
            cout << "\n\t\t\t************************************************************************";
            cout << "\n\t\t\t\t\t\t*MAIN MENU*";
            cout << "\n\t\t\t************************************************************************";
            cout << "\n\n\n\t\t\t1. Press 1 to Book A Room";
            cout << "\n\t\t\t2. Press 2 to Display Student Record";
            cout << "\n\t\t\t3. Press 3 to Check for Room Allocation";
            cout << "\n\t\t\t4. Press 4 to Edit Record";
            cout << "\n\t\t\t5. Press 5 to Exit";
            cout << "\n\t\t\tEnter your Desired Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                add_room();
                break;
            case 2:
                display_room();
                break;
            case 3:
                room_sel();
                break;
            case 4:
                hostel::menu();
                break;
            case 5:
                cout << "\n\n\n\nExiting program";
                break;
            default:
                cout << "\n\n\t\tSorry! Wrong choice.";
                cout << "\n \n";
                system("pause");
                return 0;
            }
        }
    }
};

int hostel::add_room()
{
    system("cls");
    int r, flag;
    ofstream fout("Record.txt", ios::app);  //Write
    cout << "\n ***********************";
    cout << "\n Enter Student Details";
    cout << "\n ***********************";
    cout << "\n\n Room number: ";
    cin >> r;
    flag = check_avail(r);
    if (flag)
    {
        cout << "\n Sorry! Your entered Room is already booked";
    }
    else
    {
        room_number = r;
        cout << "\n Enter your Name: ";
        cin >> name;
        cout << "\n Enter Address: ";
        cin >> address;
        cout << "\n Enter Phone Number: ";
        cin >> phone_number;
        cout << endl;
        fout.write((char *)this, sizeof(*this));
        cout << "\nCongratulations, Room is booked!";
    }
    cout << "\n \n";
    system("pause");
    fout.close();
    return 0;
}

int hostel::display_room()
{
    system("cls");
    ifstream fin("Record.txt", ios::in);   //Read
    int r;
    cout << "\n Enter your Room Number: ";
    cin >> r;
    while (fin.read((char *)this, sizeof(*this)))
    {
        if (room_number == r)
        {
            cout << "\n ******************************";
            cout << "\n Here are the Student Details";
            cout << "\n ******************************";
            cout << "\n\n Room Number: " << room_number;
            cout << "\n Student Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone Number: " << phone_number;
            cout << "\n \n";
            system("pause");
            fin.close();
            return 0;
        }
    }
    cout << "\n Sorry Entered Room number is not found or vacant!";
    cout << "\n \n";
    system("pause");
    fin.close();
    return 0;
}

int hostel::room_sel()
{
    system("cls");
    ifstream fin("Record.txt", ios::in);
    cout << "\n\t\t\t**************************************";
    cout << "\n\t\t\tHere is the List of Allocated Rooms";
    cout << "\n\t\t\t**************************************";
    cout << "\n\n Room Number.\tStudent Name\t\tAddress\t\tPhone Number\n";
    while (fin.read((char *)this, sizeof(*this)))
    {
        cout << "\n\n " << room_number << "\t\t" << name;
        cout << "\t\t\t " << address << "\t\t" << phone_number;
    }
    cout << "\n \n";
    system("pause");
    fin.close();
    return 0;
}

int hostel::menu()
{
    system("cls");
    int choice, r;
    cout << "\n ***********************";
    cout << "\n This is the EDIT MENU";
    cout << "\n ***********************";
    cout << "\n Press 1 to Modify Customer Record";
    cout << "\n Press 2 to Delete Customer Record";
    cout << "\n Enter your desired choice: ";
    cin >> choice;
    cout << "\n Enter room number: ";
    cin >> r;
    switch (choice)
    {
    case 1:
        modify_room(r);
        break;
    case 2:
        delete_room(r);
        break;
    default:
        cout << "\n Sorry! Wrong choice.";
    }
    cout << "\n \n";
    system("pause");
    return 0;
}

int hostel::check_avail(int r)
{
    int flag = 0;
    ifstream fin("Record.txt", ios::in);
    while (fin.read((char *)this, sizeof(*this)))
    {
        if (room_number == r)
        {
            flag = 1;
            break;
        }
    }
    fin.close();
    return flag;
}

int hostel::modify_room(int room_)
{
    system("cls");
    long position;
    fstream file("Record.txt", ios::in | ios::out);
    while (file.read((char *)this, sizeof(*this)))
    {
        position = file.tellg();
        if (room_number == room_)
        {
            cout << "\n *************************";
            cout << "\n Enter the New Details: ";
            cout << "\n *************************";
            cout << "\n Student Name: ";
            cin >> name;
            cout << "\n Address: ";
            cin >> address;
            cout << "\n Phone Number: ";
            cin >> phone_number;
            file.seekp(position - sizeof(*this));
            file.write((char *)this, sizeof(*this));
            cout << "\n Your Record has been modified successfully";
            return 0;
        }
    }
    cout << "\n Sorry Your desired Room Number is not found or vacant!";
    file.close();
    return 0;
}

int hostel::delete_room(int r)
{
    system("cls");
    int flag = 0;
    char ch;
    ifstream fin("Record.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    while (fin.read((char *)this, sizeof(*this)))
    {
        if (room_number == r)
        {
            cout << "\n Student Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone Number: " << phone_number;
            cout << "\n\n Are you sure you want to delete this record (y/n): ";
            cin >> ch;
            if (ch == 'n')
                fout.write((char *)this, sizeof(*this));
            flag = 1;
        }
        else
        {
            fout.write((char *)this, sizeof(*this));
        }
    }
    fin.close();
    fout.close();
    if (flag == 0)
    {
        cout << "\n Sorry your desired room is not found or vacant!";
    }
    else
    {
        remove("Record.txt");
        rename("temp.txt", "Record.txt");
    }
    return 0;
}

int main()
{
    menuclass obj;
    system("color 0A");
    cout << "\n\t\t\t************************************************************************";
    cout << "\n\t\t\t\t\t\t*HOSTEL MANAGEMENT SYSTEM*";
    cout << "\n\t\t\t************************************************************************";
    cout << "\n\n\n\n\n\t\t\t";
    system("pause");
    obj.menu();
    cout << "\n \n";
    system("pause");
    return 0;
    //Abstraction is applied as the logic or implementation is not known to the user.
}
