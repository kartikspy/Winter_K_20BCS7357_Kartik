import java.util.Scanner;
public class BookDetail {
    BookInfo theBooks[] = new BookInfo[50];
    public static int count;
    Scanner input = new Scanner(System.in);
    public int compareBookObjects(BookInfo b1, BookInfo b2)
    {
        if (b1.bookName.equalsIgnoreCase(b2.bookName)) {
            System.out.println(
                "Book of this Name Already Exists.");
            return 0;
        }
        if (b1.sNo == b2.sNo) {
            System.out.println(
                "Book of this Serial No Already Exists.");
            return 0;
        }
        return 1;
    }
 
    public void addBook(BookInfo b)
    {
        for (int i = 0; i < count; i++) {
 
            if (this.compareBookObjects(b, this.theBooks[i])
                == 0)
                return;
        }
        if (count < 50) {
 
            theBooks[count] = b;
            count++;
        }
        else {
            System.out.println("No Space to Add More Books.");
        }
    }

    public void searchByBookName()
    {
        System.out.println("\t\tSEARCH BY BOOK'S NAME");
        input.nextLine();
        System.out.println("Enter Book Name:");
        String bookName = input.nextLine();
        int flag = 0;
        System.out.println(
            "S.No\t\tName\t\tAuthor\t\tAvailable Qty\t\tTotal Qty");
        for (int i = 0; i < count; i++) {
            if (bookName.equalsIgnoreCase(
                    theBooks[i].bookName)) {
                System.out.println(
                    theBooks[i].sNo + "\t\t"
                    + theBooks[i].bookName + "\t\t"
                    + theBooks[i].authorName + "\t\t"
                    + theBooks[i].bookQtyCopy + "\t\t"
                    + theBooks[i].bookQty);
                flag++;
            }
        }
        if (flag == 0)
            System.out.println("No Books of " + Name
                               + " Found.");
    }

    public void showAllBooks()
    {
        System.out.println("\t\t\t\tSHOWING ALL BOOKS\n");
        System.out.println(
            "S.No\t\tName\t\tAuthor\t\tAvailable Qty\t\tTotal Qty");
 
        for (int i = 0; i < count; i++) {
 
            System.out.println(
                  theBooks[i].sNo + "\t\t"
                + theBooks[i].bookName + "\t\t"
                + theBooks[i].authorName + "\t\t"
                + theBooks[i].bookQtyCopy + "\t\t"
                + theBooks[i].bookQty);
        }
    }

    public void upgradeBookQty()
    {
        System.out.println(
            "\t\tUPGRADE QUANTITY OF A BOOK\n");
        System.out.println("Enter Serial No of Book");
 
        int sNo = input.nextInt();
 
        for (int i = 0; i < count; i++) {
 
            if (sNo == theBooks[i].sNo) {
                System.out.println(
                    "Enter No of Books to be Added:");
 
                int addingQty = input.nextInt();
                theBooks[i].bookQty += addingQty;
                theBooks[i].bookQtyCopy += addingQty;
                return;
            }
        }
    }
    public int isAvailable(int sNo)
    {
 
        for (int i = 0; i < count; i++) {
            if (sNo == theBooks[i].sNo) {
                if (theBooks[i].bookQtyCopy > 0) {
 
                    System.out.println(
                        "Book is Available.");
                    return i;
                }
                System.out.println("Book is Unavailable");
                return -1;
            }
        }
 
        System.out.println("No Book of Serial Number "
                           + " Available in Library.");
        return -1;
    }

    public book checkOutBook()
    {
        System.out.println("Enter Serial No of Book to be Checked Out.");
        int sNo = input.nextInt();
 
        int bookIndex = isAvailable(sNo);
 
        if (bookIndex != -1) {
            theBooks[bookIndex].bookQtyCopy--;
            return theBooks[bookIndex];
        }
        return null;
    }
    public void checkInBook(BookInfo b)
    {
        for (int i = 0; i < count; i++) {
            if (b.equals(theBooks[i])) {
                theBooks[i].bookQtyCopy++;
                return;
            }
        }
    }
}
