// Name - Shubh patel
// Purpose: To use a linked list to create a database where the user can store 
// the names of there games, types and ratings.

/* 
The Idea to do this personal project stemmed from one of my cs classes assignments
where I had to create a city data bases with lots of useful functions. So this idea
stemmed from that assignment because who doesn't like games? Also there was a lot less
functions used this time around because I wanted this to be a shorter and simpler
personal project while also retaining general coding principles such as data
validation and how to code simple functions for a linked list. 
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

//The link list's node structure
class Node
{
public:
    string gameName = "Empty";
    string gameType = "Empty";
    string gameRating = "Empty";
    Node* nextNode;
};

//The LinkedList structure for the linkedlist implementation
class LinkedList
{
private:
    Node* head;
public:
    //Default constructor
    LinkedList()
    {
        head = NULL;
    }

    //pre - No parameters
    //post - Inserts a game into the linked list
    void insertGame()
    {
        //Gets all the game data
        string gName;
        string gType;
        string gRating;
        cout << "\nPlease insert game name: ";
        cin >> gName;
        cout << "Please insert game type like whether its fantasy, action, rpg, etc: ";
        cin >> gType;
        cout << "Please insert game rating like whether its teen, mature, etc: ";
        cin >> gRating;

        //Inserts new games into the beginning of the linked list
        Node* ptr = new Node();
        ptr->gameName = gName;
        ptr->gameType = gType;
        ptr->gameRating = gRating;
        ptr->nextNode = head;
        head = ptr;
        cout << "Insertion Successful.\n\n";
    }

    //pre - no parameters
    //post - deletes a game from the linked list.
    void deleteGame()
    {
        cout << "\nEnter the name of the game to be deleted: ";
        string gName;
        cin >> gName;

        Node* current = head;
        Node* previous = NULL;

        //To check if the head node has the stored elements to be deleted
        if ((current != NULL) && (current->gameName == gName))
        {
            head = current->nextNode;
            delete current;
            cout << "Deleted successfully.\n\n";
            return;
        }

        //The rest is using while loops to iterate through the list
        //then deleting when the desired elements to be deleted
        //are found
        bool notFoundFlag = true;
        while ((current != NULL) && (notFoundFlag))
        {
            if (current->gameName == gName)
            {
                notFoundFlag = false;
            }
            else
            {
                previous = current;
                current = current->nextNode;
            }
        }
        if (notFoundFlag)
        {
            cout << "No such games existed in the linked list.\n\n";
        }
        else
        {
            previous->nextNode = current->nextNode;
            delete current;
            cout << "Deleted successfully.\n\n";
        }
    }

    //pre - no parameters
    //post - prints all the contents of the linked list
    void printAll ()
    {
        cout << "\nPrinting All:\n";
        Node* current = head;
        //Uses if statements and hwile loops to print out contents of linked list.
        if (current != NULL)
        {
            while (current != NULL)
            {
                cout << "Name: " << current->gameName << ", Type: " << current->gameType
                     << ", Rating: " << current->gameRating << "\n\n";
                current = current->nextNode;
            }
        }
        else
        {
            cout << "The game data base is empty.\n\n";
        }
    }
};

int main()
{
    LinkedList gameDB;
    bool loopFlag = true;
    //Uses a while loop for repreating menu
    while (loopFlag)
    {
        cout << "Operations:\n1. Insert Game\n2. Delete Game\n3. Print all the records."
            << "\nSelect which operation you would like to do by there corresponding number: ";
        int operation = 0;
        bool loopFlag1 = true;
        //This part validates user input
        do
        {
            cin >> operation;
            if ((operation < 1) || (operation > 3) || !cin.good())
            {
                cout << "Incorrect Input, please enter options 1-3: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                loopFlag1 = false;
            }
        } while (loopFlag1);

        //Switch statements are used to execute the various operations.
        switch (operation)
        {
        case 1:
            gameDB.insertGame();
            break;
        case 2:
            gameDB.deleteGame();
            break;
        case 3:
            gameDB.printAll();
            break;
        default:
            break;
        }
    }
}
