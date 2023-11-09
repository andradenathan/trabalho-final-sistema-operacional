
#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int pid;
    int ppid;
    int status;

} Process;

typedef struct ProcessQueue
{
    Process *process;
    struct ProcessQueue *next;
} ProcessQueue;

typedef struct Queue
{
    ProcessQueue *head;
    ProcessQueue *tail;
    int size;
} Queue;

Queue *create_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = NULL;
    return queue;
}

void enqueue(Queue *queue, Process *process)
{
    ProcessQueue *process_queue = (ProcessQueue *)malloc(sizeof(ProcessQueue));
    process_queue->process = process;
    process_queue->next = NULL;
}

Process *dequeue(Queue *queue)
{
    if (queue->head == NULL)
        return NULL;

    Process *process = queue->head->process;
    queue->head = queue->head->next;
    queue->size--;
    free(queue->head);

    return process;
}

int main()
{
    return 0;
}