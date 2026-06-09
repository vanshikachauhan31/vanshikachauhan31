#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function for Registration
void registerUser() {
    string username, password;
    string fileUser, filePass;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Check for duplicate username
    ifstream infile("users.txt");
    while (infile >> fileUser >> filePass) {
        if (username == fileUser) {
            cout << "Registration Failed! Username already exists." << endl;
            infile.close();
            return;
        }
    }
    infile.close();

    // Store new user
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration Successful!" << endl;
}

// Function for Login
void loginUser() {
    string username, password;
    string fileUser, filePass;
    bool found = false;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");

    if (!infile) {
        cout << "No registered users found." << endl;
        return;
    }

    while (infile >> fileUser >> filePass) {
        if (username == fileUser && password == filePass) {
            found = true;
            break;
        }
    }
    infile.close();

    if (found)
        cout << "Login Successful!" << endl;
    else
        cout << "Invalid Username or Password!" << endl;
}

int main() {
    int choice;

    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid Choice!" << endl;
    }

    return 0;
}