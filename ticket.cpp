#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "ticket.h"
#include "vehicle.h"
#include "utils.h"

using namespace std;

// GENERATE TICKET
template <typename T>
void BusTicket::generateTicket(char *n, T t)
{
	char p[10];
	char d[10];
    setName(n);
    strcpy(p,generatePNR(99999).c_str());
    setpnrNo(p);
    strcpy(d,getCurrentDate().c_str());
    setdate(d);
    bus = t;
}

// DISPLAY TICKET DETAILS
void BusTicket::displayTicket()
{
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Name:-> " << getName();
    cout << "\n\t\t\t\t\t\t\t\t\t\t PNR No:-> " << getPnrNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Bus No:-> " << bus.getNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Seat No.:-> " << bus.getBookedSeats();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Date:-> " << getDate();
    cout << "\n\t\t\t\t\t\t\t\t\t\t From:-> " << bus.getSource();
    cout << "\n\t\t\t\t\t\t\t\t\t\t To:-> " << bus.getDestination();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Source Time:-> " << bus.getSourceTime();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Destination Time:-> " << bus.getDestinationTime();
    cout << fixed << setprecision(2);
    cout << "\n\t\t\t\t\t\t\t\t\t\t Bus Fare:-> " << bus.getFare();
    cout << "\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\n";
}

// BOOK TICKET
void BusTicket::bookTicket()
{
    system("cls");

    char from[20], to[20];
    int chk = 0;

    Bus b;
    fstream busFileStream, ticketFileStream, tempFileStream;

    printHeading("BOOK TICKET");

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
    if (busFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
        cin.ignore();
        cin.getline(from, 20);
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
        cin.getline(to, 20);

        system("cls");
        printHeading("AVAILABLE BUSES");

        busFileStream.read((char *)&b, sizeof(b));
        while (!busFileStream.eof())
        {
            if (strcmpi(b.getSource(), from) == 0 && strcmpi(b.getDestination(), to) == 0)
            {
                b.showDetails();
                chk = 1;
            }
            busFileStream.read((char *)&b, sizeof(b));
        }

        busFileStream.close();

        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Buses Found...!!\n";
        }
        else
        {
            char bNo[10];
            int booked = 0;

            cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
            cin.getline(bNo, 10);

            busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
            tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

            busFileStream.read((char *)&b, sizeof(b));
            while (!busFileStream.eof())
            {
                if (strcmpi(b.getSource(), from) == 0 && strcmpi(b.getDestination(), to) == 0 && strcmp(b.getNo(), bNo) == 0)
                {
                    if (b.getBookedSeats() >= 40)
                    {
                        cout << "\n\t\t\t\t\t\t\t\t\t\tSeat not available...!!\n";
                        break;
                    }
                    else
                    {
                        system("cls");
                        printHeading("BOOK TICKET");
                        char n[20];
                        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Customer Name :-> ";
                        cin.getline(n, 20);
                        b.setBookedSeats();
                        generateTicket(n, b);
                        ticketFileStream.open("bustickets.dat", ios::out | ios::app | ios::binary);
                        ticketFileStream.write((char *)this, sizeof(*this));
                        ticketFileStream.close();
                        tempFileStream.write((char *)&b, sizeof(b));

                        booked = 1;
                        system("cls");
                        printHeading("BOOKING DETAILS");
                        cout<<*this;
                        cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Booked Successfully...!!\n";
                    }
                }
                else
                {
                    tempFileStream.write((char *)&b, sizeof(b));
                }
                busFileStream.read((char *)&b, sizeof(b));
            }

            if (booked == 1)
            {
                busFileStream.close();
                tempFileStream.close();
                remove("buses.dat");
                rename("temp.dat", "buses.dat");
            }
        }
        busFileStream.close();
    }
}

// CANCEL TICKET
void BusTicket::cancelTicket()
{
    system("cls");

    char pnr[10];
    int chk = 0;

    fstream busFileStream, ticketFileStream, tempFileStream, busTempFileStream;

    printHeading("CANCEL TICKET");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter PNR Number:-> ";
    cin.ignore();
    cin.getline(pnr, 10);

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);
    tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) != 0)
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            else
            {
                Bus b;
                busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
                busTempFileStream.open("bustemp.dat", ios::out | ios::app | ios::binary);

                busFileStream.read((char *)&b, sizeof(b));
                while (!busFileStream.eof())
                {
                    if (strcmp(b.getNo(), bus.getNo()) == 0)
                    {
                        b.setCancelTicket();
                        busTempFileStream.write((char *)&b, sizeof(b));
                    }
                    else
                    {
                        busTempFileStream.write((char *)&b, sizeof(b));
                    }
                    busFileStream.read((char *)&b, sizeof(b));
                }
                busFileStream.close();
                busTempFileStream.close();
                remove("buses.dat");
                rename("bustemp.dat", "buses.dat");
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            ticketFileStream.close();
            tempFileStream.close();
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Not Found...!!\n";
        }
        else
        {
            ticketFileStream.close();
            tempFileStream.close();
            remove("bustickets.dat");
            rename("temp.dat", "bustickets.dat");
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Cancelled...!!\n";
        }
    }
}

// EDIT TICKET
void BusTicket::editTicket()
{
    system("cls");

    char pnr[10];
    int chk = 0;

    fstream ticketFileStream, tempFileStream;

    printHeading("EDIT TICKET");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter PNR Number:-> ";
    cin.ignore();
    cin.getline(pnr, 10);

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);

    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) == 0)
            {
                system("cls");
                printHeading("EDIT TICKET");

                cout<<*this;
                char n[20];
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Passenger Name :-> ";
                cin.getline(n, 20);
                setName(n);
                tempFileStream.write((char *)this, sizeof(*this));

                chk = 1;
            }
            else
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }

        if (chk = 1)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Updated Successfully...!!\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Not Found...!!\n";
        }

        ticketFileStream.close();
        tempFileStream.close();
        remove("bustickets.dat");
        rename("temp.dat", "bustickets.dat");
    }
}

// SHOW TICKET BY PNR
void BusTicket::showTicketsByPNR()
{
    system("cls");

    char pnr[10];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY PNR");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter PNR Number:-> ";
    cin.ignore();
    cin.getline(pnr, 10);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY NAME
void BusTicket::showTicketsByName()
{
    system("cls");

    char n[20];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY NAME");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Passenger Name:-> ";
    cin.ignore();
    cin.getline(n, 20);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(getName(), n) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY BUS
void BusTicket::showTicketsByVehicle()
{
    system("cls");

    char bNo[10];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY BUS");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin.ignore();
    cin.getline(bNo, 10);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(bus.getNo(), bNo) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY SOURCE
void BusTicket::showTicketsBySource()
{
    system("cls");

    char s[20];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY SOURCE");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
    cin.ignore();
    cin.getline(s, 20);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(bus.getSource(), s) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY DESTINATION
void BusTicket::showTicketsByDestination()
{
    system("cls");

    char d[20];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY DESTINATION");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
    cin.ignore();
    cin.getline(d, 20);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(bus.getDestination(), d) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW ALL BOOKINGS
void BusTicket::showAllTickets()
{
    system("cls");

    fstream ticketFileStream;

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("bustickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            cout<<*this;
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        ticketFileStream.close();
    }
}



//Train
// GENERATE TICKET
template <typename T>
void TrainTicket::generateTicket(char *n, T t)
{
    char p[10];
	char d[10];
    setName(n);
    strcpy(p,generatePNR(99999).c_str());
    setpnrNo(p);
    strcpy(d,getCurrentDate().c_str());
    setdate(d);
    train = t;
}

// DISPLAY TICKET DETAILS
void TrainTicket::displayTicket()
{
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Name:-> " << getName();
    cout << "\n\t\t\t\t\t\t\t\t\t\t PNR No:-> " << getPnrNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Train No:-> " << train.getNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Seat No.:-> " << train.getBookedSeats();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Date:-> " << getDate();
    cout << "\n\t\t\t\t\t\t\t\t\t\t From:-> " << train.getSource();
    cout << "\n\t\t\t\t\t\t\t\t\t\t To:-> " << train.getDestination();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Source Time:-> " << train.getSourceTime();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Destination Time:-> " << train.getDestinationTime();
    cout << fixed << setprecision(2);
    cout << "\n\t\t\t\t\t\t\t\t\t\t Train Fare:-> " << train.getFare();
    cout << "\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\n";
}

// BOOK TICKET
void TrainTicket::bookTicket()
{
    system("cls");

    char from[20], to[20];
    int chk = 0;

    Train T;
    fstream trainFileStream, ticketFileStream, tempFileStream;

    printHeading("BOOK TICKET");

    trainFileStream.open("trains.dat", ios::in | ios::app | ios::binary);
    if (trainFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
        cin.ignore();
        cin.getline(from, 20);
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
        cin.getline(to, 20);

        system("cls");
        printHeading("AVAILABLE Trains");

        trainFileStream.read((char *)&T, sizeof(T));
        while (!trainFileStream.eof())
        {
            if (strcmpi(T.getSource(), from) == 0 && strcmpi(T.getDestination(), to) == 0)
            {
                T.showDetails();
                chk = 1;
            }
            trainFileStream.read((char *)&T, sizeof(T));
        }

        trainFileStream.close();

        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Trains Found...!!\n";
        }
        else
        {
            char tNo[10];
            int booked = 0;

            cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Train Number:-> ";
            cin.getline(tNo, 10);

            trainFileStream.open("trains.dat", ios::in | ios::app | ios::binary);
            tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

            trainFileStream.read((char *)&T, sizeof(T));
            while (!trainFileStream.eof())
            {
                if (strcmpi(T.getSource(), from) == 0 && strcmpi(T.getDestination(), to) == 0 && strcmp(T.getNo(), tNo) == 0)
                {
                    if (T.getBookedSeats() >= 150)
                    {
                        cout << "\n\t\t\t\t\t\t\t\t\t\tSeat not available...!!\n";
                        break;
                    }
                    else
                    {
                        system("cls");
                        printHeading("BOOK TICKET");
                        char n[20];
                        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Customer Name :-> ";
                        cin.getline(n, 20);
                        T.setBookedSeats();
                        generateTicket(n, T);
                        ticketFileStream.open("traintickets.dat", ios::out | ios::app | ios::binary);
                        ticketFileStream.write((char *)this, sizeof(*this));
                        ticketFileStream.close();
                        tempFileStream.write((char *)&T, sizeof(T));

                        booked = 1;
                        system("cls");
                        printHeading("BOOKING DETAILS");
                        cout<<*this;
                        cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Booked Successfully...!!\n";
                    }
                }
                else
                {
                    tempFileStream.write((char *)&T, sizeof(T));
                }
                trainFileStream.read((char *)&T, sizeof(T));
            }

            if (booked == 1)
            {
                trainFileStream.close();
                tempFileStream.close();
                remove("trains.dat");
                rename("temp.dat", "trains.dat");
            }
        }
        trainFileStream.close();
    }
}

// CANCEL TICKET
void TrainTicket::cancelTicket()
{
    system("cls");

    char pnr[10];
    int chk = 0;

    fstream trainFileStream, ticketFileStream, tempFileStream, trainTempFileStream;

    printHeading("CANCEL TICKET");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter PNR Number:-> ";
    cin.ignore();
    cin.getline(pnr, 10);

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);
    tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) != 0)
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            else
            {
                Train b;
                trainFileStream.open("trains.dat", ios::in | ios::app | ios::binary);
                trainTempFileStream.open("traintemp.dat", ios::out | ios::app | ios::binary);

                trainFileStream.read((char *)&b, sizeof(b));
                while (!trainFileStream.eof())
                {
                    if (strcmp(b.getNo(), train.getNo()) == 0)
                    {
                        b.setCancelTicket();
                        trainTempFileStream.write((char *)&b, sizeof(b));
                    }
                    else
                    {
                        trainTempFileStream.write((char *)&b, sizeof(b));
                    }
                    trainFileStream.read((char *)&b, sizeof(b));
                }
                trainFileStream.close();
                trainTempFileStream.close();
                remove("trains.dat");
                rename("traintemp.dat", "trains.dat");
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            ticketFileStream.close();
            tempFileStream.close();
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Not Found...!!\n";
        }
        else
        {
            ticketFileStream.close();
            tempFileStream.close();
            remove("traintickets.dat");
            rename("temp.dat", "traintickets.dat");
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Cancelled...!!\n";
        }
    }
}

// EDIT TICKET
void TrainTicket::editTicket()
{
    system("cls");

    char pnr[10];
    int chk = 0;

    fstream ticketFileStream, tempFileStream;

    printHeading("EDIT TICKET");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter PNR Number:-> ";
    cin.ignore();
    cin.getline(pnr, 10);

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);

    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) == 0)
            {
                system("cls");
                printHeading("EDIT TICKET");

                cout<<*this;
                char n[20];
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Passenger Name :-> ";
                cin.getline(n, 20);
                setName(n);
                tempFileStream.write((char *)this, sizeof(*this));

                chk = 1;
            }
            else
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }

        if (chk = 1)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Updated Successfully...!!\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Not Found...!!\n";
        }

        ticketFileStream.close();
        tempFileStream.close();
        remove("traintickets.dat");
        rename("temp.dat", "traintickets.dat");
    }
}

// SHOW TICKET BY PNR
void TrainTicket::showTicketsByPNR()
{
    system("cls");

    char pnr[10];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY PNR");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter PNR Number:-> ";
    cin.ignore();
    cin.getline(pnr, 10);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY NAME
void TrainTicket::showTicketsByName()
{
    system("cls");

    char n[20];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY NAME");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Passenger Name:-> ";
    cin.ignore();
    cin.getline(n, 20);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(getName(), n) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY Train
void TrainTicket::showTicketsByVehicle()
{
    system("cls");

    char bNo[10];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY TRAIN");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Train Number:-> ";
    cin.ignore();
    cin.getline(bNo, 10);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(train.getNo(), bNo) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY SOURCE
void TrainTicket::showTicketsBySource()
{
    system("cls");

    char s[20];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY SOURCE");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
    cin.ignore();
    cin.getline(s, 20);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(train.getSource(), s) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY DESTINATION
void TrainTicket::showTicketsByDestination()
{
    system("cls");

    char d[20];
    int chk = 0;
    fstream ticketFileStream;

    printHeading("SHOW BOOKINGS BY DESTINATION");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
    cin.ignore();
    cin.getline(d, 20);

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(train.getDestination(), d) == 0)
            {
                cout<<*this;
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW ALL BOOKINGS
void TrainTicket::showAllTickets()
{
    system("cls");

    fstream ticketFileStream;

    system("cls");

    printHeading("BOOKINGS");

    ticketFileStream.open("traintickets.dat", ios::in | ios::app | ios::binary);
    if (ticketFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
//          cout<<*this;
			cout<<*this;
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        ticketFileStream.close();
    }
}
