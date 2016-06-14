#include "Node.h"



Node::Node()
{
	data = nullptr;
	//children.at(0) = nullptr;
}

Node::Node(Planet * p)
{
	data = p;
	//children.at(0) = nullptr;
}


Node::~Node()
{
}

bool Node::isEmpty()
{
	return (data == nullptr);
}

void Node::addChild(Planet * p)
{
	if (children.at(0) != nullptr) {
		children.push_back(new Node(p));
	}
	else {
		children.at(0) = new Node(p);
	}
	
}

Node * Node::find(Planet * p)
{
	//TODO: FINISH THIS
	//Iterate through to find if the planet is in the tree
	if (data == p) {
		return this;
	}
	for (unsigned int i = 0; i < children.size(); i++) {
		if (children.at(i)->find(p) != nullptr) {
			return (children.at(i)->find(p));
		}
	}
	//This will return the pointer which can then be used to add a child
	return nullptr;
}

void Node::update(float dTime)
{
	data->update(dTime);
	for (unsigned int i = 0; i < children.size(); i++) {
		if (children.at(i) != nullptr) 
			children.at(i)->update(dTime);
	}
}
