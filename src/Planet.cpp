#include "Planet.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#define _USE_MATH_DEFINES
#include <math.h>



Planet::Planet()
{
	m_rotationSpeed = 1;
	m_rotAngle = 0;
	//m_pos.m_x = 0;
	//m_pos.m_y = 0;
	//m_pos.m_z = 1;
	m_parent = nullptr;
	m_planetTexture = new Texture("./bin/textures/crate.png");
	m_spriteBatchPlanet = new SpriteBatch();
}

Planet::Planet(Texture * tex, Planet * parent, float rotateSpeed, float orbitSpeed, float scale, float posX, float posY, SpriteBatch * pSpriteBatch)
{
	m_parent = parent;
	m_planetTexture = tex;
	m_spriteBatchPlanet = pSpriteBatch;


	m_rotationSpeed = rotateSpeed;
	m_rotAngle = 0;
	m_orbitSpeed = orbitSpeed;
	m_orbitAngle = 0;
	
	m_scaleMatrix = Matrix3::CreateScale(Vector3(scale, scale, 1));
	m_rotationMatrix = Matrix3::CreateRotationZ(m_rotAngle);
	m_translationMatrix = Matrix3::CreateTranslation(posX, posY);
	m_positionMatrix = Matrix3::CreateRotationZ(m_orbitAngle);

	//m_localTransform = scaleMatrix * rotationMatrix * translationMatrix;
	m_localTransform = m_translationMatrix * m_rotationMatrix * m_scaleMatrix;

}

Planet::~Planet()
{
}

void Planet::setParent(Planet * p)
{
	m_parent = p;
}

void Planet::update(float dTime)
{
	//Update Rotation
	m_rotAngle += m_rotationSpeed * dTime;
	m_rotationMatrix = Matrix3::CreateRotationZ(m_rotAngle);

	//Change Local Orbit position
	m_orbitAngle += m_orbitSpeed * dTime;
	m_positionMatrix = Matrix3::CreateRotationZ(m_orbitAngle);
	
	
	//Calculate new transform matrix based on above changes
	m_localTransform = m_translationMatrix * m_rotationMatrix * m_scaleMatrix;
	

	if (m_parent != nullptr) {
		//Has parent
		//m_localTransform = m_positionMatrix * m_rotationMatrix * m_translationMatrix * m_scaleMatrix;
		m_localTransform = m_positionMatrix * m_localTransform;
		m_globalTransform = (m_parent->m_globalTransform) * m_localTransform;
	}
	else {
		//No parent, update independently
		m_globalTransform = m_localTransform;
	}
	//m_pos = m_pos * m_globalTransform;

	m_spriteBatchPlanet->drawSpriteTransformed3x3(m_planetTexture, m_globalTransform);
}