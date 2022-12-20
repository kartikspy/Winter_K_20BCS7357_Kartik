import java.util.*;
public class LibraryStore {
    public static void main(String[] args) {         
        Scanner sc = new Scanner(System.in);
        BookDetail bf=new BookDetail();
        while(true)
        {
            System.out.print("\n\nChoose the desired option: \n");
            System.out.print("\t1 Add a new Book\n");
            System.out.print("\t2 Upgrade the Books quantity\n");
            System.out.print("\t3 Search a Books\n");
            System.out.print("\t4 Show all the Books\n");
            System.out.print("\t5 Check-Out a Book\n");
            System.out.print("\t6 Return a Book\n");            
            int ch = sc.nextInt();             
            switch (ch) {                
                case 1:
                    BookInfo b=new BookInfo();                   
                    bf.addBook(b);                     
                    break;
                case 2:
                    bf.upgradeBookQty();
                    break;
                case 3:
                    bf.searchByBookName();
                    break;
                case 4:
                    bf.showAllBooks();
                    break;
                case 5:
                    bf.checkOutBook(b);
                    break;
                case 6:
                    bf.checkInBook(b);
                    break;
                default:                     
                    sc.close();                     
                    return;
            }
        }
    }
}
