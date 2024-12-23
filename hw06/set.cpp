#include <iostream>

struct tree_node {
    int value;
    tree_node* left;
    tree_node* right;

    tree_node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class bst {
    tree_node* top;

    tree_node* findMin(tree_node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    tree_node* removeHelper(tree_node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->value) {
            root->left = removeHelper(root->left, value);
        } else if (value > root->value) {
            root->right = removeHelper(root->right, value);
        } else {
            if (root->left == nullptr) {
                tree_node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                tree_node* temp = root->left;
                delete root;
                return temp;
            }

            tree_node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = removeHelper(root->right, temp->value);
        }
        return root;
    }


    int bigger_than_x_helper(int x, tree_node* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->value <= x) {
            return bigger_than_x_helper(x, root->right);
        } else {
            return 1 + bigger_than_x_helper(x, root->left) + bigger_than_x_helper(x, root->right);
        }
    }

public:
    bst() : top(nullptr) {}

    void insert(int value) {
        tree_node* newNode = new tree_node(value);
        if (top == nullptr) {
            top = newNode;
            return;
        }
        tree_node* p = top;
        while (p->value != value) {
            if (p->value > value) {
                if (p->left == nullptr) {
                    p->left = newNode;
                    return;
                }
                p = p->left;
            } else {
                if (p->right == nullptr) {
                    p->right = newNode;
                    return;
                }
                p = p->right;
            }
        }
    }

    void enquire(int value) {
        tree_node* p = top;
        while (p != nullptr) {
            if (p->value == value) {
                std::cout << 1 << std::endl;
                return;
            }
            if (p->value > value) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        std::cout << 0 << std::endl;
    }

    void remove(int value) {
        top = removeHelper(top, value);
    }

    void bigger_than_x(int x) {
        int count = bigger_than_x_helper(x, top);
        std::cout << count << std::endl;
    }
};

int main() {
    int num = 0;
    std::cin >> num;
    bst _bst;

    for (int i = 0; i < num; i++) {
        int method;
        int value;
        std::cin >> method >> value;

        if (method == 1) {
            _bst.insert(value);
        } else if (method == 2) {
            _bst.enquire(value);
        } else if (method == 3) {
            _bst.remove(value);
        } else if (method == 4) {
            _bst.bigger_than_x(value);
        } else {
            return -1;
        }
    }

    return 0;
}