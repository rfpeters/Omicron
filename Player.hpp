/**********************************************************************
 * Description: Header file for Player class for Adventure Game program
 * *******************************************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

class Player
{
	private:
		int maxInventoryWeight;
		std::vector<std::string> items;

		//can put objectives accomplished here for easy way to check to see if game over
		//ex: bool putOutFire = false;
		//ex: bool fixedEngine = false;
		//ex: bool learnOrigin = false;
		//ex: bool turnOnAutopilot = false;

	public:
		//setters
		void setMaxInventoryWeight(int);


		//getters
		int getMaxInventoryWeight();
		std::vector<std::string> getItems();

		void addItem(std::string);
		void removeItem(std::string);
};



#endif