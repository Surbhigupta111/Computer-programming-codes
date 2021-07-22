#include <stdio.h>
struct libraryrecords
{
 int sno;
 char bookname[50], author[50], personissued[50];
 int issuedate;
}data;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void booksissued()
{
 FILE *fp;
 fp = fopen("infoA", "a");
 printf("Enter the Sequence no : ");
 scanf("%d", &data.sno);
 printf("Enter the bookname : ");
 scanf("%s", &data.bookname);
  printf("Enter the author : ");
 scanf("%s", &data.author);
 printf("Enter the personissued : ");
 scanf("%s", &data.personissued);
 printf("Enter the issuedate : ");
 scanf("%d", &data.issuedate);
 fwrite(&data, sizeof(data), 1, fp);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void list()
{
 FILE *fp1;
 fp1 = fopen("infoA", "r");
 printf("\nS.No\tbookname\tauthor\tpersonissued\tissuedate\n\n");
 while (fread(&data, sizeof(data), 1, fp1))
 {printf("  %d\t%s\t%s\t%s\t%d\n", data.sno, data.bookname, data.author, data.personissued, data.issuedate);}
 fclose(fp1);
}

//    FUNCTION TO DELETE A RECORD


void returnbooks()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Sequence no you want to delete : ");
 scanf("%d", &r);
 if (avlsno(r) == 0)
  printf("Sequence no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("infoA", "r");
  fpt = fopen("infoB", "w");
  while (fread(&data, sizeof(data), 1, fpo))
  {
   s = data.sno;
   if (s != r)
    fwrite(&data, sizeof(data), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("infoA", "w");
  fpt = fopen("infoB", "r");
  while (fread(&data, sizeof(data), 1, fpt))
   fwrite(&data, sizeof(data), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
//    FUNCTION TO UPDATE THE RECORD
void addbooks()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter sequence number to update : ");
 scanf("%d", &r);
 avl = avlsno(r);
 if (avl == 0)
 {
  printf("sequence number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("infoA", "r");
  fpt = fopen("infoB", "w");
  while (fread(&data, sizeof(data), 1, fpo))
  {
   s = data.sno;
   if (s != r)
    fwrite(&data, sizeof(data), 1, fpt);
   else
   {
    printf("\n\t1. Update bookname of sequence Number %d", r);
    printf("\n\t2. Update author of sequence Number %d", r);
    printf("\n\t3. Update personissued of sequence Number %d", r);
    printf("\n\t3. Update issuedate of sequence Number %d", r);
    printf("\n\t4. Update all bookname author personissued and issuedate of sequence Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter bookname: ");
     scanf("%s", &data.bookname);
     break;
   
     case 2:
     printf("Enter author: ");
     scanf("%s", &data.author);
     break;
      case 3:
     printf("Enter personissued: ");
     scanf("%s", &data.personissued);
     printf("Enter issuedate: ");
     scanf("%d", &data.issuedate);
     break;
    case 4:
     printf("Enter bookname: ");
     scanf("%s", &data.bookname);
     printf("Enter author: ");
     scanf("%s", &data.author);
     printf("Enter personissued: ");
     scanf("%s", &data.personissued);
     printf("Enter issuedate: ");
     scanf("%d", &data.issuedate);
     break;
    default:
     printf("Invalid Selection");
     break;
    ;}
    fwrite(&data, sizeof(data), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("infoA", "w");
  fpt = fopen("infoB", "r");
  while (fread(&data, sizeof(data), 1, fpt))
  {
   fwrite(&data, sizeof(data), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}

//    FUNCTION TO CHECK GIVEN  NO IS AVAILABLE //
int avlsno(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("infoA", "r");
 while (!feof(fp))
 {
  fread(&data, sizeof(data), 1, fp);

  if (rno == data.sno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("infoA", "r");
 while (fread(&data, sizeof(data), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
// MAIN PROGRAM
void main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. loan books to students\n\t2. list books loaned to a student\n\t");
  printf("3. return books\n\t4. add books\n");
  printf("\t5. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice: ");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
  booksissued();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    list();
   break;
  case 3:
   returnbooks();
   break;
  case 4:
   addbooks();
   break;
  case 5:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 5);
}
