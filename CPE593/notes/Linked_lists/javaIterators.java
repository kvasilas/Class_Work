public class javaIterators{
    public static void main(string[] args){
        ArrayList<Interger> a = new ArrayList<>();
        final int n = 10;
        for (int i = 0; i < n; i++)
            a.add(i);
        for (ListIterator<Interger> i =a.ListIterator(); i.hasNext(); ) {
            Interger v = i.next();
            System.out.println(v);
        }
        //dovs suggestion for an insertAtPosition
        /*
        for (ListIterator i = a.start(); i.hasNext(); i.next()) {
            Interger v = i.get();
        }
        */
    }
}
