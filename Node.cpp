#include "Node.h"

Node::Node (int valeur)
	: m_value (valeur), m_height (0) {}
	
void Node::setLeft (Node * nodeToAdd)
{
	m_leftSon = nodeToAdd;
}

Node * Node::getLeft ()
{
	return m_leftSon;
}

void Node::setRight (Node * nodeToAdd)
{
	m_rightSon = nodeToAdd;
}

Node * Node::getRight ()
{
	return m_rightSon;
}

void Node::setValue (int value)
{
	m_value = value;
}

int Node::getValue ()
{
	return m_value;
}

void Node::setHeight (int height)
{
	m_height = height;
}

int Node::getHeight ()
{
	return m_height;
}

void Node::display ()
{
	std::cout << getValue() << std::endl;
	if (getLeft() != NULL)
		getLeft()->display();
	if (getRight() != NULL)
		getRight()->display();
}
