enum SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat* seat;
    SeatStatus status;

public:
    ShowSeat(Seat* seat) {
        this->seat = seat;
        status = AVAILABLE;
    }

    bool isAvailable() {
        return status == AVAILABLE;
    }

    void book() {
        status = BOOKED;
    }

    void release() {
        status = AVAILABLE;
    }

    Seat* getSeat() {
        return seat;
    }

    SeatStatus getStatus() {
        return status;
    }
};
