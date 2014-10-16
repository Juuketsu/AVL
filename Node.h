#include <iostream>

class Node
{
	private :
		Node * 	m_leftSon = NULL;
		Node *	m_rightSon = NULL;
		int		m_height;
		int 	m_value;
		
	public :
		Node (int valeur = -1);
		void 	setLeft 	(Node * nodeToAdd);
		Node *	getLeft		();
		void 	setRight	(Node * nodeToAdd);
		Node *	getRight	();
		void 	setValue	(int value);
		int		getValue	();
		void	setHeight	(int height);
		int		getHeight	();
		void 	display		();
};
