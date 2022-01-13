
/*NOM & PRENOM: HEDA TANKEU JOEL YVAN
 MATRICULE: 20V2006
 
 NOM & PRENOM: KUETCHE CHENDJOU JEAN BIENVENU
 MATRICULE:   20U2955                        	*/



#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

float s=0, m, p_adm, p_refu, p_ajou, MAX, moy;
long pos;
char charNcin[100], charChoix[100];
int i=0, nbre_total, inf, mat, chi, phy, bio, k, sa, a, l, mo, p, adm, lettre=0, refu, ajou, tot, j, d, trouve, n;
char rep;
char vouloir, L[100];
char texte[10000];
int ncin, choix;
float NOTES[100], t[100], dec, S1=12, S2=11.5, S3=11, h1, h2, h3, x1, x2, x3;
char nom[100], prenom[100], decision[100];
float age, INF, MAT, PHY, CHI, BIO;
float notes[100], s1;
char info[]="INFO", math[]="MATH",phys[]="PHYS",chim[]="CHIM", bios[]="BIOS";

struct candidat
{
    char NOM[100];
    char PRENOM[100];
    int NCIN;
    int AGE;
    float MOYENNE;
    char SERIEBACC[10];
    float NOTEMATH;
    float NOTEPHY;
    char CHOIX2[20];
    char CHOIX3[20];
    char DECISION[20];
};
struct candidat c, mon[1000], temps;

/*struct candidat_modifier
{
    char NOM_M[100];
    char PRENOM_M[100];
    int NCIN_M;
    int AGE_M;
    float MOYENNE_M;
    char SERIEBACC_M[10];
    float NOTEMATH_M;
    float NOTEPHY_M;
    char CHOIX2_M[20];
    char CHOIX3_M[20];
    char DECISION_M[20];
};
struct candidat_modifier cm;*/


/*void permut(float *g, float *h)
{
    tmp=*g;
    *g=*h;
    *h=tmp;
}*/

int saisir(void)
{
    //int sa;
    struct candidat c;
    FILE *CANDIDAT=fopen("candidat.txt", "a");
    FILE *BACC=fopen("bacc.txt", "a");
    FILE *CHOIX=fopen("choix.txt", "a");
    FILE *RESULTAT=fopen("resultat.txt","a");
    /*printf("Veuillez d'abord entrer le seuil S1: ");
    scanf("%f", &S1);
    h1=S1;
    x1=S1;
    printf("\n");
    printf("Veuillez aussi entrer le seuil S2: ");
    scanf("%f", &S2);
    h2=S2;
    x2=S2;
    printf("\n");
    printf("Veuillez enfin entrer le seuil S3: ");
    scanf("%f", &S3);
    h3=S3;
    x3=S3;*/
    int n, i, j;
    float NOTES[100], s, tab[100];
    if(!CANDIDAT)
    {
        printf("ERREUR:impossible d'ouvrir le fichier candidat: ");
        exit(-1);
    }
    do
    {
        system("cls");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SAISIE DES DONNEES ETUDIANT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("__________________________________________________________________________________________________________________________________\n\n");
        printf("entrer le numero de CIN du candidat: ");
        scanf("%d", &c.NCIN);
        printf("\n");
        printf("entrer le nom du candidat: ");
        scanf("%s", &c.NOM);
        printf("\n");
        printf("entrer le prenom du candidat: ");
        scanf("%s", &c.PRENOM);
        printf("\n");
        printf("entrer l'age du candidat: ");
        scanf("%d", &c.AGE);
        printf("\n");
        printf("entrer la moyenne au bacc obtenue par le candidat: ");
        scanf("%f", &c.MOYENNE);
        printf("\n");
        printf("entrer la serie du candidat: ");
        scanf("%s", &c.SERIEBACC);
        printf("\n");
        printf("entrer la note obtenu en maths au bacc par le candidat: ");
        scanf("%f", &c.NOTEMATH);
        printf("\n");
        printf("entrer la note obtenu en physique au bacc par le candidat: ");
        scanf("%f", &c.NOTEPHY);
        printf("\n");
        printf("entrer le second choix du candidat(MATH;PHYS;CHIM;BIO): ");
        scanf("%s", &c.CHOIX2);
        printf("\n");
        printf("entrer le troisieme choix du candidat(MATH;PHYS;CHIM;BIO): ");
        scanf("%s", &c.CHOIX3);
        printf("\n");
        if((c.MOYENNE >= S1)||(c.MOYENNE>=S2&&c.MOYENNE<=S1&&c.NOTEMATH>=S3&&c.NOTEPHY>=S3))
        {
            strcpy(c.DECISION,info);
        }
        else
        {
            strcpy(c.DECISION,c.CHOIX2);
        }
        fprintf(CANDIDAT,"%d ; %s ; %s ; %d\n",c.NCIN,c.NOM,c.PRENOM,c.AGE);
        fprintf(BACC,"%d ; %.2f ; %s ; %.2f ; %.2f\n",c.NCIN,c.MOYENNE,c.SERIEBACC,c.NOTEMATH,c.NOTEPHY);
        fprintf(CHOIX,"%d ; %s ; %s\n",c.NCIN,c.CHOIX2,c.CHOIX3);
        fprintf(RESULTAT,"%d ; %s ; %.2f ; %.2f ; %.2f ; %s\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY,c.DECISION);
        printf("\nvoulez vous continuer o/n: ");
        vouloir=getch();
    }while((vouloir!='n') && (vouloir!='N'));
    //return sa;
    fclose(RESULTAT);
    fclose(CANDIDAT);
    fclose(BACC);
    fclose(CHOIX);
    getch();
}

void ajouter()
{
    int sa;
    struct candidat c;
    FILE *CANDIDAT=fopen("candidat.txt", "a+");
    FILE *BACC=fopen("bacc.txt", "a+");
    FILE *CHOIX=fopen("choix.txt", "a+");
    FILE *RESULTAT=fopen("resultat.txt","a+");
    int n, i, j;
    float NOTES[100], s, tab[100];
    if(!CANDIDAT)
    {
        printf("ERREUR:impossible d'ouvrir le fichier concours: ");
        exit(-1);
    }
    system("cls");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ AJOUT D'UN ETUDIANT ++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("\n");
    printf("______________________________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("entrer le numero de CIN du candidat: ");
    scanf("%d", &c.NCIN);
    printf("\n");
    printf("entrer le nom du candidat: ");
    scanf("%s", &c.NOM);
    printf("\n");
    printf("entrer le prenom du candidat: ");
    scanf("%s", &c.PRENOM);
    printf("\n");
    printf("entrer l'age du candidat: ");
    scanf("%d", &c.AGE);
    printf("\n");
    printf("entrer la moyenne au bacc obtenue par le candidat: ");
    scanf("%f", &c.MOYENNE);
    printf("\n");
    printf("entrer la serie du candidat: ");
    scanf("%s", &c.SERIEBACC);
    printf("\n");
    printf("entrer la note obtenu en maths au bacc par le candidat: ");
    scanf("%f", &c.NOTEMATH);
    printf("\n");
    printf("entrer la note obtenu en physique au bacc par le candidat: ");
    scanf("%f", &c.NOTEPHY);
    printf("\n");
    printf("entrer le second choix du candidat: ");
    scanf("%s", &c.CHOIX2);
    printf("\n");
    printf("entrer le troisieme choix du candidat: ");
    scanf("%s", &c.CHOIX3);
    printf("\n");
    if((c.MOYENNE >=S1)||(c.MOYENNE>=S2&&c.MOYENNE<=S1&&c.NOTEMATH>=S3&&c.NOTEPHY>=S3))
    {
        strcpy(c.DECISION,info);
    }
    else
    {
        strcpy(c.DECISION,c.CHOIX2);
    }
    fprintf(CANDIDAT,"%d ; %s ; %s ; %d\n",c.NCIN,c.NOM,c.PRENOM,c.AGE);
    fprintf(BACC,"%d ; %.2f ; %s ; %.2f ; %.2f\n",c.NCIN,c.MOYENNE,c.SERIEBACC,c.NOTEMATH,c.NOTEPHY);
    fprintf(CHOIX,"%d ; %s ; %s\n",c.NCIN,c.CHOIX2,c.CHOIX3);
    fprintf(RESULTAT,"%d ; %s ; %.2f ; %.2f ; %.2f ; %s\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY,c.DECISION);
    fclose(CANDIDAT);
    fclose(BACC);
    fclose(CHOIX);
    fclose(RESULTAT);
    printf("\nOperation reussie.");
}

void supprimer(int ncin)
{
    int trouve=0;
    struct candidat c;
    i=0;
    j=0;
    system("cls");
    printf("----------------------------------------------------------------- SUPPRESSION D'UN CANDIDAT -----------------------------------------------------");
    printf("\n");
    printf("_________________________________________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("entrer le numero de CIN du candidat a supprimer: ");
    scanf("%d", &ncin);


    FILE *CANDIDAT=fopen("candidat.txt", "r");
    do
    {
        fscanf(CANDIDAT,"%d ; %s ; %s ; %d",&c.NCIN,c.NOM,c.PRENOM,&c.AGE);
        i++;
    }while(!feof(CANDIDAT));
    fclose(CANDIDAT);



    CANDIDAT=fopen("candidat.txt", "r");
    FILE *CANDIDAT1=fopen("candidat1.txt", "a");
    //do
    for(j=0;j<i-1;j++)
    {
        fscanf(CANDIDAT,"%d ; %s ; %s ; %d",&c.NCIN,c.NOM,c.PRENOM,&c.AGE);
        if(ncin!=c.NCIN)
        {
            fprintf(CANDIDAT1,"%d ; %s ; %s ; %d\n",c.NCIN,c.NOM,c.PRENOM,c.AGE);
        }
    }//while(!feof(CANDIDAT));
    fclose(CANDIDAT);
    fclose(CANDIDAT1);

    FILE *BACC=fopen("bacc.txt", "r");
    FILE *BACC1=fopen("bacc1.txt", "a");
    //do
    for(j=0;j<i-1;j++)
    {
        fscanf(BACC,"%d ; %f ; %s ; %f ; %f",&c.NCIN,&c.MOYENNE,c.SERIEBACC,&c.NOTEMATH,&c.NOTEPHY);
        if(ncin!=c.NCIN)
        {
            fprintf(BACC1,"%d ; %.2f ; %s ; %.2f ; %.2f\n",c.NCIN,c.MOYENNE,c.SERIEBACC,c.NOTEMATH,c.NOTEPHY);
        }
    }//while(!feof(BACC));
    fclose(BACC);
    fclose(BACC1);

    FILE *CHOIX=fopen("choix.txt", "r");
    FILE *CHOIX1=fopen("choix1.txt", "a");
    //do
    for(j=0;j<i-1;j++)
    {
        fscanf(CHOIX,"%d ; %s ; %s",&c.NCIN,c.CHOIX2,c.CHOIX3);
        if(ncin!=c.NCIN)
        {
            fprintf(CHOIX1,"%d ; %s ; %s\n",c.NCIN,c.CHOIX2,c.CHOIX3);
        }
    }//while(!feof(CHOIX));
    fclose(CHOIX);
    fclose(CHOIX1);

    FILE *RESULTAT=fopen("resultat.txt","r");
    FILE *RESULTAT1=fopen("resultat1.txt","a");
    //do
    for(j=0;j<i-1;j++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(ncin!=c.NCIN)
        {
            fprintf(RESULTAT1,"%d ; %s ; %.2f ; %.2f ; %.2f ; %s\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY,c.DECISION);
        }
    }//while(!feof(RESULTAT));
    fclose(RESULTAT);
    fclose(RESULTAT1);
    remove("candidat.txt");
    remove("bacc.txt");
    remove("choix.txt");
    remove("resultat.txt");
    rename("candidat1.txt", "candidat.txt");
    rename("bacc1.txt", "bacc.txt");
    rename("choix1.txt", "choix.txt");
    rename("resultat1.txt", "resultat.txt");
    printf("\n\n\tcandidat supprime avec succes");
    /*if(!trouve)
    {
        printf("\tCandidat non trouve.");
    }*/
    printf("\npresser une touche pour continuer");
    getch();
}

void modifier()
{
    struct candidat c;
    int trouve=0;
    long pos;
    char rep;
    system("cls");
    printf("entrer le numero de CIN du candidat a modifier: ");
    scanf("%d", &ncin);
    FILE *CANDIDAT=fopen("candidat.txt", "r");
    FILE *CANDIDAT1=fopen("candidat1.txt", "a");
    do
    {
        fscanf(CANDIDAT,"%d ; %s ; %s ; %d",&c.NCIN,c.NOM,c.PRENOM,&c.AGE);
        if(ncin!=c.NCIN)
        {
            fprintf(CANDIDAT1,"%d ; %s ; %s ; %d\n",c.NCIN,c.NOM,c.PRENOM,c.AGE);
        }
    }while(!feof(CANDIDAT));
    fclose(CANDIDAT);
    fclose(CANDIDAT1);

    FILE *BACC=fopen("bacc.txt", "r");
    FILE *BACC1=fopen("bacc1.txt", "a");
    do
    {
        fscanf(BACC,"%d ; %f ; %s ; %f ; %f",&c.NCIN,&c.MOYENNE,c.SERIEBACC,&c.NOTEMATH,&c.NOTEPHY);
        if(ncin!=c.NCIN)
        {
            fprintf(BACC1,"%d ; %.2f ; %s ; %.2f ; %.2f\n",c.NCIN,c.MOYENNE,c.SERIEBACC,c.NOTEMATH,c.NOTEPHY);
        }
    }while(!feof(BACC));
    fclose(BACC);
    fclose(BACC1);

    FILE *CHOIX=fopen("choix.txt", "r");
    FILE *CHOIX1=fopen("choix1.txt", "a");
    do
    {
        fscanf(CHOIX,"%d ; %s ; %s",&c.NCIN,c.CHOIX2,c.CHOIX3);
        if(ncin!=c.NCIN)
        {
            fprintf(CHOIX1,"%d ; %s ; %s\n",c.NCIN,c.CHOIX2,c.CHOIX3);
        }
        if(ncin==c.NCIN)
        {
            trouve=1;
        }
    }while(!feof(CHOIX));
    fclose(CHOIX);
    fclose(CHOIX1);

    FILE *RESULTAT=fopen("resultat.txt","r");
    FILE *RESULTAT1=fopen("resultat1.txt","a");
    do
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(ncin!=c.NCIN)
        {
            fprintf(RESULTAT1,"%d ; %s ; %.2f ; %.2f ; %.2f ; %s\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY,c.DECISION);
        }
    }while(!feof(RESULTAT));
    fclose(RESULTAT);
    fclose(RESULTAT1);
    CANDIDAT1=fopen("candidat1.txt", "a+");
    BACC1=fopen("bacc1.txt", "a+");
    CHOIX1=fopen("choix1.txt", "a+");
    RESULTAT1=fopen("resultat1.txt", "a+");
    printf("\n");
    printf("entrer le numero de CIN du candidat: ");
    scanf("%d", &c.NCIN);
    printf("\n");
    printf("entrer le nouveau nom du candidat: ");
    scanf("%s", &c.NOM);
    printf("\n");
    printf("entrer le nouveau prenom du candidat: ");
    scanf("%s", &c.PRENOM);
    printf("\n");
    printf("entrer le nouvel age du candidat: ");
    scanf("%d", &c.AGE);
    printf("\n");
    printf("entrer la moyenne au bacc obtenue par le candidat: ");
    scanf("%f", &c.MOYENNE);
    printf("\n");
    printf("entrer la serie du candidat: ");
    scanf("%s", &c.SERIEBACC);
    printf("\n");
    printf("entrer la note obtenu en maths au bacc par le candidat: ");
    scanf("%f", &c.NOTEMATH);
    printf("\n");
    printf("entrer la note obtenu en physique au bacc par le candidat: ");
    scanf("%f", &c.NOTEPHY);
    printf("\n");
    printf("entrer le second choix du candidat(MATH;PHYS;CHIM;BIOS): ");
    scanf("%s", &c.CHOIX2);
    printf("\n");
    printf("entrer le troisieme choix du candidat(MATH;PHYS;CHIM;BIOS): ");
    scanf("%s", &c.CHOIX3);
    printf("\n");
    if((c.MOYENNE >= S1)||(c.MOYENNE>=S2&&c.MOYENNE<=S1&&c.NOTEMATH>=S3&&c.NOTEPHY>=S3))
    {
        strcpy(c.DECISION,info);
    }
    else
    {
        strcpy(c.DECISION,c.CHOIX2);
    }
    fprintf(CANDIDAT1,"%d ; %s ; %s ; %d\n",c.NCIN,c.NOM,c.PRENOM,c.AGE);
    fprintf(BACC1,"%d ; %.2f ; %s ; %.2f ; %.2f\n",c.NCIN,c.MOYENNE,c.SERIEBACC,c.NOTEMATH,c.NOTEPHY);
    fprintf(CHOIX1,"%d ; %s ; %s\n",c.NCIN,c.CHOIX2,c.CHOIX3);
    fprintf(RESULTAT1,"%d ; %s ; %.2f ; %.2f ; %.2f ; %s\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY,c.DECISION);
    fclose(CANDIDAT1);
    fclose(BACC1);
    fclose(CHOIX1);
    fclose(RESULTAT1);
    remove("candidat.txt");
    remove("bacc.txt");
    remove("choix.txt");
    remove("resultat.txt");
    rename("candidat1.txt", "candidat.txt");
    rename("bacc1.txt", "bacc.txt");
    rename("choix1.txt", "choix.txt");
    rename("resultat1.txt", "resultat.txt");
    if(!trouve)
    {
        printf("\n\tCandidat non trouve.");
    }
    printf("presser une touche pour continuer");
    getch();
}

int admis()
{
    int trouve=0;
    struct candidat c;
    FILE *RESULTAT=fopen("resultat.txt","r");
    FILE *ADMIS=fopen("admis.txt","a");
    do
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, info)==0)
        {
            trouve=1;
            fprintf(ADMIS,"%d ; %s ; %.2f ; %.2f ; %.2f\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }while(!feof(RESULTAT));
    fclose(RESULTAT);
    fclose(ADMIS);
    printf("\n\t\tVotre fichier admis.txt a bien ete cree");
    return 1;
}

void selection()
{
    struct candidat c;
    n=0;
    FILE *RESULTAT=fopen("resultat.txt","r");
    do
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        n++;
    }while(!feof(RESULTAT));
    fclose(RESULTAT);

    RESULTAT=fopen("resultat.txt","r");
    FILE *MATH=fopen("math.txt", "a");
    FILE *PHYS=fopen("phys.txt", "a");
    FILE *CHIM=fopen("chim.txt", "a");
    FILE *BIOS=fopen("bios.txt", "a");
    for(i=1;i<n;i++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, math)==0)
        {
            fprintf(MATH,"%d ; %s ; %.2f ; %.2f ; %.2f\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
        if(strcmp(c.DECISION, phys)==0)
        {
            fprintf(PHYS,"%d ; %s ; %.2f ; %.2f ; %.2f\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
        if(strcmp(c.DECISION, chim)==0)
        {
            fprintf(CHIM,"%d ; %s ; %.2f ; %.2f ; %.2f\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
        if(strcmp(c.DECISION, bios)==0)
        {
            fprintf(BIOS,"%d ; %s ; %.2f ; %.2f ; %.2f\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }
    fclose(RESULTAT);
    fclose(MATH);
    fclose(PHYS);
    fclose(CHIM);
    fclose(BIOS);
}

void affiche_filiere()
{
    int i=0, j=0, k=0, l=0, m=0;
    int i1, j1, k1, l1, m1;
    n=0;
    struct candidat c;
    FILE *RESULTAT=fopen("resultat.txt", "r");
    do
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        n++;
    }while(!feof(RESULTAT));
    fclose(RESULTAT);
    RESULTAT=fopen("resultat.txt", "r");
    printf("\n\nliste des admis en INFO");
    for(i=1;i<n;i++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, info)==0)
        {
            printf("\nNCIN: %d\tNOM: %s\tMOYENNE: %.2f\tNOTEMATH: %.2f\tNOTEPHY: %.2f", c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }
    fclose(RESULTAT);
    RESULTAT=fopen("resultat.txt", "r");
    printf("\n\nliste des admis en MATH");
    for(i=1;i<n;i++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, math)==0)
        {
            printf("\nNCIN: %d\tNOM: %s\tMOYENNE: %.2f\tNOTEMATH: %.2f\tNOTEPHY: %.2f", c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }
    fclose(RESULTAT);
    RESULTAT=fopen("resultat.txt", "r");
    printf("\n\nliste des admis en PHYS");
    for(i=1;i<n;i++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, phys)==0)
        {
            printf("\nNCIN: %d\tNOM: %s\tMOYENNE: %.2f\tNOTEMATH: %.2f\tNOTEPHY: %.2f", c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }
    fclose(RESULTAT);
    RESULTAT=fopen("resultat.txt", "r");
    printf("\n\nliste des admis en CHIM");
    for(i=1;i<n;i++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, chim)==0)
        {
            printf("\nNCIN: %d\tNOM: %s\tMOYENNE: %.2f\tNOTEMATH: %.2f\tNOTEPHY: %.2f", c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }
    fclose(RESULTAT);
    RESULTAT=fopen("resultat.txt", "r");
    printf("\n\nliste des admis en BIOS");
    for(i=1;i<n;i++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, bios)==0)
        {
            printf("\nNCIN: %d\tNOM: %s\tMOYENNE: %.2f\tNOTEMATH: %.2f\tNOTEPHY: %.2f", c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }
    fclose(RESULTAT);
    printf("\n\n");
    printf("\npresser une touche pour continuer");
    getch();
}

int supprimer()
{
    struct candidat c;
    FILE *BACC=fopen("bacc.txt","r");
    FILE *CANDIDAT=fopen("candidat.txt", "r");
    FILE *CHOIX=fopen("choix.txt", "r");
    FILE *RESULTAT1=fopen("resultat1.txt", "a");

    do
    {
        fscanf(CANDIDAT,"%d ; %s ; %s ; %d",&c.NCIN,c.NOM,c.PRENOM,&c.AGE);
        fscanf(BACC,"%d ; %f ; %s ; %f ; %f",&c.NCIN,&c.MOYENNE,c.SERIEBACC,&c.NOTEMATH,&c.NOTEPHY);
        fscanf(CHOIX,"%d ; %s ; %s",&c.NCIN,c.CHOIX2,c.CHOIX3);
        if((c.MOYENNE >= S1)||(c.MOYENNE>=S2&&c.MOYENNE<=S1&&c.NOTEMATH>=S3&&c.NOTEPHY>=S3))
        {
            strcpy(c.DECISION,info);
        }
        else
        {
            strcpy(c.DECISION,c.CHOIX2);
        }
        fprintf(RESULTAT1,"%d ; %d ; %s ; %.2f ; %.2f ; %.2f ; %s\n",c.NCIN,c.AGE,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY,c.DECISION);
    }while((!feof(CANDIDAT))&&(!feof(BACC))&&(!feof(CHOIX)));
    fclose(RESULTAT1);
    fclose(CHOIX);
    fclose(BACC);
    fclose(CANDIDAT);

    RESULTAT1=fopen("resultat1.txt", "r");
    FILE *ADMIS=fopen("admis.txt", "r");
    FILE *ADMIS1=fopen("admis1.txt", "a");
    do
    {
        fscanf(RESULTAT1,"%d ; %d ; %s ; %f ; %f ; %f ; %s\n",&c.NCIN,&c.AGE,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(c.AGE<=20)
        {
            fprintf(ADMIS1,"%d ; %s ; %.2f ; %.2f ; %.2f\n",c.NCIN,c.NOM,c.MOYENNE,c.NOTEMATH,c.NOTEPHY);
        }
    }while(!feof(RESULTAT1));
    fclose(RESULTAT1);
    fclose(ADMIS);
    fclose(ADMIS1);
    remove("admis.txt");
    remove("resultat1");
    rename("admis1.txt", "admis.txt");
    return 1;
}

int statistiques(float dec)
{
    struct candidat c;
    int nbre_total=0;
    int inf=0;
    int mat=0;
    int phy=0;
    int chi=0;
    int bio=0;
    FILE *RESULTAT=fopen("resultat.txt","r");
    do
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        nbre_total++;
    }while(!feof(RESULTAT));
    fclose(RESULTAT);
    RESULTAT=fopen("resultat.txt","r");
    for(int i=1;i<nbre_total;i++)
    {
        fscanf(RESULTAT,"%d ; %s ; %f ; %f ; %f ; %s",&c.NCIN,c.NOM,&c.MOYENNE,&c.NOTEMATH,&c.NOTEPHY,c.DECISION);
        if(strcmp(c.DECISION, info)==0)
        {
            inf+=1;
        }
        if(strcmp(c.DECISION, math)==0)
        {
            mat+=1;
        }
        if(strcmp(c.DECISION, phys)==0)
        {
            phy+=1;
        }
        if(strcmp(c.DECISION, chim)==0)
        {
            chi+=1;
        }
        if(strcmp(c.DECISION, bios)==0)
        {
            bio+=1;
        }
    }
    nbre_total-=1;
    INF=(float)(inf)*100/(float)nbre_total;
    MAT=(float)(mat)*100/(float)nbre_total;
    PHY=(float)(phy)*100/(float)nbre_total;
    CHI=(float)(chi)*100/(float)nbre_total;
    BIO=(float)(bio)*100/(float)nbre_total;
    //CHI=100-INF-MAT-PHY-BIO;
    fclose(RESULTAT);
    printf("Pourcentage d'admis en INFO: %f", INF);
    printf("\nPourcentage d'admis en MATH: %f", MAT);
    printf("\nPourcentage d'admis en PHYS: %f", PHY);
    printf("\nPourcentage d'admis en CHIM: %f", CHI);
    printf("\nPourcentage d'admis en BIOS: %f", BIO);
    //return 0;
}


void menu()
{
    system("color C");
                                                                                  system("date");
    printf("\n\t   ____________________________________________________________________________________________________________");
    printf("\n\t  |                                                                                                           |");
    printf("\n\t  |  ***********************************************************************************************          |");
    printf("\n\t  |  **                                                                                           **          |");
    printf("\n\t  |  **  __  __      __  __ ___    __          _    __  __    __            _     _       ___ __  **          |");
    printf("\n\t  |  ** |__ |__ |   |__ |    |  | |  | |\\ |   | \\  |__ |__   |    /\\\  |\\ | | \\ | | \\   /\\  | |__  **  |");
    printf("\n\t  |  **  __||__ |__ |__ |__  |  | |__| | \\|   |__| |__  __|  |__ /--\\ | \\| |__|| |__| /--\\ |  __| **      |");
    printf("\n\t  |  **                                                                                           **          |");
    printf("\n\t  |  **                                                                                           **          |");
    printf("\n\t  |  ***********************************************************************************************          |");
    printf("\n\t  |                                                                                                           |");
    printf("\n\t  |  #################################BIENVENU DANS MON PROGRAMME###################################          |");
    printf("\n\t  |                                CHOIX:   MATH; PHYS; CHIM; BIO                                             |");                                  
    printf("\n\t  |                                                                                                           |");
    printf("\n\t  |  <1- Saisir les donnees des candidats                                                                     |");
    printf("\n\t  |  <2- Ajouter les donnees d'un candidat                                                                    |");
    printf("\n\t  |  <3- Modifier les donnees d'un candidat existant dans des fichiers                                        |");
    printf("\n\t  |  <4- Supprimer les donnees d'un candidat existant dans des fichiers                                       |");
    printf("\n\t  |  <5- Creer un fichier admis.txt comportant les donnees des candidats admis                                |");
    printf("\n\t  |  <6- Retourner le pourcentage des candidats admis par filiere                                             |");
    printf("\n\t  |  <7- Supprimer du fichier admis.txt les candidats ages de plus de 20 ans                                  |");
    printf("\n\t  |  <8- Afficher la liste des candidats par filiere                                                          |");
    printf("\n\t  |  <9- creer des fichiers pour chaque filiere                                                               |");
    printf("\n\t  |  <10- Quitter                                                                                             |");
    printf("\n\t  |___________________________________________________________________________________________________________|");
    printf(" \n\n");
    printf("__________________________________________________________________________________________________________________________");
}

void quitter()
{
    system("cls");
    printf("\n\t\tAU REVOIR !");
    printf("\n\n");
}

int main(){
    printf("\tS1 = %.2f\tS2 = %.2f\tS3 = %.2f",S1, S2, S3);
    printf("\n");
    system("time");
    system("color F0");
    menu();
    do
    {
        printf("\n\n\t\t Entrer votre choix: ");
        scanf("%s", &charChoix);
        choix=atoi(charChoix);
        printf("\n\n");
        switch(choix)
        {
        case 1:
            system("cls");
            saisir();
            break;
        case 2:
            system("cls");
            ajouter();
            break;
        case 3:
            system("cls");
            modifier();
            break;
        case 4:
            system("cls");
            supprimer(ncin);
            break;
        case 5:
            system("cls");
            admis();
            break;
        case 6:
            system("cls");
            statistiques(dec);
            break;
        case 7:
            system("cls");
            supprimer();
            break;
        case 8:
            system("cls");
            affiche_filiere();
            break;
        case 9:
            system("cls");
            selection();
            break;
        case 10:
            system("cls");
            quitter();
            break;
        default:
            system("cls");
            printf("\t\tvotre choix n'est pas valide\n");
            menu();
        }
    }while(choix!=10);
    return 0;
}


