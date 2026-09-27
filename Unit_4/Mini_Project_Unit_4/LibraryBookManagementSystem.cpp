#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
public:
    string isbn, title, author, category, availability;

    void addBook()
    {
        ofstream file("library.txt", ios::app);

        cout << "Enter ISBN: ";
        cin >> isbn;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Category: ";
        getline(cin, category);

        availability = "Available";

        file << isbn << "|"
             << title << "|"
             << author << "|"
             << category << "|"
             << availability << endl;

        file.close();

        cout << "\nBook Added Successfully!\n";
    }

    void displayAllBooks()
    {
        ifstream file("library.txt");

        string line;

        cout << "\n===== LIBRARY REPORT =====\n";

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    void searchBook()
    {
        ifstream file("library.txt");

        string searchISBN;
        string line;

        cout << "Enter ISBN to Search: ";
        cin >> searchISBN;

        bool found = false;

        while (getline(file, line))
        {
            if (line.find(searchISBN) != string::npos)
            {
                cout << "\nBook Found:\n";
                cout << line << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Book Not Found!\n";

        file.close();
    }
};

int main()
{
    Book b;
    int choice;

    do
    {
        cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.addBook();
            break;

        case 2:
            b.searchBook();
            break;

        case 3:
            b.displayAllBooks();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
