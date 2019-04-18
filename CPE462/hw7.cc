new_T = 200.0
delta_T = 100.0

while(delta_T > 5.0 || delta_T < -5.0){
    countA = 0;
    countB = 0;
    sumA = 0.0;
    sumB = 0.0;

    for (int i = 0; i < height; i++) {
        for (int k = 0; k < width; k++) {
            if (image_in[i][k] >= new_T) {
                sumA += image_in[i][k];
                countA++;
            }
            else{
                sumB += image_in[i][k];
                countB++;
            }
        }
    old_T = new_T;
    new_T = ((sumA/countA) + (sumB/countB)) / 2;
    delta_T = new_T - old_T;
    }
}

for(int j=0; j<height; j++){
    for (int i = 0; i < width; i++) {
        image_out[j][i] = (image_in[j][i] >= new_T ? 255 : 0)
    }
}
