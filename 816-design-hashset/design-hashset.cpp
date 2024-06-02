struct Node{
    int val;
    Node *next;
};
typedef struct Node Node;
class MyHashSet {
public:
    Node *head=NULL;
    MyHashSet() {
    }
    
    void add(int key) {
        Node *nn=new Node();
        nn->val=key;
        nn->next=NULL;
        if(head==NULL){
            head=nn;
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=nn;
    }
    
    void remove(int key) {
        if(head==NULL) return;
        while(head!=NULL && head->val==key) head=head->next;
        if(head==NULL) return;
        Node* temp=head;
        while(temp->next!=NULL){
            if(temp->next->val==key) temp->next=temp->next->next;
            else temp=temp->next;
        }
        return;
    }
    
    bool contains(int key) {
        Node* temp1=head;
        if(head==NULL) return false;
        if(head->val==key) return true;
        Node *temp=head;
        while(temp!=NULL){
            if(temp->val==key) return true;
            temp=temp->next;    
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */