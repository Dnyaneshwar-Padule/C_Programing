#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>
#include<windows.h>

#define NAME_SIZE 16
#define KEY 777
#define SUCCESS 0
#define FAILURE 1
#define ALL_SUBJECTS 3

struct student_data
{
    unsigned int rollNo;
    unsigned int totalMarks;
    float percentage;
    char grade;
    char firstName[NAME_SIZE]; 
    char middleName[NAME_SIZE]; 
    char lastName[NAME_SIZE];
    int  MathTwo;
    int C;
    int BEE;
};

void message_data_found_successfull(char message[])
{
    MessageBox(
        NULL,
        message,
        "Student Information !",
        MB_ICONINFORMATION | MB_DEFBUTTON1 | MB_OK
    );
}

void message_attempts_over()
{
    MessageBox(
            NULL,
            "You have entered wrong password so many times !\nYour attempts to enter the password are over !\nPlease try again by re-executing the program .",
            "Password Entering Attempts ",
            MB_ICONHAND | MB_OK
    );
}

void successfull_database_connection()
{
    MessageBox(
        NULL,
        "You are successfully connected with the database folder !",
        "Database folder connection !",
        MB_ICONINFORMATION | MB_OK 
    );
}

void message_successfull_verification()
{
    MessageBox(
        NULL,
        "Password is verified successfully ! ",
        "Verification ",
        MB_ICONINFORMATION | MB_OK
    );
}

int message_unsuccessfull_verification()
{
    MessageBox(
        NULL,
        "Password not Matched !\nDo you want to try again ?",
        "Verification ",
        MB_ICONINFORMATION | MB_YESNO | MB_DEFBUTTON2
    );
}

void custom_message(char buffer[])
{
    MessageBox(
        NULL,
        buffer,
        "Caution !",
        MB_ICONEXCLAMATION | MB_DEFBUTTON1 | MB_OK
    );
}

void message_successful_password_setup()
{
    MessageBox(
        NULL,
        "Password setup is Succefull !",
        "Password Setup ",
        MB_ICONINFORMATION | MB_OK
    );
}

void message_box_process_complete(char process_buffer[])
{
    MessageBox(
        NULL,
        process_buffer,
        "Process Complete ",
        MB_ICONINFORMATION | MB_DEFBUTTON1 | MB_OK

    );
}

int message_box_asking_for_going_back()
{
    return MessageBox(
        NULL,
        "Operation completed successfully !\nDo you want to go back on Home screen ?",
        "Operation Completed ",
        MB_ICONINFORMATION | MB_DEFBUTTON1 | MB_YESNO
    );
}

void message_box_program_termination()
{
    MessageBox(
        NULL,
        "Program is terminated successfully !\n",
        "Close Program ! ",
        MB_ICONINFORMATION | MB_DEFBUTTON1 | MB_OK
    );
}

void message_box_display_error(char error_msg[])
{
    MessageBox(
        NULL,
        "Error !",
        error_msg,
        MB_ICONERROR | MB_OK
    );
}

int get_instruction(void)
{

    short int choice;
    system("cls");
    printf("\n\t\tYou are connected with the database folder ...\n");
    printf("\n\t\t\t\t==================================================");
    printf("\n\t\t\t\t** STUDENT MANAGEMENT SYSTEM USING C LANGUAGE **");
    printf("\n\t\t\t\t==================================================\n\n");

    printf("\t\t\t\t +---------------**## ENTER ##**-----------------+\n");
    printf("\t\t\t\t | _____________________________________________ |\n");
    printf("\t\t\t\t |#|  1  --> To Add Student Data .             |#|\n");
    printf("\t\t\t\t | +-------------------------------------------+ |\n");
    printf("\t\t\t\t |#|  2  --> To Remove Student Data By Roll No.|#|\n");
    printf("\t\t\t\t | +-------------------------------------------+ |\n");
    printf("\t\t\t\t |#|  3  --> To Update Student Data .          |#|\n"); 
    printf("\t\t\t\t | +-------------------------------------------+ |\n");
    printf("\t\t\t\t |#|  4  --> To Display All Records .          |#|\n"); 
    printf("\t\t\t\t | +-------------------------------------------+ |\n");
    printf("\t\t\t\t |#|  5  --> To Search Student Data            |#|\n");
    printf("\t\t\t\t | +-------------------------------------------+ |\n");
    printf("\t\t\t\t |#|  6  --> To Exit !!                        |#|\n");
    printf("\t\t\t\t | +-------------------------------------------+ |\n");
    printf("\t\t\t\t +-----------------------------------------------+\n");
    printf("\t\t\t\t___________________________________________________\n");

    printf("\n\t\t\t\t\tEnter :->> ");
    scanf("%d",&choice);
    getchar();

    return choice;
}

int check_student_roll_no(int rno)
{
    FILE *roll_no_file;
    int buffer=0;

    roll_no_file = fopen("C:\\Student_Management_Software\\Student_Data\\roll_no.txt","a+");
    if (roll_no_file == NULL)
    {
        char error_message[120];
        sprintf(error_message,("C:\\Student_Management_Software\\Student_Data\\roll_no.txt : %s \n" ,strerror(errno)) );
        message_box_display_error(error_message);
        return FAILURE;
    }

    while( fscanf(roll_no_file,"%d",&buffer) != EOF )
    {
        if (buffer == rno )
        {
            fclose(roll_no_file);
            return SUCCESS;
        }
    }

    fclose(roll_no_file);
    return FAILURE;
}

void accept_student_data(struct student_data *student)
{
    getchar();
    printf("\t\t\t\t Enter First Name of the Student    : ");
    scanf("%s",&student->firstName);

    getchar();
    printf("\t\t\t\t Enter Middle Name of the Student   : ");
    scanf("%s",&student->middleName);

    getchar();
    printf("\t\t\t\t Enter Last Name of the Student     : ");
    scanf("%s",&student->lastName);

    printf("\t\t\t\t Enter the marks of M2              : ");
    scanf("%d",&student->MathTwo);
    getchar();

    printf("\t\t\t\t Enter the marks of C               : ");
    scanf("%d",&student->C);
    getchar();

    printf("\t\t\t\t Enter the marks of BEE             : ");
    scanf("%d",&student->BEE);
    getchar();
}

void encrypt_student_data(struct student_data *student)
{
    student->MathTwo = student->MathTwo ^ 777;
    student->C = student->C ^ KEY;
    student->BEE = student->BEE ^ KEY;
    student->grade = student->grade ^ KEY;
    student->percentage = student->percentage * KEY;
    student->totalMarks = student->totalMarks ^ KEY;
    student->rollNo = student->rollNo ^ KEY;

    for (int i = 0 ; student->firstName[i]; i++)
        student->firstName[i] = student->firstName[i] ^ KEY;

    for (int i = 0 ; student->middleName[i]; i++)
        student->middleName[i] = student->middleName[i] ^ KEY;

    for (int i = 0 ; student->lastName[i]; i++)
        student->lastName[i] = student->lastName[i] ^ KEY;
}

void decrypt_student_data(struct student_data *student)
{
    student->rollNo = student->rollNo ^ KEY;
    student->MathTwo = student->MathTwo ^ KEY;
    student->C = student->C ^ KEY;
    student->BEE = student->BEE ^ KEY;
    student->grade = student->grade ^ KEY;
    student->percentage = student->percentage / KEY;
    student->totalMarks = student->totalMarks ^ KEY;

    for (int i = 0 ; student->firstName[i]; i++)
        student->firstName[i] = student->firstName[i] ^ KEY;

    for (int i = 0 ; student->middleName[i]; i++)
        student->middleName[i] = student->middleName[i] ^ KEY;

    for (int i = 0 ; student->lastName[i]; i++)
        student->lastName[i] = student->lastName[i] ^ KEY;
}

void find_total_and_percentage(struct student_data *student)
{
    student->totalMarks = 0;

    student->totalMarks = student->C + student->BEE + student->MathTwo ;

    student->percentage = (float)student->totalMarks / ALL_SUBJECTS ;

    if (student->percentage >= 75)
        student->grade = 'A';
    else if (student->percentage >= 60)
        student->grade = 'B';
    else if (student->percentage >= 50)
        student->grade = 'C';
    else if (student->percentage >= 40)
        student->grade = 'D';
    else if (student->percentage >= 30)
        student->grade = 'E';
    else
        student->grade = 'F';
}

int store_roll_no(int *roll_no)
{
    FILE *rno_file;

    rno_file = fopen("C:\\Student_Management_Software\\Student_Data\\roll_no.txt","a");
    if ( rno_file == NULL )
    {
        char error_message[120];
        sprintf(error_message,("C:\\Student_Management_Software\\Student_Data\\roll_no.txt : %s \n" ,strerror(errno)) );
        strcat(error_message,"Unable to open the file !\nPlease try again .");
        message_box_display_error(error_message);
        return FAILURE;
    }

    if ( fprintf(rno_file,"%d\n",*roll_no) < 0 )
    {
        char error_message[120];
        sprintf(error_message,("C:\\Student_Management_Software\\Student_Data\\roll_no.txt : %s \n" ,strerror(errno)) );
        strcat(error_message,"Unable to perform wright operation on the file !\nPlease try again .");
        message_box_display_error(error_message);
        fclose(rno_file);
        return FAILURE;
    }

    fclose(rno_file);
    return SUCCESS;   
}

int add_Student_Data(void)
{
    struct student_data student;
    struct student_data temp_student;
    int temp,i=0,j=0;
    char flag='0';
    char another_flag='0';
    FILE *stud_data_file;
    FILE *temp_file;

    printf("\n\t\t\t\t==================================================");
    printf("\n\t\t\t\t**             ADD STUDENT RECORD             **");
    printf("\n\t\t\t\t==================================================\n\n");
    printf("\t\t\t\t Enter student information \n");
    printf("\t\t\t\t_________________________________________________\n\n");
    
    printf("\t\t\t\t Enter Roll No of the Student       : ");
    scanf("%d",&temp_student.rollNo);
    if ( check_student_roll_no(temp_student.rollNo) != FAILURE)
    {
        custom_message("Entered Roll number already exixts in the Records !\n");
        return SUCCESS;
    }

    accept_student_data(&temp_student);

    if ( store_roll_no(&temp_student.rollNo) == FAILURE)
        return FAILURE;

    find_total_and_percentage(&temp_student);
    temp = temp_student.rollNo;
    encrypt_student_data(&temp_student);

    stud_data_file = fopen("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt","a+");
    if (stud_data_file == NULL)
    {
        char err_msg[240];
        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nUnable to open the file !\nTry again !");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    temp_file = fopen("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt","w");
    if (stud_data_file == NULL)
    {
        char err_msg[240];
        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nUnable to open the file !\nTry again !");
        fclose(stud_data_file);
        message_box_display_error(err_msg);
        return FAILURE;
    }
    

    while( 
            fscanf(stud_data_file,"%s %s %s %d %d %d %d %d %f %c \n",
            &student.firstName,&student.middleName,&student.lastName,&student.rollNo,&student.MathTwo
            ,&student.C,&student.BEE,&student.totalMarks,&student.percentage,&student.grade) 

            != EOF     )
        {
            i++;
            flag = '1';

                if (ferror(stud_data_file))
                {
                    char err_msg[240];

                    sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
                    strcat(err_msg,"\nAn error occured while reading a file !\n");
                    strcat(err_msg,"Please try again later !\n");
                    fclose(stud_data_file);
                    fclose(temp_file);
                    remove("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt");
                    message_box_display_error(err_msg);
                    return FAILURE;
                }

                if( another_flag == '0' )
                {

                    if ( temp < (student.rollNo ^ KEY) )
                    {
      
                        another_flag = '1';
                        if (
                                fprintf(temp_file,"%s %s %s %d %d %d %d %d %f %c \n",
                                temp_student.firstName,temp_student.middleName,temp_student.lastName,temp_student.rollNo,temp_student.MathTwo
                                ,temp_student.C,temp_student.BEE,temp_student.totalMarks,temp_student.percentage,temp_student.grade) 
                            < 0)
                            {
                                char err_msg[120];
                                sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]\n ",strerror(errno));
                                strcat(err_msg,"Data not written , please try again ");
                                message_box_display_error(err_msg);
                                remove("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt");
                                return FAILURE; 
                            }
               
                        if ( 
                            fprintf(temp_file,"%s %s %s %d %d %d %d %d %f %c \n",
                            student.firstName,student.middleName,student.lastName,student.rollNo,student.MathTwo
                            ,student.C,student.BEE,student.totalMarks,student.percentage,student.grade)
                        < 0   )
                        {
                            char err_msg[120];
                            sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]\n ",strerror(errno));
                            strcat(err_msg,"Data not written , please try again ");
                            message_box_display_error(err_msg);
                            remove("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt");
                            return FAILURE; 
                        }

                    }
                    else
                    {
                        j++;
              
                        if ( 
                            fprintf(temp_file,"%s %s %s %d %d %d %d %d %f %c \n",
                            student.firstName,student.middleName,student.lastName,student.rollNo,student.MathTwo
                            ,student.C,student.BEE,student.totalMarks,student.percentage,student.grade)
                        < 0   )
                        {
                            char err_msg[120];
                            sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]\n ",strerror(errno));
                            strcat(err_msg,"Data not written , please try again ");
                            message_box_display_error(err_msg);
                            remove("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt");
                            return FAILURE; 
                        }
            
                    }
                }
                 else
                {
             
                    if ( 
                            fprintf(temp_file,"%s %s %s %d %d %d %d %d %f %c \n",
                            student.firstName,student.middleName,student.lastName,student.rollNo,student.MathTwo
                            ,student.C,student.BEE,student.totalMarks,student.percentage,student.grade)
                        < 0   )
                        {
                            char err_msg[120];
                            sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]\n ",strerror(errno));
                            strcat(err_msg,"Data not written , please try again ");
                            message_box_display_error(err_msg);
                            remove("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt");
                            return FAILURE; 
                        }
            
                    }
            
        }   

        if (flag == '0')
        {
            if (
                    fprintf(temp_file,"%s %s %s %d %d %d %d %d %f %c \n",
                    temp_student.firstName,temp_student.middleName,temp_student.lastName,temp_student.rollNo,temp_student.MathTwo
                    ,temp_student.C,temp_student.BEE,temp_student.totalMarks,temp_student.percentage,temp_student.grade) 
                < 0)
                {
                    char err_msg[120];
                    sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]\n ",strerror(errno));
                    strcat(err_msg,"Data not written , please try again ");
                    message_box_display_error(err_msg);
                    remove("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt");
                    return FAILURE; 
                }

            fclose(stud_data_file);
            fclose(temp_file);
            _fcloseall();

            if ( remove("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt") )
            {
                char err_msg[240];

                sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
                strcat(err_msg,"\nAn error came during delete operation !\n");
                strcat(err_msg,"Please try again later !\n");
                message_box_display_error(err_msg);
                return FAILURE;
            }

            if ( 
                    rename("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt",
                    "C:\\Student_Management_Software\\Student_Data\\Student_Data.txt")
                )
            {
                char err_msg[240];

                sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]",strerror(errno));
                strcat(err_msg,"\nAn error came during rename operation !\n");
                strcat(err_msg,"Please try again later !\n");
                message_box_display_error(err_msg);
                return FAILURE;
            }

                message_box_process_complete("Data Stored Successfully !\n");

            if ( message_box_asking_for_going_back() == 7  )
            {
                message_box_program_termination();
                return FAILURE ;                }

            return SUCCESS;
        }

        if (i == j)
        {
            if (
                    fprintf(temp_file,"%s %s %s %d %d %d %d %d %f %c \n",
                    temp_student.firstName,temp_student.middleName,temp_student.lastName,temp_student.rollNo,temp_student.MathTwo
                    ,temp_student.C,temp_student.BEE,temp_student.totalMarks,temp_student.percentage,temp_student.grade) 
                < 0)
                {
                    char err_msg[120];
                    sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]\n ",strerror(errno));
                    strcat(err_msg,"Data not written , please try again ");
                    message_box_display_error(err_msg);
                    remove("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt");
                    return FAILURE; 
                }
        }
         
            
        
        
        

    fclose(stud_data_file);
    fclose(temp_file);
    _fcloseall();

    if ( remove("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt") )
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during delete operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    if ( 
            rename("C:\\Student_Management_Software\\Student_Data\\Temp_File.txt",
            "C:\\Student_Management_Software\\Student_Data\\Student_Data.txt")
        )
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Temp_File.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during rename operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

        message_box_process_complete("Data Stored Successfully !\n");

        if ( message_box_asking_for_going_back() == 7  )
        {
            message_box_program_termination();
            return FAILURE ;
        }

        return SUCCESS;
}

int check_administrative_password()
{
    #define PASSKEY 7823
    #define MY_DEFAULT_PASS 0777

    FILE *main_file;
    char user_given_pass[20];
    char original_pass[20]="\0";

    printf("\n\t\t\t\t==================================================");
    printf("\n\t\t\t\t** STUDENT MANAGEMENT SYSTEM USING C LANGUAGE **");
    printf("\n\t\t\t\t==================================================\n\n");
    printf("\t\t\t\t\t\t+----------------+\n");
    printf("\t\t\t\t\t\t| AUTHINTICATION |\n");
    printf("\t\t\t\t\t\t+----------------+\n");
     printf("\t\t\t\t_________________________________________________\n\n");
    main_file = fopen("C:\\Student_Management_Software\\.Administrative_password\\.hid_mn","a+");
    if (main_file == NULL)
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\.Administrative_password : [ %s ] \n",strerror(errno));
        strcat(err_msg,"An error occured during the execution of the program !\n");
        strcat(err_msg,"Please try again !");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    if ( fscanf(main_file,"%s",&original_pass) != EOF)
    {
        if ( ferror(main_file) )
        {
            char err_msg[240];

            sprintf(err_msg,"C:\\Student_Management_Software\\.Administrative_password : [ %s ]",strerror(errno));
            strcat(err_msg,"An error occured during the execution of program !\n");
            strcat(err_msg,"Please try again !\n");
            message_box_display_error(err_msg);
            return FAILURE;
        }
    }
    
    if ( ! strlen(original_pass) )
    {
        printf("\n\t\t\t\tPlease set an ADMINISTRATIVE Password\n");
        printf("\t\t\t\t_________________________________________________\n\n");
        printf("\n\t\t\t\tEnter ADMINISTRATIVE Password : ");
        scanf("%s",original_pass);

        for (int i = 0; original_pass[i]; i++)
        {
            original_pass[i] = original_pass[i] ^ PASSKEY;
        }
        
        fprintf(main_file,"%s",original_pass);
        fclose(main_file);
        message_successful_password_setup();
        return SUCCESS;

    }
    else
    {
        for (int i = 0; original_pass[i]  ; i++)
        {
            original_pass[i] = original_pass[i] ^ PASSKEY;
        }
        int attempts=0;

        reauthentication :

        attempts++;
        if (attempts == 8)
        {
            message_attempts_over();
            exit(0);
        }
        
        printf("\n\t\t\t\t\tEnter ADMINISTRATIVE Password : ");
        scanf("%s",user_given_pass);
       

        if (! strcmp(user_given_pass,original_pass) )
        {
            message_successfull_verification();
            fclose(main_file);
            return SUCCESS;
        }
        else
        {
            if(  message_unsuccessfull_verification() == 7)
            {
                fclose(main_file);
                return FAILURE;
            }
            else
            {
                printf("\x1b[1F");
                printf("\x1b[1F");
                //printf("\x1b[1F");
                goto reauthentication;
            }
        }
        
    }
    
}

int Connect_To_The_Data_folder()
{
    DIR *dir;
    
    dir = opendir("C:\\Student_Management_Software");
    if (dir == NULL)
    {   
        if (errno == ENOENT)
        {
    
            char *primary_dir_name = "C:\\Student_Management_Software";
            char *secondary_dir_name = "C:\\Student_Management_Software\\Student_Data";
            char *another_secondary_dir_name = "C:\\Student_Management_Software\\.Administrative_Password";

            int result = 0;

            result = mkdir(primary_dir_name);
            if (result == 0)
            {
                result = mkdir(secondary_dir_name);
                if (result != 0)
                {
                    char err_msg[240];

                    printf("\nSomething went wrong ! \n");
                    sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data : [ %s ]",strerror(errno));
                    strcat(err_msg,"\nYou are Unable to connect with the database folder !!\nPlease Try again .\n");
                    message_box_display_error(err_msg);
                    return FAILURE;
                }
                else
                {
                    result = mkdir(another_secondary_dir_name);

                    if (result != 0)
                    {
                        char err_msg[240];

                        printf("\nSomething went wrong ! \n");
                        sprintf(err_msg,"C:\\Student_Management_Software\\.Administrative_password : [%s]",strerror(errno));
                        strcat(err_msg,"\nYou are Unable to connect with the database folder !!\nPlease Try again .\n");
                        message_box_display_error(err_msg);
                        return FAILURE;
                    }
                    else
                    {
                        if ( check_administrative_password() )
                            return FAILURE;
                        successfull_database_connection();
                        printf("\nYou are connected with the database folder ...\n");
                        return SUCCESS;
                    }
                }
            }
            else
            {
                printf("\nSomething went wrong ! \n");
                perror("C:\\Student_Management_Software ");
                printf("\nYou are Unable to connect with the database folder !!\nPlease Try again .\n");
                return FAILURE;
            }
        }
        else
        {
            char err_message[240];

            printf("\nSomething went wrong ! \n");
            sprintf(err_message,"C:\\Student_Management_Software : [ %s ]",strerror(errno));
            strcat(err_message,"\nSomething went wrong !");
            strcat(err_message,"\nYou are Unable to connect with the database folder !!\nPlease Try again .\n");
            message_box_display_error(err_message);
            return FAILURE;
        }
    }
    else
    {
        closedir(dir);
        if ( check_administrative_password() )
            return FAILURE;
        successfull_database_connection();
        printf("\nYou are connected with the database folder ...\n");
        return SUCCESS;
    }
}

void display_open_frame(void)
{
    printf("\n\t                                                              ___________________\n");
    printf("\t______________________________________________________________|      Marks      |_____________________________\n");
    printf("\t|                Name                   |  Roll No.  | CLASS  | M2  | CPR | BEE | Total | Percentage | Grade |\n");
    printf("\t+---------------------------------------+------------+--------+-----+-----+-----+-------+------------+-------+\n");
          
}

void display_close_frame(void)
{
    printf("\t+---------------------------------------+------------+--------+-----+-----+-----+-------+------------+-------+\n");         
}

void display_records(struct student_data *student)
{
    printf("\t|%-12s %-12s %-12s | %-10d |  COFY  | %-3d | %-3d | %-3d | %-5d | %-10.2f | %-5c |\n"
    ,student->firstName,student->middleName,student->lastName,student->rollNo
    ,student->MathTwo,student->C,student->BEE,student->totalMarks,student->percentage,student->grade);
}

int check_student_roll_no_to_delete(int rno)
{
    FILE *roll_no_file;
    FILE* temp_file;
    char flag='0';
    int buffer=0;

    roll_no_file = fopen("C:\\Student_Management_Software\\Student_Data\\roll_no.txt","a+");
    if (roll_no_file == NULL)
    {
        char err_msg[120];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\roll_no.txt : [%s]",strerror(errno));
        strcat(err_msg,"Unable to open the file !\nPlease Try agin");
        message_box_display_error(err_msg);
        return FAILURE;
        
    }
    temp_file = fopen("C:\\Student_Management_Software\\Student_Data\\temp.txt","w");
    if (temp_file == NULL)
    {
        char err_msg[120];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\temp.txt : [%s]",strerror(errno));
        strcat(err_msg,"Unable to open the file !\nPlease Try agin");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    while( fscanf(roll_no_file,"%d",&buffer) != EOF )
    {
        if (buffer == rno )
        {
            flag='1';
        }
        else
        {
            fprintf(temp_file,"%d\n",buffer);
        }
    }

    fclose(roll_no_file);
    fclose(temp_file);

    if (flag == '1')
    {
        remove("C:\\Student_Management_Software\\Student_Data\\roll_no.txt");
        rename("C:\\Student_Management_Software\\Student_Data\\temp.txt",
                "C:\\Student_Management_Software\\Student_Data\\roll_no.txt");
        return SUCCESS;
    }
    else
    {
        remove("C:\\Student_Management_Software\\Student_Data\\temp.txt");
        return FAILURE;
    }
}

int display_all_records()
{
    FILE* fp;
    struct student_data student;
    char choice;

    printf("\n\t\t\t\t==================================================");
    printf("\n\t\t\t\t**       DISPLAYING ALL STUDENT RECORDS       **");
    printf("\n\t\t\t\t==================================================\n\n");
    printf("\t\t\t\t                 *Student Data*\n");
    printf("\t\t\t\t__________________________________________________\n\n");

    fp = fopen("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt","a+");
    if (fp == NULL)
    {
        char err_msg[140];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [%s]",strerror(errno));
        strcat(err_msg,"Unable to open the file !\nPlease Try agin");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    display_open_frame();

    while (  
            fscanf(fp,"%s %s %s %d %d %d %d %d %f %c",&student.firstName,&student.middleName
            ,&student.lastName,&student.rollNo,&student.MathTwo,&student.C,&student.BEE,
            &student.totalMarks,&student.percentage,&student.grade)
            != EOF
    )
    {
        if (ferror(fp))
        {
            char errr_mag[240];

            sprintf(errr_mag,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
            strcat(errr_mag,"An error occured while reading the file !\n");
            strcat(errr_mag,"Please try again \n");
            fclose(fp);
            message_box_display_error(errr_mag);
            return FAILURE;
        }
        
        decrypt_student_data(&student);
        display_records(&student);
    }

    display_close_frame();
    printf("\n\t\t\t\tProcess Completed !\n");
    printf("\n\t\t\t\tEnter 'y' to go to home screen     .");
    printf("\n\t\t\t\tEnter 'n' to terminate the program .\n");
    printf("\t\t\t\t__________________________________________________\n\n");
    up:
    printf("\t\t\t\tEnter Your Choice : ");
    scanf("%c",&choice);
    getchar();
    switch (choice)
    {
            case 'y':
            case 'Y':
                    return SUCCESS;
                break;
            
            case 'n':
            case 'N':
                    message_box_program_termination();
                    return FAILURE;
                break;    
        default:
                custom_message("Please Enter a valid Option !");
                printf("\x1b[1F");
                goto up;

    }
}

int remove_student_record(void)
{
    int rno;

    printf("\n\t\t\t\t==================================================");
    printf("\n\t\t\t\t**            DELETE STUDENT RECORD           **");
    printf("\n\t\t\t\t==================================================\n\n");
    printf("\t\t\t\t Enter student information \n");
    printf("\t\t\t\t__________________________________________________\n\n");
    

    printf("\t\t\t\tEnter Roll number of the student : ");
    scanf("%d",&rno);
    getchar();

    if (check_student_roll_no_to_delete(rno) != SUCCESS)
    {
        custom_message("Given Roll No. is not preset in the student records !\n");
        return SUCCESS;
    }

    struct student_data student;
    struct student_data temp_student;
    FILE *stud_data_file;
    FILE *temp_file;

    stud_data_file = fopen("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt","a+");
    if (stud_data_file == NULL)
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nUnable to open file !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    temp_file = fopen("C:\\Student_Management_Software\\Student_Data\\temp_file.txt","w");
    if (temp_file == NULL)
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\temp_file : [ %s ]",strerror(errno));
        strcat(err_msg,"\nUnable to open file !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }
    rno = rno ^ KEY;

    while (  
        fscanf(stud_data_file,"%s %s %s %d %d %d %d %d %f %c",&student.firstName,&student.middleName
        ,&student.lastName,&student.rollNo,&student.MathTwo,&student.C,&student.BEE,
        &student.totalMarks,&student.percentage,&student.grade)
        != EOF
    )
    {
        if (ferror(stud_data_file))
        {
            char err_msg[240];

            sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
            strcat(err_msg,"\nAn error occured while reading a file !\n");
            strcat(err_msg,"Please try again later !\n");
            fclose(stud_data_file);
            fclose(temp_file);
            message_box_display_error(err_msg);
            return FAILURE;
        }
        
        if (student.rollNo != rno)
        {
            fprintf(temp_file,"%16s %16s %16s  %3d  %3d %3d %3d  %4d %3.2f  %2c \n",
            student.firstName,student.middleName,student.lastName,student.rollNo,student.MathTwo
            ,student.C,student.BEE,student.totalMarks,student.percentage,student.grade);
        }
        else
        {
            temp_student.MathTwo = student.MathTwo;
            temp_student.BEE = student.BEE;
            temp_student.C = student.C;
            temp_student.rollNo = student.rollNo;
            strcpy(temp_student.firstName,student.firstName);
            strcpy(temp_student.middleName,student.middleName);
            strcpy(temp_student.lastName,student.lastName);
            temp_student.grade = student.grade;
            temp_student.percentage= student.percentage;
            temp_student.totalMarks = student.totalMarks;
            
        }  
    }
    
    fclose(stud_data_file);
    fclose(temp_file);
    _fcloseall();
    
    if ( remove("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt") )
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during delete operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    if ( 
            rename("C:\\Student_Management_Software\\Student_Data\\temp_file.txt",
            "C:\\Student_Management_Software\\Student_Data\\Student_Data.txt")
        )
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\temp_file.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during rename operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    message_box_process_complete("Record deleted successfully !\n");
    printf("\t\t\t\t  Deleted record ->>>\n");
    decrypt_student_data(&temp_student);
    display_open_frame();
    display_records(&temp_student);
    display_close_frame();

    char buffer[240];
    sprintf(buffer,"Deleted data of student\nName : %s %s %s\nRoll Number : %d\n",temp_student.firstName,temp_student.middleName,temp_student.lastName,temp_student.rollNo);
    
    custom_message(buffer);

    if ( message_box_asking_for_going_back() == 7  )
    {
        message_box_program_termination();
        return FAILURE ;
    }

    return SUCCESS;
}

int update_roll_no_in_roll_no_file(int old,int new)
{
    FILE *data_file,*temp_file;
    int temp;

     data_file = fopen("C:\\Student_Management_Software\\Student_Data\\roll_no.txt","a+");
    if (data_file == NULL)
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\roll_no.txt : [ %s ]\n",strerror(errno));
        strcat(err_msg,"Unable to open file !\n");
        strcat(err_msg,"Please try again !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    temp_file = fopen("C:\\Student_Management_Software\\Student_Data\\temperory.txt","w");
    if (temp_file == NULL)
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\temperory.txt : [ %s ]\n",strerror(errno));
        strcat(err_msg,"Unable to open file !\n");
        strcat(err_msg,"Please try again !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    while (fscanf(data_file,"%d",&temp) != EOF)
    {
        if (temp != old)
        {
            fprintf(temp_file,"%d\n",temp);
        }
        else
        {
            fprintf(temp_file,"%d\n",new);
        }
    }

    fclose(data_file);
    fclose(temp_file);
    _fcloseall();

    if ( remove("C:\\Student_Management_Software\\Student_Data\\roll_no.txt") )
    {
       char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\roll_no.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during delete operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    if ( 
            rename("C:\\Student_Management_Software\\Student_Data\\temperory.txt",
            "C:\\Student_Management_Software\\Student_Data\\roll_no.txt")
        )
    {
       char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\temperory.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during rename operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    return SUCCESS;
}

int insert_updated_data(struct student_data temp_student, int choice,int roll_no)
{
    FILE *data_file,*temp_file;
    struct student_data student;
    roll_no = roll_no ^ KEY;

    data_file = fopen("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt","a+");
    if (data_file == NULL)
    {
        char err_msg[240];
        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]\n",strerror(errno));
        strcat(err_msg,"Unable to open file !\n");
        strcat(err_msg,"Please try again !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    temp_file = fopen("C:\\Student_Management_Software\\Student_Data\\temp_file.txt","w");
    if (temp_file == NULL)
    {
        char err_msg[240];
        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\temp.txt : [ %s ]\n",strerror(errno));
        strcat(err_msg,"Unable to open file !\n");
        strcat(err_msg,"Please try again !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    while (  
        fscanf(data_file,"%s %s %s %d %d %d %d %d %f %c",&student.firstName,&student.middleName
        ,&student.lastName,&student.rollNo,&student.MathTwo,&student.C,&student.BEE,
        &student.totalMarks,&student.percentage,&student.grade)
        != EOF
    )
    {
        if (ferror(data_file))
        {
            char err_msg[240];
            sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]\n",strerror(errno));
            strcat(err_msg,"An error occured while reading the file !\n");
            strcat(err_msg,"Please try again !\n");
            fclose(data_file);
            fclose(temp_file);
            message_box_display_error(err_msg);
            return FAILURE;
        }
        
        if (student.rollNo == roll_no)
        {   

            switch (choice)
            {
                case 1:
                        {
                            for (int i = 0; temp_student.firstName[i]; i++)
                            {
                                temp_student.firstName[i] = temp_student.firstName[i] ^ KEY;
                            }
                            for (int i = 0; temp_student.middleName[i]; i++)
                            {
                                temp_student.middleName[i] = temp_student.middleName[i] ^ KEY;
                            }
                            for (int i = 0; temp_student.lastName[i]; i++)
                            {
                                temp_student.lastName[i] = temp_student.lastName[i] ^ KEY;
                            }

                        fprintf(temp_file,"%16s %16s %16s  %3d  %3d %3d %3d  %4d %3.2f  %2c \n",
                        temp_student.firstName,temp_student.middleName,temp_student.lastName,student.rollNo,student.MathTwo
                        ,student.C,student.BEE,student.totalMarks,student.percentage,student.grade);

                        }
                    break;
                
                case 2:
                    
                    temp_student.rollNo = temp_student.rollNo ^ KEY;

                    fprintf(temp_file,"%16s %16s %16s  %3d  %3d %3d %3d  %4d %3.2f  %2c \n",
                    student.firstName,student.middleName,student.lastName,temp_student.rollNo,student.MathTwo
                    ,student.C,student.BEE,student.totalMarks,student.percentage,student.grade);
                    //update_roll_no_in_roll_no_file(roll_no^KEY,temp_student.rollNo^KEY);
                    break;

                case 3:
                    temp_student.BEE = temp_student.BEE ^ KEY;
                    temp_student.C = temp_student.C ^ KEY;
                    temp_student.MathTwo = temp_student.MathTwo ^ KEY;
                    temp_student.totalMarks = temp_student.totalMarks ^ KEY;
                    temp_student.percentage = temp_student.percentage * KEY;
                    temp_student.grade = temp_student.grade ^ KEY;

                    fprintf(temp_file,"%16s %16s %16s  %3d  %3d %3d %3d  %4d %3.2f  %2c \n",
                    student.firstName,student.middleName,student.lastName,student.rollNo,temp_student.MathTwo
                    ,temp_student.C,temp_student.BEE,temp_student.totalMarks,temp_student.percentage,temp_student.grade);

                    break;

                case 4:
                    encrypt_student_data(&temp_student);
                    fprintf(temp_file,"%16s %16s %16s  %3d  %3d %3d %3d  %4d %3.2f  %2c \n",
                    temp_student.firstName,temp_student.middleName,temp_student.lastName,temp_student.rollNo,temp_student.MathTwo
                    ,temp_student.C,temp_student.BEE,temp_student.totalMarks,temp_student.percentage,temp_student.grade);
            }
            
        }
        else
        {
            fprintf(temp_file,"%16s %16s %16s  %3d  %3d %3d %3d  %4d %3.2f  %2c \n",
            student.firstName,student.middleName,student.lastName,student.rollNo,student.MathTwo
            ,student.C,student.BEE,student.totalMarks,student.percentage,student.grade);
        }
    }

    fclose(temp_file);
    fclose(data_file);
    if (choice == 2 || choice == 4)
    {
        if( update_roll_no_in_roll_no_file(roll_no^KEY,temp_student.rollNo^KEY) == FAILURE)
            return FAILURE;
    }
    
    _fcloseall();

    if ( remove("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt") )
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during delete operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    if ( 
            rename("C:\\Student_Management_Software\\Student_Data\\temp_file.txt",
            "C:\\Student_Management_Software\\Student_Data\\Student_Data.txt")
        )
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\temp_file.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nAn error came during rename operation !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    message_box_process_complete("Data Updated Successfully !\n");

    return SUCCESS;
}

int update_an_existing_record(void)
{
    struct student_data student;
    int rno;
    int choice;
    printf("\n\t\t\t\t==================================================");
    printf("\n\t\t\t\t**           UPDATE STUDENT RECORD            **");
    printf("\n\t\t\t\t==================================================\n\n");
    printf("\t\t\t\t Enter student information \n");
    printf("\t\t\t\t To update an existing record of a student\n");
    printf("\t\t\t\t__________________________________________________\n\n");
    printf("\t\t\t\t Please enter his//her Roll No.  : ");
    scanf("%d",&rno);
    getchar();

    if( check_student_roll_no(rno) )
    {
        custom_message("Entered Roll No is not present in the student records !\n");
        return SUCCESS;
    }

    printf("\n\t\t\t\tWhat do you want to update !\n");
    printf("\t\t\t\t__________________________________________________\n");
    printf("\t\t\t\tEnter [1] to update Name \n");
    printf("\t\t\t\tEnter [2] to update Roll No \n");
    printf("\t\t\t\tEnter [3] to update Marks \n");    
    printf("\t\t\t\tEnter [4] to update Everything \n"); 
    printf("\t\t\t\t__________________________________________________\n");
    up:
    printf("\t\t\t\tEnter your Choice  : ");
    scanf("%d",&choice);
    printf("\t\t\t\t__________________________________________________\n\n");

    switch ( choice )
    {
        case 1:
            printf("\t\t\t\tEnter the first name  :");
            scanf("%s",&student.firstName);
            getchar();
            printf("\t\t\t\tEnter the Middle name :");
            scanf("%s",&student.middleName);
            getchar();
            printf("\t\t\t\tEnter the Last name   :");
            scanf("%s",&student.lastName);
            getchar();
            if ( insert_updated_data(student,choice,rno) )
                return FAILURE;
            break;

        case 2:
            printf("\t\t\t\tEnter The Roll No to be changed : ");
            scanf("%d",&student.rollNo);
           
            if(! check_student_roll_no(student.rollNo) )
            {
                custom_message("Entered Roll No. is already present in the student records !\n");
                return SUCCESS;
            }
            if ( insert_updated_data(student,choice,rno) )
                return FAILURE;
            break;
        case 3:
            printf("\t\t\t\tEnter Marks of M2  : ");
            scanf("%d",&student.MathTwo);
            getchar();
            printf("\t\t\t\tEnter Marks of C   : ");
            scanf("%d",&student.C);
            getchar();
            printf("\t\t\t\tEnter Marks of BEE : ");
            scanf("%d",&student.BEE);
            getchar();
            find_total_and_percentage(&student);
            if ( insert_updated_data(student,choice,rno) )
                return FAILURE;
            break;

        case 4:
            printf("\t\t\t\tData to be updated \n");
            printf("\t\t\t\t Enter Roll No of the Student       : ");
            scanf("%d",&student.rollNo);
            if(! check_student_roll_no(student.rollNo) )
            {
                custom_message("Entered Roll No is already present in the student records !\n");
                return SUCCESS;
            }

            accept_student_data(&student);
            find_total_and_percentage(&student);
            if ( insert_updated_data(student,choice,rno) )
                return FAILURE;
            break;
    
        default:

        custom_message("Invalid Choice !\nTry Again\n");
        printf("\x1b[1F");
        printf("\x1b[1F");
        printf("\x1b[1F");
        goto up;
        return SUCCESS;
    }
    if ( message_box_asking_for_going_back() == 7  )
    {
        message_box_program_termination();
        return FAILURE ;
    }
    return SUCCESS;
}

int search_student()
{
    FILE *data_file;
    struct student_data student;
    int rno;
    char flag = '0';

    printf("\n\t\t\t\t==================================================");
    printf("\n\t\t\t\t**            SEARCH STUDENT RECORD           **");
    printf("\n\t\t\t\t==================================================\n\n");
    printf("\t\t\t\t Enter student information \n");
    printf("\t\t\t\t To search his/her data \n");
    printf("\t\t\t\t__________________________________________________\n\n");

    printf("\t\t\t\tEnter the Roll number of the student : ");
    scanf("%d",&rno);
    rno = rno ^ KEY;

    data_file = fopen("C:\\Student_Management_Software\\Student_Data\\Student_Data.txt","a+");
    if (data_file == NULL)
    {
        char err_msg[240];

        sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
        strcat(err_msg,"\nUnable to open file !\n");
        strcat(err_msg,"Please try again later !\n");
        message_box_display_error(err_msg);
        return FAILURE;
    }

    while (  
        fscanf(data_file,"%s %s %s %d %d %d %d %d %f %c",&student.firstName,&student.middleName
        ,&student.lastName,&student.rollNo,&student.MathTwo,&student.C,&student.BEE,
        &student.totalMarks,&student.percentage,&student.grade)
        != EOF
    )
    {
        if (ferror(data_file))
        {
            char err_msg[240];

            sprintf(err_msg,"C:\\Student_Management_Software\\Student_Data\\Student_Data.txt : [ %s ]",strerror(errno));
            strcat(err_msg,"\nAn error occured while reading a file !\n");
            strcat(err_msg,"Please try again later !\n");
            fclose(data_file);
            message_box_display_error(err_msg);
            return FAILURE;
        }

        if (student.rollNo == rno)
        {
            flag = '1';
            fclose(data_file);
            break;
        }

    }

    if (flag == '1')
    {
        char buffer[512],choice;
        custom_message("Student Data found successfully !");
        decrypt_student_data(&student);
        display_open_frame();
        display_records(&student);
        display_close_frame();
        sprintf(buffer,"Student Data\n\nName : %s %s %s\nRoll number  : %d\nMarks of M2  : %d\nMarks of C     : %d\nMarks of BEE : %d\nTotal Marks   : %d\nPercentage    : %.2f\nGrade            : %c",
        student.firstName,student.middleName,student.lastName,student.rollNo,student.MathTwo,student.C,student.BEE,student.totalMarks,student.percentage,student.grade);
        message_data_found_successfull(buffer);
        getchar();

        if ( message_box_asking_for_going_back() == 7 )
        {
            message_box_program_termination();
            return FAILURE;
        }
        return SUCCESS;
        
    }
    else
    {
        fclose(data_file);
        custom_message("Student Data Not Found !");
        return SUCCESS;
    }
}

int main(void)
{
    system("cls"); 
    if (Connect_To_The_Data_folder() == FAILURE)
    {
        exit(0);
    }
    
    while (1)
    {
        switch ( get_instruction() )
        {
            case 1: 
                    system("cls"); // use this function
                  if ( add_Student_Data() )
                    exit(0);
                break;

            case 2:
                    system("cls"); 
                    if ( remove_student_record() )
                        exit(0);
                    
                break;

            case 3:
                    system("cls"); 
                    if ( update_an_existing_record() )
                        exit(0);
                    break;
            case 4:
                    system("cls"); 
                    if ( display_all_records())
                        exit(0);
                break;

            case 5 :
                    system("cls"); 
                    if( search_student() )
                        exit(0);
                    break;

            case 6:
                    printf("\n\t\t\t\t\t\t ** Exited ** \n");
                    printf("\t\t\t\t_________________________________________________\n\n");
                    message_box_program_termination();
                    exit(0);
        default:
            custom_message("Please choose a valid operation !\n");
        }
    }
}
