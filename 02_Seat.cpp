enum SeatType { SILVER, GOLD, PLATINUM };

class Seat {
private:
    int seatNumber;
    SeatType type;

public:
    Seat(int seatNumber, SeatType type) {
        this->seatNumber = seatNumber;
        this->type = type;
    }

    int getSeatNumber() { return seatNumber; }
    SeatType getType() { return type; }

    double getPrice() {
        if (type == SILVER) return 150;
        if (type == GOLD) return 250;
        return 400;
    }
};
