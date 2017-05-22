#include <fstream>
#include <iostream>


typedef enum { BLACK, RED } nodeColor;
template <class T> struct Node 
{
	Node<T>* left;
	Node<T>* right;       
	Node<T>* parent;       
	nodeColor color;           
	T data;                   
};
  

template <class T> class Tree
{
private:
	Node<T>*root;

public:
	Tree();
	~Tree();
	T data_() const;
	Node<T> * left_() const;
	Node<T> * right_() const;
	Node<T> * root_() const;
	Node<T>* find_node(const T& val)const;
	void deleteTr(Node<T>* temp);
	void rotate_right(Node<T> *n);
	void rotate_left(Node<T> *n);
	void insertNode(T data);
	void print()const;
	void output(std::ostream& ost, Node<T>* temp)const;
	void deleteNode(Node<T> *z);
	void deleteFixup(Node<T> *x);
	void deleteVal(const T &val);
	bool operator ==(const Tree<T> &a);
	bool equality(Node<T>* root2, const Node<T>* root1);
	//friend ostream& operator << (std::ostream& ost, Tree<T> *tr)const;
	void display(Node<T>* temp,  unsigned int level)const;
	
};
template<class T>
bool Tree<T>::operator ==(const Tree<T> &a)
{

	return equality(root, a.root);

};
template<class T>
 bool Tree<T>::equality(Node<T>* root2, const Node<T>* root1)
{
	return (root2&&root1 ? root2->data == root1->data&&equality(root2->left, root1->left) && equality(root2->right, root1->right) : !root2 && !root1);
};

 template<typename T>
 void Tree<T>::display(Node<T>* temp, unsigned int level)const
 {
	  if (temp)
	 {
		 display(temp->left,  level + 1);
		 for (unsigned int i = 0; i < level; i++)
			 std::cout << "-";
		 std::cout << temp->data << "\n";
		 display(temp->right,  level + 1);
	 }
 }

template<class T>
Tree<T>::Tree()
{
	root = nullptr;

}

template<class T>
Tree<T>::~Tree()
{
	deleteTr(root);
}

template<class T>
T Tree<T>::data_() const
{
	return this->data;
}
template<class T>
Node<T> * Tree<T>::left_() const
{
	return root->left;
}
template<class T>
Node<T> * Tree<T>::right_() const
{
	return root->right;
}
template<class T>
Node<T> * Tree<T>::root_() const
{
	return root;
}

template<class T>
void Tree<T>::deleteTr(Node<T>* temp)
{
	if (!temp)
		return;
	if (temp->left)
	{
		deleteTr(temp->left);
		temp->left = nullptr;
	}

	if (temp->right)
	{
		deleteTr(temp->right);
		temp->right = nullptr;
	}
	delete temp;
}


template<class T>
void Tree<T>::rotate_left(Node<T> *x)
{
	Node<T> *y = x->right;
	x->right = y->left;
	if (y->left != nullptr) y->left->parent = x;
	if (y != nullptr) y->parent = x->parent;
	if (x->parent) 
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else 
	{
		root = y;
	}
	y->left = x;
	if (x != nullptr) x->parent = y;
}

template<class T>
void Tree<T>::rotate_right(Node<T> *x)
{
	Node<T> *y = x->left;
	x->left = y->right;
	if (y->right != nullptr) y->right->parent = x;
	if (y != nullptr) y->parent = x->parent;
	if (x->parent) 
	{
		if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	else 
	{
		root = y;
	}

	y->right = x;
	if (x != nullptr) x->parent = y;
}

template<class T>
void Tree<T>::insertNode(T data)
{
	Node<T> *current;
	Node<T> *parent;
	Node<T> *x;
	current = root;
	parent = nullptr;
	while (current != nullptr)
	{
		if ((data == current->data)) exit(1);
		parent = current;
		if (data < current->data)
			current = current->left;
		else current = current->right;
	}

	x = new Node<T>;
	x->data = data;
	x->parent = parent;
	x->left = nullptr;
	x->right = nullptr;
	x->color = RED;
	if (parent == nullptr)
		root = x;
	else {
		if ((data < parent->data))
			parent->left = x;
		else
			parent->right = x;

		while (x != root && x->parent->color == RED)
		{
			
			if (x->parent == x->parent->parent->left) {
				Node<T> *uncle = x->parent->parent->right;
				if (uncle == nullptr || uncle->color == BLACK)
				{
					
					if (x == x->parent->right) 
					{
						x = x->parent;
						rotate_left(x);
					}
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					rotate_right(x->parent->parent);
				}
				else
				{
					x->parent->color = BLACK;
					uncle->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				}
			}
			else
			{

				Node<T> *uncle = x->parent->parent->left;
				if (uncle == nullptr || uncle->color == BLACK)
				{
					if (x == x->parent->left) 
					{
						x = x->parent;
						rotate_right(x);
					}
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					rotate_left(x->parent->parent);
				}
				else
				{
					x->parent->color = BLACK;
					uncle->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				}

			}
		}
	}
	root->color = BLACK;
}
template<typename T>
void Tree<T>::print() const
{
	output(std::cout, this->root);
}
template<typename T>
void Tree<T>::output(std::ostream& ost, Node<T>* temp)const
{
	if (!temp) return;
	ost << temp->data << " ";
	output(ost, temp->left);
	output(ost, temp->right);
}

template<class T>
Node<T>* Tree<T>::find_node(const T& val)const
{
	Node<T> *current = root;
	while (current != nullptr)
	{
		if (val == current->data)
			return current;
		else
		{
			if (val < current->data)
				current = current->left;
			else current = current->right;
		}
	}
	return current;
}

template<typename T>
void Tree<T>:: deleteFixup(Node<T> *x)
{
	while (x != root && x->color == BLACK) 
	{
		if (x == x->parent->left)
		{
			Node<T> *w = x->parent->right;
			if (w->color == RED) 
			{
				w->color = BLACK;
				x->parent->color = RED;
				rotate_left(x->parent);
				w = x->parent->right;
			}
			if ((w->right == nullptr||w->right->color == BLACK) && (w->left == nullptr ||w->left->color == BLACK ))
			{
				w->color = RED;
				x = x->parent;
			}
			else 
			{
				if (w->right == nullptr || w->right->color == BLACK) 
				{
					w->left->color = BLACK;
					w->color = RED;
					rotate_right(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rotate_left(x->parent);
				x = root;
			}
		}
		else 
		{
			Node<T> *w = x->parent->left;
			if ( w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				rotate_right(x->parent);
				w = x->parent->left;
			}
			if ((w->right== nullptr || w->right->color == BLACK)&&(w->left == nullptr || w->left->color == BLACK))
			{
				w->color = RED;
				x = x->parent;
			}
			else 
			{
				if (w->left == nullptr || w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					rotate_left(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rotate_right(x->parent);
				x = root;
			}
		}
	}
	if (x) x->color = BLACK;
}
template<typename T>
void Tree<T>::deleteNode(Node<T> *z)
{
	Node<T> *x, *y;

	if (z == nullptr) exit(2);

	if (z->left == nullptr || z->right == nullptr)
	{
		y = z;
	}
	else
	{
		y = z->right;
		while (y->left != nullptr) y = y->left;
	}

	/* x is y's only child */
	if (y->left != nullptr)
		x = y->left;
	else
		x = y->right;
	bool f=0;
	if (x == nullptr)
	{
		x = new Node <T>;
		x->left = nullptr;
		x->right = nullptr;
		x->color = BLACK;
		f = 1;
		x->data = 0;

	}
	x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	else
		root = x;

	if (y != z) z->data = y->data;

	if (y->color == BLACK)
			deleteFixup(x);
	if (f)
	{
		if (x->parent)
		{
			if (x == x->parent->left)
				x->parent->left = nullptr;
			else
				x->parent->right = nullptr;
			free(x);
		}
		else
		{
			free(root);
			root = nullptr;
		}
	}
	free(y);
}

template<typename T>
void Tree<T>::deleteVal(const T &val)
{
	deleteNode(find_node(val));
};
