package ArchiveStore;

import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

abstract class Archive {
    protected int id;
    protected Date dateArchived;

    public Archive (int id) {
        this.id = id;
    }

    void setDateArchived(Date date) { this.dateArchived = date; }

    abstract String open(Date date);
}


class LockedArchive extends Archive {

    private Date dateToOpen;

    public LockedArchive(int id, Date dateToOpen) {
        super(id);
        this.dateToOpen = dateToOpen;
    }

    @Override
    String open(Date date) {
        if (date.before(dateToOpen))
            return String.format("Item %d cannot be opened before %s", id, dateToOpen);
        return String.format("Item %d opened at %s", id, date);
    }
}

class SpecialArchive extends Archive {
    private int maxOpen;
    private int timesOpened = 0;

    public SpecialArchive(int id, int maxOpen) {
        super(id);
        this.maxOpen = maxOpen;
    }


    @Override
    String open(Date date) {
        if (timesOpened >= maxOpen)
            return String.format("Item %d cannot be opened more than %d times", id, maxOpen);
        timesOpened++;
        return String.format("Item %d opened at %s", id, date);
    }
}


class ArchiveStore {
    ArrayList<Archive> archives = new ArrayList<>();
    StringBuilder log = new StringBuilder();

    ArchiveStore() {

    }

    void archiveItem(Archive item, Date date) {
        item.setDateArchived(date);
        log.append(String.format("Item %d archived at %s", item.id, date)).append("\n")  ;
        archives.add(item);
    }

    void openItem(int id, Date date) throws NonExistingItemException {
        for (Archive archive : archives) {
            if(archive.id == id) {
                log.append(archive.open(date)).append("\n");
                return;
            }
        }
        throw new NonExistingItemException(id);
    }

    String getLog() {
        return log.toString();
    }
}

class NonExistingItemException extends Exception {
    public NonExistingItemException(int id) {
        super(String.format("Item with id %d doesn't exist", id));
    }
}


public class ArchiveStoreTest {
    @SuppressWarnings("deprecation")

    public static void main(String[] args) {
        ArchiveStore store = new ArchiveStore();
        Date date = new Date(113, 10, 7);
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        int n = scanner.nextInt();
        scanner.nextLine();
        scanner.nextLine();
        int i;
        for (i = 0; i < n; ++i) {
            int id = scanner.nextInt();
            long days = scanner.nextLong();
            Date dateToOpen = new Date(date.getTime() + (days * 24 * 60
                    * 60 * 1000));
            LockedArchive lockedArchive = new LockedArchive(id, dateToOpen);
            store.archiveItem(lockedArchive, date);
        }
        scanner.nextLine();
        scanner.nextLine();
        n = scanner.nextInt();
        scanner.nextLine();
        scanner.nextLine();
        for (i = 0; i < n; ++i) {
            int id = scanner.nextInt();
            int maxOpen = scanner.nextInt();
            SpecialArchive specialArchive = new SpecialArchive(id, maxOpen);
            store.archiveItem(specialArchive, date);
        }
        scanner.nextLine();
        scanner.nextLine();
        while(scanner.hasNext()) {
            int open = scanner.nextInt();
            try {
                store.openItem(open, date);
            } catch(NonExistingItemException e) {
                System.out.println(e.getMessage());
            }
        }
        System.out.println(store.getLog());
    }
}

// вашиот код овде


