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
	int MAX_X = 3;  //horizontal
	int MAX_Y = 5;	//vertical
	int i, j;
	Room roomArray[3][5];

	createRooms(roomArray, MAX_X, MAX_Y);


////START OF ROOM CREATION TESTING
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
			std::cout << roomArray[i][j].getIsDoorW() << std::endl << std::endl;
		}

	}

////END OF ROOM CREATION TESTING



/*****************for navigation - start************************/

	int currentX = 1;	//starts at science lab (1,1)
	int currentY = 1;
	Room currentRoom;
	currentRoom = roomArray[currentX][currentY];	//starts at science lab
	//if doorN is true currentY++
	//if doorE is true currentX++
	//if doorS is true currentY--
	//if doorW is true currentX--
	//then assign to currentRoom

	//////test current room and navigation - start
	std::cout << "current room name is " << currentRoom.getRoomName() << "\nat " << currentX << "," << currentY << std::endl << std::endl;
	currentX++;
	currentY++;
	currentRoom = roomArray[currentX][currentY];
	std::cout << "After incrementing currentX and currentY, current room name is " << 
					currentRoom.getRoomName() << "\nat " << currentX << "," << currentY << std::endl << std::endl;
					//room names seems to be storing /r. will probably be fine.
					//http://stackoverflow.com/questions/14295420/c-cout-overwriting-itself-while-in-for-loop
	//////test current room and navigation - end

/*****************for navigation - end************************/


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

			fileIndex++;
		}	
	}
	
/*	
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
*/
}