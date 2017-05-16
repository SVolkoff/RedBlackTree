#include <fstream>
#include <iostream>


typedef enum { BLACK, RED } nodeColor;



template <class T> struct Node {
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
	Node<T> * root_() const;
	Node<T>* find_node(const T& val)const;
	void deleteTr(Node<T>* temp);
	void rotate_right(Node<T> *n);
	void rotate_left(Node<T> *n);
	void insertNode(T data);
	void print()const;
	void output(std::ostream& ost, Node<T>* temp)const;
};

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
T Tree<T>:: data_() const
{
	return this->data;
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
	if (x->parent) {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else {
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
		if (x->parent) {
			if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
		}
		else {
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
		if ((data==current->data)) exit(1);
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
	if(parent==nullptr) 
			root = x;
	else {
		if ((data < parent->data))
			parent->left = x;
		else
			parent->right = x;

		while (x != root && x->parent->color == RED) 
		{
			
			if (x->parent == x->parent->parent->left) 
			{
				Node<T> *uncle = x->parent->parent->right;
				if( uncle == nullptr || uncle->color == BLACK)
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
			else {
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
