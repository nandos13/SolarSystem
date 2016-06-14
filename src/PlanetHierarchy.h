#pragma once
#include "Node.h"
#include <vector>
class PlanetHierarchy
{
private:
	Node* m_root;
public:
	PlanetHierarchy();
	PlanetHierarchy(Planet* p);
	~PlanetHierarchy();

	bool isEmpty();
	bool addChild(Planet* child, Planet* parent);
	void updateAll(float dTime);
};

