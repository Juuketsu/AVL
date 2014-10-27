#define		LEFT	true
#define		RIGHT	false
#include <iostream>
#include <fstream>

class AVL
{
	private :
		AVL * 	m_leftSon = NULL;
		AVL * 	m_rightSon = NULL;
		int 	m_height;
		int 	m_value;
		int max (int, int);
		void exportRecursive (std::ofstream&);
		
	public :
		AVL (int value);
		AVL ();
		void 		insert		(int);
		bool 		isIn		(int);
		void		display		();
		void		exportAVL	();
		AVL *		joint		(AVL *, int, AVL *);
		AVL	*		jointLeft	(AVL *, int, AVL *);
		AVL *		jointRight	(AVL *, int, AVL *);
		
		// Setter, getter etc..
		void 	setLeft 	(AVL *);
		AVL *	getLeft		();
		void 	setRight	(AVL *);
		AVL *	getRight	();
		void	setHeight	(int);
		int		getHeight	();
		void	setValue	(int);
		int		getValue	();
};
