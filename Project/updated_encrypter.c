/*
    Author : Dnyaneshwar Padule
    Date : 17-12-2023


    updates :- 
    store user records in C://ENCRYPTER//store_info.txt
    create functions :- int check_setup();
                        void setup();
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include<windows.h>

struct user_data
{
    char user_name[20];
    int key;
    char file_path[120];
};


char menu();
int message_invalid_input();
int check_key_validation(int ,struct user_data *);
void get_user_data(struct user_data *);
void message_file_opening_error(const char*);
void message_file_already_encrypted();
int message_username_and_password_already_used();
void message_successfull_file_or_folder_operation(char *,const char *);
void encrypt_user_data(struct user_data *);
int is_file_already_encrypted(struct user_data *);
int check_username_and_key(struct user_data *);
void my_string_copy_for_file(char *,char[]);
int file_encryption_or_decryption_process(char * ,int);
void store_user_record_in_file(struct user_data *);
void encrypt_file();
void save_info(const char *, struct user_data *);
void decrypt_file();
void get_data_for_decryption(struct user_data *);
int is_data_matched(struct user_data *);
void message_data_not_matched();
void remove_user_record(struct user_data *);
void show_all_entries(void);
void message_Re_run_program(void);

char menu()
{
    short int choice;
    system("cls");
    printf("\n\t    +--------------------------------------------------------------------+\n");
    printf("\t    | This program performs encryption and decryption for files/folders. |\n");
    printf("\t    +--------------------------------------------------------------------+\n");

    printf("\n\t\t\t\t      +--------------+\n");
    printf("\t\t\t\t      | **- Menu -** |\n");
    printf("\t\t\t\t      +--------------+\n");

    printf("\t\t\t+------------------------------------------+\n");
    printf("\t\t\t| Enter '1' for Encrypt a file             |\n");
    printf("\t\t\t| Enter '2' for Decrypt an Encrypted file  |\n");
    printf("\t\t\t| Enter '3' for Encrypt a folder           |\n");
    printf("\t\t\t| Enter '4' for Decrypt an Encrypted folder|\n");
    printf("\t\t\t| Enter '5' to exit                        |\n");
    printf("\t\t\t+------------------------------------------+\n");
    printf("\t\t\t\tEnter : ");
    scanf("%d",&choice);
    getchar();

    return choice;
}

int message_invalid_input()
{
    return MessageBox(
        NULL,
        "Input not matched !\nDo you want to try again ?",
        "Warning !",
        MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON1
    ) ;
}

void message_Re_run_program()
{
    MessageBox(
        NULL,
        "You have entered wrong input for many times .\nThe program is terminated , for trying again re-run the program !",
        "Warning",
        MB_ICONWARNING | MB_OK | MB_DEFBUTTON1
    );    
}

int check_key_validation(int attempt,struct user_data *ptr)
{
    if ( ! (ptr->key > 1000 && ptr->key < 9999)  )
    {
        if (attempt > 5)
        {
            MessageBox(
                NULL,
                "Your attempts to enter the key are over !\nProgram is terminated .",
                "Caution !",
                MB_ICONEXCLAMATION | MB_OKCANCEL | MB_DEFBUTTON1
            );

            rename("hid.txt",".hid");
            printf("Aborted !\n");
            exit(0);
        }

        if(
            MessageBox(
                NULL,
                "Key is not valid !\nDo you want to try again ?",
                "Warning !",
                MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON1 
            ) == 7
        )
        {
            rename("hid.txt",".hid");
            exit(0);
        }
        else
        {
            return 1;
        }

    }// if(ptr)
    else
    {
        return 0;
    }
    
}

void get_user_data(struct user_data *User)
{
    unsigned short int attempt=0;
    
    printf("Enter username : ");
    scanf("%s",&User->user_name);
    reenter_key:
    printf("Enter a four digit (Integer) key : ");
    scanf("%d",&User->key);
    getchar();
    attempt++;

    if ( check_key_validation(attempt,User) )
    {
        goto reenter_key;
    }

}

void message_file_opening_error(const char *file )
{
    char buffer[120];
    sprintf(buffer,"[ %s ] \nUnable to open the file !",file);

    MessageBox(
        NULL,
        buffer,
        "Error !",
        MB_OKCANCEL | MB_ICONHAND | MB_DEFBUTTON1
    );
}

void message_file_already_encrypted()
{
    MessageBox(
        NULL,
        "File is already encrypted !",
        "Warning !",
        MB_OKCANCEL | MB_ICONWARNING | MB_DEFBUTTON1
    );
}

int message_username_and_password_already_used()
{
   return MessageBox(
        NULL,
        "Username and password is already in use !\nDo you want to try again",
        "Warning !",
        MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON1
    );
}

void message_successfull_file_or_folder_operation(char *df,const char *operation)
{
    char buffer[420];
    sprintf(buffer,"%s of [%s] is successfull !\n",operation,df);

   MessageBox(
        NULL,
        buffer,
        "Notice !",
        MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON1
    );
}

void encrypt_user_data(struct user_data *u)
{
    u->key = u->key ^ 8882;
    
    for (int i = 0; u->user_name[i] ; i++)
    {
        u->user_name[i] = u->user_name[i] ^ 8882;
    }

    for (int i = 0; u->file_path[i] ; i++)
    {
        u->file_path[i] = u->file_path[i] ^ 8882;
    }
}

int is_file_already_encrypted(struct user_data *u)
{
    int n;
    char flag='0',error_msg[120];
    struct user_data user;
    FILE *data_file;

    if ( (data_file = fopen("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\.hid","r")) == NULL )
    {
        sprintf(error_msg," %s : %s ","Main File",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    printf("Enter the path of file/folder : ");
    scanf("%s",&u->file_path);
    getchar();

    for (int i = 0; u->file_path[i] ; i++)
    {
        u->file_path[i] = u->file_path[i] ^ 8882 ;
    }
    

    while (1)
    {
        n = fscanf(data_file,"%s %d %s",user.user_name,&user.key,user.file_path);
        if (n == EOF)
        {
            break;
        }

        if ( strcmp(user.file_path,u->file_path) == 0)
        {
            flag = '1';
            break;
        }
    } // While
    
    if (flag == '1')
    {
        message_file_already_encrypted();
        fclose(data_file);
        return 1;
    }
    else
    {
        fclose(data_file);
        for (int i = 0; u->file_path[i] ; i++)
        {
            u->file_path[i] = u->file_path[i] ^ 8882 ;
        }
        return 0;
    }
}

int check_username_and_key(struct user_data *u)
{
    struct user_data user;
    int n;
    char flag ='0',error_msg[120]; 

    FILE *data_file;

    if ( (data_file = fopen("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\.hid","r")) == NULL )
    {
        sprintf(error_msg," %s : %s ","Main File",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    for (int i = 0; u->user_name[i] ; i++)
    {
        u->user_name[i] = u->user_name[i] ^ 8882;
    }
    u->key = u->key ^ 8882;

    while (1)
    {
        n = fscanf(data_file,"%s %d %s",user.user_name,&user.key,user.file_path);
        if (n == EOF)
        {
            break;
        }
        if ( ( strcmp(u->user_name,user.user_name) == 0) && u->key == user.key )
        {
            flag ='1';
            break;
        }
    }

    if (flag == '1')
    {   
        fclose(data_file);
        message_username_and_password_already_used();
        return 1; 
    }
    else
    {
        fclose(data_file);
        for (int i = 0; u->user_name[i] ; i++)
        {
            u->user_name[i] = u->user_name[i] ^ 8882;
        }
        u->key = u->key ^ 8882;
        
        return 0;
    }
}

void my_string_copy_for_file(char *destination_file,char source_file[])
{
    int i , j = 0;
    
    for ( i = 0; source_file[i] ; i++)
    {
    
        if (source_file[i]  == '.' )
        {
            
            strcat(destination_file,"temp");
            j = j+4;
            for ( ; source_file[i] ; i++)
            {
                destination_file[j] = source_file[i];
                j++;   
            }

            break;
        }

        else
        {
            destination_file[j] = source_file[i];
            j++; 
        }
        
    } // for
    
}

int file_encryption_or_decryption_process(char *file_name,int key)
{
    FILE *source_file=NULL,*target_file=NULL;
    char buffer[1024],destination_file[1024]={'\0'};
    size_t bytes_read=0;
    char error_msg[120];

    if ( (source_file = fopen(file_name,"rb")) == NULL )
    {
        sprintf(error_msg," %s : %s ",file_name,strerror(errno));
        message_file_opening_error(error_msg);
        return 1;
    }

    my_string_copy_for_file(destination_file,file_name);

    if ( (target_file = fopen(destination_file,"wb") ) == NULL)
    {
        fclose(source_file);
        sprintf(error_msg," %s : %s ",destination_file,strerror(errno));
        message_file_opening_error(error_msg);
        return 1;
    }

    while (1)
    {
        bytes_read = fread(buffer,1,sizeof(buffer),source_file);

        if ( ! bytes_read )
        {
            break;
        }

        for (int i = 0; i < bytes_read ; i++)
        {
            buffer[i] = buffer[i] ^ key ;
        }
        
        fwrite(buffer,1,bytes_read,target_file);
    }
    
    fclose(source_file);
    fclose(target_file);

    remove(file_name);
    rename(destination_file,file_name);

}

void save_info(const char *ch ,struct user_data *u)
{
    FILE *fp=NULL;
    time_t tm;
    char *time_str;
    char error_msg[120];

    tm = time(NULL);

    fp = fopen("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\store_info.txt","a");
    if (fp == NULL)
    {
        sprintf(error_msg," %s : %s ","store_info.txt",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    time_str = ctime(&tm);
    if ( *ch == 'E')
    {
        fprintf(fp,"[ %s ] encrypted by %s at : %s",u->file_path,u->user_name,time_str);   
    }
    else
    {
        fprintf(fp,"[ %s ] decrypted by %s at : %s",u->file_path,u->user_name,time_str);   
    }

    fclose(fp);
}

void store_user_record_in_file(struct user_data *u)
{
    FILE *data_file;
    char error_msg[120];

    if(( data_file = fopen("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\.hid","a") )== NULL )
    {
        sprintf(error_msg," %s : %s ","Main File",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    fprintf(data_file,"%s %d %s\n",u->user_name,u->key,u->file_path);

    fclose(data_file);
}

void encrypt_file()
{
    struct user_data user;

    if(  is_file_already_encrypted(&user) )
    {
        exit(0);
    }
    else
    {
        get_again:
        get_user_data(&user);
    }

   if( check_username_and_key(&user) )
   {
        goto get_again;
   }

    if( file_encryption_or_decryption_process(user.file_path,user.key) )
    {
        exit(0);
    }
    save_info("E",&user);
    message_successfull_file_or_folder_operation(user.file_path,"Encryption");

    encrypt_user_data(&user);
    store_user_record_in_file(&user);
    
}

void get_data_for_decryption(struct user_data *u)
{
    printf("\nEnter file or folder path : ");
    scanf("%s",u->file_path);
    getchar();
    printf("Enter the Username : ");
    scanf("%s",u->user_name);
    getchar();
    printf("Enter the key : ");
    scanf("%d",&u->key);
    getchar();
} 

int is_data_matched(struct user_data *u)
{
    struct user_data user={'\0',0,'\0'};
    FILE *data_file;
    int n;
    char flag = '0',error_msg[120];

    if ( (data_file = fopen("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\.hid","r") ) == NULL )
    {
        sprintf(error_msg," %s : %s ","Main File",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    while (1)
    {
        n = fscanf(data_file,"%s %d %s",user.user_name, &user.key, user.file_path);

        if (n == EOF)
        {
            break;
        }

        if ( ( strcmp(user.user_name,u->user_name) == 0 ) && ( strcmp(user.file_path,u->file_path) == 0 ) && user.key == u->key)
        {
            flag = '1';
            break;
        }
        
    }
    

    if (flag == '1')
    {
        fclose(data_file);
        encrypt_user_data(u);
        return 1;
    }
    else
    {
        fclose(data_file);
        return 0;
    }
    
}

void message_data_not_matched()
{
    MessageBox(
        NULL,
        "Data not found for resprctive file !",
        "Error",
        MB_OKCANCEL | MB_DEFBUTTON1 | MB_ICONERROR
    );
}

void remove_user_record(struct user_data *u)
{
    struct user_data user;
    FILE *data_file,*temp_file;
    int n;
    char error_msg[120];

    if ( (data_file = fopen("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\.hid","r") ) == NULL )
    {
        sprintf(error_msg," %s : %s ","Main File",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    if ( (temp_file = fopen("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\temp.txt","w") ) == NULL )
    {
        sprintf(error_msg," %s : %s ","temp.txt",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    while (1)
    {
        n = fscanf(data_file,"%s %d %s",user.user_name,&user.key,user.file_path);
        if (n == EOF)
        {
            break;
        }

        if ( ! ( (strcmp(user.user_name,u->user_name) == 0) && user.key == u->key ) )
        {
            fprintf(temp_file,"%s %d %s\n",user.user_name,user.key,user.file_path);
        }
    }

    fclose(data_file);
    fclose(temp_file);

    remove("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\.hid");
    rename("C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\temp.txt","C:\\DNYANESHWAR\\Sysyem_Programming_using_C\\.hid");
    
}

void decrypt_file()
{
    struct user_data user;

    get_data_for_decryption(&user);

    encrypt_user_data(&user);
    
    if ( ! is_data_matched(&user) )
    {
        message_data_not_matched();
        exit(0);
    }

   if( file_encryption_or_decryption_process(user.file_path,user.key) )
   {
        exit(0);
   }
    message_successfull_file_or_folder_operation(user.file_path,"Decryption");
    save_info("D",&user);
    encrypt_user_data(&user);
    remove_user_record(&user);  
}

void folder_encryption_or_decryption_process(struct user_data *u)
{
    struct dirent *de;
    DIR *dr;
    char buffer[240]={"\0"};
    char *file_name;
    
    dr = opendir(u->file_path);
    if(dr == NULL)
    {
        message_file_opening_error(u->file_path);
        exit(0);
    }
    printf("\n");
    while( (de = readdir(dr)) != NULL)
    {   
        strcpy(buffer,u->file_path);
        strcat(buffer,"\\");
        strcat(buffer,de->d_name);

        if( file_encryption_or_decryption_process(buffer,u->key) )
       {
            printf("[%s] is unable to open\n",de->d_name);
       }
       else
       {
            printf("Operation done with [%s] \n",de->d_name);
       }
    }

}

void encrypt_folder()
{
    struct user_data user;
    printf("\n");

    if(  is_file_already_encrypted(&user) )
    {
        exit(0);
    }
    else
    {
        get_again:
        get_user_data(&user);
    }

   if( check_username_and_key(&user) )
   {
        goto get_again;
   }

    folder_encryption_or_decryption_process(&user);
    save_info("E",&user);
    message_successfull_file_or_folder_operation(user.file_path,"Encryption");

    encrypt_user_data(&user);
    store_user_record_in_file(&user);

}

void decrypt_folder()
{
    struct user_data user;

    get_data_for_decryption(&user);

    encrypt_user_data(&user);
    
    if ( ! is_data_matched(&user) )
    {
        message_data_not_matched();
        exit(0);
    }

    folder_encryption_or_decryption_process(&user);
    message_successfull_file_or_folder_operation(user.file_path,"Decryption");
    save_info("D",&user);
    encrypt_user_data(&user);
    remove_user_record(&user);  
}

void show_all_entries(void)
{
    FILE *data_file;
    int key;
    char dir_name[75],user_name[20],error_msg[120];

    data_file = fopen(".hid","r");
    if (data_file == NULL)
    {
        sprintf(error_msg," %s : %s ","Main File",strerror(errno));
        message_file_opening_error(error_msg);
        exit(0);
    }

    while( (fscanf(data_file,"%s %d %s",user_name,&key,dir_name)) != EOF )
    {
        key = key ^ 8882;
        for (int i = 0; user_name[i] ; i++)
        {
            user_name[i] = user_name[i] ^ 8882 ;
        }

        for (int i = 0; dir_name[i] ; i++)
        {
            dir_name[i] = dir_name[i] ^ 8882;
        }
        
        printf("%s\t%d\t%s\n",user_name,key,dir_name);
        
    }
    
    fclose(data_file);
}

int main()
{
    unsigned short int cnt=0;
    get_input_again :

    cnt++;
    if (cnt > 5)
    {
        message_Re_run_program();
        exit(0);
    }
    
    switch (menu())
    {
        case 0:
                show_all_entries();
        break;
        case 1:
                encrypt_file();
        break;

        case 2:
               decrypt_file();
        break;

        case 3:
               encrypt_folder();
        break;

        case 4:
               decrypt_folder();
        break;

        case 5:
                exit(0);


    default:
        if ( message_invalid_input() == 7 )
        {
            exit(0);
        }
        else
        {
            goto get_input_again;
        }
    }


}