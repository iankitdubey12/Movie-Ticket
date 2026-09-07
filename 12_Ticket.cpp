class Ticket {
public:
    void print(Booking* booking) {
        cout << endl;
        cout << "========== TICKET ==========" << endl;
        cout << "Booking ID : " << booking->getBookingId() << endl;
        cout << "Movie      : "
             << booking->getShow()->getMovie()->getTitle() << endl;
        cout << "Screen     : "
             << booking->getShow()->getScreen()->getScreenNumber() << endl;
        cout << "Show Time  : "
             << booking->getShow()->getStartTime() << endl;

        cout << "Seats      : ";
        for (ShowSeat* seat : booking->getSeats())
            cout << seat->getSeat()->getSeatNumber() << " ";

        cout << endl;
        cout << "Total      : Rs." << booking->getTotalAmount() << endl;
        cout << "Status     : CONFIRMED" << endl;
        cout << "============================" << endl;
    }
};
