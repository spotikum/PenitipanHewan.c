time_t rawtime;
struct tm*  time_;

struct DataHewanOUT;
struct Harga;
void StrukOut(void);
void PrintStruk(void);
void Write();
int InputKode(void);
int ViewData();
int Output(void);
struct DataHewanOUT outDataHewan;
struct DataHewanOUT hrgDataHewan;
struct DataHewanOUT scaningDataHewan;
struct Harga harga;
char inputKode[MAXCODE];
int banyak_data, banyak_dataLog;
int temp;
int i;

struct DataHewanOUT{
    char kode[MAX_NAME];
    char namaPemilik[MAX_NAME];
    char namaHewan[MAX_NAME];
    char rasHewan[MAX_NAME];
    char telepon[MAX_NAME];
    char namaPaket[MAX_NAME];
    char namaPegawai[MAX_NAME];
    char tanggal[MAX_NAME];
    char jenisJaminan[MAX_NAME];
    char noJaminan[MAX_NAME];
    int dp;
    int lama_titip;
    int jenis_hewan;
    int ras_hewan;
    int kode_paket;
    int menit;
    int jam;
    int hari;
    int bulan;
    int tahun;
};

struct Harga{
    int satuan_harga;
    int harga_total;
    int harga_bayar;
    int harga_kembalian;
};

int ViewData(){
    HeadUser();
    char tanggal[MAXCODE];
    FILE * scan;
    i = 0;
    scan = fopen("file/pending.txt","r");
    while (!feof(scan))
    {
        fscanf(scan,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s", &scaningDataHewan.kode, &scaningDataHewan.namaPegawai, &scaningDataHewan.namaHewan, &scaningDataHewan.rasHewan, &scaningDataHewan.tanggal, &scaningDataHewan.namaPaket, &scaningDataHewan.lama_titip, &scaningDataHewan.telepon);
        i++;
    }
    banyak_data = i-1;
 	fclose(scan);
    
    struct DataHewanOUT saveDataHewan[banyak_data];
    printf("\nKode\tPemilik\t\tJenis\tRas\t\tDiambil\t\tPaket\tTelepon\n");
    printf("-----------------------------------------------------------------------------------\n");
    scan = fopen("file/pending.txt","r");
    for (i = 0; i < banyak_data; i++)
    {
        fscanf(scan,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s", &saveDataHewan[i].kode, &saveDataHewan[i].namaPegawai, &saveDataHewan[i].namaHewan, &saveDataHewan[i].rasHewan, &saveDataHewan[i].tanggal, &saveDataHewan[i].namaPaket, &saveDataHewan[i].lama_titip, &saveDataHewan[i].telepon);
        printf("%s\t%s\t\t%s\t%s\t\t%s\t%s\t%s\n", saveDataHewan[i].kode, saveDataHewan[i].namaPegawai, saveDataHewan[i].namaHewan, saveDataHewan[i].rasHewan, saveDataHewan[i].tanggal, saveDataHewan[i].namaPaket, saveDataHewan[i].telepon);
    }
    fclose(scan);

    printf("\n\n*Type any key to continue\n > ");
    scanf("%s", &input);
    return 9;
}

int InputKode(){

    char kodesalah[MAXCODE] = {"q"};
    char viewkode[MAXCODE] = {"v"};

    printf("\nInput Kode : ");
    scanf("%s", &inputKode);

    if (strcmp(inputKode,kodesalah) == 0)
    {
        return 9;
    }
    if (strcmp(inputKode,viewkode) == 0)
    {
        ViewData();
        return 2;
    }
       

    FILE *log;
    log = fopen("file/log.txt","r");
    while(!feof(log)){
        fscanf(log,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%s", &outDataHewan.kode, &outDataHewan.namaPegawai, &outDataHewan.namaPemilik, &outDataHewan.namaHewan, &outDataHewan.rasHewan, &outDataHewan.namaPaket, 
        &outDataHewan.jenis_hewan, &outDataHewan.ras_hewan, &outDataHewan.kode_paket, &outDataHewan.menit, &outDataHewan.jam, &outDataHewan.hari, &outDataHewan.bulan, &outDataHewan.tahun, &outDataHewan.lama_titip, &outDataHewan.jenisJaminan, &outDataHewan.noJaminan, &outDataHewan.dp, &outDataHewan.telepon);
        if (strcmp(inputKode,outDataHewan.kode) == 0)
        {
            break;
        }
    }
    fclose(log);

    struct DataHewanOUT cek_kode;
    fopen("file/pending.txt","r");
    while (!feof(log))
    {
        fscanf(log,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s", &cek_kode.kode, &cek_kode.namaPegawai, &cek_kode.namaHewan, &cek_kode.rasHewan, &cek_kode.tanggal, &cek_kode.namaPaket, &cek_kode.lama_titip, &cek_kode.telepon);
        if (strcmp(inputKode,cek_kode.kode) == 0)
        {
            break;
        }
    }
    fclose(log);

    if (strcmp(inputKode,cek_kode.kode) != 0)
    {
        printf("\n\n*Incorrect code");
        printf("\n\n*Type any key to continue\n > ");
        scanf("%s", &input);
        return 9;
    }
    

    log = fopen("file/harga.txt","r");
    while(!feof(log)){
        fscanf(log,"%d\t%d\t%d\t%d", &hrgDataHewan.jenis_hewan, &hrgDataHewan.ras_hewan, &hrgDataHewan.kode_paket, &harga.satuan_harga);
        if (outDataHewan.jenis_hewan == hrgDataHewan.jenis_hewan)
        {
            if (outDataHewan.ras_hewan == hrgDataHewan.ras_hewan)
            {
                if (outDataHewan.kode_paket == hrgDataHewan.kode_paket)
                {
                    break;
                }
            }
        }
    }
    fclose(log);

    struct DataHewanOUT temp_harga;

    if (outDataHewan.bulan < time_->tm_mon+1){
        temp = time_->tm_mon+1 - outDataHewan.bulan;
        temp_harga.hari = (time_->tm_mday + 30) * temp;
    }else
    {
        temp_harga.hari = outDataHewan.hari;
    }
    
    harga.harga_total = (harga.satuan_harga * ((time_->tm_mday + 1) - temp_harga.hari) - outDataHewan.dp);

    HeadUser();
    struct DataHewanOUT saveDataHewan[banyak_data];
    int perpanjang_titip;
    printf("\nKode\tPemilik\tHewan\tRas\tPaket\tDiambil\t\tTelepon\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s", outDataHewan.kode, outDataHewan.namaPemilik, outDataHewan.namaHewan, outDataHewan.rasHewan, outDataHewan.namaPaket, cek_kode.tanggal, outDataHewan.telepon);
    printf("\n\n\nTotal Bayar           : Rp.%d", harga.harga_total);
    printf("\n\nLanjut ke pembayaran? [y/t/p]\n\n > ");
    scanf("%s",&input);
    if (input == 't')
    {
        return 9;
    }else if (input == 'p')
    {
        printf("Tambah berapa hari?\n\n > ");
        scanf("%d", &perpanjang_titip);
        FILE * perpanjang;

        struct DataHewanOUT perpanjangData;

        perpanjang = fopen("file/pending.txt","r");
        for (i = 0; i < banyak_data; i++)
        {
            fscanf(perpanjang,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s", &saveDataHewan[i].kode, &saveDataHewan[i].namaPegawai, &saveDataHewan[i].namaHewan, &saveDataHewan[i].rasHewan, &saveDataHewan[i].tanggal, &saveDataHewan[i].namaPaket, &saveDataHewan[i].lama_titip, &saveDataHewan[i].telepon);
            if (strcmp(inputKode,saveDataHewan[i].kode) == 0)
            {
                saveDataHewan[i].lama_titip += perpanjang_titip;
                perpanjangData.hari = outDataHewan.hari + saveDataHewan[i].lama_titip;
                perpanjangData.bulan = outDataHewan.bulan;
                perpanjangData.tahun = outDataHewan.tahun;
                if (perpanjangData.hari > 30)
                {
                    perpanjangData.hari -= 30;
                    perpanjangData.bulan += 1;
                    if (perpanjangData.bulan)
                    {
                        perpanjangData.bulan -= 12;
                        perpanjangData.tahun += 1;
                    }
                }

            }
            
        }
        fclose(perpanjang);

        perpanjang = fopen("file/pending.txt","w");
        for ( i = 0; i < banyak_data; i++)
        {
            if (strcmp(inputKode,saveDataHewan[i].kode) == 0)
            {
                fprintf(perpanjang, "%s\t%s\t%s\t%s\t%d-%d-%d\t%s\t%d\t%s\n", saveDataHewan[i].kode, saveDataHewan[i].namaPegawai, saveDataHewan[i].namaHewan, saveDataHewan[i].rasHewan, perpanjangData.hari, perpanjangData.bulan, perpanjangData.tahun, saveDataHewan[i].namaPaket, cek_kode.lama_titip + perpanjang_titip, saveDataHewan[i].telepon);
            }else
            {
                fprintf(perpanjang, "%s\t%s\t\t%s\t%s\t\t%s\t%s\t%d\t%s\n", saveDataHewan[i].kode, saveDataHewan[i].namaPegawai, saveDataHewan[i].namaHewan, saveDataHewan[i].rasHewan, saveDataHewan[i].tanggal, saveDataHewan[i].namaPaket, saveDataHewan[i].lama_titip, saveDataHewan[i].telepon);
            }
            
        }
        fclose(perpanjang);


        return 2;
    }
    
    
    printf("\n\nApakah Hewan dalam keadaan sehat? [y/t]\n\n > ");
    scanf("%s",&input);
    if (input == 'y')
    {
        HeadUser();
        printf("\nTotal Bayar           : %d", harga.harga_total);
        printf("\nUang yang dibayarkan  : ");
        scanf("%d", &harga.harga_bayar); harga.harga_kembalian = harga.harga_bayar - harga.harga_total;
        if (harga.harga_bayar == 0)
        {
            return 9;
        }
        Write();
        StrukOut();
    }
    else
    {
        printf("\n\nApakah Hewan masih bernafas? [y/t]\n\n > ");
        scanf("%s", &input);
        if (input == 'y')
        {
            HeadUser();
            printf("\nTotal Bayar Seharusnya    : %d", harga.harga_total);
            int asuransi = harga.harga_total/2;
            printf("\nTotal Bayar               : %d", asuransi);
            printf("\nUang yang dibayarkan      : ");
            scanf("%d", &harga.harga_bayar); harga.harga_kembalian = harga.harga_bayar - asuransi;
            if (harga.harga_bayar == 0)
            {
                return 9;
            }
            Write();
            StrukOut();
        }else
        {
            HeadUser();
            printf("\n\nMaaf");
            printf("\n\n(Berurusan dengan admin)");
            printf("\n*Type any key to continue\n > ");
            scanf("%s", &input);
            return 9;
        }
    }
    printf("\n\n*lagi? [y/t] \n> ");
    scanf("%s", &input);
    if (input == 'y')
    {
        return 2;
    }else
    {
        return 9;
    }
}

void Write(){
    FILE * scan = fopen("file/pending.txt","r");
    struct DataHewanOUT saveDataHewan[banyak_data];
    scan = fopen("file/pending.txt","r");
    for (int i = 0; i < banyak_data; i++)
    {
        fscanf(scan,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s", &saveDataHewan[i].kode, &saveDataHewan[i].namaPegawai, &saveDataHewan[i].namaHewan, &saveDataHewan[i].rasHewan, &saveDataHewan[i].tanggal, &saveDataHewan[i].namaPaket, &saveDataHewan[i].lama_titip, &saveDataHewan[i].telepon);
    }
    fclose(scan);

    printf("\nKode\tPemilik\t\tJenis\tRas\t\tTanggal\t\tPaket\tTelepon\n");
    printf("-----------------------------------------------------------------------------------\n");
    scan = fopen("file/pending.txt","w");
    for (int i = 0; i < banyak_data; i++)
    {
        if (strcmp(inputKode,saveDataHewan[i].kode) != 0)
        {
            fprintf(scan, "%s\t%s\t\t%s\t%s\t\t%s\t%s\t%d\t%s\n", saveDataHewan[i].kode, saveDataHewan[i].namaPegawai, saveDataHewan[i].namaHewan, saveDataHewan[i].rasHewan, saveDataHewan[i].tanggal, saveDataHewan[i].namaPaket, saveDataHewan[i].lama_titip, saveDataHewan[i].telepon);
        }
    }
    fclose(scan);
}

void StrukOut(void){
    FILE * struk = fopen("struk.txt","w");
    fprintf(struk, "\n___________________________________________________________________________________");
    fprintf(struk, "\n");
    fprintf(struk, "\n                                 Titip Hewan Kuy");
    fprintf(struk, "\n");
    fprintf(struk, "\n Jln. Kenangan Indah No.1 - Karangasem - Bali");
    fprintf(struk, "\n Hp/Wa 081337335678");
    fprintf(struk, "\n");
    fprintf(struk, "\n Kasir    : %s                                            %i:%i:%i %i-%i-%i", 
                    uName, time_->tm_hour, time_->tm_min, time_->tm_sec, time_->tm_mday, time_->tm_mon+1, time_->tm_year+1900);
    fprintf(struk, "\n___________________________________________________________________________________");
    fprintf(struk, "\n");
    fprintf(struk, "\n Nama Pelanggan      : %s\t\t\t Harga per hari    : Rp. %d", outDataHewan.namaPemilik, harga.satuan_harga);
    fprintf(struk, "\n Jenis Hewan         : %s\t\t\t Total             : Rp. %d", outDataHewan.namaHewan, harga.harga_total);
    fprintf(struk, "\n Ras Hewan           : %s\t\t\t Bayar             : Rp. %d", outDataHewan.rasHewan, harga.harga_bayar);
    fprintf(struk, "\n Paket Penitipan     : %s\t\t\t Kembalian         : Rp. %d", outDataHewan.namaPaket, harga.harga_kembalian);
    fprintf(struk, "\n Kode Penganbilan    : %s", outDataHewan.kode);
    fprintf(struk, "\n Penerima            : %s", outDataHewan.namaPegawai);
    fprintf(struk, "\n Diterima pada       : %d:%d %d-%d-%d", outDataHewan.jam, outDataHewan.menit, outDataHewan.hari, outDataHewan.bulan, outDataHewan.tahun);
    fprintf(struk, "\n Lama Penitipan      : %d Hari", (time_->tm_mday + 1) - outDataHewan.hari);
    fprintf(struk, "\n___________________________________________________________________________________");
    fprintf(struk, "\n");
    fprintf(struk, "\n                    Terimakasih telah menggunakan layanan kani");
    fprintf(struk, "\n                         Hewan tidak boleh dikembalikan :)");
    fprintf(struk, "\n___________________________________________________________________________________");
    fclose(struk);
    PrintStruk();
}

int Output(void){
    time(&rawtime);
    time_ = localtime(&rawtime);

    HeadUser();
    return InputKode();
}