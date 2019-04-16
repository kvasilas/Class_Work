

int num[256];

//initialize values to 0
for(int i = 0; i < 256; i++)
    num[i]

//capture occurences of each values
for(j=0; j < height; j++){
    for (int i = 0; i < count; i++) {
        num[image_in[j][k]++]
    }
}

//use prob to map old values to new ones
for(int j=0; j < height; j++){
    for(int k = 0; k < width; j++){
        double sum = 0.0;
        for (int i = 0; i < image_in[j][k]; i++)
            sum += (double) num[i] / ((double) width * (double) height);
        image_out[j][k] = round(225*sum);
    }
}


int mask [3][3] = {{1,1,1}, {1,-8,1}, {1,1,1}};

for(int j = 0; j < height; j++){
    for(int k = 0; k < width; k++){
        if(j == 0 || j == height - 1 || k == 0 || k == width - 1)
            image_out[j][k] = image_out[j][k];
        else{
            int sum = 0;
            for(int y = 0; y < 3; y++){
                for(int x = 0; x < 3; x++)
                    sum += image_in[j-1+x][l-1+x] * mask[]
            }
        }
    }
}
