/*
Yumee Chung
A01712059

Fecha: lunes, 07 de octubre de 2024

Materia: Programación de estructuras de datos y algoritmos fundamentales
 
Tarea5: Arbol Busqueda Binaria 
*/

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <sstream>
#include <string>

template <class T> class BST;

template <class T>
class Node{
    private:
        T value;
        Node *left, *right;
    public:
        Node(T);
        Node(T, Node<T>*, Node<T>*);
        void add(T);
        bool find(T);
        void inorder(std::stringstream&) const;
        void preorder(std::stringstream&) const;
        void postorder(std::stringstream&) const;
        void levelbylevel(std::stringstream&) const;
        int height() const;
        int whatlevelamI(T,int);

        friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri) : value(val), left(le), right(ri) {} 

template <class T>
void Node<T>::add(T val) { 
    if (val < value) {
        if (left != 0) {
            left->add(val);
        } else {
            left = new Node<T>(val);
        }
    } else {
        if (right != 0) {
            right->add(val);
        } else {
            right = new Node<T>(val);
        }
    }
}

template <class T>
bool Node<T>::find(T val) {
    if (val == value) {
        return true;
    } else if (val < value) {
        return (left != 0 && left->find(val));
    } else {
        return (right != 0 && right->find(val));
    }
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
    aux << value;
    if (left != 0) {
        aux << " ";
        left->preorder(aux);
    }
    if (right != 0) {
        aux << " ";
        right->preorder(aux);
    }
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
    if (left != 0) {
        left->inorder(aux);
        aux << " ";
    }

    aux << value;

    if (right != 0) {
        aux << " ";
        right->inorder(aux);
    }
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
    if (left != 0) {
        left->postorder(aux);
        aux << " ";
    }
    if (right != 0) {
        right->postorder(aux);
        aux << " ";
    }

    aux << value;
}

template <class T>
void Node<T>::levelbylevel(std::stringstream &aux) const {
    
    aux << value;

    if(left != 0){
        aux << " ";
        left->levelbylevel(aux);
    }

    if(right != 0){
        aux << " ";
        right->levelbylevel(aux);
    }
}

template <class T>
int Node<T>::whatlevelamI(T val, int level) { 
    if (value == val) {
        return level+1; 
    }
    if (val < value && left) {
        return left->whatlevelamI(val, level + 1); 
    }
    if (val > value && right) {
        return right->whatlevelamI(val, level + 1); 
    }
}

template <class T>
int Node<T>::height() const{
    int hl = 0;
    int hr = 0;

    if(left != 0){
        hl = left->height();
    }

    if(right != 0){
        hr = right->height();
    }

    if (hl > hr) {
        return 1 + hl; 
    } else {
        return 1 + hr; 
    }
}

template <class T>
class BST {
    private:
        Node<T> *root;
    public:
        BST();
        bool empty() const;
        bool find(T) const;
        void add(T);
        std::string visit();
        int height();
        std::string ancestors(T);
        int whatlevelamI(T);
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
bool BST<T>::empty() const {
    return (root == 0);
}

template <class T>
void BST<T>::add(T val) {
    if (root != 0) {
        if (!root->find(val)) {
            root->add(val);
        }
    } else {
        root = new Node<T>(val);
    }
}

template <class T>
bool BST<T>::find(T val) const {
    if (root != 0) {
        return root->find(val);
    }
    return false;
}

template <class T>
std::string BST<T>::visit() {
    std::stringstream aux;

    if(!empty()){
        aux << "[";
        root->preorder(aux);
        aux << "]\n";

        aux << "[";
        root->inorder(aux);
        aux << "]\n";

        aux << "[";
        root->postorder(aux);
        aux << "]\n";

        aux << "[";
        root->levelbylevel(aux);
        aux << "]";
    }
    return aux.str();
}

template <class T>
int BST<T>::height() {
    if (root) {
        return root->height();
    }
    return 0; 
}

template <class T>
std::string BST<T>::ancestors(T val) {
    std::stringstream aux;
    Node<T> *p = root;

    aux << "[";
    while (p != 0 && val != p->value) {

        if (aux.tellp() > 1)
            aux << " ";

        aux << p->value;

        if (val < p->value){
            p = p->left;
        } else {
            p = p->right;
        }

        if (p == 0)
        return "[]";

    }
    
    aux << "]";
    return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val) {
    if (root) {
        return root->whatlevelamI(val, 0);
    } 
}

#endif




