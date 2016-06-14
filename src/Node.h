#pragma once
#include <vector>
#include "Planet.h"
class Planet;
class Node
{
public:
	Planet* data;
	std::vector<Node*> children{ nullptr };
	Node();
	Node(Planet* p);
	~Node();

	bool isEmpty();
	void addChild(Planet* p);
	Node* find(Planet* p);
	void update(float dTime);
};

