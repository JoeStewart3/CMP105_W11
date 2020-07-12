#pragma once
#include "Framework/AudioManager.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <string.h>
#include <iostream>


class Player : public GameObject {

public:

	bool justPressedL;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f firstMousePos;
	sf::Vector2f finalMousePos;
	sf::Vector2f xyDifference;

	//functions
	//constructors/destructors
	Player();
	~Player();

	void handleInput(Input* input, AudioManager* audio);

	void update(float dt);



};