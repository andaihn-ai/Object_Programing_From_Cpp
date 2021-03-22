#include <iostream>
#include "array.h"

int main(){

    //Array arr1;
    Array arr2(10);

    int nums[] = {1,2,3,4,5};
    Array arr3(nums,5);
    Array arr4(arr3);

    
    if(arr3 == arr4){
        std::cout << "arr3 and arr4 are equal" << std::endl;
    }else{std::cout << "arr3 and arr4 are not equal" << std::endl;}

    for(int i = 0; i< arr3.size(); ++i){
        std::cout<< arr3[i] << std::endl;       //arr3[i]--> arr3.operator[](i)

    }
/*
    // 상수객체인 경우에
    const Array arr5(arr3,5); 
    // const 맴버함수여야 한다.
    int num = arr5[i];
*/

    
    return 0;

}