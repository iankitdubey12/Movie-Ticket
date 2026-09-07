enum BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };

class Booking {
private:
    static int nextBookingId;
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;

public:
    Booking(Customer* customer, Show* show,
            vector<ShowSeat*> seats, double amount) {
        bookingId = nextBookingId++;
        this->customer = customer;
        this->show = show;
        this->seats = seats;
        totalAmount = amount;
        status = PENDING;
    }

    void confirm() { status = CONFIRMED; }
    void cancel() { status = CANCELLED; }
    void fail() { status = FAILED; }

    int getBookingId() { return bookingId; }
    double getTotalAmount() { return totalAmount; }
    BookingStatus getStatus() { return status; }

    vector<ShowSeat*>& getSeats() { return seats; }
    Show* getShow() { return show; }
    Customer* getCustomer() { return customer; }
};

int Booking::nextBookingId = 1001;
