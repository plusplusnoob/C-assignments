/************************************************************************************************************
Assignment for Programming in C++
by PlusPlusNoob

Note to first time admin user: Please see admin() at the bottom of the code for it is hidden.
tldr: run program > "5" > "admin" > "pass" > "123" > then create username and password for HR.

Criteria/feature:
A Human Resources user will be able to add, view, search, modify, and delete employees. 
A Management user can only search and view employees. 
A General Employee user can only view his or her own file. 

Note 2: This program was compiled using an online compiler: https://www.onlinegdb.com/online_c++_compiler. 
I'm using a work laptop so I can't install a real IDE.
************************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include <climits> // for INT_MAX limits
using namespace std;
void admin(); //first time user set up
void proc(); //Online compiler can't use system(cls), so I made my own line break for menu readability.
//Employee Functions
void PassChange();
int EmpMenu();
void EmpLogin(); 
//Manager Menu
int MgrMenu();
void MgrLogin();
void MgrReg();
void DisByName();
void DisById();
//Huamn Resources Menu
int HrMenu();
void HrLogin();
void HrReg();
void MainMenuHR();
//Employee Class
class employee
{
    private:
        //Variables for employee details
        char id[5];
        char password[10];
        int age;
        int pay;
        char fname[30];
        char lname[30];
        char uname[30];
//1.List of all employees with First and Last Name, Username, ID and Salary
        void listEmployees()
        { 
            FILE *file;
            file= fopen("Employee.dat", "r");//opens the employee data file
            cout<<"\n\t\t      List of Employees\n";
            cout<<"-----------------------------------------------------------";
            cout<<"\n NAME        | Username       |     ID     |     Salary\n";
            cout<<"-----------------------------------------------------------";
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
            cout<<"\n"<<fname<<" "<<lname<<"\t "<<uname<<"\t\t   "<<id<<"\t\t "<<"$"<<pay;
                fclose(file);//closes the employee data file
        }
//2.Displays all details according to Employee's id
        void showDetails()
        { 
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("Employee.dat", "r");
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
                if(strcmp(checkId,id)==0)
                {
                cout<<"\n---------------------";
                cout<<"\nFirst Name: "<<fname;
                cout<<"\n---------------------";
                cout<<"\nLast Name: "<<lname;
                cout<<"\n---------------------";
                cout<<"\nUsername: "<<uname;
                cout<<"\n---------------------";                    
                cout<<"\nID: "<<id;
                cout<<"\n---------------------";
                cout<<"\nPassword: "<<password;
                cout<<"\n---------------------";
                cout<<"\nAge: "<<age<<" years old";
                cout<<"\n---------------------";
                cout<<"\nSalary: "<<"$"<<pay;
                cout<<"\n---------------------";
                }
            fclose(file);
        }
//Edits Salary of an employee
        void editExisting()
        { 
            int newPay;
            char checkId[5];
            cout<<"\nEnter Employee ID: ";
            cin>>checkId;       //enters ID
            cout<<"------------------------------";
            cout<<"\nEnter New Salary: ";
            cin>>newPay;        //enters newPay
            FILE *file, *tempfile;
            file= fopen("Employee.dat", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
            {
                if(strcmp(checkId, id)==0)//if ID exists
                    fprintf(tempfile, "%s %s %s %s %s %d %d \n", fname, lname, uname, id, password, age, newPay );
                else
                    fprintf(tempfile, "%s %s %s %s %s %d %d \n", fname, lname, uname, id, password, age, pay );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("Employee.dat");
            int isRenamed= rename("temp.txt", "Employee.dat");
        }
//adding records
        void addNewEmployee()
        { 
            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of Employee: ";
            cin>>fname;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Last Name of Employee: ";
            cin>>lname; 
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee's Username: ";
            cin>>uname;            
            cout<<"\n----------------------------------------";
            cout<<"\n Enter 4 Digit Employee ID Number: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Password: ";
            cin>>password;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Salary number: ";
            cin>>pay;
            cout<<"\n----------------------------------------";
            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y' || "Y")
            {
                FILE  *file;
                file= fopen("Employee.dat","a");
                fprintf(file, "%s %s %s %s %s %d %d \n", fname, lname, uname, id, password, age, pay );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
        }
//removing records
        void deleteEmployeeDetails()
        { 
            char checkId[5];
            FILE *file;
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee ID To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            file= fopen("Employee.dat", "r");
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
                if(strcmp(checkId,id)==0)
                {
                	cout<<"\n---------------------";
                    cout<<"\nFirst Name: "<<fname;
                    cout<<"\n---------------------";
                    cout<<"\nLast Name: "<<lname;
                    cout<<"\n---------------------";
                    cout<<"\nUsername: "<<uname;
                    cout<<"\n---------------------";                    
                    cout<<"\nID: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nPassword: "<<password;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age<<" years old";
                    cout<<"\n---------------------";
                    cout<<"\nSalary: "<<"$"<<pay;
                    cout<<"\n---------------------";
                }
            fclose(file);
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'|| "Y")
            {
                FILE *file, *tempfile;
                file= fopen("Employee.dat", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %s %s %d %d \n", fname, lname, uname, id, password, age, pay );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("Employee.dat");
                int isRenamed= rename("temp.txt", "Employee.dat");
                cout<<"\nRemoved Successfully\n";
            }
            else
                deleteEmployeeDetails();
        }
    public:
        // HR Menu Options
        void options()
        { 
            int choice;
            while(1)//the 1 makes the menu loop until a valid choice is made
            {
                // Options to choose an action
                cout<<"\n\t\t\t-=*******  EMPLOYEE MANAGEMENT SYSTEM  *******=-"<<endl;
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View a List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Employee Full Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Salary of Existing Employee";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add a New Employee";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   6:   To Add a New Manager";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   7:   To Add a New Human Resource Personnel";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   8:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";
                // Taking the action input
                cin>>choice;
                while(choice <1|| choice > 8) //only 0-7 are valid choices
            {
            // input validation
            while (cin.fail())
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "Sorry, you've made an invalid selection! Please select using only the numbers 1 through 8.\n\n";
                cout<<"Please enter a selection (1 - 8): ";
                cin >> choice;
            }
                // Calling relevant function as per choice
                switch (choice) 
                {
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    case 6:
                        MgrReg();
                        break;
                    case 7:
                        HrReg();
                        break;
                    case 8:
                        proc();
                        cout<<"Returning to Main Menu..."<<endl;
                       return;                        
                }
            }
        }
};
//Main Menu
int main()
{
  int choice; //declaring choices for the menu
    while(1) //the 1 makes the menu loop until a valid choice is made
    {
    //cout << " 5. Admin Login" << endl;
    cout<<"\n\t\t\t**************************************************";//creates some room to make reading easier for each options     
    cout<<endl<<"\t\t\t\t\tStaff Login Main Menu";
    cout<<"\n\t\t\t**************************************************";
    cout<<"\n\t\t\t 1.Employee Menu";
    cout<<"\n\t\t\t 2.Manager Login";
    cout<<"\n\t\t\t 3.Human Resource Login";
    cout<<"\n\t\t\t 4.Exit\n";
    cout<<"\t\t\tSelection: ";
    cin>>choice;///input from user, selecting their choices
    proc();
while(choice < 1 || choice > 5) //only 1-5 are valid choices; 5 is hidden
        {
        // input validation
        while (cin.fail())
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "Sorry, you've made an invalid selection! Please select using only the numbers 1 through 4.\n\nPlease enter a selection (1 - 4): ";
            cin >> choice;
        }
switch(choice) //switch Functions - what each choice above correlates to.
        {
            case 1:
                EmpLogin();
                break;
            case 2: 
                MgrLogin();
                break;
            case 3:
                HrLogin();
                break;
            case 4:
                cout<<"This program deserves an A";//What other grade does this awesome program deserves? Maybe A++
                exit(0);//exits the program
            case 5: //hidden case
                admin(); 
                break;
        }  
    }
}
//2. Manager level Menu
int MgrMenu()
{  
  int choice; //declaring choices for the menu
    while(1) //the 1 makes the menu loop until a valid choice is made
    {
    cout<< "\t\t\t\t-=*Manager Menu*=-"<<endl;
    cout<<"\t\t\t(1) Search and View Employee by Name "<<endl;
    cout<<"\t\t\t(2) Search and View Employee by ID "<<endl;
    cout<<"\t\t\t(3) Quit\n\n"; //3 options
    cout<< "\t\t\tEnter a number that corresponds to your choice > ";
    cin>>choice;///input from user, selecting their choices
    proc();
    while(choice < 1 || choice > 3) 
        {
        // input validation
        while (cin.fail())
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "Sorry, you've made an invalid selection! Please select using only the numbers 1 through 3.\n\nPlease enter a selection (1 - 3): ";
            cin >> choice;
        }
switch(choice) //switch Functions - what each choice above correlates to.
        {
          case 1:
            DisByName();
            break;
          case 2:
            DisById();
            break;
          case 3: 
            proc();
            main();
            break;
        }
    }
}
//Manager login >> DisByName,
void MgrLogin()
{
        char pass[10];
        char uname[30];
            FILE *file;
            char name[30];
            char des[10];
            file= fopen("Manager.txt", "r");
            cout<<"\n\nEnter Manager Username: ";
            cin>>name;
            while(fscanf(file, "%s %s ", &uname[0], &pass[0])!= EOF)
                    if(strcmp(name,uname)==0)
                    fclose(file);
    {
            cout<<"Enter Password: ";
            cin>>des;
            proc();
                if(strcmp(des,pass)==0) 
                {
                    MgrMenu();
                }
        else
        {
            cout<<"\nLOGIN ERROR\n\nPlease check your username and password\n";
            main();
        }
    }
}
//Manager Registeration
void MgrReg()
{
        char uname[30];
        char pass[10];
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Manager Username: ";
            cin>>uname;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Desired Password: ";
            cin>>pass; 
            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y' || "Y")
            {
                FILE  *file;
                file= fopen("Manager.txt","a");
                fprintf(file, "%s %s \n", uname, pass);
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                MgrReg();
}
//Displays all details according to Employee's first name from MgrMenu
void DisByName() 
{
        char id[5];
        char password[10];
        int age;
        int pay;
        char fname[30];
        char lname[30];
        char uname[30];
            FILE *file;
            char name[30];
            cout<<"\n\nEnter Employee First Name: ";
            cin>>name;
            file= fopen("Employee.dat", "r");
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
                if(strcmp(name,fname)==0)
                {
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<fname<<" "<<lname;
                    cout<<"\n---------------------";
                    cout<<"\nID: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age<<" "<<"years old";
                    cout<<"\n---------------------";
                    cout<<"\nSalary: "<<"$"<<pay;
                    cout<<"\n---------------------"<<endl;
                    cout<<"\n*********************"<<endl;
                }
                fclose(file);
}
//Displays all details according to Employee's ID from MgrMenu
void DisById() 
{
        char id[5];
        char password[10];
        int age;
        int pay;
        char fname[30];
        char lname[30];
        char uname[30];
            FILE *file;
            char checkID[5];
            cout<<"\n\nEnter Employee ID Number: ";
            cin>>checkID;
            file= fopen("Employee.dat", "r");
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
                if(strcmp(checkID,id)==0)
                {
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<fname<<" "<<lname;
                    cout<<"\n---------------------";
                    cout<<"\nID: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age<<" "<<"years old";
                    cout<<"\n---------------------";
                    cout<<"\nSalary: "<<"$"<<pay;
                    cout<<"\n---------------------"<<endl;
                    cout<<"\n*********************"<<endl;
                }
                fclose(file);
}
//Displays all details according to Employee's id
 void EmpLogin() 
{
        char id[5];
        char password[10];
        int age;
        int pay;
        char fname[30];
        char lname[30];
        char uname[30];
            char pass[10];
            char name[30];
            FILE *file;
            file= fopen("Employee.dat", "r");
            cout<<"\n\nEnter Employee Username: ";
            cin>>name;
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
                    if(strcmp(name,uname)==0)
                    fclose(file);
    {
            cout<<"Enter Password: ";
            cin>>pass;
            proc();
                if(strcmp(pass,password)==0) 
                {
                    proc();
                    cout<< "\n-=*"<<fname<<"'s "<<" Information*=-";
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<fname<<" "<<lname;
                    cout<<"\n---------------------";
                    cout<<"\nID: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nUsername: "<<uname;
                    cout<<"\n---------------------";
                    cout<<"\npassword: "<<password;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age<<" years old";
                    cout<<"\n---------------------";
                    cout<<"\nSalary: "<<"$"<<pay;
                    cout<<"\n---------------------"<<endl;
                    cout<< "\n\n\t\t\t\t\t-=*"<<fname<<" "<<lname<<"'s"<<" Menu*=-";
                    EmpMenu();
                }
        else
        {
            cout<<"\nLOGIN ERROR\n\nPlease check your username and password\n";
            main();
        }
        fclose(file);
    }
}
// change password
void PassChange()
{
    char id[5];
    char password[10];
    int age;
    int pay;
    char fname[30];
    char lname[30];
    char uname[30];
    char OldPass[10];
        cout<<"\nEnter current password: ";
        cin>>OldPass;
        char newPassword[10];
        cout<<"\n-----------------------------";
        cout<<"\nEnter new password: ";
        cin>>newPassword;
            FILE *file, *tempfile;
            file= fopen("Employee.dat", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %s %d %d ", &fname[0], &lname[0], &uname[0], &id[0], &password[0], &age, &pay )!= EOF)
            if(strcmp(OldPass, password)==0)
            {
            proc();
            cout<<endl<<"Password changed successfully"<<endl;
            fprintf(tempfile, "%s %s %s %s %s %d %d \n", fname, lname, uname, id, newPassword, age, pay );
            }
            else
            {
            fprintf(tempfile, "%s %s %s %s %s %d %d \n", fname, lname, uname, id, password, age, pay );
            }
           fclose(file);
            fclose(tempfile);
            int isRemoved= remove("Employee.dat");
            int isRenamed= rename("temp.txt", "Employee.dat");
                cout<< "\n\n\t\t\t\t\t-=*"<<fname<<" "<<lname<<"'s"<<" Menu*=-";
}
//3. General Employee Menu EmpLogin << EmpMenu >> EmpLogin, passchange, 
int EmpMenu()
{   
  int choice; //declaring choices for the menu
    while(1) //the 1 makes the menu loop until a valid choice is made
    {
    cout<< "\n\t\t\t(1) Employee details";
    cout<< "\n\t\t\t(2) Change Password";
    cout<< "\n\t\t\t(3) Quit\n"; //3 options
    cout<< "\n\t\t\tEnter a number that corresponds to your choice > ";
    cin>>choice;///input from user, selecting their choices
    proc();
        while(choice < 1 || choice > 3) 
        {
        // input validation
        while (cin.fail())
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "Sorry, you've made an invalid selection! Please select using only the numbers 1 through 3.\n\nPlease enter a selection (1 - 3): ";
            cin >> choice;
        }
        switch(choice) //switch Functions - what each choice above correlates to.
        {
        case 1:
            EmpLogin();
            break;
        case 2: 
            PassChange();
            break;
        case 3:
            proc();
             main();
             break;
        }
    }
}
//HR Login from main option 3.
void HrLogin()
{
        char pass[10];
        char uname[30];
            FILE *file;
            char name[30];
            char des[10];
            file= fopen("HumanResources.txt", "r");
            cout<<"\n\nEnter Username: ";
            cin>>name;
            while(fscanf(file, "%s %s ", &uname[0], &pass[0])!= EOF)
                    if(strcmp(name,uname)==0)
                    fclose(file);
    {
            cout<<"Enter Password: ";
            cin>>des;
            proc();
                if(strcmp(des,pass)==0) 
                {
                MainMenuHR();
                }
        else
        {
        cout<<"\nLOGIN ERROR\n\nPlease check your username and password\n";
            main();
        }
    }
}
//Main Menu after HR logins
void MainMenuHR()
{
    employee e;
    e.options();
}
//Human Resources Registeration from HrMenu
void HrReg()
    { 
        char uname[30];
        char pass[10];
            cout<<"\n----------------------------------------";
            cout<<"\n Enter HR Username: ";
            cin>>uname;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Desired Password: ";
            cin>>pass; 
            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y' || "Y")
            {
                FILE  *file;
                file= fopen("HumanResources.txt","a");
                fprintf(file, "%s %s \n", uname, pass);
                fclose(file);
                cout<<"\nNew Human Resource Personnel has been added to database\n";
            }
            else
                HrReg();
    }
//proc() test
void proc()
{
    cout<<"Processing..."<<endl<<endl;
}
//admin login
void admin()
{
    string name2, pass2, key2;
    string name = "admin";
    string pass = "pass";
    string key = "123";
    cout<<"Credentials: ";
    cin>>name2;
    cout<<"Authentications: ";
    cin>>pass2;
    cout<<"Key: ";
    cin>>key2;
    if(name == name2 && pass == pass2 && key == key2)
    {
        HrReg();
    }
        else
    {
        cout<<"\nProcessing..."<<endl;
        cout<<"\n\t\t\tAuthentication Denied"<<endl;
        cout<<"\t\t\tTerminating Program"<<endl;
        exit(0);//exits the program
    }
}
