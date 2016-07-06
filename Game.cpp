/****************************************************
* Description:
*****************************************************/

#include <iostream>

#include "Room.hpp"


int main()
{
	int x = 3;  //horizontal
	int y = 5;	//vertical
	int i, j;
	Room roomArray[x][y];



/****************** START OF HARD CODING ROOMS - TO BE DELETED***********************/
	for (i = 0; i < x; i++)
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
	}

/****************** END OF HARD CODING ROOMS - TO BE DELETED***********************/

////START OF ROOM CREATION TESTING
	for (i = 0; i < x; i++)
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

	}

////END OF ROOM CREATION TESTING

	return 0;
}