#include<bits/stdc++.h>
using namespace std;
typedef struct LNode{
	int num;
	struct LNode *next;
}*LinkList,LNode;
int main(){
	void InitList(LinkList list);
	LinkList InsertList(int position,int insert_num,LinkList list);
	LNode* SearchNode(int position,LinkList list);
	bool DropNode(int position,LinkList list);
	bool AlterNode(int position,int alter_num,LinkList list);
	void DeleteList(LinkList list);
	int choice=0,position=0,num=0;
	LinkList list=NULL;
	LNode* listnode;
	InitList(list);
	int q=0;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>choice;
		if(choice==1){
		cin>>position>>num;
		InsertList(position,num,list);
	}else if(choice==2){
		cin>>position;
		listnode=SearchNode(position,list);
		if(listnode->next==NULL){
			cout<<'0';
		}else{
			cout<<listnode->next->num;
		}
	}
	else if(choice==3){
		cin>>position;
		if(DropNode(position,list)){continue;}
	}
	}
	DeleteList(list);
	
	return 0;
}
void InitList(LinkList list){
	list->num=1;
	list->next=NULL;
} 
/*初始化*/

LinkList InsertList(int position,int insert_num,LinkList list){
	LNode* SearchNode(int position,LinkList list);
	LNode *node=(LinkList)malloc(sizeof(LNode));
	node->num=insert_num;
	LNode *listnode=list;
	listnode=SearchNode(position,list);
	node->next=listnode->next;
	listnode->next=node;
	//插入 
	return list;
}
/*后插*/

LNode* SearchNode(int position,LinkList list) {
	/*for(int i=0;i<position;i++){
		listnode=listnode->next;
	}*/
	//这里变成看按位查询 
	LNode* listnode=(LNode*)malloc(sizeof(LNode));
	listnode=list;
	while(listnode!=NULL){
		if(listnode->num!=position){
			listnode=listnode->next;
		}else{
			break;
		}
	}
	//这里是按值查询 
}
//查找
bool DropNode(int position,LinkList list){
	LNode* SearchNode(int position,LinkList list);
	LNode *node=(LNode*)malloc(sizeof(LNode));
	node=SearchNode(position,list); 
	if(node->next!=NULL){
		node->next=node->next->next;
		free(node->next);
		return true;
	}else{return false;}
}
//删除下一节点 

bool AlterNode(int position,int alter_num,LinkList list){
	LNode* SearchNode(int position,LinkList list);
	LNode *node=(LNode*)malloc(sizeof(LNode));
	node=SearchNode(position,list); 
	if(node!=NULL) {
		node->num=alter_num;
		return true;
	}else{return false;}
}
//改值

void DeleteList(LinkList list){
	LNode *node=list;
	while(node!=NULL){
		free(node);
	}
} 
//删表 

//10.10 存在内存泄露 
