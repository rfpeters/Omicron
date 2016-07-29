/****************************************************************
 * Description: Methods for Player class for Adventure Game program
 * *************************************************************/

#include "Player.hpp"

//setters
void Player::setMaxInventoryWeight(int w)
{
	maxInventoryWeight = w;
}


//getters
int Player::getMaxInventoryWeight()
{
	return maxInventoryWeight;
}

std::vector<std::string> Player::getItems()
{
	return items;
}

void Player::addItem(std::string item)
{
	items.push_back(item);
}

void Player::removeItem(std::string item)
{
	
}