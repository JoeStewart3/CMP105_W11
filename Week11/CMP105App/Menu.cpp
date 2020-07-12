#include "Menu.h"


Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud) {
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/hyrulefield.ogg", "hyrulefield");

	// text
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("FUN: THE GAME 2D\n\n      Press Enter to Start");
	text.setCharacterSize(24);
	text.setPosition(350, 200);
	text.setFillColor(sf::Color::Red);
}

Menu::~Menu() {}


// handle user input
void Menu::handleInput(float dt)
{
	sf::Vector2f mousePos = sf::Vector2f(input->getMouseX(), input->getMouseY());
	if (input->isKeyDown(sf::Keyboard::Enter)){
		gameState->setCurrentState(State::LEVEL); 
		audio->playMusicbyName("cantina");
	}
}

// Update game objects
void Menu::update(float dt)
{

}

// Render level
void Menu::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Menu::beginDraw()
{
	window->clear(sf::Color::Black);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Menu::endDraw()
{
	window->display();
}