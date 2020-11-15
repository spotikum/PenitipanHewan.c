#define MAXCHAR 1000
#define MAX_NAME 20
#define MAX_UNAME 15
#define MAX_UPASS 8
#define MAXCODE 15

struct Account;
void HeadUser(void);
void HeadText(void);
void User(void);
int GuideText(void);
int Guide(void);
int Head(void);
int Head1(void);
int Head2(void);
int Login(void);
char input;
char uName[MAX_UNAME];
char uType[MAX_NAME];
char quit[MAXCODE] = {"q"};
short int type_user;

struct Account {
    char name[MAX_UNAME];
    char pass[MAX_UPASS];
    short int type;
};

void HeadUser(void){
    HeadText();
    User();
}

void HeadText(void){
    system("clear||clr");
    FILE * head = fopen("file/head.txt", "r");;
    char str[MAXCHAR];
    while (fgets(str, MAXCHAR, head))
        printf("%s", str);
    fclose(head);
}

int GuideText(void){
    system("clear||clr");
    FILE * guide = fopen("file/guide.txt", "r");;
    char str[MAXCHAR];
    while (fgets(str, MAXCHAR, guide))
        printf("%s", str);
    fclose(guide);
    printf("\n\n*Type any key to continue\n > ");
    scanf("%s", &input);
    return 9;
}

void User(void){
    if (type_user == 1){
        strcpy(uType, "Admin");
    }else if (type_user == 2){
        strcpy(uType, "Pegawai");
    }
    puts("___________________________________________________________________________________");
    puts(" ");
    printf("\t\t\t\t%s - %s\n", uName, uType);
    puts("___________________________________________________________________________________");
}

int Guide(void){
    HeadText();
    puts("___________________________________________________________________________________");
    printf("\n*Type [ l ] to login [ h ] to help [ q ] to exit");
    printf("\n\n> ");
    scanf("%c", &input);
    switch (input){
    case 'q': return 0;
    case 'l': return Login();
    case 'h': return GuideText();
    default : return 9;
    }
}

int Head(void){
    switch (type_user){
    case 1: return Head1();
    case 2: return Head2();
    }
}

int Head1(void){
    HeadUser();
    printf("\n*Type [ i ] to input [ o ] to output [ v ] to view [ q ] to loguot [ s ] to setting\n\n");
    printf("%s > ", uName);
    scanf("%c", &input);
    switch (input){
    case 'q': return 0;
    case 'i': return 1;
    case 'o': return 2;
    case 'v': return 3;
    case 's': return 4;
    default : return 9;
    }
}

int Head2(void){
    HeadUser();
    printf("\n*Type [ i ] to input [ o ] to output [ v ] to view [ q ] to loguot\n\n");
    printf("%s > ", uName);
    scanf("%c", &input);
    switch (input){
    case 'q': return 0;
    case 'i': return 1;
    case 'o': return 2;
    case 'v': return 3;
    default : return 9;
    }
}

int Login (void){
    struct Account acc;
    char name[MAX_UNAME], pass[MAX_UPASS];
    
    printf("\tUsername : ");
    scanf("%s", &name);
    printf("\tPassword : ");
    scanf("%s", &pass);

    FILE * sc = fopen("file/user.txt","r");
    
    while (!feof(sc))
    {
        fscanf(sc,"%s\t%s\t%d", &acc.name, &acc.pass, &acc.type);
        if(strcmp(name,acc.name) == 0) {
            if (strcmp(pass,acc.pass) == 0){
                strcpy(uName, acc.name);
                type_user = acc.type;
                if (acc.type == 1){
                    return 1;
                }
                if (acc.type == 2){
                    return 2;
                }
            }
        }
    }
    fclose(sc);
    printf("\n\n*Username or Password wrong");
    printf("\n\n*Type any key to continue\n > ");
    printf("\n\n > ");
    scanf("%c", &input);
    return 9;
}