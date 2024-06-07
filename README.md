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
<br>

![WhatsApp Image 2024-06-08 at 01 18 32_90811a5a](https://github.com/iniparhan/Tugas-Besar-Banget-Semester-2/assets/105894704/b4091d83-aea8-49b7-9619-86c8a5b0e8e4)

<br> _Output Code_ <br>

> _In-order Traversal:_ <br><br> Sabun Cuci Piring -> Dapur -> Spons -> Kebutuhan Sehari-hari -> Sabun Cair -> Sabun Mandi -> Sabun Batang -> Kamar Mandi -> Conditioner -> Vitamin Rambut -> Shampoo -> Supermarket -> Beras Putih -> Beras -> Beras Merah -> Bahan Makanan -> 500 gram -> Paha Ayam -> 1000 gram -> Ayam Seekor -> Dada Ayam -> Lauk -> Slice -> Wagyu -> Beef ->      

> _Pre-order Traversal:_ <br><br> Supermarket -> Kebutuhan Sehari-hari -> Dapur -> Sabun Cuci Piring -> Spons -> Kamar Mandi -> Sabun Mandi -> Sabun Cair -> Sabun Batang -> Vitamin Rambut -> Conditioner -> Shampoo -> Bahan Makanan -> Beras -> Beras Putih -> Beras Merah -> Lauk -> Ayam Seekor -> Paha Ayam -> 500 gram -> 1000 gram -> Dada Ayam -> Beef -> Wagyu -> Slice ->    

> _Post-order Traversal:_ <br><br> Sabun Cuci Piring -> Spons -> Dapur -> Sabun Cair -> Sabun Batang -> Sabun Mandi -> Conditioner -> Shampoo -> Vitamin Rambut -> Kamar Mandi -> Kebutuhan Sehari-hari -> Beras Putih -> Beras Merah -> Beras -> 500 gram -> 1000 gram -> Paha Ayam -> Dada Ayam -> Ayam Seekor -> Slice -> Wagyu -> Beef -> Lauk -> Bahan Makanan -> Supermarket ->

> _Data barang dengan harga 20000.00 atau lebih:_ <br><br> Nama: Beras Putih, Harga: 60000.00, Stok: 12, Kategori: Bahan Makanan<br>
Nama: Beras Merah, Harga: 70000.00, Stok: 15, Kategori: Bahan Makanan<br>
Nama: Ayam Seekor, Harga: 40000.00, Stok: 10, Kategori: Bahan Makanan<br>
Nama: Slice, Harga: 54000.00, Stok: 30, Kategori: Bahan Makanan<br>

> _Jalur dari root ke nama Sabun Cair:_ <br><br> Supermarket -> Kebutuhan Sehari-hari -> Kamar Mandi -> Sabun Mandi -> Sabun Cair ->

> _Tinggi tree:_ 6

> _Sibling dari nama Sabun Mandi:_ <br><br> Nama: Sabun Batang, Harga: 3000.00, Stok: 17, Kategori: kebutuhan Sehari-hari
