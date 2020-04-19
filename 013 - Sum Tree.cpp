#include <tuple>

struct Node
{
    int data;
    Node *left, *right;
};


std::tuple<int, bool> sumTree(Node* root) {
    if (root == nullptr)
        return std::make_tuple(0, true);
    else if ((root->left == nullptr) && (root->right == nullptr))
        return std::make_tuple(root->data, true);
    
    auto left_tuple = sumTree(root->left);
    auto right_tuple = sumTree(root->right);
    
    int left_sum = std::get<0>(left_tuple);
    int right_sum = std::get<0>(right_tuple);
    
    bool is_left_sum = std::get<1>(left_tuple);
    bool is_right_sum = std::get<1>(right_tuple);
    
    int sum = root->data + left_sum + right_sum;
    bool is_sum = is_left_sum && is_right_sum && (root->data == left_sum + right_sum);
    
    return std::make_tuple(sum, is_sum);
}

// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
    // Your code here
    return std::get<1>(sumTree(root));
}