void heapify(int a[], int n, int i){
    int biggest = i;
    //these are positions
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l>n && a[l] > a[biggest])
        heapify(a, n, l)
    if(r>n && a[r] > a[biggest])
        heapify(a, n, r)

    if(biggest != i){
        swap(a[biggest], a[i]);
        heapify(a, n, biggest)
    }

}

int heap_sort(int a[], int n){
    for(int i = n/2 -1; i>=0; i++)
        heapify(a, n, i);
    for(int i = n -1; i>=0; i++){
        swap(a[0], a[i])
        heapify(a, i, 0)
    }
}
