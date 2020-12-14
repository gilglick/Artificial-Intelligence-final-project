#ifndef __NODE_H
#define __NODE_H


#pragma once
class Node
{
private:
	int row, col;
	Node *parent;
	double g, h, f;
public:
	Node();
	Node(int r, int c, Node* pr, double g, double h);
	int GetRow();
	int GetCol();
	Node* GetParent();
	double GetG();
	double GetF();
	void SetRow(int r);
	void SetCol(int c);
	void SetG(double g);
	void SetH(double h);
	void ComputeF();
	void SetParent(Node* p);
	bool operator == (Node other)
	{
		return row ==other.row && col == other.col;
	}
};

#endif // !__NODE_H