#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "06_ShowSeat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "11_Price.cpp"
#include "12_Ticket.cpp"
#include "13_Controller.cpp"

int main() {
    Cinema cinema("City Cinema");

    Screen screen1(1);
    screen1.addSeat(Seat(1, SILVER));
    screen1.addSeat(Seat(2, SILVER));
    screen1.addSeat(Seat(3, GOLD));
    screen1.addSeat(Seat(4, GOLD));
    screen1.addSeat(Seat(5, PLATINUM));

    Screen screen2(2);
    screen2.addSeat(Seat(1, SILVER));
    screen2.addSeat(Seat(2, GOLD));
    screen2.addSeat(Seat(3, GOLD));
    screen2.addSeat(Seat(4, PLATINUM));
    screen2.addSeat(Seat(5, PLATINUM));

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    vector<Movie> movies;
    movies.emplace_back("Spiderman- Brand New Day", "English", 180);
    movies.emplace_back("3 Idiots", "Hindi", 170);
    movies.emplace_back("RaOne", "Hindi", 180);
    movies.emplace_back("Bahubali", "Telugu", 160);

    vector<Show> shows;
    shows.emplace_back(&movies[0], &cinema.getScreens()[0], "6:00 PM");
    shows.emplace_back(&movies[0], &cinema.getScreens()[0], "9:00 PM");
    shows.emplace_back(&movies[1], &cinema.getScreens()[1], "5:00 PM");
    shows.emplace_back(&movies[1], &cinema.getScreens()[1], "8:00 PM");

    Customer customer("Customer", "0000000000");
    Controller controller;

    int choice;

    do {
        cout << endl;
        cout << "===== MOVIE TICKET BOOKING SYSTEM =====" << endl;
        cout << "1. Movie Listing" << endl;
        cout << "2. Show Listing" << endl;
        cout << "3. Seat Display" << endl;
        cout << "4. Book Ticket" << endl;
        cout << "5. Cancel Booking" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << endl << "Movies:" << endl;

            for (int i = 0; i < (int)movies.size(); i++) {
                cout << i + 1 << ". "
                     << movies[i].getTitle() << " | "
                     << movies[i].getLanguage() << " | "
                     << movies[i].getDuration() << " min" << endl;
            }
        }

        else if (choice == 2) {
            int movieChoice;

            cout << endl << "Select Movie:" << endl;

            for (int i = 0; i < (int)movies.size(); i++)
                cout << i + 1 << ". " << movies[i].getTitle() << endl;

            cout << "Enter choice: ";
            cin >> movieChoice;

            if (movieChoice < 1 || movieChoice > (int)movies.size()) {
                cout << "Invalid movie choice." << endl;
                continue;
            }

            for (int i = 0; i < (int)shows.size(); i++) {
                if (shows[i].getMovie() == &movies[movieChoice - 1]) {
                    cout << i + 1 << ". Screen "
                         << shows[i].getScreen()->getScreenNumber()
                         << " | " << shows[i].getStartTime() << endl;
                }
            }
        }

        else if (choice == 3) {
            int showChoice;

            cout << endl << "Shows:" << endl;

            for (int i = 0; i < (int)shows.size(); i++) {
                cout << i + 1 << ". "
                     << shows[i].getMovie()->getTitle()
                     << " | Screen "
                     << shows[i].getScreen()->getScreenNumber()
                     << " | " << shows[i].getStartTime() << endl;
            }

            cout << "Enter show number: ";
            cin >> showChoice;

            if (showChoice < 1 || showChoice > (int)shows.size()) {
                cout << "Invalid show choice." << endl;
                continue;
            }

            shows[showChoice - 1].displaySeats();
        }

        else if (choice == 4) {
            int showChoice, count;

            cout << endl << "Shows:" << endl;

            for (int i = 0; i < (int)shows.size(); i++) {
                cout << i + 1 << ". "
                     << shows[i].getMovie()->getTitle()
                     << " | Screen "
                     << shows[i].getScreen()->getScreenNumber()
                     << " | " << shows[i].getStartTime() << endl;
            }

            cout << "Enter show number: ";
            cin >> showChoice;

            if (showChoice < 1 || showChoice > (int)shows.size()) {
                cout << "Invalid show choice." << endl;
                continue;
            }

            cout << "Enter number of seats: ";
            cin >> count;

            if (count < 1 ||
                count > (int)shows[showChoice - 1].getShowSeats().size()) {
                cout << "Invalid number of seats." << endl;
                continue;
            }

            vector<int> seatNumbers(count);

            cout << "Enter seat numbers: ";
            for (int& number : seatNumbers)
                cin >> number;

            int paymentChoice;

            cout << "1. UPI" << endl;
            cout << "2. Card" << endl;
            cout << "3. Cash" << endl;
            cout << "Enter payment method: ";
            cin >> paymentChoice;

            Payment* payment = nullptr;

            UpiPayment upi;
            CardPayment card;
            CashPayment cash;

            if (paymentChoice == 1)
                payment = &upi;
            else if (paymentChoice == 2)
                payment = &card;
            else if (paymentChoice == 3)
                payment = &cash;
            else {
                cout << "Invalid payment method." << endl;
                continue;
            }

            controller.bookTicket(
                &customer,
                &shows[showChoice - 1],
                seatNumbers,
                payment
            );
        }

        else if (choice == 5) {
            int bookingId;

            cout << "Enter booking ID: ";
            cin >> bookingId;

            controller.cancelBooking(bookingId);
        }

        else if (choice == 6) {
            cout << "Exiting..." << endl;
        }

        else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}
