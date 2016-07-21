#pragma once
#include <vector>
#include <string>

using namespace std;

class Node {
private:
	Node *parent;
	vector <Node*> children;
	string NodeName;
	int Data;

public:
	Node();
	Node(Node* parent, vector<Node*> children);
	Node(Node* parent, vector<Node*> children, int data);
	~Node();

	void Node::SetParent(Node* parent);
	Node * GetParent();

	void SetChildren(vector<Node*> children);
	vector<Node*> GetChildren();
	void AddChildren(vector<Node*> children);
	void AddChild(Node* children);

	void SetData(int data);
	int GetData();

	void SetNodeName(string nodeName);
	string GetNodeName();

	bool IsLeaf();
	bool IsInternalNode();
	bool IsRoot();

};