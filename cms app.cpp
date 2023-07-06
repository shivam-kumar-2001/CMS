#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
using namespace std;
char un[20];

class Admin
{

    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[15], mail[50], fname[20];
    char passwd[20], rpasswd[20];

public:
    char rollno[15];
    void getstdata() // this function used to get student data entry from the admin portal...
    {

        cout << "\nEnter the Student Name : ";
        while (!getchar());
        gets(name);
        cout << "\nEnter the Student ID/Roll No. : ";
        cin >> rollno;
        cout << "\nEnter the Student Father's Name : ";
        while (!getchar());
        gets(fname);
        cout << "\nEnter the Mobile Number : ";
        while (!getchar());
        gets(mobile);
        cout << "\nEnter the E-Mail Id : ";
        while (!getchar());
        gets(mail);
        cout << "\nEnter the Total Subject : ";
        cin >> totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout << "\nEnter the Subject " << i + 1 << " Name : ";
            cin >> subject[i];
        }
        while (!getchar());
        cout << "\nCreate your login password : ";
        cin >> passwd;
        cout << "\nEnter the Uniqwe KeyWord to Recover Password : ";
        cin >> rpasswd;
        cout << "\n\nPlease note your UserName is ID/Roll no.\n";
        system("cls");

    }

    int login() // this function aunthenticates the login of both the students & faculties with their unique Id/Password.
    {
        if (strcmp(::un, rollno) == 0)
        {
            cout << "\nEnter the login password : ";
            int len = 0, i = 0;
            len = strlen(passwd);
            char inputpasswd[20];
            for (i = 0; i < len; i++)
            {
                inputpasswd[i] = getch();
                cout << "#";
            }
            inputpasswd[i] == NULL;
            //cout<<"\nThe Entered password is "<<inputpasswd;
            if ((strcmp(::un, rollno) == 0) && (strcmp(passwd, inputpasswd) == 0))
            {
                return 1;
            }
        }
        return 0;
    }

    int recovery()  // this function help to recover the password with help of unique keyword
    {
        // cout<<"\n the input Username is "<<::un;
        char key[20];
        if (strcmp(::un, rollno) == 0)
        {
            cout << "\nEnter the Unique KeyWord(Provided by admin) : ";
            cin >> key;
            if ((strcmp(key, rpasswd) == 0))
            {
                cout << "\nYou are a valid user." ;
                cout << "\nYour password is " << passwd;
                cout << "\nPlease Exit To Login Again ";
                return 1;
            }

        }
        return 0;
    }

    int faprofile() // this function display profile to the faculty at their portals.
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\nFaculty Name                 :" << name;
            cout << "\nFaculty Father's Name        :" << fname;
            cout << "\nFaculty Mobile No.             :" << mobile;
            cout << "\nFalculty E-Mail ID             :" << mail;
            return 1;
        }
        return 0;
    }

    int knowfasub()  // this function display the diffrent subject of the faculty at thier portals
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\nFaculty total subject :- " << totsub;
            for (int i = 0; i < totsub; i++)
            {
                cout << "\n\tsubject " << i + 1 << " : " << subject[i];
            }
            return 1;
        }
        return 0;
    }

    void addfasub() // this function help to add a subject in their faculty's module.
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\nEnter the New subject : ";
            cin >> subject[totsub];
            totsub++;
            cout << "\n\nNew Aubject Added Successfully...";
        }
    }

    void delfasub()
    {
        knowfasub();
        int de = 0;
        if ((strcmp(::un, rollno) == 0))
        {
            if (totsub == 0 || totsub < 0)
            {
                totsub = 0;
                cout << "\nNone Subject Exits...";
                exit(0);
            }
            cout << "\nEnter the Subject No. to be deleted : ";
            cin >> de;
            if (de == totsub)
            {
                totsub--;
                strcpy(subject[totsub], " ");
            }
            else if (totsub == 1)
            {
                totsub = 0;
                strcpy(subject[totsub], " ");
            }
            else
            {
                de--;
                strcpy(subject[totsub], " ");
                for (int p = de; p < totsub; p++)
                {
                    strcpy(subject[p], subject[p + 1]);
                }
                totsub--;
            }
            cout << "\n Record Updated Successfuly...";
        }
    }

    void modfaprofile() // this function helps a faculty to modify his personal profile.
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\n The profile Details are : ";
            cout << "\n 1. Faculty E-Mail : " << mail;
            cout << "\n 2. Faculty Mobile : " << mobile;
            int g = -1;
            cout << "\n\n Enter the Details No. to be Modified : ";
            cin >> g;
            if (g == 1)
            {
                char nmail[50];
                cout << "\n Enter the new E-Mail : ";
                while (!getchar());
                gets(nmail);
                strcpy(mail, nmail);
                cout << "\nRecord Updated Successfuly....";
            }
            else if (g == 2)
            {
                char nmobile[15];
                cout << "\nEnter the new Mobile No. : ";
                while (!getchar());
                gets(nmobile);
                strcpy(mobile, nmobile);
                cout << "\nRecord Updated Successfuly....";
            }
            else
            {
                cout << "\nInvalid Input Provided....";
            }
        }
    }

    int stprofile() // this function displays the student profile at student protal
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\nStudent Name               :" << name;
            cout << "\nStudent Father's Name      :" << fname;
            cout << "\nStudent Mobile No.         :" << mobile;
            cout << "\nStudent E-Mail ID          :" << mail;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int knowstsub() //this function display the diffrent enrolled subject of the respective student...accoding to their profile.
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\nStudent Total Subject :- " << totsub;
            for (int i = 0; i < totsub; i++) {
                cout << "\n\tSubject " << i + 1 << " : " << subject[i];
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void addstsub() // this function allow the student to add subject in total subject of the student profile...
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\n Enter the new subject : ";
            cin >> subject[totsub];
            totsub++;
            cout << "\n\n New Subject Added Successfully....";
        }
    }

    void delstsub() // this function allows the student to delete a subject in total subject of student portal...
    {
        knowstsub();
        int de = 0;
        if ((strcmp(::un, rollno) == 0))
        {
            if (totsub == 0 || totsub < 0)
            {
                totsub = 0;
                cout << "\nNone Subject Exits...";
                getch();
                exit(0);
            }
            cout << "\n Enter the Subject No. to be Deleted : ";
            cin >> de;
            if (de == totsub)
            {
                totsub--;
                strcpy(subject[totsub], " ");
            }
            else if (totsub == 1)
            {
                totsub = 0;
                strcpy(subject[totsub], " ");
            }
            else
            {
                de--;
                strcpy(subject[totsub], " ");
                for (int p = de; p < totsub; p++)
                {
                    strcpy(subject[p], subject[p + 1]);
                }
                totsub--;
            }
            cout << "\n Record Updated Successfuly...";
        }
    }

    void modstprofile() // this funtion allows the student to modify their personal profile details at the student portal...
    {
        if ((strcmp(::un, rollno) == 0))
        {
            cout << "\nThe profile Details are : ";
            cout << "\n 1. Student E-Mail : " << mail;
            cout << "\n 2. Student Mobile : " << mobile;
            cout << "\n Enter Your Choice : ";
            int g;
            cin >> g;
            if (g == 1)
            {
                char nmail[50];
                cout << "\n Enter the new E-Mail : ";
                while (!getchar());
                gets(nmail);
                strcpy(mail, nmail);
                cout << "\nRecord Updated Successfuly....";
            }
            else if (g == 2)
            {
                char nmobile[15];
                cout << "\nEnter the new Mobile No. : ";
                while (!getchar());
                gets(nmobile);
                strcpy(mobile, nmobile);
                cout << "\nRecord Updated Successfuly....";
            }
            else
            {
                cout << "\nInvalid Input Provided....";
            }
        }
    }

    void getfadata() // this function allow the admin to make new Record Entry for the diffrent new faculties..
    {

        cout << "\nEnter the Falculty Name : ";
        while (!getchar());
        gets(name);
        cout << "\nEnter the Falculty ID/Roll no. : ";
        cin >> rollno;
        cout << "\nEnter the Falculty Father's Name : ";
        while (!getchar());
        gets(fname);
        cout << "\nEnter the Mobile No. : ";
        while (!getchar());
        gets(mobile);
        cout << "\nEnter the E-Mail Id : ";
        while (!getchar());
        gets(mail);
        cout << "\nEnter the Total Subject : ";
        cin >> totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout << "\nEnter the Subject " << i + 1 << " Name : ";
            cin >> subject[i];
        }
        while (!getchar());
        cout << "\nCreate your Login Password : ";
        cin >> passwd;
        cout << "\nEnter the Unique Keyword to recovery Password : ";
        cin >> rpasswd;
        cout << "\n\nPlease note Your UserName is ID/Roll no.\n";
        system("cls");
    }


    void stdisplay() // this function displays all the relevant information to the admin related to the Students at the ADMIN portals
    {
        if (name[0] <= 0)
        {
            cout << "No data .... " << "\n";
            return;
        }
        cout << "Student Details : ";
        cout << "\nStudent Name               : " << name;
        cout << "\nStudent ID/Roll No.        : " << rollno;
        cout << "\nStudent Father's Name      : " << fname;
        cout << "\nStudent Mobile No.         : " << mobile;
        cout << "\nStudent E-Mail ID          : " << mail;
        cout << "\nStudent Subjects           : " << totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout << "\n   Subject  " << i + 1 << " : " << subject[i];
        }
        if (totsub == 0)
        {
            cout << "(None Subject Specified....)";
        } cout << "\n\n";
    }

    void fadisplay() // this function display all the relevant information to the admin related to the faculty at the admin portals..
    {
        if (name[0] <= 0)
        {
            cout << "No data ..... " << "\n";
            return;
        }
        cout << "\n Faculty Name              : " << name[0];
        cout << "\n Faculty ID/Roll No.       : " << rollno;
        cout << "\n Faculty Father's Name     : " << fname;
        cout << "\n Faculty Mobile No.        : " << mobile;
        cout << "\n Faculty E-Mail ID         : " << mail;
        cout << "\n Faculty Subject           : " << totsub;
        for (int i = 0; i < totsub; i++) {
            cout << "\n   Subject  " << i + 1 << " : " << subject[i];
        }
        if (totsub == 0)
        {
            cout << "(None Subject Specified....)";
        }
        cout << "\n\n";
    }

} a;
Admin f;   // a & f are the objects of the Admin class...

int main()
{
    int ch;
    // clrscr();
    system("cls");
    cout << "\n\n\n\t\t\tWelecome to RKGIT Database Portal ";
    cout << "\n\n\n\t\t\t\tEnter to Continue ";
    getch();
    // clrscr();
    system("cls");
    cout << "\n\n\n\t\t\tPress 1 for admin protal";
    cout << "\n\t\t\tPress 2 for Faculty portal";
    cout << "\n\t\t\tPress 3 for Student Portal";
    cout << "\n\n\t\t\tEnter your Choice : ";
    cin >> ch;
    // clrscr();
    system("cls");
    if (ch == 1)
    {
        char adminuser[20], adminpass[20];
        cout << "\n\t\t\tWelcome To Admin Login Portal ";
        cout << "\n\nEnter the UserName : ";
        cin >> adminuser;
        cout << "\nEnter the 8- digit Password : ";
        int k = 0;
        for ( k = 0; k < 1; k++)
        {
            adminpass[k] = getch();
            cout << "*";
        }
        getch();
        adminpass[k] = NULL;
        if ((strcmp(adminuser, "a") == 0) && (strcmp(adminpass, "1") == 0))
        {
            // clrscr();  // clear screen
            system("cls");
        }
        else
        {
            cout << "\n\n\t\t\t  Invalid Access to Portal ";
            cout << "\n\n\t\t\t\t Thank You  !!!!";
            getch();
            exit(0);
        }

        char opera = 'y';
        do {
            int tmp;
            system("cls");
            cout << "\n\t\t\t\tWelcome TO Admin Protal ";
            cout << "\n\tPress 1 to Add a Faculty Record ";
            cout << "\n\tPress 2 to Add Multiple Record Of Faculty ";
            cout << "\n\tpress 3 to view All Record Of Faculty ";
            cout << "\n\tpress 4 to Delete a Faculty Record ";
            cout << "\n\tpress 5 to Add a Student Record ";
            cout << "\n\tpress 6 to Add Multiple Record of Students ";
            cout << "\n\tpress 7 to view All Record Of Students ";
            cout << "\n\tpress 8 to Delete a Student Record ";
            cout << "\n\tpress 9 to Exit. ";
            cout << "\n\n\t\tEnter Your Choice : ";
            cin >> tmp;
            // clrscr();
            system("cls");
            if (tmp == 1) // for inserting a single faculty record
            {
                cout << "\nEnter the details :- ";
                fstream fs;
                fs.open("fainfo.txt", ios::in | ios::out | ios::ate);
                a.getfadata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                system("cls");
                cout << "\nRecord Entered Successfully....";
                cout << "\nPrsss any Key .... ";
            }
            if (tmp == 2) // for inserting multiple faculty records
            {
                int m = 0;
                fstream fs;
                fs.open("fainfo.txt", ios::in | ios::out | ios::ate);
                do
                {
                    while (!getchar());
                    cout << "\nEnter the Details :- ";
                    a.getfadata();
                    fs.write((char *)&a, sizeof(Admin));
                    cout << "press 0 if you want to enter More Records otherwise 1 : ";
                    cin >> m;
                } while (m == 0);
                fs.close();
                cout << "\nRecord Entered Successfully....";
                cout << "\nPress Enter .... ";
            }
            if (tmp == 3) // for view all faculty record...
            {
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fs.seekg(0);
                int k = 1;
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    cout << k << '.';
                    a.fadisplay();
                    cout << "\n";
                    k++;
                }
                fs.close();
                cout << "Press Enter .......";
            }

            if (tmp == 4) // for deleting a faculty record
            {
                char tmpfaid[15];
                int de = 0, result = -1;
                cout << "\nEnter the Faculty ID/rollno. :- ";
                cin >> tmpfaid;
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fstream fs1;
                fs1.open("fanewinfo.txt", ios::out | ios::ate);
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    result = strcmp(tmpfaid, a.rollno);
                    if (result == 0)
                    {
                        de = 1;
                    }
                    else
                    {
                        fs1.write((char *)&a, sizeof(Admin));
                    }
                }
                if (de == 1)
                {
                    cout << "\nRecord Deleted Successfully....";
                }
                else
                {
                    cout << "\nRecord not Found....";
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("fanewinfo.txt", "fainfo.txt");
            }
            if (tmp == 5) // for single student record input...
            {
                cout << "\nEnter the Details :- ";
                fstream fs;
                fs.open("stinfo.txt", ios::in | ios::out | ios::ate);
                a.getstdata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                cout << "\nRecord Entered Successfully ....";
            }
            if (tmp == 6) // for multiple student record input...
            {
                int m = 0;
                fstream fs;
                fs.open("stinfo.txt", ios::in | ios::out | ios::ate);
                do
                {
                    cout << "\nEnter the Details :- ";
                    a.getstdata();
                    fs.write((char *)&a, sizeof(Admin));
                    cout << "press 0 if you want to Enter More Records : ";
                    cin >> m;
                } while (m == 0);
                fs.close();
                cout << "\nRecord Entered Successfully....";
            }
            if (tmp == 7) // for view of all student record
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);
                int k = 1;
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    cout << k << ". ";
                    a.stdisplay();
                    k++;
                }
                fs.close();
            }

            if (tmp == 8) // for deleting a student record...
            {
                char tmpstid[15];
                int de = 0, result = -1;
                cout << "\nEnter the Student ID/Rollno. :- ";
                cin >> tmpstid;
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt", ios::out | ios::ate);
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    result = strcmp(tmpstid, a.rollno);
                    if (result == 0)
                    {
                        de = 1;
                    }
                    else {
                        fs1.write((char *)&a, sizeof(Admin));
                    }
                }
                if (de == 1)
                {
                    cout << "\nRecord Deleted Successfully....";
                }
                else
                {
                    cout << "\nRecord not found....";
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt", "stinfo.txt");
            }

            if (tmp == 9) // for exit
            {
                cout << "\n\n\n\n\t\t\t\tThank YOU !!!!";
                getch();
                exit(0);
            }

            if (tmp < 1 || tmp > 9) // for invalid choice
            {
                // clrscr();
                system("cls");
                cout << "\n\n\n\t\t\t\tInvalid Input .....";
            }
            getch();
            cout << "\n\nPress y : for more opearatios otherwise n : ";
            cin >> opera;
            if (opera != 'y')
            {
                getch();
                // clrscr();
                system("cls");
                cout << "\n\n\n\n\t\t\t\tThank You !!!!";
                getch();
            }

        } while (opera == 'Y' || opera == 'y');

    } // closing of admin login

    if (ch == 2) // begin of faculty view portal
    {
        // clrscr();
        system("cls");
        // char un[20];
        int val, s = 0;
        cout << "\n\t\t\tWelcome to Faculty Login page ";
        cout << "\n\nEnter the UserName : ";
        cin >>::un;
        fstream fs;
        fs.open("fainfo.txt", ios::in | ios::binary);
        fs.seekg(0);
        while (!fs.eof())
        {
            val = -1;
            fs.read((char *)&f, sizeof(Admin));
            val = f.login();
            if (val == 1)
            {
                s = 1;
                break;
            }
        }
        fs.close();
        if (s == 1) // if first login is valid
        {
            // clrscr();
            system("cls");
        }
        if (s != 1) // if first login is Invalid then
        {
            // clrscr();
            system("cls");
            int ho = 0;
            cout << "\n\n\t\tYour Login Credentials are In-correct ";
            cout << "\nThe UserName is Your ID/Rollno. ";
            cout << "\nThe Password is Case-Sensetive. ";
            cout << "\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
            cout << "\nEnter the Choice : ";
            cin >> ho;
            if (ho == 1) // recover password
            {
                cout << "Enter the UserName :- ";
                cin >>::un;
                fstream fs;
                fs.open("fainfo.txt", ios::in | ios::binary);
                fs.seekg(0);
                int re, su = -1;
                while (!fs.eof())
                {
                    re = -1;
                    fs.read((char *)&f, sizeof(Admin));
                    re = f.recovery();
                    if (re == 1)
                    {
                        su = -1;
                        break;
                    }
                }
                fs.close();
                if (su == 1)
                {
                    getch();
                    // clrscr();
                    system("cls");
                    cout << "\n\n\n\n\t\t\tThank You !!!! ";
                    getch();
                    exit(0);
                }
                else
                {
                    cout << "\nYou are a Invalid User. ";
                    getch();
                    exit(0);
                }
            }
            if (ho == 2) // re-attemp of login
            {
                cout << "\n\nEnter the UserName : ";
                cin >>::un;
                fstream fs;
                fs.open("fainfo.txt", ios::in | ios::binary);
                fs.seekg(0);
                int suc = -1, valu; // value for storing login() returned value suc for sucess login.

                while (!fs.eof())
                {
                    valu = -1;
                    fs.read((char *)&f, sizeof(Admin));
                    valu = f.login();
                    if (valu == 1)
                    {
                        suc = 1;
                        break;
                    }
                }
                fs.close();
                if (suc == 1)
                {
                    // clrscr();
                    system("cls");
                }
                else
                {
                    getch();
                    cout << "\nYou are an Invalid User ....";
                    cout << "\nThank You !!!!";
                    getch();
                    exit(0);
                    exit(0);
                }
            }
            if (ho != 1 && ho != 2)
            {
                cout << "\n\nInvalid Input Provided. ";
                cout << "\n\n\t\t\tThank You  !!!! ";
                getch();
                exit(0);
            }
        }

        char con = 'y';
        do
        {
            // clrscr();
            system("cls");
            cout << "\n\n\t\t\tWelcome to Faculty pannel  ";
            cout << "\n\n\t\t\t\t\t\t    your UserID is : " <<::un;
            cout << "\n\nPress 1 to view Your Profile.";
            cout << "\npress 2 to Know Your Subject.";
            cout << "\nPress 3 to Add a Subject.";
            cout << "\nPress 4 to Delete a Subject.";
            cout << "\nPress 5 to Modify your Profile.";
            int choice;
            cout << "\n\nEnter Your Choice : ";
            cin >> choice;
            if (choice == 1)
            {
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fs.seekg(0);
                int x;
                while (!fs.eof())
                {
                    x = 0;
                    fs.read((char *)&f, sizeof(Admin));
                    x = f.faprofile();
                    if (x == 1)
                    {
                        break;
                    }
                }
                fs.close();
            } // closing of choice = 1
            if (choice == 2)
            {
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fs.seekg(0);
                int y = 0;
                while (!fs.eof())
                {

                    fs.read((char *)&f, sizeof(Admin));
                    int y = f.knowfasub();
                    if (y == 1)
                    {
                        break;
                    }
                }
                fs.close();
            } // closing of choice = 2
            if (choice == 3)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt", ios::in | ios::binary);
                fs1.open("tmpfainfo.txt", ios::out | ios::ate);
                fs.seekg(0);
                while (!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.addfasub();
                    fs1.write((char *)&f, sizeof(Admin));
                    break;
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("tmpfainfo.txt", "fainfo.txt");
            }// closing of choice = 3
            if (choice == 4)
            {
                fstream fs;
                fs.open("fainfo.txt", ios::in | ios::binary);
                fstream fs1;
                fs1.open("delfainfo.txt", ios::out | ios::ate);
                fs.seekg(0);
                while (!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.delfasub();
                    fs1.write((char *)&f, sizeof(Admin));
                    break;
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("delfainfo.txt", "fainfo.txt");
            }
            if (choice == 5)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt", ios::in | ios::binary);
                fs.seekg(0);
                fs1.open("modfainfo.txt", ios::out | ios::ate);
                while (!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.modfaprofile();
                    fs1.write((char *)&f, sizeof(Admin));
                    break;
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("modfainfo.txt", "fainfo.txt");
            }
            if (choice < 1 || choice > 5)
            {
                cout << "\nIvalid Input Provided  !!!!";
            }

            cout << "\n\n\t\t\t\tEnter TO Continue";
            getch();
            cout << "\n\nPress y to Continue ; otherwise n : ";
            cin >> con;
            if (con != 'y' && con != 'Y')
            {
                // clrscr();
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\tThank You  !!!!";
                getch();
                exit(0);
            }

        } while (con == 'y' || con == 'Y');
    } // close of faculty view

    // begin of student view
    if (ch == 3)  // begin of student view
    {
        // clrscr();
        system("cls");
        // char un[20];
        int value, s1 = 0;
        cout << "\n\t\t\tWelcome to Student Login page";
        cout << "\n\nEnter the UserName : ";
        cin >>::un;
        fstream fs;
        fs.open("stinfo.txt", ios::in | ios::binary);
        fs.seekg(0);
        while (!fs.eof())
        {
            value = -1;
            fs.read((char *)&f, sizeof(Admin));
            value = f.login();
            if (value == 1)
            {
                s1 = 1;
                break;
            }
        }
        fs.close();
        if (s1 == 1)
        {
            // clrscr();
            system("cls");
            // cout<<"\n\n\n\t\t\t\tWelcome to Student Page ";
        } // if first login is valid
        if (s1 != 1) // if first login is invalid then
        {
            // clrscr();
            system("cls");
            int sho = 0;
            cout << "\n\n\t\tYour Login Credentials are In-correct";
            cout << "\nTher UserName is Your ID/Rollno. ";
            cout << "\nThe Password is Case-Sensetive.";
            cout << "\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
            cout << "\nEnter the Choice : ";
            cin >> sho;
            if (sho == 1) //recover password
            {
                cout << "Enter the UserName :- ";
                cin >>::un;
                fstream fs;
                fs.open("stinfo.txt", ios::in | ios::binary);
                fs.seekg(0);
                int re, su = -1;
                while (!fs.eof())
                {
                    re = -1;
                    fs.read((char *)&f, sizeof(Admin));
                    re = f.recovery();
                    if (re == 1)
                    {
                        su = 1;
                        break;
                    }
                }
                fs.close();
                if (su == 1)
                {
                    getch();
                    //clrscr();
                    system("cls");
                    cout << "\n\n\n\n\t\t\tThank You !!!! ";
                    getch();
                    exit(0);
                }
                else
                {
                    cout << "\nYou are a Invalid User. ";
                    cout << "\nThank You !!!! ";
                    getch();
                    exit(0);
                }
            } // recovery password
            if (sho == 2) //re-attempt of login
            {
                cout << "\n\nEnter the UserName : ";
                cin >>::un;
                fstream fs;
                fs.open("stinfo.txt", ios::in | ios::binary);
                fs.seekg(0);
                int suc = -1, valu; // value for storing login() returned value suc for success login
                while (!fs.eof())
                {
                    valu = -1;
                    fs.read((char *)&f, sizeof(Admin));
                    valu = f.login();
                    if (valu == 1)
                    {
                        suc = 1;
                        break;
                    }
                }
                fs.close();
                if (suc == 1)
                {
                    //clrscr();
                    system("cls");
                }
                else
                {
                    getch();
                    cout << "\nYou are an Invalid User .... ";
                    cout << "\nThank You !!!! ";
                    getch();
                    exit(0);
                    exit(0);

                }
            }
            if (sho != 1 && sho != 2)
            {
                cout << "\n\nInvalid Input Provided. ";
                cout << "\n\n\t\t\tThank You !!!! ";
                getch();
                exit(0);
            }
        } // closing of first Invalid login (forget pasword & recover password)
        //getch();

        // Begin of student Panel

        char moreop = 'y';
        do
        {
            //clrscr();
            system("cls");
            cout << "\n\n\t\t\tWelcome to Student pannel  ";
            cout << "\n\n\t\t\t\t\t\t   Your UserID is : " <<::un;
            cout << "\n\nPress 1 to view Your Profile. ";
            cout << "\nPress 2 to Know Your Subject. ";
            cout << "\nPress 3 to Add a Subject. ";
            cout << "\nPress 4 to Delete a Subject. ";
            cout << "\nPress 5 to Modify your Profile. ";
            int inchoice;
            cout << "\n\nEnter Your Choice : ";
            cin >> inchoice;

            if (inchoice == 1)
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);
                int x;
                while (!fs.eof())
                {
                    x = 0;
                    fs.read((char *)&f, sizeof(Admin));
                    x = f.stprofile();
                    if (x == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }// closing of inchoice = 1
            if (inchoice == 2)
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);
                int y;
                while (!fs.eof())
                {
                    y = 0;
                    fs.read((char *)&f, sizeof(Admin));
                    int y = f.knowstsub();
                    if (y == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }// closing of choice = 2
            if (inchoice == 3)
            {
                fstream fs;
                fstream fs1;
                fs.open("stinfo.txt", ios::in | ios::binary);
                fs1.open("tmpstinfo.txt", ios::out | ios::ate);
                fs.seekg(0);
                while (!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.addstsub();
                    fs1.write((char *)&f, sizeof(Admin));
                    break;
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("tmpstinfo.txt", "stinfo.txt");
            } // closing of choice = 3
            if (inchoice == 4)
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in | ios::binary);
                fstream fs1;
                fs1.open("delstinfo.txt", ios::out | ios::ate);
                fs.seekg(0);
                while (!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.delstsub();
                    fs1.write((char *)&f, sizeof(Admin));
                    break;
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("delstinfo.txt", "stinfo.txt");
            }
            if (inchoice == 5)
            {
                fstream fs;
                fstream fs1;
                fs.open("stinfo.txt", ios::in | ios::binary);
                fs.seekg(0);
                fs1.open("modstinfo.txt", ios::out | ios::ate);
                while (!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.modstprofile();
                    fs1.write((char *)&f, sizeof(Admin));
                    break;
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("modstinfo.txt", "stinfo.txt");
            }
            if (inchoice < 1 || inchoice > 5)
            {
                cout << "\nInvalid Input Provided ....";
            }

            cout << "\n\n\t\t\tEnter to Continue ";
            getch();
            cout << "\n\nPress y , otherwise n to Perform More operation : ";
            cin >> moreop;
            if (moreop != 'y' && moreop != 'Y')
            {
                //clrscr();
                system("cls");
                cout << "\n\n\n\t\t\tThank You !!!! ";
                getch();
                exit(0);
            }
        } while (moreop == 'y' || moreop == 'Y');
        getch();
    }// closing of student Panel ch=3

    if (ch < 1 || ch > 3)
    {
        cout << "\nInvalid Input Provided !!!! ";
        getch();
        // clrscr();
        system("cls");
        cout << "\n\n\n\t\t\tThank You";
    }

    return 0;


}