  #include<stdio.h>  
  #define MAXSIZE 5 
   int queue[MAXSIZE];
  int front = 0, rear = -1;  int isempty()
  {
  if(rear == -1)
  return 1;
  else
  return 0;
  }
  int isfull()
  {
  if(rear == MAXSIZE - 1)
  return 1;
  else return 0;
  }
  void enqueue(int data)
  {
  if(isfull())
  printf("Queue is full.\n");
  else
  {
  rear++;
  queue[rear] = data;
  }
  }
  void dequeue()
  {
      int data;
      if(isempty())
              printf("Queue is empty.\n");
      else {
          data  =  queue[front];
          front ++;
          if (front > rear) {
            front  =  0;
            rear  =  -1;
        }
      printf("Dequeued element: %d\n", data);
      }
  } 
  void peek()
  {
      if(isempty()) 
        printf("Queue is empty.\n");
      else
        printf("Element at front:%d\n", queue[front]);
  }

  void display()
  {	
      if(isempty())
        printf("Queue is empty.\n");
      else
      {
        for (int i = front; i <= rear; i++)
          printf("%d\n", queue[i]);
      }
  }
  int main()
  {
  enqueue(3);  enqueue(5);  enqueue(9);  enqueue(1);  enqueue(12);
  peek();
  dequeue();
  dequeue();
  return 0;
  }
