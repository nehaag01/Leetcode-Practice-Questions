#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int val){
			data = val;
			next = NULL;
		} 
};
node* reverse(node* head){
	node* prevptr = NULL ;
	node* currptr = head ;
	node* nextptr ;
	while(currptr!=NULL){
		nextptr = currptr->next ;
		currptr->next = prevptr ;
		prevptr = currptr;
		currptr = nextptr ;
	}
	return prevptr ;
}
node* addoneutil(node* head){
	node* res = head;
	node* temp,prev=NULL;
	int carry=1,sum;
	while(head!=NULL){
	sum = carry + head->data;
	carry = (sum>=10)?1:0	;
	sum = sum % 10 ;
	head->data = sum;
	 temp = head;
	head = head->next ;
	}
	if(carry>0)
	temp->next = new node(carry);
	return res;
}
node* addone(node* head){
	head = reverse(head);
	head = addoneutil(head);
	return reverse(head);
}
void print(node* head){
	node* temp = head ;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next ;
	}
	cout<<"NULL"<<endl ;
}
int main(){
	node* head = new node(4) ;
	head->next = new node(9);
	head->next->next = new node(9);
	print(head);
	head = addone(head);
	print(head);
}
