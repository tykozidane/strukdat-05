/*
Nama	: tyko zidane badhawi
NPM		: 140810180031
Program	: exercise-05
*/
#include<iostream>
using namespace std;

struct Pembalap{
	int nomor;
	char nama[40];
	int waktu;
	Pembalap* next;
	Pembalap* prev;
};
void createNode(Pembalap* &p){
	p=new Pembalap;
	cout << ">>> Insert List\n";
	cout << "Nomor	: "; cin >> p->nomor;
	cout << "Nama	: "; cin >> p->nama;
	cout << "waktu	: "; cin >> p->waktu;
	p->next=NULL;
	p->prev=NULL;
}
void insertFirst(Pembalap* &head, Pembalap* node){
	if (head==NULL){
		head=node;
	}
	else{
		node->next=head;
		head->prev=node;
		head=node;
	}
}
void insertBefore(Pembalap* &head, int nomorkey, Pembalap* node){
	Pembalap* pBantu;
	pBantu=head;
	while(pBantu!=NULL){
		if (pBantu->nomor==nomorkey){
			if(pBantu->prev==NULL){
				insertFirst(head, node);
			}
			else{
				node->next=pBantu;
				node->prev=pBantu->prev;
				pBantu->prev->next=node;
				pBantu->prev=node;
			}
		}
		pBantu=pBantu->next;
	}
}
void deleteByKey(Pembalap* &head, int nomorkey, Pembalap* &deletedNode){
	Pembalap* pBantu;
	pBantu=head;
	while(pBantu!=NULL){
		if (pBantu->prev==NULL){
			deletedNode=pBantu;
 		pBantu=pBantu->next;
 		pBantu->prev=NULL;
 		deletedNode->next=NULL;
		}
		
		else if (pBantu->nomor==nomorkey){
			if(pBantu->next==NULL){
				Pembalap* last;
				last=head;
			while(last->next!=NULL){
				last=last->next;
				}
				deletedNode=last;
				last->prev->next=NULL;
				deletedNode->prev=NULL;
			}
			else{
				deletedNode=pBantu;
				pBantu->prev->next=pBantu->next;
				pBantu->next->prev=pBantu->prev;
				pBantu->next=NULL;
				pBantu->prev=NULL;
			}
		}
		pBantu=pBantu->next;
	}
}
void sortingByNomor(Pembalap* &head){
	Pembalap* pBantu;
	Pembalap* tuker;
	pBantu=head;
	while(pBantu!=NULL){
		if (pBantu->nomor > pBantu->next->nomor){
			if (pBantu->prev==NULL){
			tuker=pBantu->next;
			pBantu->next=pBantu->next->next;
			tuker->next=pBantu;
			}
			else if (pBantu->next->next==NULL){
			tuker=pBantu->next;
			pBantu->prev->next=tuker;
			pBantu->next=NULL;
			tuker->next=pBantu;
			}
			else {
				tuker=pBantu->next;
				pBantu->next=pBantu->next->next;
				pBantu->prev->next=tuker;
				tuker->next=pBantu;
				
			}
			
		}
	}
}
void traversal(Pembalap* head){
	Pembalap* pBantu;
	while(pBantu!=NULL){
		cout << "Nomor	: " << pBantu->nomor << endl;
		cout << "Nama	: " << pBantu->nama << endl;
		cout << "Waktu	: " << pBantu->waktu << endl;
		pBantu=pBantu->next;
	}
	
}
void update (Pembalap* &head, int nomorkey){
	Pembalap* pBantu;
	pBantu=head;
	while(pBantu!=NULL){
		if (pBantu->nomor==nomorkey){
		cout << ">>> Insert List\n";
	cout << "Nomor	: "; cin >> pBantu->nomor;
	cout << "Nama	: "; cin >> pBantu->nama;
	cout << "waktu	: "; cin >> pBantu->waktu;
		}
		pBantu=pBantu->next;
	}
}
int main (){
	Pembalap* head = NULL;
 Pembalap* pBaru = NULL;
 Pembalap* pToUpdate = NULL;
 for (int i=0; i<4; i++){
 	createNode(pBaru);
 	insertFirst(head, pBaru);
 }
 cout << ">>>List\n";
 traversal(head);
}
