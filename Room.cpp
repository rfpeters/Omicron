/****************************************************************
 * Description: Methods for Room class for Adventure Game program
 * *************************************************************/

 #include "Room.hpp"

//setters
void Room::setRoomName(std::string name)
{
	roomName = name;
}

void Room::setLongDesc(std::string ldesc)
{
	longDesc = ldesc;
}

void Room::setShortDesc(std::string sdesc)
{
	shortDesc = sdesc;
}

void Room::setIsDoorN(bool doorN)
{
	isDoorN = doorN;
}

void Room::setIsDoorE(bool doorE)
{
	isDoorE = doorE;
}

void Room::setIsDoorS(bool doorS)
{
	isDoorS = doorS;
}

void Room::setIsDoorW(bool doorW)
{
	isDoorW = doorW;
}

//getters
std::string Room::getRoomName()
{
	return roomName;
}

std::string Room::getLongDesc()
{
	return longDesc;
}

std::string Room::getShortDesc()
{
	return shortDesc;
}

bool Room::getIsDoorN()
{
	return isDoorN;
}

bool Room::getIsDoorE()
{
	return isDoorE;
}

bool Room::getIsDoorS()
{
	return isDoorS;
}

bool Room::getIsDoorW()
{
	return isDoorW;
}