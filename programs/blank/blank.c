#include "../stdlib/src/shearos.h"
#include "../stdlib/src/stdlib.h"

int main(int argc, char** argv)
{
    print("Hello, program active\n");

    print(itoa(928));
    void* ptr = malloc(512);
    free(ptr);
    while(1){
        if(getkey() != 0)
        {
            print("key press\n");
        }
    }
    return 0;
}