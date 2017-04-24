#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

  struct stack_element{
    void *element;
    struct stack_element *prev;
  };
  struct _stack{
    int element_size;
    struct stack_element *top;
    void *buffer;
  };
  typedef struct _stack *stack;




//Создание стека
stack create_stack(int _element_size){

  stack st;

  st = malloc(sizeof(struct _stack));
  if (!st)
    {
      return NULL;
    }
  st->element_size = _element_size;
  st->top = NULL;
  st->buffer = NULL;
  
  return st;
}    


//Вталкивание элемента в стек
int push(stack _stack, void *_element){
  struct stack_element* buf;

  if(!_stack){
    return -1;
  }
  
  buf=malloc(sizeof(struct stack_element));
  if(!buf){
    return -1;
  }
  buf->element=malloc(_stack->element_size);
  if(!buf->element){
    return -1;
  }
  
  buf->prev = _stack->top;
  memcpy(buf->element, _element, _stack->element_size);
  _stack->top = buf;
  return 0;
  }

//Выталкивание элемента из стека
void * pop(stack _stack){
  struct stack_element* buf;

  if ((!_stack) || (!_stack->top)){
    return NULL;
  }
  
  buf= _stack->top;
  _stack->buffer = buf->element;
  _stack->top = buf->prev;
  free(buf);
  return _stack->buffer;
} 

//Удаление стека
void delete_stack(stack _stack){
  
  struct stack_element* buf;

  if(!_stack){
    return;
  }
  buf = _stack->top;
  while (buf)
    {
      _stack->top=_stack->top->prev;
      free(buf->element);
      free(buf);
      buf=_stack->top;
    }
  free(_stack);
  return;
};

//Вывод стека
void print_stack(stack _stack, void (*print_head)(), void (*print_body)(void *_element), void (*print_foot)())
{
  struct stack_element *buf;

  if (!_stack || !_stack->top)
    {
      print_head();
      print_foot();
      return;
    }

  print_head();

  buf = _stack->top;
  while (buf)
    {
      print_body(buf->element);
      buf = buf->prev;
    }

  print_foot();
  return;
}
