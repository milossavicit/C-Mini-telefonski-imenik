#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char ime[50];
    char prezime[50];
    char mestoStanovanja[50];
    char adresa[20];
    char brojTelefona[25];
} Imenik;

Imenik A[200];
char *Ime = (char*)malloc(sizeof(char)*50);  //Dinamičko alociranje memorije.
char *Prezime = (char*)malloc(sizeof(char)*50);
void Ucitaj();
void Sacuvaj();
void Pretraga();
void Obrisi();
void Azuriraj();
void Dodaj();
void Prikazi();
void Sortiranje();
void Meni();

FILE *p; //Pokazivač na fajl. Koji se koristi u funkcijama Ucitaj() i Sacuvaj().
int brojac=0;

 int main()
{
    
    Ucitaj(); //Fajl se učitava na samom startu programa.
    int izbor;
    Meni();
    while (1)
    {
    printf("-> "); scanf("%d", &izbor);
    //Uz pomoć switch naredbe se biraju opcije.
    switch(izbor)
    {
    case 1:
        Dodaj();
        break ;
    case 2:
        Prikazi();
        break ;
    case 3:
        Azuriraj();
        break ;
    case 4:
        Pretraga();
        break ;
    case 5:
        Obrisi();
        break ;
    case 6:
        Sortiranje();
        break ;
    case 7:
        Sacuvaj();
        break;
    case 8:
        printf("Program se zatvara...\n");
        exit(0);
        break;
    default :
        printf("Pogrešan unos, pokušajte ponovo.\n");
    }
  }
    free(Prezime); //Oslobađanje dinamički alocirane memorije.
    free(Ime);
    return 0;
}
 
 void Meni(){
    printf("   TELEFONSKI IMENIK   \n");
    printf("|-------- Meni -------|\n");
    printf("|1. Unesi novi kontakt|\n");
    printf("|2. Prikaži sve unose |\n");
    printf("|3. Izmeni kontakt    |\n");
    printf("|4. Pretraga imenika  |           Napomena: Nakon načinjenih izmena odabrati opciju 7 za trajno čuvanje!\n");
    printf("|5. Brisanje kontakta |\n");
    printf("|6. Sortiraj          |\n");
    printf("|7. Sačuvaj           |\n");
    printf("|8. Izlaz             |\n");
    printf("|---------------------|\n");
 }

void Ucitaj()
{
        p=fopen("imenik.txt","r"); //Ime fajla koji se nalazi u direktorijumu projekta.
        if(p==0)
        {
            printf("Fajl nije pronađen.\n");
        }
        else{
            while(!feof(p)){
            //Učitavanje u niz odnosno strukturu.
            fscanf(p,"%s %s %s %s %s",A[brojac].ime,A[brojac].prezime,
            A[brojac].mestoStanovanja,A[brojac].adresa,A[brojac].brojTelefona);
            brojac++;
        }
            printf("Fajl je uspešno učitan!\n");
    }
        fclose(p);
}
void Dodaj()
{
    printf("Ime: ");
    scanf("%s",A[brojac].ime);
    printf("Prezime: ");
    scanf("%s",A[brojac].prezime);
    printf("Mesto stanovanja: ");
    scanf("%s",A[brojac].mestoStanovanja);
    printf("Adresa: ");
    scanf("%s",A[brojac].adresa);
    printf("Br. telefona: ");
    scanf("%s",A[brojac].brojTelefona);
    brojac++;
    printf("Kontakt je uspešno unet.\n");
    Meni();
}

void Sacuvaj()
{
    int j=0;
    p=fopen("imenik.txt","w");
    for(j=0; j<brojac; j++)
    {
        //Upisivanje u fajl.
        fprintf(p,"%s %s %s %s %s\n",A[j].ime,A[j].prezime,
        A[j].mestoStanovanja,A[j].adresa,A[j].brojTelefona);
    }
    fclose(p);
    printf("Uspešno sačuvano!\n");
    Meni();
}

void Azuriraj()
{

    int i,v=0;
    int a[100];
    printf("Unesite prezime: ");
    scanf("%s",Prezime);
    for(i=0; i<=brojac; i++)
    {
        if(strcmp(Prezime,A[i].prezime)==0) //Funkcija za poređenje stringova.
        {
            v++;
            a[v]=i;
            printf("\n%d.Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",v,A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
        }
    }
    if(v==0)
        printf("Kontakt nije pronađen.\n") ;
    else
    {
        printf("\n");
        printf("Odaberite kontakt za ažuriranje: ");
        scanf("%d",&v);
        printf("\n");
        printf("Ime: ");
        scanf("%s",A[a[v]].ime);
        printf("Prezime: ");
        scanf("%s",A[a[v]].prezime);
        printf("Mesto stanovanja: ");
        scanf("%s",A[a[v]].mestoStanovanja);
        printf("Adresa: ");
        scanf("%s",A[a[v]].adresa);
        printf("Br. telefona: ");
        scanf("%s",A[a[v]].brojTelefona);
        printf("\n");
        printf("Kontakt je uspešno ažuriran.\n");
    }
    
    Meni();
}
void Obrisi()
{
    int i,v=0;
    int a[200];
    printf("Unesite prezime: ");
    scanf("%s",Prezime);
    
    for(i=0; i<=brojac; i++)
    {
        if(strcmp(Prezime,A[i].prezime)==0)
        {
            v++;
            a[v]=i;
            printf("\n%d.Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",v,A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
        }
    }
    if(v==0)
        printf("Kontakt nije pronađen.\n") ;
    else
    {

        printf("Odaberite kontakt za brisanje: \n");
        scanf("%d",&v);
        printf("\n");
        strcpy(A[a[v]].ime,A[brojac-1].ime); //Funkcija za kopiranje stringova.
        strcpy(A[a[v]].prezime,A[brojac-1].prezime);
        strcpy(A[a[v]].mestoStanovanja,A[brojac-1].mestoStanovanja);
        strcpy(A[a[v]].adresa,A[brojac-1].adresa);
        strcpy(A[a[v]].brojTelefona,A[brojac-1].brojTelefona);
        brojac--;
        printf("Kontakt je uspešno obrisan.\n");
    }

    Meni();
}
void Pretraga()
{
    int k=0,i=0;
    char telefon[30];
    char adresa[30];
    char mestoStanovanja[30];
    int izbor;
    printf("Pretraga po:\n");
    printf("1.Imenu\n2.Prezimenu\n3.Mestu stanovanja\n4.Adresi\n5.Broju telefona\n");
    printf("-> ");
    scanf("%d", &izbor);
    //Nakon odabira po kom kriterijumu se pretražuje vrši se provera jednakosti stringa i ispisivanje.
    switch(izbor)
    {
    case 1:
        printf("Ime: ");
        scanf("%s",Ime);
        printf("\n");
        while(i<=brojac)
        {
            if(strcmp(Ime,A[i].ime)==0)
                {printf("Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
            k++;}i++;
        }
        break;
    case 2:
        printf("Prezime: ");
        scanf("%s",Prezime);
        printf("\n");
        while(i<=brojac)
        {
            if(strcmp(Prezime,A[i].prezime)==0)
                               {printf("Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
            k++;}i++;
        }
        break;
    case 3:
        printf("Mesto stanovanja: ");
        scanf("%s",mestoStanovanja);
        printf("\n");
        while(i<=brojac)
        {
            if(strcmp(mestoStanovanja,A[i].mestoStanovanja)==0)
                               {printf("Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
            k++;}i++;
        }
        break;
    case 4:
        printf("Adresa: ");
        scanf("%s",adresa);
        printf("\n");
        while(i<=brojac)
        {
            if(strcmp(adresa,A[i].adresa)==0)
                                {printf("Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
            k++;}i++;
        }
        break;
    case 5:
        printf("Br. telefona: ");
        scanf("%s",telefon);
        printf("\n");
        while(i<=brojac)
        {
            if(strcmp(telefon,A[i].brojTelefona)==0)
                               {printf("Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
            k++;}i++;
        }
        break;
    default :
        printf("Pogrešan unos, pokušajte ponovo.\n");
        Pretraga();
    }
    if(k==0)
        printf("Kontakt nije pronađen.\n");
        Meni();
}

void Prikazi()
{
    int i=1;

    for (i = 0; i <= brojac-2; i++)
    {
        printf("Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",A[i].ime,A[i].prezime,A[i].mestoStanovanja,A[i].adresa,A[i].brojTelefona);
    }

        Meni();
}

void Sortiranje()
{
    //Sortiranje se vrši po prezimenu.
    int j=1,i=0;
    Imenik p;
    for (i=0; i<=brojac-1; i++)
    {
        for (j=i+1; j<brojac; j++)
            if (strcmp(A[i].prezime, A[j].prezime)>0)
            {
                strcpy(p.prezime, A[i].prezime);
                strcpy(A[i].prezime, A[j].prezime);
                strcpy(A[j].prezime, p.prezime);

                strcpy(p.ime, A[i].ime);
                strcpy(A[i].ime, A[j].ime);
                strcpy(A[j].ime, p.ime);

                strcpy(p.adresa, A[i].adresa);
                strcpy(A[i].adresa, A[j].adresa);
                strcpy(A[j].adresa, p.adresa);

                strcpy(p.mestoStanovanja, A[i].mestoStanovanja);
                strcpy(A[i].mestoStanovanja, A[j].mestoStanovanja);
                strcpy(A[j].mestoStanovanja, p.mestoStanovanja);

                strcpy(p.brojTelefona, A[i].brojTelefona);
                strcpy(A[i].brojTelefona, A[j].brojTelefona);
                strcpy(A[j].brojTelefona, p.brojTelefona);
            }
    }
    for (j = 1; j < brojac; j++)
    {
        printf("Ime: %s Prezime: %s Mesto stanovanja: %s Adresa: %s Br. telefona: %s\n",A[j].ime,A[j].prezime,A[j].mestoStanovanja,A[j].adresa,A[j].brojTelefona);
    }

        Meni();
}