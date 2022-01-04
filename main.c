#include <stdio.h>

#include <stdlib.h>

struct bst{

    struct bst * left;

    int data;

    struct bst * right;

};

struct bst * root = NULL;

struct bst * insert(struct bst * root , int data);

void preOrder(struct bst * root);

void inOrder(struct bst * root);

void postOrder(struct bst * root);

void minimum(struct bst * root);

void maximum(struct bst * root);

struct bst * checkLeft(struct bst * root);

struct bst * delete(struct bst * root , int data);

struct bst * search(int data);

int main() {

    // printf("Hello, World!\n");

    int dataToBeEntered;

    int dataToBeDeleted;

    int dataToBeSearched;

    int choice;

    do {

        printf("Enter :: \n");

        printf("1 To Insert Data \n");

        printf("2 To Delete Data \n");

        printf("3 To Print Data In Pre-Order \n");

        printf("4 To Print Data In In-Order \n");

        printf("5 To Print Data In Post-Order \n");

        printf("6 To Print Minimum Value In The Binary Search Tree \n");

        printf("7 To Print Maximum Value In The Binary Search Tree \n");

        printf("8 To Search Data \n");

        printf("9 To Exit \n");

        printf("Enter Your Choice :: \n");

        scanf("%d",&choice);

        switch (choice) {

            case 1:
                printf("Enter Data :: \n");
                scanf("%d",&dataToBeEntered);
                root = insert(root , dataToBeEntered);
                printf("Data %d Successfully Inserted \n",dataToBeEntered);
                break;

            case 2:
                printf("Enter Data :: \n");
                scanf("%d",&dataToBeDeleted);
                root = delete(root , dataToBeDeleted);
                printf("Data %d Successfully Deleted \n",dataToBeDeleted);
                break;

            case 3:
                printf("Data In Pre-Order In The Binary Search Tree Is Given As :: \n");
                preOrder(root);
                break;

            case 4:
                printf("Data In In-Order In The Binary Search Tree Is Given As :: \n");
                inOrder(root);
                break;

            case 5:
                printf("Data In Post-Order In The Binary Search Tree Is Given As :: \n");
                postOrder(root);
                break;

            case 6:
                minimum(root);
                break;

            case 7:
                maximum(root);
                break;

            case 8:
                printf("Enter Data You Want To Search :: \n");
                scanf("%d",&dataToBeSearched);
                search(dataToBeSearched);
                break;

            case 9:
                exit(1);

            default:
                printf("Invalid Entry \n");

        }

    } while (choice != 9);

    return 0;

}

struct bst * insert(struct bst * root , int data){

    struct bst * temp;

    temp = (struct bst *) malloc (sizeof(struct bst));

    temp -> left = NULL;

    temp -> data = data;

    temp -> right = NULL;

    if (root == NULL){

        root = temp;

        return root;

    } else if (root -> data == data){

        return root;

    } else if (root -> data > data){

        root -> left = insert(root -> left , data);

        return root;

    } else if (root -> data < data){

        root -> right = insert(root -> right , data);

        return root;

    }

    return root;

}

void preOrder(struct bst * root){

    struct bst * p;

    p = root;

    if (p != NULL){

        printf("%d \n",p -> data);

        preOrder(p -> left);

        preOrder(p -> right);

    }

}

void inOrder(struct bst * root){

    struct bst * p;

    p = root;

    if (p != NULL){

        inOrder(p -> left);

        printf("%d \n",p -> data);

        inOrder(p -> right);

    }

}

void postOrder(struct bst * root){

    struct bst * p;

    p = root;

    if (p != NULL){

        postOrder(p -> left);

        postOrder(p -> right);

        printf("%d \n",p -> data);

    }

}

void minimum(struct bst * root){

    struct bst * p;

    p = root;

    if (p -> left != NULL){

        while (p -> left != NULL){

            p = p -> left;

        }

        printf("Minimum Value In The Binary Search Tree Is Given As :: %d \n",p -> data);

    }

}

void maximum(struct bst * root){

    struct bst * p;

    p = root;

    if (p -> right != NULL){

        while (p -> right != NULL){

            p = p -> right;

        }

        printf("Maximum Value In The Binary Search Tree Is Given As :: %d \n",p -> data);

    }

}

struct bst * checkLeft(struct bst * root){

    if (root == NULL){

        return root;

    } else if (root -> left != NULL){

        return checkLeft(root -> left);

    } else if (root -> left == NULL){

        return root;

    }

}

struct bst * delete(struct bst * root , int data){

    if (root == NULL){

        return root;

    } else if (data < root -> data){

        root -> left = delete(root -> left , data);

    } else if (data > root -> data){

        root -> right = delete(root -> right , data);

    } else{

        if (root -> left == NULL){

            struct bst * temp = root -> right;

            free(root);

            return temp;

        } else if (root -> right == NULL){

            struct bst * temp = root -> left;

            free(root);

            return temp;

        }

        struct bst * temp = checkLeft(root -> right);

        root -> data = temp -> data;

        root -> right = delete(root -> right , temp -> data);

    }

    return root;

}

struct bst * search(int data){

    struct bst * current;

    current = root;

    while (current -> data != data){

        if (current -> data > data){

            current = current -> left;

        } else{

            current = current -> right;

        }

        if (current == NULL){

            printf("Data %d Not Found \n",data);

            return NULL;

        }

    }

    printf("Data %d Found \n",current -> data);

}