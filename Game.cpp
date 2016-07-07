/****************************************************
* Description:
*****************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "Room.hpp"

void createRooms(Room[3][5], int, int);

int main()
{
	int x = 3;  //horizontal
	int y = 5;	//vertical
	int i, j;
	Room roomArray[3][5];

	createRooms(roomArray, x, y);

/****************** START OF HARD CODING ROOMS - TO BE DELETED***********************/
	/*for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			roomArray[i][j].setRoomName("room name");
			roomArray[i][j].setLongDesc("dfjksdjfklsjdsafksjdjafhjdsfjk");
			roomArray[i][j].setShortDesc("short description");
			roomArray[i][j].setIsDoorN(true);
			roomArray[i][j].setIsDoorE(false);
			roomArray[i][j].setIsDoorS(true);
			roomArray[i][j].setIsDoorW(false);
			//can create a constructor is that will be easier
		}
	}*/

/****************** END OF HARD CODING ROOMS - TO BE DELETED***********************/

////START OF ROOM CREATION TESTING
	/*for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			std::cout << roomArray[i][j].getRoomName() << std::endl;
			std::cout << roomArray[i][j].getLongDesc() << std::endl;
			std::cout << roomArray[i][j].getShortDesc() << std::endl;
			std::cout << roomArray[i][j].getIsDoorN() << std::endl;
			std::cout << roomArray[i][j].getIsDoorE() << std::endl;
			std::cout << roomArray[i][j].getIsDoorS() << std::endl;
			std::cout << roomArray[i][j].getIsDoorW() << std::endl << std::endl;
		}

	}*/

////END OF ROOM CREATION TESTING

	return 0;
}

void createRooms(Room roomArray[3][5], int x, int y)
{
	std::string line;
	std::string data;
	std::string delimiter = ":";
	std::ifstream infile;
	std::string roomFiles[2] = {"testroom.txt", "testroom2.txt"};
	
	
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{			
			infile.open(roomFiles[j].c_str());
			
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
				//can create a constructor is that will be easier
				infile.close();
			}
			else
			{
				std::cout << "Could not open file: " << roomFiles[j].c_str() << std::endl;
			}
		}	
	}
	
	
	std::cout << roomArray[0][0].getRoomName() << std::endl;
	std::cout << roomArray[0][0].getLongDesc() << std::endl;
	std::cout << roomArray[0][0].getShortDesc() << std::endl;
	std::cout << roomArray[0][0].getIsDoorN() << std::endl;
	std::cout << roomArray[0][0].getIsDoorE() << std::endl;
	std::cout << roomArray[0][0].getIsDoorS() << std::endl;
	std::cout << roomArray[0][0].getIsDoorW() << std::endl << std::endl;
	
	std::cout << roomArray[0][1].getRoomName() << std::endl;
	std::cout << roomArray[0][1].getLongDesc() << std::endl;
	std::cout << roomArray[0][1].getShortDesc() << std::endl;
	std::cout << roomArray[0][1].getIsDoorN() << std::endl;
	std::cout << roomArray[0][1].getIsDoorE() << std::endl;
	std::cout << roomArray[0][1].getIsDoorS() << std::endl;
	std::cout << roomArray[0][1].getIsDoorW() << std::endl << std::endl;
}