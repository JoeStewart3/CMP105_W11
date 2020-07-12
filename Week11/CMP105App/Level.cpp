#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	audio->addSound("sfx/smb_jump-small.ogg", "smb_jump-small");
	// text
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("THIS IS THE GAME!\n\nB^)");
	text.setCharacterSize(24);
	text.setPosition(350, 200);
	text.setFillColor(sf::Color::Black);

	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(300, 400);
	player.setFillColor(sf::Color::Green);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(input, audio);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	window->draw(player);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}