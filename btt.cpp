#include<iostream>
using namespace std;

class btt

{
 struct btt_node
{
 int data;
 int lflag;
 int rflag;
 btt_node *l;
 btt_node *r;
}*root,*header;

 public:
  void create();
  void btt_pre();
  void btt_post();
  void btt_in();
};

void btt::create()
{
 btt_node *t, *curr;
 char ans;
 header=new btt_node;
 header->data=-999;
 header->l=header;
 header->r=header;

 root=new btt_node;
 cout<<"\n Enter the data of root node :";
 cin>>root->data;
 root->l=header;
 root->r=header;
 root->lflag=0;
 root->rflag=0;
 header->l=root;
 do{
    t=new btt_node;
    cout<<"\n Enter data :";
    cin>>t->data;
    t->lflag=0;
    t->rflag=0;
    curr=root;
    while(1)
    {
    if(t->data < curr->data)
    {
     if(curr->lflag==0)
     {
      t->l=curr->l;   // LEFT THREAD
      t->r=curr;      //RIGHT THREAD
      curr->l=t;      //LEFT LINK OF CURRENT
      curr->lflag=1;
      break;
     }
      curr=curr->l;
    }


     if(t->data > curr->data)
     {
      if(curr->rflag==0)
      {
       t->r=curr->r;   // RIGHT THREAD
       t->l=curr;      //RIGHT THREAD
       curr->r=t;      //LEFT LINK OF CURRENT
       curr->rflag=1;
       break;
      }
       curr=curr->r;
     }
    }
     cout<<"\n More nodes ??(y/n)..";
     cin>>ans;
   }while(ans=='y' || ans=='Y');
}

void btt::btt_pre()
{
      btt_node *t;
      if(root==NULL)
      {
	cout<<"BTT IS EMPTY"<<endl;
	return;
      }
	t=root;

	while(t!=header)
	{
	 cout<<t->data<<endl;
	if(t->lflag==1)
	 t=t->l;    // move to left child
	else
	{
	 while(t->rflag==0)
	{
	 t=t->r;   // move to right thread
	if(t==header)
	 break;
        }
	t=t->r;        // move to right child
        }
        }
}


void btt::btt_post()
{
 btt_node *t;
 int arr[20];
 int i,j=0;
 t=root;
 if(root==NULL)
 {
   cout<<"\n BTT is empty";
   return;
 }
 else
 {
  while(t!=header)
  {
   arr[i]=t->data;
   i++;
   if(t->rflag==1)
   {
    t=t->r;   // move to right child
   }
   else
   {
    while(t->lflag==0)
    {
     t=t->l;  // move to left thread
     if(t==header)
     break;
    }
    if(t==header)
     break;
    t=t->l;   // move to left child
   }
  }
  for(j=i-1;j>=0;j--)
   cout<<arr[j]<<endl;
 }
}


void btt::btt_in()
{
 btt_node *t;
 t=root;
 if(root==NULL)
 {
  cout<<"\n BTT is empty";
  return;
 }

 else
 {
 while(t->lflag==1)  // Leftmost node
 {
  t=t->l;   //Move to left child
 }
 cout<<t->data<<endl;

 while(t!=header)
 {
  if(t->rflag==1)
  {
   t=t->r;   // move to right child
   while(t->lflag==1)  // Leftmost node
   {
     t=t->l;
   }
   cout<<t->data<<endl;
  }
  else
  {1
   while(t->rflag==0)
   {
   t=t->r;  //Move to right thread
   if(t==header)
    break;
   cout<<t->data<<endl;
   }
  }
 }
}
}




int main()
{
 btt obj;
 char ans;
 int ch;
 do
 {
  cout<<" **************************BINARY THREADED TREE*********************"<<endl;
  cout<<"\n 1. CREATE \n 2. PREORDER TRAVERSAL\n 3. POSTORDER TRAVERSAL\n 4. EXIT";
  cout<<"\n ENTER CHOICE :";
  cin>>ch;
  switch(ch)
  {
   case 1:
        obj.create();
        break;
   case 2:
        cout<<"\n PREORDER TRAVERSAL :"<<endl;
        obj.btt_pre();
        break;
   case 3:
        cout<<"\n POSTORDER GRAVERSAL :"<<endl;
        obj.btt_post();
        break;
   case 4:
        return 0;
  }
  cout<<"\n CONTINUE MENU..?(y/n)..";
  cin>>ans;
  }while(ans=='y' || ans=='Y');
 return 0;
}
