#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "stack.h"

//Функции вывода стека
void Print_head();
//
void Print_body_int(void *_element);
//
void Print_foot();
//И даже для символов
void Print_body_char(void *_element);

int main()
{
  stack st;
  int _element_size,i,answer;
  int*  e[5];

  _element_size=sizeof(int);
  printf("Размер элемента: %d байт\n",_element_size);

  if(st=create_stack( _element_size)) {
    printf("Стек создан.\n\n");
  } else {
    printf("Стек не создан.\n\n");
    return 0;
  }

  if(answer == 1) {
    printf("Выводим пустой стек: \n");
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

    printf("Заполняем стек элементами 5,6,777,-59,3. \n");
    for(i=0;i<5;i++) {
      if(push(st,e[i])) {
	      printf("Не удалось добавить элемент %d в стек\n",*e[i]);
      }
    }

    printf("\n\nЗаполненный стек:\n");
    print_stack(st,&Print_head,&Print_body_int,&Print_foot);

    printf("\nУдаляем верхний элемент стека\n");
    pop(st);
    printf("Значение в *buffer : %d\n", *((int*)st->buffer));
    printf("Стек после удаления верхнего элемента:\n");
    print_stack(st,&Print_head,&Print_body_int,&Print_foot);

    printf("Возвращаем удаленный выше элемент\n");
    if(push(st,st->buffer)) {
      printf("Не удалось затолкнуть элемент.\n");
    }
    printf("Получившийся стек:\n");
    print_stack(st,&Print_head,&Print_body_int,&Print_foot);

    printf("Удаляем стек.\n");
    delete_stack(st);


    free(e[0]);
    free(e[1]);
    free(e[2]);
    free(e[3]);
    free(e[4]);
    }

  return 666;
};

//Функции вывода стека
void Print_head()
{
  printf("Stack: \n");
  return;
};
//
void Print_body_int(void *_element)
{
  printf("|%10d|\n",*((int*)_element));
  return;
};
//
void Print_foot()
{
  printf("Конец стека.\n\n");
  return;
};

//И даже для символов
void Print_body_char(void *_element)
{
  printf("|%c|\n",*((char*)_element));
  return;
};
