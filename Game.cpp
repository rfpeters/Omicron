/****************************************************
* Description:
*****************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "Room.hpp"
#include "Item.hpp"
#include "Player.hpp"


void createRooms(Room[3][5], int, int);
void moveRoom(Room*, Room[3][5], int&, int&, std::string);
void parseUserCommand(Player&, Room*, Room[3][5], int&, int &, std::string);
void displayRoomDesc(Room*);
void displayIntro();
void displayHelpMenu();
void attack(Player&, Room*);
int checkWinGame(Player&);

int main()
{
	Player player; //has constructor to initialize all attributes



	int MAX_X = 3;  //horizontal
	int MAX_Y = 5;	//vertical
	int i, j;
	Room roomArray[3][5];

	createRooms(roomArray, MAX_X, MAX_Y);


////START OF ROOM STATUS TESTING
	/*
	for (i = 0; i < MAX_X; i++)
	{
		for (j = 0; j < MAX_Y; j++)
		{
			std::cout << "room at " << i << "," << j <<":" << std::endl;
			std::cout << roomArray[i][j].getRoomName() << std::endl;
			std::cout << roomArray[i][j].getLongDesc() << std::endl;
			std::cout << roomArray[i][j].getShortDesc() << std::endl;
			std::cout << roomArray[i][j].getIsDoorN() << std::endl;
			std::cout << roomArray[i][j].getIsDoorE() << std::endl;
			std::cout << roomArray[i][j].getIsDoorS() << std::endl;
			std::cout << roomArray[i][j].getIsDoorW() << std::endl;
			std::cout << "hasVisited == " << roomArray[i][j].getHasVisited() << std::endl << std::endl;
		}

	}
	*/

////END OF ROOM STATUS TESTING



	int currentX = 1;
	int currentY = 4;
	Room *currentRoom;
	currentRoom = &roomArray[currentX][currentY];
	std::string d = "";
	std::string verb = "";
	std::string noun = "";
	std::string userCommand = "";


	displayIntro();
	displayRoomDesc(currentRoom);
	roomArray[currentX][currentY].setHasVisited(true);
	

/*****************game loop - start***********************/
	do {
		int verbFunction = 0;
		//std::cout << "Enter your command separated by spaces: " << std::endl; // for testing purposes
		std::cout << "> ";
		std::getline(std::cin, userCommand);

		if (userCommand == "n" || userCommand == "e" || userCommand == "s" || userCommand == "w")
		{
			moveRoom(currentRoom, roomArray, currentX, currentY, userCommand);
			currentRoom = &roomArray[currentX][currentY];
			displayRoomDesc(currentRoom);
			currentRoom->setHasVisited(true);
		}
		else
		{
			parseUserCommand(player, currentRoom, roomArray, currentX, currentY, userCommand);
		}

/**************START TEST OF WIN GAME**********/
		if (userCommand == "switch objs to true")
		{
			std::cout << "switching to true" << std::endl;
			player.setFireOut(true);
			player.setEngineFueled(true);
			player.setShipStarted(true);
			player.setAlienKilled(true);
			player.setFoodEaten(true);
			player.setSpaceSuitOn(true);
		}
/**************END TEST OF WIN GAME**********/

/**************START TEST OF PLAYER STATUS**********/
		
	std::cout << "maxInventoryWeight= " << player.getMaxInventoryWeight() << std::endl;
	std::cout << "fireOut= " << player.getFireOut() << std::endl;
	std::cout << "engineFueled= " << player.getEngineFueled() << std::endl;
	std::cout << "shipStarted= " << player.getShipStarted() << std::endl;
	std::cout << "alienKilled= " << player.getAlienKilled() << std::endl;
	std::cout << "foodEaten= " << player.getFoodEaten() << std::endl;
	std::cout << "spaceSuitOn= " << player.getSpaceSuitOn() << std::endl;
	
/**************END TEST OF PLAYER STATUS**********/
		
	
		if (checkWinGame(player))
		{
			break;
		}

	} while(1); //use CTRL+C to stop loop & program for now

/*****************game loop - end***********************/


	return 0;
}

void createRooms(Room roomArray[3][5], int x, int y)
{
	std::string line;
	std::string data;
	std::string delimiter = ":";
	std::ifstream infile;
	std::string roomFiles[15] = {"room00.txt", "room01.txt",  "room02.txt", "room03.txt", "room04.txt",
								"room10.txt", "room11.txt",  "room12.txt", "room13.txt", "room14.txt",
								"room20.txt", "room21.txt",  "room22.txt", "room23.txt", "room24.txt"};
	
	int fileIndex = 0;
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{			
			infile.open(roomFiles[fileIndex].c_str());
			
			if(infile)
			{
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				roomArray[i][j].setRoomName(line);
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				roomArray[i][j].setLongDesc(line);

				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				roomArray[i][j].setDependentDesc(line);
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				roomArray[i][j].setShortDesc(line);

				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				roomArray[i][j].addItem(line);
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				if(line.compare("true") == 0)
				{
					roomArray[i][j].setIsDoorN(true);
				}
				else
				{
					roomArray[i][j].setIsDoorN(false);
				}
				
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				if(line.compare("true") == 0)
				{
					roomArray[i][j].setIsDoorE(true);
				}
				else
				{
					roomArray[i][j].setIsDoorE(false);
				}
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				if(line.compare("true") == 0)
				{
					roomArray[i][j].setIsDoorS(true);
				}
				else
				{
					roomArray[i][j].setIsDoorS(false);
				}
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				if (!line.empty() && line[line.length() - 1] == '\r')
				{
					line.erase(line.length() - 1);
				}
				if(line.compare("true") == 0)
				{
					roomArray[i][j].setIsDoorW(true);
				}
				else
				{
					roomArray[i][j].setIsDoorW(false);
				}
				
				roomArray[i][j].setHasVisited(false); //sets all rooms to not visited

				infile.close();
			}
			else
			{
				std::cout << "Could not open file: " << roomFiles[j].c_str() << std::endl;
			}

			fileIndex++;
		}	
	}
	
}

void moveRoom(Room *currentRoom, Room roomArray[3][5], int &currentX, int &currentY, std::string d) {
	
	// move south
	if (d == "s" && currentRoom->getIsDoorS() == true) {
		currentY--;
	}

	// move north
	else if (d == "n" && currentRoom->getIsDoorN() == true) {
		currentY++;
	}

	// move east
	else if (d == "e" && currentRoom->getIsDoorE() == true) {
		currentX++;
	}

	// move west
	else if (d == "w" && currentRoom->getIsDoorW() == true) {
		currentX--;
	}
	else
		std::cout << std::endl << "No door in that direction" << std::endl;

}

void parseUserCommand(Player &player, Room *currentRoom, Room roomArray[3][5], int &currentX, int &currentY, std::string command)
{
	
	if (command == "help")
	{
		displayHelpMenu();
	}
	else if (command == "attack")
	{
		attack(player, currentRoom);
	}
	else if (command == "look")
	{
		std::cout << currentRoom->getLongDesc() << std::endl;
		std::cout << currentRoom->getDependentDesc() << std::endl << std::endl;
	}
	else if (command == "look at item")
	{
		std::cout << "look at item test." << std::endl;
	}
	else if (command == "take item")
	{
		std::cout << "take item test." << std::endl;
	}
	else if (command == "drop item")
	{
		std::cout << "drop item test." << std::endl;
	}
	else if (command == "inventory")
	{
		std::cout << "inventory test." << std::endl;
	}

	else if (command == "use item")
	{
		std::cout << "use item test." << std::endl;
	}
	else
	{
		std::cout << std::endl << "That is not a valid command." << std::endl;
	}

}

void displayRoomDesc(Room *currentRoom)
{
	std::cout << std::endl;

	if (currentRoom->getHasVisited() == true)
	{
		std::cout << currentRoom->getShortDesc() << std::endl;

		if (currentRoom->getDependentDesc() != "")
		{
			std::cout << currentRoom->getDependentDesc() << std::endl;
		}
	}
	else
	{
		std::cout << currentRoom->getLongDesc() << std::endl;

		if (currentRoom->getDependentDesc() != "")
		{
			std::cout << currentRoom->getDependentDesc() << std::endl;
		}
	}

	std::cout << std::endl;
}

void displayIntro()
{
	std::cout << std::endl << "Intro here Intro here Intro here " << std::endl << std::endl;
}

void attack(Player &player, Room *currentRoom)
{
	std::cout << std::endl;

	if (currentRoom->getRoomName() == "bridge" && player.getAlienKilled() == false)
	{
		player.setAlienKilled(true);
		currentRoom->setDependentDesc("");

		std::cout << "You killed the alien." << std::endl << std::endl;
	}
	else
	{
		std::cout << "There is nothing to attack." << std::endl << std::endl;
	}
}

void displayHelpMenu()
{
	std::cout << std::endl;
	std::cout << "This is the help menu." << std::endl;
	std::cout << "This is the help menu. Max weight right now set to 5." << std::endl;
	std::cout << "This is the help menu. List available commands." << std::endl;
	std::cout << std::endl;
}

int checkWinGame(Player &player)
{
	if (player.getFireOut() == true &&
		player.getEngineFueled() == true &&
		player.getShipStarted() == true &&
		player.getAlienKilled() == true &&
		player.getFoodEaten() == true &&
		player.getSpaceSuitOn() == true)
	{
		std::cout << std::endl << "CONGRATULATIONS! You have won the game!" << std::endl << std::endl;
		return 1;
	}
	
	return 0;
}
