class Controller {
private:
    Price price;
    Ticket ticket;
    vector<Booking> bookings;

public:
    Booking* bookTicket(Customer* customer, Show* show,
                        vector<int> seatNumbers, Payment* payment) {
        vector<ShowSeat*> selected;
        vector<ShowSeat>& showSeats = show->getShowSeats();

        for (int number : seatNumbers) {
            ShowSeat* found = nullptr;

            for (ShowSeat& seat : showSeats) {
                if (seat.getSeat()->getSeatNumber() == number) {
                    found = &seat;
                    break;
                }
            }

            if (found == nullptr) {
                cout << "Invalid seat number. Booking rejected." << endl;
                return nullptr;
            }

            for (ShowSeat* selectedSeat : selected) {
                if (selectedSeat == found) {
                    cout << "Duplicate seat selected. Booking rejected." << endl;
                    return nullptr;
                }
            }

            selected.push_back(found);
        }

        for (ShowSeat* seat : selected) {
            if (!seat->isAvailable()) {
                cout << "One or more selected seats are already BOOKED." << endl;
                cout << "Booking rejected." << endl;
                return nullptr;
            }
        }

        double amount = price.calculateTotal(selected);

        bookings.emplace_back(customer, show, selected, amount);
        Booking* booking = &bookings.back();

        if (!payment->pay(amount)) {
            booking->fail();
            cout << "Payment failed." << endl;
            cout << "Seats released." << endl;
            cout << "Booking FAILED." << endl;
            return booking;
        }

        for (ShowSeat* seat : selected)
            seat->book();

        booking->confirm();

        cout << "Payment successful." << endl;
        cout << "Booking confirmed." << endl;

        ticket.print(booking);
        return booking;
    }

    void cancelBooking(int bookingId) {
        for (Booking& booking : bookings) {
            if (booking.getBookingId() == bookingId) {
                if (booking.getStatus() != CONFIRMED) {
                    cout << "Only CONFIRMED bookings can be cancelled." << endl;
                    return;
                }

                for (ShowSeat* seat : booking.getSeats())
                    seat->release();

                booking.cancel();

                cout << "Booking cancelled." << endl;
                cout << "Seats are AVAILABLE." << endl;
                return;
            }
        }

        cout << "Booking ID not found." << endl;
    }
};
