#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n) {
// write your code here...
	if (n <= 0) return NULL;

    int x;
    NODE head = NULL, tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        NODE newNode = createNodeInCLL(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;        // points to itself initially
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;          // maintain circularity
        }
    }
    return head;


}

// Traverse CLL
void traverseListInCLL(NODE head) {

// write your code here...
	 if (head == NULL) return;

    NODE temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");


}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE head, int pos, int data) {
//write your code here.
	if (pos <= 0) {
        printf("Position not found\n");
        return head;
    }

    NODE newNode = createNodeInCLL(data);

    // Empty list: only allow insert at position 1
    if (head == NULL) {
        if (pos != 1) {
            printf("Position not found\n");
            free(newNode);
            return head;
        }
        head = newNode;
        newNode->next = head;
        return head;
    }

    // Insert at head (position 1)
    if (pos == 1) {
        NODE last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        return head;
    }

    // Insert at position > 1
    NODE curr = head;
    int count = 1;
    while (count < pos - 1 && curr->next != head) {
        curr = curr->next;
        count++;
    }

    if (count != pos - 1 || curr->next == NULL) {
        // Position beyond length
        printf("Position not found\n");
        free(newNode);
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;


	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(NODE head, int pos) {
	if (head == NULL) {
        printf("CLL is empty\n");
        return head;
    }

    if (pos <= 0) {
        printf("Position not found\n");
        return head;
    }

    NODE curr = head, prev = NULL;
    int count = 1;

    // Single node list
    if (head->next == head) {
        if (pos != 1) {
            printf("Position not found\n");
            return head;
        }
        printf("Deleted element: %d\n", head->data);
        free(head);
        return NULL;
    }

    // Delete head node
    if (pos == 1) {
        // Find last node
        NODE last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        NODE temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return head;
    }

    // Delete node at position > 1
    curr = head;
    while (count < pos && curr->next != head) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (count != pos) {
        printf("Position not found\n");
        return head;
    }

    prev->next = curr->next;
    printf("Deleted element: %d\n", curr->data);
    free(curr);
    return head;
	
	
}

// Reverse CLL
NODE reverseCLL(NODE head) {
	
//write your code here...
	if (head == NULL || head->next == head) return head;

    NODE prev = NULL, curr = head, next = NULL;
    NODE first = head;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != first);

    // Fix circular link
    first->next = prev;
    head = prev;
    return head;


}

// Concatenate two CLLs
NODE concatCLL(NODE first, NODE second) {

//write your code here..
	if (first == NULL) return second;
    if (second == NULL) return first;

    NODE last1 = first;
    while (last1->next != first) {
        last1 = last1->next;
    }

    NODE last2 = second;
    while (last2->next != second) {
        last2 = last2->next;
    }

    // Connect last of first to head of second
    last1->next = second;
    // Connect last of second to head of first
    last2->next = first;

    return first;



}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
