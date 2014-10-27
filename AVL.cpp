#include <unistd.h>
#include <cmath>
#include <list>

#include "AVL.h"

AVL::AVL (int value)
{
	setValue (value);
	setHeight (1);
	m_leftSon = new AVL;
	m_rightSon = new AVL;
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
		m_leftSon = new AVL;
		m_rightSon = new AVL;
		return;
	}
	
	if (getValue() == value)
	{
		std::cout 	<< "Il ne peut pas y avoir deux fois la même valeur" 
					<< std::endl;
		return;
	}
	
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
		setValue (temp->getValue());
		setHeight (temp->getHeight());
		setRight (temp->getRight());
		setLeft (temp->getLeft());
	}
}

AVL * AVL::joint (AVL * a1, int n, AVL * a2)
{
	AVL * temp = new AVL (n);
	temp->setRight (a2);
	temp->setLeft (a1);
	temp->setHeight (max (a1->getHeight(), a2->getHeight()) + 1);
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
	{
		return joint (joint (g, n, d->getLeft()), d->getValue(), d->getRight());
	}
	
	// cas 2
	return joint (joint (g, n, d->getLeft()->getLeft()),
				  d->getLeft()->getValue(),
				  joint (d->getLeft()->getRight(), d->getValue(), d->getRight()));
}

void AVL::display ()
{
	if (getValue() > 0)
	{
		std::cout << getValue () << "(" << getHeight() << ") ; ";
		if (getLeft() != NULL)
			getLeft()->display();
		if (getRight() != NULL)
			getRight()->display();
	}
}

void AVL::exportRecursive (std::ofstream& fileOut)
{
	if (getLeft()->getValue() != -1)
	{
		fileOut << getValue() << " -> " << getLeft()->getValue() << std::endl;
		getLeft()->exportRecursive (fileOut);
	}
	
	if (getRight()->getValue() != -1)
	{
		fileOut << getValue() << " -> " << getRight()->getValue() << std::endl;
		getRight()->exportRecursive (fileOut);
	}
		
	
}

void AVL::exportAVL ()
{
	std::ofstream fileOut ("AVL.dot", std::ios::out | std::ios::trunc);
	if (!fileOut)
	{
		std::cout 	<< "Problème lors de la création du fichier de sortie"
					<< std::endl;
		return;
	}
	fileOut << "digraph G{" << std::endl
			<< "graph [ordering=\"out\"];" << std::endl;
	exportRecursive (fileOut);
	fileOut << "}";
	fileOut.close ();
	
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
