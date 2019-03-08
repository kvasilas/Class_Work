class GrowArray {
private:
    int* data;
    uint32_t len;
    uint32_t capacity;
    void grow() { /*if length > capacity -> grow*/
        //double each time its called
    }
public:
    GrowArray() : data(nullptr), len(0){ }
    void addEnd(){ /*c++ O(1), Java O(n)*/
        int* old = data;
        data = new int[len+1];
        for (int i = 0; i < len; i++)
            data[i] = old[i];
        delete [] old;
    }
    void addStart(int v){
        int* old = data;
        data = new int[len+1];
        data[0]=v;
        for (int i = 0; i <= len; i++)
            data[i] = old[i-1];
        len++;
        delete [] old;
    }

    void removeEnd(){
        len--;
        /*
        int* old = data;
        data = new int[--len];
        for (int i = 0; i < n; i++) {
            data[i] = old[i]
        }
        delete [] old;
        */
    }

    void removeStart(){
        int* old = data;
        data = new int[--len];
        for (int i = 0; i < n; i++)
                data[i] = old[i+1]
        delete [] old;
    }

    uint32_t size() {
        return len;
    }
};

int main(){
    GrowArray a;
    const int n = 1000000;
    for (int i = 0; i < n; i++) {
        a.addEnd(i);
    }
}
