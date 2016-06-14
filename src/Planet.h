#pragma once
#include "BaseApplication.h"
#include "Vector3.h"
#include "Matrix3.h"
class SpriteBatch;
class Texture;
class Font;

class Planet {
private:
	float			m_rotationSpeed, m_rotAngle;
	float			m_orbitSpeed, m_orbitAngle;
	Matrix3			m_localTransform, m_globalTransform;
	Matrix3			m_scaleMatrix, m_rotationMatrix, m_translationMatrix, m_positionMatrix;
	Texture*		m_planetTexture;
	Planet*			m_parent;
	SpriteBatch*	m_spriteBatchPlanet;
public:
	Planet();
	Planet(Texture * tex, Planet* parent, float rotateSpeed, float orbitSpeed, float scale, float posX, float posY, SpriteBatch * pSpriteBatch);
	~Planet();

	void setParent(Planet* p);
	void update(float dTime);
};