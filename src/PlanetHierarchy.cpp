#include "PlanetHierarchy.h"



PlanetHierarchy::PlanetHierarchy()
{
	m_root = nullptr;
}

PlanetHierarchy::PlanetHierarchy(Planet * p)
{
	m_root = new Node(p);
}


PlanetHierarchy::~PlanetHierarchy()
{
}

bool PlanetHierarchy::isEmpty()
{
	if (m_root->data == nullptr) return true;
	return false;
}

bool PlanetHierarchy::addChild(Planet * child, Planet * parent)
{
	// return true if the parent was found, false if it doesnt exist
	Node* temp = (m_root->find(parent));
	if (temp != nullptr) {
		//Parent was found, add child
		temp->addChild(child);
		child->setParent(parent);
		return true;
	}
	else {
		//No Parent, child will not be added
		return false;
	}
}

void PlanetHierarchy::updateAll(float dTime)
{
	m_root->update(dTime);
}
