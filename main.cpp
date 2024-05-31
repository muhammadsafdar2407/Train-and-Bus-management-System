#include <iostream>
#include <string.h>

#include "vehicle.cpp"
#include "ticket.cpp"
#include "utils.h"

using namespace std;

// GLOBAL FUNCTION
void mainMenu();
void BususerMenu();
void TrainuserMenu();
void BusadminMenu();
void TrainadminMenu();
void BusadminLogin();
void TrainadminLogin();
void BusviewBookingsMenu();
void TrainviewBookingsMenu();
void welcomeScreen();

// MAIN FUNCTION
int main()
{
    system("cls");
    system("COLOR 0f");

    welcomeScreen();

    return 0;
}

//OPERATOR OVERLOADING#
//template<typename >
ostream& operator<<(ostream &output, Ticket &obj){
	obj.displayTicket();
}

//  WELCOME SCREEN FUNCTION
void welcomeScreen()
{
    system("cls");

    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t================================================\n";
    cout << "\t\t\t\t\t\t\t\t\t\t||                  WELCOME TO                ||\n";
    cout << "\t\t\t\t\t\t\t\t\t\t||                                            ||\n";
    cout << "\t\t\t\t\t\t\t\t\t\t||  BUS & TRAIN RESERVATION SYSTEM MANAGEMENT ||\n";
    cout << "\t\t\t\t\t\t\t\t\t\t||                                            ||\n";
    cout << "\t\t\t\t\t\t\t\t\t\t||                    PROJECT                 ||\n";
    cout << "\t\t\t\t\t\t\t\t\t\t================================================\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t  Developed By:-                             \t\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t                                             \t\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t  Muhammad Safdar                              \t\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t  Abdul Rafiu                              \t\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t  Syed Mohammed Rayyan Imam                              \t\n";
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

    system("pause");
    mainMenu();
}

// MAIN MENU
void mainMenu()
{
    int choice,choice2;

    while (1)
    {
        system("cls");

        // MENU ITEMS
        printHeading("MAIN MENU");
        
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. Browse Buses                                    \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. Browse Trains                                   \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 3. EXIT                                         \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
        cin>>choice;
		if(choice!=3){
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. User Menu                                    \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. Admin Menu                                   \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice2;
    	}
        


        switch (choice)
        {
        	case 1:
        	switch (choice2){
        	case 1:
            BususerMenu();
            break;

        	case 2:
            BusadminLogin();
            break;

        	default:
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            mainMenu();
        }
        break;
        
        case 2:{
        	switch (choice2){
        	case 1:
            TrainuserMenu();
            break;

        	case 2:
            TrainadminLogin();
            break;

        	default:
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            mainMenu();
        }
        break;
    	}
        
        case 3:{
            system("cls");
            cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t  Thanks for using our project...!!! \t\t\t\n";
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t          Have a nice day...!!!      \t\t\t\n\n";
            exit(0);
            break;
        }
    }
}
}
// ADMIN LOGIN
void BusadminLogin()
{
    string adminUname, adminPass;

    system("cls");

    printHeading("ADMIN LOGIN");

    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter AdminID:-> ";
    cin >> adminUname;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Password:-> ";
    cin >> adminPass;

    if (adminUname == "admin" && adminPass == "pass")
    {
        BusadminMenu();
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tUsername or Password is wrong...!!! ";
        system("pause");
        BusadminLogin();
    }
}

void TrainadminLogin()
{
    string adminUname, adminPass;

    system("cls");

    printHeading("ADMIN LOGIN");

    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter AdminID:-> ";
    cin >> adminUname;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Password:-> ";
    cin >> adminPass;

    if (adminUname == "admin" && adminPass == "pass")
    {
        TrainadminMenu();
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tUsername or Password is wrong...!!! ";
        system("pause");
        TrainadminLogin();
    }
}

// USER MENU
void BususerMenu()
{

    int choice;

    while (1)
    {
        system("cls");

        BusTicket t;

        // MENU ITEMS
        printHeading("USER MENU");

        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. Book Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. View Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 3. Cancel Ticket                                \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 4. BACK                                         \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";

        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.bookTicket();
            system("pause");
            break;

        case 2:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 3:
            t.cancelTicket();
            system("pause");
            break;

        case 4:
            system("cls");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            break;
            BususerMenu();
        }
    }
}

void TrainuserMenu()
{

    int choice;

    while (1)
    {
        system("cls");

        TrainTicket t;

        // MENU ITEMS
        printHeading("USER MENU");

        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. Book Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. View Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 3. Cancel Ticket                                \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 4. BACK                                         \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";

        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.bookTicket();
            system("pause");
            break;

        case 2:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 3:
            t.cancelTicket();
            system("pause");
            break;

        case 4:
            system("cls");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            break;
            TrainuserMenu();
        }
    }
}

// ADMIN MENU FUNCTION
void BusadminMenu()
{
    Bus b;
    BusTicket t;

    int choice;

    while (1)
    {
        system("cls");

        printHeading("ADMIN PORTAL");

        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. Add Bus                                      \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. View Buses                                   \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 3. Book Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 4. Edit Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 5. Cancel Ticket                                \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 6. View Bookings                                \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 7. View Bus Details                             \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 8. Edit Bus                                     \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 9. Delete Bus                                   \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 10. BACK                                        \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            b.add();
            system("pause");
            break;

        case 2:
            b.showAll();
            system("pause");
            break;

        case 3:
            t.bookTicket();
            system("pause");
            break;

        case 4:
            t.editTicket();
            system("pause");
            break;

        case 5:
            t.cancelTicket();
            system("pause");
            break;

        case 6:
            BusviewBookingsMenu();
            break;

        case 7:
            b.viewDetails();
            system("pause");
            break;

        case 8:
            b.edit();
            system("pause");
            break;

        case 9:
            b.Delete();
            system("pause");
            break;

        case 10:
            system("cls");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            BusadminMenu();
        }
    }
}



void TrainadminMenu()
{
    Train b;
    BusTicket t;

    int choice;

    while (1)
    {
        system("cls");

        printHeading("ADMIN PORTAL");

        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. Add Train                                      \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. View Trains                                   \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 3. Book Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 4. Edit Ticket                                  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 5. Cancel Ticket                                \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 6. View Bookings                                \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 7. View Train Details                             \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 8. Edit Train                                     \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 9. Delete Train                                   \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 10. BACK                                        \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            b.add();
            system("pause");
            break;

        case 2:
            b.showAll();
            system("pause");
            break;

        case 3:
            t.bookTicket();
            system("pause");
            break;

        case 4:
            t.editTicket();
            system("pause");
            break;

        case 5:
            t.cancelTicket();
            system("pause");
            break;

        case 6:
            TrainviewBookingsMenu();
            break;

        case 7:
            b.viewDetails();
            system("pause");
            break;

        case 8:
            b.edit();
            system("pause");
            break;

        case 9:
            b.Delete();
            system("pause");
            break;

        case 10:
            system("cls");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            TrainadminMenu();
        }
    }
}




// VIEW BOOKINGS MENU FUNCTION
void BusviewBookingsMenu()
{
    BusTicket t;

    int choice;

    while (1)
    {
        system("cls");

        printHeading("VIEW BOOKINGS");

        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. By PNR                                      \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. By Name                                      \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 3. By Bus                                       \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 4. By Source                                    \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 5. By Destination                               \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 6. All Bookings                                 \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 7. BACK                                         \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 2:
            t.showTicketsByName();
            system("pause");
            break;

        case 3:
            t.showTicketsByVehicle();
            system("pause");
            break;

        case 4:
            t.showTicketsBySource();
            system("pause");
            break;

        case 5:
            t.showTicketsByDestination();
            system("pause");
            break;

        case 6:
            t.showAllTickets();
            system("pause");
            break;

        case 7:
            system("cls");
            BusadminMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            BusviewBookingsMenu();
        }
    }
}

void TrainviewBookingsMenu()
{
    TrainTicket t;

    int choice;

    while (1)
    {
        system("cls");

        printHeading("VIEW BOOKINGS");

        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. By PNR                                      \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2. By Name                                      \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 3. By Train                                       \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 4. By Source                                    \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 5. By Destination                               \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 6. All Bookings                                 \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 7. BACK                                         \n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 2:
            t.showTicketsByName();
            system("pause");
            break;

        case 3:
            t.showTicketsByVehicle();
            system("pause");
            break;

        case 4:
            t.showTicketsBySource();
            system("pause");
            break;

        case 5:
            t.showTicketsByDestination();
            system("pause");
            break;

        case 6:
            t.showAllTickets();
            system("pause");
            break;

        case 7:
            system("cls");
            TrainadminMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            TrainviewBookingsMenu();
        }
    }
}

