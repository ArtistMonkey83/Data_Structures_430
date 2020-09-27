FindMax(inputArray) {
   max = inputArray[0]
   for (i = 1; i < inputArray.size; ++i) {
      if (inputArray[i] > max) {
         max = inputArray[i]
      }
   }
   return max
}
FOR BIG O
If f(N) is a sum of several terms, the highest order term
is kept and others are discarded.
= O(
2
7·N
Rule 1:
)
Rule 2:
If f(N) has a term that is a product of several factors,
all constants are omitted.


  _____ _             _                  _      _       _            _   _      _     _
 / ____(_)           | |                | |    (_)     | |          | | | |    (_)   | |
| (___  _ _ __   __ _| |_   _   ______  | |     _ _ __ | | _____  __| | | |     _ ___| |_ ___
 \___ \| | '_ \ / _` | | | | | |______| | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __/ __|
 ____) | | | | | (_| | | |_| |          | |____| | | | |   <  __/ (_| | | |____| \__ \ |_\__ \
|_____/|_|_| |_|\__, |_|\__, |          |______|_|_| |_|_|\_\___|\__,_| |______|_|___/\__|___/
                 __/ |   __/ |
                |___/   |___/

ListAppend(list, newNode) {
  if (list⇢head == null) { // List empty
    list⇢head = newNode
    list⇢tail = newNode
  }
  else{
    list⇢tail⇢next = newNode
    list⇢tail = newNode
  }
  list⇢length++
}

ListInsertAfter(list, curNode, newNode) {
  if (list⇢head == null) { // List empty
    list⇢head = newNode
    list⇢tail = newNode
  }
  else if (curNode == list⇢tail) { // Insert after tail
    list⇢tail⇢next = newNode
    list⇢tail = newNode
  }
  else {
    newNode⇢next = curNode⇢next
    curNode⇢next = newNode
  }
}

ListRemoveAfter(list,curNode){
 //Special case, remove head node
 if(curNode == null && list->head != null){
   successorNode = list->head->next;
   list->head = successorNode;

   if(successorNode == null){list->tail = null;} //Removed last item
 }
 else if(curNode->next != null){
   successorNode = curNode->next->next;
   curNode->next = successorNode;

   if (successorNode == null){ //Removed tail
     list->tail = curNode;
   }
 }
}

listSearch(list, key){
 curNode = list -> head;
 while (curNode != null){
   if(curNode->data == key){ return curNode;}
   return null;
 }
}

 _____              _     _                  _      _       _            _   _      _     _
|  __ \            | |   | |                | |    (_)     | |          | | | |    (_)   | |
| |  | | ___  _   _| |__ | |_   _   ______  | |     _ _ __ | | _____  __| | | |     _ ___| |_ ___
| |  | |/ _ \| | | | '_ \| | | | | |______| | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __/ __|
| |__| | (_) | |_| | |_) | | |_| |          | |____| | | | |   <  __/ (_| | | |____| \__ \ |_\__ \
|_____/ \___/ \__,_|_.__/|_|\__, |          |______|_|_| |_|_|\_\___|\__,_| |______|_|___/\__|___/
                             __/ |
                            |___/


append to empty list: if the list's head pointer is null(empty), the algorithm points the list's head and tail pointers to the new node

append to non empty list: if the list's head pointer is not null(not empty), the algorithm points the tail node's next pointer to the new node, points the new node's previous pointer to the lists's tail node and points the lits's tail pointer to the new node
listAppend(list, newNode) {
 if(list->head == null){
   list->head = newNode;
   list->tail = newNode;
 }
 else {
   list->tail->next = newNode;
   newNode-> prev = list->tail;
   list->tail = newNode;
 }
}
prepend to emptly list: if the list's head pointer is null(empty), the algorithm poitns the list's head and tail to newNode

prepend to non-empty list: if the list's head pointer is not null(not empty), the algorithm points the newNode's next pointer to the list's head node, points the list head node's previous pointer to the new node and then points the list's head pointer to the new node.

listPrepend(list, neNode){
 if(list->head == null){
   list->head = newNode;
   list->tail = newNode;
 }
 else{
   newNode->next = list ->head;
   list->head->prev = newNode;
   list ->head = newNode;
 }
}

insert as first node: if the list's head pointer is null(list is empty), the algorithm points the list's head and tail to new NODE

insert arter list's tail node: if the list's head pointer is not null(not empty) and currentNode points to the list'staild node the new node is inserted after the tail node. the algorithm points teh tali node's next pointer to the new node, points the new node's prevous pointer to the list's tail node, and then points the list's tail pointer to the new NODE

insert in the middle of the list:if the list's head pointer is not null(not empty) and currentNode does not point to the list's tail node, the algorithm updates the current, new and successor nodes' next and previous pointers to ahieve the order {currentNode newNode successorNode}, which requires four pointer updates:

     point the new node's next pointer to successorNode
     point the new node's previous pointer to currentNode
     point currentNode's next pointer to the new node
     point successorNode previous pointer to the new node

listInsertAfter(list, curNode, newNode){
 if(list->head ==n null){
   list->head = newNode;
   list->tail = newNode;
 }
 else if ( curNode == list->tail){
   list->tail->next = newNode;
   newNode->prev = list->tail;
   list->tail = newNode;
 }
 else{
   sucNode = curNode->next;
   newNode->next = sucNode;
   newNode->prev = curNode;
   curNode->next = newNode;
   sucNode->prev = newNode;
 }
}

Remove operation removes a provided existing list node. curNode is a pointer to an existing list node. The algorithm first determines the node's successor(the next node) and predecessor(the previous node). The variable sucNode pointes to the node's successor and the variable predNode points to the node's predescessor. the algorithm uses four separate check to update each pointer.

Successor exists: if the successor node pointer is not null(successor exists), point the sucNode previous pointer to the predNode.

predNode exists: if the predNode pointer is not null(predNode exists), point the predNode next pointer to sucNode

removing lists's head: if curNode points to the head node, then point the head pointer to the successor node.

removing lists tail: if curNode points to the list's tail, then point the list's tail to the predNode.

listRemove(list, curNode){
 sucNode = curNode->next;
 predNode = curNode->prev;

 if (sucNode != null){
   sucNode->prev = predNode;
 }
 if (predNode!=null){
   predNode->next = sucNode;
 }
 if (curNode == list->head){
   list->head = sucNode;
 }
 if (curNode == list->tail){
   list->tail = predNode;
 }
}



 _ ____ _                _              _      _     _
/  ____(_)              | |            | |    (_)   | |
| |     _ _ __ ___ _   _| | __ _ _ __  | |     _ ___| |_ ___
| |    | | '__/ __| | | | |/ _` | '__| | |    | / __| __/ __|
| |____| | | | (__| |_| | | (_| | |    | |____| \__ \ |_\__ \
\__ ___|_|_|  \___|\__,_|_|\__,_|_|    |______|_|___/\__|___/

Traversal through a circular linked list is similar to traversal through a standard linked list, but must terminate after reaching the start(head) node a second time, instead of terminating at null. The tail node points to the start node. In a circular doubly-linked list the startNode->prev points to the tail. Forward and reverse traversal have the same structure. Reverse traversal starts at the tail and uses the prev pointer, and ends when coming back to the tail.

CircularListTraverse(start){
 if(start!=null){
   currentNode = start;
   do{
     visit current; //this could be print out something for example
     current = current->next;
   }while (current != start);
 }
}





 _______                                 _            _      _       _            _   _      _     _
|__   __|                               | |          | |    (_)     | |          | | | |    (_)   | |
   | |_ __ __ ___   _____ _ __ ___  __ _| |  ______  | |     _ _ __ | | _____  __| | | |     _ ___| |_ ___
   | | '__/ _` \ \ / / _ \ '__/ __|/ _` | | |______| | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __/ __|
   | | | | (_| |\ V /  __/ |  \__ \ (_| | |          | |____| | | | |   <  __/ (_| | | |____| \__ \ |_\__ \
   |_|_|  \__,_| \_/ \___|_|  |___/\__,_|_|          |______|_|_| |_|_|\_\___|\__,_| |______|_|___/\__|___/
This algorithm visits all nodes in the list once and performs an operation, a common operation is to print. the algorithm starts by pointing curNode to the list->head. While curNode != null, perform operation and then point curNode to curNode->next. After the tail is visited, curNode points to the tail->next which does not exist.curNode == null the traversal ends. The traversal algorithm supports singly and doubly-linked lists, with a doubly-linked list also supporting a reverse traversal.
listTraverse(list){
 curNode = list->head; //start for circular lists! Use tail for reverse traversal!
 while(curNode!=null){
   //perform operation(s) like printf("%s\n", );
   curNode = curNode->next;  // Use prev instead of next for reverse traversal!
 }
}
 __ ___            _   _                        _      _       _            _   _      _     _
/  ____|          | | (_)                      | |    (_)     | |          | | | |    (_)   | |
| (___   ___  _ __| |_ _ _ __   __ _   ______  | |     _ _ __ | | _____  __| | | |     _ ___| |_ ___
\ ___ \ / _ \| '__| __| | '_ \ / _` | |______| | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __/ __|
 ____) | (_) | |  | |_| | | | | (_| |          | |____| | | | |   <  __/ (_| | | |____| \__ \ |_\__ \
|_____/ \___/|_|   \__|_|_| |_|\__, |          |______|_|_| |_|_|\_\___|\__,_| |______|_|___/\__|___/
                               __/ |
                              |___/
Starting with the second list element, each element in the linked list is visited. Each element is moved back as needed and inserted into the correct position in the list's sorted portion. The list must be doubly-linked! Very similar to algorithm for arrays, the runtime is O(N^2), unless it is already sorted then the runtime complexity is O(N).
ListInsertionSortDoublyLinked(list){
 curNode= list->head->next;
 while(curNode!= null){
   nextNode = curNode->next;
   searchNode = curNode->prev;
   while(searchNode!= null && searchNode->data > curNode->data){
     searchNode = searchNode->;
   }
   //Remove and re-insert curNode
   listRemove(list,curNode);
   if (searchNode == null){
     curNode->prev = null;
     listPrepend(list,curNode);
   }
   else{listInsertAfter(list,searchNode,curNode);}
   //Advance to next node
   curNode = nextNode;
 }
}
ListInsertionSortSinglyLinked (list){
 beforeCurrent = list->head;
 curNode = list ->head->next;
 while(curNode!= null){
   next = curNode->next;
   position = ListFindInsertionPostion(list,curNode->); //searches the list for the insertion position and return the list node after which the current node should be inserted. if it is inserted at the head it will return null.
   if(position = beforeCurrent) {beforeCurrent = curNode;}
   else{
     ListRemoveAfter(list, beforeCurrent)
     if(position == null){listPrepend(list,beforeCurrent);}
     else { listInsertAfter(list, position, curNode);}
   }
   curNode = next;
 }
}
ListFindInsertionPostion(list, dataValue){
 curNodeA = null;
 curNodeB = list->head;
 while(curNodeB != null && dataValue>curNodeB->data){
   curNodeA = curNodeB;
   curNodeB = curNodeB->next;
 }
 return curNodeA;
}
Very difficut to adapt quicksort and heapsort from arrays to linked lists because there is no indexed access.
 _____                                    _   _           _                      _      _       _            _   _      _     _
|  __ \                                  | \ | |         | |                    | |    (_)     | |          | | | |    (_)   | |
| |  | |_   _ _ __ ___  _ __ ___  _   _  |  \| | ___   __| | ___  ___   ______  | |     _ _ __ | | _____  __| | | |     _ ___| |_ ___
| |  | | | | | '_ ` _ \| '_ ` _ \| | | | | . ` |/ _ \ / _` |/ _ \/ __| |______| | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __/ __|
| |__| | |_| | | | | | | | | | | | |_| | | |\  | (_) | (_| |  __/\__ \          | |____| | | | |   <  __/ (_| | | |____| \__ \ |_\__ \
|_____/ \__,_|_| |_| |_|_| |_| |_|\__, | |_| \_|\___/ \__,_|\___||___/          |______|_|_| |_|_|\_\___|\__,_| |______|_|___/\__|___/
                                   __/ |
                                  |___/
Linked list implementation may use a dummy node or a header node. A node with an unused data member that always resides at the head of the list, and cannot be removed. Using a dummy node simplifies the algorithms for a linked list because the head and tail pointers are never null. An empty list consists of the dummy node, which has the next pointer set to null and the head and tail pointers both pointing to the dummy node.


SINGLY-LINKED LIST

listAppend(list,newNode){
  list->tail->next = newNode;
  list->tail = newNode;
}

listPrepend(list,newNode){
  newNode->next = list->head->next;
  list->head->next = newNode;
}

listInsertAfter(list, curNode){   //insert after tail
  if(curNode == list->tail){
    list->tail->next = newNode;
    list->tail = newNode;
  }
  else{
    newNode->next = curNode->next;
    curNode->next = newNode;
  }
}

ListRemoveAfter(list, curNode){
  if(curNode!=null && curNode->next != null){
    sucNode = curNode->next->next;
    curNode->next = sucNode;

    if(sucNode == null){    //removed tail
      list->tail = curNode;
    }
  }
}

DOUBLY-LINKED LIST

listAppend(list, newNode){
  list->tail->next = newNode;
  newNode->prev = list->tail;
  list->tail = newNode;
}

listPrepend(list, newNode){
  firstNode = list->head->next;

  //set the next and prev pointer for newNode
  newNode->next = list->head->next;
  newNode->prev = list ->head;

  //set the dummy nodes next pointer
  list->head->next =newNode;
  //SET PREV ON FORMER FIRST node
  if(firstNode != null){firstNode->prev = newNode;}
}

listInsertAfter(list, curNode,newNode){
  if(curNode == list->tail){ //insert after tail
    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
  }
  else{
    sucNode = curNode->next;
    newNode->next = sucNode;
    newNode->prev = curNode;
    curNode->next = newNode;
    sucNode->prev = newNode;
  }
}

listRemove(list, curNode){
  if(curNode == list->head){
    //dummy node cannot be Removed
    return;
  }
  sucNode = curNode->next;
  predNode = curNode->prev;

  if (sucNode != null){sucNode->prev = predNode;}

  //predecessor node is always non- null
  predNode->next = sucNode;

  if(curNode == list->tail) { list->tail = predNode;} //removed tail
}


USING TWO DUMMY NODES IN DOUBLY-LINKED LIST


listInsertAfter(list,curNode,newNode){
  if(curNode == list->tail){return;} //can't insert after dummy tail!

  sucNode = curNode->;
  newNode->next = sucNode;
  newNode->prev = sucNode;
  curNode->next = newNode;
  sucNode->prev = newNode;
}

listRemove(list,curNode){
  if(curNode == list->head || curNode == list->tail){return;} //dummy nodes cannot be removed!
  sucNode = curNode->next;
  predNode = curNode->prev;

  //successor node is never null!
  sucNode->prev =predNode;
  //predecessor node is never null!
  predNode->next = sucNode;
}


 _____                          _
|  __ \                        (_)
| |__) |___  ___ _   _ _ __ ___ _  ___  _ __
|  _  // _ \/ __| | | | '__/ __| |/ _ \| '_ \
| | \ \  __/ (__| |_| | |  \__ \ | (_) | | | |
|_|  \_\___|\___|\__,_|_|  |___/_|\___/|_| |_|

forward traversal through a linked list can be implemented using a recursive function that takes a nodes as an argument. If non-null, the node is visited first. Then a recursive call is made on the node next pointer to traverse the remainder of the list. If the recursive call is made first (before visits a node) the list is traversed in reverse order.

listTraverse(list){ listTraverseRecursive(list->);}

listTraverseRecursive(node){
  if(node!=null){
    //do something with the node you are visiting
    //perhaps print?
    listTraverseRecursive(node->next)
  }
}

listTraverseReverse(list){
  listTraverseReverseRecursive(list->head)
}

listTraverseReverseRecursive(node){
  if(node!=null){
    listTraverseReverseRecursive(node->next)
    //do something with the node you visit such as print?
  }
}


A recursive linked list search is implemented similar to forward traversal.

listSearch(list,key){ return listSearchRecursive(key,list->head);}

listSearchRecursive(key,node){
  if(node!=null){
    if(node->data ==key){return node;}
    return listSearchRecursive(key,node->next);
  }
  return null;
}



  _____ _             _               _____ _______
 / ____| |           | |        /\   |  __ \__   __|
| (___ | |_ __ _  ___| | __    /  \  | |  | | | |
 \___ \| __/ _` |/ __| |/ /   / /\ \ | |  | | | |
 ____) | || (_| | (__|   <   / ____ \| |__| | | |
|_____/ \__\__,_|\___|_|\_\ /_/    \_\_____/  |_|

Push(stack,x) inserts x on top of stack
Pop(stack) returns and removes item at top of stack
Peek(stack) returns but does not remove item at top of stack
IsEmpty(stack) returns true if stack has no items
GetLength(stack) returns the number of items in the stack

first in last out FILO structure, items are only inserted or removed from the top.

StackPush(stack,item){
  newNode = new node;
  newNode->next = null;
  newNode->data = item;

  //insert as list head(top of stack)
  listPrepend(stack,newNode);
}

StackPop(stack){
  headData = stack->head->data;
  ListRemoveAfter(stack,null);
  return headData;
}

  ____                                   _____ _______
 / __ \                            /\   |  __ \__   __|
| |  | |_   _  ___ _   _  ___     /  \  | |  | | | |
| |  | | | | |/ _ \ | | |/ _ \   / /\ \ | |  | | | |
| |__| | |_| |  __/ |_| |  __/  / ____ \| |__| | | |
 \___\_\\__,_|\___|\__,_|\___| /_/    \_\_____/  |_|

Enqueue(queue,x) inserts x at end of the queue
Dequeue(queue) returns and removes item at front of queue
Peek(queue) returns but does not remove item at the front of the queue
IsEmpty(queue) returns true if queue has no items
GetLength(queue) returns the number of items in the queue

A queue is an ADT with items inserted at the end and removed from the front. The enqueue operation inserts an item at the end of the queue. the dequeue operation removes and returns the item at the front of the queue. A queue is referred to as a first in first out ADT, can be implemented using a linked list or an array.

QueueEnqueue(queue,item){
  newNode= new node;
  newNode->next =null;
  newNode->data = item;

  //insert node as list tail(end of queue)
  listAppend(queue,newNode)
}

QueueDequeue(queue){
  headData = queue->head->data;
  ListRemoveAfter(queue,null);
  return headData;
}


 _____                                   _____ _______
|  __ \                            /\   |  __ \__   __|
| |  | | ___  __ _ _   _  ___     /  \  | |  | | | |
| |  | |/ _ \/ _` | | | |/ _ \   / /\ \ | |  | | | |
| |__| |  __/ (_| | |_| |  __/  / ____ \| |__| | | |
|_____/ \___|\__, |\__,_|\___| /_/    \_\_____/  |_|
                | |
                |_|

PushFront(deque,x) inserts x at the front of the deque
PushBack(deque,x) inserts x at the back of the deque
PopFront(deque) returns and removes item at the front of the deque
PopBack(deque) returns and removes item at the back of the deque
PeekFront(deque) returns but does not remove item at the front of deque
PeekBack(deque) returns but does not remove item at the back of deque
IsEmpty(deque) returns true if the deque is empty
GetLength(deque) returns the number of items in the deque

A 'DECK' id a doubled-ended queue, and can have items inserted/removed at both the front and the back.


                                 _                        _   _ _     _
    /\                          | |                      | | | (_)   | |
   /  \   _ __ _ __ __ _ _   _  | |__   __ _ ___  ___  __| | | |_ ___| |_ ___
  / /\ \ | '__| '__/ _` | | | | | '_ \ / _` / __|/ _ \/ _` | | | / __| __/ __|
 / ____ \| |  | | | (_| | |_| | | |_) | (_| \__ \  __/ (_| | | | \__ \ |_\__ \
/_/    \_\_|  |_|  \__,_|\__, | |_.__/ \__,_|___/\___|\__,_| |_|_|___/\__|___/
                          __/ |
                         |___/

An array-based list supports the common list ADT operations such as append, prepend, insert after, remove and search. The implementation allocates a fixed size array and uses a length variable to keep track of how many array elements are in use. the list starts with a default allocation size a common size is ten.

arrayListAppend(list, newItem){
  if(list->allocationSize == list->length){
    arrayListResize(list,list->length*2)
  }
  list->array[list->length]= newItem;
  list->length = list->length +1;
}

arrayListResize(list,newAllocationSize){
  newArray = new array of size newAllocationSize;
  copy all elements from list->array to newArray;
  list->array= newArray;
  list->allocationSize = newAllocationSize;
}

ArrayListPrepend(list,newItem){
// If the list is full, double allocation size
  if(list->allocationSize== list->length){arrayListResize(list,list->length *2);}
// Start at the end of the list, while i>0, decrement i and set the value of current postion to the element before. This moves each element up 1 index remember this is actually bytes that change with data type!
  for(int i = list->length; i>0;i--){list->array[i]= list->array[i-1];}
  list->array[0]= newItem; // put the newItem at element 0
  list->length = list-> length +1;
}

arrayListInsertAfter(list, index, newItem){
  if(list->allocationSize== list->length) {arrayListResize(list, list->length * 2);}

  for(int i = list->length; i > index +1; i--) {list->array[i] = list-array[i-1];}

  list->array[index +1] = newItem;
  list->length = list->length +1;
}

arrayListSearch(list,item){
  for(int i=0; i<list->length;i++) {if(list->array[i] == item){returni};}

  return -1 // not found
}

arrayListRemoveAt(list,index){
  if(index >=0 && index < list->length){
    for(int i = index; i< list->length -1; i++) {list->array[i]=list->array[i+1]}

    list->length = list_.length - 1;
  }
}

ArrayAppend(array, newItem) {
    currentSize = array⇢length
    Increase array size by one
    array[currentSize] = newItem
}

FindMax(list, listSize) {
   if (listSize >= 1) {
      maximum = list[0]
      i = 1
      while (i < listSize) {
         if (list[i] > maximum) {maximum = list[i]}
         i = i + 1
      }
      return maximum
   }
}

DisplayTopFiveSalespersons(allSalespersons) {
   // topSales array has 5 elements
   // Array elements have subitems for name and total sales
   // Array will be sorted from highest total sales to lowest total sales
   Create topSales array with 5 elements

   // Initialize all array elements with a negative sales total
   for (i = 0; i < topSales⇢length; ++i) {
      topSales[i]⇢name = ""
      topSales[i]⇢salesTotal = -1
   }

   for each salesPerson in allSalespersons {
      // If salesPerson's total sales is greater than the last
      // topSales element, salesPerson is one of the top five so far
      if (salesPerson⇢salesTotal > topSales[topSales⇢length - 1]⇢salesTotal) {

         // Assign the last element in topSales with the current salesperson
         topSales[topSales⇢length - 1]⇢name =  salesPerson⇢name
         topSales[topSales⇢length - 1]⇢salesTotal =  salesPerson⇢salesTotal

         // Sort topSales in descending order
         SortDescending(topSales)
      }
   }

   // Display the top five salespersons
   for (i = 0; i < topSales⇢length; ++i) {
      Display topSales[i]
   }
}
