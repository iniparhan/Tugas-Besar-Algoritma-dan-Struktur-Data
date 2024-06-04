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
    // Semakin menjorok ke kanan, berarti itu anaknya
    // paham kan? paham doong
    // masa gk paham -_-
    // Contohnya, ini Mbahnya tree (Supermarket)
    struct node *root = buatNode("Supermarket");

        struct node *makanan = masukkanKiri(root,"makanan");
            struct node *kaleng = masukkanKiri(makanan,"kaleng");
                struct node *lauk = masukkanKiri(kaleng,"lauk");
                    struct node *ikan = masukkanKiri(lauk,"ikan");
                        masukkanKiri(ikan,"tuna");
                        masukkanKanan(ikan,"sarden");
                    masukkanKanan(lauk,"rendang");
            
                struct node *buah = masukkanKanan(kaleng,"buah");
                    masukkanKiri(buah,"nanas");
                    struct node *apel = masukkanKanan(buah,"apel");
                        masukkanKiri(apel,"pir");
                                            
            struct node *cemilan = masukkanKanan(makanan,"cemilan");
                masukkanKiri(cemilan,"rentengan");
                struct node *kiloan = masukkanKanan(cemilan,"kiloan");
                    masukkanKiri(kiloan,"jelly");
                    masukkanKanan(kiloan,"kacang-kacangan");

        struct node *minuman = masukkanKanan(root,"minuman");
            struct node *berperisa = masukkanKiri(minuman,"berperisa");
                masukkanKiri(berperisa,"yogurt");
                struct node *kopi = masukkanKanan(berperisa,"kopi");
                    masukkanKiri(kopi,"kopi susu");

            struct node *bersoda = masukkanKanan(minuman,"bersoda");
                masukkanKiri(bersoda,"cola");
                masukkanKanan(bersoda,"soda kopi");


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
