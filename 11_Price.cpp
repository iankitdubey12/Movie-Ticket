class Price {
public:
    double calculateTotal(vector<ShowSeat*>& seats) {
        double total = 0;

        for (ShowSeat* seat : seats)
            total += seat->getSeat()->getPrice();

        return total;
    }
};
