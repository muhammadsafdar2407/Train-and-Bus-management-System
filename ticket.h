#ifndef TICKET_H
#define TICKET_H

#include <iostream>

#include "vehicle.h"


// CLASS TICKET
class Ticket
{
private:
    char name[20], pnrNo[10], date[20];

public:
	template <typename T>
    void generateTicket(char *, T){}
    virtual void displayTicket()=0;
    virtual void bookTicket()=0;
    virtual void cancelTicket()=0;
    virtual void editTicket()=0;
    virtual void showTicketsByPNR()=0;
    virtual void showTicketsByName()=0;
    virtual void showTicketsByVehicle()=0;
    virtual void showTicketsBySource()=0;
    virtual void showTicketsByDestination()=0;
    virtual void showAllTickets()=0;

    // GETTERS
    char *getName()
    {
        return name;
    }

    char *getPnrNo()
    {
        return pnrNo;
    }

    char *getDate()
    {
        return date;
    }

    // SETTERS
    void setName(char *n)
    {
        if (n && n[0])
            strcpy(name, n);
    }
    
    void setpnrNo(char *n)
    {
        if (n && n[0])
            strcpy(pnrNo, n);
    }
    
    void setdate(char *d)
    {
        if (d && d[0])
            strcpy(date, d);
    }
    
    friend ostream& operator<<(ostream&, Ticket&);
};

class BusTicket: public Ticket{
	Bus bus;
	
	public:
		template <typename T>
		void generateTicket(char *, T);
    	void displayTicket();
    	void bookTicket();
    	void cancelTicket();
    	void editTicket();
    	void showTicketsByPNR();
    	void showTicketsByName();
    	void showTicketsByVehicle();
    	void showTicketsBySource();
    	void showTicketsByDestination();
    	void showAllTickets();
};

class TrainTicket: public Ticket{
	Train train;
	
	public:
		template <typename T>
		void generateTicket(char *, T);
    	void displayTicket();
    	void bookTicket();
    	void cancelTicket();
    	void editTicket();
    	void showTicketsByPNR();
    	void showTicketsByName();
    	void showTicketsByVehicle();
    	void showTicketsBySource();
    	void showTicketsByDestination();
    	void showAllTickets();
    	
};

#endif // !TICKET_H
