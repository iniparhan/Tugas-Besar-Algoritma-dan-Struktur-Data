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

// Fungsi untuk mencetak jalur
void cetakJalur(struct node* jalur[], int panjang) {
    for (int i = 0; i < panjang; i++) {
        printf("%s -> ", jalur[i]->data.nama);
    }
    printf("\n");
}

// Fungsi untuk menemukan jalur dari root ke node dengan nama tertentu
int cari_jalur(struct node* root, char *nama, struct node* jalur[], int panjang) {
    if (root == NULL) return 0;
    jalur[panjang] = root;
    panjang++;
    if (strcmp(root->data.nama, nama) == 0) {
        cetakJalur(jalur, panjang);
        return 1;
    }
    if ((root->kiri && cari_jalur(root->kiri, nama, jalur, panjang)) || (root->kanan && cari_jalur(root->kanan, nama, jalur, panjang))) {
        return 1;
    }
    return 0;
}

int main() {
    // Membuat root kategori utama
    struct node* root = buatNode("Supermarket", 0, 0, "Root");

        // Menambahkan kategori
        struct node* kebutuhanSehariHari = masukkanKiri(root, "Kebutuhan Sehari-hari", 0, 0, "Kategori");

            // Menambahkan barang ke kategori Kebutuhan Sehari-hari
            struct node* dapur = masukkanKiri(kebutuhanSehariHari, "Dapur", 0, 0, "Kebutuhan Sehari-hari");
                masukkanKiri(kebutuhanSehariHari->kiri, "Sabun Cuci Piring", 10000.00, 10, "Kebutuhan Sehari-hari");
                masukkanKanan(kebutuhanSehariHari->kiri, "Spons", 10000.00, 5, "Kebutuhan Sehari-hari");
            struct node* kamarMandi = masukkanKanan(kebutuhanSehariHari, "Kamar Mandi", 0, 0, "Kebutuhan Sehari-hari");
                struct node* vitaminRambut = masukkanKanan(kebutuhanSehariHari->kanan, "Vitamin Rambut", 0, 0, "Kebutuhan Sehari-hari");
                    masukkanKiri(kamarMandi->kanan, "Conditioner", 35000.00, 20, "Kebutuhan Sehari-hari");
                    masukkanKanan(kamarMandi->kanan, "Shampoo", 30000.00, 25, "Kebutuhan Sehari-hari");
                struct node* sabunMandi = masukkanKiri(kebutuhanSehariHari->kanan, "Sabun Mandi", 0, 0, "Kebutuhan Sehari-hari");
                    masukkanKiri(kamarMandi->kiri, "Sabun Cair", 15000.00, 14, "Kebutuhan Sehari-hari");
                    masukkanKanan(kamarMandi->kiri, "Sabun Batang", 3000.00, 17, "kebutuhan Sehari-hari");
    
        struct node* bahanMakanan = masukkanKanan(root, "Bahan Makanan", 0, 0, "Kategori");
            // Menambahkan barang ke kategori Bahan Makanan
            struct node* Beras = masukkanKiri(bahanMakanan, "Beras", 0, 0, "Bahan Makanan");
                masukkanKiri(bahanMakanan->kiri, "Beras Putih", 60000.00, 12, "Bahan Makanan");
                masukkanKanan(bahanMakanan->kiri, "Beras Merah", 70000.00, 15, "Bahan Makanan");
            struct node* Lauk = masukkanKanan(bahanMakanan, "Lauk", 0, 0, "Bahan Makanan");
                struct node* ayamSeekor = masukkanKiri(bahanMakanan->kanan, "Ayam Seekor", 40000.00, 10, "Bahan Makanan");
                    masukkanKanan(Lauk->kiri, "Dada Ayam", 20000.00, 10, "Bahan Makanan");
                    struct node* pahaAyam = masukkanKiri(Lauk->kiri, "Paha Ayam", 0, 0, "Bahan Makanan");
                        masukkanKiri(ayamSeekor->kiri, "500 gram", 16000, 12, "Bahan Makanan");
                        masukkanKanan(ayamSeekor->kiri, "1000 gram", 32000, 20, "Bahan Makanan");
                struct node* beef = masukkanKanan(bahanMakanan->kanan, "Beef", 0, 0, "Bahan Makanan");
                    struct node* wagyu = masukkanKiri(Lauk->kanan, "Wagyu", 0, 0, "Bahan Makanan");
                        masukkanKiri(beef->kiri, "Slice", 54000.00, 30, "Bahan Makanan");

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
    float cari_harga = 40000.00;
    printf("\nData barang dengan harga %.2f atau lebih:\n", cari_harga);
    cariNode(root, cari_harga);

    // Pemanggilan Fungsi untuk menampilkan jalur dari root ke barang yang dituju
    char *cariNama = "Sabun Cair";
    printf("\nJalur dari root ke nama %s:\n", cariNama);
    struct node* jalur[100];
    if (!cari_jalur(root, cariNama, jalur, 0)) {
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
