#include <iostream>
#include <unistd.h>
#include <cmath>
#include <list>

#include "AVL.h"

AVL::AVL (int value)
{
	setValue (value);
	setHeight (1);
}

AVL::AVL ()
{
	setValue (-1);
	setHeight (0);
}

void AVL::insert (int value)
{
	if (getHeight() <= 0)
	{
		setValue (value);
		setHeight (1);
		return;
	}
	
	if (getValue() == value)
	{
		std::cout 	<< "Il ne peut pas y avoir deux fois la même valeur" 
					<< std::endl;
		return;
	}
	
	if (getLeft() == NULL)
		m_leftSon = new AVL;
	if (getRight() == NULL)
		m_rightSon = new AVL;
	
	if (value < getValue())
	{
		getLeft()->insert(value);
		AVL * temp = jointLeft (getLeft(), getValue(), getRight());
		setValue (temp->getValue());
		setHeight (temp->getHeight());
		setRight (temp->getRight());
		setLeft (temp->getLeft());
	}
	else
	{
		getRight()->insert(value);
		AVL * temp = jointRight (getLeft(), getValue(), getRight());
	}
}

AVL * AVL::joint (AVL * a1, int n, AVL * a2)
{
	AVL * temp = new AVL (n);
	temp->setRight (a2);
	temp->setLeft (a1);
	temp->setHeight (max (a1->getHeight(), a2->getHeight()));
	return temp;
}

AVL * AVL::jointLeft (AVL * g, int n, AVL * d)
{
	if (g->getHeight() - d->getHeight() <= 1)
		return joint (g, n, d);
	
	if (g->getLeft()->getHeight() == g->getHeight() - 1) // cas 1
		return joint (g->getLeft(), g->getValue(), joint (g->getRight(), n, d));
		
	// cas 2
	return joint (joint (g->getLeft(), g->getValue(), g->getRight()->getLeft()),
				  g->getRight()->getValue(),
				  joint (g->getRight()->getRight(), n, d));
}

AVL * AVL::jointRight (AVL * g, int n, AVL * d)
{
	if (d->getHeight() - g->getHeight() <= 1)
		return joint (g, n, d);
	
	if (d->getRight()->getHeight() == d->getHeight() - 1) // cas 1
		return joint (joint (g, n, d->getLeft()), d->getValue(), d->getRight());
	
	// cas 2
	return joint (joint (d->getRight(), d->getValue(), d->getLeft()->getRight()),
				  d->getLeft()->getValue(),
				  joint (g, n, d->getLeft()->getLeft()));
}

void AVL::display ()
{
	std::cout << getValue () << "(" << getHeight() << ") ; ";
	if (getLeft() != NULL)
		getLeft()->display();
	if (getRight() != NULL)
		getRight()->display();
}


// Setter, getter etc ...
void AVL::setHeight (int height)
{
	m_height = height;
}

int AVL::getHeight ()
{
	return m_height;
}

int AVL::max (int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void AVL::setLeft (AVL * avlToAdd)
{
	m_leftSon = avlToAdd;
}

AVL * AVL::getLeft ()
{
	return m_leftSon;
}

void AVL::setRight (AVL * avlToAdd)
{
	m_rightSon = avlToAdd;
}

AVL * AVL::getRight ()
{
	return m_rightSon;
}

void AVL::setValue (int value)
{
	m_value = value;
}

int AVL::getValue ()
{
	return m_value;
}
