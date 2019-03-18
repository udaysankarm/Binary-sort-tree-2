#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* Lft;
	Node* Rgt;
	Node* P; //pointer to parent
	Node()//constructor
	{
		Rgt=NULL;
		Lft=NULL;
	}
};
class tree		//class tree
{				
	public:				
	Node *root;		//root the main reference
	tree()			
	{			// default constructor
		root=NULL;
	}
	void Insert(int val)		// insert function
	{
		if(root==NULL)		//first insertion
		{			
		Node* temp=new Node;	/// creating new node
		temp->data=val;
		root=temp;		// assiging root to temp

		}
		else
		InsertH(root,val);	//  the insert function which actually does insertion
	}
	
	void InsertH(Node* current, int Val)		// actual insertion function which inserts elements
	{
		if(Val < current->data)		//if val is less than value of current node
		{
			if(current->Lft==NULL)		//if the left node is empty add the new node here
			{
				Node* temp=new Node;
				temp->data=Val;
				temp->P=current;
				current->Lft=temp;	
			}
			else		//else call the function again
			InsertH(current->Lft,Val);	// 	
		}
		else			// inserting on right side
		{
			if(current->Rgt==NULL)		// checking whether the left is empty or not
			{
				Node* temp=new Node;
				temp->data=Val;
				temp->P=current;
				current->Rgt=temp;	
			}
			else
			InsertH(current->Rgt,Val); //if left position is not empty call the function again
		}
			
	}
	void display()		//display function 
	{
		displayM(root);	//display main function call
	}
	void displayM(Node* current)
	{
		// base condition
		if(current==NULL)
		return;
		//display left
		displayM(current->Lft);
		//display centre
		cout<<current->data<<",";	
		//display right
		displayM(current->Rgt);
	}
	bool search(int E)		//helper search function
	{
		searchM(E,root);		//calling the maIN SEARCH FUNCTION
	}
	bool searchM(int V, Node* current)
	{
		if(current==NULL) //stopping condition
		return 0;
		else
		{
			if(current->data==V) //stopping condition
			return 1;	//returning 1
			if(V > current->data) //if the value is greater than current value 
			searchM(V,current->Rgt);
			else 		//if the v is less than current data go to the left side
			searchM(V,current->Lft); //search in the left position
		}
		
			
	}
	Node *find_min(Node* curr)	// code to find the minimum of a sub tree
	{			
		if(curr==NULL)
		return NULL;			// we are continously going from left to left brach
		else if(curr->Lft==NULL)		// check for the end of the left brached
		{
			return curr;
		}
		else
		find_min(curr->Lft);		// go on to the next left child 	
	}
	void replace_At_parent(Node *c,Node * d)	// replacing functing
	{
		Node *p=c->P;		//storing the parent node of first node 	
		Node *pa=d->P;		//storing the parent of second in a variable
		delete	c;
		if(p->Lft==c)		//check where the current node is
		p->Lft=d;		// modify the pointer(lft,Rgt of parent) to point to d 
		else
		p->Rgt=d;		// modify the pointer(lft,Rgt of parent) to point to d
		
		if(pa->Lft==d)		// check the position of second node respect to its parent 
		pa->Lft=NULL;		//modify the parent of second node
		else
		pa->Rgt=NULL;		//modify the parent of second node 	
		
		d->P=p;			// changing the parent of second node	
	}
	Node *searchP(int VL)		// function to find the position of needed node
	{
		if(search(VL))		// if the element is present
			{
				searchPM(VL,root);	// function doing the search	
			}
			else
			cout<<"\nThe element is not present\n";// element is absent
	}
	Node *searchPM(int VV,Node* curr)
	{
		if(curr==NULL)		//stopping condition
		{
		cout<<"end";
		}
		else if(curr->data==VV)	//needed condition
		return curr;
		if(VV < curr->data)
		searchPM(VV,curr->Lft);
		else
		searchPM(VV,curr->Rgt);
	}
	void Delete(int VAL)			//delete function
	{
			if(search(VAL))			//deletion should occur only if the element is present
			{
				Node *N=searchP(VAL);	//pointer to pointer to location to be deleted 
				if(N->Lft!=NULL)	//if the left location is empty
				{
					if(N->Rgt!=NULL)	//if right location is empty
					{
						
						Node *M=find_min(N->Rgt);//pointer to minimum location
						N->data=M->data;	 // storing data in the current node
						if(M->P!=N)
						M->P->Lft=NULL;		 // making the pointer to minimum null
						delete M;
					}
				}
			}
			else
			cout<<"\nThe element is not present\n";
	}
};
int main()
{
	tree A;
	Node *b;
	int AR[9]={110,45,23,42,89,34,67,99,454};
	for(int i=0;i<9;i++)
	A.Insert(AR[i]);
	A.display();
	cout<<endl<<A.search(454)<<endl;
	A.Delete(89);
	A.display();
	return 0;
}




