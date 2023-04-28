#include <iostream>
#include <queue>
namespace data
{
    struct BinaryTree
    {
        BinaryTree(): BinaryTree(0) {};

        BinaryTree(int val): data(val), left(nullptr), right(nullptr)
        {
            std::cout << "initialise node(" << this << ") with: " << data << std::endl;
        };

        ~BinaryTree()
        {
            std::cout << "deleting node(" << this << ")" << std::endl;
            delete left;
            delete right;
        }

        int data;
        BinaryTree* left;
        BinaryTree* right;
    };
};

namespace bfs
{
    void BreadthFirstSearch(data::BinaryTree* root)
    {
        // traverse the tree and print node values by level
        std::queue<data::BinaryTree*> q;
        if (root == nullptr)
            return;

        q.push(root);

        while (! q.empty())
        {
            auto currNode = q.front();
            q.pop();
            std::cout << "data:" << currNode->data << std::endl;

            if (currNode->left != nullptr)
                q.push(currNode->left);
            if (currNode->right != nullptr)
                q.push(currNode->right);
        }

        return;
    }
};

int main()
{
    auto root = new data::BinaryTree(1);
    root->left = new data::BinaryTree(2);
    root->right = new data::BinaryTree(3);
    root->left->left = new data::BinaryTree(4);
    root->left->right = new data::BinaryTree(5);
    root->right->left = new data::BinaryTree(6);
    root->right->right = new data::BinaryTree(7);

    bfs::BreadthFirstSearch(root);

    delete root;
    return 0;
}