#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "vehicle.h"
#include "ticket.h"
#include "utils.h"

using namespace std;

// ADD BUS
void Bus::add()
{
	char n[20], s[20], d[20], sTime[20], dTime[20];
    double fare;
    fstream busFileStream;

    system("cls");

    printHeading("ADD BUS");

    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin.ignore();
    cin.getline(n, 10);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
    cin.getline(s, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
    cin.getline(d, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source Time:-> ";
    cin.getline(sTime, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination Time:-> ";
    cin.getline(dTime, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Fare:-> ";
    cin >> fare;
    
    setNo(n);
    setSource(s);
    setDestination(d);
	setSourceTime(sTime);
    setDestinationTime(dTime);
    setFare(fare);

    busFileStream.open("buses.dat", ios::out | ios::app | ios::binary);
    busFileStream.write((char *)this, sizeof(*this));
    busFileStream.close();

    cout << "\n\t\t\t\t\t\t\t\t\t\tBus Added Successfully...!!!:-> \n";
}

// SHOW BUS DETAILS
void Bus::showDetails()
{
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Bus No:-> " << getNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Source:-> " << getSource();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Destination:-> " << getDestination();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Time:-> " << getSourceTime() << " - " << getDestinationTime();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Total Seats:-> " << getMaxSeats();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Seats Remaining:-> " << (getMaxSeats() - getBookedSeats());
    cout << fixed << setprecision(2);
    cout << "\n\t\t\t\t\t\t\t\t\t\t Bus Fare:-> " << getFare();
    cout << "\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\n";
}

// VIEW ALL BUS INFO
void Bus::showAll()
{
    system("cls");

    fstream busFileStream;

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
    if (!busFileStream)
        cout << "\n\t\t\t\tFile Not Found...!!!";
    else
    {
        printHeading("BUSES");

        busFileStream.read((char *)this, sizeof(*this));

        while (!busFileStream.eof())
        {
            showDetails();
            busFileStream.read((char *)this, sizeof(*this));
        }
        busFileStream.close();
    }
}

// VIEW BUS INFO
void Bus::viewDetails()
{
    system("cls");

    char bNo[10];
    int chk = 0;
    fstream busFileStream;

    printHeading("VIEW BUS INFO");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin.ignore();
    cin.getline(bNo, 10);

    system("cls");
    printHeading("BUS INFO");

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
    if (busFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        busFileStream.read((char *)this, sizeof(*this));
        while (!busFileStream.eof())
        {
            if (strcmp(getNo(), bNo) == 0)
            {
                showDetails();
                chk = 1;
            }
            busFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Not Found...!!\n";
        }
        busFileStream.close();
    }
}

// EDIT BUS
void Bus::edit()
{
    system("cls");

    char bNo[10];
    int chk = 0;

    fstream busFileStream, tempFileStream;

    printHeading("EDIT BUS");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin.ignore();
    cin.getline(bNo, 10);

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);

    if (busFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

        busFileStream.read((char *)this, sizeof(*this));
        while (!busFileStream.eof())
        {
            if (strcmp(getNo(), bNo) == 0)
            {
                system("cls");
                printHeading("EDIT BUS");

                showDetails();
                char s[20], d[20], sTime[20], dTime[20];
                double fare;
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
                cin.getline(s, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
                cin.getline(d, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source Time:-> ";
                cin.getline(sTime, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination Time:-> ";
                cin.getline(dTime, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Fare:-> ";
                cin.ignore();
                cin >> fare;
                setSource(s);
                setDestination(d);
                setSourceTime(sTime);
                setDestinationTime(dTime);
                setFare(fare);
                tempFileStream.write((char *)this, sizeof(*this));

                chk = 1;
            }
            else
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            busFileStream.read((char *)this, sizeof(*this));
        }

        if (chk = 1)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Updated Successfully...!!\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Not Found...!!\n";
        }

        busFileStream.close();
        tempFileStream.close();
        remove("buses.dat");
        rename("temp.dat", "buses.dat");
    }
}

// DELETE BUS
void Bus::Delete()
{
    system("cls");

    char bNo[10];
    int chk = 0;
    fstream busFileStream, tempFileStream;

    printHeading("DELETE BUS");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus No:-> ";
    cin.ignore();
    cin.getline(bNo, 10);

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);

    if (busFileStream.fail())
    {
        cout << "\n\\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {
        tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);
        busFileStream.read((char *)this, sizeof(*this));
        while (!busFileStream.eof())
        {
            if (strcmp(getNo(), bNo) != 0)
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            else
            {
                chk = 1;
            }
            busFileStream.read((char *)this, sizeof(*this));
        }

        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Not Found...!!\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Deleted...!!\n";
        }

        busFileStream.close();
        tempFileStream.close();
        remove("buses.dat");
        rename("temp.dat", "buses.dat");
    }
}

void Train::add()
{
	char n[20], s[20], d[20], sTime[20], dTime[20];
    double fare;
    fstream trainFileStream;

    system("cls");

    printHeading("ADD Train");

    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Train Number:-> ";
    cin.ignore();
    cin.getline(n, 10);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
    cin.getline(s, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
    cin.getline(d, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source Time:-> ";
    cin.getline(sTime, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination Time:-> ";
    cin.getline(dTime, 20);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Train Fare:-> ";
    cin >> fare;
    
    setNo(n);
    setSource(s);
    setDestination(d);
	setSourceTime(sTime);
    setDestinationTime(dTime);
    setFare(fare);

    trainFileStream.open("trains.dat", ios::out | ios::app | ios::binary);
    trainFileStream.write((char *)this, sizeof(*this));
    trainFileStream.close();

    cout << "\n\t\t\t\t\t\t\t\t\t\tTrain Added Successfully...!!!:-> \n";
}

void Train::showDetails()
{
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Train No:-> " << getNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Source:-> " << getSource();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Destination:-> " << getDestination();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Time:-> " << getSourceTime() << " - " << getDestinationTime();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Total Seats:-> " << getMaxSeats();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Seats Remaining:-> " << (getMaxSeats() - getBookedSeats());
    cout << fixed << setprecision(2);
    cout << "\n\t\t\t\t\t\t\t\t\t\t Train Fare:-> " << getFare();
    cout << "\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\n";
}

void Train::showAll()
{
    system("cls");

    fstream trainFileStream;

    trainFileStream.open("trains.dat", ios::in | ios::app | ios::binary);
    if (!trainFileStream)
        cout << "\n\t\t\t\tFile Not Found...!!!";
    else
    {
        printHeading("Trains");

        trainFileStream.read((char *)this, sizeof(*this));

        while (!trainFileStream.eof())
        {
            showDetails();
            trainFileStream.read((char *)this, sizeof(*this));
        }
        trainFileStream.close();
    }
}

void Train::viewDetails()
{
	
    system("cls");

    char tNo[10];
    int chk = 0;
    fstream trainFileStream;

    printHeading("VIEW TRAIN INFO");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Train Number:-> ";
    cin.ignore();
    cin.getline(tNo, 10);

    system("cls");
    printHeading("TRAIN INFO");

    trainFileStream.open("trains.dat", ios::in | ios::app | ios::binary);
    if (trainFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        trainFileStream.read((char *)this, sizeof(*this));
        while (!trainFileStream.eof())
        {
            if (strcmp(getNo(), tNo) == 0)
            {
                showDetails();
                chk = 1;
            }
            trainFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTrain Not Found...!!\n";
        }
        trainFileStream.close();
    }
}

void Train::edit()
{
    system("cls");

    char tNo[10];
    int chk = 0;

    fstream trainFileStream, tempFileStream;

    printHeading("EDIT TRAIN");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Tus Number:-> ";
    cin.ignore();
    cin.getline(tNo, 10);

    trainFileStream.open("trains.dat", ios::in | ios::app | ios::binary);

    if (trainFileStream.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

        trainFileStream.read((char *)this, sizeof(*this));
        while (!trainFileStream.eof())
        {
            if (strcmp(getNo(), tNo) == 0)
            {
                system("cls");
                printHeading("EDIT TRAIN");

                showDetails();
                char s[20], d[20], sTime[20], dTime[20];
                double fare;
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
                cin.getline(s, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
                cin.getline(d, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source Time:-> ";
                cin.getline(sTime, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination Time:-> ";
                cin.getline(dTime, 20);
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Train Fare:-> ";
                cin.ignore();
                cin >> fare;
                setSource(s);
                setDestination(d);
                setSourceTime(sTime);
                setDestinationTime(dTime);
                setFare(fare);
                tempFileStream.write((char *)this, sizeof(*this));

                chk = 1;
            }
            else
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            trainFileStream.read((char *)this, sizeof(*this));
        }

        if (chk = 1)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTrain Updated Successfully...!!\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTrain Not Found...!!\n";
        }

        trainFileStream.close();
        tempFileStream.close();
        remove("trains.dat");
        rename("temp.dat", "tains.dat");
    }
}

void Train::Delete()
{
    system("cls");

    char tNo[10];
    int chk = 0;
    fstream trainFileStream, tempFileStream;

    printHeading("DELETE TRAIN");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Train No:-> ";
    cin.ignore();
    cin.getline(tNo, 10);

    trainFileStream.open("trains.dat", ios::in | ios::app | ios::binary);

    if (trainFileStream.fail())
    {
        cout << "\n\\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {
        tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);
        trainFileStream.read((char *)this, sizeof(*this));
        while (!trainFileStream.eof())
        {
            if (strcmp(getNo(), tNo) != 0)
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            else
            {
                chk = 1;
            }
            trainFileStream.read((char *)this, sizeof(*this));
        }

        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTrain Not Found...!!\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTrain Deleted...!!\n";
        }

        trainFileStream.close();
        tempFileStream.close();
        remove("trains.dat");
        rename("temp.dat", "trains.dat");
    }
}
