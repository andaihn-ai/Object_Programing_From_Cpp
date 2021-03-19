#include <iostream>
#include "safeArray.h" 


int main(){

    SafeArray arr1;
    SafeArray arr2(10);
    int nums[] = {1,2,3,4,5};
    SafeArray arr3(nums,5);
    SafeArray arr4(arr3);

    arr1 = arr3;

    if(arr1 == arr3){
        std::cout << "arr1 and arr3 are equal" << std::endl;

    }else{
        std::cout << "arr1 and arr3 are not equal" << std::endl;
    }
    
    // 예외가 발생할 가능성이 있는 블록을 묶어준다 
    try         
    {
        Array arr5(nums,5);
        for (int i = 0; i < arr5.size(); ++i)
            std::cout << arr5[i] << std::endl;
        
        Array *pArr = new SafeArray(nums,5);
        (*pArr)[5] = 5;

        delete pArr;
        
    } catch(int e) {
        std::cerr << "we receive exception code : " << e << std::endl;

        return e;
    } catch(double e) {
        //
    } catch(...) {          
        // 위에서 처리하고 남은 나머지들
    }


    
    return 0 ;
}