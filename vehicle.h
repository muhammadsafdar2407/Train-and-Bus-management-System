#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

// CLASS VEHICLE
class Vehicle
{
private:
    int maxSeats, bookedSeats;
    double Fare;
    char VehicleNo[10], source[20], destination[20], sourceTime[20], destinationTime[20];

public:
    Vehicle()
    {
        strcpy(VehicleNo, "");
        maxSeats = 32;
        bookedSeats = 0;
        Fare = 0.0;
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(sourceTime, "");
        strcpy(destinationTime, "");
    }

    // METHODS
	virtual void add()=0;
    virtual void showAll()=0;
    virtual void showDetails()=0;
    virtual void viewDetails()=0;
    virtual void Delete()=0;
    virtual void edit()=0;

    // GETTERS
    char *getNo()
    {
        return VehicleNo;
    }

    char *getSource()
    {

        return source;
    }

    char *getDestination()
    {
        return destination;
    }

    char *getSourceTime()
    {
        return sourceTime;
    }

    char *getDestinationTime()
    {
        return destinationTime;
    }

    int getBookedSeats()
    {
        return bookedSeats;
    }

    int getMaxSeats()
    {
        return maxSeats;
    }

    double getFare()
    {
        return Fare;
    }

    // SETTERS
    void setBookedSeats()
    {
        bookedSeats++;
    }

    void setCancelTicket()
    {
        bookedSeats--;
    }
    
    void setNo(char *n)
    {
        if (n && n[0])
            strcpy(VehicleNo, n);
    }

    void setSource(char *s)
    {
        if (s && s[0])
            strcpy(source, s);
    }

    void setDestination(char *d)
    {
        if (d && d[0])
            strcpy(destination, d);
    }

    void setSourceTime(char *s)
    {
        if (s && s[0])
            strcpy(sourceTime, s);
    }

    void setDestinationTime(char *d)
    {
        if (d && d[0])
            strcpy(destinationTime, d);
    }

    void setFare(double f)
    {
        if (f)
            Fare = f;
    }
    
    void setmaxSeats(int s)
    {
        if (s)
            maxSeats = s;
    }
};

class Bus : public Vehicle{
	public:
		Bus()
    	{
        	setmaxSeats(40);
    	}
		void add();
    	void showAll();
    	void showDetails();
    	void viewDetails();
    	void Delete();
		void edit();
	
};

class Train : public Vehicle{
	public:
		Train()
    	{
        	setmaxSeats(150);
    	}
		void add();
    	void showAll();
    	void showDetails();
    	void viewDetails();
    	void Delete();
		void edit();
	
};
#endif // !VEHICLE_H
