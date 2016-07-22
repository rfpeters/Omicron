/****************************************************
* Description:
*****************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "Room.hpp"

void createRooms(Room[3][5], int, int);
void moveRoom(Room*, int&, int&, std::string);
int ParseUserCommand(std::string verb);
void displayRoomDesc(Room*);
void displayIntro();

int main()
{
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



	int currentX = 0;
	int currentY = 4;
	Room *currentRoom; //not quite sure we even need currentRoom since we can access everything with roomArray[currentX][currentY], only makes sense as a pointer -ML
	currentRoom = &roomArray[currentX][currentY];
	std::string d = "";
	std::string verb = "";
	std::string noun = "";


	displayIntro();
	displayRoomDesc(currentRoom);
	roomArray[currentX][currentY].setHasVisited(true);
	

/*****************game loop - start***********************/
	do {
		int verbFunction = 0;
		std::cout << "Enter your command separated by spaces: " << std::endl; // for testing purposes
		std::cout << "> ";
		std::cin >> verb >> noun;
		verbFunction = ParseUserCommand(verb);
		if (verbFunction == 1)
		{
			moveRoom(currentRoom, currentX, currentY, noun);
		}
		else if (verbFunction == 0)
		{
			std::cout << "For testing. Did not recognize command" << std::endl;
		}
		
		currentRoom = &roomArray[currentX][currentY]; //saves a copy of current room to currentRoom
		
		//for testing
		//std::cout << "After incrementing currentX and currentY, current room name is " <<
		//currentRoom->getRoomName() << "\nat " << currentX << "," << currentY << std::endl << std::endl;
		

		displayRoomDesc(currentRoom);
		roomArray[currentX][currentY].setHasVisited(true);


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
				roomArray[i][j].setRoomName(line);
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				roomArray[i][j].setLongDesc(line);
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
				roomArray[i][j].setShortDesc(line);
				
				std::getline(infile, line);
				line.erase(0, line.find(delimiter) + delimiter.length());
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

void moveRoom(Room *currentRoom, int &currentX, int &currentY, std::string d) {
	//Room roomArray[3][5];
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
		std::cout << "No door in that direction" << std::endl;

}

int ParseUserCommand(std::string verb)
{
	if (verb == "move")
	{
		std::cout << "You typed move. Now I will call the moveRooms()" << std::endl;
		return 1;
	}
	else if (verb == "grab")
	{
		std::cout << "You typed grab, this is placeholder for item function" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "I don't recognize that command." << std::endl;
		return 0;
	}

}

void displayRoomDesc(Room *currentRoom)
{
	if (currentRoom->getHasVisited() == true)
	{
		std::cout << currentRoom->getShortDesc() << std::endl << std::endl;
	}
	else
	{
		std::cout << currentRoom->getLongDesc() << std::endl << std::endl;
	}
}

void displayIntro()
{
	std::cout << std::endl << "Intro here Intro here Intro here " << std::endl << std::endl;
}
