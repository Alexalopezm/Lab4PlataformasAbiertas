/*
 *Implementacion de una lista enlazada que realiza las operaciones:
 * -Agregar nodo
 * -Eliminar nodo por valor
 * -Agregar nodo al inicio
 * -Agregar nodo al final de la lista
 * -Buscar nodo por su valor
 * -Imprimir lista
 * -Obtener elemento n-simo
 * */
#include <stdlib.h>
#include <stdio.h>

// Agregar nodo
struct Node {
    int data;
    struct Node* next;
};

// Eliminar el nodo por su valor
void deleteNode(int valor, struct Node **node) {
    struct Node* current = *node;
    struct Node* prev = NULL;

    //Caso esquina: eliminar el primer elemento
    if (current != NULL && current->data == valor) {
    *node = current->next;
    free(current);
    return;
    };

    // Buscar el nodo de la lista
    while(current != NULL && current->data != valor) {
    prev = current;
    current = current->next;
    };

    // Nodo encontrado o final de la lista
    if (current == NULL) {
    printf("\nNodo no encontrado en la lista\n");
    return;
    };

    // Encontramos el nodo, toca eliminarlo
    prev->next = current->next;
    free(current);
    printf("\nNodo con valor %d eliminado\n", valor);
};

// Imprimir la lista
void printList(struct Node* node) {
    printf("\nLa lista es: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    };
    printf("\n");
};

// Liberar la memoria
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next; 

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    };
};

// Insertar nodo al principio de la lista
void insert(int data,struct Node** head) {
    struct Node* nuevo = (struct Node*)malloc(sizeof(struct Node));
    nuevo->data = data;
    nuevo->next = (*head);
    (*head) = nuevo;
    printf("\nNodo con valor %d agregado al principio de la lista\n", data);
};

// Insertar nodo al final de la lista
void insertend(int data, struct Node **head) {
    struct Node *nuevo = (struct Node *)malloc(sizeof(struct Node));
    nuevo->data = data;
    nuevo->next = NULL;  // El nuevo nodo será el último, por lo que su puntero 'next' es NULL

    if (*head == NULL) {
        // Si la lista está vacía, el nuevo nodo se convierte en el primer nodo
        *head = nuevo;
    } else {
        // Si la lista no está vacía, recorremos la lista para encontrar el último nodo
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Enlazamos el último nodo con el nuevo nodo
        temp->next = nuevo;
    }
    printf("\nNodo con valor %d agregado al final de la lista\n", data);
};

// Buscar un nodo por su valor
void search(int valor, struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == valor) {
            printf("\nNodo con valor %d encontrado\n", valor);
            return;  // Termina la búsqueda si se encuentra el valor
        };
        current = current->next;
    };
    printf("\nNodo con valor %d no encontrado\n", valor);
};

// Obtener el elemento n-ésimo de la lista y mostrar su valor
void getNthNode(int n, struct Node *head) {
    struct Node *current = head;
    int contador = 0;       // Se inicializa el contador en 0

    while (current != NULL) {
        if (contador == n) {
            printf("\nEl nodo %d tiene el valor: %d\n", n, current->data);
            return;
        };
        contador++;         // Se aumenta el contador
        current = current->next;
    };
    printf("\nEl nodo %d no fue encontrado\n", n);
};


int main() {
    struct Node* head = NULL;
    insert(5, &head);       // Agrega un nodo al principio de la lista
    insert(10, &head);      // Agrega un nodo al principio de la lista
    printList(head);        // Imprime la lista
    insert(15, &head);      // Agrega un nodo al principio de la lista
    printList(head);        // Imprime la lista
    insertend(4, &head);    // Agrega un nodo al final de la lista
    printList(head);        // Imprime la lista
    search(4, head);        // Busca el nodo por su valor
    search(3, head);        // Busca el nodo por su valor
    getNthNode(2, head);    // Busca el nodo n y muestra su valor
    getNthNode(5, head);    // Busca el nodo n y muestra su valor
    deleteNode(10, &head);  // Elimina nodo por su valor
    printList(head);        // Imprime la lista
    freeList(head);         // Libera la memoria
};