/*
Kirk Vasilas
CPE 555A
Homework 3 - Due 9/27/18
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int latD, latM, lonD, lonM; //time usints for output
    float lon, lat, temp, latS, lonS; // input lat and Longitude
    char ns, we;

    // Cardinal Directions
    //Inputs
    printf("Enter Latitude : ");
    scanf("%f", &lat);
    printf("Enter Longitude : ");
    scanf("%f", &lon);
    // Cardinal Directions
    if(lat < 0){
        ns = 'S';
        lat*=-1;
    }
    else if(lat > 0){ns = 'N';}
    else{ns = ' ';}

    if(lon < 0){
        we = 'W';
        lon*=-1;
    }
    else if(lon > 0){we = 'E';}
    else{we = ' ';}

    //Conversions
    latD = (int) lat;
    //printf("lat %f\n",lat ); //all comments here for debugging
    //printf("latD %d\n",latD );
    lat = lat - latD;
    //printf("lat %f\n", lat);
    temp = lat*60;
    latM = (int) temp;
    //printf("temp %f\n", temp);
    //printf("latm %d\n", latM);
    lat = temp - latM;
    //printf("lat %f\n", lat);
    temp = lat*60;
    latS = temp;

    lonD = (int) lon;
    lon = lon - lonD;
    temp = lon*60;
    lonM = (int) temp;
    lon = temp - lonM;
    temp = lon*60;
    lonS = temp;
    //Output
    printf("Latitude : %d degrees, %d minutes, %f seconds %c\n", latD, latM, latS, ns);
    printf("Longitude: %d degrees, %d minutes, %f seconds %c\n", lonD, lonM, lonS, we);

    return 0;
}
