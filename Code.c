//
// Definition for singly-linked list:
// typedef struct list_##name {
//   type value;
//   struct list_##name *next;
// } list_##name;
//
// list_##name *alloc_list_##name(type v) {
//   list_##name *l = calloc(1, sizeof(list_##name));
//   l->value = v;
//   return l;
// }
//
//


void reverse(list_integer ** l){
    list_integer * next;
    list_integer * prev = NULL;
    list_integer * curr = *l;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    *l = prev;
    
}

void print_linked_list(list_integer * list){
    while(list){
        printf("%d ", list->value);
        list = list->next;
    }
}

list_integer * addTwoHugeNumbers(list_integer * a, list_integer * b) {
    reverse(&a);
    reverse(&b);
    //print_linked_list(a);
    
    
    list_integer * head = NULL;
    int rem = 0;
    
    while(a != NULL || b != NULL){
        int v_a = 0;
        int v_b = 0;
        if(a != NULL)
            v_a = a->value; //printf(" %d h", a->value);}
        if(b != NULL)
            v_b = b->value; //printf(" %d t", b->value);}
        
        int total = v_a + v_b + rem;
        rem = 0;
        
        if(total > 9999){
            total -= 10000;
            rem = 1;
        }
        
        list_integer * res;
        res = alloc_list_integer(total);
        res->next = head;
        head = res;
   
        if(a != NULL) a = a->next;
        if(b != NULL) b = b->next;
    }
    
    if(rem > 0){
        list_integer * res;
        res = alloc_list_integer(1);
        res->next = head;
        head = res;
    }
    
    return head;
}
