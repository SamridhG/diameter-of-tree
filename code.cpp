#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
		int val;
		node *right,*left;
		node(int val)
		{
			this->val=val;
			right=left=NULL;
		}
};
class tree{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
		void insert(int data)
		{
			if(root==NULL)
			{
				root=new node(data);
			}
			else
			{
				node *current=root;
				while(true)
				{
					if(current->val>data)
					{
						if(current->left==NULL)
						{
							current->left=new node(data);
							break;
						}
						else
						{
							current=current->left;
						}
					}
					else{
						if(current->right==NULL)
						{
							current->right=new node(data);
							break;
						}
						else
						{
							current=current->right;
						}
					
					}
				}
			}
		}
		int height(node *rt)
		{
			if(rt==NULL)return 0;
			return (max(height(rt->left),height(rt->right))+1);
		}
		int diameter(node *rt)
		{
			if(rt==NULL)return 0;
			int cd=height(rt->left)+1+height(rt->right);
			int ld=diameter(rt->left);
			int rd=diameter(rt->right);
			return max(cd,max(rd,ld));
		}
		void inorder(node *rt)
		{
			if(rt==NULL)
			{
				return;
			}
			inorder(rt->left);
			cout<<rt->val<<" ";
			inorder(rt->right);	
		}
};
int main()
{
	tree A;
	A.insert(25);
	A.insert(10);
	A.insert(8);
	A.insert(7);
	A.insert(50);
	A.insert(51);
	A.insert(70);
	A.insert(80);
	A.insert(90);
	A.insert(79);
	A.insert(76);
	A.insert(48);
	A.insert(49);
	A.insert(47);
	A.insert(46);
	A.insert(45);
	A.insert(44);
	A.inorder(A.root);
	cout<<endl;
	cout<<A.diameter(A.root);
}
