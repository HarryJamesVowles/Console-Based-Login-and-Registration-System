#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// ---------------------------------------------------------
// GLOBAL DATABASE
// We use a global map so both functions can access it easily.
// Key = Username (string), Value = Password (string)
// ---------------------------------------------------------
unordered_map<string, string> users;


// ---------------------------------------------------------
// FUNCTION: Register User
// Goal: Add a new user if they don't exist yet.
// ---------------------------------------------------------
void registerUser() {
    string username, password;

    cout << "--- REGISTRATION ---" << endl;
    cout << "Enter new username: ";
    cin >> username;

    // TODO STEP 1: Check if username already exists
    // Hint: Use if (users.count(username)) ...

        // If true: Print "Error: User already exists!"


    // TODO STEP 2: If user does NOT exist
    // 1. Ask for password ( cout << "Enter password: "; cin >> password; )
    // 2. Insert into map ( users[username] = password; )
    // 3. Print "User registered successfully!"

}


// ---------------------------------------------------------
// FUNCTION: Login User
// Goal: Authenticate a user.
// ---------------------------------------------------------
void loginUser() {
    string username, password;

    cout << "--- LOGIN ---" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // TODO STEP 3: Validate Credentials
    // Logic:
    // 1. Check if user exists (using .count() or .find())
    // 2. IF they exist, Check if users[username] matches the input password.

    // Hint:
    // if (users.count(username)) {
    //      if (users[username] == password) {
    //          print "Login Successful!"
    //      } else {
    //          print "Wrong Password!"
    //      }
    // } else {
    //      print "User not found!"
    // }
}


// ---------------------------------------------------------
// MAIN FUNCTION
// This runs the loop. You don't need to change this much.
// ---------------------------------------------------------
int main() {
    int choice = 0;

    // While loop keeps program running until user types 3
    while (choice != 3) {
        cout << "\n---------------------" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}
