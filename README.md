# Tugas Besar Banget Sumpah dah | Semester 2
### Table of Contents

- [Main.c](#Main)
- [Main_v2.c](#Main_v2)

## Main
### Problem yang ada

- Fungsi Apalagi yang perlu dimasukkan, supaya lebih beragam <br>

![Screenshot (692)](https://github.com/iniparhan/Tugas-Besar-Banget-Semester-2/assets/105894704/bb9cab9f-9060-4057-875d-08f0ec8787cf)

_Ini Cuma Awalan doang yak, buat nyoba dulu_ <br>
_nanti aja kalo mau dimasukkin lagi sisanya_ 

<br> _Output Code_ <br>
> _Traversal InOrder_ <br><br> tuna -> ikan -> sarden -> lauk -> rendang -> kaleng -> nanas -> buah -> pir -> apel -> makanan -> rentengan -> cemilan -> jelly -> kiloan -> kacang-kacangan -> Supermarket -> yogurt -> berperisa -> kopi susu -> kopi -> minuman -> cola -> bersoda -> soda kopi -> 

> _Traversal PreOrder_ <br><br> Supermarket -> makanan -> kaleng -> lauk -> ikan -> tuna -> sarden -> rendang -> buah -> nanas -> apel -> pir -> cemilan -> rentengan -> kiloan -> jelly -> kacang-kacangan -> minuman -> berperisa -> yogurt -> kopi -> kopi susu -> bersoda -> cola -> soda kopi -> 

> _Traversal PostOrder_ <br><br> tuna -> sarden -> ikan -> rendang -> lauk -> nanas -> pir -> apel -> buah -> kaleng -> rentengan -> jelly -> kacang-kacangan -> kiloan -> cemilan -> makanan -> yogurt -> kopi susu -> kopi -> berperisa -> cola -> soda kopi -> bersoda -> minuman -> Supermarket -> 
<br>

## Main_v2

Ini versi upgrade dari file kode sebelumnya, isi fungsinya sebagai berikut :

- Membuat node
- Memasukkan Node ke kiri atau kanan
- In-order traversal
- pre-order traversal
- post-order traversal
- Mencari dan menampilkan node berdasarkan harga tertentu
- Menghitung tinggi tree
- Mencari sibling dari node dengan nama tertentu
- Menemukan jalur dari root ke node dengan nama tertentu

### Problem yang ada
- Keknya datanya masih kurang banyak deh, minta tolong tambahin ya kalo kurang

#### _BTW Isi Structnya Udah 4_

![Screenshot (696)](https://github.com/iniparhan/Tugas-Besar-Banget-Semester-2/assets/105894704/2f8eb4f1-047c-41e4-a05f-53ea4f473982)

<br> _Output Code_ <br>

> _In-order Traversal:_ <br><br> Sabun Mandi -> Kebutuhan Sehari-hari -> Pasta Gigi -> Shampoo -> Supermarket -> Beras 5kg -> Bahan Makanan ->     

> _Pre-order Traversal:_ <br><br> Supermarket -> Kebutuhan Sehari-hari -> Sabun Mandi -> Shampoo -> Pasta Gigi -> Bahan Makanan -> Beras 5kg ->     

> _Post-order Traversal:_ <br><br> Sabun Mandi -> Pasta Gigi -> Shampoo -> Kebutuhan Sehari-hari -> Beras 5kg -> Bahan Makanan -> Supermarket ->     

> _Data barang dengan harga 20000.00 atau lebih:_ <br><br> Nama: Shampoo, Harga: 25000.00, Stok: 15, Kategori: Kebutuhan Sehari-hari <br> Nama: Beras 5kg, Harga: 60000.00, Stok: 10, Kategori: Bahan Makanan

> _Jalur dari root ke nama Sabun Mandi:_ <br><br> Supermarket -> Kebutuhan Sehari-hari -> Sabun Mandi ->   

> _Tinggi tree:_ 4

> _Sibling dari nama Sabun Mandi:_ <br><br> Nama: Shampoo, Harga: 25000.00, Stok: 15, Kategori: Kebutuhan Sehari-hari

> _Nodes dengan parent yang sama sebagai Sabun Mandi:_ <br><br> Sibling: Shampoo, Harga: 25000.00, Stok: 15, Kategori: Kebutuhan Sehari-hari
