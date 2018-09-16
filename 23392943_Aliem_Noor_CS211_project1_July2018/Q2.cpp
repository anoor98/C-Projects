//Q2
#include <iostream>
using namespace std;

int bounding_rect(int n, int x[], int y[], int u[], int v[]){
    int largest_x = x[0];
    int smallest_x = x[0];
    int largest_y = y[0];
    int smallest_y = y[0];

    for (int i=0; i < n; i++) {
        if (x[i] > largest_x)
          largest_x = x[i];
    }

    for (int j = 0; j < n; j++) {
        if (x[j] < smallest_x)
          smallest_x = x[j];
    }

    for (int k = 0; k < n; k++) {
        if (y[k] > largest_y)
          largest_y = y[k];
    }

    for (int l = 0; l < n; l++) {
        if (y[l] < smallest_y)
          smallest_y = y[l];
    }

    int i[] = {smallest_x ,largest_x, largest_x, smallest_x};
    int j[] = {smallest_y, smallest_y, largest_y, largest_y};
    
    int Area = (i[2]-i[0]) * (j[2]-j[0]);

    return Area;
}