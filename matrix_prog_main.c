#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>



#define  max_size 20
#define flo "%10.3f "



struct matrix {
    float array[max_size][max_size];
    int m,n;
};



struct matrix readmatrix();
struct matrix readmatrixfile();
void printmatrix(struct matrix a);
void starting_Program();
void starting_menu();
void menu_2(struct matrix matrix_A);
void menu_3(struct matrix matrix_A,struct matrix matrix_B);
int addmatrix(struct matrix *matrix_A,struct matrix *matrix_B,struct matrix *matrix_C);
int submatrix(struct matrix *matrix_A,struct matrix *matrix_B,struct matrix *matrix_C);
int mulmatrix(struct matrix *matrix_A,struct matrix *matrix_B,struct matrix *matrix_C);
int tranmatrix(struct matrix *matrix_A,struct matrix *matrix_C);
int determatrix(struct matrix *matrix_A,double *det);
double determinants(int n,struct matrix a);
void menu_export_file(struct matrix *a);
void export_file(struct matrix *a);
void invermatrix(struct matrix matrix_A,struct matrix *matrix_C,double deter);



int main() {
    system("color 70");
    starting_Program();
    starting_menu();
    printf("\n\n  Press any key to exit program\n\n");
    getch();
    return 0;
}



struct matrix readmatrix(){
    struct matrix a;
    system("cls");
    printf("\n\n  Row: "),scanf("%d",&a.n);
    printf("  Column: "),scanf("%d",&a.m);
    printf("  Enter the matrix data\n");
    for (int i = 0; i < a.n; i++) {
        printf("  ");
        for (int j = 0; j < a.m; j++) {
            scanf("%f",&a.array[i][j]);
        }
    }
    return a;
}



void printmatrix(struct matrix a) {
    printf("\n\n    ");
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++) {
            printf(flo,a.array[i][j]);
        }
        printf("\n    ");
    }
}



void starting_menu() {
    system("cls");
    printf("\n\n Please select a task and enter the corresponding number.\n\n\n");
    printf("   1) Receive matrix A from input\n\n");
    printf("   2) Receive matrix A from file\n\n");
    char select=getch();
    struct matrix matrix_A;
    switch (select) {
        case '1':
            matrix_A=readmatrix();
            printmatrix(matrix_A);
            printf("\n  Press any key to continue\n");
            getch();
            menu_2(matrix_A);
            break;

        case '2':
            matrix_A=readmatrixfile();
            printmatrix(matrix_A);
            printf("\n  Press any key to continue\n");
            getch();
            menu_2(matrix_A);
            break;

        default:
            starting_menu();
            break;
    }
}



void menu_2(struct matrix matrix_A) {
    system("cls");
    printf("\n\n Please select a task and enter the corresponding number.\n\n\n");
    printf("   1) Display the determinants of matrix A\n\n");
    printf("   2) Display inverse of matrix A\n\n");
    printf("   3) Display transpose of matrix A\n\n");
    printf("   4) Receive matrix B from input\n\n");
    printf("   5) Receive matrix B from file\n\n");
    printf("   0) back\n\n");
    char select=getch();
    struct matrix matrix_C;
    struct matrix matrix_B;
    double det;
    switch (select) {
        case '1':
            printf("");
            int determinant=determatrix(&matrix_A,&det);
            if (determinant==1)
            {
                system("cls");
                printf("\n\n  Result:\n\n");
                printf("\n\n  |A|= %lf\n",det);
            } else {
                system("cls");
                printf("\n\n  Invalid Matrix\n\n");
            }
            break;

        case '2':
            printf("");
            int de=determatrix(&matrix_A,&det);
            if (de==1 && det!=0)
            {
                system("cls");
                printf("\n\n  Result:\n\n");
                printf("   A*(-1) =");
                invermatrix(matrix_A,&matrix_C,det);
                printmatrix(matrix_C);
                menu_export_file(&matrix_C);
            } else {
                system("cls");
                printf("\n\n  Invalid Matrix\n\n");
            }
            break;

        case '3':
            printf("");
            int tran=tranmatrix(&matrix_A,&matrix_C);
            if (tran==1)
            {
                system("cls");
                printf("\n\n  Result:\n\n");
                printmatrix(matrix_C);
                menu_export_file(&matrix_C);
            } else {
                system("cls");
                printf("\n\n  Invalid Matrix\n\n");
            }
            break;

        case '4':
            matrix_B=readmatrix();
            printf("\n\n   A=");
            printmatrix(matrix_A);
            printf("\n   B=");
            printmatrix(matrix_B);
            printf("\n  Press any key to continue\n");
            getch();
            menu_3(matrix_A,matrix_B);
            break;

        case '5':
            matrix_B=readmatrixfile();
            printf("\n\n   A=");
            printmatrix(matrix_A);
            printf("\n   B=");
            printmatrix(matrix_B);
            printf("\n  Press any key to continue\n");
            getch();
            menu_3(matrix_A,matrix_B);
            break;

        case '0':
            starting_menu();
            break;

        default:
            menu_2(matrix_A);
            break;
    }
}



void menu_3(struct matrix matrix_A,struct matrix matrix_B) {
    system("cls");
    printf("\n\n Please select a task and enter the corresponding number.\n\n\n");
    printf("   1) Add two matrix A and B and save the result in matrix A and display it\n\n");
    printf("   2) Subtract two matrix A and B and save the result in matrix A and display it\n\n");
    printf("   3) Multiply  two matrix A and B and save the result in matrix A and display it\n\n");
    printf("   0) back\n\n");
    char select=getch();
    struct matrix matrix_C;
    switch (select) {
        case '1':
            printf("");
            int add=addmatrix(&matrix_A,&matrix_B,&matrix_C);
            if (add==1)
            {
                system("cls");
                printf("\n\n  Result:\n\n");
                printf("   A + B =");
                printmatrix(matrix_C);
                menu_export_file(&matrix_C);
            } else {
                system("cls");
                printf("\n\n  Invalid Matrix\n\n");
            }
            break;

        case '2':
            printf("");
            int sub=submatrix(&matrix_A,&matrix_B,&matrix_C);
            if (sub==1)
            {
                system("cls");
                printf("\n\n  Result:\n\n");
                printf("   A - B =");
                printmatrix(matrix_C);
                menu_export_file(&matrix_C);
            } else {
                system("cls");
                printf("\n\n  Invalid Matrix\n\n");
            }
            break;

        case '3':
            printf("");
            int mul=mulmatrix(&matrix_A,&matrix_B,&matrix_C);
            if (mul==1)
            {
                system("cls");
                printf("\n\n  Result:\n\n");
                printf("   A * B =");
                printmatrix(matrix_C);
                menu_export_file(&matrix_C);
            } else {
                system("cls");
                printf("\n\n  Invalid Matrix\n\n");
            }
            break;

        case '0':
            menu_2(matrix_A);
            break;

        default:
            menu_3(matrix_A,matrix_B);
            break;
    }
}



int addmatrix(struct matrix *matrix_A,struct matrix *matrix_B,struct matrix *matrix_C) {
    if (matrix_A->n!=matrix_B->n || matrix_A->m!=matrix_B->m) {
        return 0;
    } else {
        matrix_C->n=matrix_A->n,matrix_C->m=matrix_A->m;
        for (int i = 0; i < matrix_A->n; i++)
            for (int j = 0; j < matrix_A->m; j++)
                matrix_C->array[i][j]=matrix_A->array[i][j]+matrix_B->array[i][j];
        return 1;
    }
}



int submatrix(struct matrix *matrix_A,struct matrix *matrix_B,struct matrix *matrix_C) {
    if (matrix_A->n!=matrix_B->n || matrix_A->m!=matrix_B->m) {
        return 0;
    } else {
        matrix_C->n=matrix_A->n,matrix_C->m=matrix_A->m;
        for (int i = 0; i < matrix_A->n; i++)
            for (int j = 0; j < matrix_A->m; j++)
                matrix_C->array[i][j]=matrix_A->array[i][j]-matrix_B->array[i][j];
        return 1;
    }
}



int mulmatrix(struct matrix *matrix_A,struct matrix *matrix_B,struct matrix *matrix_C) {
    if (matrix_A->m!=matrix_B->n) {
        return 0;
    } else {
        matrix_C->n=matrix_A->n,matrix_C->m=matrix_B->m;
        for (int i = 0; i < matrix_C->n; i++)
            for (int j = 0; j < matrix_C->m; j++) {
                matrix_C->array[i][j]=0;
                for (int k = 0; k < matrix_B->n; k++)
                    matrix_C->array[i][j] +=matrix_A->array[i][k] * matrix_B->array[k][j];
            }
        return 1;
    }
}



int tranmatrix(struct matrix *matrix_A,struct matrix *matrix_C) {
    if (matrix_A->n!=matrix_A->m) {
        return 0;
    } else {
        matrix_C->n=matrix_C->m=matrix_A->n;
        for (int i = 0; i < matrix_C->n; i++)
            for (int j = 0; j < matrix_C->m; j++) {
                matrix_C->array[i][j]=0;
                matrix_C->array[i][j]=matrix_A->array[j][i];
            }
        return 1;
    }
}



int determatrix(struct matrix *matrix_A,double *det) {
    if (matrix_A->n!=matrix_A->m) {
        return 0;
    } else {
        *det=determinants(matrix_A->n,*matrix_A);
        return 1;
    }
}



double determinants(int n,struct matrix a) {
    if (n==2) {
        return a.array[0][0]*a.array[1][1]-a.array[1][0]*a.array[0][1];
    }
    struct matrix minor;
    minor.n=minor.m=n;
    double deter=0;
    int p=1;
    for (int i = 0; i < n; i++) {
        int ii=0,jj=0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j!=0 && k!=i) {
                    minor.array[ii][jj]=a.array[j][k];
                    jj++;
                    if (jj>n-2) {
                        jj=0;
                        ii++;
                    }
                }
            }
        }
        deter += p*a.array[0][i]*determinants(n-1,minor);
        p*=-1;
    }
    return deter;
}



struct matrix readmatrixfile(){
    struct matrix a;
    system("cls");
    char filename[20];
    printf("\n\n The first line of the file should have the number of rows and the second line the number of columns.\n");
    printf(" And in the next lines the matrix elements are written.");
    //system("dir");
    printf("\n\n\n Please Enter the name of file(example: filename.txt): ");
    scanf("%s",filename);
    FILE *stream;
    stream=fopen(filename,"r");
    if (stream == NULL)
        {
            printf("\n\n  File does not exist\n\n");
            printf("\nPress any key to back\n");
            getch();
            starting_menu();
        } else {
            fscanf(stream,"%d",&a.n);
            fscanf(stream,"%d",&a.m);
            for (int i = 0; i < a.n; i++)
                for (int j = 0; j < a.m; j++)
                    fscanf(stream,"%f",&a.array[i][j]);
        }
    fclose(stream);
    return a;
}




void menu_export_file(struct matrix *a) {
    printf("\n\n  Do you want the result to be saved in a file? (Y/N)  ");
    hear:
    printf("");
    char select=getch();
    switch (select) {
        case 'y':
            printf("y\n");
            export_file(a);
            break;

        case 'Y':
            printf("Y\n");
            export_file(a);
            break;

        case 'n':
            printf("n\n");
            break;

        case 'N':
            printf("N\n");
            break;

        default:
            goto hear;
            break;
    }
}



void export_file(struct matrix *a) {
    printf("\n\n\n  Please Enter the name of file to save(example: filename.txt): ");
    char filename[20];
    scanf("%s",filename);
    FILE *stream;
    stream=fopen(filename,"w");
    fprintf(stream,"\n\n");
    fprintf(stream,"    %d\n    %d\n    ",a->n,a->m);
    for (int i = 0; i < a->n; i++) {
        for (int j = 0; j < a->m; j++)
            fprintf(stream,flo,a->array[i][j]);
        fprintf(stream,"\n    ");
    }
    fclose(stream);
    printf("\n\n  Succesful\n");
    system(filename);
}



void invermatrix(struct matrix matrix_A,struct matrix *matrix_C,double deter) {
    int n=matrix_A.n,p=1;;
    struct matrix minor,cofactor;
    minor.n=minor.m=n-1;
    cofactor.n=cofactor.m=n;
    for (int k = 0; k < n; k++) {
        for (int q = 0; q < n; q++) {
            int ii=0,jj=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i!=k && j!=q) {
                        minor.array[ii][jj]=matrix_A.array[i][j];
                        jj++;
                        if (jj>n-2) {
                            ii++;
                            jj=0;
                        }
                    }
                }
            }
            cofactor.array[k][q]= pow(-1,k+q) * (float)determinants(n-1,minor);
            p*=-1;
        }
    }
    struct matrix matrix_temp;
    tranmatrix(&cofactor,&matrix_temp);
    matrix_C->n=matrix_C->m=n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix_C->array[i][j]=matrix_temp.array[i][j]/deter;
        }
    }
}



void starting_Program() {
    printf("\n\n");
    printf("  $$$$$$$$$$$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$   $$$$$$$$$$$$$$   $$            $$$$$$$$$$$$$$   $$$$$          $$$$$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$           $$$          $$$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$             $$        $$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$              $$      $$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$               $$    $$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$$$$$$$$$$$        $$                $$  $$\n");
    printf("  $$          $$          $$   $$$$$$$$$$$$$$         $$         $$                  $$                 $$$$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$                $$  $$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$               $$    $$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$              $$      $$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$             $$        $$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$                  $$           $$$          $$$\n");
    printf("  $$          $$          $$   $$          $$         $$         $$            $$$$$$$$$$$$$$   $$$$$          $$$$$\n\n\n\n");


    printf("  $$$$$$$$$$  $$$$$$$$$$  $$          $$$$$$$$$$  $$      $$  $$          $$$$$$$$$$  $$$$$$$$$$  $$$$$$$$$$  $$      \n");
    printf("  $$          $$      $$  $$          $$          $$      $$  $$          $$      $$      $$      $$      $$  $$      \n");
    printf("  $$          $$      $$  $$          $$          $$      $$  $$          $$      $$      $$      $$      $$  $$$$$$$$\n");
    printf("  $$          $$$$$$$$$$  $$          $$          $$      $$  $$          $$$$$$$$$$      $$      $$      $$  $$      \n");
    printf("  $$          $$      $$  $$          $$          $$      $$  $$          $$      $$      $$      $$      $$  $$      \n");
    printf("  $$$$$$$$$$  $$      $$  $$$$$$$$$$  $$$$$$$$$$  $$$$$$$$$$  $$$$$$$$$$  $$      $$      $$      $$$$$$$$$$  $$      \n\n\n");
    Sleep(2000);
    printf("                                                                                                  Starting");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(". ");
    Sleep(1000);
    system("cls");
}
