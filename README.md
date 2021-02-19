# Object_Programing_From_Cpp
## Queue from C to Cpp
### queue.h / queue.c /  main.c 를 cpp로 변경합니다.
  1. 확장자를 .c에서 .cpp로 바꿉니다.
  2. push(&s1, 100); ---> s1.push(100)
  3. queue와 관련된 전역함수 --> 멤버함수
      - void push(Queue *ps, int data) {...} ---> void Queue::push(int data) {...}
   2) ps->   -->  this->

  > 멤버함수는 반드시 객체를 통해서 호출해야 한다.
     ex) s1.push(100)    s2.push(800)
  > 멤버함수는 자신을 호출한 객체를가리키는 this 라는 포인터를 가진다.

3. typedef struct {...} Stack; ---> struct Stack {...};
4. int main(void) {...} ---> int main() {...}
5. namespace 가 적용된 header file사용. <stdio.h> --> <cstdio>
6. malloc() / free()  ---> new / delete 연산자
7. 접근지정자 private / public
  > 내부 구현(implemetation)은 숨기고 인터페이스(interface)는 보인다
  > 허용된 연산을 통해서 내부 구현에 접근한다.
  ; 정보 은닉(information hiding) 
8. 생성자(constructor) / 소멸자(destructor)
  > 생성자 : 객체가 생성될때 자동적으로 호출되는 멤버함수
                 객체 초기화.
  > 소멸자 : 객체가 소멸될때 자동적으로 호출되는 멤버함수
                 객체 cleanup.
  > void Stack::initStack(int size) {...} --> Stack::Stack(int size) {...}
  > void Stack::cleanupStack() {...} --> Stack::~Stack() {...}
9. struct ---> class
  > class (in C++) = struct (in C) + 멤버함수 + 접근지정자
10. stream input / output
