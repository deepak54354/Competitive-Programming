#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef struct node
{
	ll data;
	node * right;
	node * left;
}node;
node * insert_tree(node * root,ll value)
{
	node * entry = new node;
	entry->left = NULL;
	entry->right = NULL;
	entry->data = value;
	node * temp = root;
	if(root == NULL)
	{
		root = entry;
		return root;
	}
	while(temp != NULL)
	{
		if(value < temp->data)
		{
			if(temp->left != NULL)
				temp=temp->left;
			else
			{
				temp->left = entry;
				break;
			}
		}
		else
		{
			if(temp->right != NULL)
				temp= temp->right;
			else
			{
				temp->right = entry;
				break;
			}
		}

	}
	return root;
}
void pre_order(node* root)
{
	if(root == NULL)
		return;
	cout << root->data << endl;
	pre_order(root->left);
	pre_order(root->right);
}
node* find_tree(node* root, ll value)
{
	node* temp = root;
	while(temp!= NULL)
	{
		if(value < temp->data)
			temp= temp-> left;
		else if(value > temp-> data)
			temp = temp->right;
		else if(value == temp->data)
			return temp;
	}
}
int main()
{
    int N;
   	ll x;
   	node* root = NULL;
    cin >> N;
   	for(int i = 0; i < N; i++)
   	{
   		cin >> x;
   		root = insert_tree(root,x);
   	}
   	ll value;
   	cin >> value;
   	pre_order(find_tree(root, value));
    return 0;
}
