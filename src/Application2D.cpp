#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <chrono>
#include <thread>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	unsigned int windowWitdh = 1280;
	unsigned int windowHeight = 720;
	unsigned int centerW = windowWitdh / 2;
	unsigned int centerH = windowHeight / 2;

	createWindow("A.I. Project", windowWitdh, windowHeight);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	m_dTime = 0;

	planetSun = new Planet(m_texture, nullptr, 0, 0, .2, centerW, centerH, m_spriteBatch);
	planetMercury = new Planet(m_texture, nullptr, 8, 1, 0.5, centerW, centerH, m_spriteBatch);

	m_SolarSystem = new PlanetHierarchy(planetSun);
	m_SolarSystem->addChild(planetMercury, planetSun);


	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	//m_rottts += M_PI * deltaTime;
	m_dTime = deltaTime;




	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();


	m_SolarSystem->updateAll(m_dTime);
	//m_spriteBatch->drawSprite(m_texture, 200, 200, 100, 100, m_rottts);
	//m_spriteBatch->drawText(m_font, "*not to scale bitches", 30, 30);

	// done drawing sprites
	m_spriteBatch->end();
}


