#include <stack>
#include <algorithm>

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

int height(Node* node) {
    if(node == nullptr)
        return 0;
    
    return node->height;
}

Node* rotateL(Node *root);
Node* rotateR(Node *root);

Node* deleteNode(Node* root, int data) {
    Node *del_node = root;
    
    std::stack<Node*> visited_parents;
    while (del_node != nullptr) {
        visited_parents.push(del_node);
        if (data > del_node->data) {
            del_node = del_node->right;
        } else if (data < del_node->data) {
            del_node = del_node->left;
        } else {
            break;
        }
    }
    
    if (del_node == nullptr)
        return root;
        
    visited_parents.pop();
        
    Node *del_parent = (visited_parents.empty() ? nullptr : visited_parents.top());
    bool is_left_child = (del_parent != nullptr) && (data < del_parent->data);
    
    if ((del_node->left == nullptr) && (del_node->right == nullptr)) {
        if (del_parent != nullptr) {
            if (is_left_child)
                del_parent->left = nullptr;
            else
                del_parent->right = nullptr;
        } else {
            delete del_node;
            return nullptr;
        }
        delete del_node;
        
    } else if ((del_node->left == nullptr) || (del_node->right == nullptr)) {
        
        Node *child = (del_node->left == nullptr ? del_node->right : del_node->left);
        if (del_parent != nullptr) {
            if (is_left_child)
                del_parent->left = child;
            else
                del_parent->right = child;
        } else {
            delete del_node;
            return child;
        }
        
        delete del_node;
        
    } else {
        
        Node *successor = del_node->right;
        while(successor->left != nullptr)
            successor = successor->left;
        
        del_node->data = successor->data;
        del_node->right = deleteNode(del_node->right, successor->data);
        visited_parents.push(del_node);
    }
    
    while(!visited_parents.empty()) {
        Node *parent = visited_parents.top();
        visited_parents.pop();
        
        int l_height = height(parent->left);
        int r_height = height(parent->right);
        
        if (std::abs(l_height - r_height) > 1) {
            if (l_height > r_height) {
                
                if (height(parent->left->left) < height(parent->left->right))
                    parent->left = rotateL(parent->left);
                    
                parent = rotateR(parent);
                
            } else {
                
                if (height(parent->right->right) < height(parent->right->left))
                    parent->right = rotateR(parent->right);
                    
                parent = rotateL(parent);
                
            }
        }
        
        parent->height = std::max(height(parent->left), height(parent->right)) + 1;
        
        if (visited_parents.empty()) {
            return parent;
        } else {
            Node *grand_parent = visited_parents.top();
            if (parent->data > grand_parent->data)
                grand_parent->right = parent;
            else
                grand_parent->left = parent;
        }
    }
}

Node* rotateL(Node* root) {
    if (root->right == nullptr)
        return root;
    
    Node *new_root = root->right;
    Node *temp_node = new_root->left;
    
    new_root->left = root;
    root->right = temp_node;
    
    root->height = std::max(height(root->left), height(root->right)) + 1;
    new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
    
    return new_root;
}

Node* rotateR(Node* root) {
    if (root->left == nullptr)
        return root;
    
    Node *new_root = root->left;
    Node *temp_node = new_root->right;
    
    new_root->right = root;
    root->left = temp_node;
    
    root->height = std::max(height(root->left), height(root->right)) + 1;
    new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
    
    return new_root;
}