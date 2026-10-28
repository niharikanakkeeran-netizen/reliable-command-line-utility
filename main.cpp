#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

struct Expense {
    string description;
    string category;
    double amount;
};

double readAmount() {
    double amount;
    while (true) {
        cout << "Enter amount (greater than 0): Rs. ";
        if (cin >> amount && amount > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }
        cout << "Invalid amount. Please enter a number greater than 0.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string readNonEmptyLine(const string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);

        // Remove leading and trailing spaces.
        size_t first = value.find_first_not_of(" \t\r\n");
        if (first != string::npos) {
            size_t last = value.find_last_not_of(" \t\r\n");
            return value.substr(first, last - first + 1);
        }
        cout << "This field cannot be empty. Please try again.\n";
    }
}

int readMenuChoice() {
    int choice;
    while (true) {
        cout << "\n========== EXPENSE TRACKER ==========\n";
        cout << "1. Add expense\n";
        cout << "2. List all expenses\n";
        cout << "3. Show total by category\n";
        cout << "4. Show overall total\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";

        if (cin >> choice && choice >= 1 && choice <= 5) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid choice. Enter a whole number from 1 to 5.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void addExpense(vector<Expense>& expenses) {
    cout << "\n--- Add Expense ---\n";
    Expense expense;
    expense.description = readNonEmptyLine("Enter description: ");
    expense.category = readNonEmptyLine("Enter category (e.g., Food, Travel): ");
    expense.amount = readAmount();

    expenses.push_back(expense);
    cout << "Expense added successfully!\n";
}

void listExpenses(const vector<Expense>& expenses) {
    cout << "\n--- All Expenses ---\n";
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << left << setw(5) << "No."
         << setw(28) << "Description"
         << setw(20) << "Category"
         << right << setw(12) << "Amount (Rs.)" << '\n';
    cout << string(65, '-') << '\n';

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << left << setw(5) << i + 1
             << setw(28) << expenses[i].description.substr(0, 27)
             << setw(20) << expenses[i].category.substr(0, 19)
             << right << setw(12) << expenses[i].amount << '\n';
    }
}

void showCategoryTotals(const vector<Expense>& expenses) {
    cout << "\n--- Total by Category ---\n";
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    map<string, double> totals;
    for (const Expense& expense : expenses) {
        totals[expense.category] += expense.amount;
    }

    cout << fixed << setprecision(2);
    for (const auto& item : totals) {
        cout << left << setw(24) << item.first
             << "Rs. " << item.second << '\n';
    }
}

void showOverallTotal(const vector<Expense>& expenses) {
    double total = 0.0;
    for (const Expense& expense : expenses) {
        total += expense.amount;
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Overall Total ---\n";
    cout << "Total expenses: Rs. " << total << '\n';
    cout << "Number of expenses: " << expenses.size() << '\n';
}

int main() {
    vector<Expense> expenses;

    cout << "Welcome to the Reliable Command-Line Expense Tracker!\n";

    while (true) {
        int choice = readMenuChoice();

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                listExpenses(expenses);
                break;
            case 3:
                showCategoryTotals(expenses);
                break;
            case 4:
                showOverallTotal(expenses);
                break;
            case 5:
                cout << "Thank you for using the Expense Tracker. Goodbye!\n";
                return 0;
            default:
                // readMenuChoice() validates the menu range.
                cout << "Unexpected menu option.\n";
        }
    }
}
