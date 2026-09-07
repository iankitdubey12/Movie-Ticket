class Show {
private:
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(Movie* movie, Screen* screen, string startTime) {
        this->movie = movie;
        this->screen = screen;
        this->startTime = startTime;

        for (Seat& seat : screen->getSeats()) {
            showSeats.push_back(ShowSeat(&seat));
        }
    }

    Movie* getMovie() { return movie; }
    Screen* getScreen() { return screen; }
    string getStartTime() { return startTime; }

    vector<ShowSeat>& getShowSeats() {
        return showSeats;
    }

    void displaySeats() {
        for (ShowSeat& s : showSeats) {
            cout << "Seat " << s.getSeat()->getSeatNumber() << " - ";

            if (s.getSeat()->getType() == SILVER)
                cout << "SILVER - ";
            else if (s.getSeat()->getType() == GOLD)
                cout << "GOLD - ";
            else
                cout << "PLATINUM - ";

            cout << (s.isAvailable() ? "AVAILABLE" : "BOOKED") << endl;
        }
    }
};
