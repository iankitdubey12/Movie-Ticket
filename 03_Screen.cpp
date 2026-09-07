class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber) {
        this->screenNumber = screenNumber;
    }

    void addSeat(Seat seat) {
        seats.push_back(seat);
    }

    vector<Seat>& getSeats() {
        return seats;
    }

    int getScreenNumber() {
        return screenNumber;
    }
};
