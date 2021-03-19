#include <iostream>
#include "safeArray.h"


int main()
{
    // 내부적으로 int 형을 저장하는 array 
    // <> 안의 타입을 받아 타입에 타겟팅되는 소스코드 생성

    int nums[]={1, 2, 3, 4, 5 };                    // int형 nums 배열 생성
    SafeArray<int> arr1(nums, 5);                       // int 형 array코드

    for(int i = 0; i < arr1.size(); ++i)
    {
        std::cout << arr1[i] << std::endl;
    }

    double nums2[]={1.1, 2.2, 3.3, 4.4, 5.5 };
    SafeArray<double> arr2(nums2, 5);                   // double 형 array코드

    for(int i = 0; i < arr2.size(); ++i)
    {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}