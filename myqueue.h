#pragma once


typedef struct qnode qnode;

typedef struct queue queue;

queue * create_queue();
void insert_qnode(queue * q_add,int val);
int remove_qnode(queue * q_add);
void print_queue(queue * q_add);

void queue_init();
int get_q_choice();
void perform_as_q_choice(int choice,queue * q);
