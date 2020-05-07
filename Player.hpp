

#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
#include "hpps/Entity.h"


 
class Player2 : public Entity{
private:
	float m_X;
	float m_Y;
public:
	Player2(const std::string& textureFile,float i_x, float i_y, float i_w, float i_h);
	

};
