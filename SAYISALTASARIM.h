#ifndef _SAYISALTASARIM_H_
#define _SAYISALTASARIM_H_
#include<string.h>
#include <stdint.h>
#include<stdio.h>
#include<math.h>
#pragma pack(1)
struct sayisal_tasarim_cevirimler{
	public:
void tam_sayilarin_basamak_cevirimi(char sayi[20],int taban,int cevirilecek_taban);//sayi[20]  sayýmýzý yazdýðýmýz yer , taban = yazdýðýmýz yaban þu an hangi tabanda
void ondalikli_sayilarin_basamak_cevirimi(char sayi[20],int taban,int cevirilecek_taban,int vskb);//sayi[20]  sayýmýzý yazdýðýmýz yer , taban = yazdýðýmýz yaban þu an hangi tabanda , vskb = virgülden sonra kaç basamak olmasýný istiyorsunuz?
void BCD(const char* sayi);//10 luk tabandaki sayýyý BCD ye çevirirken kullanýlýr
void BCD_TO_DEC(char* sayi);//BCD tabandaki sayýyý 10 luða çevirirken kullanýlýr
void BIN_TO_GRAY(char* sayi);
void GRAY_TO_BIN(char* sayi);
void DEC_TO_EXCESS_3(const char* sayi);
void EXCESS_3_TO_DEC(char* sayi);
void BIN_R_TUMLEYENI(const char* sayi);
	private:
char digit_to_char(int sayi);
int char_to_digit(char sayi);

int pozitif_ust(int sayi,int ust);//sayýlarýn pozitif üstlerini almak için kullandýðýmýz fonksiyon
float negatif_ust(int sayi,int ust);//sayýlarýn negatif üstlerini almak için kullandýðýmýz fonksiyon

int int_dec_to(int sayi,int taban);//int türüne çevirdiðimiz sayý üzerinde iþlem yapmamýz için gerekli fonksiyon
float float_dec_to(float sayi,int cevirilecek_taban,int vskb);//float türüne çevirdiðimiz sayý üzerinde iþlem yapmamýz için gerekli fonksiyon

void DEC_TO_BCD_CONVERTER(char sayi);//10 tabanýndan sayýmýzý BCD ye çevirirken kullandýðýmýz ara fonksiyon!!!
void BCD_TO_DEC_CONVERTER(char* sayi);//BCD tabanýndan sayýmýzý 10 luk tabana çevirirken kullandýðýmýz ara fonksiyon!!!

void DEC_TO_EXCESS_3_CONVERTER(char sayi);
void EXCESS_3_TO_DEC_CONVERTER(char* sayi);

}basamak_cevirimi;

void sayisal_tasarim_cevirimler::tam_sayilarin_basamak_cevirimi(char sayi[20],int taban,int cevirilecek_taban){
	int uzunluk = strlen(sayi)-1,gecici = uzunluk,toplam=0;//,taban=2,istenilen_taban=16;
    for(;gecici>=0;gecici--){
    	toplam += char_to_digit(sayi[gecici])*pozitif_ust(taban,uzunluk - gecici);
	}
	int_dec_to(toplam,cevirilecek_taban);
	putchar('\n');
}

void sayisal_tasarim_cevirimler:: ondalikli_sayilarin_basamak_cevirimi(char sayi[20],int taban,int cevirilecek_taban,int vskb){
	int uzunluk = strlen(sayi)-1,gecici = 0;
    double toplam_virgulden_once=0.0,toplam_virgulden_sonra=0.0;
    
	char * p_ch;
    p_ch=strchr(sayi,'.');
    int noktanin_konumu = p_ch-sayi;//virgülün olduðu konum hesaplandý sonraki iþlemler buradaki sonuca göre yapýlacak
	
	for(gecici=noktanin_konumu-1 ;gecici >= 0; gecici--){//virgülden önceki kýsým double sayýya çevirildi
		toplam_virgulden_once += char_to_digit(sayi[gecici])*pozitif_ust(taban,noktanin_konumu-gecici-1);
	}
	if(p_ch != NULL){//Eðer  p_ch == NULL ise o dizide . iþareti yoktur 
	for(gecici=noktanin_konumu+1 ;gecici <= uzunluk; gecici++){//virgülden sonraki kýsým double sayýya çevirildi
		toplam_virgulden_sonra += char_to_digit(sayi[gecici])*negatif_ust(taban,-(gecici-noktanin_konumu));
	}
	}
	
	float_dec_to(toplam_virgulden_sonra+toplam_virgulden_once,cevirilecek_taban,vskb);
	putchar('\n');
}


void sayisal_tasarim_cevirimler::BCD(const char* sayi){
	int uzunluk = strlen(sayi);
	int gecici = 0;
	
	putchar('(');
	while((gecici) != (uzunluk)){
		
		DEC_TO_BCD_CONVERTER(sayi[gecici]);
		gecici++;
		if(gecici !=uzunluk )
		putchar(' ');
		
		
	}
	puts(")BCD\n");
}

void sayisal_tasarim_cevirimler::BCD_TO_DEC(char* sayi){
	char gecici_sayi[5]="----";
	int uzunluk = strlen(sayi);
	int gecici = 0,simdiki_dongu_sayisi=0,max_dongu_sayisi=uzunluk/4;
	
	//printf("uzunluk = %d\n",strlen(sayi));
	putchar('(');
	for(;simdiki_dongu_sayisi<max_dongu_sayisi;simdiki_dongu_sayisi++){
		gecici_sayi[0] = sayi[gecici + 0];
		gecici_sayi[1] = sayi[gecici + 1];
		gecici_sayi[2] = sayi[gecici + 2];
		gecici_sayi[3] = sayi[gecici + 3];
		gecici +=4; 
		BCD_TO_DEC_CONVERTER(gecici_sayi);
	}
	puts(")10\n");
	}
	
	void sayisal_tasarim_cevirimler::BIN_TO_GRAY(char* sayi){
	char gecici_karakter = '0';
	int uzunluk = strlen(sayi),gecici = 0;
	putchar('(');
	for(;gecici<uzunluk;gecici++){
		if(gecici_karakter !=sayi[gecici]){
		putchar('1');
		}
		else{
		putchar('0');
		}
		gecici_karakter =sayi[gecici];
		
	}
	puts(")GRAY");
}

void sayisal_tasarim_cevirimler::GRAY_TO_BIN(char* sayi){
	char* sayi2;
	char gecici_karakter = sayi[0];
	int uzunluk = strlen(sayi),gecici = 1;
	putchar('(');
	putchar(gecici_karakter);
	for(;gecici<uzunluk;gecici++){
		if(gecici_karakter !=sayi[gecici]){
		putchar('1'),
		gecici_karakter ='1';
		}
		else{
		putchar('0'),
		gecici_karakter ='0';
		}
	}
	puts(")BIN");
}

void sayisal_tasarim_cevirimler::DEC_TO_EXCESS_3(const char* sayi){
int uzunluk = strlen(sayi),gecici = 0;
putchar('(');
	for(;gecici<uzunluk;gecici++){
		DEC_TO_EXCESS_3_CONVERTER(sayi[gecici]);
		if(gecici != uzunluk-1)
		putchar(' ');
	}
puts(")+3");
}

void sayisal_tasarim_cevirimler::EXCESS_3_TO_DEC(char* sayi){
	char gecici_sayi[5]="----";
	int uzunluk = strlen(sayi);
	int gecici = 0,simdiki_dongu_sayisi=0,max_dongu_sayisi=uzunluk/4;
	
	//printf("uzunluk = %d\n",strlen(sayi));
	putchar('(');
	for(;simdiki_dongu_sayisi<max_dongu_sayisi;simdiki_dongu_sayisi++){
		gecici_sayi[0] = sayi[gecici + 0];
		gecici_sayi[1] = sayi[gecici + 1];
		gecici_sayi[2] = sayi[gecici + 2];
		gecici_sayi[3] = sayi[gecici + 3];
		gecici +=4; 
		//printf("gecici sayi = %s\n",gecici_sayi);
		//printf("geciici = %d\n",gecici);
		EXCESS_3_TO_DEC_CONVERTER(gecici_sayi);
	}
	puts(")10\n");
	}






char sayisal_tasarim_cevirimler::digit_to_char(int sayi){
	switch(sayi){
		case 0:{
			return '0';
		}
		
		case 1:{
			return '1';
		}
		
		case 2:{
			return '2';
		}
		
		case 3:{
			return '3';
		}
		
		case 4:{
			return '4';
		}
		
		case 5:{
			return '5';
		}
		
		case 6:{
			return '6';
		}
		
		case 7:{
			return '7';
		}
		
		case 8:{
			return '8';
		}
		
		case 9:{
			return '9';
		}
		
		case 10:{
			return 'A';
		}
		
		case 11:{
			return 'B';
		}
		case 12:{
			return 'C';
		}
		
		case 13:{
			return 'D';
		}
		
		case 14:{
			return 'E';
		}
		
		case 15:{
			return 'F';
		}
		
		default:{
			printf("gecersiz %c \n",sayi);	
			break;
		}
			
	}
}



int sayisal_tasarim_cevirimler::char_to_digit(char sayi){
	switch(sayi){
		case '0':{
			return 0;
		}
		
		case '1':{
			return 1;
		}
		
		case '2':{
			return 2;
		}
		
		case '3':{
			return 3;
		}
		
		case '4':{
			return 4;
		}
		
		case '5':{
			return 5;
		}
		
		case '6':{
			return 6;
		}
		
		case '7':{
			return 7;
		}
		
		case '8':{
			return 8;
		}
		
		case '9':{
			return 9;
		}
		
		case 'A':{
			return 10;
		}
		
		case 'B':{
			return 11;
		}
		case 'C':{
			return 12;
		}
		
		case 'D':{
			return 13;
		}
		
		case 'E':{
			return 14;
		}
		
		case 'F':{
			return 15;
		}
		
		case '.':{
			return 16;
			break;
		}
		
		default:{
			printf("gecersiz %d \n",sayi);	
			break;
		}
			
	}
}

int sayisal_tasarim_cevirimler::pozitif_ust(int sayi,int ust){
	int sonuc = 1;
	if(ust < 0)
		return -1;
	while(ust !=0){
		ust--;
		sonuc *=sayi;
	}
	return sonuc;
}

float sayisal_tasarim_cevirimler::negatif_ust(int sayi,int ust){
	float sonuc = 1.0;
	if(ust >0)
		return -1.0;
	while(ust !=0){
		ust++;
		sonuc *=(1.0/sayi);
	}
	return sonuc;
}

int sayisal_tasarim_cevirimler::int_dec_to(int sayi,int taban){
	if(taban >16)
		return -1;
	
char sayi_c[100];
int sayac=-1;
	while(sayi != 0){
	sayi_c[++sayac] = digit_to_char(sayi %taban);
	sayi /= taban;
	}
	
	printf("Sonuc = ");
	while(sayac !=-1){
		printf("%c",sayi_c[sayac]);
		sayac--;
	}
	
}
float sayisal_tasarim_cevirimler::float_dec_to(float sayi,int cevirilecek_taban,int vskb){
if(sayi>=1){
	int_dec_to((int)sayi,cevirilecek_taban);
}
else{
	putchar('0');
	
}
	putchar('.');

	sayi -=(int) sayi;
	int sayac = 0;
	while(sayi != 0 && sayac != vskb){		
		sayi *=cevirilecek_taban;
		putchar(sayi>=1?digit_to_char((int)sayi):'0');
		(sayi>=1)?sayi-=(int)sayi:sayi;
		sayac++;
	}
}

void sayisal_tasarim_cevirimler::DEC_TO_BCD_CONVERTER(char sayi){
	if(sayi == '0'){
		printf("0000");
	}
	else if(sayi == '1'){
		printf("0001");
	}
	else if(sayi == '2'){
		printf("0010");
	}
	else if(sayi == '3'){
		printf("0011");

	}
	else if(sayi == '4'){
		printf("0100");

	}
	else if(sayi == '5'){
		printf("0101");

	}
	else if(sayi == '6'){
		printf("0110");

	}
	else if(sayi == '7'){
		printf("0111");

	}
	else if(sayi == '8'){
		printf("1000");

	}
	else if(sayi == '9'){
		printf("1001");

	}
	else if(sayi == '.'){
		putchar('.');
	}
	else{
		printf("HATA");
	}
}


void sayisal_tasarim_cevirimler::BCD_TO_DEC_CONVERTER(char* sayi){
	//printf("saiiii = %s\n",sayi);
	//printf("sayi uzz2 = %d ",strlen(sayi));

	//sayi[0] == '' &&sayi[1] == '' &&sayi[2] == '' &&sayi[3] == ''
	//(sayi[0] == '' && sayi[1] == '' && sayi[2] == '' && sayi[3] == '')
	if(sayi[0] == '0' && sayi[1] == '0' && sayi[2] == '0' && sayi[3] == '0'){
		putchar('0');
	}
	else if(sayi[0] == '0' && sayi[1] == '0' && sayi[2] == '0' && sayi[3] == '1'){
		putchar('1');
	}
	else if(sayi[0] == '0' && sayi[1] == '0' && sayi[2] == '1' && sayi[3] == '0'){
		putchar('2');
	}
	else if(sayi[0] == '0' && sayi[1] == '0' && sayi[2] == '1' && sayi[3] == '1'){
		putchar('3');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '0' && sayi[3] == '0'){
		putchar('4');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '0' && sayi[3] == '1'){
		putchar('5');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '1' && sayi[3] == '0'){
		putchar('6');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '1' && sayi[3] == '1'){
		putchar('7');

	}
	else if(sayi[0] == '1' && sayi[1] == '0' && sayi[2] == '0' && sayi[3] == '0'){
		putchar('8');

	}
	else if(sayi[0] == '1' && sayi[1] == '0' && sayi[2] == '0' && sayi[3] == '1'){
		putchar('9');

	}
	else{
		printf("HATA");
	}
	
}

void sayisal_tasarim_cevirimler::DEC_TO_EXCESS_3_CONVERTER(char sayi){
	if(sayi == '0'){
		printf("0011");
	}
	else if(sayi == '1'){
		printf("0100");
	}
	else if(sayi == '2'){
		printf("0101");
	}
	else if(sayi == '3'){
		printf("0110");
	}
	else if(sayi == '4'){
		printf("0111");
	}
	else if(sayi == '5'){
		printf("1000");
	}
	else if(sayi == '6'){
		printf("1001");
	}
	else if(sayi == '7'){
		printf("1010");
	}
	else if(sayi == '8'){
		printf("1011");
	}
	else if(sayi == '9'){
		printf("1100");
	}
	else{
		printf("HATA");
	}
}

void sayisal_tasarim_cevirimler::EXCESS_3_TO_DEC_CONVERTER(char* sayi){


	if(sayi[0] == '0' && sayi[1] == '0' && sayi[2] == '1' && sayi[3] == '1'){
		putchar('0');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '0' && sayi[3] == '0'){
		putchar('1');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '0' && sayi[3] == '1'){
		putchar('2');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '1' && sayi[3] == '0'){
		putchar('3');

	}
	else if(sayi[0] == '0' && sayi[1] == '1' && sayi[2] == '1' && sayi[3] == '1'){
		putchar('4');

	}
	else if(sayi[0] == '1' && sayi[1] == '0' && sayi[2] == '0' && sayi[3] == '0'){
		putchar('5');

	}
	else if(sayi[0] == '1' && sayi[1] == '0' && sayi[2] == '0' && sayi[3] == '1'){
		putchar('6');

	}
	
	else if(sayi[0] == '1' && sayi[1] == '0' && sayi[2] == '1' && sayi[3] == '0'){
		putchar('7');
	}
	else if(sayi[0] == '1' && sayi[1] == '0' && sayi[2] == '1' && sayi[3] == '1'){
		putchar('8');
	}
	else if(sayi[0] == '1' && sayi[1] == '1' && sayi[2] == '0' && sayi[3] == '0'){
		putchar('9');
	}
	else{
		printf("HATA");
	}
	
}
void  sayisal_tasarim_cevirimler::BIN_R_TUMLEYENI(const char* sayi){
	puts("olmadi");
}



char digit_to_char(int sayi);
int int_dec_to(int sayi,int taban);

float float_dec_to(float sayi,int cevirilecek_taban,int vskb){
if(sayi>=1){
	int_dec_to((int)sayi,cevirilecek_taban);
}
else{
	putchar('0');
	
}
	putchar('.');

	sayi -=(int) sayi;
	int sayac = 0;
	while(sayi != 0 && sayac != vskb){		
		sayi *=cevirilecek_taban;
		putchar(sayi>=1?digit_to_char((int)sayi):'0');
		(sayi>=1)?sayi-=(int)sayi:sayi;
		sayac++;
	}
}
int int_dec_to(int sayi,int taban){
	if(taban >16)
		return -1;
	
char sayi_c[100];
int sayac=-1;
	while(sayi != 0){
	sayi_c[++sayac] = digit_to_char(sayi %taban);
	sayi /= taban;
	}
	
	while(sayac !=-1){
		printf("%c",sayi_c[sayac]);
		sayac--;
	}
	
}



char digit_to_char(int sayi){
	switch(sayi){
		case 0:{
			return '0';
		}
		
		case 1:{
			return '1';
		}
		
		case 2:{
			return '2';
		}
		
		case 3:{
			return '3';
		}
		
		case 4:{
			return '4';
		}
		
		case 5:{
			return '5';
		}
		
		case 6:{
			return '6';
		}
		
		case 7:{
			return '7';
		}
		
		case 8:{
			return '8';
		}
		
		case 9:{
			return '9';
		}
		
		case 10:{
			return 'A';
		}
		
		case 11:{
			return 'B';
		}
		case 12:{
			return 'C';
		}
		
		case 13:{
			return 'D';
		}
		
		case 14:{
			return 'E';
		}
		
		case 15:{
			return 'F';
		}
		
		default:{
			printf("gecersiz %c \n",sayi);	
			break;
		}
			
	}
}



int char_to_digit(char sayi){
	switch(sayi){
		case '0':{
			return 0;
		}
		
		case '1':{
			return 1;
		}
		
		case '2':{
			return 2;
		}
		
		case '3':{
			return 3;
		}
		
		case '4':{
			return 4;
		}
		
		case '5':{
			return 5;
		}
		
		case '6':{
			return 6;
		}
		
		case '7':{
			return 7;
		}
		
		case '8':{
			return 8;
		}
		
		case '9':{
			return 9;
		}
		
		case 'A':{
			return 10;
		}
		
		case 'B':{
			return 11;
		}
		case 'C':{
			return 12;
		}
		
		case 'D':{
			return 13;
		}
		
		case 'E':{
			return 14;
		}
		
		case 'F':{
			return 15;
		}
		
		case '.':{
			return 16;
			break;
		}
		
		default:{
			printf("gecersiz %d \n",sayi);	
			break;
		}
			
	}
}

double round(double var,int vskb)
{
    double value = (int)(var * pow(10,vskb) + .5);
    //printf("value = %f\n",value);
    return (double)value / pow(10,vskb);
}
double float_dec_to2(double sayi,int cevirilecek_taban, int vskb){
if(sayi>=1){
	int_dec_to((int)sayi,cevirilecek_taban);
}
else{
	putchar('0');
	
}
	putchar('.');

	sayi -=(int) sayi;
	sayi = round(sayi,vskb);
	int sayac = 0;
	while(sayi != 0 && sayac != vskb){		
		sayi *=cevirilecek_taban;
		putchar(sayi>=1?digit_to_char((int)sayi):'0');
		(sayi>=1)?sayi-=(int)sayi:sayi;
		sayac++;
	}
}

void tamsayinin_sayinin_r_tumleyeni(const char* sayi,int taban){//r tümleyeni = r^n - N, r = taban,n = uzunluk, N = tümleyeni alýncak sayý
	int n = strlen(sayi);
	int uzunluk = strlen(sayi)-1,gecici = uzunluk,toplam=0;//,taban=2,istenilen_taban=16;
    
	for(;gecici>=0;gecici--){
    	toplam += char_to_digit(sayi[gecici])*pow(taban,uzunluk - gecici);
	}
	
	toplam = (int)pow(taban,n) - toplam;
	
	char buff[50];
	itoa(toplam,buff,taban);
	
	printf("(%s)%d'nin r tumleyeni =  (%s)%d\n",sayi,taban,buff,taban);
}

void ondalikli_sayinin_r_tumleyeni(const char* sayi,int taban,int vskb){//r tümleyeni = r^n - N, r = taban,n = uzunluk, N = tümleyeni alýncak sayý
	int uzunluk = strlen(sayi)-1,gecici = 0,voksv = 0;//voksv == virgülden önce kaç sayý var ?
    double toplam_virgulden_once=0.0,toplam_virgulden_sonra=0.0;
    
	char * p_ch;
    p_ch=strchr(sayi,'.');
    int noktanin_konumu = p_ch-sayi;//virgülün olduðu konum hesaplandý sonraki iþlemler buradaki sonuca göre yapýlacak
	
	for(gecici=noktanin_konumu-1 ;gecici >= 0; gecici--){//virgülden önceki kýsým double sayýya çevirildi
		toplam_virgulden_once += char_to_digit(sayi[gecici])*pow(taban,noktanin_konumu-gecici-1);
		voksv++;
	}
	
	if(p_ch != NULL){//Eðer  p_ch == NULL ise o dizide . iþareti yoktur 
	for(gecici=noktanin_konumu+1 ;gecici <= uzunluk; gecici++){//virgülden sonraki kýsým double sayýya çevirildi
		toplam_virgulden_sonra += char_to_digit(sayi[gecici])*pow(taban,-(gecici-noktanin_konumu));
	}
	}
	
	if(toplam_virgulden_once == 0){
		voksv = 0;
	}
	double toplam = pow(taban,voksv)- (toplam_virgulden_once + toplam_virgulden_sonra);
	char buff[50];
	float_dec_to2(toplam,taban,vskb);
	}





void binary_tamsayilarin_r_tumleyeni_cikarma_yontemi(int32_t sayi1,int32_t sayi2){

	int8_t s2_uzunluk = 0;
	int8_t s2_first_one = 0 ,s1_first_one = 0;
	int8_t kontrol = 0;
	int32_t sonuc = sayi1-sayi2;

printf(" (");	
for(int i =31;i >= 0;i--){//sayi1 i ekrana yazdir
		
		if(kontrol == 1){
			printf("%d",(sayi1 & (1<<i)) ? 1 : 0);
			
		}
			
		if(kontrol == 0 && ((sayi1 & (1<<i)) ? 1 : 0) == 1){
			printf("%d",(sayi1 & (1<<i)) ? 1 : 0);kontrol = 1;s1_first_one = i;
		}
			
			
		
}

printf(")2\n+(");

int8_t sayi2_tumleyen = (~sayi2) + 1;
kontrol = 0;
for(int8_t i =31;i >= 0;i--){//sayi2 nin tümleyenini ekrana yazdýrýr ekrana yazdir
		if(kontrol == 1){
			printf("%d",(sayi2_tumleyen & (1<<i)) ? 1 : 0);
		}
			
		if(kontrol == 0 && ((sayi2 & (1<<i)) ? 1 : 0) == 1){
			printf("%d",(sayi2_tumleyen & (1<<i)) ? 1 : 0);kontrol = 1;s2_first_one = i;//printf("%d",((sayi1 & (1<<i)) ? 1 : 0));kontrol = 1;
		}
}

printf(")2\n ");
for(int8_t i = 0;i < 20;i++){//toplama iþaretinde iki sayiyi alt alta yazdýktan sonra bir çizgi var ya onu yazdýrýyor
	printf("-");
}
printf("\n (");
kontrol = 0;

for(int i =(s2_first_one>s1_first_one ? s2_first_one : s1_first_one);i >= 0;i--){//sonucu ekrana yazdir
		printf("%d",(sonuc & (1<<i)) ? 1 : 0);
		/*if(kontrol == 1){
			printf("%d",(sonuc & (1<<i)) ? 1 : 0);
		}
			
		if(kontrol == 0 && ((sonuc & (1<<i)) ? 1 : 0) == 1){
			printf("%d",(sonuc & (1<<i)) ? 1 : 0);kontrol = 1;//printf("%d",((sayi1 & (1<<i)) ? 1 : 0));kontrol = 1;
		}*/
			
			
		
}puts(")2\n");
if(sonuc>=0){
	printf(" elde = 1 oldugu icin sonuc pozitif olur unutma!!!\n");
}
else{//eðer bulunan sonucun eldesi sýfýra eþitse  buluýnan sonucun tekrar tümyeleni alýnýp ekrana yazddýrýlacak
		printf(" elde = 0 oldugu icin sonuc negatif olacak ve yukarda bulunan sonucun r tumleyeni alincak\n (");
		sonuc = (~sonuc)+1;
		kontrol = 0;
		for(int i =31;i >= 0;i--){//sayi1 i ekrana yazdir
		//printf("%d",(sonuc & (1<<i)) ? 1 : 0);
		
		if(kontrol == 1){
			printf("%d",(sonuc & (1<<i)) ? 1 : 0);
		}
			
		else if(kontrol == 0 && ((sonuc & (1<<i)) ? 1 : 0) == 1){
			printf("%d",(sonuc & (1<<i)) ? 1 : 0);kontrol = 1;
		}
			
		
	}puts(")2\n");
}
}

void tam_sayilarin_r_eksi_bir_tumleyeni(char sayi[20],int taban){

	int basamak_sayisi = strlen(sayi)-1,gecici = basamak_sayisi,toplam=0;//,taban=2,istenilen_taban=16;
    for(;gecici>=0;gecici--){
    	toplam += char_to_digit(sayi[gecici])*pow(taban,basamak_sayisi - gecici);
	}
	toplam = (int)pow(taban,basamak_sayisi+1) - toplam -1;
	printf("(%s)%d sayisinin %d tumleyeni = (",sayi,taban,taban-1);
	int_dec_to(toplam,taban);
	printf(")%d",taban);
	putchar('\n');

}

void ondalikli_sayilarin_r_eksi_bir_tumleyeni(char sayi[20],int taban,int vskb){
	int uzunluk = strlen(sayi)-1,gecici = 0;
    double toplam_virgulden_once=0.0,toplam_virgulden_sonra=0.0,tumleyen_sonucu = 0.0;
    
	char * p_ch;
    p_ch=strchr(sayi,'.');
    int noktanin_konumu = p_ch-sayi;//virgülün olduðu konum hesaplandý sonraki iþlemler buradaki sonuca göre yapýlacak
	for(gecici=noktanin_konumu-1 ;gecici >= 0; gecici--){//virgülden önceki kýsým double sayýya çevirildi
		toplam_virgulden_once += char_to_digit(sayi[gecici])*pow(taban,noktanin_konumu-gecici-1);
	}
	if(p_ch != NULL){//Eðer  p_ch == NULL ise o dizide . iþareti yoktur 
	for(gecici=noktanin_konumu+1 ;gecici <= uzunluk; gecici++){//virgülden sonraki kýsým double sayýya çevirildi
		toplam_virgulden_sonra += char_to_digit(sayi[gecici])*pow(taban,-(gecici-noktanin_konumu));
	}
	}
	if(toplam_virgulden_once<1){//eðer virgülden önceki sayý 0 ise (0.32 gibi düþün) o zaman noktanin_konumu = 0 yaparýzki yanlýþ iþlem sonucu çýkmasýn
 		noktanin_konumu = 0;//örnek verirsek 0.32 de 0 bir sayý kabul edilecek iþlem yapýlýrken 10^0-10^(-2)-0.32 olmasý gerekiyor 0 olarak kabul edilmeseydi 10^1-10^(-2)-0.32 olacaktý ve yanlýþ sonucu bulacaktýk.
	}
	tumleyen_sonucu = (pow(taban,noktanin_konumu)-pow(taban,-(uzunluk-noktanin_konumu)))-(toplam_virgulden_sonra+toplam_virgulden_once);
	printf("(%s)%d sayisinin %d tumleyeni = (",sayi,taban,taban-1);
	float_dec_to(tumleyen_sonucu,taban,vskb);
	printf(")%d",taban);
	putchar('\n');
}



#endif
