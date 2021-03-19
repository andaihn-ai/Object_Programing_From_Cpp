# Object_Programing_From_Cpp
## type casting
  - static_cast <type> (expression);
  - reinterpret_cast<type> (expression);
  - const_cast<type> (expression);
  - dynamic_cast<type> (expression);

## static_cast
  - 가장많이 사용됩니다.
  - 컴파일 시간에 타입이 호환이 되는지 체크 합니다.

## reinterpret_cast
  - 컴파일때 에러가 나면 강제형변환을 할 때 사용합니다.

## const_cast
  - 상수객체의 const 속성을 없앨때 사용합니다.

## dynamic_cast
  - RTTI 에서사용합니다.
  - 원래의 파생(자식) 클래스 타입으로 바꿀때 사용합니다.

## static_cast 예제 
  - safeArray_execption 에서 사용한 safeArray.cpp 파일을 사용합니다.

### safeArray.cpp
  - 강제 형변환 했던 부분들을 static_cast로 변경합니다.
```c
SafeArray::SafeArray(const SafeArray& rhs)
: Array( static_cast<Array>(rhs))               //slicing                  
{
    
}
```
```c
SafeArray& SafeArray::operator=(const SafeArray& rhs)      
{
    return static_cast<SafeArray&>( this->Array::operator=(static_cast<Array>(rhs)) );     
}
```
```c
bool SafeArray::operator==(const SafeArray& rhs) const
{
    return this->Array::operator==( static_cast<Array>(rhs) );               
}

```
