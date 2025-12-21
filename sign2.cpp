#include <iostream>
using namespace std;
string username[5];
string password[5];
int count = 0;
void signup();
void signin();
int main()
{
    int choice;
    do
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "       LOGIN SYSTEM      \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1.Sign Up\n";
        cout << "2.Sign In\n";
        cout << "3.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
            signup();
        else if (choice == 2)
            signin();
        else if (choice == 3)
            cout << "Exit\n";
        else
            cout << " Wrong choice!\n";
    } while (choice != 3);
    return 0;
}
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
    cout << "Signup successful\n";
    count++;
}
void signin()
{
    string u, p;
    bool match = false;
    cout << "Enter username: ";
    cin >> u;
    cout << "Enter password: ";
    cin >> p;
    for (int i = 0; i < count; i++)
    {
        if (u == username[i] && p == password[i])
        {
            match = true;
            break;
        }
    }
    if (match)
        cout << "Login successful\n";
    else
        cout << "Invalid login\n";
}