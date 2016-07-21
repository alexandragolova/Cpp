#include "Node.h"
#include<vector>
Node::Node() {
	this->parent = NULL;
	this->children.clear();
	this->Data = 0;
}

Node::~Node() {
	delete[] parent;
	children.clear();
}

Node::Node(Node* parent, vector<Node*> children) {
	this->parent = parent;
	this->children = children;
}

Node::Node(Node* parent, vector<Node*> children, int data) {
	this->parent = parent;
	this->children = children;
	this->Data = data;
}

Node* Node::GetParent() {
	return this->parent;
}

void Node::SetChildren(vector<Node*> children) {
	this->children = children;
}

vector<Node*> Node::GetChildren() {
	return children;
}

void Node::AddChildren(vector<Node*> children) {
	for (size_t i = 0; i < children.size(); i++)
	{
		this->children.push_back(children[i]);
	}
}

void Node::AddChild(Node* children) {
	this->children.push_back(children);
}

void Node::SetParent(Node* parent) {
	this->parent = parent;
}

void Node::SetData(int data) {
	this->Data = data;
}

int Node::GetData() {
	return this->Data;
}

bool Node::IsLeaf()
{
	return children.size() == 0;
}

bool Node::IsInternalNode()
{
	return (parent != NULL && children.size() != NULL);
}

bool Node::IsRoot()
{
	return !(parent == NULL);
}

void Node::SetNodeName(string nodeName)
{
	NodeName = nodeName;
}
string Node::GetNodeName()
{
	return NodeName;
}