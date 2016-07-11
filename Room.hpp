/**********************************************************************
 * Description: Header file for Room class for Adventure Game program
 * *******************************************************************/


 #ifndef ROOM_HPP
 #define ROOM_HPP

#include <string>
#include <vector>

class Room
{
	private:
		std::string roomName;
		std::string longDesc;
		std::string shortDesc;
		std::vector<std::string> items;

		//for navigation, we can test to see if current room has a doorway
		bool isDoorN;
		bool isDoorE;
		bool isDoorS;
		bool isDoorW;

	public:
		//setters
		void setRoomName(std::string);
		void setLongDesc(std::string);
		void setShortDesc(std::string);
		void setIsDoorN(bool);
		void setIsDoorE(bool);
		void setIsDoorS(bool);
		void setIsDoorW(bool);

		//getters
		std::string getRoomName();
		std::string getLongDesc();
		std::string getShortDesc();
		std::vector<std::string> getItems();
		bool getIsDoorN();
		bool getIsDoorE();
		bool getIsDoorS();
		bool getIsDoorW();
		
		void addItem(std::string);

};



 #endif
