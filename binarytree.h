#pragma once
#include<iostream>
#include<queue>
#include<stack>

namespace TREE
{
	struct Node
	{
		int mValue;
		Node* mLeft;
		Node* mRight;
		Node(int value, Node* left, Node* right)
		{
			mValue = value;
			mLeft = left;
			mRight = right;
		}
	};
	namespace BINARY
	{
		class binarytree
		{
		private:
			Node* mRoot{};
			Node* CreateNode(int value) { return new Node(value, nullptr, nullptr); }

		public:
			binarytree() { mRoot = CreateNode(0); }
			~binarytree() {};

			Node* GetRoot() { return mRoot; }
			Node* InsertLeft(Node* parent, int value) { parent->mLeft = CreateNode(value); return parent->mLeft; }
			Node* InsertRight(Node* parent, int value) { parent->mRight = CreateNode(value); return parent->mRight; }

			void Visit(Node* node) { std::cout << node->mValue << " -> "; }
			void BreathFirst()
			{
				std::queue<Node*> q;
				q.push(mRoot);
				while (!q.empty())
				{
					auto node = q.front();
					Visit(node);
					q.pop();

					if (node->mLeft != nullptr)
					{
						q.push(node->mLeft);
					}
					if (node->mRight != nullptr)
					{
						q.push(node->mRight);
					}
				}
			}
			void DepthFirst()
			{
				std::stack<Node*> s;
				s.push(mRoot);
				while (!s.empty())
				{
					auto node = s.top();
					Visit(node);
					s.pop();

					if (node->mRight != nullptr)
					{
						s.push(node->mRight);
					}

					if (node->mLeft != nullptr)
					{
						s.push(node->mLeft);
					}
				}
			}
			void DepthFirstRecursive(Node* node)
			{
				if (node == nullptr)
				{
					return;
				}

				//visit 위치에 따라 표기가 다름

				Visit(node);//pre-order
				DepthFirstRecursive(node->mLeft);
				//Visit(node);//in-order
				DepthFirstRecursive(node->mRight);
				//Visit(node);//post-order
			}
			bool Search(Node* node, int value)
			{
				if (node == nullptr)
				{
					return false;
				}

				return(node->mValue == value) || Search(node->mLeft, value) || Search(node->mRight, value);
			}
			int Sum(Node* node)
			{

				if (node == nullptr)
				{
					return 0;
				}

				return Sum(node->mLeft) + node->mValue + Sum(node->mRight);
			}
		};
	};
	namespace BINARYSEARCH
	{
		class binarysearchtree
		{
		private:
			Node* mRoot{};
			Node* CreateNode(int value) { return new Node(value, nullptr, nullptr); }

		public:
			binarysearchtree() : binarysearchtree{0} { }
			binarysearchtree(int value) { mRoot = CreateNode(value); }

			~binarysearchtree() {};

			Node* InsertNode(Node* node, int value)
			{
				if (node == nullptr)
					return CreateNode(value);

				if (node->mValue > value)
				{
					node->mLeft = InsertNode(node->mLeft, value);
				}
				else
				{
					node->mRight = InsertNode(node->mRight, value);
				}

				return node;
			}

			Node* GetRoot() { return mRoot; }

			void Visit(Node* node) { std::cout << node->mValue << " -> "; }
			int Sum(Node* node)
			{

				if (node == nullptr)
				{
					return 0;
				}

				return Sum(node->mLeft) + node->mValue + Sum(node->mRight);
			}
			void BreathFirst()
			{
				std::queue<Node*> q;
				q.push(mRoot);
				while (!q.empty())
				{
					auto node = q.front();
					Visit(node);
					q.pop();

					if (node->mLeft != nullptr)
					{
						q.push(node->mLeft);
					}
					if (node->mRight != nullptr)
					{
						q.push(node->mRight);
					}
				}
			}			
			void DepthFirst()
			{
				std::stack<Node*> s;
				s.push(mRoot);
				while (!s.empty())
				{
					auto node = s.top();
					Visit(node);
					s.pop();

					if (node->mRight != nullptr)
					{
						s.push(node->mRight);
					}

					if (node->mLeft != nullptr)
					{
						s.push(node->mLeft);
					}
				}
			}
			void DepthFirstRecursive(Node* node)
			{
				if (node == nullptr)
				{
					return;
				}

				//visit 위치에 따라 표기가 다름

				Visit(node);//pre-order
				DepthFirstRecursive(node->mLeft);
				//Visit(node);//in-order
				DepthFirstRecursive(node->mRight);
				//Visit(node);//post-order
			}
			bool Search(Node* node, int value)
			{
				if (node == nullptr) { return false; }
				if (node->mValue == value) { return true; }
				if (node->mValue > value) { Search(node->mLeft, value); }

				return Search(node->mRight, value);
			}
			Node* FindNode(Node* node, int value)
			{
				if (node->mValue == value) { return node; }
				if (node->mValue > value) { FindNode(node->mLeft, value); }

				return FindNode(node->mRight, value);
			}
			Node* minValueNode(Node* node)
			{
				if (node == nullptr)
					return nullptr;

				minValueNode(node->mLeft);

				return node;
			}
			Node* Erase(Node* node, int value)
			{
				if (node == nullptr)
					return node;

				if (node->mValue < value)
				{
					node->mRight = Erase(node->mRight, value);
				}
				else if (node->mValue > value)
				{
					node->mLeft = Erase(node->mLeft, value);
				}
				else
				{
					//자식 노드 없음
					if (node->mLeft == nullptr and node->mRight == nullptr)
						return nullptr;

					//오른쪽 자식만 존재
					else if (node->mLeft == nullptr) {
						Node* temp = node->mRight;
						delete node;
						return temp;
					}//왼쪽 자식만 존재
					else if (node->mRight == nullptr) {
						Node* temp = node->mLeft;
						delete node;
						return temp;
					}

					//자식 노드 2개 존재
					Node* temp = minValueNode(node->mRight);
					node->mValue = temp->mValue;

					// Delete the inorder successor
					node->mRight = Erase(node->mRight, temp->mValue);
				}
				return node;
			};
		};
	}
}

