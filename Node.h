struct Node {
    Node* parent;
    int num;

    Node* createChild(int number);
};

Node* Node::createChild(int number)
{
    Node* newNode = new Node;
    newNode->parent = this;
    newNode->num = number;

    return newNode;
}