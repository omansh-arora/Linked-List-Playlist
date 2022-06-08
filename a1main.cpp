//Omansh Arora
//301415265
//June 1 2022

// PlayList Methods
// // Default constructor
// // // O(1) because it only has to initalize variables
// // Destructor
// // // O(n) as it has to iterate through every Node in the List
// // Copy constructor
// // // O(n) because it calls the copy function which iterates through every node in the reference List
// // Overloaded assignment operator
// // // O(n) because it calls the copy function which iterates through every node in the reference List
// // Insert
// // // O(n) as in the worst case it would have to iterate through each node to reach the end of the List
// // Remove
// // // O(n) as in the worst case it would have to iterate through each node to reach the end of the List
// // Get
// // // O(n) as in the worst case it would have to iterate through each node to reach the end of the List
// // Swap
// // // O(n) as in the worst case it would have to iterate through each node to reach the end of the List to
// // //      swap the two last elements
// // Size
// // // O(1) as it just returns a variable
// Main Function Commands
// // Enter a song
// // // O(n) as it calls upon the insert method
// // Remove a song
// // // O(n) as it calls upon the remove method
// // Swap two songs
// // // O(n) as it calls upon the swap method
// // Print all the songs
// // // O(n) as it has to iterate through each Node in the playlist

#include <iostream>
#include "PlayList.h"
#include "Song.h"

using namespace std;

int main()
{

    PlayList pl;
    int input = -1;

    while (input != 5)
    {

        cout << "Menu:\n"
             << "1 - Enter a song in the play list at a given position\n"
             << "2 - Remove a song from the play list at a given position\n"
             << "3 - Swap two songs in the play list\n"
             << "4 - Print all the songs in the play list\n"
             << "5 - Quit\n";

        cout << "Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): ";
        cin >> input;

        while (input < 1 || input > 5)
        {

            cout << "Please select a valid option from 1-5: ";
            cin >> input;
        }

        if (input == 1)
        {

            cout << "Song name: ";

            string name;
            getline(cin >> ws, name);

            cout << "Song artist: ";
            string artist;
            getline(cin >> ws, artist);

            cout << "Song length (seconds): ";
            int length;
            cin >> length;
            while (length < 1)
            {

                cout << "Song length cannot be less than 1s: ";
                cin >> length;
            }

            cout << "Song position (1";
            unsigned int pos = -1;

            if (pl.size() == 0)
                cout << "): ";
            else
            {

                cout << " to " << pl.size() + 1 << "): ";
            }

            cin >> pos;

            while (pos > pl.size() + 1 || pos <= 0)
            {

                cout << "Please enter a valid position (1";
                if (pl.size() == 0 || pl.size() == 1)
                    cout << "): ";
                else
                {

                    cout << " to " << pl.size() + 1 << "): ";
                }
                cin >> pos;
            }

            pl.insert(Song{name, artist, length}, pos - 1);
            cout << name + " inserted at position " << pos << ".\n\n";
        }
        else if (input == 2)
        {

            if (pl.size() == 0)
            {

                cout << "No songs in playlist.\n\n";
                continue;
            }

            cout << "Song position (1";
            unsigned int pos = -1;

            if (pl.size() == 1)
                cout << "): ";
            else
            {

                cout << " to " << pl.size() << "): ";
            }

            cin >> pos;

            while (pos > pl.size() || pos <= 0)
            {

                cout << "Please enter a valid position (1";
                if (pl.size() == 1)
                    cout << "): ";
                else
                {

                    cout << " to " << pl.size() << "): ";
                }
                cin >> pos;
            }

            cout << pl.get(pos - 1).getName() << " removed.\n\n";
            pl.remove(pos - 1);
        }
        else if (input == 3)
        {

            if (pl.size() == 0)
            {

                cout << "No songs in playlist.\n\n";
                continue;
            }

            cout << "Swap song at position (1";
            unsigned int pos1 = -1;
            if (pl.size() == 1)
                cout << "): ";
            else
            {

                cout << " to " << pl.size() << "): ";
            }

            cin >> pos1;

            while (pos1 > pl.size() || pos1 <= 0)
            {

                cout << "Please enter a valid position (1";
                if (pl.size() == 1)
                    cout << "): ";
                else
                {

                    cout << " to " << pl.size() << "): ";
                }
                cin >> pos1;
            }

            cout << "with song at position (1";
            unsigned int pos2 = -1;
            if (pl.size() == 1)
                cout << "): ";
            else
            {

                cout << " to " << pl.size() << "): ";
            }

            cin >> pos2;

            while (pos2 > pl.size() || pos2 <= 0)
            {

                cout << "Please enter a valid position (1";
                if (pl.size() == 1)
                    cout << "): ";
                else
                {

                    cout << " to " << pl.size() << "): ";
                }
                cin >> pos2;
            }

            pl.swap(pos1 - 1, pos2 - 1);
            cout << "Songs swapped at positions " << pos1 << " and " << pos2 << ".\n\n";
        }
        else if (input == 4)
        {

            cout << endl;

            for (int i = 0; i < pl.size(); i++)
            {

                cout << i + 1 << " " << pl.get(i).getName() << " (" << pl.get(i).getArtist() << ") " << pl.get(i).getLength() << "s\n";
            }

            cout << "\nThere are " << pl.size() << " songs in the playlist.\n\n";
        }
    }
}
