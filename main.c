#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char item[100];
    struct node *kiri;
    struct node *kanan;
};

struct node *buatNode(char *nilai) {
    struct node *nodeBaru = malloc(sizeof(struct node));
    strcpy(nodeBaru->item, nilai);
    nodeBaru->kiri = NULL;
    nodeBaru->kanan = NULL;
    return nodeBaru;
}

struct node *masukkanKiri(struct node *root, char *nilai) {
    if (root == NULL) return NULL;
    root->kiri = buatNode(nilai);
    return root->kiri;
}

struct node *masukkanKanan(struct node *root, char *nilai) {
    if (root == NULL) return NULL;
    root->kanan = buatNode(nilai);
    return root->kanan;
}

void traversalInOrder(struct node *root) {
    if (root == NULL) return;
    traversalInOrder(root->kiri);
    printf("%s -> ", root->item);
    traversalInOrder(root->kanan);
}

void traversalPreOrder(struct node *root) {
    if (root == NULL) return;
    printf("%s -> ", root->item);
    traversalPreOrder(root->kiri);
    traversalPreOrder(root->kanan);
}

void traversalPostOrder(struct node *root) {
    if (root == NULL) return;
    traversalPostOrder(root->kiri);
    traversalPostOrder(root->kanan);
    printf("%s -> ", root->item);
}

int main() {
    // Mbahnya tree (Supermarket)
    struct node *root = buatNode("Supermarket");

        struct node *makanan = masukkanKiri(root, "Makanan");

            struct node *kaleng = masukkanKiri(makanan, "Kaleng");

                struct node *lauk = masukkanKiri(kaleng, "Lauk");
                    masukkanKiri(lauk, "Sarden");
                    masukkanKanan(lauk, "Rendang");
                    masukkanKanan(lauk, "Tuna");

                struct node *buah = masukkanKanan(kaleng, "Buah");
                    masukkanKiri(buah, "Nanas");
                    masukkanKanan(buah, "Leci");

                masukkanKanan(kaleng, "Kornet");

            struct node *cemilan = masukkanKanan(makanan, "Cemilan");
                masukkanKiri(cemilan, "Rentengan");
                struct node *kiloan = masukkanKanan(cemilan, "Kiloan");
                    masukkanKiri(kiloan,"Jelly");
                    masukkanKanan(kiloan,"Kacang-kacangan");

        struct node *minuman = masukkanKanan(root, "Minuman");
            struct node *berperisa = masukkanKiri(minuman, "Berperisa");
                masukkanKiri(berperisa, "Teh");
                masukkanKanan(berperisa, "Yogurt");
                masukkanKanan(berperisa, "Kopi");

            struct node *bersoda = masukkanKanan(minuman, "Bersoda");
                masukkanKiri(bersoda, "Cola");
                masukkanKanan(bersoda, "Teh Soda");

            masukkanKanan(minuman, "Air Mineral");

    printf("Traversal InOrder \n");
    traversalInOrder(root);
    printf("\n");

    printf("Traversal PreOrder \n");
    traversalPreOrder(root);
    printf("\n");

    printf("Traversal PostOrder \n");
    traversalPostOrder(root);
    printf("\n");

    return 0;
}
