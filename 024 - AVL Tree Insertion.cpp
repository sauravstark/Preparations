#include <stack>
#include <algorithm>

struct Node {
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node* node) {
    if(node == nullptr)
        return 0;
    
    return node->height;
}

Node* rotateL(Node* root);
Node* rotateR(Node* root);

/*You are required to complete this method */
Node* insertToAVL( Node* node, int data) {
    if (node == nullptr)
        return new Node(data);
        
    std::stack<Node*> visited_parents;
    
    Node *temp_node = node;
    while(true) {
        visited_parents.push(temp_node);
        
        if (data > temp_node->data) {
            if (temp_node->right == nullptr) {
                temp_node->right = new Node(data);
                break;
            } else {
                temp_node = temp_node->right;
            }
        } else if (data < temp_node->data){
            if (temp_node->left == nullptr) {
                temp_node->left = new Node(data);
                break;
            } else {
                temp_node = temp_node->left;
            }
        } else {
            return node;
        }
    }
    
    while(!visited_parents.empty()) {
        Node* parent = visited_parents.top();
        visited_parents.pop();
        
        int l_height = height(parent->left);
        int r_height = height(parent->right);
        
        if (std::abs(l_height - r_height) > 1) {
            if (l_height > r_height) {
                
                if (height(parent->left->left) < height(parent->left->right))
                    parent->left = rotateL(parent->left);
                parent = rotateR(parent);
                
            } else {
                
                if (height(parent->right->left) > height(parent->right->right))
                    parent->right = rotateR(parent->right);
                parent = rotateL(parent);
                
            }
        }
        
        parent->height = std::max(height(parent->left), height(parent->right)) + 1;
        
        if (visited_parents.empty()) {
            return parent;
        } else {
            Node* grand_parent = visited_parents.top();
            if (parent->data > grand_parent->data) {
                grand_parent->right = parent;
            } else {
                grand_parent->left = parent;
            }
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