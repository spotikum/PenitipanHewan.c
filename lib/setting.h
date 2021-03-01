int Setting();
int ViewUser();
int AddUser();
int DeleteUser();
int edit();
void ScanDataUser();
void ViewDataUser();
struct Account;
int Juser;

struct Account uac;

int Setting(){
    ScanDataUser();
    HeadUser();
    printf("\n\t\t\t\t[ Setting User ]");
    printf("\n\n*Type [ a ] to add [ v ] to view [ d ] to delete [ e ] to edit [ q ] to back\n\n> ");
    scanf("%s", &input);
    switch (input){
    case 'q': return 9;
    case 'a': return AddUser();
    case 'v': return ViewUser();
    case 'd': return DeleteUser();
    case 'e': return edit();
    default : return 4;
    }
}

int edit(){
    struct Account scan[Juser];
    ViewDataUser();
    printf("\n\nUser for edit : ");
    scanf("%s", &uName);

    FILE * edit;
    edit = fopen("file/user.txt", "r");
    int i;
    char tempNama[MAX_UNAME];
    for (i = 0; i < Juser; i++){
        fscanf(edit,"%s\t%s\t%d", &scan[i].name, &scan[i].pass, &scan[i].type);
        if (strcmp(uName,scan[i].name) == 0){
            strcpy(tempNama, scan[i].name);
            printf("\nInput New Name      : ");
            scanf("%s", &scan[i].name);
            printf("Input New Password  : ");
            scanf("%s", &scan[i].pass);
            printf("Input New Type      : ");
            scanf("%d", &scan[i].type);
            break;
        }else if (strcmp(uName,quit) == 0)
        {
            return 4;
        }
        
    }
    if (strcmp(uName,tempNama) != 0)
    {
        printf("\n\n*Incorrect Name");
        printf("\n\n*Type any key to continue\n > ");
        scanf("%s", &input);
        return 4;
    }
    
    fclose(edit);

    edit = fopen("file/user.txt", "w");
    for (i = 0; i < Juser; i++){
        fprintf(edit,"%s\t%s\t%d\n", scan[i].name, scan[i].pass, scan[i].type);
    }
    fclose(edit);

    printf("\n\n*Successfully edit the user");
    printf("\n\n*Type any key to continue\n > ");
    scanf("%s", &input);
    return 4;
}

int AddUser(){
    HeadUser();
    printf("\n New Username    : ");
    scanf("%s", &uac.name);
    printf("\n New Password    : ");
    scanf("%s", &uac.pass);
    printf("\n Type of user    : ");
    scanf("%d", &uac.type);
    FILE * add = fopen("file/user.txt", "a");
    fprintf(add,"%s\t%s\t%d\n", uac.name, uac.pass, uac.type);
    fclose(add);
    printf("\n\n *Add user sucsess*\n\n");
    printf("\n*Type any key to continue\n > ");
    scanf("%s", &input);
    return 4;
}

int DeleteUser(){
    printf("\n\t\t\t\t[ Delete User ]");
    ViewDataUser();
    printf("\n Input nama user : ");
    scanf("%s", uName);
    struct Account scan[Juser];
    struct Account scanac;
    FILE * delete;
    delete = fopen("file/user.txt", "r");
    while (!feof(delete))
    {
        fscanf(delete,"%s\t%s\t%d", &scanac.name, &scanac.pass, &scanac.type);
        if (strcmp(uName,scanac.name) == 0)
        {
            break;
        }else if (strcmp(uName,quit) == 0)
        {
            return 4;
        }
        
    }
    fclose(delete);
    if (strcmp(uName,scanac.name) != 0)
    {
        printf("\n\n*Incorrect Name");
        printf("\n\n*Type any key to continue\n > ");
        scanf("%s", &input);
        return 4;
    }
    
    delete = fopen("file/user.txt", "r");
    int d;
    for (d = 0; d < Juser; d++)
    {
        fscanf(delete,"%s\t%s\t%d", &scan[d].name, &scan[d].pass, &scan[d].type);
    }
    fclose(delete);

    delete = fopen("file/user.txt", "w");
    for (int i = 0; i < Juser; i++)
    {
        if (strcmp(uName,scan[i].name) != 0)
        {
            fprintf(delete,"%s\t%s\t%d\n", scan[i].name, scan[i].pass, scan[i].type);
        }
    }
    fclose(delete);

    printf("\n\n*Successfully delete the user");
    printf("\n\n*Type any key to continue\n > ");
    scanf("%s", &input);

    return 4;
}

void ViewDataUser(){
    printf("\n\t\t\t   Nama\t\tPwd\tType\n");
    printf("\t\t\t  _____________________________\n");
    FILE * view = fopen("file/user.txt", "r");
    for (int i = 0; i < Juser; i++)
    {
        fscanf(view,"%s\t%s\t%d", &uac.name, &uac.pass, &uac.type);
        printf("\t\t\t   %s\t%s\t%d\t\n", uac.name, uac.pass, uac.type);
    }
    fclose(view);
}

int ViewUser(){
    HeadUser();
    ViewDataUser();
    printf("\n*Type any key to continue\n > ");
    scanf("%s", &input);
    return 4;
}

void ScanDataUser(){
    FILE * scan = fopen("file/user.txt", "r");
    int i = 0;
    while(!feof(scan)){
        fscanf(scan,"%s\t%s\t%d", &uac.name, &uac.pass, &uac.type);
        i++;
    }
    Juser = i - 1;
    fclose(scan);
}