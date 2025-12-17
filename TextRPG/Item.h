#pragma once
#include <string>

class Item
{
public:
	std::string name;
	int score; //공격력 증가량 혹은 회복량 등등

	Item(std::string n,int s) : name(n), score(s) {}

	virtual ~Item(){}

};

