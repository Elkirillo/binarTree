#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


struct tree
{
	int count;
	tree* left;
	tree* right;	
};


//������� ���������� ���� � ������
tree *addtree(tree *p,int &num,int &coun) 
	{	
		//���� ������� �� �������
		if(p == nullptr) 
		{
			p =new tree[1];
			p->count=num;
			cout << p->count << endl;
			p->left = p->right = nullptr;
			return p;
		} 
  		//���� ������� ������ ������
  		if (p!=nullptr) 
  		{
  			//���� ��� ������ ��������
  			if (coun==0)
  			{
  				
  				p->left = addtree(p->left,num,coun);
  				return p;
			}
			//���� ��� ���� ����� ���������
			else
			{	
				
				p->right = addtree (p->right,num,num);
				return p;
			}
		}	
	}
//������� ������ ��������� � ����������� ������������ ������/����� �������
void foomin1(tree *p,double &c,double &min) 
{    

	//������� ������������� ��� ����� ����� ������
	if (p!=nullptr)
	{
		foomin1(p->left,c,min);
		c+=1;
		if (1/c < min)
			min=1/c;
	}
}
void foomin2(tree *p,double &c,double &min) 
{    

	//������� ������������� ��� ������ ����� ������
	if (p!=nullptr)
	{
		foomin2(p->right,c,min);
		c+=1;
		if (1/c < min)
			min=1/c;
	}
}
void foomin3(tree *p,double &c,double &min) 
{    
	int b=0;
	//������������� ��������� ����� ����� � ��� ������������
	if (p!=nullptr)
	{
		tree *n
		if ((b>0)&&(p->right!=nullptr))
		{

			foomin3(p->right,c,min);
			
		}
		foomin3(p->left,c,min);
		b++;
		c+=1;
		if (1/c < min)
			min=1/c;
	}
}
void foomin4(tree *p,double &c,double &min) 
{    
	int b=0;
	//������������� ��������� ������ ����� � ��� ������������
	if (p!=nullptr)
	{
		if ((b>0)&&(p->left!=nullptr))
			foomin4(p->left,c,min);
		foomin4(p->right,c,min);
		b++;
		c+=1;
		if (1/c < min)
			min=1/c;
	}
}
//������� ������ ��������� � ������������ ������������ ������/����� �������
void foomax(tree *p,double &c,double &max) 
{    
	int b=0;
	//�������������  ������ ����� � ��� ������������
	if (p!=nullptr)
	{
		foomax(p->right,c,max);
		b++;
		c+=1;
		if (b/c > max)
			max=b/c;
	}
}

int main()
{
	int num=0;
	int count=0;
	int value=0;
	tree *root;
	root=nullptr;
	ifstream inp("table.txt");
	char a;
	
	//�������� ����� ������
	root= new tree[1];
	root->count=num;
	root->left = root->right = nullptr;
	cout <<"root " << root->count << endl;
	//���� ���������� ������ ���������
	while (!inp.eof())
	{
		inp.get(a);
		//���� � ������ ������� ���� ����� � ������ ��������
		if (a == '1')
		{
			num+=1;
			root = addtree(root,num,count);
			count+=1;
		}
		//���� �� ��������� � ������ ������� ������
		if (a =='\n')
		{	
			if (count > 0)
			{
				value+=1;
				cout << "root "<<value << endl;
			}
			count =0;
		}
			
	}
	//���� ����������� ��������� ������/����� ��������
	double c=0;
	double min=1;
	foomin1(root,c,min);
	c=0;
	foomin2(root,c,min);
	c=0;
	foomin3(root,c,min);
	c=0;
	foomin4(root,c,min);
	cout << "min of tree = " << min<< endl;
	//���� ������������ ��������� ������/����� ��������
	c=0;
	double max=0;
	foomax (root,c,max);
	cout << "max of tree = " << max<< endl;
return 0;
}
