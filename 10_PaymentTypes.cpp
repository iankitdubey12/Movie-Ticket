class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        int choice;
        cout << "UPI Payment: Rs." << amount << endl;
        cout << "1. Successful Payment" << endl;
        cout << "2. Failed Payment" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        return choice == 1;
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        int choice;
        cout << "Card Payment: Rs." << amount << endl;
        cout << "1. Successful Payment" << endl;
        cout << "2. Failed Payment" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        return choice == 1;
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        int choice;
        cout << "Cash Payment: Rs." << amount << endl;
        cout << "1. Successful Payment" << endl;
        cout << "2. Failed Payment" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        return choice == 1;
    }
};
