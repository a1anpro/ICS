/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q == NULL){
      return NULL;
    }
    q->tail = q->head = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements? */
    /* Free queue structure */
    if (q == NULL)return ;
    list_ele_t *p = NULL;
    while (q->head != NULL){
      p = q->head;
      q->head = p->next;
      free(p);
    }
    q->size = 0;
    free(q);
    q = NULL;
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    /* What should you do if the q is NULL? */
    if (q == NULL) {
      return false;
    }
    list_ele_t *newh;
    /* What if malloc returned NULL? */
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL){
      return false;
    }
    newh->value = v;
    newh->next = NULL;//set the next element is NULL
    newh->next = q->head;
    q->head = newh;
    if (q->size == 0){
      //if its the first element to insert.set tail;
      q->tail = newh;
    }
    ++q->size; //increment size
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL){
      return false;
    }
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (newh != NULL){
      newh->value = v;
      newh->next = NULL;
      q->tail->next = newh;
      q->tail = newh;
      ++q->size;
      return true;
    }
    return false;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* You need to fix up this code. */
    if (!vp || q == NULL || q->size == 0){
      return false;
    }
    list_ele_t *p = q->head;
    q->head = q->head->next;
    *vp = p->value;
    free(p);
    p = NULL;
    --q->size;
    return true;
}

int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL) return 0;
    return q->size;
}

/*
  Reverse elements in queue
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (q == NULL || q->size == 0){
      return ;
    }
    
    list_ele_t *end = q->tail;//tail not change;
    list_ele_t *p = q->head;
    bool tag = false;
    while (q->head != end){
      //always put head to end-next
      q->head = q->head->next;
      p->next = end->next;
      end->next = p;
      if (!tag){
        q->tail = p;
        tag = true;
      }
      p = q->head;
    }
}

