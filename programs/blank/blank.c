#include "../stdlib/src/shearos.h"


int main(int argc, char** argv)
{
    print("Hello, program active\n");

    while(1){
        if(getkey() != 0)
        {
            print("key press\n");
        }
    }
    return 0;
}