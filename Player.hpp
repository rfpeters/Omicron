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

		//objectives and dependencies to check to see if command can be executed or if is game over
		bool fireOut;
		bool engineFueled;
		bool shipStarted;
		bool alienKilled;
		bool foodEaten;
		bool spaceSuitOn;

	public:
		//constructor
		Player();
		
		//setters
		void setMaxInventoryWeight(int);
		void setFireOut(bool);
		void setEngineFueled(bool);
		void setShipStarted(bool);
		void setAlienKilled(bool);
		void setFoodEaten(bool);
		void setSpaceSuitOn(bool);


		//getters
		int getMaxInventoryWeight();
		std::vector<std::string> getItems();
		bool getFireOut();
		bool getEngineFueled();
		bool getShipStarted();
		bool getAlienKilled();
		bool getFoodEaten();
		bool getSpaceSuitOn();


		void addItem(std::string);
		void removeItem(std::string);
};



#endif