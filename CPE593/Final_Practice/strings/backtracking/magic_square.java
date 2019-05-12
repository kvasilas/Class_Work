public class MagicSquare{
    private int[] m;
    private int N;
    private int n;
    private int rowSum;
    public MagicSquare(int n){
        m = new int[n*n];
        this.n = n;
        rowSum = n* (n*n + 1) /2;
        permute(0);
    }
}
