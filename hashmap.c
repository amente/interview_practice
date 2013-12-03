#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define HM_LOAD_FACTOR  0.75  //TODO: Rehash based on load factor
#define HM_INIT_CAPACITY  100

//Reprensents a single Node in the HashMap with key and data
typedef struct _HMNode{	
	char *key;
	int len;
	int data;
	struct _HMNode *next; // Linked list collision resolution, 
}HMNode;

typedef struct _HM{
	int size;	
	HMNode **members;
	int capacity;
	void (*put)(struct _HM *h,char *key,int len,int data);
	int  (*get)(struct _HM *h,char *key,int len);
	int (*exists)(struct _HM *h, char *key, int len);
}HM;

void HM_put(HM *t,char *key,int len,int data); 
int HM_get(HM *t,char *key,int len);
int HM_exists(HM *t,char *key,int len);
HMNode **HM_allocate(int capacity);

HM *HM_HM_new(int capacity){
	HM * h = malloc(sizeof(HM));
	assert(h!=NULL);
	h->size = 0;	
	h->capacity =capacity;
	h->members = HM_allocate(h->capacity);	
	h->put = HM_put;
	h->get = HM_get;
	h->exists = HM_exists;
}

HM *HM_HM(){
	return HM_HM_new(HM_INIT_CAPACITY);
}

void HM_destroy(HM *h){
	if(h){	
		while(h->size>0){
			if(h->members[h->size-1]){
				//TODO: free key copies
				free(h->members[h->size-1]);
			}
			h->size--;
		}
		free(h);
	}	
}

HMNode **HM_allocate(int capacity){
	HMNode **members = malloc(capacity*sizeof(HMNode *));	
	assert(members!=NULL);
	int i;
	//Initialize all new allocated pointers to null
	for(i = 0; i < capacity; i++){
		members[i]=NULL;
	} 
	return members;	
}

int HM_hash(char *key , int len,int capacity){
	// Simple hash function, adds the ascii values and returns modulo capacity;
	int i;
	int sum=0;
	for(i=0;i<len;i++){
		sum+=key[i];
	}
	return sum%capacity;	
}
void HM_put(HM *t, char *key, int len,int data){		
	//Hash the data	
	int index = HM_hash(key,len,t->capacity);
	
	printf("Index: %d\n",index);
	//Copy the Key;
	char *copy = malloc(len*sizeof(char));
	assert(copy!=NULL);
	int i;
	for(i=0;i<len;i++){
		copy[i] = key[i];
	}		
		
	//Check if there is a collision
	if(t->members[index]){
		//Collision
		//Find if the key exists in the chain
		HMNode **cur = &(t->members[index]);
		while(*cur){
			if((*cur)->len == len){
				int i,j=0;
				for (i=0;i<len;i++){
					if((*cur)->key[i]==key[i]){
						j++;
					}
				}
				if(j==len){
					//If there is a similar key just update the data
					(*cur)->data = data;
					return;
				}
			}
			cur = &((*cur)->next);
		}
		
		*cur = malloc(sizeof(HMNode));		
		(*cur)->key = copy;
		(*cur)->len  = len;
		(*cur)->data = data;		
		
	}else{		
		t->members[index] = malloc(sizeof(HMNode));
		t->members[index]->key = copy;
		t->members[index]->len  = len;
		t->members[index]->data = data;				
	}
	t->size++;
	
}

int HM_get(HM *t,char *key,int len){
	// Hash the key
	int index = HM_hash(key,len,t->capacity);
	
	// Get the would be location for the data
	HMNode *cur = t->members[index];
	if(!cur){
		goto keyError;
	};
		
	//We have some data at that index
	//Now traverse the LL and check the chain 	
	while(cur){
		if(cur->len == len){
			int i,j=0;
			for (i=0;i<len;i++){
				if(cur->key[i]==key[i]){
					j++;
				}
			}
			if(j==len){
				return cur->data;					
			}
		}
		cur = cur->next;
	}
	
	//If we reach here it is an error
	keyError:
		//key doesn't exist
		return 0;
}


int HM_exists(HM *t,char *key,int len){
	
	// Hash the key
	int index = HM_hash(key,len,t->capacity);
	
	// Get the would be location for the data
	HMNode *cur = t->members[index];
	if(!cur){
		return 0;
	};
		
	//We have some data at that index
	//Now traverse the LL and check the chain 	
	while(cur){
		if(cur->len == len){
			int i,j=0;
			for (i=0;i<len;i++){
				if(cur->key[i]==key[i]){
					j++;
				}
			}
			if(j==len){
				return 1;					
			}
		}
		cur = cur->next;
	}
	
	return 0;
}













