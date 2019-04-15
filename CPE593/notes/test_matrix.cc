class matrix{
private:
    int rows, cols;
    double* m;
public:
    matrix(int rows, int cols, double val): rows(rows), cols(cols){
    for(int i = 0, i< rows*cols, i++)
        m[i]= val;
    }
    ~matrix(){
`       delete;`
    }
    matrix(const matrix& orig) = delete;
    //matrix operator = (const matrix& orig) = delete;

};

class TriDiagonalMatrix{
public:  
};


int main(){
    matrix m1(n, n, 0.0)
}
