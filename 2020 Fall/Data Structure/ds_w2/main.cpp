//
//  main.cpp
//  ds_w2_time
//
//  Created by RUAN on 2020/09/19.
//  Copyright © 2020 RUAN. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    clock_t start, stop;
    double duration;
    start=clock();
    for(int i=1; i<1000000; i++);
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("time: %f sec\n",duration);
    return 0;
}
