#include"binarytree.h"
using namespace TREE;

int main()
{
	BINARY::binarytree btree;

	auto pRoot = btree.GetRoot();
	pRoot->mValue = 1;

	auto pNode = btree.InsertLeft(pRoot, 2);
	btree.InsertLeft(pNode, 4);
	btree.InsertRight(pNode, 5);

	pNode = btree.InsertRight(pRoot, 3);
	pNode = btree.InsertLeft(pNode, 6);
	pNode = btree.InsertRight(pNode, 7);

	

	BINARYSEARCH::binarysearchtree bstree{8};
	bstree.InsertNode(bstree.GetRoot(), 3);
	bstree.InsertNode(bstree.GetRoot(), 10);
	bstree.InsertNode(bstree.GetRoot(), 1);
	bstree.InsertNode(bstree.GetRoot(), 6);

	bstree.BreathFirst();
	std::cout << std::endl;
	bstree.Erase(bstree.GetRoot(), 8);
	bstree.BreathFirst();

	
}