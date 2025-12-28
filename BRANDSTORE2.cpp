
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// For user to sign in
string username[5];
string password[5];
int count = 0;
//To store Watches information 
int watch_id[30];
string watch_name[30];
string watch_brand[30];
float watchPrice[30];
int watch_count = 0;
// main fuctions decleration 
void signup();
void signin();
void customer_menu(int);
void view_users();
void update_user();
void delete_User();
// watches info 
void add_watch();
void view_watches();
void update_watch();
void delete_watch();

void load_user();
void save_user();
void load_watches();
void save_watches();

int main()
{
    load_user();
    load_watches();
    int choice;
    do
    {
        cout << "\n=========================\n";
        cout << "           LOGIN         \n";
        cout << "=========================\n";
        cout << "1. Sign up \n";
        cout << "2. Sign in \n";
        cout << "3. View users\n";
        cout << "4. Update user password\n";
        cout << "5. Delete user\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
            signup();
        else if (choice == 2)
            signin();
        else if (choice == 3)
            view_users();
        else if (choice == 4)
            update_user();
        else if (choice == 5)
            delete_User();
        else if (choice == 6)
        {
            save_user();
            save_watches();
            cout << "Exit\n";
        }
        else
            cout << "Wrong choice\n";

    } while (choice != 6);

    return 0;
}
// file where user signin is stored 
void load_user()
{
    ifstream file("users.txt");
    while (file >> username[count] >> password[count])
    {
        count++;
        if (count >= 5)
            break;
    }
    file.close();
}
// to store signup of user 
void save_user()
{
    ofstream file("users.txt");
    for (int i = 0; i < count; i++)
        file << username[i] << " " << password[i] << endl;
    file.close();
}
// fetch stored watches 
void load_watches()
{
    ifstream file("watches.txt");
    while (file >> watch_id[watch_count] >> watch_name[watch_count] >> watch_brand[watch_count] >> watchPrice[watch_count])
    {
        watch_count++;
    }
    file.close();
}
// save new watches 
void save_watches()
{
    ofstream file("watches.txt");
    for (int i = 0; i < watch_count; i++)
        file << watch_id[i] << " " << watch_name[i] << " "
             << watch_brand[i] << " " << watchPrice[i] << endl;
    file.close();
}
// to create signup
void signup()
{
    if (count >= 5)
    {
        cout << "User limit reached\n";
        return;
    }
    cout << "Enter username: ";
    cin >> username[count];
    cout << "Enter password: ";
    cin >> password[count];
    count++;
    save_user();
    cout << "Signup successful\n";
}
void signin()
{
    string u, p;
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    for (int i = 0; i < count; i++)
    {
        if (u == username[i] && p == password[i])
        {
            cout << "Login successful\n";
            customer_menu(i);
            return;
        }
    }
    cout << "Invalid login\n";
}
void customer_menu(int index)
{
    int choice;
    do
    {
        cout << "\n======= WATCH BRAND STORE MENU =====\n";
        cout << "1. Add Watch\n";
        cout << "2. View Watches\n";
        cout << "3. Update Watch\n";
        cout << "4. Delete Watch\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
            add_watch();
        else if (choice == 2)
            view_watches();
        else if (choice == 3)
            update_watch();
        else if (choice == 4)
            delete_watch();
        else if (choice == 5)
            cout << "Logged out\n";
        else
            cout << "Invalid choice\n";

    } while (choice != 5);
}

// Admin managment 
void view_users()
{
    for (int i = 0; i < count; i++)
        cout << i + 1 << ". " << username[i] << endl;
}

void update_user()
{
    string u;
    cout << "Enter username: ";
    cin >> u;

    for (int i = 0; i < count; i++)
    {
        if (u == username[i])
        {
            cout << "new password: ";
            cin >> password[i];
            save_user();
            cout << "updated\n";
            return;
        }
    }
    cout << "User not found\n";
}
void delete_User()
{
    string u;
    cout << "Enter username: ";
    cin >> u;

    for (int i = 0; i < count; i++)
    {
        if (u == username[i])
        {
            for (int j = i; j < count - 1; j++)
            {
                username[j] = username[j + 1];
                password[j] = password[j + 1];
            }
            count--;
            save_user();
            cout << "Deleted\n";
            return;
        }
    }
    cout << "User not found\n";
}

// to edit watches info
void add_watch()
{
    cout << "Watch ID: ";
    cin >> watch_id[watch_count];
    cout << "Watch Name: ";
    cin >> watch_name[watch_count];
    cout << "Brand: ";
    cin >> watch_brand[watch_count];
    cout << "Price: ";
    cin >> watchPrice[watch_count];

    watch_count++;
    save_watches();
    cout << "Watch added\n";
}

void view_watches()
{
    if (watch_count == 0)
    {
        cout << "No watches available\n";
        return;
    }

    for (int i = 0; i < watch_count; i++)
    {
        cout << "\nID: " << watch_id[i]
             << "\nName: " << watch_name[i]
             << "\nBrand: " << watch_brand[i]
             << "\nPrice: " << watchPrice[i] << endl;
    }
}

void update_watch()
{
    int id;
    cout << "Enter watch ID to update : ";
    cin >> id;

    for (int i = 0; i < watch_count; i++)
    {
        if (watch_id[i] == id)
        {
            cout << "New Name: ";
            cin >> watch_name[i];
            cout << "New Brand: ";
            cin >> watch_brand[i];
            cout << "New Price: ";
            cin >> watchPrice[i];

            save_watches();
            cout << "Watch updated\n";
            return;
        }
    }
    cout << "Watch not found\n";
}

void delete_watch()
{
    int id;
    cout << "Enter Watch ID to delete: ";
    cin >> id;

    for (int i = 0; i < watch_count; i++)
    {
        if (watch_id[i] == id)
        {
            for (int j = i; j < watch_count - 1; j++)
            {
                watch_id[j] = watch_id[j+1];
                watch_name[j] = watch_name[j+1];
                watch_brand[j] = watch_brand[j+1];
                watchPrice[j] = watchPrice[j+1];
            }
            watch_count--;
            save_watches();
            cout << "Watch deleted\n";
            return;
        }
    }
    cout << "Watch not found\n";
}
