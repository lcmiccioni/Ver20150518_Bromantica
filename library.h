#define N 5
#define MAX_NAMELEN 20
#define MAX_DESCRIPTIONLEN 50
#define FNAME1 "normale.csv"
#define FNAME2 "senzaglutine.csv"

struct s_ricetta {
    char nome[MAX_NAMELEN+1];
    char descrizione[MAX_DESCRIPTIONLEN+1];
    int pomodoro;
    int mozzarella;
    int glutine;
};

typedef struct s_ricetta ricetta;

void inputRicette(ricetta elencoRicette[], int dimensione);
void ordinaRicette(ricetta elencoRicette[], int dimensione);
void fileRicette(ricetta elencoRicette[], int dimensione);

void inputRicette(ricetta elencoRicette[], int dimensione) {
    int i;
    
    for(i=0;i<dimensione;i++) {
        printf("Ricetta %d\n", i+1);
        printf("Inserisci il nome: ");
        scanf("%s", elencoRicette[i].nome);
        
        printf("Inserisci la descrizione: ");
        scanf("%s", elencoRicette[i].descrizione);
        
        printf("Inserisci la quantita' di pomodoro: ");
        scanf("%d", &(elencoRicette[i].pomodoro));
        
        printf("Inserisci la quantita' di mozzarella: ");
        scanf("%d", &(elencoRicette[i].mozzarella));
        
        printf("Con glutine (0. no, qualsiasi altro valore. si)? ");
        scanf("%d", &(elencoRicette[i].glutine));
    }
}

void ordinaRicette(ricetta elencoRicette[], int dimensione) {
    int i, j;
    ricetta temp;
    
    //bubble sort
    for(i=0;i<dimensione-1;i++) {
        for(j=0;j<dimensione-i-1;j++) {
            if((strcmp(elencoRicette[j].nome, elencoRicette[j+1].nome)>0)) {
                temp = elencoRicette[j+1];
                elencoRicette[j+1] = elencoRicette[j];
                elencoRicette[j] = temp;
            }
        }
    }
}

void fileRicette(ricetta elencoRicette[], int dimensione) {
    int i;
    FILE *normale, *senzaglutine;
    
    normale = fopen(FNAME1, "w");
    senzaglutine = fopen(FNAME2, "w");
    
    if(normale==NULL || senzaglutine==NULL) {
        fprintf(stderr, "Impossibile creare il file");
        exit(1);
    }
    
    for(i=0;i<dimensione;i++) {
        if(elencoRicette[i].glutine==0) {
            fprintf(senzaglutine, "%s;%s;%d;%d;%d\n", 
                    elencoRicette[i].nome, 
                    elencoRicette[i].descrizione, 
                    elencoRicette[i].pomodoro, 
                    elencoRicette[i].mozzarella, 
                    elencoRicette[i].glutine);
        }else {
            fprintf(normale, "%s;%s;%d;%d;%d\n", 
                    elencoRicette[i].nome, 
                    elencoRicette[i].descrizione, 
                    elencoRicette[i].pomodoro, 
                    elencoRicette[i].mozzarella, 
                    elencoRicette[i].glutine);
        }
    }
    
    fclose(normale);
    fclose(senzaglutine);
}