#include<iostream>
#include"Node.h"
using namespace std;

bool IsDigit(char c)
{
	return c >= '0' && c <= '9';
}

int CreateNumber(string number)
{
	int result = 0;
	for (size_t i = 0; i < number.length(); i++)
	{
		result += (pow(10, number.length() - i - 1) * ((int)number[i] - '0'));
	}
	return result;
}

void BuildTree(string treeStr, int currentIndex, Node* parent)
{
	if (treeStr.length() == currentIndex)
		return;

	if (treeStr[currentIndex] == '(')
	{
		currentIndex++;
		string digit = "";

		if (IsDigit(treeStr[currentIndex]))
		{
			while (IsDigit(treeStr[currentIndex]))
			{
				digit += treeStr[currentIndex];
				currentIndex++;
			}
		}
		int newDigit = CreateNumber(digit);
		Node* child = new Node();
		child->SetData(newDigit);
		child->SetParent(parent);
		parent->AddChild(child);
		BuildTree(treeStr, currentIndex, child);
		return;
	}

	if (treeStr[currentIndex] == '{')
	{
		currentIndex++;
		BuildTree(treeStr, currentIndex, parent);
		return;
	}

	if (treeStr[currentIndex] == ')')
	{
		currentIndex++;
		BuildTree(treeStr, currentIndex, parent->GetParent());
		return;
	}

	if (treeStr[currentIndex] == '}')
	{
		currentIndex++;
		BuildTree(treeStr, currentIndex, parent);
		return;
	}
}

void PrintTree(Node* node, int indent)
{
	int size = node->GetChildren().size();
	for (int i = 0; i < indent; i++)
		cout << ' ';
	cout << node->GetData() << endl;

	if (size != 0) {

		vector<Node*>children = vector<Node*>();
		children = node->GetChildren();

		for (size_t i = 0; i < size; i++)
		{
			PrintTree(children[i], indent + 1);
		}
	}
	else return;
}

void Sort(vector<Node*> chldren, int size)
{
	string tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j > 0; j--)
		{
			int node1 = atoi(chldren[j]->GetNodeName().c_str());
			int node2 = atoi(chldren[j - 1]->GetNodeName().c_str());
			if (node1 < node2)
			{
				tmp = chldren[j - 1]->GetNodeName();
				chldren[j - 1]->SetNodeName(chldren[j]->GetNodeName());
				chldren[j]->SetNodeName(tmp);
			}
		}
	}
}

void Ahu(Node* node)
{
	if (node->GetChildren().size() == 0)
		node->SetNodeName("10");
	else
	{
		for (size_t i = 0; i < node->GetChildren().size(); i++)
			Ahu(node->GetChildren()[i]);

		int childrenNum = node->GetChildren().size();
		Sort(node->GetChildren(), childrenNum);

		string nodeChildrenName = "";
		for (size_t i = 0; i < node->GetChildren().size(); i++)
			nodeChildrenName += node->GetChildren()[i]->GetNodeName();
		node->SetNodeName(nodeChildrenName);

		//string nodeName = '(' + node->GetNodeName + ')';
		string nodeName = '1' + node->GetNodeName() + '0';
		node->SetNodeName(nodeName);
	}
}

bool IsIsomorphic(string node1, string node2)
{
	return node1.compare(node2) == 0;
}

int main()
{
	//Test 
	//True
	//string tree1 = "(5{(1{(4{})(8{})(9{})})(9{})})";
	//string tree2 = "(5{(9{})(1{(4{})(8{})(9{})})})";

	//True
	//string tree1 = "(5{(9{})(1{(4{})(8{})(9{})})})";
	//string tree2 = "(5{(9{})(1{(4{})(8{})(9{})})})";

	//False
	//string tree1 = "(5{(9{})(1{(4{})(12{})(42{})})})";
	//string tree2 = "(7{(15{(7{})(10{})})(3{})})";
	

	string tree1 = "";
	string tree2 = "";

	cout << "Input tree: ";
	cin >> tree1;
	cout << "Input tree: ";
	cin >> tree2;

	Node* node1 = new Node();
	Node* node2 = new Node();

	BuildTree(tree1, 0, node1);
	BuildTree(tree2, 0, node2);

	PrintTree(node1, 0);
	cout << endl;
	PrintTree(node2, 0);

	Ahu(node1);
	Ahu(node2);

	if (IsIsomorphic(node1->GetNodeName(), node2->GetNodeName()) == true)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}