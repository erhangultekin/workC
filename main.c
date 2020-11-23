#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *token;
    char ch;
    char toplayan[25]={'0'};
    FILE *fileR;
    int j=1;
    int l=0;
    int r=0;
    int s=0;
    int c=0;
    int boyut=0;
    int kontrol=0;
    char kelime[25]={'0'};
    printf("a.txt de aranacak olan kelimeyi giriniz :");
    scanf("%s",&kelime);

    if((fileR=fopen("a.txt","r+"))==NULL){
        printf("Dosya bulunamadi");
    }
    else{
        while((ch=fgetc(fileR))!=EOF){
              boyut++;
        }
        rewind(fileR);
        token=(char *)malloc(boyut*sizeof(char)); //DÝNAMÝK MEMORY
        while((ch=fgetc(fileR))!=EOF){
              token[j++]=ch;
        }
        token[0]=' '; //BASINA VE SONUNA ' ' ATTIM  IC ICE GECMIS KELIMELERI ENGELLEMEK ICIN ORNEK  (KATLANMAK=ATLANMAK) GIBI
        token[j++]=' ';
        for(l=0;l<strlen(token);l++){
            if((token[l]==kelime[0]) && (token[l-1]=='\0' || token[l-1]==' ')){ //KELIME ESITLIGI KONTROLU
                for(r=l;r<(strlen(kelime)+l);r++){
                    toplayan[s++]=token[r];
                    c=l+strlen(kelime);
            }
            s=0;
            if((strstr(kelime,toplayan)!=0) && (token[c]=='\0' || token[c]==' ')){ // ESITLIK TAM KONTROLU
                kontrol++;
                printf("%15s << Bulunan kelime\n",toplayan);
                printf("%15d << Bulunan kelimenin boyu\n",strlen(toplayan));
                printf("%15d << Kelimenin bulundugu ilk indeks\n",c-strlen(toplayan));
            }
        }
        }
        if (kontrol==0){
            printf("Bulunamadi");
        }
    }


    return 0;
}
