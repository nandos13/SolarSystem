#pragma once

#include "BaseApplication.h"
#include "PlanetHierarchy.h"

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

protected:

	SpriteBatch*		m_spriteBatch;
	Texture*			m_texture;
	Font*				m_font;
	//float				m_rottts;
	float				m_dTime;

	Planet*				planetSun;
	Planet*				planetMercury;

	PlanetHierarchy*	m_SolarSystem;
};