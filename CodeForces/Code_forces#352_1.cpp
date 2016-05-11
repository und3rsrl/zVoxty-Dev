#include <iostream>

int main()
{
    int a[1000];
    int b[4000];
    int j = 1;
    int l = 10;
    int k = 11;
    int z = 192;
    int nr;


    for(int i = 1; i <= 1000; i++){
        a[i] = i;
    }
    
    while(j <= 1000){
        if(j < 10){
            b[j] = a[j];
            j++;
        }

        if(j >= 10 && j < 100){

                b[l] = a[j]/10;
                b[k] = a[j]%10;
                j++;
                l += 2;
                k += 2;
        }

        if(j >=100 && j <= 1000){

            b[l] = a[j]/100;
            b[k] = a[j]/10%10;
            b[z] = a[j]%100%10;
            j++;
            l += 3;
            k += 3;
            z += 3;

        }
    }

    std::cin >> nr;
    std::cout << b[nr];

    return 0;
}
