#include "capture_tb.h"

void capture_tb(void){
    while(1){
        printf("Frequency: %u \n", get_frequency());
    }
}
