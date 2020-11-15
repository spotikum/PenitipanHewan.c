struct DataHewanIN;
struct HargaIn;
void Scandata(void);
int Inputdata(void);
void StrukIn(void);
void PrintStruk();
int Input();
struct DataHewanIN scanDataHewan;
struct DataHewanIN inDataHewan;
struct DataHewanIN hrgDataHewanin;
struct DataHewanIN tanggalAmbil;
struct HargaIn hrgInData;
int NextKode;

time_t rawtime;
struct tm*  time_;

struct DataHewanIN{
    char namaPemilik[MAX_NAME];
    char namaHewan[MAX_NAME];
    char rasHewan[MAX_NAME];
    char telepon[MAX_NAME];
    char namaPaket[MAX_NAME];
    char namaPegawai[MAX_NAME];
    char jenisJaminan[MAX_NAME];
    char noJaminan[MAX_NAME];
    short int jenis_jaminan;
    short int jenis_hewan;
    short int ras_hewan;
    short int kode_paket;
    int dp;
    int lama_titip;
    int kode;
    int menit;
    int jam;
    int hari;
    int bulan;
    int tahun;
};

struct HargaIn{
    int satuan_harga;
    int harga_total;
    int harga_bayar;
    int harga_kembalian;
};

void Scandata(void){
    FILE *log = fopen("file/log.txt","r");
    while(!feof(log)){
        fscanf(log,"%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%s", &scanDataHewan.kode, &scanDataHewan.namaPegawai, &scanDataHewan.namaPemilik, &scanDataHewan.namaHewan, &scanDataHewan.rasHewan, &scanDataHewan.namaPaket, 
        &scanDataHewan.jenis_hewan, &scanDataHewan.ras_hewan, &scanDataHewan.kode_paket, &scanDataHewan.menit, &scanDataHewan.jam, &scanDataHewan.hari, &scanDataHewan.bulan, &scanDataHewan.tahun, &scanDataHewan.lama_titip, &scanDataHewan.jenisJaminan, &scanDataHewan.noJaminan, &scanDataHewan.dp, &scanDataHewan.telepon);
    }
    NextKode = scanDataHewan.kode + 1;
    fclose(log);
}

int Inputdata(void){
    HeadUser();
	printf("\nNama Pemilik    : ");
	scanf(" %[^\n]s", inDataHewan.namaPemilik);
	
	HeadUser();
	printf("\n\t\t\t[1] Anjing \t[2] Kucing\n\n");
	printf("Jenis Hewan     : ");
	scanf("%d",&inDataHewan.jenis_hewan);
	if (inDataHewan.jenis_hewan == 1)
	{
		strcpy(inDataHewan.namaHewan, "Anjing");
		
		HeadUser();
		printf("\n\t\t[1] Small \t[2] Medium \t[3] Large \t[4] Giant\n\n");
		printf("Ras Hewan     : ");
		scanf("%d", &inDataHewan.ras_hewan);
		if (inDataHewan.ras_hewan == 1)
		{
			strcpy(inDataHewan.rasHewan, "Small");
		}else if (inDataHewan.ras_hewan == 2)
		{
			strcpy(inDataHewan.rasHewan, "Medium");
		}else if (inDataHewan.ras_hewan == 3)
		{
			strcpy(inDataHewan.rasHewan, "Large");
		}else if (inDataHewan.ras_hewan == 4)
		{
			strcpy(inDataHewan.rasHewan, "Giant");
		}
		
	}else if (inDataHewan.jenis_hewan == 2)
	{
		strcpy(inDataHewan.namaHewan, "Kucing");
		
		HeadText(); User();
		printf("\n\t\t[1] Small \t[2] Medium \t[3] Large \t[4] Giant\n\n");
		printf("Ras Hewan     : ");
		scanf("%d", &inDataHewan.ras_hewan);
		if (inDataHewan.ras_hewan == 1)
		{
			strcpy(inDataHewan.rasHewan, "Small");
		}else if (inDataHewan.ras_hewan == 2)
		{
			strcpy(inDataHewan.rasHewan, "Medium");
		}else if (inDataHewan.ras_hewan == 3)
		{
			strcpy(inDataHewan.rasHewan, "Large");
		}else if (inDataHewan.ras_hewan == 4)
		{
			strcpy(inDataHewan.rasHewan, "Giant");
		}
	}

    HeadUser();
    printf("\n\t\t\t[1] Standar \t[2] Spesial \t[3] Istimewa\n\n");
    printf("Paket Penitipan : ");
	scanf("%d",&inDataHewan.kode_paket);
    switch (inDataHewan.kode_paket)
    {
    case 1: strcpy(inDataHewan.namaPaket, "Standar");
        break;
    case 2: strcpy(inDataHewan.namaPaket, "Spesial");
        break;
    case 3: strcpy(inDataHewan.namaPaket, "Stimewa");
        break;
    }

    HeadUser();
    printf("\nTelepon         : ");
    scanf("%s", &inDataHewan.telepon);

    HeadUser();
    printf("\n\t\t\t[1] KTP \t[2] Paspor \n\n");
    printf("\nJaminan         : ");
    scanf("%d", &inDataHewan.jenis_jaminan);
    if (inDataHewan.jenis_jaminan == 1)
    {
        strcpy(inDataHewan.jenisJaminan, "KTP");
    }else if (inDataHewan.jenis_jaminan == 2)
    {
        strcpy(inDataHewan.jenisJaminan, "PAS");
    }else
    {
        printf("Input salah");
        printf("\n\n*Type any key to continue\n > ");
        scanf("%s", &input);
        return 1;
    }
    
    
    

    HeadUser();
    printf("\nNomor Jaminan %s : ", inDataHewan.jenisJaminan);
    scanf("%s", &inDataHewan.noJaminan);

    HeadUser();
    printf("\nLama Penitipan(hari) : ");
    scanf("%d", &inDataHewan.lama_titip);

    tanggalAmbil.hari = time_->tm_mday + inDataHewan.lama_titip;
    tanggalAmbil.bulan = time_->tm_mon+1;
    tanggalAmbil.tahun = time_->tm_year+1900;
    if (tanggalAmbil.hari > 30)
    {
        tanggalAmbil.hari -= 30;
        tanggalAmbil.bulan += 1;
        if (tanggalAmbil.bulan)
        {
            tanggalAmbil.bulan -= 12;
            tanggalAmbil.tahun += 1;
        }
    }

    FILE * log = fopen("file/harga.txt","r");
    while(!feof(log)){
        fscanf(log,"%d\t%d\t%d\t%d", &hrgDataHewanin.jenis_hewan, &hrgDataHewanin.ras_hewan, &hrgDataHewanin.kode_paket, &hrgInData.satuan_harga);
        if (inDataHewan.jenis_hewan == hrgDataHewanin.jenis_hewan)
        {
            if (inDataHewan.ras_hewan == hrgDataHewanin.ras_hewan)
            {
                if (inDataHewan.kode_paket == hrgDataHewanin.kode_paket)
                {
                    break;
                }
            }
        }
    }
    fclose(log);
    HeadUser();
    hrgInData.satuan_harga = (hrgInData.satuan_harga * inDataHewan.lama_titip) * 30/100;
    printf("\nUang Muka (DP)        : %d", hrgInData.satuan_harga);
    printf("\nUang yang dibayarkan  : ");
    scanf("%d", &hrgInData.harga_bayar);
    hrgInData.harga_kembalian = hrgInData.harga_bayar - hrgInData.satuan_harga;


    FILE *out = fopen("file/log.txt","a");
 	fprintf(out,"\n%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%s", NextKode, uName, inDataHewan.namaPemilik, 
        inDataHewan.namaHewan, inDataHewan.rasHewan, inDataHewan.namaPaket, inDataHewan.jenis_hewan, inDataHewan.ras_hewan, inDataHewan.kode_paket, 
        time_->tm_min, time_->tm_hour, time_->tm_mday, time_->tm_mon+1, time_->tm_year+1900, inDataHewan.lama_titip, inDataHewan.jenisJaminan, inDataHewan.noJaminan, hrgInData.satuan_harga, inDataHewan.telepon);
 	fclose(out);

    out = fopen("file/pending.txt","a");
 	fprintf(out,"%d\t%s\t%s\t%s\t%d-%d-%d\t%s\t%d\t%s\n", NextKode, inDataHewan.namaPemilik, inDataHewan.namaHewan, inDataHewan.rasHewan, tanggalAmbil.hari, tanggalAmbil.bulan, tanggalAmbil.tahun, inDataHewan.namaPaket, inDataHewan.lama_titip, inDataHewan.telepon);
 	fclose(out);

    StrukIn();
    PrintStruk();

    printf("\n\nLagi? [y/t] \n> ");
    scanf("%s",&input);
    switch (input){
    case 'y': return 1;
    default : return 9;
    }
}

void StrukIn(void){
    FILE * struk = fopen("struk.txt","w");
    fprintf(struk, "\n___________________________________________________________________________________");
    fprintf(struk, "\n");
    fprintf(struk, "\n                              Titip Hewan Kuy");
    fprintf(struk, "\n");
    fprintf(struk, "\n Jln. Kenangan Indah No.1 - Karangasem - Bali");
    fprintf(struk, "\n Hp/Wa 081337335678");
    fprintf(struk, "\n");
    fprintf(struk, "\n Kasir    : %s                                            %i:%i:%i %i-%i-%i\n", 
                    uName, time_->tm_hour, time_->tm_min, time_->tm_sec, time_->tm_mday, time_->tm_mon+1, time_->tm_year+1900);
    fprintf(struk, "\n___________________________________________________________________________________");
    fprintf(struk, "\n");
    fprintf(struk, "\nNama Pelanggan      : %s \t\t\tUang Muka (DP)      : Rp.%d", inDataHewan.namaPemilik, hrgInData.satuan_harga);
    fprintf(struk, "\nJenis Hewan         : %s \t\t\tUang yang dibayarkan: Rp.%d", inDataHewan.namaHewan, hrgInData.harga_bayar);
    fprintf(struk, "\nRas Hewan           : %s \t\t\tKembalian           : Rp.%d", inDataHewan.rasHewan, hrgInData.harga_kembalian);
    fprintf(struk, "\nPaket Penitipan     : %s", inDataHewan.namaPaket);
    fprintf(struk, "\nKode Penganbilan    : %d", NextKode);
    fprintf(struk, "\nWaktu Pengambilan   : %d-%d-%d", tanggalAmbil.hari, tanggalAmbil.bulan, tanggalAmbil.tahun);
    // fprintf(struk, "\nUang yang dibayarkan: %d", hrgInData.harga_bayar);
    // fprintf(struk, "\nKembalian           : %d", hrgInData.harga_kembalian);
    fprintf(struk, "\n");
    fprintf(struk, "\n___________________________________________________________________________________");
    fprintf(struk, "\n");
    fprintf(struk, "\n                    Pembayaran dilakukan saat menganbil hewan");
    fprintf(struk, "\n                                    Terimakasih :)");
    fprintf(struk, "\n");
    fprintf(struk, "\n___________________________________________________________________________________");
    fclose(struk);

}

void PrintStruk(){
    system("clear||clr");
    FILE * print_struk;
    char str[MAXCHAR];
    print_struk = fopen("struk.txt", "r");
    while ( fgets(str, MAXCHAR, print_struk))
        printf("%s", str);
    fclose(print_struk);
}

int Input(){
    time(&rawtime);
    time_ = localtime(&rawtime);

    Scandata();
    return Inputdata();
}