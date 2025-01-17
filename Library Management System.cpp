#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store book details
class Book {
    public:
    int id;
    string title;
    string author;
};

// Function to display all books
void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available in the library.\n";
        return;
    }
    cout << "\nAvailable Books:\n";
    for (const auto& book : books) {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
    }
}

// Function to add a new book
void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Book Author: ";
    getline(cin, newBook.author);

    books.push_back(newBook);
    cout << "Book added successfully!\n";
}

// Function to search for a book by ID
void searchBook(const vector<Book>& books) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (const auto& book : books) {
        if (book.id == id) {
            cout << "Book Found:\n";
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

int main() {
    vector<Book> books;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                displayBooks(books);
                break;
            case 3:
                searchBook(books);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
