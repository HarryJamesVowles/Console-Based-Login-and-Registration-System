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



// FUNCTION: Register User
void registerUser() {
    string username, password;
    

	// While True: username in users -> try again.
    while (true) {
        cout << "--- REGISTRATION ---" << endl;
        cout << "Enter new username: ";    cin >> username;

        // If user exists -> print error
        if (users.count(username)) {
            cout << "Error: User already exists!" << endl;
            cout << "Please try again." << endl;
            continue;
        }
        break;
    }
    // While True: Ask for password, Ask for password again -> if match, break.
    while (true) {
        cout << "Enter password: ";    cin >> password;
        cout << "Re-enter password: ";    string password2;    cin >> password2;
        if (password != password2) {
            cout << "Error: Passwords do not match! Please try again." << endl;
            continue;
        }
		// If passwords match -> insert into map, print success.
		users[username] = password;
		cout << "User registered successfully!" << endl;
        break;
    }
}


// FUNCTION: Login User
void loginUser() {
    string username, password;

    //  While True: Check if username and password match database
    while (true) {
	    // Ask for username and password
        cout << "--- LOGIN ---" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;


        // Validate Credentials -> print success or error.
        if (users.count(username)) {
            if (users[username] == password) {
                cout << "Login Successful!" << endl;
				break;
            }
            else {
                cout << "Wrong Password!" << endl;
				cout << "Please try again." << endl;
				continue;
            }
        }
        else {
            cout << "User not found!" << endl;
			cout << "Please try again." << endl;
		    continue;
        }
    }
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
