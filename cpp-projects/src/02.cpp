// Copyright 2024 Arnaldo Lopes. All Rights Reserved.

/*
  File: 02.cpp
  Author: Arnaldo Lopes
  Date: [Insert Date]

  Description:
  This C++ program implements a simple banking system using a class
  (BankAccount) to manage user accounts. Users can create accounts, deposit and
  withdraw funds, and display their account information. User data is stored in
  a text file ("bankAccounts.txt"). The program provides a command-line
  interface for users to interact with their accounts.

  How to Compile and Run:
  Compile using the following command:
  $ g++ 02.cpp -o builds/02 && ./builds/02

  Notes:
  - This program is designed for educational purposes and may not include
  advanced security features.
  - Ensure proper input validation and error handling for real-world
  applications.

  TODO: Error Handling/Input Validation;
  Function Modularity;
  Remove hard-coding (the menu options for instance);
  Find a better way to clear the screen:
  (system("clear") only works on linux);
  Improve file operations (consider using smart pointers);
  Separate Bank Logic from menu UI:
  (create a class for the menu);

*/

#include <fstream>
#include <iostream>
#include <string>

class BankAccount {
 private:
  const std::string name;
  const std::string fileName = "bankAccounts.txt";
  double balance;

 public:
  // Constructor to initialize the BankAccount object
  explicit BankAccount(std::string accountName) : name(accountName) {
    if (!getUser()) {
      createUser();
    }
  }

  // Function to create user information in the file
  void createUser() {
    // Open the file in append mode
    std::ofstream file(fileName, std::ios::app);
    double initialDeposit;
    bool isValid = false;

    while (!isValid) {
      std::cout << "Enter initial deposit: ";
      if (std::cin >> initialDeposit && initialDeposit >= 0) {
        isValid = true;
      } else {
        system("clear");
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid amout." << std::endl;
      }
    }

    balance = initialDeposit;
    // Write user information to the file
    file << name << " " << balance << std::endl;

    // Close the file
    file.close();
  }

  // Function to update user information in the file
  void updateFile() {
    // Create a temporary file
    std::ofstream tempFile("temp.txt");

    std::ifstream file(fileName);
    std::string accountName;
    double initialBalance;

    // Iterate through each line in the file
    while (file >> accountName >> initialBalance) {
      // Check if the current line cointains the desired accountName
      if (name == accountName) {
        tempFile << name << " " << balance << std::endl;
      } else {
        // Write the remaining data to the temporary file
        tempFile << accountName << " " << initialBalance << std::endl;
      }
    }

    // Close the files
    file.close();
    tempFile.close();

    // Replace the original file with the temporary file
    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());
  }

  // Function to retrieve user information from the file
  bool getUser() {
    // Open the file for reading
    std::ifstream file(fileName);
    std::string accountName;
    double initialBalance;

    // Iterate through each line in the file
    while (file >> accountName >> initialBalance) {
      // Check if the current line contains the desired user's name
      if (accountName == name) {
        balance = initialBalance;
        return true;
      }
    }

    // Close the file
    file.close();

    return false;
  }

  // Function to deposit money into the account
  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      updateFile();
    } else {
      std::cout << "Invalid amount." << std::endl;
    }
  }

  // Function to withdraw money from the account
  void withdraw(double amount) {
    if (amount <= 0) {
      std::cout << "Invalid amount." << std::endl;
    } else if (amount <= balance) {
      balance -= amount;
      updateFile();
    } else {
      std::cout << "Insufficient funds." << std::endl;
    }
  }

  // Function to display account information
  void display() {
    std::cout << "Account: " << name << "\nBalance: $" << balance << std::endl;
  }
};

int main() {
  std::string name;

  std::cout << "Enter your name: ";
  getline(std::cin, name);
  system("clear");

  BankAccount account(name);

  int choice;
  double amount;
  bool exited = false;

  while (!exited) {
    std::cout << "\n1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Display Account" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        system("clear");
        std::cout << "Enter deposit amount: ";
        std::cin >> amount;
        system("clear");
        account.deposit(amount);
        break;
      case 2:
        system("clear");
        std::cout << "Enter withdrawal amount: ";
        std::cin >> amount;
        system("clear");
        account.withdraw(amount);
        break;
      case 3:
        system("clear");
        account.display();
        break;
      case 4:
        system("clear");
        exited = true;
        break;
      default:
        system("clear");
        std::cout << "Invalid choice." << std::endl;
    }
  }

  return 0;
}
