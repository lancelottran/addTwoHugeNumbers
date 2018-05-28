// Definition for singly-linked list:
// class ListNode<T> {
//   ListNode(T x) {
//     value = x;
//   }
//   T value;
//   ListNode<T> next;
// }
//
ListNode<Integer> addTwoHugeNumbers(ListNode<Integer> a, ListNode<Integer> b) {
    int remainder = 0, sum = 0;
    ListNode<Integer> node = null;
    ListNode<Integer> temp = null;
    ListNode<Integer> head = null;


    a = reverse(a);
    b = reverse(b);
    
    while(a != null || b != null)
    {       
        sum = (a == null ? 0 : a.value) + (b == null ? 0 : b.value);
        
        if(remainder > 0)
        {
            sum += remainder;
            remainder = 0;   
        }
        
        if(sum > 9999)
        {
            remainder = 1;
            sum -= 10000;
        }
        
        temp = new ListNode<Integer>(sum);
        
        if(node == null)
        {    
            node = temp;
        }
        else{
            head.next = temp;
        }
        
        head = temp;
        if(a != null)
            a = a.next;
        if(b != null)
            b = b.next;
    }
    
    if(remainder == 1)
    {
        head.next = new ListNode<Integer>(1);
    }
    
    node = reverse(node);

    
    return node;
}

ListNode reverse(ListNode<Integer> a)
{
    ListNode<Integer> curr = a;
    ListNode<Integer> next = null;
    ListNode<Integer> prev = null;
    
    while(curr != null)
    {
        next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    
    a = prev;
    return a;
}
