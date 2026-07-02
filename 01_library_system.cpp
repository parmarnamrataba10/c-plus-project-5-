
#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:

    string title;
    string author;
    string dueDate;

public:

    LibraryItem(string title, string author, string dueDate)
    {

        this->title = title;
        this->author = author;
        this->dueDate = dueDate;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() 
    {

    }

    // get

    string getTitle() const
    {

        return title;
    }

    string getAuthor() const
    {

        return author;
    }
    string getDueDate() const
    {

        return dueDate;
    }

    // set

    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }
};

class Book : public LibraryItem
{
private:
    string isbn;
    bool isCheckedOut;

public:
    Book(string title, string author, string dueDate, string isbn) : LibraryItem(title, author, dueDate), isbn(isbn), isCheckedOut(false)
    {


    }

    void checkOut() override
    {
        if (isCheckedOut)


            cout << "Book already checked out!\n";
        else
        {
            isCheckedOut = true;
            cout << "------Book checked out successfully!\n------";
        }
    }

    void returnItem() override
    {
        if (!isCheckedOut)


            cout << "Book is not checked out!\n";
        else
        {
            isCheckedOut = false;
            cout << "------Book returned successfully!\n------";
        }
    }

    void displayDetails() const override
    {
        cout << "-- Book --";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;
    bool isCheckedOut;

public:
    DVD(string title, string director, string dueDate, int duration) : LibraryItem(title, director, dueDate), duration(duration), isCheckedOut(false)
    {
    }

    void checkOut() override
    {
        if (isCheckedOut)

            cout << "DVD  checked out!\n";
        else
        {
            isCheckedOut = true;
            cout << "DVD checked out successfully!\n";
        }
    }

    void returnItem() override
    {
        if (!isCheckedOut)

            cout << "DVD is not checked out!\n";
        else
        {
            isCheckedOut = false;
            cout << "DVD returned successfully!\n";
        }
    }

    void displayDetails() const override
    {
        cout << " -- DVD --";
        cout << "Title: " << getTitle() << endl;
        cout << "Director: " << getAuthor() << endl;
        cout << "Duration: " << duration << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

int main()
{
    LibraryItem *libraryItems[100];

    int count = 0;
    int choice;

    do
    {
        cout << "==== Library Management System ===== \n ";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Display All Items\n";
        cout << "4. Search Item by Title\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        try
        {
            if (choice == 1)
            {
                string title, author, dueDate, isbn;

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter ISBN: ";
                getline(cin, isbn);

                if (isbn.empty())
                    throw runtime_error("Invalid ISBN!");

                libraryItems[count++] = new Book(title, author, dueDate, isbn);
                cout << "------Book added successfully!\n------";
            }

            else if (choice == 2)
            {
                string title, director, dueDate;
                int duration;

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Director: ";
                getline(cin, director);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Duration (minutes): ";
                cin >> duration;
                cin.ignore();

                if (duration <= 0)

                    throw runtime_error("Invalid duration!");

                libraryItems[count++] = new DVD(title, director, dueDate, duration);
                cout << "------DVD added successfully!\n------";
            }

            else if (choice == 3)
            {
                if (count == 0)
                    cout << "No items in library.\n";
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        cout << "\nItem Number: " << i << endl;
                        libraryItems[i]->displayDetails();
                    }
                }
            }
            else if (choice == 4)
            {
                string searchTitle;
                cout << "Enter title to search: ";
                getline(cin, searchTitle);

                bool found = false;
                for (int i = 0; i < count; i++)
                {
                    if (libraryItems[i]->getTitle() == searchTitle)
                    {
                        libraryItems[i]->displayDetails();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Item not found!\n";
            }
            else if (choice == 5)
            {
                int index;
                cout << "Enter item number: ";
                cin >> index;
                cin.ignore();

                if (index < 0 || index >= count)
                    throw runtime_error("Invalid item index!");

                libraryItems[index]->checkOut();
            }
            else if (choice == 6)
            {
                int index;
                cout << "Enter item number: ";
                cin >> index;
                cin.ignore();

                if (index < 0 || index >= count)
                    throw runtime_error("Invalid item index!");

                libraryItems[index]->returnItem();
            }
            else if (choice != 7)
            {
                cout << "Invalid choice!\n";
            }
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 7);

    for (int i = 0; i < count; i++)
        delete libraryItems[i];

    cout << "Exiting program...\n";

    return 0;
}
