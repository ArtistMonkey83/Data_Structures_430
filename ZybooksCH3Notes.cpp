  _____ _             _                  _      _       _            _   _      _     _
 / ____(_)           | |                | |    (_)     | |          | | | |    (_)   | |
| (___  _ _ __   __ _| |_   _   ______  | |     _ _ __ | | _____  __| | | |     _ ___| |_ ___
 \___ \| | '_ \ / _` | | | | | |______| | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __/ __|
 ____) | | | | | (_| | | |_| |          | |____| | | | |   <  __/ (_| | | |____| \__ \ |_\__ \
|_____/|_|_| |_|\__, |_|\__, |          |______|_|_| |_|_|\_\___|\__,_| |______|_|___/\__|___/
                 __/ |   __/ |
                |___/   |___/

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

  _____            _   _                        _      _       _            _   _      _     _
 / ____|          | | (_)                      | |    (_)     | |          | | | |    (_)   | |
| (___   ___  _ __| |_ _ _ __   __ _   ______  | |     _ _ __ | | _____  __| | | |     _ ___| |_ ___
 \___ \ / _ \| '__| __| | '_ \ / _` | |______| | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __/ __|
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




_____                          _
|  __ \                        (_)
| |__) |___  ___ _   _ _ __ ___ _  ___  _ __
|  _  // _ \/ __| | | | '__/ __| |/ _ \| '_ \
| | \ \  __/ (__| |_| | |  \__ \ | (_) | | | |
|_|  \_\___|\___|\__,_|_|  |___/_|\___/|_| |_|


  _____ _             _               _____ _______
 / ____| |           | |        /\   |  __ \__   __|
| (___ | |_ __ _  ___| | __    /  \  | |  | | | |
 \___ \| __/ _` |/ __| |/ /   / /\ \ | |  | | | |
 ____) | || (_| | (__|   <   / ____ \| |__| | | |
|_____/ \__\__,_|\___|_|\_\ /_/    \_\_____/  |_|

  ____                                   _____ _______
 / __ \                            /\   |  __ \__   __|
| |  | |_   _  ___ _   _  ___     /  \  | |  | | | |
| |  | | | | |/ _ \ | | |/ _ \   / /\ \ | |  | | | |
| |__| | |_| |  __/ |_| |  __/  / ____ \| |__| | | |
 \___\_\\__,_|\___|\__,_|\___| /_/    \_\_____/  |_|

 _____                                   _____ _______
|  __ \                            /\   |  __ \__   __|
| |  | | ___  __ _ _   _  ___     /  \  | |  | | | |
| |  | |/ _ \/ _` | | | |/ _ \   / /\ \ | |  | | | |
| |__| |  __/ (_| | |_| |  __/  / ____ \| |__| | | |
|_____/ \___|\__, |\__,_|\___| /_/    \_\_____/  |_|
                | |
                |_|
                _                        _   _ _     _
/\                          | |                      | | | (_)   | |
/  \   _ __ _ __ __ _ _   _  | |__   __ _ ___  ___  __| | | |_ ___| |_ ___
/ /\ \ | '__| '__/ _` | | | | | '_ \ / _` / __|/ _ \/ _` | | | / __| __/ __|
/ ____ \| |  | | | (_| | |_| | | |_) | (_| \__ \  __/ (_| | | | \__ \ |_\__ \
/_/    \_\_|  |_|  \__,_|\__, | |_.__/ \__,_|___/\___|\__,_| |_|_|___/\__|___/
         __/ |
        |___/                                                                                                                                 
