#define		LEFT	true
#define		RIGHT	false
#include <iostream>

class AVL
{
	private :
		AVL * 	m_leftSon = NULL;
		AVL * 	m_rightSon = NULL;
		int 	m_height;
		int 	m_value;
		int max (int a, int b);
		
	public :
		AVL (int value);
		AVL ();
		void 	insert		(int value);
		bool 	isIn		(int value);
		void	display		();
		AVL *	joint		(AVL * a1, int n, AVL * a2);
		AVL	*	jointLeft	(AVL * g, int n, AVL * d);
		AVL *	jointRight	(AVL * g, int n, AVL * d);
		
		// Setter, getter etc..
		void 	setLeft 	(AVL * avlToAdd);
		AVL *	getLeft		();
		void 	setRight	(AVL * avlToAdd);
		AVL *	getRight	();
		void	setHeight	(int height);
		int		getHeight	();
		void	setValue	(int value);
		int		getValue	();
};
