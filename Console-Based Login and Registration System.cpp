#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>    // For file saving/loading
#include <functional> // For password hashing
#include <limits> // To discard invalid input from cin
using namespace std;

// GLOBAL DATABASE
unordered_map<string, string> users;
const string DB_FILE = "users.txt"; // The file name

// FUNCTION: Hash Password (simple example, not secure for real applications)
string hashPassword(const string& password) {
	hash<string> hasher; // Standard hash -> called hasher
	size_t hashed = hasher(password);
	return to_string(hashed); // Convert to string
}

// FUNCTION: Save Database to file
void saveDatabase() {
	ofstream outfile(DB_FILE); // Open file for writing
	for (const auto& pair : users) { // Iterate through map
        outfile << pair.first << " " << pair.second << endl;
    }
    outfile.close();
}
// FUNCTION: Load Database from file
void loadDatabase() {
	ifstream infile(DB_FILE); // Open file for reading
	if (!infile.is_open()) { // If file doesn't exist
        cout << "No existing database found. Starting fresh." << endl;
        return;
    }
    string username, hashedPassword;
    while (infile >> username >> hashedPassword) {
		users[username] = hashedPassword; // Load into map
    }
    infile.close();
}

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
        users[username] = hashPassword(password);
		cout << "User registered successfully!" << endl;
		saveDatabase(); // Save database after registration
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
        auto it = users.find(username);
        if (it != users.end()) {
            // Compare stored hashed password with hash of entered password
            if (it->second == hashPassword(password)) {
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



// MAIN FUNCTION
int main() {
	loadDatabase(); // Load database at start
    int choice = 0;

    // While loop keeps program running until user types 3
    while (choice != 3) {
        cout << "\n---------------------" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

		// Input validation -> if cin fails, clear and ignore invalid input. (suggested by Google Gemini)
		if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input, please enter a number." << endl;
            continue;
        }

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
