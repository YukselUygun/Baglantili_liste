#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// Baglantili liste icin dugum yapisi olusturuldu.
struct dugum {
    int veri;
    struct dugum* sonraki;
};

// Yeni bir dugum olusturuldu.
struct dugum* dugum_olustur(int veri) {
    struct dugum* yeniDugum = (struct dugum*) malloc(sizeof(struct dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

// Kuyruga eleman eklemek icin ekleme islemi tanimlandi.
void ekle(struct dugum** ilk, struct dugum** son, int veri) {
    struct dugum* yeniDugum = dugum_olustur(veri);
    if (*ilk == NULL) {
        *ilk = *son = yeniDugum;
    }
    else {
        (*son)->sonraki = yeniDugum;
        *son = yeniDugum;
    }
    printf("%d kuyruga eklendi.\n\n", veri);
}

// Kuyruktan eleman cikarmak icin cikarma iþlemi tanimlandi.
void cikar(struct dugum** ilk, struct dugum** son) {
    if (*ilk == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    struct dugum* temp = *ilk;
    *ilk = (*ilk)->sonraki;
    if (*ilk == NULL) {
        *son = NULL;
    }
    printf("%d kuyruktan cikarildi.\n", temp->veri);
    free(temp);
}

// Kuyruktaki elemanlari goruntulemek icin goruntuleme islemi tanimlandi.
void goruntuleme(struct dugum* ilk) {
    if (ilk == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    struct dugum* temp = ilk;
    printf("Kuyruktaki elemanlar:");
    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }
    printf("\n\n");
}
//Ýslemlerin secimi tanýmlandi ve dongu kuruldu.
int main() {
    struct dugum* ilk = NULL, *son = NULL;
    int secenekler, veri;
    while (1) {
        printf("1. Ekle\n");
        printf("2. Cikar\n");
        printf("3. Goruntule\n");
        printf("4. Cikis\n");
        printf("Secmek istediginiz islem: ");
        scanf("%d", &secenekler);
        switch (secenekler) {
            case 1:
                printf("Kuyruga eklemek istediginiz veri: ");
                scanf("%d", &veri);
                ekle(&ilk, &son, veri);
                break;
            case 2:
                cikar(&ilk, &son);
                break;
            case 3:
                goruntuleme(ilk);
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz islem...\n");
        }
    }
    return 0;
}

