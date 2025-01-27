#include <stdio.h>
#include <stdlib.h>
#define MAX_SIMULASI 100 // mendefinisikan suatu makro. hanya bisa mengelola 100 simulasi energi. untuk mempermudah apabila jumlah maksimumnya ingin diubah
// makro ini digunakan untuk menentukan ukuran maksimum array yang menyimpan hasil simulasi energi (float simulasiEnergiTerbarukan[MAX_SIMULASI]).
// Mengimpor file header standar untuk operasi input/output (stdio.h) dan alokasi memori dinamis (stdlib.h).

/*
1. Rowen Rodotua Harahap
2. Dimas Ananda Sutiardi
3. Isyana Trevia Pohaci
4. Muhammad Rey Kafaka Fadlan
*/

// POINTER ADALAH CARA MENGAKSES DAN MENGUBAH DATA DARI STRUCTURE yang berasal dari suatu function.

// Struktur untuk menyimpan data-model energi
struct ModelEnergi {
	 // ... (rumus-rumus energi terbarukan)
    float luasAreaAngin;
    float kecepatanAngin;
    float koefisienDaya;
    float produksiAngin;

    float luasPermukaanSelSurya;
    float efisiensiSelSurya;
    float intensitasSinarMatahari;
    float rasioKinerja;
    float produksiMatahari;

    float efisiensiHidro;
    float massaJenisAir;
    float percepatanGravitasi;
    float ketinggianJatuhAir;
    float debitAir;
    float dayaHidro;

    float luasPermukaanUap;
    float efisiensiUap;
    float temperaturUap;
    float massaJenisUap;
    float produksiUap;

    float penyimpananEnergi;
    float konsumsiEnergi;
    float konsumsiEnergiMatahari;
    float konsumsiEnergiAngin;
    float konsumsiEnergiHidro;
    float konsumsiEnergiUap;

    float simulasiEnergiTerbarukan[MAX_SIMULASI]; // simulasinya maksimal 100 dan bisa diganti pada makro diatas.Ini adalah array dalam struktur struct ModelEnergi. 
	//Array ini digunakan untuk menyimpan hasil simulasi energi terbarukan.
};

float *ptrSimulasiEnergi; /* Pointer untuk menyimpan hasil simulasi energi. ini juga disebut deklarasi variable global yang merupakan pointer ke float. 
Berfungsi untuk menyimpan hasil simulasi energi terbarukan dalam bentuk array*/
int nomorUrutSimulasi = 1; // inisialisasi Nomor urut simulasi
int nomorUrutData = 1; // inisialisasi Nomor urut data

void simulasiProduksiMatahari(struct ModelEnergi *model) { // deklarasi fungsi, yang menerima satu argumen, yaitu pointer model ke struktur modelenergi
/* menhitung energi matahari. 
memakai void karena fungsi ini bertujuan untuk melakukan operasi tanpa memberikan nilai kembali. 
fungsi ini menerima suatu pointer ke struktur ModelEnergi yang disebut model, menunjukkan bahwa parameter tersebut adalah sebuah
pointer ke struktur modelenergi. fungsi ini menerima alamat memori dari struktur Modelenergi, ini memungkinkan simulasiprodukmatahari 
untuk memodifikasi nilai dalam struktur modelenergi.*/

// ... (input luas permukaan sel surya, efisiensi sel surya, dll.)
    printf("\nMasukkan luas permukaan sel surya (m^2): ");
    /*saat program membaca input dari pengguna, pointer model akan menyimpan inputan pengguna ke variable luaspermukaanselsurya pada strutcture modelenergi.
Operator panah (->) digunakan untuk mengakses dan memodifikasi variabel-variabel yang ada dalam struktur melalui pointer. 
Dalam konteks fungsi-fungsi simulasi seperti simulasiProduksiMatahari, kita menggunakan pointer (model) untuk mengakses dan menyimpan nilai dalam struktur ModelEnergi. */
    scanf("%f", &model->luasPermukaanSelSurya);

    printf("Masukkan efisiensi sel surya (persen): ");
    scanf("%f", &model->efisiensiSelSurya);

    printf("Masukkan intensitas sinar matahari (jam): ");
    scanf("%f", &model->intensitasSinarMatahari);

    printf("Masukkan rasio kinerja (PR): ");
    
    scanf("%f", &model->rasioKinerja);
    
    /* rumus perhitungan produksi energi matahari */;
    model->produksiMatahari = model->luasPermukaanSelSurya * (model->efisiensiSelSurya / 100.0) * model->intensitasSinarMatahari * model->rasioKinerja;
    
    // Menampilkan hasil energi matahari ke layar
    printf("\nHasil Produksi Energi Matahari: %.2f KWh\n", model->produksiMatahari);
    
// Menyimpan hasil daya matahari ke dalam array simulasi energi
// Indeks dihitung dari nomor urut simulasi (nomorUrutSimulasi).
// Ini dilakukan agar nilai pada indeks tersebut dapat diakses dan diperbarui sesuai dengan nomor urut simulasi
    ptrSimulasiEnergi[nomorUrutSimulasi] += model->produksiMatahari;
/*menggambarkan penambahan nilai model->produksiMatahari ke dalam elemen array ptrSimulasiEnergi yang diindeks oleh nomorUrutSimulasi. 
Ini dilakukan untuk menyimpan dan mengakumulasi hasil simulasi energi terbarukan dari sumber matahari pada simulasi tertentu.*/
}
//dimas

void simulasiProduksiHidro(struct ModelEnergi *model) { //penjelasan mirip dengan yang matahari
    printf("\nMasukkan efisiensi sistem konversi energi hidro (persen): ");
    scanf("%f", &model->efisiensiHidro);

    printf("Masukkan massa jenis air (kg/m^3): ");
    scanf("%f", &model->massaJenisAir);

    printf("Masukkan percepatan gravitasi (m/s^2): ");
    scanf("%f", &model->percepatanGravitasi);

    printf("Masukkan ketinggian jatuh air (meter): ");
    scanf("%f", &model->ketinggianJatuhAir);

    printf("Masukkan debit air (m^3/s): ");
    scanf("%f", &model->debitAir);

    model->dayaHidro = model->efisiensiHidro * model->massaJenisAir * model->percepatanGravitasi * model->ketinggianJatuhAir * model->debitAir;

    printf("\nHasil Daya Hidro: %.2f Watt\n", model->dayaHidro);
    ptrSimulasiEnergi[nomorUrutSimulasi] += model->dayaHidro;
}

void simulasiProduksiAngin(struct ModelEnergi *model) {  //penjelasan mirip dengan yang matahari
    printf("\nMasukkan luas area yang terkena angin (m^2): ");
    scanf("%f", &model->luasAreaAngin);

    printf("Masukkan kecepatan angin (m/s): ");
    scanf("%f", &model->kecepatanAngin);

    printf("Masukkan koefisien daya (Cp): ");
    scanf("%f", &model->koefisienDaya);

    model->produksiAngin = 0.5 * model->luasAreaAngin * model->kecepatanAngin * model->kecepatanAngin * model->kecepatanAngin * model->koefisienDaya;

    printf("\nHasil Produksi Energi Angin: %.2f KWh\n", model->produksiAngin);
    ptrSimulasiEnergi[nomorUrutSimulasi] += model->produksiAngin;
}

void simulasiProduksiUap(struct ModelEnergi *model) { //penjelasan mirip dengan yang matahari
    printf("\nMasukkan luas permukaan sistem uap (m^2): ");
    scanf("%f", &model->luasPermukaanUap);

    printf("Masukkan efisiensi sistem uap (persen): ");
    scanf("%f", &model->efisiensiUap);

    printf("Masukkan temperatur uap (Celsius): ");
    scanf("%f", &model->temperaturUap);

    printf("Masukkan massa jenis uap (kg/m^3): ");
    scanf("%f", &model->massaJenisUap);

    model->produksiUap = model->luasPermukaanUap * (model->efisiensiUap / 100.0) * model->temperaturUap * model->massaJenisUap;

    printf("\nHasil Produksi Energi Uap: %.2f KWh\n", model->produksiUap);
    ptrSimulasiEnergi[nomorUrutSimulasi] += model->produksiUap;
}
//rowen

void optimalkanPemanfaatanEnergiTerbarukan(struct ModelEnergi *model) {
    // deklarisi variabel lokal
	float rasioSimpan = 0.75;
    float totalProduksiTerbarukan = 0; // digunakan untuk menhitung total produksi energi terbarukan dari hasil simulasi
    // menhitung total produksi energi terbarukan
    for (int i = 0; i < nomorUrutSimulasi; ++i) {
        totalProduksiTerbarukan += ptrSimulasiEnergi[i];
    } // menjumlahkan hasil simulasi energi terbarukan dalam array 'ptrSimulasienergi' ke dalam variabel 'totalproduksiterbarukan'
    // menhitung energi yang akan disimpan
    float energiSimpan = totalProduksiTerbarukan * rasioSimpan;
    //menambah energi yang akan disimpan ke dalam variabel penyimpananenergi dalam struktur model energi dengan poitner model.
    model->penyimpananEnergi += energiSimpan;
}

void simpanHasilEnergi(struct ModelEnergi *model) {
	// menhitung total energi terbarukan
    float totalEnergiTerbarukan = model->produksiMatahari + model->produksiAngin + model->dayaHidro + model->produksiUap;
    // menyimpan energi terbarukan jika ada
    if (totalEnergiTerbarukan > 0) {
        printf("\nDATA %d TERSIMPAN: ", nomorUrutData++);
        
        //menyimpan hasil produksi energi ke dalam penyimpanan energi dalam struktur model energi
        if (model->produksiMatahari > 0) {
            printf("Matahari, ");
            model->penyimpananEnergi += model->produksiMatahari; // akan dimakasukkan ke variabel penyimpanan energi pada structure
        }
        if (model->produksiAngin > 0) {
            printf("Angin, ");
            model->penyimpananEnergi += model->produksiAngin;// akan dimakasukkan ke variabel penyimpanan energi pada structure
        }
        if (model->dayaHidro > 0) {
            printf("Hidro, ");
            model->penyimpananEnergi += model->dayaHidro;// akan dimakasukkan ke variabel penyimpanan energi pada structure
        }
        if (model->produksiUap > 0) {
            printf("Uap, ");
            model->penyimpananEnergi += model->produksiUap;// akan dimakasukkan ke variabel penyimpanan energi pada structure
        }
        // menampilkan pesan udh disimpan
        printf("berhasil disimpan.\n");
    } else {
        printf("\nError: Tidak ada data energi yang dimasukkan. Harap masukkan data energi terlebih dahulu.\n"); // kalau gk ada error
    }
}
// buat masukin konsumsi energi saat nyimpen
void simulasiKonsumsiEnergi(struct ModelEnergi *model) {
    printf("\nMasukkan konsumsi energi (KWh): ");
    scanf("%f", &model->konsumsiEnergi);
}
// rey

// menampilkan hasil simulasi
void simulasiDistribusiEnergi(struct ModelEnergi *model) {
    float energiDidistribusikan = model->penyimpananEnergi / 4;
    printf("\nHasil Simulasi Energi Mikro (Data %d):\n", nomorUrutSimulasi);
    printf("Total Produksi Energi Terbarukan: %.2f KWh\n", model->produksiMatahari + model->produksiAngin + model->dayaHidro + model->produksiUap);
    printf("Energi Terbarukan yang Dioptimalkan dan Tersimpan: %.2f KWh\n", model->penyimpananEnergi);
    printf("Konsumsi Energi: %.2f KWh\n", model->konsumsiEnergi);
    printf("Distribusi Energi ke Setiap Sumber Energi Mikro: %.2f KWh per sumber energi mikro\n", energiDidistribusikan);
}
// menampilkan bantuan helppp
void tampilkanBantuan() {
    printf("\n*** BANTUAN ***\n");
    printf("Program ini adalah simulasi untuk menghitung produksi dan distribusi energi terbarukan.\n");
    printf("Pilih opsi yang sesuai dengan tugas yang ingin Anda lakukan.\n");
    printf("Opsi:\n");
    printf("1. Produksi Energi Matahari\n");
    printf("2. Produksi Energi Hidro\n");
    printf("3. Produksi Energi Angin\n");
    printf("4. Produksi Energi Uap\n");
    printf("5. Simpan Hasil Energi\n");
    printf("6. Keluar\n");
    printf("7. Simpan Hasil Energi\n");
    printf("8. Help (Tampilkan Bantuan)\n");
}
// menampilkan tabel
void tampilkanDataSimulasi(struct ModelEnergi *model) {
    float energiDidistribusikan = model->penyimpananEnergi / 4;
    printf("\nHasil Simulasi Energi Mikro (Data %d):\n", nomorUrutSimulasi++);
    printf("\nData Simulasi (Data %d):\n", nomorUrutSimulasi);
    printf("|------------------------------------------------------------------|\n");
    printf("| No | Sumber Energi  | Produksi (KWh) | Simpanan (KWh) | Konsumsi (KWh) | Distribusi (KWh) |\n");
    printf("|----|----------------|-----------------|-----------------|-----------------|------------------|\n");
    printf("| %-2d | Matahari       | %-15.2f | %-15.2f |                 |                 |\n", nomorUrutSimulasi, model->produksiMatahari, model->penyimpananEnergi);
    printf("| %-2d | Angin          | %-15.2f | %-15.2f |                 |                 |\n", nomorUrutSimulasi, model->produksiAngin, model->penyimpananEnergi);
    printf("| %-2d | Hidro          | %-15.2f | %-15.2f |                 |                 |\n", nomorUrutSimulasi, model->dayaHidro, model->penyimpananEnergi);
    printf("| %-2d | Uap            | %-15.2f | %-15.2f |                 |                 |\n", nomorUrutSimulasi, model->produksiUap, model->penyimpananEnergi);
    printf("|----|----------------|-----------------|-----------------|-----------------|------------------|\n");
    printf("| %-2d | Total Produksi | %-15.2f |                 |                 |                 |\n", nomorUrutSimulasi, model->produksiMatahari + model->produksiAngin + model->dayaHidro + model->produksiUap);
    printf("|----|----------------|-----------------|-----------------|-----------------|------------------|\n");
    printf("| %-2d | Simpanan Total |                 | %-15.2f |                 |                 |\n", nomorUrutSimulasi, model->penyimpananEnergi);
    printf("|----|----------------|-----------------|-----------------|-----------------|------------------|\n");
    printf("| %-2d | Konsumsi Energi|                 |                 | %-15.2f |                 |\n", nomorUrutSimulasi, model->konsumsiEnergi);
    printf("|----|----------------|-----------------|-----------------|-----------------|------------------|\n");
    printf("| %-2d | Energi Terbarukan yang Dioptimalkan dan Tersimpan | %-15.2f |                 |                 |\n", nomorUrutSimulasi, model->penyimpananEnergi);
    printf("|----|----------------|-----------------|-----------------|-----------------|------------------|\n");
    printf("| %-2d | Distribusi Energi ke Setiap Sumber Energi Mikro    |                 |                 |                 | %-15.2f |\n", nomorUrutSimulasi, energiDidistribusikan);
    printf("|------------------------------------------------------------------|\n");
}

int main() {
    int pilihan; // variabel untuk menyimpan pilihan pengguna
    struct ModelEnergi modelEnergi = {0}; // memastikan semua varibel dalam struktur memiliki nilai awal yang terdefinisi. memastikan variabel pada model energi memiliki nilaai awal yang konstan
    ptrSimulasiEnergi = (float *)malloc(MAX_SIMULASI * sizeof(float));// mengalokasikan memori dinamis untuk menyimpan hasil simulasi energi max simulasi
// Di dalam fungsi main(), dilakukan alokasi memori dinamis untuk array ptrSimulasiEnergi sehingga dapat menyimpan hasil simulasi energi dalam bentuk array
    do { // program berjalan trus trusan sampai pengguna memilih untuk keluar
    	printf("|*********************************************************|");
        printf("\n|Simulasi Produksi dan Distribusi Energi Terbarukan       |\n");
        printf("|1. Produksi Energi Matahari.                             |\n");
        printf("|2. Produksi Energi Hidro.                                |\n");
        printf("|3. Produksi Energi Angin.                                |\n");
        printf("|4. Produksi Energi Uap.                                  |\n");
        printf("|5. Simpan Hasil Energi.                                  |\n");
        printf("|6. Simulasi Energi Mikro.                                |\n");
        printf("|7. Help (Tampilkan Bantuan).                             |\n");
        printf("|8. Tampilkan Data Simulasi.                              |\n");
        printf("|9. Keluar dari Program.                                  |\n");
        printf("|*********************************************************|\n");

        // Menentukan pilihan
        printf("Masukkan nomor pilihan (9 untuk keluar): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                simulasiProduksiMatahari(&modelEnergi);
                break;
            case 2:
                simulasiProduksiHidro(&modelEnergi);
                break;
            case 3:
                simulasiProduksiAngin(&modelEnergi);
                break;
            case 4:
                simulasiProduksiUap(&modelEnergi);
                break;
            case 5:
                simpanHasilEnergi(&modelEnergi);
                simulasiKonsumsiEnergi(&modelEnergi);
                break;
            case 6:
                if (modelEnergi.penyimpananEnergi > 0) {
                    optimalkanPemanfaatanEnergiTerbarukan(&modelEnergi);
                    simulasiDistribusiEnergi(&modelEnergi);
                } else {
                    printf("\nERROR: Tidak ada data energi yang disimpan. Harap masukkan data energi terlebih dahulu.\n");
                }
                break;
            case 7:
                tampilkanBantuan();
                break;
            case 8:
                tampilkanDataSimulasi(&modelEnergi);
                break;
            case 9:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Error: Nomor operasi tidak valid.\n");
        }

    } while (pilihan != 9);

    free(ptrSimulasiEnergi);  // Dealokasi memori yang dialokasikan, mencegah memory leaks.
    return 0;
    //isyana
}
