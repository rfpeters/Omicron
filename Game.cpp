/****************************************************
* Description:
*****************************************************/

#include <iostream>
#include <fstream>
#include <string>
//#include <algorithm>

#include "Room.hpp"
#include "Item.hpp"
#include "Player.hpp"


void createRooms(Room[3][5], int, int);
void moveRoom(Room*, int&, int&, std::string);
void parseUserCommand(Player&, Room*, Room[3][5], int&, int &, std::string);
void displayRoomDesc(Room*);
void displayIntro();
void displayHelpMenu();
void attack(Player&, Room*);
int checkWinGame(Player&);

int main()
{
	Player player; //has constructor to initialize all attributes

	const int MAX_X = 3;	//horizontal
	const int MAX_Y = 5;	//vertical
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

		//if a direction is inputted
		if (userCommand == "n" || userCommand == "e" || userCommand == "s" || userCommand == "w")
		{
			moveRoom(currentRoom, currentX, currentY, userCommand);
			currentRoom = &roomArray[currentX][currentY];
			displayRoomDesc(currentRoom);
			currentRoom->setHasVisited(true);
		}
		else
		{
			parseUserCommand(player, currentRoom, roomArray, currentX, currentY, userCommand);
		}

/*
		currentRoom->addItem("added1");
		currentRoom->addItem("added2");
		currentRoom->removeItem("added1");
*/
/**************START TEST OF WIN GAME**********/
		/*
		if (userCommand == "switch objs to true")
		{
			std::cout << "switching to true..." << std::endl;
			player.setFireOut(true);
			player.setEngineFueled(true);
			player.setShipStarted(true);
			player.setAlienKilled(true);
			player.setFoodEaten(true);
			player.setSpaceSuitOn(true);
		}
		*/
/**************END TEST OF WIN GAME**********/

/**************START TEST OF PLAYER STATUS**********/
	/*	
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


/**********************************************************
* This function reads in data and populated roomArray with
* that data.
***********************************************************/
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

				//add item
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


/************************************************************************
* This function increments or decrements either the currentX or currentY
* variables to navigate through the rooms.
************************************************************************/
void moveRoom(Room *currentRoom, int &currentX, int &currentY, std::string d) 
{
	
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
	std::string command2 = command;
	std::string delimiter = " ";
	std::string command3;
			

	//parse use command delimited by space. If space found, split into two strings.
	std::size_t found = command.find(delimiter);
  	if (found!=std::string::npos)
  	{
		command.erase(command.find(delimiter), command.length()); //string before first space
		command2.erase(0, command2.find(delimiter) + delimiter.length()); //part after first space
		//std::cout << "command after delimited: " << command << std::endl;
		//std::cout << "command2 after delimited: " << command2 << std::endl;
		
		if (!(command2 != "fire extinguisher" || command2 != "access code")) ////////two-worded items should skip this step//////////////
		{
			//If space found, split into another two strings.
			found = command2.find(delimiter);
		  	if (found!=std::string::npos)
		  	{
				command3 = command2;
				command2.erase(command2.find(delimiter), command2.length()); //string before first space
				command3.erase(0, command3.find(delimiter) + delimiter.length()); //part after first space
				//std::cout << "command2 after delimited: " << command2 << std::endl;
				//std::cout << "command3 after delimited: " << command3 << std::endl;
			}
		}
	}

	if (command == "help")
	{
		displayHelpMenu();
	}
	else if (command == "attack")
	{
		attack(player, currentRoom);
	}
	else if (command == "look" && command2 != "at")
	{
		//std::cout << currentRoom->getLongDesc() << std::endl;
		//std::cout << currentRoom->getDependentDesc() << std::endl << std::endl;
		displayRoomDesc(currentRoom);
	}
	else if (command == "look" && command2 == "at")
	{
		std::cout << "look at -" << command3 << "- test." << std::endl;
	}
	else if (command == "take")
	{
		bool inRoom = false;

		//check to see if the item exists in room
		for (int j = 0; j < currentRoom->getItems().size(); j++)
		{
			if (currentRoom->getItems()[j] == command2)
				inRoom = true;
		}

		//if exists, add into inventory
		if (inRoom)
		{
			player.addItem(command2);
			currentRoom->removeItem(command2);
			std::cout << std::endl << "You have added " << command2 << " into your inventory." << std::endl << std::endl;
		}
		else
		{
			std::cout << std::endl << command2 << " is not in this room." << std::endl << std::endl;
		}

	}
	else if (command == "drop")
	{
		bool inInventory = false;

		//check to see if the item exists in player's inventory
		for (int k = 0; k < player.getItems().size(); k++)
		{
			if (player.getItems()[k] == command2)
				inInventory = true;
		}

		//if exists, drop into room
		if (inInventory)
		{
			currentRoom->addItem(command2);
			player.removeItem(command2);
			std::cout << std::endl << "You have removed " << command2 << " from your inventory." << std::endl << std::endl;
		}
		else
		{
			std::cout << std::endl << command2 << " is not in your inventory." << std::endl << std::endl;

		}
	}
	else if (command == "inventory")
	{
		//std::cout << "current inventory size: " << player.getItems().size() << std::endl;
		std::cout << std::endl << "Items in inventory: " << std::endl;
		for (int i = 0; i < player.getItems().size(); i++)
		{
			//if(currentRoom->getItems()[i] != "")
				std::cout << player.getItems()[i] << std::endl;
		}
		std::cout << std::endl;

	}

	else if (command == "use")
	{
		std::cout << "use -" << command2 << "- test." << std::endl;
	}
	else
	{
		std::cout << std::endl << "That is not a valid command." << std::endl << std::endl;
	}

}


/*********************************************************************
* This function displays a description each time the players navigates
* to a new room.
**********************************************************************/
void displayRoomDesc(Room *currentRoom)
{
	std::cout << std::endl;

	//if the room has been visted before, show only a short description
	if (currentRoom->getHasVisited() == true)
	{
		std::cout << currentRoom->getShortDesc() << std::endl;
		//display dependent description if not empty
		if (currentRoom->getDependentDesc() != "")
		{
			std::cout << currentRoom->getDependentDesc() << std::endl;
		}
	}
	else
	{	
		//if the room has not been visited before, display the long description
		std::cout << currentRoom->getLongDesc() << std::endl;

		//display dependent description if not empty
		if (currentRoom->getDependentDesc() != "")
		{
			std::cout << currentRoom->getDependentDesc() << std::endl;
		}
	}

	//display the items and features within the room
	//displayItemList(currentRoom);
	std::cout << "current number of items in room: " << currentRoom->getItems().size() << std::endl;
	std::cout << "Items in room: " << std::endl;
	for (int i = 0; i < currentRoom->getItems().size(); i++)
	{
		//if(currentRoom->getItems()[i] != "")
			std::cout << currentRoom->getItems()[i] << std::endl;
	}
	std::cout << std::endl;
}


/*********************************************************************
* This function displays the opening introduction.
**********************************************************************/
void displayIntro()
{
	std::cout << std::endl << "Intro here Intro here Intro here " << std::endl << std::endl;
}


/*********************************************************************
* This function first tests to see if the player is on the bridge;
* if so, the alienKilled objective is marked as true and the 
* dependent description is also over written with an empty string.
**********************************************************************/
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


/*********************************************************************
* This function displays a help menu that lists available
* commands for use in the game.
**********************************************************************/
void displayHelpMenu()
{
	std::cout << std::endl;
	std::cout << "This is the help menu." << std::endl;
	std::cout << "This is the help menu. Max weight right now set to 5." << std::endl;
	std::cout << "This is the help menu. List available commands." << std::endl;
	std::cout << std::endl;
}


/*********************************************************************
* This function checks to see if all objectives were accomplished
* and if they are, returns 1.
**********************************************************************/
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
