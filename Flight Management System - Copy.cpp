#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <limits>
#include <cstring>

using namespace std;

const char l_destination[5][20] = {"LAHORE", "ISLAMABAD", "KARACHI", "PESHAWAR", "QUETTA"};
const char i_destination[11][20] = {"LONDON", "BERLIN", "DUBAI", "RIYADH", "BEIJING", "PARIS", "CANBERRA", "TOKYO", "WASHINGTON", "DELHI", "ISLAMABAD"}; // International Destination

class Entity {
public:
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void report() = 0;
    virtual ~Entity() = default; // Virtual destructor for proper cleanup
};

class Passenger : public Entity {
protected:
    string firstname, lastname, phone, mealtype, passport, address;
    int bus, eco, datedep, payment;
    char origin[30];
    char destination[30];
public:
    Passenger(string f_name, string l_name, string phone_no, string add = "N/A", string pass_no = "N/A", int dd = 0)
        : bus(50), eco(250), datedep(dd), firstname(f_name), lastname(l_name), address(add), phone(phone_no), passport(pass_no) {}

    virtual bool ldest() = 0;
    virtual bool idest(string pass) = 0;
    virtual void seats() = 0;
    virtual void meals() = 0;
    virtual void registration() = 0;
    virtual bool display() = 0;
    virtual void drive() = 0;

    void add() override {
        // Implementation to add a passenger
    }

    void remove() override {
        // Implementation to remove a passenger
    }

    void report() override {
        // Implementation to report passenger details
    }
};

class Booking : public Passenger {
public:
    Booking(string f, string l, string num, string add, string pass, int dd)
        : Passenger(f, l, num, add, pass, dd) {}

    bool ldest() override {
        cout << "Available Local Destinations:" << endl;
        for (const auto& dest : l_destination) {
            cout << dest << endl;
        }
        cout << "Enter destination: ";
        cin.ignore();
        cin.getline(destination, 30);
        for (const auto& dest : l_destination) {
            if (strcmp(destination, dest) == 0) return true;
        }
        return false;
    }

    bool idest(string pass) override {
        cout << "Available International Destinations:" << endl;
        for (const auto& dest : i_destination) {
            cout << dest << endl;
        }
        cout << "Enter destination: ";
        cin.ignore();
        cin.getline(destination, 30);
        for (const auto& dest : i_destination) {
            if (strcmp(destination, dest) == 0) return true;
        }
        return false;
    }

    void seats() override {
        cout << "Booking seat..." << endl;
        // Implementation for seat booking
    }

    void meals() override {
        cout << "Selecting meal..." << endl;
        // Implementation for meal selection
    }

    void registration() override {
        cout << "Registering..." << endl;
        // Implementation for registration
    }

    bool display() override {
        cout << "Displaying booking details..." << endl;
        // Implementation for displaying booking details
        return true;
    }

    void drive() override {
        cout << "Driving option selected..." << endl;
        // Implementation for drive option
    }
};

class Plane : public Entity {
    string serial_number;
    int seats;
    string manufacture_date;
public:
    Plane(string sn, int s, string md) : serial_number(sn), seats(s), manufacture_date(md) {}

    void add() override {
        cout << "Adding Plane..." << endl;
        // Implementation to add a plane
    }

    void remove() override {
        cout << "Removing Plane..." << endl;
        // Implementation to remove a plane
    }

    void report() override {
        cout << "Reporting Plane..." << endl;
        // Implementation to report plane details
    }
};

class Flight : public Entity {
    string flight_number;
    string plane_serial;
    string origin;
    string destination;
    string flight_date;
    string flight_time;
    int passenger_count;
    string pilot_id;
    vector<string> attendants;
public:
    Flight(string fn, string ps, string o, string d, string fd, string ft, int pc, string pid, vector<string> att)
        : flight_number(fn), plane_serial(ps), origin(o), destination(d), flight_date(fd), flight_time(ft), passenger_count(pc), pilot_id(pid), attendants(att) {}

    void add() override {
        cout << "Adding Flight..." << endl;
        // Implementation to add a flight
    }

    void remove() override {
        cout << "Removing Flight..." << endl;
        // Implementation to remove a flight
    }

    void report() override {
        cout << "Reporting Flight..." << endl;
        // Implementation to report flight details
    }
};

class Pilot : public Entity {
    string national_id;
    string personnel_id;
    string name;
    string surname;
    string birth_date;
    string hire_date;
    string rank;
public:
    Pilot(string nid, string pid, string n, string s, string bd, string hd, string r)
        : national_id(nid), personnel_id(pid), name(n), surname(s), birth_date(bd), hire_date(hd), rank(r) {}

    void add() override {
        cout << "Adding Pilot..." << endl;
        // Implementation to add a pilot
    }

    void remove() override {
        cout << "Removing Pilot..." << endl;
        // Implementation to remove a pilot
    }

    void report() override {
        cout << "Reporting Pilot..." << endl;
        // Implementation to report pilot details
    }
};

class Attendant : public Entity {
    string national_id;
    string personnel_id;
    string name;
    string surname;
    string birth_date;
    string hire_date;
public:
    Attendant(string nid, string pid, string n, string s, string bd, string hd)
        : national_id(nid), personnel_id(pid), name(n), surname(s), birth_date(bd), hire_date(hd) {}

    void add() override {
        cout << "Adding Attendant..." << endl;
        // Implementation to add an attendant
    }

    void remove() override {
        cout << "Removing Attendant..." << endl;
        // Implementation to remove an attendant
    }

    void report() override {
        cout << "Reporting Attendant..." << endl;
        // Implementation to report attendant details
    }
};

class CargoVehicle : public Entity {
    string serial;
    string manufacture_date;
public:
    CargoVehicle(string s, string md) : serial(s), manufacture_date(md) {}

    void add() override {
        cout << "Adding Cargo Vehicle..." << endl;
        // Implementation to add a cargo vehicle
    }

    void remove() override {
        cout << "Removing Cargo Vehicle..." << endl;
        // Implementation to remove a cargo vehicle
    }

    void report() override {
        cout << "Reporting Cargo Vehicle..." << endl;
        // Implementation to report cargo vehicle details
    }
};

class Manage {
private:
    string temp, y, c2;
    int option;
public:
    int change() {
        ifstream file("flight.txt");
        if (file.is_open()) {
            cout << endl << "Enter your Ticket Number or Press 0 to exit\nTicket Number: ";
            cin >> temp;
            if (temp == "0")
                return 1;
            string v("Ticket: " + temp);
            while (getline(file, y)) {
                if (y == v) {
                    file.seekg(0, ios::beg);
                    while (getline(file, temp)) {
                        cout << temp << endl;
                    }
                    cout << endl << endl << "1. Change date\n2. Cancel the flight\n3. Go Back\n";
                    cin >> option;
                    switch (option) {
                        case 1:
                            // Change date implementation
                            break;
                        case 2:
                            // Cancel flight implementation
                            break;
                        case 3:
                            // Go back implementation
                            break;
                        default:
                            cout << "Invalid option. Try again.";
                            break;
                    }
                    return 0;
                }
            }
        } else {
            cout << endl << endl << "Unable to find any record" << endl;
            cout << endl << "Going back to main page\n\n";
            return 1;
        }
        return 1;
    }
};

class About {
public:
    void aboutUs() {
        cout << "The height of skies was first touched by our airline in 1969. Since then,\nHigh Fly is the world's leading airline with 4 biggest airplanes.\nWe are at the customers high service in cuisine, comfort and care.\nSo make a plan and fly high with High Fly." << endl << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }
};

class Complain {
private:
    string f_name, l_name, p_num;
    int choice;
    string sentence;
    string types;
    char ch;
public:
    Complain(string f, string l, string num) : f_name(f), l_name(l), p_num(num) {}

    void type() {
        while (true) {
            cout << endl << endl << "Enter the type of complain you want to register:\n1. Airport Handling\n2. Baggage Delivery\n3. Booking and ticketing\n4. Other\n";
            cin >> choice;
            cin.ignore();
            cout << "Enter your complain:\n";
            switch (choice) {
                case 1: types = "Airport Handling: "; break;
                case 2: types = "Baggage Delivery: "; break;
                case 3: types = "Booking and Ticketing: "; break;
                case 4: types = "Other: "; break;
                default: cout << "Invalid choice. Try again."; continue;
            }
            cout << types;
            getline(cin, sentence);
            cout << endl << "Do you want to edit your complain (y/n): ";
            cin >> ch;
            if (ch == 'N' || ch == 'n') {
                cout << endl << "Complain noted!\n";
                ofstream outfile("complain.txt", ios::app);
                outfile << "Name: " << f_name << " " << l_name << endl
                        << "Phone: " << p_num << endl
                        << "Complain:\n" << types << sentence << endl;
                outfile.close();
                this_thread::sleep_for(chrono::seconds(3));
                break;
            }
        }
    }
};

class Routes {
public:
    bool print() {
        cout << "\n\n\n\n\tFollowing are the international flights available" << endl;
        for (int i = 0; i < 11; i++) {
            cout << endl;
            for (int j = 0; j < 11; j++) {
                if (i != j) {
                    cout << "Flight from " << i_destination[i] << " to " << i_destination[j] << endl;
                }
            }
        }
        cout << "\n\n\n\n\tFollowing are the local flights available" << endl;
        for (int i = 0; i < 5; i++) {
            cout << endl;
            for (int j = 0; j < 5; j++) {
                if (i != j) {
                    cout << "Flight from " << l_destination[i] << " to " << l_destination[j] << endl;
                }
            }
        }
        cout << endl << "Do you want to book a flight (y/n) ";
        char ch;
        cin >> ch;
        return (ch == 'Y' || ch == 'y');
    }
};

void add_entity(Entity* entity) {
    entity->add();
}

void remove_entity(Entity* entity) {
    entity->remove();
}

void report_entity(Entity* entity) {
    entity->report();
}

int main() {
    system("COLOR 5f");
    cout << endl << "\n\n\n\tWelcome to HIGH FLY Airline" << endl;
    string f_name, l_name, add, pass_no, phone_no;
    int choice, datedep, date, month, year;
    bool ans;
    char ch;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    date = timePtr->tm_mday;
    month = timePtr->tm_mon + 1;
    year = timePtr->tm_year + 1900;

    while (true) {
        cout << endl << "Press 1 for Booking"
             << endl << "Press 2 for Routes"
             << endl << "Press 3 for Complaint"
             << endl << "Press 4 for About"
             << endl << "Press 5 for Manage"
             << endl << "Press 6 to Add Entity"
             << endl << "Press 7 to Remove Entity"
             << endl << "Press 8 for Report"
             << endl << "Press 0 for Exit\n";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1: {
                cout << ">>>>>>>>>>BOOKING<<<<<<<<<<\n";
                Passenger* ptr;
                cout << "Enter Your First Name: ";
                cin >> f_name;
                cin.ignore();
                cout << "Enter Your Last Name: ";
                getline(cin, l_name);
                cout << "Enter Your Address (Using Commas only): ";
                getline(cin, add);
                cout << "Enter Your Phone Num (Without -): ";
                cin >> phone_no;
                cout << "Enter date of departure (DDMMYYYY): ";
                cin >> datedep;
                Booking obj1(f_name, l_name, phone_no, add, pass_no, datedep);
                ptr = &obj1;
                while (true) {
                    cout << endl << "1. Local Destination\n2. International Destination\n3. Back\n4. Exit\n";
                    cin >> choice;
                    if (choice == 1) {
                        if (!ptr->ldest()) {
                            cout << endl << "We do not fly to this place\nPlease Choose again\n";
                        } else {
                            cout << endl << "Yes we do fly\n";
                            ptr->seats();
                            ptr->meals();
                            ptr->registration();
                            system("cls");
                            if (!ptr->display()) {
                                system("cls");
                                break;
                            } else {
                                cout << endl << "Thanks for Flying With Us" << endl << endl
                                     << "Would you like to avail our Pick'n Drop facility? (y/n)";
                                cin >> ch;
                                if (ch == 'y' || ch == 'Y') {
                                    ptr->drive();
                                } else if (ch == 'n' || ch == 'N') {
                                    ofstream ofile("flight.txt", ios::app);
                                    ofile << endl << endl << "Pick'n Drop: NO";
                                    ofile.close();
                                }
                                cin.ignore();
                                cin.get();
                                system("cls");
                                break;
                            }
                        }
                    } else if (choice == 2) {
                        cout << endl << "Enter Your Passport Num (Without \"-\"): ";
                        cin >> pass_no;
                        if (!ptr->idest(pass_no)) {
                            cout << endl << "We do not fly to this place\n";
                        } else {
                            cout << endl << "Yes we do fly\n";
                            ptr->seats();
                            ptr->meals();
                            ptr->registration();
                            system("cls");
                            if (!ptr->display()) {
                                system("cls");
                                break;
                            } else {
                                cout << endl << "Thanks for Flying With Us" << endl << endl
                                     << "Would you like to avail our Pick'n Drop facility? (y/n)";
                                cin >> ch;
                                if (ch == 'y' || ch == 'Y') {
                                    ptr->drive();
                                } else if (ch == 'n' || ch == 'N') {
                                    ofstream ofile("flight.txt", ios::app);
                                    ofile << endl << endl << "Pick'n Drop: NO";
                                    ofile.close();
                                }
                                cin.ignore();
                                cin.get();
                                system("cls");
                                break;
                            }
                        }
                    } else if (choice == 3) {
                        system("cls");
                        break;
                    } else {
                        exit(0);
                    }
                }
                break;
            }
            case 2: {
                cout << ">>>>>>>>>>ROUTES<<<<<<<<<<\n";
                Routes obj;
                ans = obj.print();
                if (ans) continue;
                else {
                    cout << endl;
                    system("cls");
                }
                break;
            }
            case 3: {
                cout << ">>>>>>>>>>COMPLAINT<<<<<<<<<<\n";
                cout << "Enter Your First Name: ";
                cin >> f_name;
                cin.ignore();
                cout << "Enter Your Last Name: ";
                getline(cin, l_name);
                cout << "Enter Your Phone Num (Without -): ";
                cin >> phone_no;
                Complain obj(f_name, l_name, phone_no);
                obj.type();
                system("cls");
                break;
            }
            case 4: {
                cout << "\t\t>>>>>>>>>>ABOUT US<<<<<<<<<<\n";
                About obj;
                obj.aboutUs();
                system("cls");
                break;
            }
            case 5: {
                cout << ">>>>>>>>>>MANAGE<<<<<<<<<<\n";
                Manage pass;
                if (pass.change() == 1) {
                    this_thread::sleep_for(chrono::seconds(2));
                    system("cls");
                }
                break;
            }
            case 6: {
                cout << ">>>>>>>>>ADD ENTITY<<<<<<<<<\n";
                int entity_choice;
                cout << "Select entity to add:\n1. Plane\n2. Flight\n3. Pilot\n4. Attendant\n5. Cargo Vehicle\n";
                cin >> entity_choice;
                switch (entity_choice) {
                    case 1: {
                        string sn, md;
                        int seats;
                        cout << "Enter Serial Number: ";
                        cin >> sn;
                        cout << "Enter Number of Seats: ";
                        cin >> seats;
                        cout << "Enter Manufacture Date: ";
                        cin >> md;
                        Plane plane(sn, seats, md);
                        add_entity(&plane);
                        break;
                    }
                    case 2: {
                        string fn, ps, o, d, fd, ft, pid;
                        int pc;
                        vector<string> att;
                        string temp;
                        cout << "Enter Flight Number: ";
                        cin >> fn;
                        cout << "Enter Plane Serial: ";
                        cin >> ps;
                        cout << "Enter Origin: ";
                        cin >> o;
                        cout << "Enter Destination: ";
                        cin >> d;
                        cout << "Enter Flight Date: ";
                        cin >> fd;
                        cout << "Enter Flight Time: ";
                        cin >> ft;
                        cout << "Enter Passenger Count: ";
                        cin >> pc;
                        cout << "Enter Pilot ID: ";
                        cin >> pid;
                        cout << "Enter Attendants (enter 'done' to stop): ";
                        while (cin >> temp && temp != "done") {
                            att.push_back(temp);
                        }
                        Flight flight(fn, ps, o, d, fd, ft, pc, pid, att);
                        add_entity(&flight);
                        break;
                    }
                    case 3: {
                        string nid, pid, n, s, bd, hd, r;
                        cout << "Enter National ID: ";
                        cin >> nid;
                        cout << "Enter Personnel ID: ";
                        cin >> pid;
                        cout << "Enter Name: ";
                        cin >> n;
                        cout << "Enter Surname: ";
                        cin >> s;
                        cout << "Enter Birth Date: ";
                        cin >> bd;
                        cout << "Enter Hire Date: ";
                        cin >> hd;
                        cout << "Enter Rank: ";
                        cin >> r;
                        Pilot pilot(nid, pid, n, s, bd, hd, r);
                        add_entity(&pilot);
                        break;
                    }
                    case 4: {
                        string nid, pid, n, s, bd, hd;
                        cout << "Enter National ID: ";
                        cin >> nid;
                        cout << "Enter Personnel ID: ";
                        cin >> pid;
                        cout << "Enter Name: ";
                        cin >> n;
                        cout << "Enter Surname: ";
                        cin >> s;
                        cout << "Enter Birth Date: ";
                        cin >> bd;
                        cout << "Enter Hire Date: ";
                        cin >> hd;
                        Attendant attendant(nid, pid, n, s, bd, hd);
                        add_entity(&attendant);
                        break;
                    }
                    case 5: {
                        string s, md;
                        cout << "Enter Serial: ";
                        cin >> s;
                        cout << "Enter Manufacture Date: ";
                        cin >> md;
                        CargoVehicle cargoVehicle(s, md);
                        add_entity(&cargoVehicle);
                        break;
                    }
                    default:
                        cout << "Invalid choice. Try again.";
                        break;
                }
                system("cls");
                break;
            }
            case 7: {
                cout << ">>>>>>>>>REMOVE ENTITY<<<<<<<<<\n";
                int entity_choice;
                cout << "Select entity to remove:\n1. Plane\n2. Flight\n3. Pilot\n4. Attendant\n5. Cargo Vehicle\n";
                cin >> entity_choice;
                switch (entity_choice) {
                    case 1: {
                        Plane plane("", 0, "");
                        remove_entity(&plane);
                        break;
                    }
                    case 2: {
                        Flight flight("", "", "", "", "", "", 0, "", {});
                        remove_entity(&flight);
                        break;
                    }
                    case 3: {
                        Pilot pilot("", "", "", "", "", "", "");
                        remove_entity(&pilot);
                        break;
                    }
                    case 4: {
                        Attendant attendant("", "", "", "", "", "");
                        remove_entity(&attendant);
                        break;
                    }
                    case 5: {
                        CargoVehicle cargoVehicle("", "");
                        remove_entity(&cargoVehicle);
                        break;
                    }
                    default:
                        cout << "Invalid choice. Try again.";
                        break;
                }
                system("cls");
                break;
            }
            case 8: {
                cout << ">>>>>>>>>REPORT ENTITY<<<<<<<<<\n";
                int entity_choice;
                cout << "Select entity to report:\n1. Plane\n2. Flight\n3. Pilot\n4. Attendant\n5. Cargo Vehicle\n";
                cin >> entity_choice;
                switch (entity_choice) {
                    case 1: {
                        Plane plane("", 0, "");
                        report_entity(&plane);
                        break;
                    }
                    case 2: {
                        Flight flight("", "", "", "", "", "", 0, "", {});
                        report_entity(&flight);
                        break;
                    }
                    case 3: {
                        Pilot pilot("", "", "", "", "", "", "");
                        report_entity(&pilot);
                        break;
                    }
                    case 4: {
                        Attendant attendant("", "", "", "", "", "");
                        report_entity(&attendant);
                        break;
                    }
                    case 5: {
                        CargoVehicle cargoVehicle("", "");
                        report_entity(&cargoVehicle);
                        break;
                    }
                    default:
                        cout << "Invalid choice. Try again.";
                        break;
                }
                system("cls");
                break;
            }
            case 0:
                exit(0);
            default:
                cout << endl << endl << "ERROR!!!";
                break;
        }
    }
    return 0;
}

bool datecheck(int datedep, int date, int month, int year) {
    if ((datedep % 10000) > 2017 && (datedep % 10000) == year) {
        if (((datedep / 10000) % 100) > 0 && ((datedep / 10000) % 100) < 13 && ((datedep / 10000) % 100) == month) {
            if ((datedep / 1000000) > 0 && (datedep / 1000000) < 32 && (datedep / 1000000) > date && (datedep / 1000000) < (date + 20)) {
                return true;
            }
        }
    }
    return false;
}
