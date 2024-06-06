#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk menyimpan data barang
typedef struct {
    char nama[100];
    float harga;
    int stok;
    char kategori[100];
} Barang;

// Node untuk binary search tree
struct node {
    Barang data;
    struct node* kiri;
    struct node* kanan;
};

// Fungsi untuk membuat node baru
struct node* buatNode(char *nama, float harga, int stok, char *kategori) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data.nama, nama);
    newNode->data.harga = harga;
    newNode->data.stok = stok;
    strcpy(newNode->data.kategori, kategori);
    newNode->kiri = newNode->kanan = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di posisi kiri
struct node *masukkanKiri(struct node *root, char *nama, float harga, int stok, char *kategori) {
    if (root == NULL) return NULL;
    root->kiri = buatNode(nama, harga, stok, kategori);
    return root->kiri;
}

// Fungsi untuk menambahkan node di posisi kanan
struct node *masukkanKanan(struct node *root, char *nama, float harga, int stok, char *kategori) {
    if (root == NULL) return NULL;
    root->kanan = buatNode(nama, harga, stok, kategori);
    return root->kanan;
}

// Fungsi untuk melakukan in-order traversal
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->kiri);
        printf("%s -> ", root->data.nama);
        inorderTraversal(root->kanan);
    }
}

// Fungsi untuk melakukan pre-order traversal
void preorderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%s -> ", root->data.nama);
        preorderTraversal(root->kiri);
        preorderTraversal(root->kanan);
    }
}

// Fungsi untuk melakukan post-order traversal
void postorderTraversal(struct node* root) {
    if (root != NULL) {
        postorderTraversal(root->kiri);
        postorderTraversal(root->kanan);
        printf("%s -> ", root->data.nama);
    }
}

// Fungsi untuk mencari dan menampilkan semua node berdasarkan harga
void cariNode(struct node* root, float harga) {
    if (root == NULL) return;
    if (root->data.harga >= harga) {
        printf("Nama: %s, Harga: %.2f, Stok: %d, Kategori: %s\n", root->data.nama, root->data.harga, root->data.stok, root->data.kategori);
    }
    cariNode(root->kiri, harga);
    cariNode(root->kanan, harga);
}

// Fungsi untuk menghitung tinggi tree
int hitungTinggi(struct node* root) {
    if (root == NULL) return 0;
    int tinggiKiri = hitungTinggi(root->kiri);
    int tinggiKanan = hitungTinggi(root->kanan);
    return (tinggiKiri > tinggiKanan ? tinggiKiri : tinggiKanan) + 1;
}

// Fungsi untuk mencari sibling dari node dengan nama tertentu
struct node* cariSibling(struct node* root, char *nama) {
    if (root == NULL || root->kiri == NULL || root->kanan == NULL) return NULL;
    if ((strcmp(root->kiri->data.nama, nama) == 0 && root->kanan != NULL) || (strcmp(root->kanan->data.nama, nama) == 0 && root->kiri != NULL)) {
        return (strcmp(root->kiri->data.nama, nama) == 0) ? root->kanan : root->kiri;
    }
    struct node* sibling = cariSibling(root->kiri, nama);
    if (sibling != NULL) return sibling;
    return cariSibling(root->kanan, nama);
}

// Fungsi untuk menemukan jalur dari root ke node dengan nama tertentu
int cari_jalur(struct node* root, char *nama) {
    if (root == NULL) return 0;
    printf("%s -> ", root->data.nama);
    if (strcmp(root->data.nama, nama) == 0) {
        printf("\n");
        return 1;
    }
    if ((root->kiri && cari_jalur(root->kiri, nama)) || (root->kanan && cari_jalur(root->kanan, nama))) {
        return 1;
    }
    printf("<- "); // Backtracking step
    return 0;
}

int main() {
    // Membuat root kategori utama
    struct node* root = buatNode("Supermarket", 0, 0, "Root");

    // Menambahkan kategori
    struct node* kebutuhanSehariHari = masukkanKiri(root, "Kebutuhan Sehari-hari", 0, 0, "Kategori");
    struct node* bahanMakanan = masukkanKanan(root, "Bahan Makanan", 0, 0, "Kategori");

    // Menambahkan barang ke kategori Kebutuhan Sehari-hari
    masukkanKiri(kebutuhanSehariHari, "Sabun Mandi", 15000.00, 20, "Kebutuhan Sehari-hari");
    masukkanKanan(kebutuhanSehariHari, "Shampoo", 25000.00, 15, "Kebutuhan Sehari-hari");
    masukkanKiri(kebutuhanSehariHari->kanan, "Pasta Gigi", 10000.00, 30, "Kebutuhan Sehari-hari");

    // Menambahkan barang ke kategori Bahan Makanan
    masukkanKiri(bahanMakanan, "Beras 5kg", 60000.00, 10, "Bahan Makanan");

    // Pemanggilan Fungsi In-order Traversal
    printf("In-order Traversal:\n");
    inorderTraversal(root);
    printf("\n");

    // Pemanggilan Fungsi Pre-order Traversal
    printf("\nPre-order Traversal:\n");
    preorderTraversal(root);
    printf("\n");

    // Pemanggilan Fungsi Post-order Traversal
    printf("\nPost-order Traversal:\n");
    postorderTraversal(root);
    printf("\n");

    // Pemanggilan Fungsi untuk mencari barang yang lebih dari harga 20000
    float cari_harga = 20000.00;
    printf("\nData barang dengan harga %.2f atau lebih:\n", cari_harga);
    cariNode(root, cari_harga);

    // Pemanggilan Fungsi untuk menampilkan jalur dari root ke barang yang dituju
    char *cariNama = "Sabun Mandi";
    printf("\nJalur dari root ke nama %s:\n", cariNama);
    if (!cari_jalur(root, cariNama)) {
        printf("Nama %s tidak ditemukan di tree.\n", cariNama);
    }

    // Pemanggilan Fungsi untuk menampilkan tinggi tree 
    printf("\nTinggi tree: %d\n", hitungTinggi(root));

    // Pemanggilan Fungsi untuk menampilkan sibling atau saudara yang 1 parent
    struct node* sibling = cariSibling(root, cariNama);
    if (sibling != NULL) {
        printf("\nSibling dari nama %s:\n", cariNama);
        printf("Nama: %s, Harga: %.2f, Stok: %d, Kategori: %s\n", sibling->data.nama, sibling->data.harga, sibling->data.stok, sibling->data.kategori);
    } else {
        printf("\nTidak ada sibling untuk nama %s.\n", cariNama);
    }

    return 0;
}
