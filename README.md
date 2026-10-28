# Reliable Command-Line Utility — Expense Tracker

A beginner-friendly C++ command-line expense tracker built for the EdVyro task.

## Features
- Menu-driven interface
- Add an expense with a description, category, and positive amount
- List all expenses
- Calculate totals by category
- Calculate the overall total and number of expenses
- Validate menu choices, empty text fields, and invalid/non-positive amounts
- Uses a `vector` to store expenses and a `map` to calculate category totals

## Requirements
- A C++ compiler that supports C++11 or later (g++ recommended)

## Compile and run

### Windows (MinGW g++)
Open the terminal in this folder and run:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o expense_tracker.exe
.\expense_tracker.exe
```

### Linux / macOS
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o expense_tracker
./expense_tracker
```

### VS Code
1. Open this folder in VS Code.
2. Open `main.cpp`.
3. Make sure a C++ compiler is installed and available in the terminal.
4. Open **Terminal → New Terminal**.
5. Run the compile command for your operating system above.
6. Run the generated program and test each menu option.

## Example test data
Add these expenses:
- Description: Lunch; Category: Food; Amount: 120
- Description: Bus ticket; Category: Travel; Amount: 30
- Description: Snacks; Category: Food; Amount: 50

Expected results:
- Food total: Rs. 170.00
- Travel total: Rs. 30.00
- Overall total: Rs. 200.00
- Number of expenses: 3

## Notes
- Expenses are kept in memory while the program runs. They reset when you exit.
- This project is a command-line application, not a web app.
