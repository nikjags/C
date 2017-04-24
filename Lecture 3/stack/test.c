#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "stack.h"


void Print_head(){
  printf("Stack: \n");
  return;
};

void Print_body_int(void *_element){
  printf("|%10d|\n",*((int*)_element));
  return;
};

void Print_foot(){
  printf("End of stack.\n\n");
  return;
};


void Print_body_char(void *_element)
{
  printf("|%c|\n",*((char*)_element));
  return;
};




int main(){

  stack st;
  int _element_size,i,answer;
  int*  e[5];
  char* a[5];


  

  printf("int or char (1 or 2): ");
  scanf("%d",&answer);

  if (answer == 1){
    _element_size=sizeof(int);
  }
  else{
    _element_size=sizeof(char);
  }
  printf("\n����� ���������: %d\n",_element_size);
  
  if(st=create_stack( _element_size)){
    printf("���� ������.\n\n");
  }
  else{
    printf("���� �� ������.\n\n");
    return 0;
  }


  if(answer == 1){
    printf("Вывод пустого стека \n");
    print_stack(st,&Print_head,&Print_body_int,&Print_foot);


    e[0]=malloc(sizeof(int));
    *e[0]=5;
    e[1]=malloc(sizeof(int));
    *e[1]=6;
    e[2]=malloc(sizeof(int));
    *e[2]=777;
    e[3]=malloc(sizeof(int));
    *e[3]=-59;
    e[4]=malloc(sizeof(int));
    *e[4]=3;

    printf("Заполнение стека пятью элементами \n");  
    for(i=0;i<5;i++){   
      printf("element[%d]= %d\n",i,*e[i]);
      if(push(st,e[i])){
	printf("�� ������� �������� ����� ������� � ����\n");
      }
    }
    

    printf("\n\nВывод стека с пятью элементами\n");
    print_stack(st,&Print_head,&Print_body_int,&Print_foot);
    
    printf("\nУдаление верхнего элемента стека\n");
    pop(st);
    printf("Значение *buffer : %d\n", *((int*)st->buffer));
    printf("Вывод стека после удаления элемента:\n");
    print_stack(st,&Print_head,&Print_body_int,&Print_foot);
    
    printf("Добавление удалённого элемента обратно в стек\n");
    if(push(st,st->buffer)){
      printf("�� ������� �������� ����� ������� � ����\n");
    }
    else{
      printf("Элемент добавлен\n");
    }
    printf("Вывод стека\n");
    print_stack(st,&Print_head,&Print_body_int,&Print_foot);
    
    printf("Удаление стека.\n");
    delete_stack(st);
    
    
    free(e[0]);
    free(e[1]);
    free(e[2]);
    free(e[3]);
    free(e[4]);
    
  }
  
  if(answer == 2){
    a[0]=malloc(sizeof(char));
    *a[0]='1';
    a[1]=malloc(sizeof(char));
    *a[1]='2';
    a[2]=malloc(sizeof(char));
    *a[2]='3';
    a[3]=malloc(sizeof(char));
    *a[3]='4';
    a[4]=malloc(sizeof(char));
    *a[4]='5'; 


  printf("Заполнение стека пятью элементами \n");  
    for(i=0;i<5;i++){   
      printf("element[%d]= %c\n",i,*a[i]);
      if(push(st,a[i])){
	printf("�� ������� �������� ����� ������� � ����\n");
      }
    }
    

    printf("\n\nВывод стека с пятью элементами\n");
    print_stack(st,&Print_head,&Print_body_char,&Print_foot);
    
    printf("\nУдаление верхнего элемента стека\n");
    pop(st);
    printf("Значение *buffer : %c\n", *(char*)st->buffer);
    printf("Вывод стека после удаления элемента:\n");
    print_stack(st,&Print_head,&Print_body_char,&Print_foot);
    
    printf("Добавление удалённого элемента обратно в стек\n");
    if(push(st,st->buffer)){
      printf("Cannot put new element in stack\n");
    }
    else{
      printf("Элемент добавлен\n");
    }
    printf("Вывод стека\n");
    print_stack(st,&Print_head,&Print_body_char,&Print_foot);
    
    printf("Удаление стека.\n");
    delete_stack(st);

    free(a[0]);
    free(a[1]);
    free(a[2]);
    free(a[3]);
    free(a[4]);
    
}

  return 666;
};


