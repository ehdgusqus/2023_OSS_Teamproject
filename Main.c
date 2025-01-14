#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "Book.h"

#define MAX_MEMBERDATA 100
#define MAX_BOOKDATA 100

int LoadBook(Book **book_data);
int LoadMember(Member **Member_data);

int main()
{
    int choice;
    Book *book_data[MAX_BOOKDATA];
    Member *member_data [MAX_MEMBERDATA];

    idx = LoadBook(book_data);
    num_members = LoadMember(member_data);
    if(idx > 0)
        no = book_data[idx - 1]->no;

    while (1) {
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛         Library Management System       弛\n");
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
        printf("弛 0. Exit                                 弛\n");
        printf("弛 1. Display book list                    弛\n");
        printf("弛 2. Add a book                           弛\n");
        printf("弛 3. Delete a book                        弛\n");
        printf("弛 4. Edit a book                          弛\n");
        printf("弛 5. Search a book                        弛\n");
        printf("弛 6. Loan a book                          弛\n");
        printf("弛 7. Return a book                        弛\n");
        printf("弛 8. Save book                            弛\n");
        printf("弛 9. Display member list                  弛\n");
        printf("弛 10. Add a member                        弛\n");
        printf("弛 11. Delete a member                     弛\n");
        printf("弛 12. Search a member                     弛\n");
        printf("弛 13. Save member                         弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\n");
        printf("Enter your choice (0-13): ");

        scanf("%d", &choice);
        printf("\n");
  
        if(choice == 0)
        {
            printf("Thank you for using the library management system.\n");
            break;
        }
              
        switch (choice) {
            case 1:
                DisplayBook(book_data);
                break;
            case 2:
                AddBook(book_data);
                break;
            case 3:
                DeleteBook(book_data);
                break;
            case 4:
                ModifyBook(book_data);
                break;
            case 5:
                SearchBook(book_data);
                break;
            case 6:
                LoanBook(book_data,member_data);
                break;
            case 7:
                ReturnBook(book_data,member_data);
                break;
            case 8:
                SaveBook(book_data);
                break;
            case 9:
                DisplayMember(member_data);
                break;
            case 10:
                AddMember(member_data);
                break;
            case 11:
                DeleteMember(member_data);
                break;
            case 12:
                SearchMember(member_data);
                break;
            case 13:
                SaveMemberData(member_data);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 12.\n");
                break;
        }
    }
    return 0;
}

int LoadBook(Book **book_data) 
{
    FILE *file = fopen(BOOK_FILENAME, "r");

    int count = 0;
      
    while (!feof(file))
    {
        book_data[count] = (Book *)malloc(sizeof(Book));
        fscanf(file, "%u %s %s %s %s %s",
               &book_data[count]->no,
               book_data[count]->title,
               book_data[count]->author,
               book_data[count]->publisher,
               book_data[count]->end_date,
               book_data[count]->name);

        if(feof(file))
            break;
       
        data_num++;
        count++;
    }

    fclose(file);
    return count;
}

int LoadMember(Member **member_data) 
{
    FILE *file = fopen(MEMBER_FILENAME, "r");
    
    int count = 0;
    while (!feof(file)) 
    {
        member_data[count] = (Member *)malloc(sizeof(Member));
      
        fscanf(file, "%s %u %s",
              member_data[count]->name,
              &member_data[count]->age,
              member_data[count]->loan);

        if(feof(file))
                break;
        count++;
    }

    fclose(file);
    return count;
}