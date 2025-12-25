#include <iostream>
#include <string>
using namespace std;
// globle variables
string username[5];
string password[5];
int count = 0;
// function decleration
void signup();     // create login
void signin();     // read(to check login )
void viewUsers();  // read(display user data)
void updateUser(); // update
void deleteUser(); // delete
int main()
{
    int choice;
    do
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "       LOGIN SYSTEM      \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1.Sign up\n";
        cout << "2.Sign in\n";
        cout << "3.View users\n";
        cout << "4.Update password\n";
        cout << "5.Delete user\n";
        cout << "6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
            signup();
        else if (choice == 2)
            signin();
        else if (choice == 3)
            viewUsers();
        else if (choice == 4)
            updateUser();
        else if (choice == 5)
            deleteUser();
        else if (choice == 6)
            cout << "Exit\n";
        else
            cout << "wrong choive !\n";
    } while (choice != 6);
    return 0;
}
// create login
void signup()
{
    if (count >= 5)
    {
        cout << "Limit reached!\n";
        return;
    }
    cout << "Enter username: ";
    cin >> username[count];
    cout << "Enter password: ";
    cin >> password[count];
    cout << "Signup done successful\n";
    count++;
}
// read (to check login)
void signin()
{
    string u, p;
    bool found = false;
    cout << "Enter username: ";
    cin >> u;
    cout << "Enter password: ";
    cin >> p;
    for (int i = 0; i < count; i++)
    {
        if (u == username[i] && p == password[i])
        {
            found = true;
            break;
        }
    }
    if (found)
        cout << "Login successful\n";
    else
        cout << "wrong login\n";
}
// read (check login from users)
void viewUsers()
{
    if (count == 0)
    {
        cout << "no users found\n";
        return;
    }
    cout << "\nUser is registered :\n";
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << username[i] << endl;
    }
}
// update user or add user
void updateUser()
{
    string u;
    bool found = false;
    cout << "Enter username to update password: ";
    cin >> u;
    for (int i = 0; i < count; i++)
    {
        if (u == username[i])
        {
            cout << "Enter new password: ";
            cin >> password[i];
            cout << "Password updated successfully\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "User not found\n";
}
// delete or remove user
void deleteUser()
{
    string u;
    bool found = false;
    cout << "Enter username to delete: ";
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
            cout << "User was deleted \n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "User not found\n";
}
