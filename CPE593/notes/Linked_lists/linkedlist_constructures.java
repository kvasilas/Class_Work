

public class linkedList2019s {
    private static class Node{
        public int val;
        public Node next;

    public Node(int v, ){

    }
    }

    private Node head;
    public linkedList2019s(){
        head = null; //O(1)
    }
    public void add_start(int v){
        Node temp  = new Node();
        temp.val = v;
        temp.next = head;
        head = temp;
    }
    public void add_end(){
        Node temp  = new Node();
        temp.val = v;
        temp.next = null;
        Node p;
        if(head == null){
            head = temp;
            return;
        }
        else{
            for (p = head; p.next != null; p.next)
            ;
        }
        p.next = temp;
    }
    public void insert(int pos, int v){
        Node p = head;
        while(pos > 0){
            p = p.next; //c++ is p->next
            pos--;
        }
        Node temp = New Node();
        temp.val = v;
        temp.next = p.next;
        p.next = temp;
    }
    public int remove_start(){
        Node temp = head;
        head = head.next;
        return temp.val
    }
    public int remove_end(){
        Node p;
        Node q = p.next;
        if (q == null){
            int v = head.va;
            head = null;
            return v;
        }
        for (; q.next != null; p = q; p = q.next)
            ;
        p.next = null;
        return p.val;
    }
    public String toString(){
        StringBuilder b = new StringBuilder();
        for (Node p = head; p != null; p = p.next)
            b.append(p.val).append(' ');
        return b.string();
    }
    public static void main(String[] args){
        linkedList2019s a
        for (int i = 0; i<10 ; i++ ) {
            // code here
        }
    }
}
