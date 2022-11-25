#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;

struct node* newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->data)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);

  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(){
     int c;
     int n;
printf("Enter \n1 to insert\n2 to delete\n3 to display\n4 to exit\n");
while(1){
    printf("\nEnter choice:");
    scanf("%d",&c);
    switch(c){
        case 1:
        printf("Enter data to insert:");
        scanf("%d",&n);
        root=insert(root,n);
        break;
        case 2:
        printf("Enter data to delete:");
        scanf("%d",&n);
        root=deleteNode(root,n);
        break;
        case 3: 
        inorder(root);
        break;
        case 4:
        exit(0);
        default:
        printf("Enter valid choice");
    }
}
}