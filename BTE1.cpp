#include <iostream>
using namespace std;

struct Node{

    int id;      
    string name; 
    Node *left;   
    Node *right;  

    Node(int _id, string _name, Node *_left, Node *_right){
        id = _id;
        name = _name;
        left = _left;
        right = _right;
    }
};

class bsTree{

public:                                      
    bsTree() { root = NULL; }                 
    ~bsTree() { makeEmpty(); }               

    bool isEmpty() { return (root == NULL); } 
    void makeEmpty() { makeEmpty(root); }  

    void insert(int id, string name){
        return insert(id, name, root);
    } 

    Node *search(int id){
        return search(id, root);
    }

    Node *findParent(int val) { return findParent(root, val); }
    void insertParent(int id, string name, Node *&child) {
        return insertParent(id, name, child,root);
    }

    Node *findNode(int id) { return findNode(id, root); }

    void printTree(ostream &out = cout) const{
        return printTree(root, out);
    };

private:
    Node *root; 
    void makeEmpty(Node *&t){
        if (t == NULL) return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }

 
    void insert(int id, string name, Node *&t){
        if (t == NULL) t = new Node(id, name, NULL, NULL);
        else if (id < t->id) insert(id, name, t->left);
        else if (id > t->id) insert(id, name, t->right);
        else;
    }

    Node *search(int id, Node *t){
        if (t == NULL) return NULL;
        if (id == t->id) return t;
        if (id < t->id) return search(id, t->left);
        if (id > t->id) return search(id, t->right);
        return NULL;
    }

    void printTree(Node *t, ostream &out) const{
        if (t != nullptr){
            printTree(t->left, out);
            out << t->id << ": "<< t->name << endl;
            printTree(t->right, out);
        }
    }

    Node *findNode(int id, Node *t){
        if (t == NULL) return NULL;

        if (t->id == id) return t;

        Node *res1 = search(id, t->left);
        if (res1) return res1;

        Node *res2 = search(id, t->right);
        return res2;
    }

    Node *findParent(Node *node, int val, Node *parent = NULL){
        if (node == NULL) return NULL;
      
        if (node->id == val) return parent;
        else{
            Node *res1 = findParent(node->left, val, node);
            if (res1) return res1;
            Node *res2 = findParent(node->right, val, node);
            return res2;
        }
    }

    void changeRoot(int id, string name, Node *&t){
        root = new Node(id,name, root, NULL);
    }

    void insertParent(int id, string name, Node *&child, Node *&root){
        
        Node *cparent = findParent(child->id);
        if (cparent == NULL) changeRoot(id, name, root);
        else{
            Node *nparent = new Node (id, name ,child, NULL);
            if (cparent->left == child) cparent->left = nparent;
            else cparent->right = nparent;
        }
    }
};
int main(){

    bsTree cnp; 
    // Chen mot so sinh vien moi vao cay.
    cnp.insert(5, "Tuan");
    cnp.insert(6, "Lan");
    cnp.insert(3, "Cong");
    cnp.insert(8, "Huong");
    cnp.insert(7, "Binh");
    cnp.insert(4, "Hai");
    cnp.insert(2, "Son"); 

    // Tim hai sinh vien co so bao danh 4 va 9.
    Node *node1 = cnp.search(4);
    Node *node2 = cnp.search(9);  // khum tim thay

    // In ket qua tim kiem
    if (node1 != NULL) cout << "Sinh vien voi SBD = 4 la " << node1->name << endl;
    if (node2 == NULL) cout << "Khong tim thay sinh vien voi SBD=9" << endl; 
    cnp.printTree();
    cout <<endl;

    //them nut cha
    cnp.insertParent(11,"DANG",node1); // node1 phai ton tai trong cay
    cnp.printTree();

    Node *p1 = cnp.findParent(2);
    if (p1 != NULL) cout << "Nut cha nut co SBD = 2 la " << p1->id << endl;

    //lam rong cay
    cnp.makeEmpty();
    if (cnp.isEmpty()) cout << "Cay da bi xoa rong" << endl;
    return 0;
}
