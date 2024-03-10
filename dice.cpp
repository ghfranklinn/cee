#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef _LUDO_H
#define _LUDO_H

enum Color
{
    RED,
    GREEN,
    YELLOW,
    BLUE,
    NOCOLOR
};

struct House {
    Color color; //Red
    int members; //4
    bool status;//false

    House(Color c = Color::RED, int m = 4, bool s = false){
        color = c;
        members = m;
        status = s;
    }
};

struct Player {
    string name;
    House houses[2]; //House_1, House_2
};

void GameConfiguration(Player players[], int numOfPlayers);


void DisplayResults(Player players[], int numOfPlayers);

#endif


#include <iostream>
#include <string>
#include <iomanip>
#include "ludo.h";

int main()
{
    Player players[4];

    int numOfPlayers;

	cout << "How many players are in this game: ";
	cin >> numOfPlayers;

    GameConfiguration(players, numOfPlayers);

    DisplayResults(players, numOfPlayers);

    //reduce members
    cout << "Reducing members from players\n";
    for (int i = 0; i < numOfPlayers; i++)
    {
        for (int j = 0; j < 2; j++){
            players[i].houses[j].members -= (i + 1);
        }
    }

        DisplayResults(players, numOfPlayers);
		system("pause");
    return 0;

}

void GameConfiguration(Player players[], int numOfPlayers)
{
    string color_string;
    Color chosen_color = Color::NOCOLOR;
    bool exists = false;
    cout << "Starting Game Configuration... \n";
    /**
     *[Red(0), Green(1), Yellow(2), Blue(3)]
     * [true, false, true, false]
     */
    bool assignedHouses[4] = {false, false, false, false};

    for (int i = 0; i < numOfPlayers; i++)
    {
        cout << "Enter name for Player " << i + 1 << ": ";
        cin >> players[i].name;

        for (int j = 0; j < (numOfPlayers == 4 ? 1 : 2); j++)
        {
            do
            {
                cout << "\nChoose a House color(Red, Green, Yellow, Blue) for " << players[i].name << ": ";
                cin >> color_string;

                if (color_string == "Red" || color_string == "red")
                {
                    chosen_color = Color::RED;
                    exists = true;
                }
                else if (color_string == "Green" || color_string == "green")
                {
                    chosen_color = Color::GREEN;
                    exists = true;
                }
                else if (color_string == "Yellow" || color_string == "yellow")
                {
                    chosen_color = Color::YELLOW;
                    exists = true;
                }
                else if (color_string == "Blue" || color_string == "blue")
                {
                    chosen_color = Color::BLUE;
                    exists = true;
                }

                else
                {
                    cout << "Invalid color, choose from (Red, Green, Yellow, Blue)";
                }

                    if (assignedHouses[(int)chosen_color])
                    {
                        exists = false;
                        cout << "House already chosen, choose a different house\n";
                    }
            
            } while (!exists);

            players[i].houses[j] = House(chosen_color, 4, true);
            assignedHouses[(int)chosen_color] = true;
        }
    }
}



void DisplayResults(Player players[], int numOfPlayers)
{
     string HouseNames[4] = {"Red", "Green", "Yellow", "Blue"};
    cout << "Name\tHouse\tMembers\n";
    
    for (int i = 0; i < numOfPlayers; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (players[i].houses[j].status)
            {
                cout << players[i].name << "\t"
                     << HouseNames[players[i].houses[j].color] << "\t"
                     << players[i].houses[j].members << "\n";
            }
        }
    }
  
}
